<?php
	$numefila="textscris.txt";
	$fila = fopen($numefila, "w");
	if($fila==false){
		echo("Eroare la scrierea $numefila");
		exit();	
	}
	fwrite($fila, "Textul de scris in fila.\n");
	fclose($fila);
?>