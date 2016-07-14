<table class="table table-striped">
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Action</th>
            <th>Time</th>
            <th>Cost</th>
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
                        print("<th>" . $holding["shares"] . "</th>");
                        print("<th>" . $holding["action"] . "</th>");
                        print("<th>" . $holding["time"] . "</th>");

                        // print PRICE right now
                        if($holding["cost"] < 0)
                            print("<th>" . "-$" . money_format('%i', -$holding["cost"]) . "</th>");
                        else
                            print("<th>" . "$" . money_format('%i', $holding["cost"]) . "</th>");

                        print("</tr>");
                    }
                }
            ?>
    </tbody>
</table>
<div>
    <a href="logout.php">Log Out</a>
</div>

