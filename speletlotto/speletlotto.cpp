
#include "bubblesort.h"
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	int* choices = new int[7];
	int input = 0;
	int error = 0;
	cout << "Lotto! chose 7 unique integers from 1 - 35.\n";
	for (int i = 0; i < 7; i++)
	{
		error = 0;
		while (!(cin >> input))
		{
			cout << "Not valid, only 1 - 35 valid!\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (input > 35 || input < 1)
			error = 1;
		for (int j = 0; j < i; j++)
		{
			if (input == choices[j])
				error = 2;
		}
		if (error)
		{
			cout << "Error! You " << ((error == 1) ? "chose a number out of the range\n" : "have already used this number\n");
			--i;
		}
		else
			choices[i] = input;
		
	}

	Sort::sort(choices, 7);
	srand(time(0));
	int winnumbers[7];
	// tilldelning av de sju talen som vann
	for (int i = 0; i < 7; i++)
	{
		winnumbers[i] = rand() % 35 + 1;
	}
	// kollar så att alla tal är unika
	bool different = true;
	while (different)
	{
		different = false;
		for (int i = 0; i < 7; i++) {
			for (int j = i + 1; j < 7; j++)
			{
				if (winnumbers[i] == winnumbers[j]) {
					winnumbers[j] = rand() % 35 + 1;
					different = true;
				}
			}
		}
	}
	short wincount = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++) {
			if (winnumbers[j] == choices[i])
				wincount++;
		}

	}

	cout << "Your choices were: ";
	for (int i = 0; i < 7; i++)
		cout << choices[i] << " ";
	cout << endl;
	delete[] choices;
	choices = nullptr;
	cout << "You got " << wincount << " correct number";
	if (wincount > 1)
		cout << "s";
	cout << endl;
	Sort::sort(winnumbers, 7);
	cout << "The correct numbers were: ";
	for (int i = 0; i < 7; i++)
	{
		cout << winnumbers[i] << " ";
	}
	return 0;
	
}


