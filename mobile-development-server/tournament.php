<?php
    
    if(isset($_POST['submit_tournament'])){
        static $arrayOfTournaments = array();

        $name = $_POST['Name'];
        $team = $_POST['Team'];

        createTournament($arrayOfTournaments, $team, $name);
    }

    function createTournament($arrayOfTournaments, $Teams, $Name){
        $tournament = new basketball_tournament($Teams, $Name);

        array_push($arrayOfTournaments, $tournament);

    }
    
    class basketball_tournament{
        private $Teams;
        private string $Name;

        function __cunstruct($Teams, $Name){
            if(count($Teams)%2 != 0){
                echo 'NOOOOO';
            }
            else{
                $this->Teams = $Teams;
                $this->Name = $Name;
            }

        }

        function games(){
            for($i = 0; $x < count($this->Teams);$i++){
                
            }

            // foreach($this->Teams as $t => $team){

            // }
        }

        function get_Team(){
            return $this->Team;
        }

        function set_Team($Team){
            $this->Team = $Team; 
        }
    }


?>