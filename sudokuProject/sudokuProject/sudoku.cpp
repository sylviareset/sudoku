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
void sudokutest::first()//初始化空白九宫格
{
	int i, j;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			sudoku[i][j] = 0;
		}
	}
	sudoku[0][0] = (2 + 5) % 9 + 1;//学号后两位为25
}
bool sudokutest::rightplace(int g, int h)//检测九宫格里的每个数字是否符合数独要求
{
	int row, col;
	row = g / 9;
	col = g % 9;
	int i, j;

	for (i = 0; i < 9; i++)	//对该数字所在的行查找是否有相同的数字
	{
		if (sudoku[row][i] == h)
			return false;
	}
	for (i = 0; i < 9; i++)	//对该数字所在的行查找是否有相同的数字
	{
		if (sudoku[i][col] == h)
			return false;
	}

	int a, b;
	a = row / 3;
	b = col / 3;

	for (i = a * 3; i < a * 3 + 3; i++)	//在每一个宫里判断是否有相同的数字出现
	{
		for (j = b * 3; j < b * 3 + 3; j++)
		{
			if (sudoku[i][j] == h)
				return false;
		}
	}

	return true;

}

void sudokutest::print()//输出函数
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
	if (n == 81)//达到81，说明九宫格已经被填满
	{
		pd = true;
		return;
	}
	if (sudoku[row][col] != 0)//找到没有被填的格子
	{
		put(n + 1);
	}
	else
	{
		if (n % 9 == 0)//每一行将数组随机调换
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
			for (int m = 0; m < l; m++)//判断输入的字符串是不是纯数字
			{
				if (na[m] <= 57 && na[m] >= 48)//数字0-9的ascii码为48-57，若发现数字，p就加一
				{
					p++;
				}
			}
			if (p != l)//如果最后的p与字符串长度不相同，就说明输入的字符串不是纯数字
			{
				cout << "please enter an integer" << endl;
				return 0;
			}
			stream << na;//将字符串转换成数字
			stream >> n;
			stream.clear();
			freopen("./sudoku.txt", "w", stdout);
			while (n--)
			{
				sudokutest s;
				s.first();
				pd = false;
				s.put(1);//左上角第一个数已被确认，所以从下一个位置开始
				s.print();
			}
		}
		else
		{
			cout << "Your input format is wrong!!!" << endl;
		}
	}


	
	
	
	

}
