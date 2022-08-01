#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>
#include<stdlib.h>
using namespace std;


class fddata                                                           // class creation
{
	protected:
		char name[20];
		char dob[15];
		int age;
		char occupation[20];
		char address[50];
		char phn[12];
		unsigned long int deposit;
		int time_period;
		float interest;
		int fd_no;
		
		public:
			void get_fd_data();
			void display_fd_data();
			void put_in_file(fddata&);
			int agevalidate();
			int phnvalidate(char*);
			void createFile(fddata &);
			void generate(int l,int r);
			friend void display_specific_fd_data();
};


void fddata::get_fd_data()                                                   // function to  get the details of customer who applies for FD                                        
{
	cout<<"\t\t\t\t\t\t\t\t\t\t\tFILL THE DETAILS TO APPLY:\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

	fflush(stdin);                                                           // clears input buffer
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER NAME:";
	cin.getline(name,50);                                                    // gets space also as input 
	
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
		if(phnvalidate(phn))                                                       //phone number validation is done
			break;
	}while(1);
	
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER AMOUNT TO BE DEPOSITED:";
	cin>>deposit;
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER TIME PERIOD:";
	cin>>time_period;
	
	int l=10051000,r=10051999;
	srand(time(0));                                                              // gets the random FD number
	generate(l,r);
	ofstream file("fd_number.txt",ios::app);
	file<<name<<endl<<fd_no<<endl;                                              // writes those names and FD number in text file for referrence
	
	interest=4.0;

}
void fddata::generate(int l,int r)                                               // function to generate random FD number
{
	fd_no=(rand()%(r-l+1))+l;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tYOUR DEPSOIT NUMBER IS ";
	yellow();
	cout<<fd_no<<endl;	
	reset();
	cout<<"\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}
int fddata::phnvalidate(char *phn)                                                 // function to check the phone number (The phone number should not be repeated)
{                                                                                  // object creation
	fddata obj;
	ifstream f("fd_database.dat",ios::in|ios::binary);                             // opening the  binary file in read mode
	while(f.read((char*)&obj,sizeof(obj)))
	{
		if(!strcmp(obj.phn,phn))                                                   // checks whether the enetered phone number is equal to the phone number existing in the file
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
	return 1;                                                                         // returns 1 if the phone number is new 
}
int fddata::agevalidate()
{
	cin>>age;
	while(age<18||age>100)                                                            // (Age validation) the age should be above 18 and below 60 if age is not in this range it again gets the age as input 
	{
		red();
		cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t\tINVALID AGE!!!";
		cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
		reset();
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tENTER AGE AGAIN:";
		cin>>age;
	}
	return age;
}

void fddata::createFile(fddata &s)                                                      // function to create a file and write the contents
{
	ofstream file("fd_database.dat",ios::binary | ios::app);                            // opens the binary file in append mode
	if (!file)                                                                          // if the file is not created or error in opening the file
	{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else
	{
	file.write((char*)&s,sizeof(s));                                                      // write the contents into the file
	file.close();
    }
}

void fddata::display_fd_data()                                                            // displays the details of customer who applied for FD
{
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tFIXED DEPOSIT APPLICATION NUMBER:"<<fd_no<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tNAME:"<<name<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tDOB:"<<dob<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tAGE:"<<age<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tOCCUPATION:"<<occupation<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tADDRESS:"<<address<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tCONTACT: +91"<<phn<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tAMOUNT:"<<deposit<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tTIME PERIOD:"<<time_period<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tINTEREST:"<<interest<<"%"<<endl;
}
void display_all_fd_application()                                                         // displays all the customer details who applied for FD
{
	fddata s;                                                                             // object creation
	int n=0;
	ifstream f("fd_database.dat",ios::in|ios::binary);                                    // opens the binary file in read mode
	if (!f)                                                                               // if the file is not created or error in opening the file
	{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else
	{
	
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tFIXED DEPOSIT DETAILS:"<<endl<<endl;
	while(f.read((char*)&s,sizeof(s)))
	s.display_fd_data();                                                                    // all the details of all the customers are displayed
	n=1;
	f.close();
	if(n==0)                                                                                // if no records in the file
	{
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"THERE ARE NO RECORDS IN THE BANK"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	} 
    }
}
void display_specific_fd_data()                                                             // displays the specific customer's FD details based on the FD number
{
	fddata obj;                                                                             // object creation 
	int no,fo=0;
	ifstream f("fd_database.dat",ios::in|ios::binary);                                      // opens the binary file in read mode
	if (!fo)
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER YOUR FIXED DEPOSIT APPLICATION NUMBER:";
	cin>>no;
	while(f.read((char*)&obj,sizeof(obj)))
	{
		if(no==obj.fd_no)                                                                     // if the FD number given by the customer matches the FD number in the file 
		{
			obj.display_fd_data();                                                            // display the details of the customer
			fo=1;
		}
	}
	if(fo==0)                                                                                 // if the FD number is not found in the file
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	red();
	cout<<"\t\t\t\t\t\t\t\t\t\t\tFIXED DEPOSIT APPLICATION NOT FOUND!!";
	reset();
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	f.close();                                                                                // closing the file
	}
}
void apply_fd()                                                                               // function to check whether the FD is applied or not
{
	fddata l;
	l.get_fd_data();
	l.createFile(l);
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tFIXED DEPOSIT APPLICATION DONE SUCCESFULLY!!"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
}

