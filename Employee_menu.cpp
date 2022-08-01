#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class customer                                                                       //customer class
{
	protected:                                                                       //protected data member
		
	char name[20];
	int age;
	char occupation[20];
	char address[50];
	char dob[15];
	char phn[12];
	int acc_no;
	float total_balance;
	
	public:                                                                         //public data members
		
	friend customer& modify(customer&);
	friend void modifycustomer();
	friend void deletecustomer();
	void getData();
	void createFile(customer &s);
	void display();
	int idvalidate(int &n);
	int phnvalidate(char *phn);
	int agevalidate();
};


void customer::getData()                                                              //get data function
{
	
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER USER DETAILS:\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE ACCOUNT NUMBER:";
	cin>>acc_no;
	do{
	if(idvalidate(acc_no))                                                              //check for id validation
	break;			
	}while(1);
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE USER NAME:";
	cin.getline(name,50);
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE USER  DOB(DD/MM/YYYY):";
	cin.getline(dob,11);

	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE USER AGE:";
	age=agevalidate();
			
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE USER OCCUPATION:";
	cin.getline(occupation,30);
			
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER CUSTOMER ADDRESS:";
	cin.getline(address,100);
	
	fflush(stdin);
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER CUSTOMER CONTACT(+91):";
	cin.getline(phn,11); 
	do
	{
    if(phnvalidate(phn))                                                              //check phone number validation
	break;
	}while(1);
	
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER ACCOUNT BALANCE:";
	cin>>total_balance;		
}


void customer::createFile(customer &s)                                              //create file function
{
	
	ofstream file("bankdatabase.dat",ios::binary | ios::app);                        //open file in append mode
	if (!file)
	{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else
	{
	file.write((char*)&s,sizeof(s));                                                 //write and close the file
	file.close();
}
}


void customer::display()                                                             //display function
{
	
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t=================================================="<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tACCOUNT NUMBER:"<<acc_no<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tNAME:"<<name<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tDOB:"<<dob<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tAGE:"<<age<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tOCCUPATION:"<<occupation<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tADDRESS:"<<address<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tCONTACT: +91"<<phn<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tBALANCE:"<<total_balance<<endl;
}


int customer::idvalidate(int &n)				                          		//function to validate id
{ 
   
	customer obj;
	ifstream f("bankdatabase.dat",ios::in|ios::binary);                        //open file in read mode
	while(f.read((char*)&obj,sizeof(obj)))
	{
		if(obj.acc_no==n)                                                       //if the id already exists enter another id
		{
			cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
			red();
			cout<<"\t\t\t\t\t\t\t\t\t\t\tID ALREADY EXIST!"<<endl;
			reset();
			cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
			cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER ANOTHER ID:";
			cin>>n;
			f.close();
			return 0;
		}
	}
	f.close();
	return 1;
}


int customer::phnvalidate(char *phn)                                                      //function to validate phone number

{
	customer obj;
	ifstream f("bankdatabase.dat",ios::in|ios::binary);
	while(f.read((char*)&obj,sizeof(obj)))
	{
		if(!strcmp(obj.phn,phn))                                                                      //comparing ph num for validation
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
	return 1;
}


int customer::agevalidate()                                                                            //function to validate age
{
	
	cin>>age;
	while(age<18||age>100)                                                                           //check for the valid age
	{ 
		red();
		cout<<"\t\t\t\t\t\t\t\t\t\t\tINVALID AGE!!!";
		reset();
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tENTER AGE AGAIN:"<<endl;
		cin>>age;
	}
	return age;
}


void addCustomer()                                                                                      //add record function
{
	
	customer s;
	s.getData();
	s.createFile(s);
}


void readCustomer()                                                                                       //display function
{
	char found='t';
	customer s;
	ifstream f("bankdatabase.dat",ios::in|ios::binary);                                                   //open the file in read mode
	if (!f)
	{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME SERVER ERROR IN THE BANK............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else
	{
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\tUSER DETAILS"<<endl<<endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while(f.read((char*)&s,sizeof(s)))   
	{                                                                    //read and dispaly the account details
	s.display();                                                                                             //assign flag
	found='t';    
	}                                                                                           //if not found print not found
	if (found == 'f')
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE ARE NO RECORDS IN THE BANK............" << endl<< endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
	f.close();
	
}
}


customer& modify(customer &emp)                                                                        //modify menu function
{
	int ch,f;
	char phno[11];
	while(1)
	{
		system("cls");
		cout<<"\t\t\t\t\t\t\t\t\t\t\tMODIFY MENU"<<endl;
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
		red();
		cout<<"| Please enter the correct field name you want to modify |";
		reset();
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
		cout<<"\t\t1.Name\n\t\t2.DOB\n\t\t3.Age\n\t\t4.Occupation\n\t\t5.Address\n\t\t6.Contact\n\t\t7.Exit"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE CHOICE: ";
		cin>>ch;
	
		switch(ch)                                                                                        //get the correct case and modify
		{
				case 1:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\t\tOLD NAME:"<<emp.name<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW NAME:";
				cin.getline(emp.name,50);
				break;
				
			case 2:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\t\tOLD DOB:"<<emp.dob<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW DOB(DD/MM/YYYY):";
				cin.getline(emp.dob,11);
				break;
				
			case 3:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\t\tOLD AGE:"<<emp.age<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW AGE:";
				emp.age=emp.agevalidate();
				break;
				
			case 4:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\t\tOLD OCCUPATION:"<<emp.occupation<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW OCCUPATION:";
				cin.getline(emp.occupation,30);
				break;
				
			case 5:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\t\tOLD ADDRESS:"<<emp.address<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW ADDRESS:";
				cin.getline(emp.address,100);
				break;
				
			case 6:
				fflush(stdin);
				cout<<"\t\t\t\t\t\t\t\t\t\t\tOLD CONTACT: +91"<<emp.phn<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW CONTACT:(+91)";
				cin.getline(phno,11);
				do
				{
					if(emp.phnvalidate(phno))
					{
						strcpy(emp.phn,phno);
						break;
					}
				}while(1);
				break;
				
			case 7:
				return emp;
				
			default:
				cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE CORRECT OPTION"<<endl;
				cout<<"\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
		}
		
		system("pause");
	}
	return emp;
}


void modifycustomer()                                                                                       //modify function
{
	
	customer cus;
	int n,fo=0;
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tENTER THE ID OF THE USER TO MODIFY:";                                  //open the file in read and write mode
	cin>>n;
	fstream f("bankdatabase.dat",ios::in|ios::out|ios::binary);
	if (!f)
	{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	}
	else
	{
	while(f.read((char*)&cus,sizeof(cus)))                                                                  //if found read the file and check for the id match
	{
		if(cus.acc_no==n)
		{
			cus=modify(cus);
			
			f.seekp((int)f.tellg()-sizeof(cus), ios::beg);                                                 //modify and write the data
			f.write((char*)&cus,sizeof(cus));
			fo=1;
			break;
		}
	}
	f.close();
	fo?cout<<"\n\t\t\t\t\t\t\t\t\t\t\t=====================================================\n\t\t\t\t\t\t\t\t\t\t\tEXITING THE MODIFY MENU!\n\t\t\t\t\t\t\t\t\t\t\t====================================================="<<endl:cout<<"\n\t\t\t\t\t\t\t\t\t\t\t=====================================================\t\t\t\t\t\t\t\t\t\t\tDATA NOT FOUND\n\t\t\t\t\t\t\t\t\t\t\t====================================================="<<endl;
}
}


void deletecustomer()                                                                                       //delete cus function
{
	
	int pos, flag = 0, n;
		customer obj;                                                                                        //object creation
		ifstream f1;										                                                //ifstream object
		f1.open("bankdatabase.dat", ios::in | ios::binary);                                               //open the old file in read mode
		ofstream f2;										                                              //ofstream object
		f2.open("bankdatabase_temp.dat", ios::out | ios::binary);		                                              //open temp file in write mode

		if (!f1)                                                                                        //if there is no file
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME SERVER ERROR IN THE BANK............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE EMPLOYEE NUMBER TO BE DELETED:";                          //get the acc number to be deleted
			cin >> n;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			
			while (!f1.eof())
			{
				f1.read((char *)&obj, sizeof(obj));
				if (f1)                                                                // if(f1)checks the buffer record in the file
				{
					if (obj.acc_no == n)                                                   //comparing the acc no with roll no of record to be deleted
					{
						flag = 1;
					
					}
					else
					{
						f2.write((char *)&obj, sizeof(obj));                                                  // copy the record of "bankdatbase" file to "temp" file                                       
						                                    
					}
				}
			}
			f2.close();                                                                                    //close the files
			f1.close();
			remove("bankdatabase.dat");				                                                         // delete the old file
			rename("bankdatabase_temp.dat", "bankdatabase.dat");                                                          // rename new file to the older file

			if (flag == 1)                                                                               //if the acc no is found and deleted
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tRECORD IS DELETED SUCCESSFULLY" << endl
					 << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}

			else
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\t\tRECORD IS NOT FOUND TO BE DELETED" << endl << endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
		}
	}


void employee_menu()                                                                                           //menu function
{
	
	int i,n,ch;
	while(1)
	{
	system("cls");
	cout<<"\t\t\t\t\t\t\t\t\t\t\tEMPLOYEE  MENU\n\t\t\t\t\t\t\t\t\t\t\t YOU CAN WORK NOW "<<endl;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t[1]Add New customer\n\n\t\t\t\t\t\t\t\t\t\t\t[2]Display All customer\n\n\t\t\t\t\t\t\t\t\t\t\t[3]Modify a customer\n\n\t\t\t\t\t\t\t\t\t\t\t[4]Delete a customer\n\n\t\t\t\t\t\t\t\t\t\t\t[5]Add New Loan\n\n\t\t\t\t\t\t\t\t\t\t\t[6]Add New FD\n\n\t\t\t\t\t\t\t\t\t\t\t[0]Exit"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE OPTION YOU NEED TO DO:     ";
	cin>>ch;
	switch(ch)
	{
		
		case 1:
			addCustomer();
			break;
			
		case 2:
			readCustomer();
			break;
			
		case 3:
			modifycustomer();
			break;
			
		case 4:
			deletecustomer();
			break;
			
		case 5:
			apply_loan();
			break;
			
		case 6:
			apply_fd();
			break;
			
		
			
		case 0:
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
			cout<<"\t\t\t\t\t\t\t\t\t\t\tTHANK YOU !!";
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\t============================================="<<endl;
			return;
			
		default:
		    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
			red();
			cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE CORRECT OPTION"<<endl;
			reset();
			cout<<"\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
			
	}
	cout<<"\t\t\t\t\t\t\t\t\t\t\t-------------------------------------------------------"<<endl;
	system("pause");
	}
}

