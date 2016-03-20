//���Σ���Өӫ��2016.3.15
//���������������3

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class Fenshu
{
private:
	int fenzi;  // ����  
	int fenmu;  // ��ĸ 
public:
	Fenshu(int fz = 0, int fm = 1) :fenzi(fz), fenmu(fm){}
	void set(int, int);
	void simplify();
	friend bool judge1(const Fenshu &c1, const Fenshu &c2);     //�ж����������Ƿ����
	friend bool judge2(const Fenshu &c1, int z);     //�ж����������Ƿ����
	friend Fenshu add(const Fenshu &c1, const Fenshu &c2);  //����������ӣ����Ҫ����  
	friend Fenshu sub(const Fenshu &c1, const Fenshu &c2);  //����������������Ҫ����  
	friend Fenshu mul(const Fenshu &c1, const Fenshu &c2);  //����������ˣ����Ҫ����  
	friend Fenshu div(const Fenshu &c1, const Fenshu &c2);  //����������������Ҫ���� 
};

void Fenshu::set(int m, int n)// ������ֵ
{
	fenzi = m;
	fenmu = n;
}

void Fenshu::simplify()// ��������
{
	int m, n, r;
	m = abs(fenmu);
	n = abs(fenzi);
	while (r = m%n)  // ��m��n�����Լ��  
	{
		m = n;
		n = r;
	}
	fenmu /= n;     // ����  
	fenzi /= n;
	if (fenmu<0)  // ����ĸת��Ϊ����  
	{
		fenmu = -fenmu;
		fenzi = -fenzi;
	}
}

Fenshu add(const Fenshu &c1, const Fenshu &c2)// �������  
{
	Fenshu t;
	t.fenzi = c1.fenzi*c2.fenmu + c2.fenzi*c1.fenmu;
	t.fenmu = c1.fenmu*c2.fenmu;
	t.simplify();
	return t;
}

Fenshu sub(const Fenshu &c1, const Fenshu &c2)// ������� 
{
	Fenshu t;
	t.fenzi = c1.fenzi*c2.fenmu - c2.fenzi*c1.fenmu;
	t.fenmu = c1.fenmu*c2.fenmu;
	t.simplify();
	return t;
}

Fenshu mul(const Fenshu &c1, const Fenshu &c2)// �������
{
	Fenshu t;
	t.fenzi = c1.fenzi*c2.fenzi;
	t.fenmu = c1.fenmu*c2.fenmu;
	t.simplify();
	return t;
}

Fenshu div(const Fenshu &c1, const Fenshu &c2)// ������� 
{
	Fenshu t;
	if (!c2.fenzi) return c1;
	t.fenzi = c1.fenzi*c2.fenmu;
	t.fenmu = c1.fenmu*c2.fenzi;
	t.simplify();
	return t;
}

bool judge1(const Fenshu &c1, const Fenshu &c2)//�ж�����
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

bool judge2(const Fenshu &c1, int z)//�ж�����
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

	cout << "��������Ŀ������";
	cin >> num;
	if (num < 0)	//��Ŀ������Ϊ����
	{
		cout << "������������Ч����Ŀ����";
		cin >> num;
	};
	if (num == 0)
	{
		exit(1);
	}

	cout << "�Ƿ��г˳�����1.�ǣ�2.��";
	cin >> chengchu;
	if ((chengchu != 1)||(chengchu != 2)) //ֻ��ѡ��1��2
	{
		cout << "������������Ч����ֵ��";
		cin >> chengchu;
	};
	if (chengchu == 1)
	{
		cout << "�����Ƿ���������1.�ǣ�2.��";
		cin >> yushu;
		if ((yushu != 1)||(yushu != 2)) //ֻ��ѡ��1��2
		{
			cout << "������������Ч����ֵ��";
			cin >> yushu;
		};
	}

	cout << "�����Ƿ��и�����1.�ǣ�2.��";
	cin >> fushu;
	if ((fushu != 1)||(fushu != 2)) //ֻ��ѡ��1��2
	{
		cout << "������������Ч����ֵ��";
		cin >> fushu;
	};
	cout << "��������ֵ��Χ��";
	cin >> fanwei;
	if (fanwei <= 0)	//����������Ϊ����
	{
		cout << "������������Ч�ķ�Χ��";
		cin >> fanwei;
	};

	srand((int)time(NULL)); //��ʱ�������ӣ�ÿ�β������������һ��

	for (i = 0; i<num; i++)
	{
		j = rand() % 2;        //ѡ�������������㻹�Ƿ�������

		if (j == 0)           //ѡ������
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
			case 0:                      //�����ӷ�
				cout << first << "+" << second << "=" << endl;
				cout << "����������";
				cin >> ans;
				if (ans == first + second)
				{
					cout << "����ˣ�" << endl;
					right = right + 1;
				}
				else
				{
					cout << "����ˣ�" << endl;
					wrong = wrong + 1;
				}
				break;
			case 1:                      //��������
				if (fushu == 1)
				{
					cout << first << "-" << second << "=" << endl;
					cout << "����������";
					cin >> ans;
					if (ans == first - second)
					{
						cout << "����ˣ�" << endl;
						right = right + 1;
					}
					else
					{
						cout << "����ˣ�" << endl;
						wrong = wrong + 1;
					}
				}
				else
				{
					if (first>second)
					{
						cout << first << "-" << second << "=" << endl;
						cout << "����������";
						cin >> ans;
						if (ans == first - second)
						{
							cout << "����ˣ�" << endl;
							right = right + 1;
						}
						else
						{
							cout << "����ˣ�" << endl;
							wrong = wrong + 1;
						}
					}
					else
					{
						cout << second << "-" << first << "=" << endl;
						cout << "����������";
						cin >> ans;
						if (ans == second - first)
						{
							cout << "����ˣ�" << endl;
							right = right + 1;
						}
						else
						{
							cout << "����ˣ�" << endl;
							wrong = wrong + 1;
						}
					}
				}
				break;
			case 2:                   //�����˷�
				cout << first << "*" << second << "=" << endl;
				cout << "����������";
				cin >> ans;
				if (ans == first * second)
				{
					cout << "����ˣ�" << endl;
					right = right + 1;
				}
				else
				{
					cout << "����ˣ�" << endl;
					wrong = wrong + 1;
				}
				break;
			case 3:                   //��������
				if (yushu == 1)
				{
					if (second != 0)
					{
						cout << first << "/" << second << "=" << endl;
						cout << "��������(�̺�����)��";
						cin >> ans >> ansy;
						if ((ans == (first / second)) && (ansy == (first%second)))
						{
							cout << "����ˣ�" << endl;
							right = right + 1;
						}
						else
						{
							cout << "����ˣ�" << endl;
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
						cout << "����������";
						cin >> ans;
						if (ans == first / second)
						{
							cout << "����ˣ�" << endl;
							right = right + 1;
						}
						else
						{
							cout << "����ˣ�" << endl;
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

		else              //ѡ�����
		{
			first = rand() % (fanwei + 1);
			second = rand() % (fanwei + 1);//����
			firstm = rand() % (fanwei + 1);
			secondm = rand() % (fanwei + 1);//��ĸ
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
			case 0:                //�����ӷ�
				if ((firstm != 0) && (secondm != 0) && (first<firstm) && (second<secondm))
				{
					cout << first << "/" << firstm << "  +  " << second << "/" << secondm << "=" << endl;
					cout << "�������������Ӻͷ�ĸ����";
					cin >> ans >> ansm;
					x.set(ans, ansm);
					x1.set(first, firstm);
					x2.set(second, secondm);
					y = add(x1, x2);
					if (true == judge1(x, y))
					{
						cout << "����ˣ�" << endl;
						right = right + 1;
					}
					else
					{
						cout << "����ˣ�" << endl;
						wrong = wrong + 1;
					}
				}
				else
				{
					i = i - 1;
				}
				break;
			case 1:                //��������
				if (fushu == 1)
				{
					if ((firstm != 0) && (secondm != 0) && (first<firstm) && (second<secondm))
					{
						cout << first << "/" << firstm << "  -  " << second << "/" << secondm << "=" << endl;
						cout << "�������������Ӻͷ�ĸ����";
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
								cout << "����ˣ�" << endl;
								right = right + 1;
							}
							else
							{
								cout << "����ˣ�" << endl;
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
								cout << "����ˣ�" << endl;
								right = right + 1;
							}
							else
							{
								cout << "����ˣ�" << endl;
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
						cout << "�������������Ӻͷ�ĸ����";
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
								cout << "����ˣ�" << endl;
								right = right + 1;
							}
							else
							{
								cout << "����ˣ�" << endl;
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
								cout << "����ˣ�" << endl;
								right = right + 1;
							}
							else
							{
								cout << "����ˣ�" << endl;
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
			case 2:                //�����˷�
				if ((firstm != 0) && (secondm != 0) && (first<firstm) && (second<secondm))
				{
					cout << first << "/" << firstm << "  *  " << second << "/" << secondm << "=" << endl;
					cout << "�������������Ӻͷ�ĸ����";
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
							cout << "����ˣ�" << endl;
							right = right + 1;
						}
						else
						{
							cout << "����ˣ�" << endl;
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
							cout << "����ˣ�" << endl;
							right = right + 1;
						}
						else
						{
							cout << "����ˣ�" << endl;
							wrong = wrong + 1;
						}
					}
				}
				else
				{
					i = i - 1;
				}
				break;
			case 3:                //��������
				if ((firstm != 0) && (secondm != 0) && (first != 0) && (second != 0) && (first<firstm) && (second<secondm))
				{
					cout << first << "/" << firstm << "  /  " << second << "/" << secondm << "=" << endl;
					cout << "�������������Ӻͷ�ĸ����";
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
							cout << "����ˣ�" << endl;
							right = right + 1;
						}
						else
						{
							cout << "����ˣ�" << endl;
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
							cout << "����ˣ�" << endl;
							right = right + 1;
						}
						else
						{
							cout << "����ˣ�" << endl;
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
	cout << "�ܹ����" << num << "���⣬����" << right << "��������" << wrong << "���⣡" << endl;

	return 0;
}