package com.example.myapplication;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;

import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.PopupMenu;
import android.widget.Toast;

import com.google.android.material.bottomnavigation.BottomNavigationView;

public class r10Activity extends AppCompatActivity implements MenuItem.OnMenuItemClickListener{


    private BottomNavigationView bottomNavigationView;
    ImageButton showMenu;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_r10);

//        bottomNavigationView = findViewById(R.id.bottomNav);
//
//        bottomNavigationView.setOnNavigationItemSelectedListener(bottomNavMethod);
//        getSupportFragmentManager().beginTransaction().replace(R.id.container, new HomeFragment()).commit();

        showMenu = (ImageButton) findViewById(R.id.show_dropdown_menu);
        showMenu.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                PopupMenu dropDownMenu = new PopupMenu(getApplicationContext(),showMenu);
                dropDownMenu.getMenuInflater().inflate(R.menu.r10_filter_menu, dropDownMenu.getMenu());
                dropDownMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
                    @Override
                    public boolean onMenuItemClick(MenuItem menuItem) {
                        Toast.makeText(getApplicationContext(), "You have clicked"+ menuItem.getTitle(), Toast.LENGTH_LONG).show();
                        return true;
                    }
                });
                dropDownMenu.show();
            }
        });

    }

    @Override
    public boolean onMenuItemClick(MenuItem menuItem) {
        return false;
    }

    private BottomNavigationView.OnNavigationItemSelectedListener bottomNavMethod=new
            BottomNavigationView.OnNavigationItemSelectedListener() {
                @Override
                public boolean onNavigationItemSelected(@NonNull MenuItem item) {

                    Fragment fragment=null;
                    setContentView(R.layout.activity_login_new);

//                    switch (item.getItemId()){
//                        case R.id.home:
//                            setContentView(R.layout.activity_login_new);
//                            break;
//                        case R.id.ranking:
//                            setContentView(R.layout.activity_login_new);
//                            break;
//                        case R.id.favourites:
//                            setContentView(R.layout.activity_login_new);
//                            break;
//                    }
                    //getSupportFragmentManager().beginTransaction().replace(R.id.container,fragment).commit();

                    return true;
                }
            };

    public void showDropDownMenu(View view) {

    }
}