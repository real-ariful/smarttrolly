<?php
require_once 'dbconfig.php';
 
$sql = "INSERT INTO sensor(Temp) values('$_GET[Temp]')";


if (mysqli_query($conn, $sql))
 {  
 
 	$URL="welcome.php";
echo '<META HTTP-EQUIV="refresh" content="0;URL=' . $URL . '">';
echo "<script type='text/javascript'>document.location.href='{$URL}';</script>";
 } 
else {
    echo "Error: " . $sql . "<br>" . mysqli_error($conn);
}

mysqli_close($conn);



?>

