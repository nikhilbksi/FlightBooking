#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
//--------------sources and destinations-----------
char s1[]="DELHI", s2[]="MUMBAI",s3[]="KOLKATA",s4[]="CHENNAI",s5[]="CHANDIGARH";
char d11[]="DELHI", d22[]="MUMBAI",d33[]="KOLKATA",d44[]="CHENNAI",d55[]="CHANDIGARH",d66[]="PATNA",d77[]="AHEMDABAD",d88[]="BANGALORE",
d99[]="JAIPUR",d111[]="HYDERABAD",d112[]="NEW YORK",d113[]="LONDON",d114[]="ROME",d115[]="DUBAI";
//--------------------------------------------------     
struct date
{
	int date,month,year;
};
struct time
{
	int hours;
	int minutes;
};
class flight
{
	protected:
	long flightno;
	char airline[30];
	char source[30];
	char destination[30];
	char type[15];		            // international and domestic
	time t;
	time du;
	date dod;
	int eco,business,first;	           	 // no. of each seats
	char mealv[20],mealn[20];		 //veg, non-veg
	long int cost_flight;		 	// destination and airline dependent
	long int cost_eco,cost_bus,cost_fir;	// for eco,business,first
	long int cost_v,cost_n;		// for veg and non-veg
	long total;
	int aa,bb,cc;

	public:
	flight()
	{
		strcpy(mealv,"VEGETARIAN");
		strcpy(mealn,"NON-VEGETARIAN");
	}
	//admin-----------------------------------------------
	void in();
	void modify();
	long getflightno()
	{
		return flightno;
	}
	void out();
	//customer-reserve --------------------------------
	void display();
	void display2();
	long select_seat(int x,int y);
	long select_meal(int t)
	{
		if(t==1)
			return cost_v;
		else 
			return cost_n;
	}
	char getsource()
	{
		return source;
	};
	char getdestination()
	{
		return destination;
	}
	void passenger_final(long tot,int a,int b,int c);
	void passenger_final();
};
//-----admin----------------------------------------
void flight::in()
{
	cout<<"Enter Flight no.: ";		cin>>flightno;
	cout<<"Enter airline: ";   		gets(airline);
	cout<<"Enter source: ";		gets(source);
	cout<<"Enter destination: ";	gets(destination);
	cout<<"Enter flight type(international/domestic): ";	gets(type);
	cout<<"Enter time of departure:\n"; //enter in 24 hour format
	cout<<"Hour of day: ";		cin>>t.hours;
	cout<<"Minutes: ";		cin>>t.minutes;
	cout<<"Enter date of departure: \n";
	cout<<"Date: ";			cin>>dod.date;
	cout<<"Month: ";		cin>>dod.month;
	cout<<"Year: ";			cin>>dod.year;
	cout<<"Duration:\n";
	cout<<"Hours: ";		cin>>du.hours;
	cout<<"Enter no. of seats:\n";
	cout<<"Economy: ";		cin>>eco;
	cout<<"Business: ";		cin>>business;
	cout<<"First class: ";		cin>>first;
	cout<<"Enter cost:\n";
	cout<<"Flight: ";		cin>>cost_flight;
	cout<<"Seat:- ";
	cout<<"Economy:";		cin>>cost_eco;
	cout<<"Business: ";		cin>>cost_bus;
	cout<<"First: ";		cin>>cost_fir;
	cout<<"Meal:\n";
	cout<<mealv<<" ";			cin>>cost_v;
	cout<<mealn<<" ";		cin>>cost_n;
}
void flight::out()
{
	cout<<"Flight no.: "<<flightno<<endl;
	cout<<"Airline: "<<airline<<endl;
	cout<<"Source: "<<source<<"\tDestination: "<<destination<<endl;
	cout<<"Flight Type: "<<type<<endl;
	cout<<"Date of departure:\n";
	cout<<"Date: "<<dod.date<<"\tMonth: "<<dod.month<<"\tYear: "<<dod.year<<endl;
	cout<<"Time of departure: "<<t.hours<<":"<<t.minutes<<endl;
	cout<<"Duration: "<<du.hours<<endl;
	cout<<"No. of seats: \n";
	cout<<"Economy: "<<eco<<"\tBusiness: "<<business<<"\tFirst: "<<first<<endl;
	cout<<"Cost of seats:\n";
	cout<<"Economy: "<<cost_eco<<"\tBusiness: "<<cost_bus<<"\tFirst: "<<cost_fir<<endl;
	cout<<"Meal cost:\n";
	cout<<mealv<<": "<<cost_v<<"\t"<<mealn<<": "<<cost_n<<endl;
}
void flight::modify()
{
	char ch;
	cout<<"Choose a feild to be Modified:\n";
	cout<<"1. Airline name\n 2. Source\n 3. Destination\n";
	cout<<"4. Date of Departure\n 5. Time of Departure\n";
	cout<<"6. Duration\n 7. No. of seats\n 8.Cost of seats\n";
	cout<<"9. Cost of meals\n";
	cout<<"Enter choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:	cout<<"Enter airline: ";	gets(airline);
			break;
		case 2:	cout<<"Enter source: ";		gets(source);
			break;
		case 3:	cout<<"Enter destination: ";	gets(destination);
			break;
		case 4:	cout<<"Enter Date:\n ";
			cout<<"Date: ";		cin>>dod.date;
			cout<<"Month: ";	cin>>dod.month;
			cout<<"Year: ";		cin>>dod>year;
			break;
		case 5:	cout<<"Enter time of departure:\n";
			cout<<"Hour: ";		cin>>t.hours;
			cout<<"Minutes; ";	cin>>t.minutes;
			break;
		case 6:	cout<<"Enter duration; ";	cin>>du.hours;
			break;
		case 7:	cout<<"Enter no. of seats:\n ";
			cout<<"Economy: ";	cin>>eco;
			cout<<"Business: ";	cin>>business;
			cout<<"First: ";	cin>>first;
			break;
		case 8:	cout<<"Enter cost of seats:\n";
			cout<<"Economy: ";	cin>>cost_eco;
			cout<<"Business: ";	cin>>cost_bus;
			cout<<"First: ";	cin>>cost_fir;
			break;
		case 9:	cout<<"Enter cost of meals:\n";
			cout<<"Vegetarian: ";	cin>>cost_v;
			cout<<"Non-Vegetarian: ";	cin>>cost_n;
			break;
		default: cout<<"Wrong choice!!!!";
	}
}
//------passenger------------------------------------
void flight::display()
{
	cout<<flightno<<"  "<<airline<<"\t"<<source<<"\t\t"<<destination<<"\t"<<dod.date<<"/"<<dod.month<<"/"<<dod.year<<"\t"<<t.hours<<":"<<t.minutes<<"  "<<cost_flight+cost_eco<<endl;
}
void flight::display2()
{
	cout<<"Flight no.: "<<flightno<<endl;
	cout<<"Airline: "<<airline<<endl;
	cout<<"Source: "<<source<<"\tDestination: "<<destination<<endl;
	cout<<"Flight Type: "<<type<<endl;
	cout<<"Date of departure: "<<dod.date<<"/"<<dod.month<<"/"<<dod.year<<endl;
	cout<<"Time of departure: "<<t.hours<<":"<<t.minutes<<endl;
	cout<<"Duration: "<<du.hours<<endl;
	cout<<"No. of seats: \n";
	cout<<"Economy: "<<eco<<"\tBusiness: "<<business<<"\tFirst: "<<first<<endl;
	cout<<"Cost of flight: "<<cost_flight<<endl;
	cout<<"Cost of seats:\n";
	cout<<"Economy: "<<cost_eco<<"\tBusiness: "<<cost_bus<<"\tFirst: "<<cost_fir<<endl;
	cout<<"Meal cost:\n";
	cout<<"Vegetarian: "<<cost_v<<"\tNon-Vegetarian: "<<cost_n<<endl;
}
long flight::select_seat(int x,int y)	
{
	long c,f;
	if(x==1)
	{
		for(i=1;i<=y;i++)
			eco--;
		c=y*cost_eco;
		f=cost_flight+c;
		return f;
	}
	else if(x==2)
	{
		for(i=1;i<=y;i++)
			business--;
		c=y*cost_bus;
		f=cost_flight+c;
		return f;
	}
	else if(x==3)
	{
		for(i=1;i<=y;i++)
			first--;
		c=y*cost_fir;
		f=cost_flight+c;
		return f;
	
	}
}
void flight::passenger_final(long tot,int a,int b,int c)
{
	total=tot;
	aa=a;
	bb=b;
	cc=c;
	cout<<"Flight no.: "<<flightno<<endl;
	cout<<"Airline: "<<airline<<endl;
	cout<<"Source: "<<source<<"\tDestination: "<<destination<<endl;
	cout<<"Flight Type: "<<type<<endl;
	cout<<"Date of departure: "<<dod.date<<"/"<<dod.month<<"/"<<dod.year<<endl;
	cout<<"Time of departure: "<<t.hours<<":"<<t.minutes<<endl;
	cout<<"Duration: "<<du.hours<<endl;
	cout<<"Seat type: ";
	if(aa==1)
		cout<<"ECONOMY\n";
	else if(aa==2)
		cout<<"BUSINESS\n";
	else if(aa==3)
		cout<<"FIRST\n";
	cout<<"NO. OF SEATS BOOKED: "<<bb<<endl;
	cout<<"MEAL TYPE: ";
	if(cc==1)
		cout<<mealv<<endl;
	else if(cc==2)
		cout<<mealn<<endl;
	cout<<"TOTAL COST OF FLIGHT: "<<total<<endl;
}
void flight::passenger_final()
{
	cout<<"Flight no.: "<<flightno<<endl;
	cout<<"Airline: "<<airline<<endl;
	cout<<"Source: "<<source<<"\tDestination: "<<destination<<endl;
	cout<<"Flight Type: "<<type<<endl;
	cout<<"Date of departure: "<<dod.date<<"/"<<dod.month<<"/"<<dod.year<<endl;
	cout<<"Time of departure: "<<t.hours<<":"<<t.minutes<<endl;
	cout<<"Duration: "<<du.hours<<endl;
	cout<<"Seat type: ";
	if(aa==1)
		cout<<"ECONOMY\n";
	else if(aa==2)
		cout<<"BUSINESS\n";
	else if(aa==3)
		cout<<"FIRST\n";
	cout<<"NO. OF SEATS BOOKED: "<<bb<<endl;
	cout<<"MEAL TYPE: ";
	if(cc==1)
		cout<<mealv<<endl;
	else if(cc==2)
		cout<<mealn<<endl;
	cout<<"TOTAL COST OF FLIGHT: "<<total<<endl;
}

//------------------------------------------------------------
class passenger
{
	protected:
	int a;
	char fname[20],lname[20];
	int age;
	char phno[11];
	char gender;	//m or f
	char passport[20];
	public:
	void input();
	void in_pass()	  //passport details if flight is international
	{
		cout<<"ENTER PASSPORT NO.: ";
		gets(passport);
		a=0;
	}
	void output();
};
void passenger::input()
{
	cout<<"ENTER NAME:\n ";
	cout<<"FIRST NAME: ";		gets(fname);
	cout<<"LAST NAME: ";		gets(lname);
	cout<<"ENTER PHONE NO.: ";		gets(phno);
	cout<<"ENTER AGE: ";		cin>>age;
	cout<<"ENTER GENDER(M/F): ";	cin>>gender;
}
void passenger::output()
{
	cout<<"ENTERED DETAILS:\n";
	cout<<"NAME: "<<fname<<" "<<lname<<endl;
	cout<<"PHONE NO.: "<<phno<<endl;
	cout<<"AGE: "<<age<<endl;
	cout<<"GENDER: "<<gender<<endl;
	if(a==0)
		cout<<"PASSPORT NO.: "<<passport<<endl;
}
//------------------------------------------------------------
class user
{
	protected:

	char userid[40],adminid[40]; 		//email for customers
	char passwords[25],ad_pass[40];
	public:
	user()
	{
		strcpy(adminid,"admin");
		strcpy(ad_pass,"gangadharshaktimaanhai");
	}
	void admin_pass();
	void passenger_enter();
	char getuserid()
	{
		return userid;
	}
	char getpassword()
	{
		return passwords;
	}
};
void admin_pass()
{
	int x=0;
	char p,user[30],pass[30];
	do
	{
		cout<<"ENTER ADMIN ID:-\t";
		gets(user);
		cout<<"\n\n";
		cout<<"ENTER PASSWORD:-\t";
		for(int i=0;i<23;i++)
		{
			getch(pass);
			cout<<"*";
		}
		pass[23]='\0';
		if ((strcmp(adminid,user)==1)&&(strcmp(pass,ad_pass)==1))
			     x++;

		else
		{
			cout<<"ERROR !!! EITHER THE PASSWORD OR USERNAME IS WRONG\n";
			cout<<"TO ENTER AGAIN PRESS ANY KEY OR ENTER Z TO EXIT	\n";
			getch(p);
			if(p=='Z')
				exit(0);

		}
	}while(x==0);
}

void user::passenger_enter()
{
	char f[30],ch;
	int x=0;
	cout<<"ENTER EMAIL ID:\t";
	gets(userid);
	cout<<"\n\n";
	cout<<"ENTER PASSWORD:\t";
	gets(passwords);
	do
	{
		cout<<"RE-ENTER PASSWORD:\t";
		gets(f);
		if(strcmp(f,passwords)==0)
			x++;
		else
		{
			cout<<"INCORRECT!!! PLEASE ENTER AGAIN\n";
			getch();
		}
	}while(x==0);
}
//------------------------------------------------------
class ticket: public flight,public passenger, public user
{
	unsigned long pnr; //ticket no.
}a;
