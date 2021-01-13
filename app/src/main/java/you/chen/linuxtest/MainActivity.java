package you.chen.linuxtest;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;


import you.chen.breakpad.BreakpadInit;

import java.io.File;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        findViewById(R.id.bt0).setOnClickListener(this);

        initBreakpad();

    }

    /**
     * 这方法可以考虑在Application中初始化
     */
    private void initBreakpad() {
        String path = Environment.getExternalStorageDirectory() + File.separator + "youxiaochen";
        Log.i("youxiaochen", path);
        BreakpadInit.initBreakpad(path);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.bt0:
                test();
                break;
        }
    }

    public native void test();

}
