//#include<iostream>
//using namespace std;
//#define MAXNUM 100
//int tube[MAXNUM];//��ʼ��Ϊ0
////��⺯����l��ʼ��������tmp����
//bool test(int l, int tmp)
//{
//	int sum = 0;
//	for (int i = l; i < l + tmp; i++)
//	{
//		sum = sum | tube[i];
//	}
//	return sum;
//}
////lΪ���������������ţ�tΪ��������������pΪ���ȷ�
//void find(int l, int t, int p)
//{
//	//�ݹ����������������������,�����ȷ�������������
//	if (test(l, t) == 0)//
//		return;
//	else if (t == 1)//ֻʣ��������,�����ȷ���������ս������
//	{
//		cout << l << "�ź����������" << endl;
//		return;
//	}
//
//	//��ǰ�鲻�������������򽫵�ǰ��������
//	int tmp = t / p;//��ǰ�����ÿ��ĸ���
//	for (int i = 0; i < p; i++)
//	{
//		if (test(l + i * tmp, tmp) != 0)//��ǰ��������ԣ�������ֽ�
//		{
//			find(l + i * tmp, tmp, p);
//		}
//	}
//	return;
//}
//int main()
//{
//	int n=27;//һ�����м�������
//	cout << "������м�������n=27"<<endl;
//	int x;//����������Եĸ�����
//	x = rand() % n + 1;//����������Ը�����
//	tube[x] = 1;
//	//Ϊ�˷�����֤�����ǽ�������ɵ����Ը�����������Ա���֮�����Ƚ�
//	cout << "����õ������Ա��Ϊ��" << x << endl;
//	find(1, n, 3);
//	//�����μ������0��������һ�ֵļ��㡣
//	system("pause");
//	return 0;
//}