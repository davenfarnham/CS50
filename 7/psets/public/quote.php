<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form; login_form.php now has access to a variable $title that has value "Log In"
        render("quote_form.php", ["title" => "Lookup"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a stock symbol!");
        }
        else
        {
            // store stock symbol, name, and price in stock
            $stock = lookup($_POST["symbol"]);

            if($stock === false)
                apologize("Please provide a viable stock symbol!");

            // render display of stock
            render("quote_display.php", ["stock" => $stock]);
        }
    }

?>
