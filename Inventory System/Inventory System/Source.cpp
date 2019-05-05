
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class Branch
{
private:
	string b_code;
	double profit;
	int index;

public:
	Branch() {}
	Branch(string c,double p) : b_code(c), profit(p) {}

	void setB_code(string b) { b_code = b; }
	string getB_code() { return b_code; }

	void setProfit(double p) { profit = p; }
	double getProfit() { return profit; }

	void setInfo(string c, double p) {b_code = c, profit = p;}

	friend ostream& operator<<(ostream& out,Branch &b)
	{
		out<<b.b_code<<"\t\t"<<"RM"<<b.profit<<endl;
		return out;
	}
};

class Sale
{
private:
	string month;
	Branch* branch;
	unsigned branch_count;
public:
	Sale(){}

	Sale(string m, Branch* b): month(m), branch(0), branch_count(0)
	{
		if(b != 0)
		{
			branch = new Branch[1];
			branch[0].setInfo(b->getB_code(), b->getProfit());
			branch_count++;
		}
	}

	void addBranch(Branch *b)
	{
		if(branch == 0)
		{
			branch = new Branch[1];
			branch[0].setInfo(b->getB_code(), b->getProfit());
			branch_count++;
		}
		else
		{
			Branch* temp = new Branch[branch_count + 1];
			for(int i = 0; i < branch_count; i++)
			{
				temp[i] = branch[i];
			}
			temp[branch_count].setInfo(b->getB_code(), b->getProfit());
			delete [] branch;
			branch = temp;
			branch_count++;
		}
	}

	friend ostream& operator<<(ostream& out, Sale &s)
	{
		for (int i = 0; i < s.branch_count; i++)
		{
			out<<i+1<<") ";
			out<<s.branch[i]<<endl;
		}
		return out;
	}

	void removeBranch(int index)
	{
		if(index < 1 || index > branch_count)
		{
			cout<<"Invalid Choice!!!!"<<endl;
			return;
		}

		Branch* temp = new Branch[branch_count -1];

		int j = 0;

		for(int i = 0; i < branch_count; i++)
		{
			if( i != index -1)
			{
				temp[j].setInfo(branch[i].getB_code(), branch[i].getProfit());
				j++;
			}
		}

		delete [] branch;
		branch = temp;
		branch_count--;
	}

	string getB_code()
	{
		for(int i = 0; i <branch_count; i++)
		{
			cout<<i+1;
			return branch[i].getB_code();
		}
	}
};

class item
{
    private:
        char name[20];
        int code[20];
        float price[20];
        int z;
    public:
		item(){z=5;}
    	void setName(char* Name)
    	{
    		for (int i=0; i<5; i++)
    		{
    			name[i] = Name[i];
    		
			}
		}
		
		void setCode(int* Code)
    	{
    		for (int i=0; i<5; i++)
    		{
    			code[i] = Code[i];
    		
			}
		}
		
		void setPrice(float* Price)
    	{
    		for (int i=0; i<5; i++)
    		{
    			price[i] = Price[i];
    		
			}
		}
	
		
        void add_(void);
        void delete_(void);
        void sell_(void);
        void display_(void);
  

};

void item :: add_(void)
{
    cout<<"\nEnter the item category    : ";
    cin>>name[z];
    cout<<"Enter the item code        : ";
    cin>>code[z];
    cout<<"Enter the price of the item: ";
    cin>>price[z];
    z++;
    
    system("pause");
	system("CLS");

}

void item :: delete_(void)
{
     int i,j;

     cout<<"\nPlease enter the item code:";
     cin>>i;
     for(j=0;j<z;j++)
		{
			if(code[j]==i)
			{
				price[j]=0;
				cout<<"\nThe item is deleted from the list.";
				break;
			}
		}
    
    system("pause");
	system("CLS");
}

void item :: sell_(void)
{
    char a;
    int i,j;
    float total_price=0;

    cout<<"\nEnter the item code:";
    cin>>i;
    for(j=0;j<z;j++)
    {
      if (code[j]==i)
      {
        if(price[j]==0)
        {
          cout<<"\nSorry.There is no item left in this category.";
          cout<<"\nDo you want to buy another item? ( y\\n ): "<<endl;
          cin>>a;

          if (a=='y')
          {
			cout<<"\nEnter the item code:";
			cin>>i;
			j=-1;
          }
          else if (a=='Y')
          {
			cout<<"\nEnter the item code:";
			cin>>i;
			j=-1;
          }
          else
          {
			if (total_price!=0)
			{
				cout<<"\nYour total price is: ";
				cout<<total_price<<" Dollar."<<"\nThank You.\nPress any key to continue...";
			}

			cout<<"Bye...bye...\nPress any key to continue...";
			break;
          }
        }
        else
        {
          cout<<"Item category is: "<<name[j];
          cout<<"\nItem price is   : "<<price[j]<<"usd."<<endl;

          total_price+=price[j];
          price[j]=0;

          cout<<"\nDo you want to buy another item ( y\\n ): ";
          cin>>a;

          if (a=='y')
          {
			cout<<"\nEnter the item code:";
			cin>>i;
			j=-1;
          }
          else if (a=='Y')
          {
			cout<<"\nEnter the item code:";
			cin>>i;
			j=-1;
          }
          else
          {  
			cout<<"\nYour total price is: ";
			cout<<total_price<<" Dollar."<<"\nThank You.\nPress any key to continue...";
			break;
          }
        }
      }
    }
   	system("pause");
	system("CLS");
}

 void item :: display_()
{
       int i,j=0;

       for(i=0;i<z;i++)
		{
			cout<<j+1<<".Item category is: "<<name[i];
			cout<<"\n  Item code is    : "<<code[i];
			cout<<"\n  Item price is   : "<<fixed<<setprecision(2)<<price[i]<<" usd."<<endl<<endl;
			j++;
		}
        system("pause");
		system("CLS");
}

 int main ()
{
	int i;
    item shoping_mall;
	
	int size = 0; 
	string scores[100];
	string scores2[100];
	string scores3[100];
    string names[20];
    int Scores[20];
    float Scores2[20];
    char names1[5];
	
	Sale m1("January",0);
	int choice;
	do
	{
		cout<<"\t\t\tWelcome to Inventory System\t\t\t"<<endl;
		cout<<"\n\n";
		cout<<"\tMain Menu"<<endl;
		cout<<"1) View Sales"<<endl;
		cout<<"2) Goto Branch"<<endl;
		cout<<"3) Add New Branch"<<endl;
		cout<<"4) Delete Branch"<<endl;
		cout<<"5) Print report" <<endl;
		cout<<"6) Exit System" <<endl;
		cout<<endl;

		cout<<"Enter Your Choice : ";
		cin>>choice;

		if(choice == 1)
		{
			cout<<"Branch Code\t\tProfit"<<endl;
			cout<<m1;
			system("pause");
			system("CLS");
		}

		else if(choice == 2)
		{
			string c;
			cout<<"Enter the Branch code, Example (JB10001.csv): "<<endl;
			cout<<"This is available branch file: "<<endl<<endl;
			cout<<m1<<endl;
			cin >> c;
			
			ifstream inFile;
			inFile.open(c.c_str());
	 
			if(inFile.fail())
			{
				cout<<"error open "<<c;
				break;
			}
	
			while (inFile.get(names1[size]))
			{
				getline(inFile, scores3[size], ',');
				getline(inFile, scores[size], ',');
				getline(inFile, scores2[size], '\n');
		
				stringstream geek(scores[size]);
				geek >> Scores[size];
	
				stringstream geek2(scores2[size]);
				geek2 >> Scores2[size];

				size++;
			}
	
				shoping_mall.setName(names1);
				shoping_mall.setCode(Scores);
				shoping_mall.setPrice(Scores2);

			while(1)
			{
				system("cls");
				cout<<"\nWhat do you want to do?"<<endl;
				cout<<"\n1: Add a new item.";
				cout<<"\n2: Delete an item.";
				cout<<"\n3: Sale an item.";
				cout<<"\n4: Display all items.";
				cout<<"\n5: Exit"<<endl;
				cout<<"\n\n Choose a number:";
				cin>>i;

					switch(i)
					{
						case 1:
						{
							shoping_mall.add_();
							break;
						}
						case 2:
						{
							shoping_mall.delete_();
							break;
						}
						case 3:
						{
							shoping_mall.sell_();
							break;
						}
						case 4:
						{
							shoping_mall.display_();
							break;
						}

						case 5:
						{
							cout<<"Good Bye! Thank you.";
							break;
						}
					}
					if (i==5)
					break;
			}
			inFile.close();
			system("pause");
			system("CLS");
		}

		else if(choice == 3)
		{
			Branch b1;
			double p = 0;
			string c;
			cout<<"Enter the new Branch code (JB10001.csv):";
			cin>>c;

			ifstream inFile;
			inFile.open(c.c_str());
	 
			if(inFile.fail())
			{
				cout<<"error open "<<c;
				break;
			}
	
			while (inFile.get(names1[size]))
			{
				getline(inFile, scores3[size], ',');
				getline(inFile, scores[size], ',');
				getline(inFile, scores2[size], '\n');
		
				stringstream geek(scores[size]);
				geek >> Scores[size];
				
				stringstream geek2(scores2[size]);
				geek2 >> Scores2[size];
				p = p + Scores2[size];
				size++;
			}
			b1.setProfit(p);
			b1.setB_code(c);
			m1.addBranch(&b1);
			system("pause");
			system("CLS");
		}

		else if(choice == 4)
		{
			unsigned int index;
			cout<<m1<<endl;
			cout<<"Enter Branch number you want to delete :";
			cin>>index;
			m1.removeBranch(index);
			system("pause");
			system("CLS");
		}

		else if(choice == 5)
		{
			int index;
			string c;
			string name;
			cout<<"Enter the report name(Report.txt): ";
			cin>>c;
			cout<<"Enter your name: ";
			getline(cin,name,'\n');
			ofstream outfile;
			outfile.open(c.c_str());

			if(outfile.fail())
			{
				cout<<"Error opening file!!!";
				break;
			}

			outfile<<"Created by "<<name<<endl<<
			outfile<<"Branch Code\t\tProfit";
			outfile << m1;
			system("pause");
			system("CLS");
		}

		else if(choice == 6)
		{
			cout<<"Good Bye"<<endl;
			system("pause");
			system("CLS");
		}
		
		else 
		{
			cout<<"Invalid Choice"<<endl;
			system("pause");
			system("CLS");
		}
	}while(choice != 6);
    
    return 0;
}
