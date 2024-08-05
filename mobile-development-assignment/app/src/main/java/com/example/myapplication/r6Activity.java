package com.example.myapplication;

import android.graphics.Color;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.squareup.picasso.Picasso;

public class r6Activity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_r6);

        //Dummy Data
        String teamAName = "Olympiakos";
        String teamBName = "Panathinaikos";
        String teamAImage = "https://upload.wikimedia.org/wikipedia/el/thumb/7/7f/Olympiacos_BC_logo.svg/800px-Olympiacos_BC_logo.svg.png";
        String teamBImage = "https://upload.wikimedia.org/wikipedia/en/thumb/1/18/Panathinaikos_BC_logo.svg/1200px-Panathinaikos_BC_logo.svg.png";
        int teamAScore = 62;
        int teamBScore = 70;
        Integer[] teamAFreeThrows = new Integer[]{20, 50};   /* Index 0: Hit | Index 1: Hit+Missed */
        Integer[] teamBFreeThrows = new Integer[]{23, 52};
        Integer[] teamA2Pointers = new Integer[]{26, 32};
        Integer[] teamB2Pointers = new Integer[]{25, 56};
        Integer[] teamA3Pointers = new Integer[]{16, 30};
        Integer[] teamB3Pointers = new Integer[]{22, 56};

        int teamARebound = 23;
        int teamBRebound = 14;
        int teamAFouls = 17;
        int teamBFouls = 24;
        int teamAAssists = 35;
        int teamBAssists = 33;
        int teamABlocks = 10;
        int teamBBlocks = 11;
        int teamAMistakes = 16;
        int teamBMistakes = 18;
        int teamASteals = 19;
        int teamBSteals = 25;




        ((TextView)findViewById(R.id.teamAName)).setText(teamAName);
        ((TextView)findViewById(R.id.teamBName)).setText(teamBName);

//        Picasso.with(this).setLoggingEnabled(true);
        Picasso.with(this).load(teamAImage).resize(200, 0).into((ImageView) findViewById(R.id.teamAImage));
        Picasso.with(this).load(teamBImage).resize(200, 0).into((ImageView) findViewById(R.id.teamBImage));

        if(teamAScore > teamBScore) {
            ((TextView)findViewById(R.id.teamAScore)).setTextColor(Color.GREEN);
            ((TextView)findViewById(R.id.teamBScore)).setTextColor(Color.RED);
        }
        if(teamAScore < teamBScore) {
            ((TextView)findViewById(R.id.teamBScore)).setTextColor(Color.GREEN);
            ((TextView)findViewById(R.id.teamAScore)).setTextColor(Color.RED);
        }
        ((TextView)findViewById(R.id.teamAScore)).setText(String.valueOf(teamAScore));
        ((TextView)findViewById(R.id.teamBScore)).setText(String.valueOf(teamBScore));


        if(teamAFreeThrows[1] != 0) {
            ((TextView)findViewById(R.id.teamAFreeThrows)).setText(teamAFreeThrows[0] + "/" + teamAFreeThrows[1] + " (" + String.format("%.2f",(double)teamAFreeThrows[0]/teamAFreeThrows[1]*100) + "%)");
        } else {
            ((TextView)findViewById(R.id.teamAFreeThrows)).setText(teamAFreeThrows[0] + "/" + teamAFreeThrows[1] + " (-%)");
        }

        if(teamBFreeThrows[1] != 0) {
            ((TextView)findViewById(R.id.teamBFreeThrows)).setText(teamBFreeThrows[0] + "/" + teamBFreeThrows[1] + " (" + String.format("%.2f",(double)teamBFreeThrows[0]/teamBFreeThrows[1]*100) + "%)");
        } else {
            ((TextView)findViewById(R.id.teamBFreeThrows)).setText(teamBFreeThrows[0] + "/" + teamBFreeThrows[1] + " (-%)");
        }

        if(teamA2Pointers[1] != 0) {
            ((TextView)findViewById(R.id.teamA2Pointers)).setText(teamA2Pointers[0] + "/" + teamA2Pointers[1] + " (" + String.format("%.2f",(double)teamA2Pointers[0]/teamA2Pointers[1]*100) + "%)");
        } else {
            ((TextView)findViewById(R.id.teamA2Pointers)).setText(teamA2Pointers[0] + "/" + teamA2Pointers[1] + " (-%)");
        }
        if(teamB2Pointers[1] != 0) {
            ((TextView)findViewById(R.id.teamB2Pointers)).setText(teamB2Pointers[0] + "/" + teamB2Pointers[1] + " (" + String.format("%.2f",(double)teamB2Pointers[0]/teamB2Pointers[1]*100) + "%)");
        } else {
            ((TextView)findViewById(R.id.teamB2Pointers)).setText(teamB2Pointers[0] + "/" + teamB2Pointers[1] + " (-%)");
        }

        if(teamA3Pointers[1] != 0) {
            ((TextView)findViewById(R.id.teamA3Pointers)).setText(teamA3Pointers[0] + "/" + teamA3Pointers[1] + " (" + String.format("%.2f",(double)teamA3Pointers[0]/teamA3Pointers[1]*100) + "%)");
        } else {
            ((TextView)findViewById(R.id.teamA3Pointers)).setText(teamA3Pointers[0] + "/" + teamA3Pointers[1] + " (-%)");
        }
        if(teamB3Pointers[1] != 0) {
            ((TextView)findViewById(R.id.teamB3Pointers)).setText(teamB3Pointers[0] + "/" + teamB3Pointers[1] + " (" + String.format("%.2f",(double)teamB3Pointers[0]/teamB3Pointers[1]*100) + "%)");
        } else {
            ((TextView)findViewById(R.id.teamB3Pointers)).setText(teamB3Pointers[0] + "/" + teamB3Pointers[1] + " (-%)");
        }


        ((TextView)findViewById(R.id.teamARebound)).setText(String.valueOf(teamARebound));
        ((TextView)findViewById(R.id.teamBRebound)).setText(String.valueOf(teamBRebound));
        ((TextView)findViewById(R.id.teamAFouls)).setText(String.valueOf(teamAFouls));
        ((TextView)findViewById(R.id.teamAFouls)).setText(String.valueOf(teamAFouls));
        ((TextView)findViewById(R.id.teamBFouls)).setText(String.valueOf(teamBFouls));
        ((TextView)findViewById(R.id.teamAAssists)).setText(String.valueOf(teamAAssists));
        ((TextView)findViewById(R.id.teamBAssists)).setText(String.valueOf(teamBAssists));
        ((TextView)findViewById(R.id.teamABlocks)).setText(String.valueOf(teamABlocks));
        ((TextView)findViewById(R.id.teamBBlocks)).setText(String.valueOf(teamBBlocks));
        ((TextView)findViewById(R.id.teamAMistakes)).setText(String.valueOf(teamAMistakes));
        ((TextView)findViewById(R.id.teamBMistakes)).setText(String.valueOf(teamBMistakes));
        ((TextView)findViewById(R.id.teamASteals)).setText(String.valueOf(teamASteals));
        ((TextView)findViewById(R.id.teamBSteals)).setText(String.valueOf(teamBSteals));


    }


}
