// Arrays2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

void printTable(int[12][9], string[12]);
void rec_nonRec_visitors(int[12][9]);
void tent_and_rv(int[12][9]);

int main()
{
	int choice;
	int visitors[12][9];
	string months[12];

	cout << endl << "  Visitors To Acadia National Park" << endl << endl;

	cout << "  1) Display Park Data" << endl;
	cout << "  2) Display total number of recreational and non-recreational visitors" << endl;
	cout << "  3) Display total tent and RV campers by month" << endl;
	cout << "  4) Display the number of recreational visitors for a certain month" << endl << endl;
	cout << "  Enter your selection and press ENTER:";
	cin >> choice;
	cout << endl << endl;

	if (choice == 1)
	{
		printTable(visitors, months);
	}
	else if (choice == 2)
	{
		rec_nonRec_visitors(visitors);
	}
	else if (choice == 3)
	{
		tent_and_rv(visitors);
	}
	else
	{

	}
		system("pause");

		return 0;



	system("pause");
    return 0;
}

void printTable(int visitors[12][9], string months[12])
{
	ifstream visitorsFile;
	ifstream monthsFile;

	visitorsFile.open("AcadiaVisitors.txt");
	monthsFile.open("Months.txt");

	cout << left << "  " << setw(11) << "Month" << setw(11) << "Rec" << setw(11) << "Non-Rec" << setw(11) << "Con Lodge" << setw(11) << "Tent"
		<< setw(11) << "RV" << setw(11) << "Con Camp" << setw(11) << "Back Camp" << setw(11) << "Misc Camp" << setw(11) << "Total" << endl;

	for (int row = 0; row < 12; row++)
	{
		monthsFile >> months[row];
		cout << left << "  " << setw(11) << months[row];

		for (int col = 0; col < 9; col++)
		{
			visitorsFile >> visitors[row][col];
			cout << left << setw(11) << visitors[row][col];
		}

		cout << endl;
	}
	visitorsFile.close();
	monthsFile.close();
}

void rec_nonRec_visitors(int visitors[12][9])
{
	int total = 0;
	int combinedTotal = 0;

	ifstream visitorsFile;
	ifstream monthsFile;

	visitorsFile.open("AcadiaVisitors.txt");
	monthsFile.open("Months.txt");

	for (int row = 0; row < 12; row++)
	{		
		for (int col = 0; col < 9; col++)
		{
			visitorsFile >> visitors[row][col];
			
			if (col > 1)
			{
				visitors[row][col] = 0;
			}
			else 
			{
				total += visitors[row][col];
			}
		}
	}

	cout << total << endl;

	visitorsFile.close();
	monthsFile.close();
}

void tent_and_rv(int visitors[12][9])
{
	int total = 0;
	int combinedTotal = 0;

	ifstream visitorsFile;
	ifstream monthsFile;

	visitorsFile.open("AcadiaVisitors.txt");
	monthsFile.open("Months.txt");

	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			visitorsFile >> visitors[row][col];

			if (col == 3 || col == 4)
			{
				total += visitors[row][col];
			}
			else
			{
				visitors[row][col] = 0;
			}
		}
	}

	cout << total << endl;

	visitorsFile.close();
	monthsFile.close();
}