#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include"Customer.h"
#include"RoomManagement.h"


using namespace std;

class Gym:public Customer
{
	int customer_id;
	int trainerId;
	char trainer_name[20];
	char hallname[20];
	int equipment_id;
	char equipment_name[20];
	int exercise_plan_id;
	int duration;
	int subs_id;
	string payment_date;
	char payment_status;
	char equipment_status;
	string payment_time;
	
	
	public:
		
	void show_trainer()
	{
		cout<<"\n\t\t\t"<<trainerId<<" "<<trainer_name<<endl;
	}
	
	/////////// TRAINER //////////////////////////
	void get_trainer_data()
	{
		cout<<"\n\t\t\tEnter Trainer's ID :\n\t\t\t";
		cin>>trainerId;
		
		cout<<"\n\t\t\tEnter Trainers Name :\n\t\t\t";
		cin.ignore();
		cin.getline(trainer_name,19);
		
	}
	
		
	void add_trainer_data()
	{
	// Adding a record to a file
	get_trainer_data();// Taking Data As Input
	ofstream fout;
	fout.open("Trainers.txt",ios::app);
	fout.write((char*)this,sizeof(*this));// Writing Objects to file
	fout.close();
	}
	
	void delete_trainer(int t)
	{
	ifstream fin;
	ofstream fout;
	fin.open("Trainers.txt",ios::in);
	if(!fin)
	{
		cout<<"\n\t\t\tFile Not Found !"<<endl;
	}
	else{
		fout.open("tempTrainers.txt",ios::out);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(!(t==trainerId))
			{
				fout.write((char*)this,sizeof(*this));
			}
			fin.read((char*)this,sizeof(*this));
			
		}
		fin.close();
		fout.close();
		remove("Trainers.txt");
		rename("tempTrainers.txt","Trainers.txt");
		
	}
	}
	
	void update_trainer(int tid)
	{
	fstream file;
	file.open("Trainers.txt",ios::in|ios::out|ios::ate);
	file.seekg(0);
	file.read((char*)this,sizeof(*this));
	while(!file.eof())
	{
		if(tid==trainerId)
		{
			get_trainer_data();
			file.seekp(file.tellp()-sizeof(*this));
			file.write((char*)this,sizeof(*this));
			
		}
		
		
		file.read((char*)this,sizeof(*this));
		
	}
	}
	
	void view_trainers()
	{
	ifstream fin;
	fin.open("Trainers.txt",ios::in);
	if(!fin)
	{
		cout<<"\n\t\t\tFile Not Found !"<<endl;
	}
	
	else{
		fin.read((char*)this,sizeof(*this));// Reading Objects from file
		while(!fin.eof())
		{
			show_trainer();
			fin.read((char*)this,sizeof(*this));
		}
	fin.close();
	}
	}
	
	void choose_trainer()
	{
		int tid;
		cout<<"\n\t\t\tEnter ID of the trainer you want to choose :\n\t\t\t";
		cin>>tid;
		
		cout<<"\n\t\t\tYou have chosen the following Trainer :";
		search_trainer(tid);
		
		delete_trainer(tid);
		
		cout<<"\n\t\t\tTrainers Have Been Updated"<<endl;
		
		
	}
	
	void search_trainer(int id)
	{
	int count=0;
	ifstream fin;
	fin.open("Trainers.txt",ios::in);
	if(!fin)
	{
		cout<<"\n\t\t\tFile Not Found"<<endl;
	}
	else{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(id==trainerId)
			{
				show_trainer();
				count++;
			}
			fin.read((char*)this,sizeof(*this));
		}
		
	    if(count==0)
	    {
	    	cout<<"\n\t\t\tNo Record Found"<<endl;
		}
		fin.close();
	}
	}
	
	
	
	
	///////////////// EQUIPMENT  //////////////////////////
	
	void show_equipments()
	{
		cout<<"\n\t\t\t"<<equipment_id<<" "<<equipment_name<<endl;
	}
	
	void get_equipment_data()
	{
		cout<<"\n\t\t\tEnter Equipment ID :\n\t\t\t"<<endl;
		cin>>equipment_id;
		
		cout<<"\n\t\t\tEnter Equipment Name :\n\t\t\t"<<endl;
		cin.ignore();
		cin.getline(equipment_name,19);
	}
	
	void add_equipment_data()
	{
	// Adding a record to a file
	get_equipment_data();// Taking Data As Input
	ofstream fout;
	fout.open("Equipments.txt",ios::app);
	fout.write((char*)this,sizeof(*this));// Writing Objects to file
	fout.close();
	}
	
	void display_equipments()
	{
	ifstream fin;
	fin.open("Equipments.txt");
	if(!fin)
	{
		cout<<"\n\t\t\tFile Not Found !"<<endl;
	}
	
	else{
		fin.read((char*)this,sizeof(*this));// Reading Objects from file
		while(!fin.eof())
		{
			show_equipments();
			fin.read((char*)this,sizeof(*this));
		}
	fin.close();
	getch();
	}
	}
	
	void enter_working_status()
	{
		
			cout<<"\n\t\t\tEnter Equipment ID:\n\t\t\t";
			cin>>equipment_id;
			
			cout<<"\n\t\t\tEnter  Status (W-Working O-Out Of Order):\n\t\t\t ";
			cin>>equipment_status;
			
			ofstream fout;
	        fout.open("EquipmentStatus.txt",ios::app);
	        fout.write((char*)this,sizeof(*this));// Writing Objects to file
	        fout.close();
		
	}
	
	void view_e_status()
	{
		cout<<"\n\t\t\t"<<equipment_id<<" "<<equipment_status<<endl;
	}
	
	void view_equipment_status()
	{
	ifstream fin;
	fin.open("EquipmentStatus.txt",ios::in);
	if(!fin)
	{
		cout<<"\n\t\t\tFile Not Found !"<<endl;
	}
	
	else{
		fin.read((char*)this,sizeof(*this));// Reading Objects from file
		while(!fin.eof())
		{
			view_e_status();
			fin.read((char*)this,sizeof(*this));
		}
	fin.close();
	}
	}
	
	
	
	////////////// EXERCISE PLANS /////////////////////////////////
	void get_plan_data()
	{
		cout<<"\n\t\t\tEnter Exercise Plan ID :\n\t\t\t";
		cin>>exercise_plan_id;
		
		cout<<"\n\t\t\tEnter Trainer ID:\n\t\t\t ";
		cin>>trainerId;
		
		cout<<"\n\t\t\tEnter Equipment ID :\n\t\t\t";
		cin>>equipment_id;
		
		cout<<"\n\t\t\tEnter Duration of exercise :\n\t\t\t";
		cin>>duration;
	}
	
	void add_exercise_plan()
	{
	// Adding a record to a file
	get_plan_data();// Taking Data As Input
	ofstream fout;
	fout.open("Plans.txt",ios::app);
	fout.write((char*)this,sizeof(*this));// Writing Objects to file
	fout.close();
	}
	
	
	
	void delete_plan(int i)
	{
		//Deleting A record
	ifstream fin;
	ofstream fout;
	fin.open("Plans.txt",ios::in);
	if(!fin)
	{
		cout<<"\n\t\t\tFile Not Found !"<<endl;
	}
	else{
		fout.open("tempPlans.txt",ios::out);
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(!(i==exercise_plan_id))
			{
				fout.write((char*)this,sizeof(*this));
			}
			fin.read((char*)this,sizeof(*this));
			
		}
		fin.close();
		fout.close();
		remove("Plans.txt");
		rename("tempPlans.txt","Plans.txt");
		
	}
	}
	
	void choose_plan()
	{
	
		int choice;
		int nid;
		char estatus;
		cout<<"Enter Exercise Plan ID you want to choose "<<endl;
		cin>>nid;
		
	int count=0;
	ifstream fin;
	fin.open("Plans.txt",ios::in);
	if(!fin)
	{
		cout<<"File Not Found"<<endl;
	}
	else{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(nid==exercise_plan_id)
			{
				showPlanData();
				count++;
			}
			fin.read((char*)this,sizeof(*this));
		}
		
	    if(count==0)
	    {
	    	cout<<"No Record Found"<<endl;
		}
		fin.close();
	}
		
		if(count>0)
		{
		
		ifstream fin;
		fin.open("EquipmentStatus.txt",ios::in);
		estatus=equipment_status;
		
		if (estatus=='O')
		{
			cout<<"Sorry The Chosen Machine is out of order !"<<endl;
		}
	}
		delete_plan(nid);
		
		cout<<"Plans Have been updated"<<endl;
		
}

void showPlanData()
	{
		cout<<"\n"<<exercise_plan_id<<" "<<trainerId<<" "<<equipment_id<<" "<<duration<<endl;
	}
	
	void exercise_plan()
	{
	cout<<"\n\t\t\tThese Are The Available Exercise Plans :";
	
	cout<<"\n\t\t\tPlan ID ***** Trainer ID ***** Equipment ID **** Duration Of Exercise\n\t\t\t";
		
	ifstream fin;
	fin.open("Plans.txt",ios::in);
	if(!fin)
	{
		cout<<"\n\t\t\tFile Not Found !"<<endl;
		
	}
	
	else{
		fin.read((char*)this,sizeof(*this));// Reading Objects from file
		while(!fin.eof())
		{
			showPlanData();
			fin.read((char*)this,sizeof(*this));
		}
	fin.close();
	}
	}
	
	
	///////////////// MEMBER SUBSCRIPTIONS //////////////////////////////////

    void get_subscription_details()
    {
    	
    	cout<<"\n\t\t\tEnter Subscription ID :\n\t\t\t";
    	cin>>subs_id;
    	
    	
    	
    	cout<<"\n\t\t\tEnter Status of Payment (Paid-P Unpaid-N)\n\t\t\t";
    	cin>>payment_status;
    	
    }
    
    void store_subscriptions()
    {
    get_subscription_details();
    ofstream fout;
	fout.open("Subscriptions.txt",ios::app);
	fout.write((char*)this,sizeof(*this));// Writing Objects to file
	fout.close();
	}

    void check_subscription()
    {
    	int sid;
    	char status;
    	
    	cout<<"\n\t\t\tEnter The Subscription id to check :\n\t\t\t";
    	cin>>sid;
    	
    	ifstream fin;
    	fin.open("Subscriptions.txt",ios::in);
    	
    	if(sid==subs_id)
    	{
    		status=payment_status;
    		if(status=='P')
    		{
    			cout<<"\n\t\t\tAllow Member to enter - Payment Already Done\n\t\t\t";
			}
			
			else if(status=='N')
			{
				cout<<"\n\t\t\tDonot Allow Member - Payment Not Done\n\t\t\t";
			}
		}
		
		else{
			cout<<"\n\t\t\tNo Matching Customer Found\n\t\t\t";
		}
    	
    	
	}
	
	
	
	void Admingym()
	{
	
	int x;
	long long n;
	int tid;
	
	do{
	system("cls");
	cout<<"\t\t\t\t************ A D M I N *************\n\n\n"<<endl;	
	cout<<"\n\t\t\t1.Add a trainer";
	cout<<"\n\t\t\t2.Delete a trainer";
	cout<<"\n\t\t\t3.Update A Trainer";
	cout<<"\n\t\t\t4.Display All trainers records";
	cout<<"\n\t\t\t5.Add Equipment ";
	cout<<"\n\t\t\t6.Display All Equipments";
	cout<<"\n\t\t\t7.View Working Status of each equipment";
	cout<<"\n\t\t\t8.Update Working Status of Equipment";
	cout<<"\n\t\t\t9.Add Exercise Plan ";
	cout<<"\n\t\t\t10.Search a Member ";
	cout<<"\n\t\t\t11.Delete a Member";
	cout<<"\n\t\t\t12.View All Members :";
	cout<<"\n\t\t\t13.Check Subscription Details Of a Member";
	cout<<"\n\t\t\t14.Enter Status :";
	cout<<"\n\t\t\t15.Exit\n\t\t\t";
	cin>>x;
	
	switch(x)
	{
		case 1:
			{
				system("cls");
				add_trainer_data();
				getch();
		      system("cls");
				break;
			}
			
		case 2:
			{
				system("cls");
				cout<<"\n\t\t\tEnter ID of the Trainer you want to delete:\n\t\t\t ";
				cin>>tid;
				delete_trainer(tid);
				getch();
		      system("cls");
				break;
			}
			
		case 3:
			{
				system("cls");
				cout<<"\n\t\t\tEnter ID of the Trainer you want to update:\n\t\t\t ";
				cin>>tid;
				update_trainer(tid);
				getch();
		      system("cls");
				break;
			}
			
		case 4:
			{
				system("cls");
				cout<<"\n\t\t\tTrainer ID ******** Trainer Name\n\t\t\t"<<endl;
				view_trainers();
				getch();
				system("cls");
				break;
			}
			
		case 5:
			{
				system("cls");
				add_equipment_data();
				getch();
		      system("cls");
				break;
			}
		
		case 6:
			{
				system("cls");
				display_equipments();
				getch();
		      system("cls");
				break;
			}
		 case 7:
		 	{
		 		system("cls");
		 		view_equipment_status();
		 		getch();
		      system("cls");
		 		break;
			}
			
		case 8:
			{
				system("cls");
				enter_working_status();
				getch();
		      system("cls");
				break;
			}
		case 9:
			{
				system("cls");
				add_exercise_plan();
				getch();
		      system("cls");
				break;
			}
			
		case 10:
			{
			system("cls");
		      cout<<"\n\t\t\tEnter CNIC of the customer you want to search :\n\t\t\t";
	          cin>>n;
		      Customer::search(n);
		      getch();
		      system("cls");
		      break;
			}
			
		case 11:
			{
		      system("cls");
			  long long n;
		      cout<<"\n\t\t\tEnter CNIC of the customer you want to delete :\n\t\t\t";
		      cin>>n;
		      Customer::deleteRecord(n);
		      break;
			}
			
		case 12:
			{
				system("cls");
				Customer::DisplayCustomer();
				getch();
				system("cls");

				break;
			}
			
		case 13:
			{
				system("cls");
				check_subscription();
				getch();
				system("cls");
				break;
			}
			
		case 14:
			{
				store_subscriptions();
				break;
			}
	}
	
	
	}while(x!=15);
	}
	
	void Customergym()
	{
	
	int x;
	do{
	cout<<"\n\t\t\t1.Choose An Exercise Plan"<<endl;
	cout<<"\n\t\t\t2.Select A Personal Trainer "<<endl;
	cout<<"\n\t\t\t3.View Available Trainers "<<endl;
	cout<<"\n\t\t\t4.Exit\n\t\t\t";
	cin>>x;
	
	switch(x)
	{
		case 1:
			{
				system("cls");
				exercise_plan();
				choose_plan();
				break;
			}
			
		case 2:
			{
				system("cls");
				view_trainers();
				choose_trainer();
				break;
			}
			
		case 3:
			{
				system("cls");
				view_trainers();
				getch();
				system("cls");
				break;
			}
	}
}while(x!=4);
}	
};
