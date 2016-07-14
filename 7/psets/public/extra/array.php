<!DOCTYPE html>

// primary/ unique + echo/ print + scope within foreach loops 

<?php
    $array = [
                "daven" => "teacher",
                "rob" => "teacher",
                "emily" => "student",
    ];


    print "Hello!" . $array["daven"] . "\n";
/*
    // print out contents of array
    var_dump($array);
*/

    foreach($array as $value)
        echo "Value: $value<br />\n";

    echo "$value";

    // look up scope
    foreach($array as $key => $value)
        print("<li>$key</li>");

    echo "$value";

    // simple example of a for loop
    for($i = 0; $i < 4; $i++)
        echo "<li>moooo!</li>";

    if(sizeof($array) == 2)
        echo "size of two!";

    if(sizeof($array) == 3)
        echo "<h1>nope! 3</h1>";
?>
