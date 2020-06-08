#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include"Restaurant.h"
using namespace std;
class RoomService:public Restaurant
{
	char complain[100];
	public:
		void orderFood()
		{
			 CustomerOrder();
		}
	
		void help()
		{
			cout<<"\n***Please enter your complain***\n\n";
			cin.ignore();
			cin.getline(complain,99);
			cout<<"\n-----Thankyou for informing.Your complain has been registered and will be solved soon-----\n";
		}
		
		void finalservicemain()
		{
		       int ch;
				cout<<"Select:\n1.Order Food\n2.Complain\n3.Exit\n";
				cin>>ch;
			while(ch!=3)
			{
				switch(ch)
				{
					case 1:
						orderFood();
						break;
					case 2:
						help();
						break;
						
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

