//李俏，2016.3.3
//随机生成四则运算

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

void main()
{
	int first,second,firstm,secondm;
	int sign,i,j;
	srand((int)time(NULL)); //用时间做种子，每次产生随机数都不一样
	for(i=0;i<30;i++)
	{
		j=rand()%2;        //选择生成整数运算还是分数运算

		if(j==0)           //选择整数
		{
			first=rand()%100;
			second=rand()%100;
			sign=rand()%4;

			switch(sign)
			{
			case 0:                                   //整数加法
				cout<<first<<"+"<<second<<"="<<endl;
				break;
			case 1:                                    //整数减法
				if(first>second)
					cout<<first<<"-"<<second<<"="<<endl;
				else
					cout<<second<<"-"<<first<<"="<<endl;
				break;
			case 2:                                     //整数乘法
				cout<<first<<"*"<<second<<"="<<endl;
				break; 
			case 3:                                     //整数除法
				if(second!=0)
					cout<<first<<"/"<<second<<"="<<endl;
				else
					cout<<second<<"/"<<first<<"="<<endl;
				break;
			}
		}

		else              //选择分数
		{
			first=rand()%100;
			second=rand()%100;//分子
			firstm=rand()%100;
			secondm=rand()%100;//分母
			sign=rand()%4;

			switch(sign)
			{
			case 0://分数加法
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
					cout<<first<<"/"<<firstm<<"  +  "<<second<<"/"<<secondm<<"="<<endl;
				else
					i=i-1;
				break;
			case 1://分数减法
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm&&(first/firstm)>(second/secondm))
					cout<<first<<"/"<<firstm<<"  -  "<<second<<"/"<<secondm<<"="<<endl;
				else
					i=i-1;
				break;
			case 2://分数乘法
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
					cout<<first<<"/"<<firstm<<"  *  "<<second<<"/"<<secondm<<"="<<endl;
				else
					i=i-1;
				break;
			case 3://分数除法
				if(firstm!=0&&secondm!=0&&first!=0&&second!=0&&first<firstm&&second<secondm)
					cout<<first<<"/"<<firstm<<"  /  "<<second<<"/"<<secondm<<"="<<endl;
				else
					i=i-1;
				break;
			}
		}
	}
} 