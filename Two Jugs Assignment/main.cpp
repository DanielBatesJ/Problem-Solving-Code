#include <iostream>
#include <string>

using namespace std;

string attempts[100];

void printJug(int currJug1, int currJug2, int operationCount)
{
	/*
	This first set of statements adds the integer values as strings to an array of strings to mirror the output.
	 */
	int i;
	string temp;
	temp = to_string(currJug1) + "	" + to_string(currJug2);
	attempts[operationCount] = temp;

	for(i = 0; i < operationCount - 1; i++)
	{	// Checks to see if steps are repeating, to know when the problem can't be solved.
		if(temp == attempts[i])
		{
			// A common case is that if the remainder of jug1/jug2 is == 0, than you cannot find anything that isn't either of the two numbers
			cout << "Cannot fulfill request.\n";
			exit(0);
		}
	}
	/*
	The second half of this function just prints the current status of the jugs to the user.
	 */
	cout << currJug1 << "	" << currJug2 << endl;
}

void trueCondition(int currJug1, int currJug2, int waterTotal, int operationCount)
{	// Checks to see if the success conditions are met, prints out a message, and quits the program.
	if(currJug1 + currJug2 == waterTotal)
	{
		cout << "Request Complete\n";
		cout << "Steps taken: " << operationCount << endl;
		exit(0);	
	}
}

void fullFromSource(int jug, int &currJug, int &operationCount)
{	// Fills the current jug.
	currJug = jug;
	operationCount++;
}

void emptyToSource(int jug, int &currJug, int &operationCount)
{	// Dumps the current jug.
	currJug = 0;
	operationCount++;
}

void untilFull(int jug1, int jug2, int &currJug1, int &currJug2, int &operationCount)
{
	int i;
	if(currJug2 != jug2)
	{	// If the jug you're pouring into isn't full...
		if((currJug2 + currJug1) >= jug2)
		{	// Checks to make sure the jug can be filled with the water on hand.
			for(i = 0; i < jug2; i++)
			{	// Takes removes water from one, and adds it to the other
				currJug2++;
				currJug1--;
				if(currJug2 == jug2)
				{
					operationCount++;
					return;
				}
			}
			cout << "Error\n";
			printJug(currJug1, currJug2, operationCount);
		}
	}
}

void untilEmpty(int jug1, int jug2, int &currJug1, int &currJug2, int &operationCount)
{
	// Pours from one jug, into another, until the one you're pouring from is empty.
	int i;
	if(currJug1 != 0)
	{	// Checks to make sure that the jug you're pouring into isn't going to reach capacity before the end of this function.
		if((currJug1 + currJug2) <= jug2)
		{
			for(i = 0; i < jug1; i++)
			{	// Takes water out of one jug, and moves it into the other
				currJug2++;
				currJug1--;
				if(currJug1 == 0)
				{
					operationCount++;
					return;
				}
			}
			cout << "Error\n";
			printJug(currJug1, currJug2, operationCount);
		}
	}	
}

void operations(int jug1, int jug2, int waterTotal)
{
	int currJug1 = 0;
	int currJug2 = 0;
	int operationCount = 0;
	int temp1;
	// The following two if statements are for if the total can be satisfied by filling one jug by itself.
	if(jug1 == waterTotal)
	{
		printJug(currJug1, currJug2, operationCount);
		fullFromSource(jug1, currJug1, operationCount);
		
		printJug(currJug1, currJug2, operationCount);
		trueCondition(currJug1, currJug2, waterTotal, operationCount);	
	}
	if(jug2 == waterTotal)
	{
		printJug(currJug1, currJug2, operationCount);
		fullFromSource(jug2, currJug2, operationCount);
		
		printJug(currJug1, currJug2, operationCount);
		trueCondition(currJug1, currJug2, waterTotal, operationCount);	
	}
	// Checks if the first jug is larger than the second, if it is, it re-orders them to keep the main loop simpler.
	if(jug1 > jug2)
	{
		//system("clear");
		cout << "Reordering so that the larger value is \"B\"\n";
		temp1 = jug1;
		jug1 = jug2;
		jug2 = temp1;
		cout << "A(" << jug1 << ")	B(" << jug2 << ")\n";
		cout << "Request Amount: " << waterTotal << endl;
	}
	// This case checks to see if both of the jugs together would give us the total.
	if((jug1 + jug2) == waterTotal)
	{
		printJug(currJug1, currJug2, operationCount);
		fullFromSource(jug2, currJug2, operationCount);

		printJug(currJug1, currJug2, operationCount);
		fullFromSource(jug1, currJug1, operationCount);
		
		printJug(currJug1, currJug2, operationCount);
		trueCondition(currJug1, currJug2, waterTotal, operationCount);		
	}
	if(((jug1 % 2 == 0) && (jug2 % 2 == 0)) && (waterTotal%2 != 0))
	{
		cout << "Two even jugs cannot change to form an odd jug.\n";
	}
	/*
	The main function loop.
	 */
	do{
		printJug(currJug1, currJug2, operationCount);
		// Fill up the larger jug
		fullFromSource(jug2, currJug2, operationCount);
		// Print what you have done
		printJug(currJug1, currJug2, operationCount);
		// Check to see if the condition is met (these two sets repeat after every operation.)
		trueCondition(currJug1, currJug2, waterTotal, operationCount);
		// Pours from the larger jug, into the smaller jug until it's full.
		untilFull(jug2, jug1, currJug2, currJug1, operationCount);
		printJug(currJug1, currJug2, operationCount);
		trueCondition(currJug1, currJug2, waterTotal, operationCount);
		// Dumps the smaller jug
		emptyToSource(jug1, currJug1, operationCount);
		printJug(currJug1, currJug2, operationCount);
		trueCondition(currJug1, currJug2, waterTotal, operationCount);
		// While the current jug isn't 0...
		while(currJug2 != 0)
		{
			// If the jug we're pouring from can't fill jug2.
			if((currJug1 + currJug2) < jug1)
			{
				untilEmpty(jug2, jug1, currJug2, currJug1, operationCount);
				printJug(currJug1, currJug2, operationCount);
				trueCondition(currJug1, currJug2, waterTotal, operationCount);
			}
			else
			{
				// Re-pour from the larger into the smaller, until full
				untilFull(jug2, jug1, currJug2, currJug1, operationCount);
				printJug(currJug1, currJug2, operationCount);
				trueCondition(currJug1, currJug2, waterTotal, operationCount);
			}
			// If the larger jug is 0, repeat the initial steps again, for larger numbers with more possibilities.
			if(currJug2 == 0)
			{
				fullFromSource(jug2, currJug2, operationCount);
				printJug(currJug1, currJug2, operationCount);
				trueCondition(currJug1, currJug2, waterTotal, operationCount);

				untilFull(jug2, jug1, currJug2, currJug1, operationCount);
				printJug(currJug1, currJug2, operationCount);
				trueCondition(currJug1, currJug2, waterTotal, operationCount);

				emptyToSource(jug1, currJug1, operationCount);
				printJug(currJug1, currJug2, operationCount);
				trueCondition(currJug1, currJug2, waterTotal, operationCount);
			}
			emptyToSource(jug1, currJug1, operationCount);
			printJug(currJug1, currJug2, operationCount);
			trueCondition(currJug1, currJug2, waterTotal, operationCount);	
			// Checks to see if the combination is possible, with two evens making an odd being impossible, after a few steps.
		}
	}while((currJug1 != jug1) && (currJug2 != jug2));

}

void setUp()
{

	int jug1;
	int jug2;
	int waterTotal;
	bool check = true;
	// Loop to get proper input from the user
	do{
		do{
			cout << "Enter the size for the first jug: ";
			cin >> jug1;
			if(jug1 <= 0)
			{
				cout << "Invalid Input: Make sure to use a positive, non-zero integer.\n";
			}					
		}while(!jug1 > 0);
		do{
			cout << "Enter the size for the second jug: ";
			cin >> jug2;
			if(jug2 <= 0)
			{
				cout << "Invalid Input: Make sure to use a positive, non-zero integer.\n";
			}					
		}while(!jug2 > 0);
	}while((jug2 + jug1) > waterTotal);

	// Second input loop, for the total amount of water
	do{
		cout << "Enter the total amount of water: ";
		cin >> waterTotal;
		if((waterTotal <= 0) || (waterTotal > jug1+jug2))
		{
			cout << "Invalid total amount of water. Make sure the total is less than, or equal to the total amount avalible in the jugs.\n";
			check = false;
		}
	}while(check == false);


	cout << "A(" << jug1 << ")	B(" << jug2 << ")\n";
	cout << "Request Amount: " << waterTotal << endl;

	// Jumps to the next function
	operations(jug1, jug2, waterTotal);
}

int main()
{	
	// Just loads the next function, setUp.
	setUp();
	return 0;
}
