void sd(char a[],char b[])
{
	char x,y;
	do
	{
	cout<<"CHOOSE A SOURCE\n";
	cout<<"1. "<<s1<<endl;
	cout<<"2. "<<s2<<endl;
	cout<<"3. "<<s3<<endl;
	cout<<"4. "<<s4<<endl;
	cout<<"5. "<<s5<<endl;
	cin>>x;
	switch(x)
	{
		case 1:	strcpy(a,s1);
			break;
		case 2:	strcpy(a,s2);
			break;
		case 3:	strcpy(a,s3);
			break;
		case 4:	strcpy(a,s4);
			break;
		case 5:	strcpy(a,s5);
			break;
		default: cout<<"WRONG CHOICE!! CHOOSE AGAIN\n"
	}
	}while(x>5);
	clrscr();
	do
	{
	cout<<"CHOOSE A DESTINATION\n";
	if(x!='1')
		cout<<"11. "<<d11<<endl;
	if(x!='2')
		cout<<"22. "<<d22<<endl;
	if(x!='3')
		cout<<"33. "<<d33<<endl;
	if(x!='4')
		cout<<"44. "<<d44<<endl;
	if(x!='5')
		cout<<"55. "<<d55<<endl;
	cout<<"66. "<<d66<<endl;
	cout<<"77. "<<d77<<endl;
	cout<<"88. "<<d88<<endl;
	cout<<"99. "<<d99<<endl;;
	cout<<"111. "<<d111<<endl;
	cout<<"112. "<<d112<<endl;
	cout<<"113. "<<d113<<endl;
	cout<<"114. "<<d114<<endl;
	cout<<"115. "<<d115<<endl;
	cin>>y;
	switch(y)
	{
		case 11:	strcpy(b,d11);
			break;
		case 22:	strcpy(b,d22);
			break;
		case 33:	strcpy(b,d33);
			break;
		case 44:	strcpy(b,d44);
			break;
		case 55:	strcpy(b,d55);
			break;
		case 66:	strcpy(b,d66);
			break;
		case 77:	strcpy(b,d77);
			break;
		case 88:	strcpy(b,d88);
			break;
		case 99:	strcpy(b,d99);
			break;
		case 111:	strcpy(b,d111);
			break;
		case 112: strcpy(b,d112);
			break;
		case 113: strcpy(b,d113);
			break;
		case 114: strcpy(b,d114);
			break;
		case 115: strcpy(b,d115);
			break;
		default:	cout<<" WRONG CHOICE !! CHOOSE AGAIN\n";
	}
	}while(y>115);				
}
//----------------admin functions------------------
void admin_in()
{
	fstream f1;
	f1.open("FLIGHT.dat",ios::binary|ios::in|ios::out);
	char ch='y';
	while(ch=='y')
	{
		char s;
		do
		{
			a.in();
			cout<<"IS THE ABOVE ADDED INFO CORRECT?(Y/N)\n";
			cin>>s;
			if(s=='y')
				f1.write((char*)&a, sizeof(a));
		}while(s=='n'); 
		cout<<"WISH TO CONTINUE?(Y/N)";
		cin>>ch;
	}
	f1.close();
}
void admin_modify()
{
	char ch,s[30],d[30];
	clrscr();
	cout<<"SELECT FLIGHT TO BE MODIFIED:\n";
	sd(s,d);
	fstream f("FLIGHT.dat",ios::binary|ios::in|ios::app);
	do
	{
		while(!f.eof())
		{
			f.read((char*)&a,sizeof(a));
			if((strcmpi(a.getsource(),s)==0)&&(strcmpi(a.getdestination,d)==0))
			{
				a.modify();
				f.seekg(f.tellg()-sizeof(a));
				f.write((char*)&a,sizeof(a));
			}
			else
			{
				cout<<"SORRY, FLIGHT NOT FOUND\n";
				break;
			}
		}
		cout<<"DO YOU WISH TO MODIFY MORE ITEMS?(Y/N)\n";
		cin>>ch;
	}while(ch=='y');
	f.close();
}
void admin_display()
{
	char ch,s[30],d[30];
	do
	{
		clrscr();
		cout<<"SELECT FLIGHT TO BE DISPLAYED:\n";
		sd(s,d);
		fstream f("FLIGHT.dat",ios::binary|ios::in|ios::app);
		while(!f.eof())
		{
			if((strcmpi(a.getsource(),s)==0)&&(strcmpi(a.getdestination,d)==0))
			{
				f.read((char*)&a,sizeof(a));
				a.out();
			}
			else
			{
				cout<<"REQUIRED FLIGHT NOT FOUND\n";
			}
		}
		f.close();
		cout<<"\nWISH TO SEARCH OTHER FLIGHT?(Y/N)\n";
		cin>>ch;
	}while(ch=='y');
}
void admin_delete()
{
	clrscr();
	fstream f1,f2;
	char s[30],d[30],ch;
	f1.open("FLIGHT.dat",ios::binary|ios::in|ios::app);
	f2.open("DUP.dat",ios::binary|ios::in|ios::out);
	cout<<"SELECTTHE FLIGHT TO BE DELETED:\n";
	sd(s,d);
	clrscr();
	while(!f1.eof())
	{
		f1.read((char*)&a,sizeof(a));
			if((strcmpi(a.getsource(),s)==0)&&(strcmpi(a.getdestination,d)==0))
			{
				cout<<"DO YOU WISH TO DELETE THE FOLLOWINF FILE?\n";
				a.out();
				cout<<endl;
				cin>>ch;
				if(ch=='y')
				{
					cout<<"DATA DELETED\n";
				}
				else
					f2.write((char*)&a,sizeof(a));
			}
			else
			{
				f2.write((char*)&a,sizeof(a));
			}
	}
	f1.close();
	f2.close();
	remove("FLIGHT.dat");
	rename("DUP.dat","FLIGHT.dat");
}
//----------------------------------------------------------------------------------------
//---------------- passenger functions---------------
void passenger_in()
{
}
void booking(long &tot,int &r,int &q,int &e)
{
	char m;
	int a,b,c;
	long s,v;
	do
	{
		do
		{
			do
			{
				clrscr();
				cout<<"CHOOSE SEAT TYPE:\n";
				cout<<"1.ECONOMY\t 2. BUSINESS\t 3. FIRST CLASS\n":
				cin>>a;
				if(a>3)
				{
					cout<<"WRONG CHOICE!! ENTER AGAIN\n";
					break;
				}
				cout<<"ENTER NO. OF SEATS: ";
				char>>b;
				cout<<"IS ABOVE ADDED INFORMATION CORRECT?(Y/N)";
				cin>>m;
			}while(m=='n');
		if(a<=3)
			s=a.select_seat(a,b);
		cout<<"CONTINUE?\n";
		getch();
		}while(a>3);
		do
		{
			do
			{
				clrscr();
				cout<<"ENTER MEAL TYPE:\n";
				cout<<"1. VEGITARIAN\t 2. NON-VEGITARIAN\n";
				cin>>c;
				if(c>2)
				{
					cout<<"WRONG CHOICE!! TRY AGAIN\n";
					break;
				}
				cout<<"IS ABOVE ADDED INFORMATION CORRECT?(Y/N)";
				cin>>m
			}while(m=='n');
			if(c<=2)
				v=select_meal(c);
			cout<<"CONTINUE?\n";
			getch();
		}while(c>2);
		tot=s+v;
		r=a;
		q=b;
		e=c;
		cout<<"TOTAL COST OF SEATS,FLIGHT AND MEAL: "<<tot<<endl;
		cout<<"DO YOU WISH TO MAKE ANY CHANGES?(Y/N)\n";
		cin>>m;
	}while(m=='y');
}
	
void passenger_display()
{
	clrscr();
	fstream f1;
	fstream f2("TICKET.dat",ios::binary|ios::in|ios::out);
	char p;
	cout<<"ENTER EMAIL ID AND REQUIRED PASSWORD:\n";
	do
	{
		a.passenger_enter();
		cout<<"IS THE ABOVE ADDED INFO CORRECT?(Y/N)\n";
		cin>>s;
		if(p=='y')
			f2.write((char*)&a, sizeof(a));
	}while(p=='n');
	clrscr();
	cout<<"ENTER PASSENGER INFORMATION:\n";
	do
	{
		a.input();
		cout<<"IS THE ABOVE ADDED INFO CORRECT?(Y/N)\n";
		cin>>s;
		if(s=='y')
			f2.write((char*)&a, sizeof(a));
	}while(s=='n');
	clrscr();
	char y,s[30],d[30];
	long tot;
	int a,b,c,lt=0;
	do
	{
		sd(s,d);
		f1.open("FLIGHT.dat",ios::binary|ios::in|ios::app);
		clrscr();
		cout<<"FLIGHT NO.  "<<"AIRLINE\t"<<"SOURCE\t\t"<<"DESTINATION\t"<<"DOD\t"<<"TOD  "<<"STARTS FROM\n";
		while(!f1.eof())
		{
			f1.read((char*)&a,sizeof(a));
			if((strcmpi(a.getsource(),s)==0)&&(strcmpi(a.getdestination,d)==0))
			{
				a.display();
				int u=0;
				do
				{
					cout<<"ENTER FLIGHT NO. OF REQUIRED FLIGHT: ";
					long e;
					cin>>e;
					if(strcmp(e,getflightno)==0)
					{
						clrscr();
						cout<<"DETAILS OF FLIGHT:\n";
						a.display2();
						cout<<"CONTINUE?";
						getch();
						booking(tot,a,b,c);
						cout<<"FINAL DETAILS:\n";
						a.passenger_final(tot,a,b,c);
						cout<<"WANT TO MAKE ANY CHANGES?(Y/N);
						char p;
						cin>>p;
						if(p=='y')
							lt=1;
						else
							f2.write((char*)&a,sizeof(a));			
					}
					else
					{
						clrscr();
						cout<<"WRONG CHOICE!! TRY AGAIN\n";
						u=1;
						getch();
					}	
				}while((u==1)||(lt==1));
			}
			else
			{
				clrscr();
				cout<<"SORRY, NO SUCH FLIGHTS AVAILABLE\n ";
				cout<<"WOULD YOU LIKE TO SEARCH ANY OTHER FLIGHTS?(Y/N)\n";
				cin>>y;
			}
	}while(y=='y');
	f1.close();
	f2.close();
}			
//------------------------------------------ticket functions-------------------------------------
void ticket_out()
{
	clrscr();
	fstream f("TICKET.dat",ios::binary|ios::in|ios::app);
	int i,u=0;
	char uis[30],pass[30];
	do
	{
		cout<<"ENTER EMAIL ID: ";
		gets(uid);
		cout<<"ENTER PASSWORD: ";
		gets(pass);
		f.read((char*)&a,sizeof(a));
		if((strcmp(uid,a.getuserid)==0)&&(strcmp(pass,getpassword())==0))
		{
			cout<<"TICKET DETAILS: \n";
			cout<<"FLIGHT DETAILS:\n";
			a.passenger_final();
			cout<<"USER DETAILS:\n";
			a.output();
		}
		else
		{
			cout<<"WRONG EMAIL ID OR PASSWORD\n";
			cout<<"PLEASE TRY AGAIN\n";
			u=1;
		}
	}while(u==1);
	f.close();
	cout<<"CONTINUE?\n";
	getch();
}			

	
	 

	
	
	
