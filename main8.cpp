//����,��ˮ�����������
//2016.5.25

#include<iostream> 
using namespace std;

void FindWaterKing(int ID[], int num, int wkresult[3])
{
	int i;
	int ID_Impossible = -1;//����һ�������ܴ��ڵ�ID
	int wknum[3];//ˮ�����ֵĴ���
	wknum[0] = wknum[1] = wknum[2] = 0;
	wkresult[0] = wkresult[1] = wkresult[2] = ID_Impossible;//ˮ����ID����ʼ��
	for (i = 0; i<num; i++)
	{
		if (ID[i] == wkresult[0])//ˮ��1���ִ���ͳ��
		{
			wknum[0]++;
		}
		else if (ID[i] == wkresult[1])//ˮ��2���ִ���ͳ��
		{
			wknum[1]++;
		}
		else if (ID[i] == wkresult[2])//ˮ��3���ִ���ͳ��
		{
			wknum[2]++;
		}
		else if (wknum[0] == 0)//��ǰ������ͬ�����ȴ�Ϊˮ��
		{
			wknum[0] = 1;
			wkresult[0] = ID[i];
		}
		else if (wknum[1] == 0)//��ǰ������ͬ�����ȴ�Ϊˮ��
		{
			wknum[1] = 1;
			wkresult[1] = ID[i];
		}
		else if (wknum[2] == 0)//��ǰ������ͬ�����ȴ�Ϊˮ��
		{
			wknum[2] = 1;
			wkresult[2] = ID[i];
		}
		else//��ʱ�ҵ��ĸ���ͬ������ɾ�������ҳ��ִ�����1�����Ǵ�����һ��Ϊ0
		{
			wknum[0]--;
			wknum[1]--;
			wknum[2]--;
		}
	}
}

int main()
{
	int wkresult[3];//�ҳ�����3������������ID��ÿ��ID�������ֱ�ռID������1 / 4���ϣ�
	int num, arr[1000];
	int i,j;

	cout << "���������ӵ�������";
	cin >> num;

	if (arr == NULL || num == 0)//����Ϊ��
	{
		//exit(1);
		return 0;
	}

	cout << "����������ID��" << endl;
	for (i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	FindWaterKing(arr, num, wkresult);
	cout << "3��ˮ����ID�ֱ��ǣ�";
	for (j = 0; j < 3; j++)
		cout << wkresult[j] << " ";
	cout << endl;

	return 0;
}