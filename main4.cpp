//李俏、张莹荧，2016.3.21
//求整数数组的最大子数组的和

#include<iostream>
using namespace std;

int main()
{
	int arrlength,i;
	int j;
	int maxsum=0,sum=0;
	int arr[100];

	cout<<"请输入数组长度：";
	cin>>arrlength;
	if(arr==NULL||arrlength==0)
	{
		//exit(1);
		return 0;
	}

	cout<<"请输入数组元素：";
	for(i=0;i<arrlength;i++)
	{
		cin>>arr[i];
	}
 
	maxsum=0;
	sum=0;
    for(i=0;i<arrlength;i++)
	{
		sum=sum+arr[i];//累加

		if(sum<0)      //当前和小于0，重置为0
		{
			sum=0;
		}

		if(sum>maxsum) // 当前和大于最大和，则重置最大和 
		{
			maxsum=sum;
		}
	}

	if(maxsum==0)      //maxsum=0,说明数组中的数值均为负数
	{
		maxsum=arr[0];
		for(i=1;i<arrlength;i++)
		{
			if(arr[i]>maxsum)//求出负数数组的最大值
			{
				maxsum=arr[i];
			}
		}
	}
	cout<<"最大子数组的和为："<<maxsum<<endl;

	return 0;

	//for(i=0;i<arrlength;i++)
	//{
	//	sum=0;
	//	for(j=0;j<arrlength;j++)
	//	{
	//		sum += arr[j];

	//		if(sum<0)      //当前和小于0，重置为0
	//	    {
	//			sum=0;
	//	    }

	//		if(sum>maxsum)
	//		{
	//			maxsum=sum;
	//		}
	//	}
	//}
	//cout<<"最大子数组的和为："<<maxsum<<endl;
	//return 0;
}