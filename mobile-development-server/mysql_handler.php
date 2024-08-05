<?php

    function createDbFunction($db_name, $handler){
        if (!defined('FOO_EXECUTED')) {
            $handler->createDatabase($db_name);
            define('FOO_EXECUTED', true);
        }
    }

    class MySQLHandler{
       private string $servername ;
       private string $username ;
       private string $password ;
       private int $port;
       private string $database ;
       private $connection ;

       function __construct($servername,$username,$password,$port){
            $this->servername = $servername;
            $this->username = $username;
            $this->password = $password;
            $this->port = $port;
        }

        function closeConnection(){
            $this->connection->close();
        }

        function setConnection(){
            $connection = mysqli_connect($this->servername,$this->username,$this->password);
            if ($connection->connect_error) {
                die("Connection failed: " . $connection->connect_error);
                }
            $this->connection = $connection;
        }

        function setDatabase($database){
            $this->database = $database;
        }

        function createDatabase($db_name){
            $sql = "CREATE DATABASE $db_name";
            if (mysqli_query($this->connection,$sql) === TRUE) {
                echo "Database created successfully";
            } else {
                echo "Error creating database: " . $this->connection->error;
            }
        }

        function createTables($selectQuery){
            $query = file_get_contents('tables.sql');
            if ($this->connection->query($query) === TRUE) {
                echo "all tables created successfully <br/>";
            } else {
                echo "Error creating tables: " . $this->connection->error;
            }
        }
    }

?>