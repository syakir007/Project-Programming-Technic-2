#include <iostream>
#include <string>

using namespace std;
void menuBranch();
void saleBranch();
void statSale();

class Read
{
	
	public:
	void readData(int price[], string names[], int &numData)
{
	
	numData = 0;
	
	ifstream inFile;
	inFile.open("data.csv");
	 
	if(inFile.fail())
	{
		cout<<"error open data.csv";
		exit (1);
	}
	
	while (inFile>>names[numData])
	{
		inFile>>price[numData];
		numData++;
	}
}

int getHighestPrice (int price[], int size)
{
	
	int max = price[0];
	int indH;
	
	for(int i=0; i<size; i++)
	{
		if (price[i]>max)
		{
			max = price[i];
			indH = i;
		}
	}
	
	return indH;
}

int getLowestPrice (int price[], int size)
{
	
	int min = price[0];
	int indL;
	
	for(int i=0; i<size; i++)
	{
		if (price[i]<min)
		{
			min = price[i];
			indL = i; 
		}
	}
	
	return indL;

}

float averagePrice(int price[], int size)
{
	
	float avg;
	float total=0;
	
	for(int i=0; i<size; i++)
	{
		total = total + price[i];
	}
	
	avg = total / size;
	
	return avg;

}

};

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

