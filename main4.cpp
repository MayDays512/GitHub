//���Ρ���Өӫ��2016.3.21
//��������������������ĺ�

#include<iostream>
using namespace std;

int main()
{
	int arrlength,i;
	int j;
	int maxsum=0,sum=0;
	int arr[100];

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
	}
 
	maxsum=0;
	sum=0;
    for(i=0;i<arrlength;i++)
	{
		sum=sum+arr[i];//�ۼ�

		if(sum<0)      //��ǰ��С��0������Ϊ0
		{
			sum=0;
		}

		if(sum>maxsum) // ��ǰ�ʹ������ͣ����������� 
		{
			maxsum=sum;
		}
	}

	if(maxsum==0)      //maxsum=0,˵�������е���ֵ��Ϊ����
	{
		maxsum=arr[0];
		for(i=1;i<arrlength;i++)
		{
			if(arr[i]>maxsum)//���������������ֵ
			{
				maxsum=arr[i];
			}
		}
	}
	cout<<"���������ĺ�Ϊ��"<<maxsum<<endl;

	return 0;

	//for(i=0;i<arrlength;i++)
	//{
	//	sum=0;
	//	for(j=0;j<arrlength;j++)
	//	{
	//		sum += arr[j];

	//		if(sum<0)      //��ǰ��С��0������Ϊ0
	//	    {
	//			sum=0;
	//	    }

	//		if(sum>maxsum)
	//		{
	//			maxsum=sum;
	//		}
	//	}
	//}
	//cout<<"���������ĺ�Ϊ��"<<maxsum<<endl;
	//return 0;
}