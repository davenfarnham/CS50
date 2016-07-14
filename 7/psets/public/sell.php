<?php

     // configuration
     require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        $rows = query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);

        $stocks = [];

        foreach($rows as $row)
        {
            $stocks[] = [
                        "stock" => $row["symbol"]
                      ];
        }

        // render form
        render("sell_form.php", ["title" => "Sell!", "stocks" => $stocks]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        /* the fields in table 'user' are: id, username, hash, cash and the
           fields in portfolio are: id, symbol, shares */
        if(empty($_POST["symbol"]) || empty($_POST["shares"]))
            apologize("Please fill out all fields!");

        // check if stock is in portfolio
        $rows = query("SELECT * FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], strtoupper($_POST["symbol"]));

        // break on error
        if($rows === false)
            apologize("Can't update portfolio!");

        // apologize if stock isn't there
        if(empty($rows))
            apologize("You don't have that stock!");

        // look up symbol
        $stock = lookup(strtoupper($_POST["symbol"]));

        // if lookup failed
        if($stock === false)
            apologize("Sorry! couldn't find stock!");

        // get price
        $price = $stock["price"];

        // profit = price * (# of shares)
        $profit = $price * $_POST["shares"];

        // update user's cash
        if(query("UPDATE users SET cash = cash + ? WHERE id = ?", $profit, $_SESSION["id"]) === false)
            apologize("Can't update table!");
        else
        {
            // amount of shares user has
            $row = $rows[0];

            // if user tries to sell too much stock
            if($row["shares"] < $_POST["shares"])
                apologize("Sorry! you don't have that much stock!"); /* this will exit */

            // sell all of a particular stock
            else if($row["shares"] == $_POST["shares"])
            {
                if(query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $stock["symbol"]) === false) 
                    apologize("Can't update table!");
                else
                    render("sold.php", ["title" => "Sold!", "symbol" => $stock["symbol"], "shares" => $_POST["shares"], "profit" => $price]);
            }
            // sell only some of a stock
            else
            {
                if(query("UPDATE portfolio SET shares = shares - ? WHERE id = ? AND symbol = ?", $_POST["shares"], $_SESSION["id"], $_POST["symbol"]) === false) 
                    apologize("Can't update table!");
                else
                    render("sold.php", ["title" => "Sold!", "symbol" => $_POST["symbol"], "shares" => $_POST["shares"], "profit" => $profit]);
            }

            // update history table
            if(query("INSERT INTO history VALUES (?, ?, ?, ?, NOW(), ?)", $_SESSION["id"], $stock["symbol"], $_POST["shares"], "SELL", $profit) === false)
                apologize("Couldn't update history");
        }
    }
?>
