//����,��ˮ���������
//2016.5.19
#include<iostream>
using namespace std;

void main()
{
	int num,arr[1000];
	int wknum=0, wkresult;//ˮ�����ֵĴ�����ˮ����ID
	int i;

	cout << "���������ӵ�������";
	cin >> num;

	cout << "����������ID��" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
  
	for (i = 0; i != num; i++)
	{
		if (wknum == 0)//û�г�����ͬ��ID
		{ 
			wkresult = arr[i];//�ʹӵ�ǰID���¿�ʼ
			wknum++;
		}
		else//������ͬID
		{ 
			if (wkresult == arr[i])
			{ 
				wknum++;
			}
			else
			{  
				wknum--;
			}
		}
	}

	cout << "ˮ����IDΪ��" << wkresult << endl;
}

