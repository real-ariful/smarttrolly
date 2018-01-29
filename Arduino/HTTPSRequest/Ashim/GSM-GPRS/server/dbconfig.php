
<?php

$host="localhost"; // Host name
$username="root"; // Mysql username
$password=""; // Mysql password
$dbname="sim900"; // Database name


// Create connection
$conn = mysqli_connect($host, $username, $password, $dbname);
// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
?>

