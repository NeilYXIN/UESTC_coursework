package com.example.yx654.bookshare;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Maincenter extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maincenter);


        Button btUpload = (Button) findViewById(R.id.upload);
        final EditText btToSearch = (EditText) findViewById(R.id.ToSearch);

        btToSearch.setOnKeyListener(new View.OnKeyListener() {
            @Override
            public boolean onKey(View view, int i, KeyEvent keyEvent) {
                if(i == KeyEvent.KEYCODE_ENTER){

                    String keyWord= btToSearch.getText().toString();
                    Intent intent=new Intent(Maincenter.this,BookView.class);
                    intent.putExtra("keyWord",keyWord);
                    startActivity(intent);

                    return true;

                }

                return false;
            }
        });


        btUpload.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(Maincenter.this, UploadActivity.class);
                startActivity(intent);

            }
        });

    }
}
