<?php

define('DB_SERVER', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', '');

$link = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD);

// Create database
$sql = "CREATE DATABASE demo";
if ($link->query($sql) === TRUE) {
  echo "Database created successfully\n";
} else {
  echo "Error creating database: " . $link->error;
}
 
/* Attempt to connect to new MySQL database */
$connection = mysqli_connect(DB_SERVER, DB_USERNAME, DB_PASSWORD, "demo");
 
// Check connection
if($connection === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}

$table = "CREATE TABLE users (
    id INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL UNIQUE,
    email VARCHAR(255) NOT NULL,
    radio1 VARCHAR(255) NOT NULL, 
    radio2 VARCHAR(255) NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);";

if ($connection->query($table) === TRUE) {
    echo "Table MyGuests created successfully <br> ";
  } else {
    echo "<br> Error creating table: " . $connection->error  ;
  }

$connection->close();
$link->close();



?>

<!DOCTYPE html>
<html>
<head>
<style>
  button{
    color: #fff !important;
    text-decoration: none;
    background: #ed3330;
    padding: 20px;
    border-radius: 5px;
    display: inline-block;
    border: none;
    transition: all 0.4s ease 0s;
  }
  button:hover {
    background: #434343;
    letter-spacing: 1px;
    webkit-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);
    -moz-box-shadow: 0px 5px 40px -10px rgba(0,0,0,0.57);
    box-shadow: 5px 40px -10px rgba(0,0,0,0.57);
    transition: all 0.4s ease 0s;
  }
</style>
</head>
<body>


<br> <br>
<button type="button" onclick="location.href = 'register.php'">Return to form.</button>

</body>
</html>