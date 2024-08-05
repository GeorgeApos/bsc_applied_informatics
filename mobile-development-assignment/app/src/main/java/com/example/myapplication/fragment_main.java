package com.example.myapplication;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class fragment_main extends Activity {


    private Button r2, r6,r10;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_main);

        r2 = (Button) findViewById(R.id.show_requirement23);
        r2.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                Intent intent = new Intent(v.getContext(), r2Activity.class);
                startActivity(intent);
            }
        });

        r6 = (Button) findViewById(R.id.show_requirement6);
        r6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(v.getContext(), r6Activity.class);
                startActivity(intent);
            }
        });

        r10 = (Button) findViewById(R.id.show_requirement10);
        r10.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                Intent intent = new Intent(v.getContext(), r10Activity.class);
                startActivity(intent);
            }
        });


    }

}
