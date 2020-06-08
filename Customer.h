#include<iostream>
#include<string.h>
#include <fstream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class Customer
{
protected:
char name [50];
        long long  cnic;
  long long phone_num;
  char address[100];
  char gender;
  int Customer_ID;
  int Subscription_ID;
  char email[100];
 
  public:
  void InputData();
  void showData();
     void DisplayCustomer();
     
        void deleteRecord(long long );
  int search(long long );
  void updateRecord(long long );
  int TotalRecords();
  void Admin_Customer();
  void Custom_Customer();
  void CustomerRoomManagement();
 
  void Add()
  {
 
InputData();
ofstream fout;
fout.open("record.txt",ios::out|ios::app);
fout.write((char*)this, sizeof(*this));
fout.close();

}

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
				
	    		if(!(((n[i]>='a') && (n[i]<='z'))||((n[i]>='A')&&(n[i]<='Z'))))
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
		
char checkGender(char &s)
		{
			try
			{
			if (!((s == 'm') || (s== 'f') || (s=='F') || (s=='M')))
					{
					throw 1;
			      	}	
				}	
			
			catch(int x)
			{
				cout << "Enter correct gender " << endl;
				cout << "Enter Sex: ";
				cin >> gender;
				return checkGender(gender);
			}
		}
		


 

};
 
 
void Customer:: InputData()
  {
  cout << "\t\t\t\t*** E N T E R   D E T A I L S ***\n\n" << endl;
  cout << "\n\t\t\tEnter customer name: ";
  cin.ignore();
  cin.getline(name,49);
  cout << "\n\t\t\tCnic Number: ";
  cin >> cnic;
  cout << "\n\t\t\tPhone number: ";
  cin >> phone_num;
  cout << "\n\t\t\tAddress: ";
  cin.ignore();
  cin.getline(address,99);
  cout << "\n\t\t\tEnter gender M or F: ";
  cin >> gender;
  cout << "\n\t\t\tCustomer ID: ";
  cin >> Customer_ID;
  cout << "\n\t\t\tSubscription ID: ";
  cin >>  Subscription_ID;
  cout << "\n\t\t\tEmail Address: ";
  cin.ignore();
  cin.getline(email,99);
 }
 
//show data
void Customer::showData()
 {
  cout << "\n\t\t\tName: " << name;
  cout << "\n\t\t\tCnic Number: " << cnic;
  cout << "\n\t\t\tPhone number: " << phone_num;
  cout << "\n\t\t\tAddress: " << address;
  cout << "\n\t\t\tGender: " << gender;
  cout << "\n\t\t\tCustomer ID: " << Customer_ID;
  cout << "\n\t\t\tSubscription ID: " << Subscription_ID;
  cout << "\n\t\t\tEmail Address: " << email;
 }
 
//display data from file
void Customer::DisplayCustomer()
 {
  ifstream fin;
    fin.open("record.txt", ios::in);
    if(!fin)
    {
    cout << "\n\t\t\tFile not found" << endl;
}
else
{
fin.read((char*)this,sizeof(*this));
while(!fin.eof())
{
showData();
cout<<endl;
fin.read((char*)this,sizeof(*this));
}
}
fin.close();
 }

//add customer
//void Customer::Add()
// {
// InputData();
// ofstream fout;
// fout.open("record.txt",ios::out|ios::app);
// fout.write((char*)this, sizeof(*this));
// fout.close();
// }

//delete data
void Customer::deleteRecord(long long i)
{
ifstream fin;
ofstream fout;
fin.open("record.txt",ios::in|ios::binary);
if(!fin)
{
cout<<"\n\t\t\tFile Not Found !"<<endl;
}
else
{

fout.open("temp.txt",ios::out);
fin.read((char*)this,sizeof(*this));
while(!fin.eof())
{
if(i!=cnic)
{
fout.write((char*)this,sizeof(*this));
}
fin.read((char*)this,sizeof(*this));
}
fin.close();
fout.close();
getch();
remove("record.txt");
getch();
rename("temp.txt","record.txt");
}
}

//searchCustomer
int Customer::search(long long i)
{
bool flag = true;
int count=0;
ifstream fin;
fin.open("record.txt", ios::in);
if(!fin)
    {
    cout << "\n\t\t\tFile not found" << endl;
}
else
{
fin.read((char*)this,sizeof(*this));
while(!fin.eof())
{
if(i==cnic)
{
showData();
count++;
}
fin.read((char*)this,sizeof(*this));
}
}
if(flag == false)
{
cout << "\n\t\t\tNo such record" << endl;
}
fin.close();

}

//updateData
void Customer::updateRecord(long long i)
{
fstream file;
file.open("record.txt", ios::in|ios :: out| ios::ate);
file.seekg(0);
file.read((char*)this,sizeof(*this));
while(!file.eof())
{
if(i==cnic)
{  
   InputData();
file.seekp(file.tellp()-sizeof(*this));
file.write((char*)this,sizeof(*this));
}
file.read((char*)this,sizeof(*this));
}
}

int Customer::TotalRecords()
{
int i=0;
    ifstream fin;
    fin.open("record.txt", ios::in);
    if(!fin)
    {
    cout << "\n\t\t\tFile not found" << endl;
}
else
{
fin.read((char*)this,sizeof(*this));
while(!fin.eof())
{
i++;
fin.read((char*)this,sizeof(*this));
}

}

cout << "\n\t\t\tTotal records: " << i << endl;
fin.close();
return i;
}

void Customer::Admin_Customer()
{
int x;
long long nic;
do{

  system("cls");
cout << "\t\t\t\t*********S E L E C T*********" << endl;
cout << "\n\t\t\t<1> Delete a Customer Record\n\t\t\t<2> Edit a Customer Record\n\t\t\t<3> View all Customers\n\t\t\t<4> Total Numbers of Customers\n\t\t\t<0> Exit\n\t\t\t";
cin >> x;
switch(x)
{
case 1:
{
	system("cls");
cout << "\n\t\t\tEnter the cnic of the customer to be deleted:\n\t\t\t ";
cin >> nic;
cout << endl;
deleteRecord(nic);
getch();
system("cls");
break;
}

case 2:
{
	system("cls");
cout << "\n\t\t\tEnter the cnic of the customer to be updated:\n\t\t\t ";
cin >> nic;
cout << endl;
updateRecord(nic);
getch();
system("cls");
break;
}

case 3:
{
	system("cls");
cout << "|||||||||||| C U S T O M E R    L I S T ||||||||||||" << endl;
DisplayCustomer();
getch();
system("cls");
break;
}

case 4:
{
	system("cls");
TotalRecords();
getch();
system("cls");
break;
}

case 0:
{

break;
}

default:
{
cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();
}
}

}while(x!=0);
}

void Customer::Custom_Customer()
{
int x;
long long nic;
do
{
system("cls");
cout << "\t\t\t\t*********S E L E C T*********" << endl;
cout << "\n\t\t\t<1> Add a Customer Record\n\t\t\t<2> View all Customers\n\t\t\t<3> Search a specific customer\n\t\t\t<0> Exit\n\t\t\t";
cin >> x;
switch(x)
{
case 1:
{
	system("cls");
cout << "\n\t\t\tE N T E R   Y O U R   D E T A I L S\n\t\t\t";
Add();
getch();
system("cls");

break;
}

case 2:
{
	system("cls");
cout << "\t\t\t\t|||||||||||| C U S T O M E R    L I S T ||||||||||||" << endl;
DisplayCustomer();
getch();
system("cls");

break;
}

case 3:
{
	system("cls");
cout << "\n\t\t\tEnter the cnic of the customer you wish to search:\n\t\t\t ";
cin >> nic;
cout << endl;
search(nic);
getch();
system("cls");

break;
}

case 0:
	{
		break;
	}
}

}while(x!=0);
}
