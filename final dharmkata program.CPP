
//*********************************************************************
// *CS PROJECT MADE BY SHUBHAM ON TOPIC DHARMKATA *********************
//*********************************************************************

//*********************************************************************
// *****************************HEADER FILES USED**********************
//*********************************************************************

void main();
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>



//******************************************************************
//***************************Prototype of fnctions******************
//******************************************************************

void umenu();
void login();
void dmenu();
void delete_record1();
void read_from_file1();
void Search_Selected_Record1();
void update_record1();
void insert_in_sorted_record1();
void delete_record();
void write_to_file();
void read_from_file();
void Search_Selected_Record();
void update_record();
void insert_in_sorted_record();





//************************************************
//**********************CLASS USER****************
//************************************************



class USER
{
	int userid;
	char Name[20];
	char pass[30];
	public:
		void get()
		{
		cout<<"Enter userid:- ";
		cin>>userid;
		cout<<"\n Enter Name:- ";
		gets(Name);
		cout<<"\n Enter password:-";
		gets(pass);
		}

		void show()
		{
		cout<<"\nUSER ID :-"<<userid<<" NAME:- "<<Name;
		}
		int getno()
		{
		return userid;
		}
		char *getpas()
		{
		return pass;
		}
};

USER s,s1;



//**********************************************
//******************INSERTING USER**************
//**********************************************




void insert_in_sorted_record1()
{
ofstream fout;
fout.open("temp",ios::binary|ios::app);
ifstream fin;
fin.open("stud",ios::binary|ios::app);
char last='y';
cout<<"\nEnter Details of user:-\n";
s1.get();
while(1)
{
	fin.read((char *)&s,sizeof(s));
	if(fin.eof())break;
	if(s1.getno()<=s.getno())
	{
	last='n';
	fout.write((char *)&s1,sizeof(s1));
	break;
	}
	else
	fout.write((char *)&s,sizeof(s));
}
	if(last=='y')
		fout.write((char *)&s1,sizeof(s1));
	else if(!fin.eof())
	{
		while(1)
		{
			fout.write((char *)&s,sizeof(s));
			fin.read((char *)&s,sizeof(s));
			if(fin.eof())break;

		}
	}

	fin.close();
	fout.close();
	remove("stud");
	rename("temp","stud");

cout<<" \n CREATION OF NEW ACCOUNT SUCCESSFUL :-";

umenu();

}


//*************************************************
//*******************USER LOGIN********************
//*************************************************



void login()
{
ifstream fin;
fin.open("stud",ios::binary);
char found='n';
int id; char pas[30];
cout<<"\n Enter user id :-" ;
cin>>id;
cout<<"\n Enter Password:-" ;
gets(pas);
while(1)
{
fin.read((char *)&s,sizeof(s));
	if(fin.eof())break;
if(s.getno()==id && (strcmp(s.getpas(),pas))==0)
	{
	found='y';
cout<<"\n login successful :-";
umenu();

}

}
if (found=='n')
{cout<<"\n User not found :-";
main(); }
}




//***************************************************************
//*****************MODIFYING USER********************************
//***************************************************************



void update_record1()
{
fstream finout;
finout.open("stud",ios::binary|ios::in|ios::out);
finout.seekg(0,ios::beg);
char found='n';
int id;
char pas[30];
long pos;
cout<<"\n Enter user id :-";
cin>>id;
cout<<"\n Enter Password:-" ;
gets(pas);
while(1)
{
pos=finout.tellg();
finout.read((char *)&s,sizeof(s));
	if(finout.eof())break;
if(s.getno()==id && (strcmp(s.getpas(),pas)==0))
	{
	found='y';
cout<<"\nEnter Modified Record:- \n";
	s1.get();
	finout.seekg(pos);
	finout.write((char *)&s1,sizeof(s1));
	cout<<"\n\n";
	}
}
	if(found=='n')
		cout<<"Record Not Found";

	finout.close();
}
//***************************************************************
//****************DELETING USER**********************************
//***************************************************************

void delete_record1()
{

ifstream fin;
ofstream fout;
fin.open("stud",ios::binary);
fout.open("temp",ios::binary|ios::app);
char found='n';
int id; char pas[30];
cout<<"\n Enter user id :-";
cin>>id;
cout<<"\n Enter Password:-" ;
gets(pas);
while(1)
{
fin.read((char *)&s,sizeof(s));
	if(fin.eof())break;
if(s.getno()==id && (strcmp(s.getpas(),pas)==0))
	{
	found='y';
cout<<"\n Deleted record is: -\n";
	s.show();
	cout<<"\n\n";
	}
	else
	fout.write((char *)&s,sizeof(s));
}
	if(found=='n')
		cout<<"Record Not Found";

	fin.close();
	fout.close();
	remove("stud");
	rename("temp","stud");
}



//***************************************************************
//******************SERACHING USER*******************************
//***************************************************************
void Search_Selected_Record1()
{
ifstream fin;
fin.open("stud",ios::binary|ios::app);
char found='n';
int id;
cout<<"Enter id to be Searched:- ";
cin>>id;
while(1)
{
	fin.read((char *)&s,sizeof(s));
	if(fin.eof())break;
	if(s.getno()==id)
	{
	found='y';
	s.show();
	cout<<"\n\n";
	}
}
	if(found=='n')
		cout<<"Record Not Found";

	fin.close();
}


//**************************************************************
//******************VIEWING USER********************************
//**************************************************************


void read_from_file1()
{
cout<<"This is your Reacord:-\n\n";
ifstream fin;
fin.open("stud",ios::binary|ios::app);
while(1)
{
fin.read((char *)&s,sizeof(s));
if(fin.eof())break;
s.show();
}
fin.close();
}



//****************************************************************
//**********************USER MENU*********************************
//****************************************************************

void umenu()
{
char ans='y';
int choice;
do
{
cout<<"\n1.VIEW USERS \n";
cout<<"\n2.MODIFY A/C\n";
cout<<"\n3.Search USERS \n";
cout<<"\n4.Delete A/C \n";
cout<<"\n5.Logout\n";
cout<<"\n6.dharmkata menu\n";
cout<<"\nEnter Your Choice:- ";
cin>>choice;

switch(choice)
{
case 1: read_from_file1();       //Delete from File Calling Code
	break;
case 3: Search_Selected_Record1();	//Read_from_file function calling code
	break;
case 4: delete_record1();
	break;
case 6: dmenu();
	break;
case 2 :update_record1();
	break;
case 5: main();

default: cout<<"\n Wrong Choice!!!";
}
cout<<"\nDo You Want To Contine... Press Y:- \n";
cin>>ans;
}while(ans=='y'||ans=='Y');
main();
}

//*************************************************************
//*********************DHARMKATA MENU**************************
//*************************************************************

void dmenu()
{
char ans='y';
int choice;
do
{
cout<<"\n1.Record a challan \n";
cout<<"\n2.Read records\n";
cout<<"\n3.Search records\n";
cout<<"\n4.Delete record\n";
cout<<"\n5.Update record\n";
cout<<"\n6.Previos Menu\n";
cout<<"\nEnter Your Choice:- ";
cin>>choice;

switch(choice)
{
case 1:write_to_file();	//Write_to_file function calls
	break;
case 2: read_from_file();       //read from File Calling Code
	break;
case 3: Search_Selected_Record();	//search_from_file function calling code
	break;
case 4: delete_record();                //delete function calling code
	break;
case 5 :update_record();    //update function calling code
	break;
case 6: umenu();
default: cout<<"\n Wrong Choice!!!";
}
cout<<"\nDo You Want To Contine... Press Y:- \n";
cin>>ans;
}while(ans=='y'||ans=='Y');

}

//****************************************************
// ****************** CLASS DHARMKATA*****************
//****************************************************




class dharmkata
{
	char vehicleno[30], ownername[30], itemloaded[30], ctake[30], lfrm[30], unlto[30];
	int eweight, fweight, nweight;
	public:
		void get()
		{
		cout<<"Enter vehicleno:- ";
		gets(vehicleno);
		cout<<"\n Enter  Ownername:- ";
		gets(ownername);
		cout<<"\n Enter Item loaded:-";
		gets(itemloaded);
		cout<<"\n Loaded from:-";
		gets(lfrm);
		cout<<"\n Unload to :-";
		gets(unlto);
		cout<<"\n Enter empty vehicle weight:-";
		cin>>eweight;
		cout<<"\n Enter loaded vehicle weight:-";
		cin>>fweight;
		cout<<"\n Challan taken by:-";
		gets(ctake);
		}

		void show()
		{
		cout<<"\n Vehicleno:-"<<vehicleno;
		cout<<"\n Ownername:- "<<ownername;
		cout<<"\n Item loaded:-"<<itemloaded;
		cout<<"\n Loaded from:-"<<lfrm;
		cout<<"\n Unload to :-"<<unlto;
		cout<<"\n Enter empty vehicle weight:-"<<eweight;
		cout<<"\n Enter loaded vehicle weight:-"<<fweight;
		cout<<"\n Challan taken by:-"<<ctake<<"\n\n\n";
		}
		char *getno()
		{
		return vehicleno;
		}
};

dharmkata d, d1;





//****************************************************************
//***************MAIN PROGRAM PART(VOID MAIN)*********************
//****************************************************************
void main()
{
clrscr();
int z;
char ans;
do
{
cout<<" FOR LOGIN PRESS 1 \n FOR SIGNUP PRESS 2 \n PRESS 3 TO EXIT:-";
cin>>z;
switch(z)
{
case 1:login();
break;
case 2:insert_in_sorted_record1();
break;
case 3:exit(1);
default: cout<<"wrong choice!!!!!";
}
cout<<"\nDo You Want To Contine... Press Y:- \n";
cin>>ans;
}while(ans=='y'||ans=='Y');}


//*******************************************************************
//*******************WRITING RECORDS FOR DHARMKATA*******************
//*******************************************************************



void write_to_file()
{
char ans='y';
ofstream fout;
fout.open("dharm",ios::binary|ios::app);
while(ans=='y'||ans=='Y')
{
d.get();
fout.write((char *)&d,sizeof(d));
cout<<"Do You Want To (write)Continue:- \n";
cin>>ans;
}
fout.close();
}
//*************************************************
//**************READING RECORDS********************
//*************************************************

void read_from_file()
{
cout<<"This are your Reacords:-\n\n";
ifstream fin;
fin.open("dharm",ios::binary|ios::app);
while(1)
{
fin.read((char *)&d,sizeof(d));
if(fin.eof())break;
d.show();
}
fin.close();
}
//*******************************************************************
//**************DELETING RECORDS OF DHARMKATA************************
//*******************************************************************


void delete_record()
{
ofstream fout;
fout.open("temp",ios::binary|ios::app);
ifstream fin;
fin.open("dharm",ios::binary|ios::app);
char found='n';
char id[30];
cout<<"Enter vehicleno for record to be deleted:- ";
gets(id);
while(1)
{
	fin.read((char *)&d,sizeof(d));
	if(fin.eof())break;
	if(strcmp(d.getno(),id)==0)
	{
	found='y';
	cout<<"\n Deleted record is: -\n";
	d.show();
	cout<<"\n\n";
	}
	else
	fout.write((char *)&d,sizeof(d));
}
	if(found=='n')
		cout<<"Record Not Found";

	fin.close();
	fout.close();
	remove("dharm");
	rename("temp","dharm");
}
//*******************************************************************
//*************SEARCHING RECORD IN DHARMKATA*************************
//*******************************************************************


void Search_Selected_Record()
{
ifstream fin;
fin.open("dharm",ios::binary|ios::app);
char found='n';
char id[30];
cout<<"Enter vehicleno for record  to be Searched:- ";
gets(id);
while(1)
{
	fin.read((char *)&d,sizeof(d));
	if(fin.eof())break;
	if(strcmp(d.getno(),id)==0)
	{
	found='y';
	d.show();
	cout<<"\n\n";
	}
}
	if(found=='n')
		cout<<"Record Not Found";

	fin.close();
}
//*******************************************************************
//****************UPDATING RECORD IN DHARMKATA***********************
//*******************************************************************


void update_record()
{
fstream finout;
finout.open("dharm",ios::binary|ios::in|ios::out);
char found='n';
char id[30];
long pos;
cout<<"Enter vehicleno for record to be Updated:- ";
gets(id);
while(1)
{
	pos=finout.tellg();
	finout.read((char *)&d,sizeof(d));
	if(finout.eof())break;
	if(strcmp(d.getno(),id)==0)
	{
	found='y';
	cout<<"\nEnter Modified Record:- \n";
	d1.get();
	finout.seekg(pos);
	finout.write((char *)&d1,sizeof(d1));
	cout<<"\n\n";
	break;
	}
}
	if(found=='n')
		cout<<"Record Not Found";

	finout.close();
}


