<?php

    /* Do all your logic here! */

    // configuration
    require("../includes/config.php");

    // positions equals an empty array
    $positions = [];

    // find array of arrays that contains all contents of user's holdings
    $rows = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);

    if($rows === false)
        apologize("Couldn't find stocks!");

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
                                "action" => $row["action"],
                                "time" => $row["time"],
                                "cost" => $row["cost"]
                             ];
            }

        }
    }
    // if they have no stocks
    else
    {
        $positions[] = [
                        "symbol" => "",
                        "shares" => NULL,
                        "action" => "",
                        "time" => "",
                        "cost" => NULL
                      ];
    }

    // render portfolio while passing user's holdings to Portfolio
    render("history.php", ["title" => "History", "holdings" => $positions]);

?>
