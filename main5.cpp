//���Ρ���Өӫ��2016.3.26
//��������������������ĺͣ������ѭ�� 

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

typedef long long LL;

LL maxsum(int a[], int n)
{
	int i;
	int start=0,end=0;
    LL maxsum = 0;
    LL sum = 0;
    for(i=0; i<n; i++)
    {
        if(sum < 0) 
		{
			sum = a[i];
			//start= i + 1;
		}
        else 
		{
			sum += a[i]; 
		}

		if(sum>maxsum)
		{
			maxsum = sum;				
			//end = i;		
		}
        //maxsum = max(maxsum, sum);
    }
	//cout<<"��ʼλ�ã�"<<start<<",��ֹλ�ã�"<<end;
    return maxsum;
}

int main()
{
	int i;
    int arrlength;
	int arr[1000];
	LL sum = 0,sum1,sum2;

	cout<<"���������鳤�ȣ�";
	cin>>arrlength;
	if(arr==NULL||arrlength==0)
	{
		//exit(1);
		return 0;
	}

	cout<<"����������Ԫ�أ�";
	for(i=0;i<arrlength;i++)
	{
		cin>>arr[i];
		sum += arr[i];
	}

    sum1 = maxsum(arr, arrlength);

    for(int i=0; i<arrlength; i++)//ÿ������
	{
		arr[i] = -arr[i];
	}   
    sum2 = maxsum(arr, arrlength);//���ԭ�����к�С��0��Ԫ�صĺ�

    sum = max(sum + sum2, sum1);//sum+sum2������ͷ��Ԫ�صĺ�
    
	cout<<"���������ĺ�Ϊ��"<<sum<<endl;

    return 0;
}
