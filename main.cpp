//���Σ�2016.3.3
//���������������

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

void main()
{
	int first,second,firstm,secondm;
	int sign,i,j;
	srand((int)time(NULL)); //��ʱ�������ӣ�ÿ�β������������һ��
	for(i=0;i<30;i++)
	{
		j=rand()%2;        //ѡ�������������㻹�Ƿ�������

		if(j==0)           //ѡ������
		{
			first=rand()%100;
			second=rand()%100;
			sign=rand()%4;

			switch(sign)
			{
			case 0:                                   //�����ӷ�
				cout<<first<<"+"<<second<<"="<<endl;
				break;
			case 1:                                    //��������
				if(first>second)
					cout<<first<<"-"<<second<<"="<<endl;
				else
					cout<<second<<"-"<<first<<"="<<endl;
				break;
			case 2:                                     //�����˷�
				cout<<first<<"*"<<second<<"="<<endl;
				break; 
			case 3:                                     //��������
				if(second!=0)
					cout<<first<<"/"<<second<<"="<<endl;
				else
					cout<<second<<"/"<<first<<"="<<endl;
				break;
			}
		}

		else              //ѡ�����
		{
			first=rand()%100;
			second=rand()%100;//����
			firstm=rand()%100;
			secondm=rand()%100;//��ĸ
			sign=rand()%4;

			switch(sign)
			{
			case 0://�����ӷ�
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
					cout<<first<<"/"<<firstm<<"  +  "<<second<<"/"<<secondm<<"="<<endl;
				else
					i=i-1;
				break;
			case 1://��������
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm&&(first/firstm)>(second/secondm))
					cout<<first<<"/"<<firstm<<"  -  "<<second<<"/"<<secondm<<"="<<endl;
				else
					i=i-1;
				break;
			case 2://�����˷�
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
					cout<<first<<"/"<<firstm<<"  *  "<<second<<"/"<<secondm<<"="<<endl;
				else
					i=i-1;
				break;
			case 3://��������
				if(firstm!=0&&secondm!=0&&first!=0&&second!=0&&first<firstm&&second<secondm)
					cout<<first<<"/"<<firstm<<"  /  "<<second<<"/"<<secondm<<"="<<endl;
				else
					i=i-1;
				break;
			}
		}
	}
} 