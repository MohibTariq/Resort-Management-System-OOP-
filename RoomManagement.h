#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include"Date.h"

using namespace std;
class RoomManagement:public Date
{
	private:
	int room_no;
	
	public:
			
int checkRoom(int r)
	{
		int flag=0;
		ifstream fin("Record.txt",ios::in);
		while(!fin.eof())
		{
			fin.read((char*)this,sizeof(*this));
			if(room_no==r)
			{
				flag=1;
				break;
			}
		}
		fin.close();
		return(flag);
	}
	
void BookRoom()
	{
		int r,flag;
		RoomManagement r1;
		int n;
		ofstream fout("room.txt",ios::app);
		cout<<"\n------ROOMS DETALS------\n";
		cout<<"Total no.of rooms in this hotel are: 50\n";
		cout<<"(1).Simple rooms(with 1 bed): 1-15\n(2).Simple rooms(with 2 beds): 16-30\n(3).Luxury rooms:31-45\n(4).Royal suites: 46-50 \n";
		cout<<"Enter the number of room you would like to stay in: ";
		cin>>r;
		if(r>=1&&r<=50)
		{
		
		flag=checkRoom(r);
		if(flag)
		{
			cout<<"\nSORRY! The room is already booked.";
		}
		else
		{
			
			
			r1.date_main();
            room_no=r;
			cout<<"/n...Room is booked...\n";
			fout.write((char*)this,sizeof(*this));
			fout.close();
		}
	}
	else
	{
		cout<<"No such room exists\n";
	}
		cout<<"\n Press any key to continue.....!!";
	    getch();
	}
	
void rooms()
	{
		ifstream fin("room.txt",ios::in);
		cout<<"\n\t\t\t    List Of Rooms Allotted";
		cout<<"\n\t\t\t    ----------------------";
		cout<<"\n\n Room No.";
		if(!fin)
	{
		cout<<"File Not Found !"<<endl;
	}
	
	else{
		fin.read((char*)this,sizeof(*this));
		
		while(!fin.eof())
		{
			
            cout<<"\n\n "<<room_no;
            fin.read((char*)this,sizeof(*this));
		}
	fin.close();
	}
		cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
		getch();
	
	}
	

	void delete_room(int i)
	{
		//Deleting A record
	ifstream fin;
	ofstream fout;
	fin.open("room.txt",ios::in);
	if(!fin)
	{
		cout<<"\n\t\t\tFile Not Found !"<<endl;
	}
	else{
		fout.open("temproom.txt",ios::out);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(!(i==room_no))
			{
				fout.write((char*)this,sizeof(*this));
			}
			fin.read((char*)this,sizeof(*this));
			
		}
		fin.close();
		fout.close();
		remove("room.txt");
		rename("temproom.txt","room.txt");
		
	}
	}

	
void RoomCharges(int r)
		{
			
			ifstream f1;
			f1.open("room.txt",ios::in|ios::binary);
			if(!f1)
			cout<<"cannot open";
			else
			{
				 f1.read((char*)this,sizeof (*this));
				  while(f1)
				  {
				  	f1.read((char*)this,sizeof (*this));
				  }
			if (room_no == r)
			  {
				  if(room_no>=1&&room_no<=15)
				  cout<<"Room Charges = 2000";
				
				  else if (room_no>=16&&room_no<=30)
				  cout<<"Room Charges = 4000" ;
				
				  else if (room_no>=31&&room_no<=45)
				  cout<<"Room Charges = 7000" ;
				  
				  else
				  cout<<"Room Charges = 10000";
			  }
			  else
			  { 
			  cout<<"room no. not found";
			  }
			
			}
			
	f1.close();
	getch();

		}
		
		
void AdminRoom()
		{
			
	
	int x,r;
	do{
	system("cls");
	cout<<"\t\t\t\t************ ADMIN *************"<<endl;	
	cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\n\n\t\t\t2.Rooms Allotted";
cout<<"\n\n\n\t\t\t3.Delete Room ";
		cout<<"\n\n\n\t\t\t4.Calculate Bill"<<endl;
	cout<<"\n\n\n\t\t\t0.Exit"<<endl;
	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>x;
	
	switch(x)
	{
		case 1:
			{
					system("cls");
                BookRoom();
                getch();
                	system("cls");
				break;
			}
			
		case 2:
			{
					system("cls");
				rooms();
				getch();
					system("cls");
				break;
			}
			
		case 3:
			{
					system("cls");
				int r;
				cout<<"Enter the room number you want to delete: ";
				cin>>r;
				delete_room(r);
				getch();
					system("cls");
				break;
			}
	    case 4:
	    		system("cls");
	    	cout<<"\n Enter the Room no: " ;
            cin>>r; 
            if(r>=1 && r<=50)
            {
            int ch, num, pin;
        	cout << "1. Cash\n2. Credit Card" << endl;
	        cin >> ch;
        	switch(ch)
	        {
	    	case 1:
			{
 			 RoomCharges(r);
			 break;
			}
		
	    	case 2:
		  	{
				cout << "Credit Card Number: ";
				cin >>num;
				cout << endl;
				cout << "Enter Pin: ";
				cin >> pin;
				cout << endl;
                RoomCharges(r);
 			    break;				
			}
	}
}
else
{
	cout<<"SORRY! No such room exists";
}
break;
	}
	
	
	}while(x!=0);
	}
	
		
		


};

