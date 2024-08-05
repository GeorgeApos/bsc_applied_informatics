package com.example.myapplication;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class r2Activity extends AppCompatActivity {
    int ScoreforTeamA;
    int ScoreforTeamB;
    int ReboundsForTeamA;
    int ReboundsForTeamB;
    int AssistsForTeamA;
    int AssistsForTeamB;
    int MistakesForTeamA;
    int MistakesForTeamB;
    int FoulsForTeamA;
    int FoulsForTeamB;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_r2);
    }
        /**
         * TEAM A
         */
        public void addThreeForTeamA(View v){
            ScoreforTeamA=ScoreforTeamA+3;
            displayForTeamA(ScoreforTeamA);

        }
        public void addTwoForTeamA(View v){
            ScoreforTeamA=ScoreforTeamA+2;
            displayForTeamA(ScoreforTeamA);

        }
        public void addOneForTeamA(View v){
            ScoreforTeamA=ScoreforTeamA+1;
            displayForTeamA(ScoreforTeamA);

        }

        public void addReboundForTeamA(View v){
            ReboundsForTeamA=ReboundsForTeamA+1;
            displayReboundsForTeamA(ReboundsForTeamA);
        }

        public void addAssistForTeamA(View v){
            AssistsForTeamA=AssistsForTeamA+1;
            displayAssistsForTeamA(AssistsForTeamA);
        }

        public void addMistakeForTeamA(View v){
            MistakesForTeamA=MistakesForTeamA+1;
            displayMistakesForTeamA(MistakesForTeamA);
        }

        public void addFoulForTeamA(View v){
            FoulsForTeamA=FoulsForTeamA+1;
            displayFoulsForTeamA(FoulsForTeamA);
        }

        /**
         * TEAM B
         */
        public void addThreeForTeamB(View v){
            ScoreforTeamB=ScoreforTeamB+3;
            displayForTeamB(ScoreforTeamB);

        }
        public void addTwoForTeamB(View v){
            ScoreforTeamB=ScoreforTeamB+2;
            displayForTeamB(ScoreforTeamB);

        }
        public void addOneForTeamB(View v){
            ScoreforTeamB=ScoreforTeamB+1;
            displayForTeamB(ScoreforTeamB);

        }

        public void addReboundForTeamB(View v){
            ReboundsForTeamB=ReboundsForTeamB+1;
            displayReboundsForTeamB(ReboundsForTeamB);
        }

        public void addAssistForTeamB(View v){
            AssistsForTeamB=AssistsForTeamB+1;
            displayAssistsForTeamB(AssistsForTeamB);
        }

        public void addMistakeForTeamB(View v){
            MistakesForTeamB=MistakesForTeamB+1;
            displayMistakesForTeamB(MistakesForTeamB);
        }

        public void addFoulForTeamB(View v){
            FoulsForTeamB=FoulsForTeamB+1;
            displayFoulsForTeamB(FoulsForTeamB);
        }


    public void resetScore(View v){
            ScoreforTeamA=0;
            ScoreforTeamB=0;
            ReboundsForTeamA=0;
            ReboundsForTeamB=0;
            AssistsForTeamA=0;
            AssistsForTeamB=0;
            MistakesForTeamA=0;
            MistakesForTeamB=0;
            FoulsForTeamA=0;
            FoulsForTeamB=0;
            displayForTeamA(ScoreforTeamA);
            displayForTeamB(ScoreforTeamB);
            displayReboundsForTeamA(ReboundsForTeamA);
            displayReboundsForTeamA(ReboundsForTeamB);
            displayAssistsForTeamA(AssistsForTeamA);
            displayAssistsForTeamB(AssistsForTeamB);
            displayMistakesForTeamA(MistakesForTeamA);
            displayMistakesForTeamB(MistakesForTeamB);
            displayForTeamA(FoulsForTeamA);
            displayForTeamB(FoulsForTeamB);

        }
        /**
         * Displays the given score for Team A.
         */
        public void displayForTeamA(int score) {
            TextView scoreView = (TextView) findViewById(R.id.team_a_score);
            scoreView.setText(String.valueOf(score));
        }
        /**
         * Displays the given score for Team B.
         */
        public void displayForTeamB(int score) {
            TextView scoreView = (TextView) findViewById(R.id.team_b_score);
            scoreView.setText(String.valueOf(score));
        }
        /**
        * Displays the rebounds for Team A.
        */
        public void displayReboundsForTeamA(int rebounds) {
            TextView reboundView = (TextView) findViewById(R.id.rebounds_a_score);
            reboundView.setText(String.valueOf(rebounds));
        }
        /**
         * Displays the rebounds for Team Β.
         */
         public void displayReboundsForTeamB(int rebounds) {
             TextView reboundView = (TextView) findViewById(R.id.rebounds_b_score);
            reboundView.setText(String.valueOf(rebounds));
         }
        /**
         * Displays the assists for Team A.
         */
        public void displayAssistsForTeamA(int assists) {
            TextView assistView = (TextView) findViewById(R.id.assists_a_score);
            assistView.setText(String.valueOf(assists));
        }
        /**
         * Displays the assists for Team B.
         */
        public void displayAssistsForTeamB(int assists) {
            TextView assistView = (TextView) findViewById(R.id.assists_b_score);
            assistView.setText(String.valueOf(assists));
        }
        /**
         * Displays the mistakes for Team A.
         */
        public void displayMistakesForTeamA(int mistakes) {
            TextView mistakesView = (TextView) findViewById(R.id.mistakes_a_score);
            mistakesView.setText(String.valueOf(mistakes));
        }
        /**
         * Displays the mistakes for Team B.
         */
        public void displayMistakesForTeamB(int mistakes) {
            TextView mistakesView = (TextView) findViewById(R.id.mistakes_b_score);
            mistakesView.setText(String.valueOf(mistakes));
        }
        /**
         * Displays the fouls for Team A.
         */
        public void displayFoulsForTeamA(int fouls) {
            TextView mistakesView = (TextView) findViewById(R.id.fouls_a_score);
            mistakesView.setText(String.valueOf(fouls));
        }
        /**
         * Displays the fouls for Team B.
         */
        public void displayFoulsForTeamB(int fouls) {
            TextView foulsView = (TextView) findViewById(R.id.fouls_b_score);
            foulsView.setText(String.valueOf(fouls));
        }
    }
