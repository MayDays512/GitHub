//李俏、张莹荧，2016.3.26
//求整数数组的最大子数组的和，数组可循环 

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
	//cout<<"起始位置："<<start<<",终止位置："<<end;
    return maxsum;
}

int main()
{
	int i;
    int arrlength;
	int arr[1000];
	LL sum = 0,sum1,sum2;

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
		sum += arr[i];
	}

    sum1 = maxsum(arr, arrlength);

    for(int i=0; i<arrlength; i++)//每个数求反
	{
		arr[i] = -arr[i];
	}   
    sum2 = maxsum(arr, arrlength);//求出原数组中和小于0的元素的和

    sum = max(sum + sum2, sum1);//sum+sum2数组两头的元素的和
    
	cout<<"最大子数组的和为："<<sum<<endl;

    return 0;
}
