//李俏,找水王续抽象程序
//2016.5.25

#include<iostream> 
using namespace std;

void FindWaterKing(int ID[], int num, int wkresult[3])
{
	int i;
	int ID_Impossible = -1;//定义一个不可能存在的ID
	int wknum[3];//水王出现的次数
	wknum[0] = wknum[1] = wknum[2] = 0;
	wkresult[0] = wkresult[1] = wkresult[2] = ID_Impossible;//水王的ID，初始化
	for (i = 0; i<num; i++)
	{
		if (ID[i] == wkresult[0])//水王1出现次数统计
		{
			wknum[0]++;
		}
		else if (ID[i] == wkresult[1])//水王2出现次数统计
		{
			wknum[1]++;
		}
		else if (ID[i] == wkresult[2])//水王3出现次数统计
		{
			wknum[2]++;
		}
		else if (wknum[0] == 0)//将前三个不同的数先存为水王
		{
			wknum[0] = 1;
			wkresult[0] = ID[i];
		}
		else if (wknum[1] == 0)//将前三个不同的数先存为水王
		{
			wknum[1] = 1;
			wkresult[1] = ID[i];
		}
		else if (wknum[2] == 0)//将前三个不同的数先存为水王
		{
			wknum[2] = 1;
			wkresult[2] = ID[i];
		}
		else//此时找到四个不同的数，删除，并且出现次数减1，但是次数不一定为0
		{
			wknum[0]--;
			wknum[1]--;
			wknum[2]--;
		}
	}
}

int main()
{
	int wkresult[3];//找出其中3个符合条件的ID（每个ID的总数分别占ID总数的1 / 4以上）
	int num, arr[1000];
	int i,j;

	cout << "请输入帖子的数量：";
	cin >> num;

	if (arr == NULL || num == 0)//数组为空
	{
		//exit(1);
		return 0;
	}

	cout << "请输入帖子ID：" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	FindWaterKing(arr, num, wkresult);
	cout << "3个水王的ID分别是：";
	for (j = 0; j < 3; j++)
		cout << wkresult[j] << " ";
	cout << endl;

	return 0;
}