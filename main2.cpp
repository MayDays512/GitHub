//���Σ�2016.3.7
//���������������

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
	 
	cout<<"��������Ŀ������";
	cin>>num;
	if(num==0)
	{
		exit(1);
	}

	cout<<"�Ƿ��г˳�����1.�ǣ�2.��";
	cin>>chengchu;

	if(chengchu==1)
	{
		cout<<"�����Ƿ���������1.�ǣ�2.��";
	    cin>>yushu;
	}

	cout<<"�����Ƿ��и�����1.�ǣ�2.��";
	cin>>fushu;

	cout<<"��������ֵ��Χ��";
	cin>>fanwei;

	srand((int)time(NULL)); //��ʱ�������ӣ�ÿ�β������������һ��

	for(i=0;i<num;i++)
	{
		j=rand()%2;        //ѡ�������������㻹�Ƿ�������

		if(j==0)           //ѡ������
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
			case 0:                      //�����ӷ�
				cout<<first<<"+"<<second<<"="<<endl;
				break;
			case 1:                      //��������
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
			case 2:                   //�����˷�
				cout<<first<<"*"<<second<<"="<<endl;
				break; 
			case 3:                   //��������
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

		else              //ѡ�����
		{
			first=rand()%(fanwei+1);
			second=rand()%(fanwei+1);//����
			firstm=rand()%(fanwei+1);
			secondm=rand()%(fanwei+1);//��ĸ
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
			case 0:                //�����ӷ�
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
				{
					cout<<first<<"/"<<firstm<<"  +  "<<second<<"/"<<secondm<<"="<<endl;
				}
				else
				{
					i=i-1;
				}
				break;
			case 1:                //��������
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
			case 2:                //�����˷�
				if(firstm!=0&&secondm!=0&&first<firstm&&second<secondm)
				{
					cout<<first<<"/"<<firstm<<"  *  "<<second<<"/"<<secondm<<"="<<endl;
				}
				else
				{
					i=i-1;
				}
				break;
			case 3:                //��������
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