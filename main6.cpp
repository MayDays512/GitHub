//李俏、张莹荧，2016.4.2
//求整数数组的最大子数组的和

#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
#define N 100

typedef struct
{
    int dian[N];
    int xian[N][N];
    int diannum;//数组中元素个数
}Tu;//图

void set(Tu &shuzu,int x,int y)
{  
	int i,j;
	fstream infile("input.txt",ios::in); //打开指定文件     
	if(!infile)     
	{       
		cout<<"open error!"<<endl;        
		exit(1);      
	} 
	infile>>x>>y;    //从文件中读取数组行数和列数
	shuzu.diannum=x*y;
	for(i=1;i<=shuzu.diannum;i++)//从文件中读取数组元素
	{
		infile>>shuzu.dian[i];
	}
	infile.close();

    for(i=1;i<=shuzu.diannum;i+=y)
    {
        for(j=i;j<=i+y-2;j++)
        {
            shuzu.xian[j][j+1]=1;
            shuzu.xian[j+1][j]=1;
        }
    }
    for(i=1+y;i<shuzu.diannum;i+=y)
    {
        for(j=i;j<=i+x-1;j++)
        {
            shuzu.xian[j][j-y]=1;
            shuzu.xian[j-y][j]=1;
        }
    }//将一维数组转换成二维图的形式
}

void output(Tu shuzu)//以图的形式输出数组
{
    for(int i=1;i<=shuzu.diannum;i++)
    {
        cout<<shuzu.dian[i];
        if(shuzu.xian[i][i+1]==1)
            cout<<"    ";
        else 
            cout<<endl;
    }
}

void bianli(Tu &shuzu,int v,int visit[],int &b,int &max,int x)//遍历图
{
    visit[v]=1;

    max+=shuzu.dian[v];
    if(max>=b)
        b=max;

    int a=0,bo=0;
    for(int w=1;w<=shuzu.diannum;w++)
    {
        for(int c=1;c<=shuzu.diannum;c++)
        {
            if((visit[w]==0)&&(shuzu.xian[c][w]==1)&&(visit[c]==1))
            {
                a=w;
				bo=1;
				break;
            }
        }
        if(bo==1)
		{
            break;
		}
    }
    for(int w=1;w<=shuzu.diannum;w++)
    {
        for(int c=1;c<=shuzu.diannum;c++)
        {
            if((visit[w]==0)&&(shuzu.xian[c][w]==1)&&(visit[c]==1))
            {
                if(shuzu.dian[a]<shuzu.dian[w])
				{
                    a=w;
				}
            }
        }
    }
    if(b+shuzu.dian[a]<0)
    {
        shuzu.xian[v][a]=0;
    }
    else
	{
        bianli(shuzu,a,visit,b,max,x);
	}
}

int NoVisit(int visit[],Tu shuzu)
{
    int k=0,i;
    for(i=1;i<=shuzu.diannum;i++)
    {
        if(visit[i]==0)
        {    
            k=i;
            break;
        }
    }
    return k;
}//判断图中没有visit的项

int main()
{ 
	Tu shuzu;
	int x,y;
	int i;

	fstream infile("input.txt",ios::in); //打开指定文件     
	if(!infile)     
	{       
		cout<<"open error!"<<endl;        
		exit(1);      
	} 
	infile>>x>>y;    //从文件中读取数组行数和列数
	for(i=1;i<=x*y;i++)
	{
		infile>>shuzu.dian[i];
	}
	infile.close();
    set(shuzu,x,y);
	cout<<"数组为："<<endl;
    output(shuzu);

    int v=1,b[N]={0},h=0;

    for(i=1;i<=shuzu.diannum;i++)
    {
        if(shuzu.dian[i]<0)
        {
            b[i]=shuzu.dian[i];
        }
        else
        {
            int visit[N]={0};
            int max=0;
            bianli(shuzu,i,visit,b[i],max,x);
        }
    }

    int max=b[1];
    for(int i=2;i<=shuzu.diannum;i++)
    {
        if(b[i]>max)
            max=b[i];
    }
    cout<<"最大联通子数组的和为："<<max<<endl;
	
	return 0;
}