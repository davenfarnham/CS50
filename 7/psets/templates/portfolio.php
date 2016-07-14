<table class="table table-striped">
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Value</th>
            <th>Total</th>
        </tr>
    </thead>
    <tbody>
            <?php
                if(!empty($holdings))
                {
                    // set location for money format
                    setlocale(LC_MONETARY, 'en_US');

                    foreach ($holdings as $holding)
                    {
                        print("<tr>");

                        // print SYMBOL and # of SHARES
                        print("<th>" . $holding["symbol"] . "</th>");
                        print("<th>" . $holding["name"] . "</th>");
                        print("<th>" . $holding["shares"] . "</th>");

                        // print PRICE right now
                        print("<th>" . "$" . money_format('%i', $holding["price"]) . "</th>");

                        // print TOTAL
                        print("<th>" . "$" . money_format('%i', ($holding["price"] * $holding["shares"])) . "</th>");

                        print("</tr>");
                    }
                }
            ?>
        <tr>
            <th colspan="4">CASH</th>
            <th>$<?php if(!empty($holdings)) print(money_format('%i', $holding["cash"])); else print("0");?></th>
        </tr>
    </tbody>
</table>
<div>
    <a href="logout.php">Log Out</a>
</div>

