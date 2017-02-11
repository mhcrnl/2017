<?php
/* Conectarea la bazele de date */
$dbhost = "localhost";
$dbuser = "root";
$dbpass = "";
$dbconn = mysql_connect($dbhost,$dbuser, $dbpass);

if(! $dbconn){
	die ("Conectare esuata!" .mysql_error()); 
}
echo "Conectare realizata!<br />\n";
/* Crearea unei baze de date 
$sql = 'CREATE Database test';
$retvalue = mysql_query($sql, $dbconn);
if(!$retvalue){
	die("Crearea bazei de date a esuat: => " .mysql_error().".<br />");
}
echo "Crearea bazei de date a avut succes!<br />\n";
 Selectarea unei baze de date */
$returnval = mysql_select_db("test");
if(! $returnval) {
	die("Conectarea la baza de date : => ".mysql_error().".<br />");
	}
echo "Conrectarea la baza de date a avut succes!<br />";
/* Crearea unui tabel de date intr-o baza de date */
$sql = 'CREATE TABLE Angajat('.
			'id INT NOT NULL AUTO_INCREMENT,'.
			'nume VARCHAR(30) NOT NULL,'.
			'adresa VARCHAR(30) NOT NULL,'.
			'angajare timestamp(6) NOT NULL,'.
			'primary key (id))';
mysql_select_db("test");
$retval1 = mysql_query($sql, $dbconn);
if(!$retval1){
	die("Tabelul nu a fost creat : => ".mysql_error().".<br />");
}		
echo "Tabelul a fost creat cu succes.<br />";
/* Stergerea unei baze de date */
$sterge_db = 'DROP DATABASE test';
$retval2 = mysql_query($sterge_db, $dbconn);
if(! $retval2) {
	die("Baza de date nu a fost stearsa: =>".mysql_error().".<br />");
	}
echo "Baza de date a fost stearsa.SUCCES!<br />";

mysql_close($dbconn);

?>