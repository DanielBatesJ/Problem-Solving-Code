#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void findLargest(int stickNum)
{
	int i = 0;

	cout << "Largest Number:";

	// The pattern for largest is just ones and sevens based on odd and even number of sticks
	while(stickNum > 0)
	{
		if((stickNum%2 == 1) && (stickNum >= 3))
		{
			stickNum -= 3;
			cout << "7";
			i++;
		}
		else
		{
			stickNum -= 2;
			cout << "1";
			i++;
		}
	}
}

// The smallest case has a pattern of additions of 7 to numbers, where, past the first case or two, the remaining numbers are just eights
void findSmallest(int sticksNum)
{
	int i = 0;
	cout << "Smallest Number:";
	// Special Cases that don't fit any pattern.
	if(sticksNum == 3)
	{
		cout << "7";
		return;
	}
	if(sticksNum == 4)
	{
		cout << "4";
		return;
	}
	if(sticksNum == 10)
	{
		cout << "22";
		return;
	}
	// Repeating cases based off of mod 7.
	if(sticksNum % 7 == 2)
	{
		cout << "1";
		sticksNum = sticksNum-7;
		while(sticksNum >= 2)
		{
			cout << "8";
			sticksNum = sticksNum-7;
		};
		return;
	}
	// Three and 10 don't follow the pattern so this only effects 17+7x
	if(sticksNum % 7 == 3)
	{
		cout << "200";
		sticksNum -= 7;
		while(sticksNum >= 10)
		{
			cout << "8";
			sticksNum -= 7;
		}
		return;
	}
	if(sticksNum % 7 == 4)
	{
		cout << "20";
		sticksNum = sticksNum-7;
		while(sticksNum >= 11)
		{
			cout << "8";
			sticksNum = sticksNum-7;
		};
		return;
	}
	if(sticksNum % 7 == 5)
	{
		cout << "2";
		sticksNum = sticksNum-7;
		while(sticksNum >= 5)
		{
			cout << "8";
			sticksNum = sticksNum-7;
		};
	}
	if(sticksNum % 7 == 6)
	{
		cout << "6";
		sticksNum = sticksNum-7;
		while(sticksNum >= 6)
		{
			cout << "8";
			sticksNum = sticksNum-7;
		};
	}
	if(sticksNum % 7 == 0)
	{
		cout << "8";
		sticksNum = sticksNum-7;
		while(sticksNum >= 7)
		{
			cout << "8";
			sticksNum = sticksNum-7;
		};
	}
	if(sticksNum % 7 == 1)
	{
		cout << "10";
		sticksNum = sticksNum-7;
		while(sticksNum >= 8)
		{
			cout << "8";
			sticksNum = sticksNum-7;
		};
	}
}

int main()
{
	int stickNum = 0;
	bool check;
	do{
		cout << "This program generates the largest and smallest numbers that can be created given a user-inputed number of \"sticks\".\n" << endl;
		cout << "\"Sticks\" referes to the line segments that make up numbers on a digital clock.\nFor example...\nThe number \"1\" is made up of two sticks, and the number \"8\" is made up of seven sticks.\n";
		cout << "Enter a number of sticks (2 <= x <= 100):";
		cin >> stickNum;
		if((stickNum > 100) && (stickNum < 2))
		{
			cout << "Invalid Input: Make sure to use a number greater than or eqaul to 2, and less than or equal to 100.\n";
			check = false;
		}			
		else
		{
			check = true;
		}
	}while(!check);

	findLargest(stickNum);
	cout << endl;
	findSmallest(stickNum);
	cout << endl;

	return 0;
}
