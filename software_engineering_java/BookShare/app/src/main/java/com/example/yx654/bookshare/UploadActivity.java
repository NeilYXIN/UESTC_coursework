package com.example.yx654.bookshare;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import cn.bmob.v3.exception.BmobException;
import cn.bmob.v3.listener.SaveListener;

public class UploadActivity extends AppCompatActivity {

    Button btnuppos;
    Button btnupneg;

    EditText textbookname;
    EditText textpress;
    EditText textauthor;
    EditText textrate;
    EditText textisbn;
    EditText textprice;
    EditText texttype;
    EditText textdetail;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_upload);


        btnuppos=(Button)findViewById(R.id.button_up_pos);
        btnupneg=(Button)findViewById(R.id.button_up_neg);
        textbookname=(EditText)findViewById(R.id.text_bookname);
        textpress=(EditText)findViewById(R.id.text_press);
        textauthor=(EditText)findViewById(R.id.text_author);
        textrate=(EditText)findViewById(R.id.text_rate);
        textisbn=(EditText)findViewById(R.id.text_isbn);
        textprice=(EditText)findViewById(R.id.text_price);
        texttype=(EditText)findViewById(R.id.text_type);
        textdetail=(EditText)findViewById(R.id.text_detail);
        btnuppos.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Books book = new Books();
                book.setBookname(textbookname.getText().toString());
                book.setPress(textpress.getText().toString());
                book.setAuthor(textauthor.getText().toString());
                book.setRate(textrate.getText().toString());
                book.setISBN(textisbn.getText().toString());
                book.setPrice(textprice.getText().toString());
                book.setType(texttype.getText().toString());
                book.setDetail(textdetail.getText().toString());

                book.save(new SaveListener<String>() {
                              @Override
                              public void done(String s, BmobException e) {
                                  if (e == null) {
                                      Toast.makeText(getApplicationContext(), "提交成功", Toast.LENGTH_SHORT).show();
                                      //返回主界面待修改******************
                                      Intent intent = new Intent(UploadActivity.this, Maincenter.class);
                                      startActivity(intent);
                                  } else {
                                      Toast.makeText(getApplicationContext(), "提交失败", Toast.LENGTH_SHORT).show();
                                  }
                              }
                          }
                );

            }
        });


        btnupneg.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //返回主界面待修改***************
                Intent intent = new Intent(UploadActivity.this, MainActivity.class);
                startActivity(intent);
            }
        });



    }
}
