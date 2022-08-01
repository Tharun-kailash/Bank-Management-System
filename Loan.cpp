#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
using namespace std;



class loandata                                                                 //class creation
{
	    protected:
		char name[20];
		char dob[15];
		int age;
		char occupation[20];
		char address[50];
		char phn[12];
		char purpose[50];
		unsigned long int loan_amt;
		unsigned long int income;
		int loan_no;
		
		public:
			void get_loan_data();
			void display_loan_data();
			void put_in_file(loandata&);
			int agevalidate();
			int phnvalidate(char*);
			void createFile(loandata &);
			void generate(int l,int r);
			friend void display_specific_loan_data();
};


void loandata::get_loan_data()                                                 //function to get the details of the customer who wants loan
{
	cout<<"\t\t\t\t\t\t\t\t\t\t\tFILL THE DETAILS TO APPLY:\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

	fflush(stdin);                                                             //clears input buffer
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER NAME:";
	cin.getline(name,50);                                                      //gets space also as input
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER DOB(DD/MM/YYYY):";
	cin.getline(dob,11);

	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER AGE:";
	age=agevalidate();
			
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER OCCUPATION:";
	cin.getline(occupation,30);
			
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER ADDRESS:";
	cin.getline(address,50);
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER CONTACT(+91):";
	cin.getline(phn,11);
	do
	{
		if(phnvalidate(phn))                                                    //phone number validation
			break;
	}while(1);
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER PURPOSE:";
	cin.getline(purpose,50);
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER LOAN AMOUNT:";
	cin>>loan_amt;
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER MONTHLY INCOME:";
	cin>>income;
	
	int l=10051000,r=10051999;
	srand(time(0));                                                              //gets random loan number
	generate(l,r);
	ofstream file("loan_number.txt",ios::app);                                   //opens the text file in append mode
	file<<name<<endl<<loan_no<<endl;                                             //writes into the file

}
void loandata::generate(int l,int r)                                             //generates the loan number to the customer
{
	loan_no=(rand()%(r-l+1))+l;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tYOUR APPLICATION NUMBER IS ";
	yellow();                                                                    //sets the loan number in yellow colour 
	cout<<loan_no<<endl;	
	reset();                                                                     //resets to the default font colour 
	cout<<"\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}
int loandata::phnvalidate(char *phn)                                             //function to validate the phone number
{
	loandata obj;                                                                //object creation for loandata class
	ifstream f("loan_database.dat",ios::in|ios::binary);                         //opening the binary file in read mode
	while(f.read((char*)&obj,sizeof(obj)))
	{
		if(!strcmp(obj.phn,phn))                                                 //checks if the phone number already exist
		{
			cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
			red();
			cout<<"\t\t\t\t\t\t\t\t\t\t\tCONTACT ALREADY EXIST!"<<endl;
			reset();
			cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
			cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER ANOTHER CONTACT:";
			cin.getline(phn,11);
			f.close();
			return 0;
		}
	}
	f.close();
	return 1;                                                                       //return 1 if the phone number is new
}
int loandata::agevalidate()
{
	cin>>age;
	while(age<18||age>60)                                                          //the valid age should be above 18 and below 60 
	{
		red();
		cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t\tINVALID AGE!!! YOU'RE NOT ELIGIBLE TO APPLY LOAN";
		cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
		reset();
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tENTER AGE AGAIN:";
		cin>>age;
	}
	return age;
}

void loandata::createFile(loandata &s)
{
	ofstream file("loan_database.dat",ios::binary | ios::app);                   //opens the file in append mode
	if (!file)                                                                   //if the file is not created or error in oprning the file
	{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else                                                                         //write the contents into the file
	{
	file.write((char*)&s,sizeof(s));
	file.close();
    }
}

void loandata::display_loan_data()                                             //displays the details of the respective customer who applies for loan
{
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tLOAN APPLICATION NUMBER:"<<loan_no<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tNAME:"<<name<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tDOB:"<<dob<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tAGE:"<<age<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tOCCUPATION:"<<occupation<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tADDRESS:"<<address<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tCONTACT: +91"<<phn<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tPURPOSE:"<<purpose<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tLOAN AMOUNT:"<<loan_amt<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tMONTHLY INCOME:"<<income<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
}
void display_all_loan_application()                                             //displays all the customer details
{
	int n=0;
	loandata s;
	ifstream f("loan_database.dat",ios::in|ios::binary);                         //opens the binary file in read mode 
	if (!f)                                                                      //if the file is not created or error in opening the file
	{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else
	{
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tLOAN DETAILS:"<<endl<<endl;
	while(f.read((char*)&s,sizeof(s)))
	s.display_loan_data();                                                        //displays all customer's loan details
	n=1;
	f.close();
	if(n==0)                                                                      //if there is no loan records in the file
	{
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"THERE ARE NO RECORDS IN THE BANK"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	} 
    }
}
void display_specific_loan_data()                                                  //function to display the loan details of a specific customer
{
	loandata obj;                                                                  //object creation
	int no,fo=0;
	ifstream f("loan_database.dat",ios::in|ios::binary);                           //opens the file in read mode
	if (!fo)                                                                       //if the file is not created or error in opening the file
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER YOUR LOAN APPLICATION NUMBER:";
	cin>>no;
	while(f.read((char*)&obj,sizeof(obj)))
	{
		if(no==obj.loan_no)                                                      //if the given loan number matches the loan number in the file                                  
		{
			obj.display_loan_data();                                             //displays the details
			fo=1;
		}
	}
	if(fo==0)                                                                    //if loan number is not found in the file
	{
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tLOAN APPLICATION NOT FOUND!!";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
    }
	f.close();                                                                   //closing the file
}
}

void apply_loan()                                                               //function to check whether the loan is applied or not
{
	loandata l;
	l.get_loan_data();
	l.createFile(l);
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tLOAN APPLIED SUCCESSFULLY!!"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
}

