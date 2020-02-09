#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

int addUp(int ogNumber)
{
	int i, addNum = 0;
	const char* temp;
	string strNum;
	// Converts the int to a string so I can check each index
	strNum = to_string(ogNumber);
	// Take each character and make it an int to add up.
	for(i = 0; i < strNum.length(); i++)
	{
		string sym(1, strNum[i]);
		temp = sym.c_str();
		addNum += atoi(temp);
	}
	return addNum;
}

void magicNumber(int ogNumber)
{
	int addNum = 0;
	bool check = false;

	do{
		// Runs the function to get the sum of digits
		addNum = addUp(ogNumber);
		// If the number meets the criteria, it is the magic number
		if(ogNumber%addNum == 0)
		{
			cout << ogNumber << " is the magic number.\n";
			check = true;
		}
		// If not, we go through again with the number being one larger.
		else
		{	
			ogNumber++;
			check = false;
		}
	}while(!check);

}

int main()
{
	int ogNumber = 0;
	bool check;
	do{
		cout << "Enter a number (0 < x < 1000000):";
		cin >> ogNumber;
		if((ogNumber >= 1000000) || (ogNumber < 0))
		{
			cout << "Invalid Input: Make sure to use a positive number less than 1000000.\n";
			check = false;
		}			
		else
		{
			check = true;
		}
	}while(!check);

	magicNumber(ogNumber);

	return 0;
}
