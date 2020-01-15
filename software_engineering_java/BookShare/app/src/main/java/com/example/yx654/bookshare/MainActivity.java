package com.example.yx654.bookshare;
import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.appindexing.Thing;
import com.google.android.gms.common.api.GoogleApiClient;

import java.util.List;

import cn.bmob.v3.Bmob;
import cn.bmob.v3.BmobQuery;
import cn.bmob.v3.exception.BmobException;
import cn.bmob.v3.listener.FindListener;

public class MainActivity extends AppCompatActivity {
    Button btnlogin;
    Button btnregister;
    EditText textusername;
    EditText textpassword;

    Button btntest;


    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Bmob.initialize(this, "a93d43ca80b731919f820c0a7dc8e856");


        btnlogin = (Button) findViewById(R.id.button_login);
        btnregister = (Button) findViewById(R.id.button_register);
        textusername = (EditText) findViewById(R.id.text_username);
        textpassword = (EditText) findViewById(R.id.text_password);

     //   btntest = (Button)findViewById(R.id.button_test);

//用户登录
        btnlogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                BmobQuery<User> query = new BmobQuery<User>();
                query.addQueryKeys("password");
                query.addWhereEqualTo("username",textusername.getText().toString());
               // Toast.makeText(getApplicationContext(), textusername.getText().toString(), Toast.LENGTH_SHORT).show();
                query.findObjects(new FindListener<User>() {
                    @Override
                    public void done(List<User> obt, BmobException e) {
                        if (e == null) {
                          //  System.out.println(obt.get(0).getPassword().toString());
                         //   Toast.makeText(getApplicationContext(), obt.get(0).getPassword().toString(), Toast.LENGTH_SHORT).show();
                                if(obt.get(0).getPassword().toString().equals(textpassword.getText().toString())){
                                    Toast.makeText(getApplicationContext(), "登陆成功", Toast.LENGTH_SHORT).show();
                                    //成功后进入主界面
                                    Intent intent = new Intent(MainActivity.this, Maincenter.class);
                                    startActivity(intent);

                                } else {
                                    Toast.makeText(getApplicationContext(), "密码错误", Toast.LENGTH_SHORT).show();
                                }


                        } else {
                            Toast.makeText(getApplicationContext(), "该账号未注册", Toast.LENGTH_SHORT).show();
                        }
                    }
                });

            }
        });

        btnregister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, RegisterActivity.class);
                startActivity(intent);
            }
        });



       // btntest.setOnClickListener(new View.OnClickListener() {
          //  @Override
          //  public void onClick(View v) {
        //        Intent intent = new Intent(MainActivity.this, UploadActivity.class);
        //        startActivity(intent);
      //      }
       // });











        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();
    }

    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    public Action getIndexApiAction() {
        Thing object = new Thing.Builder()
                .setName("Main Page") // TODO: Define a title for the content shown.
                // TODO: Make sure this auto-generated URL is correct.
                .setUrl(Uri.parse("http://[ENTER-YOUR-URL-HERE]"))
                .build();
        return new Action.Builder(Action.TYPE_VIEW)
                .setObject(object)
                .setActionStatus(Action.STATUS_TYPE_COMPLETED)
                .build();
    }

    @Override
    public void onStart() {
        super.onStart();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client.connect();
        AppIndex.AppIndexApi.start(client, getIndexApiAction());
    }

    @Override
    public void onStop() {
        super.onStop();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        AppIndex.AppIndexApi.end(client, getIndexApiAction());
        client.disconnect();
    }
}
