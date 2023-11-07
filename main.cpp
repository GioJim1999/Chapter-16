//Giovanni Jimenez
//11-10-2013
//Chapter 16 - Assignments
//CMPR 121

#include<iostream>
#include<cmath>
#include"input.h"
#include"TestScores.h"
#include"SimpleVector.h"
using namespace std;

//Function prototypes:
int menuOptions();
void Challenge3();
void Challenge4();
void Challenge7();
void Challenge8();

//Function Templates
template <class T>
T maximum(T x, T y);

template <class T>
T minimum(T x, T y);

template <class T>
T absValue(T x);

int main()
{

	do
	{
		system("cls");
		cout << "\n\tChapter 16 Assignment - Giovanni Jimenez";
		switch (menuOptions())
		{
		case 0:
			exit(1); break;
		case 3:
			Challenge3(); break;
		case 4:
			Challenge4(); break;
		case 7:
			Challenge7(); break;
		case 8:
			Challenge8(); break;

		}
	} while (true);

	cout << "\n";
	system("pause");
	return EXIT_SUCCESS;
}

int menuOptions()
{
	cout << "\n\t------------------------------------------------------";
	cout << "\n\t3. Challenge 3 - Minimum/Maximum Templates";
	cout << "\n\t4. Challenge 4 - Absolute Value Template";
	cout << "\n\t6. Challenge 6 - ";
	cout << "\n\t7. Challenge 7 - Test Scores Class";
	cout << "\n\t8. Challenge 8 - Simple Vector Modification";
	cout << "\n\t12. Challenge 12 - ";
	cout << "\n\t------------------------------------------------------";
	cout << "\n\t0. Exit Program";
	cout << "\n\t------------------------------------------------------";
	return inputInteger("\n\tOptions: ", 0, 12);
}

void Challenge3()
{
	system("cls");
	cout << "\n\t3. Challenge 3 - Minimum/Maximum Templates";
	cout << "\n\t------------------------------------------------------\n";

	int intX, intY;
	double doubleX, doubleY;

	intX = inputInteger("\n\tEnter an integer positive of negative: ");
	intY = inputInteger("\n\tEnter an integer positive of negative: ");

	cout << "\n\tMaximum and Minimum Functions using integers";
	cout << "\n\t------------------------------------------------------\n";
	cout << "\n\tMaximum of previous two numbers: " << maximum(intX, intY) << '\n';
	cout << "\n\tMinumum of last two numbers: " << minimum(intX, intY) << '\n';

	doubleX = inputDouble("\n\tEnter a decimal number positive of negative: ");
	doubleY = inputDouble("\n\tEnter a decimal number positive of negative: ");

	cout << "\n\tMaximum and Minimum Functions using decimals";
	cout << "\n\t------------------------------------------------------\n";
	cout << "\n\tMaximum of previous two numbers: " << maximum(doubleX, doubleY) << '\n';
	cout << "\n\tMinumum of last two numbers: " << minimum(doubleX, doubleY) << '\n';

	cout << "\n";
	system("pause");
}

void Challenge4()
{
	system("cls");
	cout << "\n\t4. Challenge 4 - Absolute Value Template";
	cout << "\n\t------------------------------------------------------\n";
	int intX = inputInteger("\n\tEnter an integer positive or negative:	");
	cout << "\n\tAboslute Value of previous number: " << absValue(intX);

	cout << '\n';
	double doubleX = inputDouble("\n\tEnter a decimal number positive or negative: ");
	cout << "\n\tAbsolute Value of previous decimal number: " << absValue(doubleX);

	cout << "\n\n";
	system("pause");
}

void Challenge7()
{
	system("cls");
	cout << "\n\t7. Challenge 7 - Test Scores Class";
	cout << "\n\t------------------------------------------------------\n";
	int length = inputInteger("\n\tHow many tests scores: ", true);
	int* tests = new int[length];

	for (int i = 0; i < length; i++)
	{
		*(tests + i) = inputInteger("\n\tEnter score for test number [" + to_string(i) + "]: ");
	}


	TestScores tests1(tests, length);

	try
	{
		cout << "\n\tTest Scores Average: " << tests1.averageTestScores();
	}
	catch (TestScores::ScoreToBig)
	{
		cout << "\n\tERROR: A test score was found that was greater than 100!";
	}
	catch (TestScores::NegativeTestScore)
	{
		cout << "\n\tERROR: A test score was found that was negative!";
	}

	cout << '\n';
	system("pause");
}

void Challenge8()
{
	system("cls");
	cout << "\n\t8. Challenge 8 - Simple Vector Modification";
	cout << "\n\t------------------------------------------------------\n";
	SimpleVector<int> test(6);

	for (int i = 0; i < 6; i++)
		test[i] = inputInteger("\n\tEnter a number: ");



	cout << "\n";

	cout << "\n";
	system("pause");
}

//FUNCTION TEMPLATES FOR CHALLENGES 3 AND 4
template <class T>
T maximum(T x, T y)
{
	if (x > y)
		return x;
	else 
		return y;
}

template <class T>
T minimum(T x, T y)
{
	if (x < y)
		return x;
	else
		return y;
}

template <class T>
T absValue(T x)
{
	return abs(x);
}

