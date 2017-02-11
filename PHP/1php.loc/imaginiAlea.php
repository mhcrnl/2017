<html>
<body>
<?php
	srand(microtime()*1000000);
	$num=rand(1,4);
	switch($num) {
		case 1:
			$imagine = "Images\forest.jpg";
			break;
		case 2:
			$imagine = 	"..\Images\OryxAntilope.jpg";
			break;
			}
		echo "Imagine: <img src = $imagine />"
		

?>
</body>
</html>