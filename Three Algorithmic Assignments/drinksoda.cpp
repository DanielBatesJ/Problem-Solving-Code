#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

// Sturct of information relating to soda drinking
struct soda{
	// Final total of drinks
	int drinksToday = 0;
	// How many bottles you have left over after drinking
	int overlap = 0;
	// How many bottles you started the day with
	int startingBottles = 0;
	// How many bottles you found during the day
	int duringBottles = 0;
	// A temp bottle value
	int tempBottles = 0;
	// How many bottles you need to get a new bottle.
	int exchangeBottles = 0;
};

// Calculates the soda your friend can drink
void calculate(soda today)
{
	bool check = false;
	// Finds the number of bottles your friend finds in total before drinking any soda.
	today.tempBottles = today.startingBottles + today.duringBottles;

	while(!check)
	{
		// Finds how many soda your friend will be able to drink initially
		today.drinksToday = today.tempBottles / today.exchangeBottles;
		// Finds how many bottles will be leftover after you drink the sodas
		today.overlap = today.tempBottles % today.exchangeBottles;
		today.overlap += today.drinksToday;
		// Repeat while you have enough soda bottles from drinking them to get more.
		while(today.overlap >= today.exchangeBottles)
		{
			today.tempBottles = today.overlap / today.exchangeBottles;
			today.drinksToday += today.tempBottles;
			today.overlap = today.overlap % today.exchangeBottles;
			today.overlap += today.tempBottles;
		};
		// Print the final number
		cout << today.drinksToday << endl;
		check = true;
		return;
	};
}

// This main is all I/O for the user to input their information
int main()
{
	soda today;
	bool check;

	// User input loops that check to make sure the input is valid, then save the information in the soda struct.
	do{
		cout << "How many soda bottles does your friend have at the start of the day (0 < x < 1000):";
		cin >> today.startingBottles;
		if((today.startingBottles >= 1000) || (today.startingBottles < 0))
		{
			cout << "Invalid Input: Make sure to use a positive number less than 1000.\n";
			check = false;
		}			
		else
		{
			check = true;
		}
	}while(!check);

	do{
		cout << "How many soda bottles did your friend find during the day (0 < x < 1000):";
		cin >> today.duringBottles;
		if((today.duringBottles >= 1000) || (today.duringBottles < 0))
		{
			cout << "Invalid Input: Make sure to use a positive number less than 1000.\n";
			check = false;
		}			
		else
		{
			check = true;
		}
	}while(!check);

	do{
		cout << "How many empty soda bottles does your friend need to exchange for a new soda bottle (1 < x < 2000):";
		cin >> today.exchangeBottles;
		if((today.exchangeBottles >= 2000) || (today.exchangeBottles < 1))
		{
			cout << "Invalid Input: Make sure to use a positive number less than 1000.\n";
			check = false;
		}			
		else
		{
			check = true;
		}
	}while(!check);

	// Take the information saved into the instance of the struct, and pass it into a calculation function
	calculate(today);

	return 0;
}