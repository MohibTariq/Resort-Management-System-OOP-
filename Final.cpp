#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"Gym.h"
#include"Restaurant.h"
#include"login.h"
using namespace std;

class Resort: public Gym, public RoomManagement, public Restaurant
{
public:



//******************************************** A D M I N   U S E   F U N C T I O N S ********************************************//
void AdminUse()
{
int x,r;
long long c;
system("cls");
    system("Color E2");
cout <<"\t\t\t\t\t\t *** Admin Management Page ***" << endl;
cout << "\n\t\t\tWhich Feature you wish to manage? Please select" << endl;
cout << "\n\t\t\t<1> Restaurant\n\t\t\t<2> Gym\n\t\t\t<3> Room Management\n\t\t\t<4> Customer Data\n\t\t\t<0> Exit\n\t\t\t";
cin >> x;
switch(x)
{
case 1:
{
system("Color E2");
Restaurant::AdminRestaurant();
break;
}

case 2:
{
system("Color E2");  
Gym::Admingym();
break;
}

case 3:
{
Customer::Add();
RoomManagement::AdminRoom();
  break;

}

case 4:
{
    system("Color E2");
Customer::Admin_Customer();
break;
}

case 0:
{
cout << "Thankyou" << endl;
break;
}

default:
{
cout<<"\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();
}
}
}


//******************************************** C U S T O M E R   B A S E D    F U N C T I O N S ********************************************//
void CustomerBookingPage()
{
int x;
do
{
   system("cls");
            system("Color E2");
cout <<"\t\t\t\t\t\t *** Customer Service Page ***" << endl;
cout << "\n\t\t\t<1> New Member\n\t\t\t<2> Already a Member?\n\t\t\t<0>Exit\n\t\t\t";
cin >> x;
switch(x)
{
case 1:
{
NewMember();

break;
}

case 2:
{
DisplayMember();
getch();
 Member();
break;
}
case 0:
	{
		break;
	}
}
}while(x!=0);
}

void NewMember()
{
	Customer::Add();
	Member();

}

void DisplayMember()
{
	long long cn;
	cout<<"\n\t\t\tEnter your CNIC: ";
	cin>>cn;
Customer::search(cn);
cout<<"\n\t\t\tWELCOME! "<<"\n\n";
//room display func
//gym display func
}

void Member()
{
            system("Color E2");
int x;
do
{
cout << "\n\t\t\tWhich Facility do you wish to access? Please Select" << endl;
cout << "\n\t\t\t<1> Restaurant\n\t\t\t<2> Gym\n\t\t\t<0> Exit\n\t\t\t";
cin >> x;
switch(x)
{
case 1:
{
		system("cls");
Restaurant::CustomerOrder();
getch();
		system("cls");
break;
}


case 2:
{
		system("cls");
 Gym::Customergym();
 getch();
 		system("cls");
break;
}

case 0:
{
cout << "\n\t\t\tThankyou" << endl;
break;
}

default:
{
cout<<"\n\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\n\n\t\t\tPress any key to   continue....!!";
getch();
}
}
}while(x!=0);
}
};

int main()
{

Resort r;

// Loginmain();
int x,y;
system("cls");
    system("Color E2");
    
    int ch;
    cout<<"\n\t\t\t********************************************************";
cout<<"\n\t\t\t* R E S O R T   M A N A G E M E N T   P R O J E C T *";
cout<<"\n\t\t\t********************************************************";
	cout<<"\n\t\t\t1.Admin";
	cout<<"\n\t\t\t2.Customer\n\t\t\t";
	cin>>ch;
	
	if(ch==1)
	{
		system("cls");
    system("Color E3");
		admin_login();
	
    do
{
system("cls");
cout<<"\n\t\t\t********************************************************";
cout<<"\n\t\t\t* R E S O R T   M A N A G E M E N T   P R O J E C T *";
cout<<"\n\t\t\t********************************************************";
cout << "\n\n\n\t\t\tPlease Select";
cout << "\n\t\t\t<1> Admin\n\t\t\t<2> Customer Service\n\t\t\t<0> Exit\n\t\t\t";
cin >> x;
switch(x)
{
case 1:
{
	system("cls");
r.AdminUse();
break;
}

case 2:
{
	system("cls");
r.CustomerBookingPage();
break;
}

case 0:
	exit(0);
default:
{
cout<<"\n\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\n\n\t\t\tPress any key to   continue....!!";
getch();
}
}
}while(x!=0);
}
	else if(ch==2)
	{
		system("cls");
        system("Color E4");
		customer_login();
		r.roomservicemain();
	}
	return 0;
}

