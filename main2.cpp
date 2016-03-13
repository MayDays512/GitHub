//李俏，2016.3.7
//随机生成四则运算

#include<iostream>
#include<fstream> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

void main()
{
	int first,second,firstm,secondm;
	int sign,i,j;
	int num,chengchu,fushu,yushu,fanwei;
	 
	cout<<"请输入题目数量：";
	cin>>num;
	if(num==0)
	{
		exit(1);
	}

	cout<<"是否有乘除法？1.是，2.否：";
	cin>>chengchu;

	if(chengchu==1)
	{
		cout<<"除法是否有余数？1.是，2.否：";
	    cin>>yushu;
	}

	cout<<"减法是否有负数？1.是，2.否：";
	cin>>fushu;

	cout<<"请输入数值范围：";
	cin>>fanwei;

	srand((int)time(NULL)); //用时间做种子，每次产生随机数都不一样

	for(i=0;i<num;i++)
	{
		j=rand()%2;        //选择生成整数运算还是分数运算

		if(j==0)           //选择整数
		{
			first=rand()%(fanwei+1);
			second=rand()%(fanwei+1);
			if(chengchu==1)
			{
				sign=rand()%4; 
			}
			else
			{
				sign=rand()%2;
			}
			switch(sign)
			{
			case 0:                      //整数加法
				cout<<first<<"+"<<second<<"="<<endl;
				break;
			case 1:                      //整数减法
				if(fushu==1)
				{
					cout<<first<<"-"<<second<<"="<<endl;
				}
				else
				{
					if(first>second)
					{
						cout<<first<<"-"<<second<<"="<<endl;
					}
					else
					{
						cout<<second<<"-"<<first<<"="<<endl;
					}
				}
				break;
			case 2:                   //整数乘法
				cout<<first<<"*"<<second<<"="<<endl;
				break; 
			case 3:                   //整数除法
				if(yushu==1)
				{
        			if(second!=0)
				    {
						cout<<first<<"/"<<second<<"="<<endl;
				    }
				    else
					{
						i=i-1;
				    }
				}
				else
				{
					if(second!=0&&(first%second==0))
					{
						cout<<first<<"/"<<second<<"="<<endl;
					}
					else
					{
						i=i-1;
				    }
				}
				break;
			}
		}

		else              //选择分数
		{
			first=rand()%(fanwei+1);
			second=rand()%(fanwei+1);//分子
			firstm=rand()%(fanwei+1);
			secondm=rand()%(fanwei+1);//分母
			if(chengchu==1)
			{
				sign=rand()%4;
			}
			else
			{
				sign=rand()%2;
			}

			switch(sign)
			{
			case 0:                //分数加法
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
				{
					cout<<first<<"/"<<firstm<<"  +  "<<second<<"/"<<secondm<<"="<<endl;
				}
				else
				{
					i=i-1;
				}
				break;
			case 1:                //分数减法
				if(fushu==1)
				{
					if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
				    {
						cout<<first<<"/"<<firstm<<"  -  "<<second<<"/"<<secondm<<"="<<endl;
				    }
				    else
				    {
						i=i-1;
				    }
				}
				else
				{
					if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm&&(first/firstm)>(second/secondm))
					{
					   cout<<first<<"/"<<firstm<<"  -  "<<second<<"/"<<secondm<<"="<<endl;
				    }
				   else
				   {
					   i=i-1;
					}
				}
				break;
			case 2:                //分数乘法
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
				{
					cout<<first<<"/"<<firstm<<"  *  "<<second<<"/"<<secondm<<"="<<endl;
				}
				else
				{
					i=i-1;
				}
				break;
			case 3:                //分数除法
				if(firstm!=0&&secondm!=0&&first!=0&&second!=0&&first<firstm&&second<secondm)
				{
					cout<<first<<"/"<<firstm<<"  /  "<<second<<"/"<<secondm<<"="<<endl;
				}
				else
				{
					i=i-1;
				}
				break;
			}
		}
	}
}   