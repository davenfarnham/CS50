#!/usr/bin/php

<?php

    if($argc != 2)
    {
	echo "[height < 23]\n";
	exit();
    }

    // save height
    $height = $argv[1];

    if($height > 23)
    {
	echo "[height <= 23]\n";
	exit();
    }

    for($i = 0; $i < $height; $i++)
    {
      for($k = $height - $i - 1; $k > 0; $k--)
      {
	printf(" ");
      }

      for($k = 0; $k < $i + 1; $k++)
      {
	printf("#");
      }

      printf("\n");
    }

 ?>
