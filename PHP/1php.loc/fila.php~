<html>
<head>
<title>Citirea unei file in php</title>
</head>
<body>
	<?php
		$numelefilei = "index.html";
		$fila = fopen($numelefilei, "r");
		if($fila == false){
			echo("Eroare la deschiderea filei!");
			exit();		
		}
		$dimensiuneafilei =filesize($numelefilei);
		$textulfilei=fread($fila, $dimensiuneafilei);
		fclose($fila);
		
		echo ("Dimensiunea filei : $dimensiuneafilei");
		echo ("<pre>$textulfilei</pre>");
	?>
</body>
</html>