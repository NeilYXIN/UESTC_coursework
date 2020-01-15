package com.example.yx654.bookshare;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import cn.bmob.v3.BmobQuery;
import cn.bmob.v3.exception.BmobException;
import cn.bmob.v3.listener.FindListener;

/**
 * Created by D on 2016/11/22.
 */
public class BookView extends AppCompatActivity {

    ListView listView;
    List<Books> listAll;
    List<Map<String, Object>> list = new ArrayList<Map<String, Object>>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.view_book);
        listView = (ListView) findViewById(R.id.listView);
        String keyWord= getIntent().getStringExtra("keyWord");

        BmobQuery<Books> query=new BmobQuery<Books>();
        query.addWhereEqualTo("bookname",keyWord);
        query.setLimit(50);
        query.order("-createdAt");
        query.findObjects(new FindListener<Books>() {
            @Override
            public void done(List<Books> list, BmobException e) {
                if (e == null) {
                    if (!list.isEmpty()) {
                        listAll = list;

                        SimpleAdapter adapter = new SimpleAdapter(BookView.this, getData(), R.layout.list_item,
                                new String[]{"bookname", "author", "press",
                                        "price", "rate", "type"},
                                new int[]{R.id.bname, R.id.bauthor, R.id.bpress,
                                        R.id.bprice, R.id.brate, R.id.btype});
                        listView.setAdapter(adapter);

                        Toast toast = Toast.makeText(getApplicationContext(),
                                "查询成功，共" + list.size() + "条数据", Toast.LENGTH_SHORT);
                        toast.show();
                    } else {
                        Toast toast = Toast.makeText(getApplicationContext(),
                                "无此书信息,请返回重新搜索", Toast.LENGTH_SHORT);
                        toast.show();
                    }
                }

            }

        });



        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Intent intent = new Intent(BookView.this, BookViewDetail.class);
                String keyId = list.get(i).get("id").toString();
                intent.putExtra("keyId",keyId);
                startActivity(intent);
            }
        });

    }

    private List<Map<String, Object>> getData() {//将listAll变为list，便于使用SimpleAdapter


        Map<String, Object> map;
        for (int i=0;i<listAll.size();i++ ){
            Books temp=listAll.get(i);
            map = new HashMap<String, Object>();
            map.put("bookname", temp.getBookname());
            map.put("author", temp.getAuthor());
            map.put("press", temp.getPress());
            map.put("price", temp.getPrice());
            map.put("rate",temp.getRate());
            map.put("type", temp.getType());
            map.put("id",temp.getObjectId());

            list.add(map);
        }

        return list;
    }

}
