<?php
     // configuration
     require("../includes/config.php");

     // if user reached page via GET (as by clicking a link or via redirect)
     if ($_SERVER["REQUEST_METHOD"] == "GET")
     {
         // else render form
         render("register_form.php", ["title" => "Register"]);
     }

     // else if user reached page via POST (as by submitting a form via POST)
     else if ($_SERVER["REQUEST_METHOD"] == "POST")
     {
        // make sure all fields are filled out and password == confirmation
        if(empty($_POST["username"]) || empty($_POST["password"]) || empty($_POST["email"]) ||
           ($_POST["confirmation"] != $_POST["password"]))
           apologize("Bad registration!");
        else
        {
            if(query("INSERT INTO users (username, hash, cash, email) VALUES (?, ?, 10000.00, ?)", $_POST["username"],
                                                                                                   crypt($_POST["password"]),
                                                                                                   $_POST["email"]) === false)
                apologize("Problem inserting into table!");

            // if registration was successful, redirect to login
            redirect("index.php");
        }
     }
?>
