<?php

    $string = "daven";

    $array = str_split($string, 1);

    $counter = 0;

    foreach($array as $value)
        $counter++;

    echo "size is: $counter";
?>
