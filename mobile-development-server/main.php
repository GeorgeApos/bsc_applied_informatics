<?php 
    include 'player.php';
    include 'team.php';
    include 'tournament.php';
    
    $team1 = new basketball_team('Pao','Athens','432123432');
    $team2 = new basketball_team('Paok','Thessaloniki','43223432');
    $team3 = new basketball_team('Olympiakos','Athens','41132432');
    $team4 = new basketball_team('Aek','Athens','34321432');

    $tournament_teams = new basketball_tournament(array($team1->get_name(), $team2->get_name(), $team3->get_name(), $team4->get_name()));

    $player1 = new basketball_player('Makhs', 1, $team1->get_name(), '412334');

    

?>