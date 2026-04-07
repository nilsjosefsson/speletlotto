
// Reset
#define RESET   "\033[0m"

// Regular colors
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Bright colors
#define BBLACK   "\033[90m"
#define BRED     "\033[91m"
#define BGREEN   "\033[92m"
#define BYELLOW  "\033[93m"
#define BBLUE    "\033[94m"
#define BMAGENTA "\033[95m"
#define BCYAN    "\033[96m"
#define BWHITE   "\033[97m"

// Background colors
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^ Konsolfärger, enbart dekorativ använder ANSI

#include <iostream>
#include <ctime>

class Lottoutils
{
public:
	static void sort(int* arr, int length) 
	{
		for (int k = 0; k < length - 1; k++)
		{
			for (int i = 0; i < length - 1; i++) {
				if (arr[i] > arr[i + 1])
				{
					int swap = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = swap;
				}
			}
		}
		return;
	}
	static void uniquenumbers(int* arr, int length) 
	{
		bool different = true;
		while (different)
		{
			different = false;
			for (int i = 0; i < length; i++) {
				for (int j = i + 1; j < length; j++)
				{
					if (arr[i] == arr[j]) {
						arr[j] = rand() % 35 + 1;
						different = true;
					}
				}
			}
		}
		return;
	}
	static bool compareuniquenumbers(int* arr, int* arr2, int length, int length2)
	{
		bool haschanged = false;
		bool different = true;
		while (different)
		{
			different = false;
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length2; j++) {
					if (arr[i] == arr2[j])
					{
						arr[i] = rand() % 35 + 1;
						different = true;
						haschanged = true;
					}
				}
			}
		}
		return haschanged;
	}
	static void randomnumbers(int* arr, int length) 
	{
		for (int i = 0; i < length; i++)
			arr[i] = rand() % 35 + 1;
	}
	static int wincounter(int* arr, int* arr2, int length, int length2) {
		int wincount = 0;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length2; j++) {
				if (arr[i] == arr2[j])
					wincount++;
			}
		}
		return wincount;
	}
	static void newsegment() 
	{
		std::cout << "#";
		for (int i = 0; i < 50; i++)
			std::cout << "*";
		std::cout << "#\n";
	}
};
int main()
{
	srand(time(0));
	int choices[7];
	int input = 0;
	int error = 0;
	std::cout << "Lotto! chose 7 unique integers from 1 - 35.\n";
	for (int i = 0; i < 7; ((error)?i=i:i++))
	{
		std::cout << GREEN;
		error = 0;
		while (!(std::cin >> input))
		{
			std::cout << RED << "Error! You did not chose a number\n" << RESET;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		if (input > 35 || input < 1)
			error = 1;
		for (int j = 0; j < i; j++)
		{
			if (input == choices[j])
				error = 2;
		}
		if (error)
			std::cout << RED << "Error! You " << ((error == 1) ? "chose a number out of the range\n" : "have already used this number\n") << RESET;
		else
			choices[i] = input;
	}
	std::cout << RESET;
	// Sorterar valen med bubblesort
	Lottoutils::sort(choices, 7);
	int wincount = 0;
	int wincount2 = 0;
	int winnumbers[7];
	int extranumbers[4];
	// Tilldelning av de sju talen som vann samt sortering och kollar om all är unika
	Lottoutils::randomnumbers(winnumbers, 7);
	Lottoutils::uniquenumbers(winnumbers, 7);
	Lottoutils::sort(winnumbers, 7);
	// Tilldelning av de 4 extratalen, sort, unik, unik mot winnumbers
	Lottoutils::randomnumbers(extranumbers, 4);
	do
	{
		Lottoutils::uniquenumbers(extranumbers, 4);
	} while (Lottoutils::compareuniquenumbers(extranumbers, winnumbers, 4, 7));
	Lottoutils::sort(extranumbers, 4);
	// wincount är antalet av winnumbers som var korrekt och wincount2 är antalet extranummer som var korrekt
	wincount += Lottoutils::wincounter(winnumbers, choices, 7, 7);
	wincount2 += Lottoutils::wincounter(extranumbers, choices, 4, 7);
	Lottoutils::newsegment();
	std::cout << "Your choices were: ";
		for (int i = 0; i < 7; i++)
			std::cout << choices[i] << " ";
	std::cout << std::endl;
	std::cout << "You got " << wincount + wincount2 << " correct number";
	if (wincount + wincount2 > 1)
		std::cout << "s";
	std::cout << std::endl;
	if (wincount2)
		std::cout << wincount2 << ((wincount2 > 1) ? " Were extra numbers": " Was an extra number");
	std::cout << std::endl;
	std::cout << "The correct main numbers were: ";
	for (int i = 0; i < 7; i++)
		std::cout << winnumbers[i] << " ";
	std::cout << std::endl;
	std::cout << "The correct extra numbers were: ";
	for (int i = 0; i < 4; i++)
		std::cout << extranumbers[i] << " ";
	return 0;
	}


