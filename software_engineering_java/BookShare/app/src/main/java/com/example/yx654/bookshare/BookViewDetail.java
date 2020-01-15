package com.example.yx654.bookshare;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.json.JSONArray;
import org.w3c.dom.Text;

import cn.bmob.v3.BmobQuery;
import cn.bmob.v3.exception.BmobException;
import cn.bmob.v3.listener.QueryListener;

/**
 * Created by D on 2016/11/22.
 */
public class BookViewDetail extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_book_detail);

        final TextView bookname= (TextView)findViewById(R.id.bnamedetail);
        final TextView press= (TextView)findViewById(R.id.bpressdetail);
        final TextView author= (TextView)findViewById(R.id.bauthordetail);
        final TextView rate= (TextView)findViewById(R.id.bratedetail);
        final TextView ISBN= (TextView)findViewById(R.id.bISBNdetail);
        final TextView price= (TextView)findViewById(R.id.bpricedetail);
        final TextView type= (TextView)findViewById(R.id.btypedetail);
        final TextView detail= (TextView)findViewById(R.id.bdetaildetail);

        Button btAddToChart = (Button) findViewById(R.id.adddetail);


        String keyId= getIntent().getStringExtra("keyId");

        BmobQuery<Books> query =new BmobQuery<>();
        query.getObject(keyId, new QueryListener<Books>() {
            @Override
            public void done(Books books, BmobException e) {
                if (e==null){
                    bookname.setText(books.getBookname());
                    author.setText(books.getAuthor());
                    rate.setText(books.getRate());
                    ISBN.setText(books.getISBN());
                    price.setText(books.getPrice());
                    type.setText(books.getType());
                    detail.setText(books.getDetail());
                    press.setText(books.getPress());

                }else {
                    Toast toast=Toast.makeText(getApplicationContext(),
                            "error", Toast.LENGTH_SHORT);
                    toast.show();
                }
            }
        });

        btAddToChart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast toast=Toast.makeText(getApplicationContext(),
                        "加入购物车成功",Toast.LENGTH_SHORT);
                toast.show();
            }
        });


    }
}
