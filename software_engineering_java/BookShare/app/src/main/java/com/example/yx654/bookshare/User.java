package com.example.yx654.bookshare;
import android.app.Activity;
import android.widget.Toast;
import java.util.List;
import android.content.Intent;
import cn.bmob.v3.BmobObject;
import cn.bmob.v3.BmobQuery;
import cn.bmob.v3.exception.BmobException;
import cn.bmob.v3.listener.FindListener;
import org.json.JSONArray;
/**
 * Created by yx654 on 2016/11/22.
 */
public class User extends BmobObject{
    private String username;
    private String password;
    private String gender;
    private  Integer age;
    private  String userid;

    public String getUserid() {
        return userid;
    }

    public void setUserid(String userid) {
        this.userid = userid;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public  String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }



}
