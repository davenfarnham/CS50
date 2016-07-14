<?php

    // configuration
    require("../includes/config.php");

    // if they didn't deposit anything (clicked on a link to get here)
    if(empty($_GET["deposit"]))
    {
        render("deposit_form.php", ["title" => "Deposit"]);
    }
    else
    {
        // give user $10000 more dollars
        if(query("UPDATE users SET cash = cash + ? WHERE id = ?", 10000, $_SESSION["id"]) === false)
            apologize("Couldn't add funds.");

        redirect("/");
    }

?>
