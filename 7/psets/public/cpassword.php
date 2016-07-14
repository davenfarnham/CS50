<?php

     // configuration
     require("../includes/config.php");
 
    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render form
        render("change.php", ["title" => "Change Password"]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // $_POST is the method of submission, where "username" is the name from the HTML form
        if(empty($_POST["old"]) || empty($_POST["password"]) || ($_POST["password"] != $_POST["confirmation"]))
            apologize("Please try again!");
        else
        {
            // this returns row and now just field?
            $old = query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);

            if($old === false)
                apologize("Can't change password right now!");

            // here you're calling crypt on the new password and passing in the old hash as the salt
            if(crypt($_POST["old"], $old[0]["hash"]) != $old[0]["hash"])
                apologize("Please input correct old password!");

            if(query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["password"]), $_SESSION["id"]) === false)
                apologize("Couldn't enter into table!");

            // redirect to main page
            redirect("index.php");
        }
    }
?>
