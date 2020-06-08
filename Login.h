#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


using namespace std;
void signup();
void login();
void forgot();
void admin_login();
void customer_login();

void Loginmain()
{
	int ch;
	cout<<"\n\t\t\t1.Admin";
	cout<<"\n\t\t\t2.Customer\n\t\t\t";
	cin>>ch;
	
	if(ch==1)
	{
		system("cls");
    system("Color E3");
		admin_login();
	}
	
	else if(ch==2)
	{
		system("cls");
        system("Color E4");
		customer_login();
	}
	
}

void admin_login()
{
	/// username : admin
	//  password : admin123
	int ch;
	int flag=0;
	cout<<"\t\t\t\t*************** ADMIN  *****************\n"<<endl;
	START:
    char radmin[20];
    cout<<"\n\t\t\tEnter username:\n\t\t\t ";
    cin.ignore();
    cin.getline(radmin,19);
    cout<<"\n\t\t\tEnter Password:\n\t\t\t ";
    char apass[20];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            apass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            apass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    
    if((strcmp(apass,"admin123")==0) && (strcmp(radmin,"admin"))==0)
    {
    	flag=1;
	}
	
	if (flag==1)
	{
		cout<<"\n\t\t\tWELCOME"<<endl;
	}
	
	else{
		cout<<"\n\t\t\tIncorrect ID or Password";
		cout<<"\n\t\t\tEnter Again:\n\t\t\t ";
		admin_login();
	}
	
	
	

}

void customer_login()
{
	system("cls");
	int ch;

	cout<<"\t\t\t*************** CUSTOMER LOGIN *****************\n";
	cout<<"\n\n\t\t\t<1> Login\n\t\t\t<2> Sign Up\n\t\t\t<3> Forgot Username/Password\n\t\t\t";
	cin>>ch;
	switch(ch)
	{
	    case 1:
		login();
		break;
		
		case 2:
		signup();
		break;
		
		case 3:
		forgot();
		break;
		
        case 4:
		cout<<"\n\t\t\tThankyou!";
		break;
		
		default:
		cout<<"\n\t\t\tWrong choice selected.Enter again:\n\t\t\t";
	    customer_login();
		
	}
}
void signup()
{
	START:
   char ruser[20];
   cout<<"\n\t\t\tEnter username: ";
   cin.ignore();
   cin.getline(ruser,19);
 
 
    
    cout<<"\n\t\t\tEnter Password  : ";
    char rpass[20];//to store password.
    int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            rpass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            rpass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    
    //here we can even check for minimum digits needed
    if(i<=5)
    {
        cout<<"\n\t\t\tMinimum 6 digits needed.\n\t\t\tEnter Again:\n\t\t\t";
        getch();//It was not pausing :p
        goto START;
    }
    
 ofstream file("login.txt",ios::app);
 file<<ruser<<' '<<rpass<<endl;
 system("cls");
 cout<<"\n\t\t\tCONGRATULATIONS! You have succcessfully registered.\n\t\t\t";
 Loginmain();
}
void login()
{
	START:
	int exist;
	char user[20];
	char pass[20];
	char u[20];
	char p[20];
	
	system("cls");
	cout<<"\n\t\t\tEnter username: ";
	cin.ignore();
	cin.getline(user,19);
	cout<<"\n\t\t\tEnter password: ";
	
	int i = 0;
    char a;//a Temp char
    for(i=0;;)//infinite loop
    {
        a=getch();//stores char typed in a
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;//stores a in pass
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';//null means end of string.
            break;//break the loop
        }
    }
    
	
	
	ifstream fin("login.txt");
	while(fin>>u>>p)
	{
		if((!strcmp(u,user)) && (!strcmp(p,pass)))
		{
			exist=1;
		}
	}
	fin.close();
	if(exist==1)
	{
		cout<<"\n\t\t\tHELLO "<<user<<"! "<<"Welcome to our XYZ Resort.\n"<<endl;
		cin.get();
		cin.get();
	}
	else
	{
		cout<<"\n\t\t\tLogin ERROR.Please try again!"<<endl;
		cin.get();
		cin.get();
		Loginmain();
	}
}
void forgot()
{
	int ch;
	system("cls");
	cout<<"\n\t\t\t<1> Search account by username\n\t\t\t<2> Search account by password\n\t\t\t<3> Go back to Main Menu"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
			int ex=0;
			string searchuser,suser,spass;
			cout<<"\n\t\t\tEnter your username: ";
			cin>>searchuser;
			ifstream fin("login.txt");
			while(fin>>suser>>spass)
			{
				if(suser==searchuser)
				{
					ex=1;
					break;
				}
			}
			fin.close();
			if(ex==1)
			{
				cout<<"\n\t\t\tACCOUNT FOUND!\n";
				cout<<"\n\t\t\tYour Password is: "<<spass<<endl;
				cin.get();
		        cin.get();
		        Loginmain();
			}
			else
			{
				cout<<"\n\t\t\tSORRY! Account was not found."<<endl;
				cin.get();
		        cin.get();
		        Loginmain();
			}
		
			break;
	        }
			case 2:
			{	
			int ex=0;
		    string searchpass,su,sp;
		    cout<<"\n\t\t\tEnter your Password: "<<endl;;
		    cin>>searchpass;
		    ifstream fin("login.txt");
			while(fin>>su>>sp)
			{
				if(sp==searchpass)
				{
					ex=1;
					break;
				}
			}
			fin.close();
			if(ex==1)
			{
				cout<<"\n\t\t\tACCOUNT FOUND!\n";
				cout<<"\n\t\t\tYour Username is: "<<su<<endl;
				cin.get();
		        cin.get();
		        Loginmain();
			}
			else
			{
				cout<<"\n\t\t\tSORRY! Account was not found."<<endl;
				cin.get();
		        cin.get();
		        Loginmain();
			}
		
			break;
		}
				
			case 3:
				Loginmain();
				break;
				
			default:
				cout<<"\n\t\t\tYou have Entered a wrong choice.Please enter again."<<endl;
				cin.get();
				cin.get();
				Loginmain();
	}
}
