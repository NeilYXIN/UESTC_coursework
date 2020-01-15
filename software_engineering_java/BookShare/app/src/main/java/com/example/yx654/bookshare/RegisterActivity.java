package com.example.yx654.bookshare;

import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import cn.bmob.v3.Bmob;
import cn.bmob.v3.BmobObject;
import cn.bmob.v3.listener.SaveListener;
import cn.bmob.v3.exception.BmobException;
import android.widget.Toast;



public class RegisterActivity extends AppCompatActivity {
    Button btnpos;
    Button btnneg;
    EditText textusernamer;
    EditText textpasswordr;
    EditText textgender;
    EditText textage;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);
        btnpos = (Button) findViewById(R.id.button_pos);
        btnneg = (Button) findViewById(R.id.button_neg);
        textusernamer = (EditText) findViewById(R.id.text_username_r);
        textpasswordr = (EditText) findViewById(R.id.text_password_r);
        textgender = (EditText) findViewById(R.id.text_gender_r);
        textage = (EditText) findViewById(R.id.text_age_r);


        //提交注册信息

        btnpos.setOnClickListener(new View.OnClickListener() {

            User user = new User();

            @Override
            public void onClick(View v) {
                user.setUsername(textusernamer.getText().toString());
                user.setPassword(textpasswordr.getText().toString());
                user.setGender(textgender.getText().toString());
                user.setAge(Integer.parseInt(textage.getText().toString()));
                user.save(new SaveListener<String>() {

                    @Override
                    public void done(String objectId, BmobException e) {
                        if (e == null) {
                            Toast.makeText(getApplicationContext(), "注册成功", Toast.LENGTH_SHORT).show();
                            Intent intent = new Intent(RegisterActivity.this, MainActivity.class);
                            startActivity(intent);
                        } else {
                            Toast.makeText(getApplicationContext(), "注册失败", Toast.LENGTH_SHORT).show();
                        }
                    }
                });
            }
        });


        //返回登陆界面
        btnneg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(RegisterActivity.this, MainActivity.class);
                startActivity(intent);
            }
        });

    }
}