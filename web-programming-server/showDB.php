<?php
// Include config file
require_once "config.php";

$sql = "SELECT id, username, email, radio1, radio2 FROM users";
$result = $link->query($sql);

if ($result->num_rows > 0) {
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "<strong>id:</strong> " . $row["id"]. 
    " - <strong>Name:</strong> " . $row["username"]. 
    " - <strong>Email:</strong> " . $row["email"].  
    " - <strong>Strong Skills:</strong> " . $row["radio1"].  
    " - <strong>Prefer Working:</strong> " . $row["radio2"]. 
    "<br>";
  }
} else {
  echo "0 results";
}
$link->close();

?>
