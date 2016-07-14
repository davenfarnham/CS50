#!/usr/bin/php

<?php

    if($argc != 2)
    {
	printf("Not enough arguments!\n");
	exit();
    }

    $height = $argv[1];

    if($height > 23)
    {
	printf("Height too big!\n");
	exit();
    }

    for($i = 0; $i < $height; $i++)
    {
	// TODO
    }
 ?>
