#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include <sstream>
#include"sudokuh.h"
using namespace std;
int sudoku[10][10];
int a[9] = { 1,2,3,4,5,6,7,8,9 };
bool pd;
void sudokutest::first()//��ʼ���հ׾Ź���
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sudoku[i][j] = 0;
		}
	}
	sudoku[0][0] = (2 + 5) % 9 + 1;//ѧ�ź���λΪ25
}
bool sudokutest::rightplace(int g, int h)//���Ź������ÿ�������Ƿ��������Ҫ��
{
	int row, col;
	row = g / 9;
	col = g % 9;
	int i, j;

	for (i = 0; i < 9; i++)	//�Ը��������ڵ��в����Ƿ�����ͬ������
	{
		if (sudoku[row][i] == h)
			return false;
	}
	for (i = 0; i < 9; i++)	//�Ը��������ڵ��в����Ƿ�����ͬ������
	{
		if (sudoku[i][col] == h)
			return false;
	}

	int a, b;
	a = row / 3;
	b = col / 3;

	for (i = a * 3; i < a * 3 + 3; i++)	//��ÿһ�������ж��Ƿ�����ͬ�����ֳ���
	{
		for (j = b * 3; j < b * 3 + 3; j++)
		{
			if (sudoku[i][j] == h)
				return false;
		}
	}

	return true;

}

void sudokutest::print()//�������
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%d ",sudoku[i][j]);
			//cout << sudoku[i][j] << " ";
		}
		printf("\n");
		//cout << endl;
	}
	printf("\n");
	//cout << endl;
}
void sudokutest::put(int n)
{
	int row, col;
	row = n / 9;
	col = n % 9;
	int i;
	if (n == 81)//�ﵽ81��˵���Ź����Ѿ�������
	{
		pd = true;
		return;
	}
	if (sudoku[row][col] != 0)//�ҵ�û�б���ĸ���
	{
		put(n + 1);
	}
	else
	{
		if (n % 9 == 0)//ÿһ�н������������
			random_shuffle(&(a[0]), &(a[9]));
		for (i = 0; i < 9; i++)
		{

			if (rightplace(n, a[i]))
			{
				sudoku[row][col] = a[i];
				put(n + 1);
				if (pd)
					return;
				sudoku[row][col] = 0;

			}
		}

	}

}
int main(int argc, char *argv[])
{
	int i, j, temp = 0;
	int k = 0, num = 0;
	int p = 0;
	stringstream stream;
	string na,ne;
	int n;
	if (argc!=3)
	{
		cout << "ERROR!!!more or less sentences" << endl;
		return 0;
}
	else
	{
		ne = argv[1];
		if (ne == "-c")
		{
			na = argv[2];
			int l = na.length();
			for (int m = 0; m < l; m++)//�ж�������ַ����ǲ��Ǵ�����
			{
				if (na[m] <= 57 && na[m] >= 48)//����0-9��ascii��Ϊ48-57�����������֣�p�ͼ�һ
				{
					p++;
				}
			}
			if (p != l)//�������p���ַ������Ȳ���ͬ����˵��������ַ������Ǵ�����
			{
				cout << "please enter an integer" << endl;
				return 0;
			}
			stream << na;//���ַ���ת��������
			stream >> n;
			stream.clear();
			freopen("./sudoku.txt", "w", stdout);
			while (n--)
			{
				sudokutest s;
				s.first();
				pd = false;
				s.put(1);//���Ͻǵ�һ�����ѱ�ȷ�ϣ����Դ���һ��λ�ÿ�ʼ
				s.print();
			}
		}
		else
		{
			cout << "Your input format is wrong!!!" << endl;
		}
	}


	
	
	
	

}
