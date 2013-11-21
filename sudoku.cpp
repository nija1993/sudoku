#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class board{
public:
	int numbers[9][9];
	void row_rotate(int,int);
	void column_rotate(int,int);
	void permute_grid_swap(int,int,int,int,int);
	void swap(int,int,int,int);
	void print();
};

int get_grid(int,int);

int main()
{
	board sudoku;
	int no_of_numbers[9];
	int i,j;
	for(i = 0;i < 9;i++)
		no_of_numbers[i] = 0;
	cout << "Enter the elements of the board row-wise";
	for(i = 0;i < 9;i++)
	{
		cout << "Row number : " << i+1 << " :: ";
		for(j = 0;j < 9;j++)
		{
			cin >> sudoku.numbers[i][j];
			no_of_numbers[sudoku.numbers[i][j]]++;
		}
	}
	for(i = 0;i < 9;i++)
	{
		if(no_of_numbers[i] != 9)
		{
			cout << "Sudoku cannot be generated";
			exit(0);
		}
	}
	sudoku.print();
	sudoku.column_rotate(1,3);
	sudoku.print();

	return 0;
}

void board :: swap(int row1,int col1,int row2,int col2)
{
	if(row1 % 3 == 1)
	{
		column_rotate(col2,row1-row2+1);
		row_rotate(row1+1,col2-col1);
		permute_grid_swap(get_grid(row1,col1),1,col1%3,2,col1%3);
		row_rotate(row1+1,col1-col2);
		column_rotate(col2,-(row1-row2+1));
	}
	else
	{
		column_rotate(col2,row1-row2-1);
		row_rotate(row1-1,col2-col1);
		permute_grid_swap(get_grid(row1,col1),row1%3,col1%3,(row1-1)%3,col1%3);
		row_rotate(row1-1,col1-col2);
		column_rotate(col2,-(row1-row2-1));
	}
}

void board :: row_rotate(int row,int number)
{
	int copy[9];
	int i,j;
	if(number > 0)			//rotate right
	{
		for(i = 0;i < number;i++)
			copy[i] = numbers[row][8-i];
		for(;i < 9;i++)
			numbers[row][8-i+number] = numbers[row][8-i];
		for(j = 0;j < number;i++,j++)
			numbers[row][8-i+number] = copy[j];
	}
	else if(number < 0)		//rotate left
	{
		for(i = 0;i < -(number);i++)
			copy[i] = numbers[row][i];
		for(;i < 9;i++)
			numbers[row][i+number] = numbers[row][i];
		for(j = 0;j < -(number);i++,j++)
			numbers[row][i+number] = copy[j];
	}
}

void board :: column_rotate(int col,int number)
{
	int copy[9];
	int i,j;
	if(number > 0)			//rotate down
	{
		for(i = 0;i < number;i++)
			copy[i] = numbers[8-i][col];
		for(;i < 9;i++)
			numbers[8-i+number][col] = numbers[8-i][col];
		for(j = 0;j < number;i++,j++)
			numbers[8-i+number][col] = copy[j];
	}
	else if(number < 0)		//rotate up
	{
		for(i = 0;i < -(number);i++)
			copy[i] = numbers[i][col];
		for(;i < 9;i++)
			numbers[i+number][col] = numbers[i][col];
		for(j = 0;j < -(number);i++,j++)
			numbers[i+number][col] = copy[j];
	}
}

void board :: permute_grid_swap(int grid,int row1,int col1,int row2,int col2)
{

}

void board :: print()
{
	int i,j;
	for(i = 0;i < 9;i++)
	{
		for(j = 0;j < 9;j++)
			cout << numbers[i][j] << " ";
		cout << endl;
	}
}

int get_grid(int row,int col)
{
	if((row-1)/3 == 0)
	{
		switch((col-1)/3)
		{
		case 0:
			return 1;
		case 1:
			return 2;
		case 2:
			return 3;
		}
	}
	else if((row-1)/3 == 1)
	{
		switch((col-1)/3)
		{
		case 0:
			return 4;
		case 1:
			return 5;
		case 2:
			return 6;
		}
	}
	else
	{
		switch((col-1)/3)
		{
		case 0:
			return 7;
		case 1:
			return 8;
		case 2:
			return 9;
		}
	}
}
