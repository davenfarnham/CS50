<?php

    /* Do all your logic here! */

    // configuration
    require("../includes/config.php"); 

    // positions equals an empty array
    $positions = [];

    // find array of arrays that contains all contents of user's holdings
    $rows = query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);

    if($rows === false)
        apologize("Couldn't find stocks!");

    $user = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);

    if($user === false)
        apologize("Couldn't find user!");

    // make your own array, and put everything inside it - if user has stocks
    if(!empty($rows))
    {
        foreach($rows as $row)
        {
            $lookup = lookup($row["symbol"]);

            if($lookup !== false)
            {
                $positions[] = [
                                "symbol" => $row["symbol"],
                                "shares" => $row["shares"],
                                "cash" => $user[0]["cash"],
                                "price" => $lookup["price"],
                                "name" => $lookup["name"]
                             ];
            }

        }
    }
    // if they have no stocks
    else
    {
        $positions[] = [
                        "symbol" => "",
                        "shares" => 0,
                        "cash" => $user[0]["cash"],
                        "price" => 0,
                        "name" => ""
                      ];
    }

    // render portfolio while passing user's holdings to Portfolio
    render("portfolio.php", ["title" => "Portfolio", "holdings" => $positions]);

?>
