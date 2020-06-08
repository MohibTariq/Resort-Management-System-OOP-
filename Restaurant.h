#include<iostream>
#include<string.h>
#include <fstream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class Restaurant{
	private:
		
	char dish[50];
	char description[200];
    int key;
    float price;
    
    public:
    	void checkFin(ifstream &fin) throw (int)
    {
    	

		try
		{
				if(!fin){
					throw 1;   
				}
			}
		catch(int x)
		{
				if(x==1)
				{
					cout<<"Error! File does not exist. ";
					exit(0);
				}
			}
	
}

void checkFout(ofstream &fout) throw (int)
    {
    

		try
		{
				if(!fout)
				{
					throw 1;   
				}
			}
		catch(int x)
		{
				if(x==1)
				{
					cout<<"Error! File does not exist. ";
					exit(0);
				}
			}
	
}


void checkFile(fstream &file) 
    {

		try{
				if(!file){
					throw 1;   
				}
			}
		catch(int x){
				if(x==1){
					cout<<"Error! File does not exist. ";
					exit(0);
				}
			}
	
}	
	

int checkID(int id)
		{
				try
			{
			if(!(id>999) && (id<=9999))
			    {
					throw id ;
			    }	
	
			}
			
			catch(int x)
			{
				cout << "Invalid ID - " << x << endl;
				cout << "Enter valid ID: ";
				cin >> id;
				return checkID(id);
			}
		}
		
void checkName(char n[])
	    {
	    int i;
	    	char a[50];
	    	int z=strlen(n);
	    	try
	    	{
	    		for(i=0 ;i<z;i++ )
	    		{
				
	    		if(!(((n[i]>='a') && (n[i]<='z'))||((n[i]>='A')&&(n[i]<='Z')) || (n[i]== ' ')))
	    		{
	    			z=0;
	    			throw 1;
				}
			}
			}
			catch(int x)
			{
				if(x==1)
				{
					cout<<"Invalid name!Enter again:\n";
					cin.getline(n,19);
					z=strlen(n);
					checkName(n);
					
				}
			}
		}
	//******************************************** M E N U   E D I T   F U N C T I O N S ********************************************//
void FileAdd() 
		{
			ofstream fout;
			fout.open("Menu.txt",ios::app);
			fout.write((char*)this, sizeof(*this));
			fout.close();
		}
		
void MenuAdd()
    	{
    		cout << "\n\n\t\t\t\t********** N E W   D I S H **********" << endl;
    		cout << "\n\t\t\tDish Name:";
    		cin.ignore();
    		cin.getline(dish,49);
    		checkName(dish);
    		cout << "\n\t\t\tDescription: ";
    		cin.ignore();
    		cin.getline(description,199);
    		cout << "\n\t\t\tKey:";
    		cin >> key;
    		checkID(key);
    		cout << "\n\t\t\tPrice: $ ";
    		cin >> price;
			FileAdd();	
		}
		
void ShowDish()
	{		cout << "\n\t\t\tDish Name: " << dish;
    		
    		cout << "\n\t\t\tDescription: " << description;
    		
    		cout << "\n\t\t\tKey: " << key;
    	
    		cout << "\n\t\t\tPrice: $ " << price;
    		
	}
		
void FileOrder() 
		{
			ofstream fout;
			fout.open("CustomerOrder.txt",ios::app);
			checkFout(fout);
			fout.write((char*)this, sizeof(*this));
			fout.close();
		}
				
bool CheckDish(int k)
    {
    	bool flag = false;
				ifstream fin;
				fin.open("Menu.txt", ios::in);
				checkFin(fin);
				fin.read((char*)this,sizeof(*this));
				while(!fin.eof())
				{
					if(k==key)
					{
					ShowDish();
					fin.read((char*)this,sizeof(*this));
					return true;	
					}
				
				}	
				
			if(flag == false)
			{
				cout << "\n\t\t\tNo such record" << endl;
				return false;
			}
			fin.close();
	}
	
void DisplayMenu()
	{
		ifstream fin;
		    	fin.open("Menu.txt", ios::in);
		    	checkFin(fin);
					fin.read((char*)this,sizeof(*this));
					while(!fin.eof())
					{
						ShowDish();
						fin.read((char*)this,sizeof(*this));
					}	
				fin.close();
	}
	
void UpdateMenu(int k)
		{
			fstream file;
			file.open("Menu.txt", ios::in|ios :: out| ios::ate);
			checkFile(file);
			file.seekg(0);
			file.read((char*)this,sizeof(*this));
			while(!file.eof())
			{
				if(k == key)
			{  
		    MenuAdd();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			}
			file.read((char*)this,sizeof(*this));
	}
}

// ****************************************** C U S T O M E R   O R D E R   F U N C T I O N S ******************************************//
void NewOrder()
		{
		   int k;
	       cout << "\t\t\t\t********** N E W   O R D E R **********\n\n" << endl;
	       cout << "\n\t\t\tEnter key:\n\t\t\t ";
	       cin >> k;
	       if (CheckDish(k) == true)
		   {
	       	FileOrder();   
		   } 
		   
		   else
		   {
		   	  return NewOrder();
		   } 
		}

		void CancelOrder(int k)
		{
			ifstream fin;
			ofstream fout;
			fin.open("CustomerOrder.txt",ios::in);
			checkFin(fin);
				fout.open("tempStudents.txt",ios::out);
				checkFout(fout);
				fin.read((char*)this,sizeof(*this));
				while(!fin.eof())
				{
						if(k == key)
				{
					fout.write((char*)this,sizeof(*this));
				}
					fin.read((char*)this,sizeof(*this));
				}
				fin.close();
				fout.close();
				remove("CustomerOrder.txt");
				rename("tempOrder.txt","CustomerOrder.txt");
		}
		
void UpdateOrder(int k)
{
	        fstream file;
			file.open("CustomerOrder.txt", ios::in|ios :: out| ios::ate);
			checkFile(file);
			file.seekg(0);
			file.read((char*)this,sizeof(*this));
			while(!file.eof())
			{
				if(k == key)
			{  
		    NewOrder();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			}
			file.read((char*)this,sizeof(*this));
}
}
		

void GenerateBill()
{
	float total;
	ifstream fin;
	fin.open("CustomerOrder.txt", ios::in|ios :: out);
	checkFin(fin);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
		total+=price;
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();	
	cout << "\n\t\t\tTotal Payment : " << total << endl;
	getch();

}
void PaymentType()
{
	int ch, num, pin;
	while(ch!=0)
	{
	system("cls");
	cout << "\n\t\t\t1. Cash\n\t\t\t2. Credit Card\n\t\t\t0.Exit\n\t\t\t";
	cin >> ch;
	switch(ch)
	{
		case 1:
			{
				GenerateBill();
				getch();
				break;
			}
		
		case 2:
			{
				cout << "\n\t\t\tCredit Card Number:\n\t\t\t ";
				cin >>num;
				cout << "\n\t\t\tEnter Pin:\n\t\t\t ";
				cin >> pin;
				GenerateBill();
				
			}
			
		case 0:
			break;
	}

	
}}

void AdminRestaurant()
{
	int ch,k;
	system("cls");
	cout <<"\t\t\t\t************ E D I T   M E N U ************\n\n" << endl;
	while(ch!=0)
	{
	cout << "\n\t\t\t1. Add New Dish in Menu\n\t\t\t2. Display Menu\n\t\t\t3. Update Menu\n\t\t\t0. Exit\n\t\t\t";
	cin >> ch;
	switch(ch)
	{
		case 1:
			{
				system("cls");
				MenuAdd();
				ShowDish();
				getch();
				system("cls");
				break;
				
			}
		
		case 2:
			{
				system("cls");
				DisplayMenu();
				getch();
				system("cls");
				break;
			}
			
		case 3:
			{
				system("cls");
				cout << "\t\t\t\t\t\t*** C U R R E N T   M E N U ***\n\n" << endl;
				DisplayMenu();
				cout << "\n\t\t\tEnter Dish Key you want to Update:\n\t\t\t ";
				cin >> k;
				UpdateMenu(k);
				break;	
			}
			
		case 0:
			{
				break;
			}
}
}}

void CustomerOrder()
{
	int ch,ans,k;
	cout <<"\t\t\t\t*** C U S T O M E R  O R D E R ***\n\n" << endl;
	while(ch!=0)
	{
		system("cls");
		cout << "\n\t\t\t1. Add Order\n\t\t\t2. Delete Order\n\t\t\t3. Update Order\n\t\t\t4. Generate Bil\n\t\t\t0. Exit\n\t\t\t";
	cin >> ch;
	switch(ch)
	{
	case 1:
		{
			system("cls");
			NewOrder();
			getch();
			system("cls");
			GenerateBill();
			break;
		}
		
	case 2:
		{
			system("cls");
			cout << "\n\t\t\tDo you want to delete the complete order?\n\t\t\t1. Yes\n\t\t\t2. No\n\t\t\t";
			cin >> ans;
			if(ans==1)
			{
				remove("CustomerOrder.txt");
			}
			
			else if(ans==2)
			{
				cout << "\n\t\t\t Enter key of the Dish to be removed from the order:\n\t\t\t ";
				cin >>k;
				CancelOrder(k);	
			}
			
		break;	
		}
		
	case 3:
		{
			system("cls");
    		cout << "\n\t\t\t Enter key of the Dish to be replaced:\n\t\t\t ";
		    cin >>k;
			UpdateOrder(k);
			break;
		}
		
	case 4:
		{
			PaymentType();
			break;
		}
		
	case 0:
		
		{
			exit (0);
		}
		
	default:
		{
    cout<<"Wrong choice .Enter again.";
}
}
}
}
void roomservicemain()
		{
				char complain[100];
		       int ch;
				cout<<"\n\n\n\t\t\tSelect:\n\t\t\t1.Order Food\n\t\t\t2.Complain\n\t\t\t3.Exit\n\t\t\t";
				cin>>ch;
			while(ch!=3)
			{
				switch(ch)
				{
					case 1:
						{
							system("cls");
							cin.ignore();
			            CustomerOrder();
			            getch();
			            system("cls");

						break;
					}
					case 2:
						{
	                     cout<<"\t\t\t******** Please enter your complain **********\n\n\t\t";
			             cin.ignore();
			             cin.getline(complain,99);
			             cout<<"\n\n\n\t\t\t-----Thankyou for informing.Your complain has been registered and will be solved soon-----\n";
						 exit(0);
					}
					case 3:
						break;
					
					default:
						{
					
						 cout<<"\n\n\t\t\tWrong choice.....!!!";
                  cout<<"\n\t\t\tPress any key to   continue....!!";
                  getch();
              }
						
				}
			}
		}
};
