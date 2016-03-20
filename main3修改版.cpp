//李俏，张莹荧，2016.3.15
//随机生成四则运算3

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Fenshu
{
private:
	int fenzi;  // 分子  
	int fenmu;  // 分母 
public:
	Fenshu(int fz = 0, int fm = 1) :fenzi(fz), fenmu(fm){}
	void set(int, int);
	void simplify();
	friend bool judge1(const Fenshu &c1, const Fenshu &c2);     //判断两个分数是否相等
	friend bool judge2(const Fenshu &c1, int z);     //判断两个分数是否相等
	friend Fenshu add(const Fenshu &c1, const Fenshu &c2);  //两个分数相加，结果要化简  
	friend Fenshu sub(const Fenshu &c1, const Fenshu &c2);  //两个分数相减，结果要化简  
	friend Fenshu mul(const Fenshu &c1, const Fenshu &c2);  //两个分数相乘，结果要化简  
	friend Fenshu div(const Fenshu &c1, const Fenshu &c2);  //两个分数相除，结果要化简 
};

void Fenshu::set(int m, int n)// 分数赋值
{
	fenzi = m;
	fenmu = n;
}

void Fenshu::simplify()// 分数化简
{
	int m, n, r;
	m = abs(fenmu);
	n = abs(fenzi);
	while (r = m%n)  // 求m，n的最大公约数  
	{
		m = n;
		n = r;
	}
	fenmu /= n;     // 化简  
	fenzi /= n;
	if (fenmu<0)  // 将分母转化为正数  
	{
		fenmu = -fenmu;
		fenzi = -fenzi;
	}
}

Fenshu add(const Fenshu &c1, const Fenshu &c2)// 分数相加  
{
	Fenshu t;
	t.fenzi = c1.fenzi*c2.fenmu + c2.fenzi*c1.fenmu;
	t.fenmu = c1.fenmu*c2.fenmu;
	t.simplify();
	return t;
}

Fenshu sub(const Fenshu &c1, const Fenshu &c2)// 分数相减 
{
	Fenshu t;
	t.fenzi = c1.fenzi*c2.fenmu - c2.fenzi*c1.fenmu;
	t.fenmu = c1.fenmu*c2.fenmu;
	t.simplify();
	return t;
}

Fenshu mul(const Fenshu &c1, const Fenshu &c2)// 分数相乘
{
	Fenshu t;
	t.fenzi = c1.fenzi*c2.fenzi;
	t.fenmu = c1.fenmu*c2.fenmu;
	t.simplify();
	return t;
}

Fenshu div(const Fenshu &c1, const Fenshu &c2)// 分数相除 
{
	Fenshu t;
	if (!c2.fenzi) return c1;
	t.fenzi = c1.fenzi*c2.fenmu;
	t.fenmu = c1.fenmu*c2.fenzi;
	t.simplify();
	return t;
}

bool judge1(const Fenshu &c1, const Fenshu &c2)//判断正误
{
	bool flag;
	if ((c1.fenzi == c2.fenzi) && (c1.fenmu == c2.fenmu))
	{
		flag = true;
		return flag;
	}
	else
	{
		flag = false;
		return flag;
	}
}

bool judge2(const Fenshu &c1, int z)//判断正误
{
	bool flag;
	if (0 == c1.fenzi - z)
	{
		flag = true;
		return flag;
	}
	else
	{
		flag = false;
		return flag;
	}
}

int main()
{
	int first, second, firstm, secondm;
	int sign, i, j;
	int num, chengchu, fushu, yushu, fanwei;
	int ans, ansm, ansy;
	int right = 0, wrong = 0;
	Fenshu x1, x2, x, y;

	cout << "请输入题目数量：";
	cin >> num;
	if (num < 0)	//题目数必须为正数
	{
		cout << "请重新输入有效的题目数：";
		cin >> num;
	};
	if (num == 0)
	{
		exit(1);
	}

	cout << "是否有乘除法？1.是，2.否：";
	cin >> chengchu;
	if ((chengchu != 1)||(chengchu != 2)) //只能选择1或2
	{
		cout << "请重新输入有效的数值：";
		cin >> chengchu;
	};
	if (chengchu == 1)
	{
		cout << "除法是否有余数？1.是，2.否：";
		cin >> yushu;
		if ((yushu != 1)||(yushu != 2)) //只能选择1或2
		{
			cout << "请重新输入有效的数值：";
			cin >> yushu;
		};
	}

	cout << "减法是否有负数？1.是，2.否：";
	cin >> fushu;
	if ((fushu != 1)||(fushu != 2)) //只能选择1或2
	{
		cout << "请重新输入有效的数值：";
		cin >> fushu;
	};
	cout << "请输入数值范围：";
	cin >> fanwei;
	if (fanwei <= 0)	//运算数必须为正数
	{
		cout << "请重新输入有效的范围：";
		cin >> fanwei;
	};

	srand((int)time(NULL)); //用时间做种子，每次产生随机数都不一样

	for (i = 0; i<num; i++)
	{
		j = rand() % 2;        //选择生成整数运算还是分数运算

		if (j == 0)           //选择整数
		{
			first = rand() % (fanwei + 1);
			second = rand() % (fanwei + 1);
			if (chengchu == 1)
			{
				sign = rand() % 4;
			}
			else
			{
				sign = rand() % 2;
			}
			switch (sign)
			{
			case 0:                      //整数加法
				cout << first << "+" << second << "=" << endl;
				cout << "请输入结果：";
				cin >> ans;
				if (ans == first + second)
				{
					cout << "答对了！" << endl;
					right = right + 1;
				}
				else
				{
					cout << "答错了！" << endl;
					wrong = wrong + 1;
				}
				break;
			case 1:                      //整数减法
				if (fushu == 1)
				{
					cout << first << "-" << second << "=" << endl;
					cout << "请输入结果：";
					cin >> ans;
					if (ans == first - second)
					{
						cout << "答对了！" << endl;
						right = right + 1;
					}
					else
					{
						cout << "答错了！" << endl;
						wrong = wrong + 1;
					}
				}
				else
				{
					if (first>second)
					{
						cout << first << "-" << second << "=" << endl;
						cout << "请输入结果：";
						cin >> ans;
						if (ans == first - second)
						{
							cout << "答对了！" << endl;
							right = right + 1;
						}
						else
						{
							cout << "答错了！" << endl;
							wrong = wrong + 1;
						}
					}
					else
					{
						cout << second << "-" << first << "=" << endl;
						cout << "请输入结果：";
						cin >> ans;
						if (ans == second - first)
						{
							cout << "答对了！" << endl;
							right = right + 1;
						}
						else
						{
							cout << "答错了！" << endl;
							wrong = wrong + 1;
						}
					}
				}
				break;
			case 2:                   //整数乘法
				cout << first << "*" << second << "=" << endl;
				cout << "请输入结果：";
				cin >> ans;
				if (ans == first * second)
				{
					cout << "答对了！" << endl;
					right = right + 1;
				}
				else
				{
					cout << "答错了！" << endl;
					wrong = wrong + 1;
				}
				break;
			case 3:                   //整数除法
				if (yushu == 1)
				{
					if (second != 0)
					{
						cout << first << "/" << second << "=" << endl;
						cout << "请输入结果(商和余数)：";
						cin >> ans >> ansy;
						if ((ans == (first / second)) && (ansy == (first%second)))
						{
							cout << "答对了！" << endl;
							right = right + 1;
						}
						else
						{
							cout << "答错了！" << endl;
							wrong = wrong + 1;
						}
					}
					else
					{
						i = i - 1;
					}
				}
				else
				{
					if (second != 0 && (first%second == 0))
					{
						cout << first << "/" << second << "=" << endl;
						cout << "请输入结果：";
						cin >> ans;
						if (ans == first / second)
						{
							cout << "答对了！" << endl;
							right = right + 1;
						}
						else
						{
							cout << "答错了！" << endl;
							wrong = wrong + 1;
						}
					}
					else
					{
						i = i - 1;
					}
				}
				break;
			}
		}

		else              //选择分数
		{
			first = rand() % (fanwei + 1);
			second = rand() % (fanwei + 1);//分子
			firstm = rand() % (fanwei + 1);
			secondm = rand() % (fanwei + 1);//分母
			if (chengchu == 1)
			{
				sign = rand() % 4;
			}
			else
			{
				sign = rand() % 2;
			}

			switch (sign)
			{
			case 0:                //分数加法
				if ((firstm != 0) && (secondm != 0) && (first<firstm) && (second<secondm))
				{
					cout << first << "/" << firstm << "  +  " << second << "/" << secondm << "=" << endl;
					cout << "请输入结果（分子和分母）：";
					cin >> ans >> ansm;
					x.set(ans, ansm);
					x1.set(first, firstm);
					x2.set(second, secondm);
					y = add(x1, x2);
					if (true == judge1(x, y))
					{
						cout << "答对了！" << endl;
						right = right + 1;
					}
					else
					{
						cout << "答错了！" << endl;
						wrong = wrong + 1;
					}
				}
				else
				{
					i = i - 1;
				}
				break;
			case 1:                //分数减法
				if (fushu == 1)
				{
					if ((firstm != 0) && (secondm != 0) && (first<firstm) && (second<secondm))
					{
						cout << first << "/" << firstm << "  -  " << second << "/" << secondm << "=" << endl;
						cout << "请输入结果（分子和分母）：";
						cin >> ans;
						if (ans != 0)
						{
							cin >> ansm;
							x.set(ans, ansm);
							x1.set(first, firstm);
							x2.set(second, secondm);
							y = sub(x1, x2);
							if (true == judge1(x, y))
							{
								cout << "答对了！" << endl;
								right = right + 1;
							}
							else
							{
								cout << "答错了！" << endl;
								wrong = wrong + 1;
							}
						}
						else
						{
							x1.set(first, firstm);
							x2.set(second, secondm);
							y = sub(x1, x2);
							if (true == judge2(y, ans))
							{
								cout << "答对了！" << endl;
								right = right + 1;
							}
							else
							{
								cout << "答错了！" << endl;
								wrong = wrong + 1;
							}
						}
					}
					else
					{
						i = i - 1;
					}
				}
				else
				{
					if ((firstm != 0) && (secondm != 0) && (first<firstm) && (second<secondm) && ((first / firstm)>(second / secondm)))
					{
						cout << first << "/" << firstm << "  -  " << second << "/" << secondm << "=" << endl;
						cout << "请输入结果（分子和分母）：";
						cin >> ans;
						if (ans != 0)
						{
							cin >> ansm;
							x.set(ans, ansm);
							x1.set(first, firstm);
							x2.set(second, secondm);
							y = sub(x1, x2);
							if (true == judge1(x, y))
							{
								cout << "答对了！" << endl;
								right = right + 1;
							}
							else
							{
								cout << "答错了！" << endl;
								wrong = wrong + 1;
							}
						}
						else
						{
							x1.set(first, firstm);
							x2.set(second, secondm);
							y = sub(x1, x2);
							if (true == judge2(y, ans))
							{
								cout << "答对了！" << endl;
								right = right + 1;
							}
							else
							{
								cout << "答错了！" << endl;
								wrong = wrong + 1;
							}
						}
					}
					else
					{
						i = i - 1;
					}
				}
				break;
			case 2:                //分数乘法
				if ((firstm != 0) && (secondm != 0) && (first<firstm) && (second<secondm))
				{
					cout << first << "/" << firstm << "  *  " << second << "/" << secondm << "=" << endl;
					cout << "请输入结果（分子和分母）：";
					cin >> ans;
					if (ans != 0)
					{
						cin >> ansm;
						x.set(ans, ansm);
						x1.set(first, firstm);
						x2.set(second, secondm);
						y = sub(x1, x2);
						if (true == judge1(x, y))
						{
							cout << "答对了！" << endl;
							right = right + 1;
						}
						else
						{
							cout << "答错了！" << endl;
							wrong = wrong + 1;
						}
					}
					else
					{
						x1.set(first, firstm);
						x2.set(second, secondm);
						y = sub(x1, x2);
						if (true == judge2(y, ans))
						{
							cout << "答对了！" << endl;
							right = right + 1;
						}
						else
						{
							cout << "答错了！" << endl;
							wrong = wrong + 1;
						}
					}
				}
				else
				{
					i = i - 1;
				}
				break;
			case 3:                //分数除法
				if ((firstm != 0) && (secondm != 0) && (first != 0) && (second != 0) && (first<firstm) && (second<secondm))
				{
					cout << first << "/" << firstm << "  /  " << second << "/" << secondm << "=" << endl;
					cout << "请输入结果（分子和分母）：";
					cin >> ans;
					if (ans != 0)
					{
						cin >> ansm;
						x.set(ans, ansm);
						x1.set(first, firstm);
						x2.set(second, secondm);
						y = sub(x1, x2);
						if (true == judge1(x, y))
						{
							cout << "答对了！" << endl;
							right = right + 1;
						}
						else
						{
							cout << "答错了！" << endl;
							wrong = wrong + 1;
						}
					}
					else
					{
						x1.set(first, firstm);
						x2.set(second, secondm);
						y = sub(x1, x2);
						if (true == judge2(y, ans))
						{
							cout << "答对了！" << endl;
							right = right + 1;
						}
						else
						{
							cout << "答错了！" << endl;
							wrong = wrong + 1;
						}
					}
				}
				else
				{
					i = i - 1;
				}
				break;
			}
		}
	}
	cout << "总共完成" << num << "道题，做对" << right << "道，做错" << wrong << "道题！" << endl;

	return 0;
}