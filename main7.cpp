//李俏,找水王抽象程序
//2016.5.19
#include<iostream>
using namespace std;

void main()
{
	int num,arr[1000];
	int wknum=0, wkresult;//水王出现的次数和水王的ID
	int i;

	cout << "请输入帖子的数量：";
	cin >> num;

	cout << "请输入帖子ID：" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
  
	for (i = 0; i != num; i++)
	{
		if (wknum == 0)//没有出现相同的ID
		{ 
			wkresult = arr[i];//就从当前ID重新开始
			wknum++;
		}
		else//出现相同ID
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

	cout << "水王的ID为：" << wkresult << endl;
}

