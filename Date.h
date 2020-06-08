#include<iostream>
using namespace std;
class Date
{
      int day;
      int month;
      int year;
      public:
      	    Date()
      	    {
			  }
             Date(int d,int m,int y)
             {
                   day=d;
                   month=m;
                   year=y;
             }
             
             

             
             friend Date operator +(Date &,int);
             void display()
             {
                  cout<<"Date:"<<day<<"-"<<month<<"-"<<year<<endl;
             }
             
void date_main()
{
	int n;
	
    int dd,mm,yy;
    cout<<"Enter Todays Date :"<<endl;
    cout<<"Enter  Day:";
    cin>>dd;
	 cout<<"Enter Month:";
    cin>>mm;
    cout<<"Enter Year:";
    cin>>yy;
    if(mm==2 && dd>29 )
    {
    	cout<<"Incorrect Number of Days"<<endl;
    	date_main();
	}
		if(dd>31)
		{
			cout<<"Incorrect Number of Days"<<endl;
			date_main();
		}
	
	if(mm>12)
	{
		cout<<"Incorrect Number"<<endl;
		date_main();
	}
	
	
	
	
    
    cout<<"Enter Number of Nights to Stay "<<endl;
    cin>>n;
    
    
    Date d1(dd,mm,yy);
    Date d2=d1+n;
    cout<<"Checkout Date : ";
    d2.display();

}
             
             
};


Date operator+(Date &x,int y)
{
	 
     return Date(x.day+y, x.month, x.year);
}
 
