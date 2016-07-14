#!/usr/bin/php

<?php

    /* Create a php script to import a .csv, search for a tf's name,
       then return his email address */

    /* what's the same here?: argc, argv, fopen, conditions, while loop, printf, etc */

    // check the number of cmd-line arguments
    if($argc != 3)
    {
	echo("[first name] [last name]!\n");
	exit();
    }

    // open the file to read in from
    $file = fopen("tf_emails.csv", "r");

    // if problem, exit
    if($file == false)
    {
	echo("problem importing file!\n");
	exit();
    }

    // read in from .csv
    while(($data = fgetcsv($file, 0, ',')) !== FALSE)
    {
        if(!strcmp($data[0], $argv[1]) && !strcmp($data[1], $argv[2]))
        {
            printf("%s %s's email address is: %s\n", $data[0], $data[1], $data[2]);
	    break;
        }
    }

?>
