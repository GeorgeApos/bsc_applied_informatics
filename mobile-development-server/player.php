<?php 
    include 'mysql_handler.php';
    if(isset($_POST['submit_player'])){
        static $arrayOfPlayers = array();

        $name = $_POST['name'];
        $position = $_POST['position'];
        $team = $_POST['team'];
        $photo = $_POST['picture'];

        createPlayer($arrayOfPlayers, $name, $position, $team, $photo);
    }

    function createPlayer($arrayOfPlayers, $Name, $Position, $Team, $Logo){
        $player = new basketball_player($Name, $Position, $Team, $Logo);

        array_push($arrayOfPlayers, $player);

        
    }

    class basketball_player{
        private $Name;
        private $Position;
        private $Team;
        private $Photo;

        function __cunstruct($Name,$Position,$Team,$Photo){
            $this->Name = $Name;
            $this->Position = $Position;
            $this->Team = $Team;
            $this->Photo = $Photo;

        }

        function getName(){
            return $this->Name;
        }

        function getPosition(){
            return $this->Position;
        }

        function getTeam(){
            return $this->Team;
        }

        function getPhoto(){
            return $this->Photo;
        }

        function setName($Name){
            $this->Name = $Name;
        }

        function setPosition($Position){
            $this->Position = $Position;
        }

        function setTeam($Team){
            $this->Team = $Team;
        }

        function setPhoto($Photo){
            $this->Photo = $Photo;
        }
    }
?>