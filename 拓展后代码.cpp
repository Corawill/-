#include<iostream>
using namespace std;
#define MAXNUM 100
int tube[MAXNUM];//初始化为0
//检测函数从l开始，连续测几个人
bool test(int l, int tmp)
{
	int sum = 0;
	for (int i = l; i < l + tmp; i++)
	{
		sum = sum | tube[i];
	}
	return sum;
}
//l为本组最左侧样本编号，t为本组样本数量，p为几等分
void find(int l, int t,int p)
{
	//递归结束条件：本组结果呈阴性,或可以确定阳性样本编号
	if (test(l, t) == 0)//
		return;
	else if(t == 1)//只剩单个个体,则可以确定问题最终解个体编号
	{
		cout << l << "号核酸检测呈阳性" << endl;
		return;
	}
	//当前组不满足解决条件，则将当前组继续拆分
	int tmp = t / p;//当前分组后每组的个数
	//如果t不能被3等分,则剩余部分可能有1或2个，则按个体检测的方式来进行检测。
	int rem = t % p;
	if (tmp <= 0)
	{
		p = t;
		tmp = 1;
	}
	int i = 0;
	for (i = 0; i < p; i++)
	{
		if (test(l + i * tmp, tmp) != 0)//当前组检测呈阳性，则继续分解
		{
			find(l + i * tmp, tmp, p);
		}
	}
	i = p * tmp;
	for (; i < p * tmp + rem; i++)
	{
		if (test(l + i, 1) != 0)//当前组检测呈阳性，则继续分解
		{
			find(l + i, 1, p);
		}
	}
	return;
}
int main()
{
	int n;//一共进行检测的人数
	while (1) 
	{
		cout << "输入进行检测的人数n=";
		cin >> n;//输入进行检测的人数
		if (n <= 0)
		{
			cout << "检测人数要求n>0，请重新输出入" << endl;
			continue;
		}
		int x;//检测结果呈阳性的个体编号
		x = rand() % n + 1;//随机生成阳性个体编号
		tube[x] = 1;
		//为了方便验证，我们将随机生成的阳性个体编号输出，以便与之后作比较
		cout << "随机得到的阳性编号为：" << x << endl;
		find(1, n, 3);
		//将本次检测结果清0，方便下一轮的计算。
		tube[x] = 0;
		cout << endl;
	}
	system("pause");
	return 0;
}