<?php
//    var_dump($_POST["name"]);

    if(empty($_POST["name"]))
        print("<h1>Give me a name!</h1>");
    else
        print "<h1>Hi! " . $_POST["name"] . "</h1>";
?>
