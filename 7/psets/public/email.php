<?php
    /*** sudo apt-get install sendmail ***/

     // configuration
     require("../includes/config.php");

     // if user reached page via GET (as by clicking a link or via redirect)
     if ($_SERVER["REQUEST_METHOD"] == "GET")
     {
         // else render form
         render("email_form.php", ["title" => "Forgotten Password"]);
     }

     // else if user reached page via POST (as by submitting a form via POST)
     else if ($_SERVER["REQUEST_METHOD"] == "POST")
     {
        // query database 'users' for email
        $password = query("SELECT hash FROM users WHERE email = ?", $_POST["email"]);

        if($password === false)
            apologize("You don't seem to be a user!");
        else
        {
            // initial string
            $str = "abcdefghijklmnopqrstuvwxyz";

            // randomize string
            $str = str_shuffle($str);

            // update password
            if(query("UPDATE users SET hash = ? WHERE email = ?", crypt($str), $_POST["email"]) === false)
                apologize("Couldn't update password.");

            // recipient
            $to = $_POST["email"];

            // email subject
            $subject = "New C$50 Finance Password";

            // message - send user their new, randomized password
            $message = "<html><p>Your new password is: ". $str . "</p></html>";

            // headers
            $headers  = 'MIME-Version: 1.0' . "\r\n";
            $headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";

            if(mail($to, $subject, $message, $headers))
                render("login_form.php", ["title" => "Login"]);
            else
                apologize("Couldn't find password");
        }
     }
?>
