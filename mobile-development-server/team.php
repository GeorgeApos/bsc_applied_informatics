<?php 
    include 'mysql_handler.php';
    if(isset($_POST['submit_team'])){
        static $arrayOfTeams = array();

        $name = $_POST['Name'];
        $city = $_POST['City'];
        $logo = $_POST['Logo'];

        createTeam($arrayOfTeams, $Name, $City, $Logo);
    }

    function createTeam($arrayOfTeams, $Name, $City, $Logo){
        $team = new basketball_team($Name, $City, $Logo);

        array_push($arrayOfTeams, $team);

    }

    class basketball_team{
        private $Name;
        private $City;
        private $Logo;

        function __construct($Name, $City, $Logo){
            $this->Name = $Name;
            $this->City = $City;
            $this->Logo = $Logo;
        }
        
        function get_name(){
            return $this->Name;
        }

        function get_city(){
            return $this->City;
        }

        function get_logo(){
            return $this->Logo;
        }

        function set_name($Name){
            $this->Name = $Name;
        }

        function set_city($City){
            $this->City = $City;
        }

        function set_logo($Logo){
            $this->Logo = $Logo;
        }
    }
?>