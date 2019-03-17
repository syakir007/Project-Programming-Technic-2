#include <iostream>
#include <string>

using namespace std;
void menuBranch();
void saleBranch();
void statSale();

void Menu()
{
	unsigned int choice;
	do
	{
		cout << "\tMENU" << endl;
		cout << "-----------------------" << endl;
		cout << "1)Branch" << endl;
		cout << "2)Sales all Branches" << endl;
		cout << "3)Statistic of Sales" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: menuBranch();
			break;
		case 2: saleBranch();
			break;
		case 3: statSale();
			break;
		}

	} while (choice != 4);
}

void saleBranch()
{
	cout << "sale branch" << endl;
}
void menuBranch()
{
	cout << "menu branch" << endl;
}
void statSale()
{
	cout << "statistic sales" << endl;
}


int main()
{
	Menu();


	return 0;
}

