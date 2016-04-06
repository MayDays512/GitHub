package com.liqiao.rjapp;

import java.util.Random;

import com.liqiao.rjapp.R;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
//变量***************************************************************************
	Random ran=new Random(System.currentTimeMillis());
	private TextView tvTimu=null;
	private EditText edtWidth= null;
	private EditText edtCcf= null;
	private EditText edtYushu= null;
	private EditText edtFushu= null;
//	private EditText edtResult= null;
//	private TextView tvJudge=null;
//	private TextView tvZongping=null;

//函数***************************************************************************
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
        tvTimu=(TextView)findViewById(R.id.tvTimu);
        edtWidth=(EditText)findViewById(R.id.edtWidth);
        edtCcf=(EditText)findViewById(R.id.edtCcf);
        edtYushu=(EditText)findViewById(R.id.edtYushu);
        edtFushu=(EditText)findViewById(R.id.edtFushu);
//        edtResult=(EditText)findViewById(R.id.edtResult);
//        tvJudge=(TextView)findViewById(R.id.tvJudge);
//        tvZongping=(TextView)findViewById(R.id.tvZongping);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	@Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
	//主要代码
    public void btnSure_Click(View v){
        int sign,j;
    	int fanwei,chengchu,yushu,fushu;
    	int first,second,firstm,secondm;
    	String s2="",s3="",s4="",s5="";
    	s2=edtWidth.getText().toString();
   	    s3=edtCcf.getText().toString();
    	s4=edtYushu.getText().toString();
    	s5=edtFushu.getText().toString();
    	fanwei=Integer.parseInt(s2);//范围
     	chengchu=Integer.parseInt(s3);//乘除法
     	yushu=Integer.parseInt(s4);//余数
    	fushu=Integer.parseInt(s5);//负数
    	
        j=ran.nextInt(2);
        if(j==0)           //选择整数
    	{
    		first=ran.nextInt(fanwei+1);
    		second=ran.nextInt(fanwei+1);
    		if(chengchu==1)
    		{
    			sign=ran.nextInt(4); 
    		}
    		else
    		{
    			sign=ran.nextInt(2);
    		}
    		switch(sign)
    		{
    		case 0:                      //整数加法
    			tvTimu.setText("题目："+first+"+"+second+"=");
    			break;
    		case 1:                      //整数减法
    			if(fushu==1)
    			{
    				tvTimu.setText("题目："+first+"-"+second+"=");
    			}
    			else
    			{
    				if(first>second)
    				{
    					tvTimu.setText("题目："+first+"-"+second+"=");
    				}
    				else
    				{
    					tvTimu.setText("题目："+second+"-"+first+"=");
    				}
    			}
    			break;
    		case 2:                   //整数乘法
    			tvTimu.setText("题目："+first+"*"+second+"=");
    			break; 
    		case 3:                   //整数除法
    			if(yushu==1)
    			{
            		if(second!=0)
    				{
            			tvTimu.setText("题目："+first+"/"+second+"=");
    				}
    			}
    			else
    			{
    				if(second!=0&&(first%second==0))
    				{
    					tvTimu.setText("题目："+first+"/"+second+"=");
    				}
    			}
    				break;
    		}
    	}
        else              //选择分数
		{
			first=ran.nextInt(fanwei+1);
			second=ran.nextInt(fanwei+1);//分子
			firstm=ran.nextInt(fanwei+1);
			secondm=ran.nextInt(fanwei+1);//分母
			if(chengchu==1)
			{
				sign=ran.nextInt(4);
			}
			else
			{
				sign=ran.nextInt(2);
			}

			switch(sign)
			{
			case 0:                //分数加法
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
				{
					tvTimu.setText("题目："+first+"/"+firstm+" + "+second+"/"+secondm+"=");
				}
				break;
			case 1:                //分数减法
				if(fushu==1)
				{
					if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
				    {
						tvTimu.setText("题目："+first+"/"+firstm+" - "+second+"/"+secondm+"=");
				    }
				}
				else
				{
					if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm&&(first/firstm)>(second/secondm))
					{
						tvTimu.setText("题目："+first+"/"+firstm+" - "+second+"/"+secondm+"=");
				    }
				}
				break;
			case 2:                //分数乘法
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
				{
					tvTimu.setText("题目："+first+"/"+firstm+" * "+second+"/"+secondm+"=");
				}
				break;
			case 3:                //分数除法
				if(firstm!=0&&secondm!=0&&first!=0&&second!=0&&first<firstm&&second<secondm)
				{
					tvTimu.setText("题目："+first+"/"+firstm+" / "+second+"/"+secondm+"=");
				}
				break;
			}
		}
    }
 //   public void btnTijiao_Click(View v){
//		if (f == first + second)
//		{
//			tvJudge.setText("判断：答对了！");
//			right = right + 1;
//		}
//		else
//		{
//			tvJudge.setText("判断：答错了！");
//			wrong = wrong + 1;
//		}
    //}
}
