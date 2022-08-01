
class Bankdata                                                             //class creation
{
protected:
	char name[20];
	int age;
	char occupation[20];
	char address[50];
	char dob[15];
	char phn_no[12];
	int acc_no;
	float total_balance;

public:
	
	int phnvalidate(char *phn_no)                                           //function to check whether the phone number is valid or not
	{
		
		Bankdata obj;                                                       //object creation
		ifstream f("bankdatabase.dat", ios::in | ios::binary);             //opening binary file in read mode
		while (f.read((char *)&obj, sizeof(obj)))
		{
			if (!strcmp(obj.phn_no, phn_no))                               // if the contact is same as in the file return 0
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\t\tCONTACT ALREADY EXIST!" << endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tENTER ANOTHER CONTACT:";
				cin.getline(phn_no, 11);
				f.close();
				return 0;
			}
		}
		f.close();
		return 1;                                                          // else return 1
	}
	

	int validateinitial()                                                  // function to check whether the initial amount is above 5000
	{
		
		cin >> total_balance;
		while (total_balance < 5000)
		{
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tENTER INITIAL AMOUNT FROM 5000!";
			reset();
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tENTER THE AMOUNT AGAIN:";
			cin >> total_balance;
		}
		return total_balance;
	}
	
	
	int agevalidate()                                                      // function to check whether the customer age is above 18 and below 100
	{
		
		cin >> age;
		while (age < 18 || age > 100)
		{
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tINVALID AGE!!!";
			reset();
			cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tENTER AGE AGAIN:";
			cin >> age;
		}
		return age;
	}


	void generate(int l, int r, int count)                                 // function to generate random account number to the customer
	{
		
		acc_no = (rand() % (r - l + 1)) + l; 
		cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tYOUR ACCOUNT NUMBER IS ";
		yellow();                                                           //sets the account no colour to yellow
		cout << acc_no << endl;
		reset();                                                           // resets to the default colour
		cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	
	
	void getdata()                                                          //function to get the data from the customer
	{
		
		
		fflush(stdin);                                                      //clears input buffer
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER YOUR NAME:";
		cin.getline(name, 20);                                             //gets space also as input
		fflush(stdin);
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER YOUR DATE OF BIRTH:";
		cin.getline(dob, 15);
		fflush(stdin);
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER YOUR AGE:";
		age = agevalidate();
		fflush(stdin);
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER YOUR OCCUPATION:";
		cin.getline(occupation, 20);
		fflush(stdin);
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER YOUR ADDRESS:";
		cin.getline(address, 50);
		fflush(stdin);
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER YOUR MOBILE NUMBER:";
		cin.getline(phn_no, 11);
		do                                                                    //loop to check the phone number is already exist in the file or not
		{
			if (phnvalidate(phn_no))
			break;
		} while (1);
		fflush(stdin);                                                         // clears input buffer
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER INITIAL AMOUNT(FROM 5000)";
		total_balance = validateinitial();                                     //the initial amount is checked(should be greater than 5000)

		int l = 10031000, r = 10031999, count = 1;
		srand(time(0));                                                       //gets random number
		generate(l, r, count);                                                //generates the account number for the customer
	}
	
	
	void get_and_create()                                                       //create the file
	{
		
		int ch;
		Bankdata b;                                                             //object creation for class Bankdata
		ofstream myfile;                                                        // myfile object is created for ofstream class
		ofstream txt("account_number.txt", ios::app);                           //the file is opened in append mode
		myfile.open("bankdatabase.dat", ios::app | ios::out | ios::binary);

		if (!myfile)                                                            //if the  file is not opened
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR............" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
			do
			{
				b.getdata();                                                      //gets the details from the customer
				txt << b.acc_no <<endl<< b.name << endl;                                //stores the acc no and customer name in text file for reference
				                              
				cout << "\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tPLEASE ENTER 1 TO PROCEED";
				cin >> ch;
			} while (ch != 1);
			myfile.write((char *)&b, sizeof(b));				//the details are stored in binary file
		}
		myfile.close();                                                            //closing the binary file
		txt.close();                                                               //closing the txt file
	}
	
	
	int getaccno()
	{
		
		return acc_no;                                                            //gives the acc no of the user
	}

	void putdata()                                                                //display details
	{
		
		cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tDISPLAYING DETAILS " << endl<< endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tACCOUNT NUMBER: " << acc_no << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tNAME: " << name << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tDATE OF BIRTH:" << dob << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tAGE: " << age << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tOCCUPATION:" << occupation << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tADDRESS: " << address << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tMOBILE NUMBER:" << phn_no << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tINITIAL AMOUNT:" << total_balance << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl;
	}


	void read_details()                                                                      //read the file
	{
		
		ifstream search;									                            	 //ifstream object
		search.open("bankdatabase.dat", ios::binary | ios::in);                              //open the file in read mode
		Bankdata b2;                                                                        //object creation
		long pos;
		char found = 'f';
		if (!search)                                                                         //if there is no file
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tTHERE IS SOME KIND OF SERVER ERROR.................." << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\tENTER YOUR ACCOUNT NUMBER: " ;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cin >> acc_no;

			search.seekg(0);                                                                     //search the current pointer
			while (!search.eof())                                                                //true untill end of file is reached
			{
				pos = search.tellg();				                                            //gives the current pointer position
				search.read((char *)&b2, sizeof(b2));                                           //read the data
				if (b2.getaccno() == acc_no)		                                            //if input matchs with this account number
				{

					b2.putdata();                                                               //display the data
					search.seekg(pos);                                                          //search for the position and display it
					found = 't';
					break;
				}
			}
			if (found == 'f')
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\t\tACCOUNT NUMBER NOT FOUND IN THE BANK!!" << endl<< endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
			search.close();                                                                         //close the file
		}
	}


	float get_balance()
	{
		
		return total_balance;                                                                        //returns the total balance 
	}
	
	
	float withdrawal(float amount)
	{

		total_balance = total_balance - amount;                                                      //subtracts the withdrawed money from the total balance
		return total_balance;
	}
	
	
	float deposited(float amount)
	{

		total_balance = total_balance + amount;                                                         //adds the deposited money to the total balance
		return total_balance;
	}
	
	
	void dispbalance()                                                                                  //displays the  current balance 
	{
		
		cout << "\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tACCOUNT HOLDER NAME:" << name << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tACCOUNT NUMBER:" << acc_no << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tBALANCE:\t" << total_balance << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl;
	}
	
	
	void withdrawl()                                                                                //function to perform operation if the user want to withdraw money from their account
	{
		
		float wdmoney;
		Bankdata b;                                                                                 //object creation
		int check = 0;
		fstream wd;                                                                                  //object for fstream class
		wd.open("bankdatabase.dat", ios::in | ios::out | ios::binary);                               //the binary file is opened in both read and write mode
		if (!wd)                                                                                     //if the file is not created or error in opening
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\t\t\t\t\t\t\t\t\t\t\tERROR!!IN THE SERVER........................................" << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER ACCOUNT NUMBER:";
			cin >> acc_no;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER AMOUNT TO BE WITHDRAWED:";
			cin >> wdmoney;
			while ((check == 0) && wd.read((char *)&b, sizeof(b)))
			{
				if (acc_no == b.getaccno())                                                             //if the acc no entered now is equal to the acc no in the file
				{

					b.withdrawal(wdmoney);                                                              //the money is subtracted
					wd.seekp((int)wd.tellg() - sizeof(b), ios::beg);
					wd.write((char *)&b, sizeof(b));
					check++;                                                                           //if money is withdrawed check is incremented
				}
			}
			if (check == 1)                                                                             //if acc no found and money withdrawed
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n\t\t\t\t\t\t\t\t\t\t\tMONEY IS WITHDRAWED SUCCESSFULLY!!!\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n";
			}
			else
			{
				red();
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n\t\t\t\t\t\t\t\t\t\t\tINVALID ACCOUNT NUMBER!!!\n\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl;
				reset();
			}
			wd.close();                                                                                 // closing the file
		}
	}
	
	
	void deposit()                                                                                     //function to perform operation if the customer needs to deposit amount
	{
		
		
		Bankdata b1;                                                                                  //object creation
		float amounts;
		int check1 = 0;
		fstream dep;                                                                                  //object for fstream class is created
		dep.open("bankdatabase.dat", ios::out | ios::in | ios::binary);                             //the binary file is opened in read and write mode
		if (!dep)                                                                                   // if the file is not created and error in opening the file
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tERROR!!IN THE SERVER...................................." << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER THE ACCOUNT NUMBER TO DEPOSIT:";
			cin >> acc_no;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER AMOUNT TO BE DEPOSITED:";
			cin >> amounts;
			while ((check1 == 0) && dep.read((char *)&b1, sizeof(b1)))
			{
				if (acc_no == b1.getaccno())                                                             //if the acc no entered now is equal to the acc no in the file
				{
 
					b1.deposited(amounts);                                                             //the money is added
					dep.seekp((int)dep.tellg() - sizeof(b1), ios::beg);
					dep.write((char *)&b1, sizeof(b1));
					check1++;                                                                         //if money is deposited check1 is incremented
				}
			}
			if (check1 == 1)                                                                         //if acc no is found and the money is deposited
			{
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n\t\t\t\t\t\t\t\t\t\t\tMONEY DEPOSITED SUCCESSFULLY!!\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n";
			}
			else
			{
				red();
				cout << "\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n\t\t\t\t\t\t\t\t\t\t\tINVALID ACCOUNT NUMBER\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n";
				reset();
			}
			dep.close();                                                                          //closing the file
		}
	}


	Bankdata &modifydata(Bankdata &bank)                                                          //function to modify the details of user
	{
		
		int ch, f;
		char phno[11];
		while (1)
		{
			system("cls"); //clears the output screen
			cout << "\t\t\t\t\t\t\t\t\t\t\tMODIFY MENU" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl;
			red(); // sets the font colour to red
			cout << "\n| Please enter the correct field name to modify|";
			reset(); //resets the default font colour
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t[1]Name\n\n\t\t\t\t\t\t\t\t\t\t\t[2]DOB\n\n\t\t\t\t\t\t\t\t\t\t\t[3]Age\n\n\t\t\t\t\t\t\t\t\t\t\t[4]Position\n\n\t\t\t\t\t\t\t\t\t\t\t[5]Address\n\n\t\t\t\t\t\t\t\t\t\t\t[6]Contact\n\n\t\t\t\t\t\t\t\t\t\t\t[7]Exit" << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE OPTION YOU NEED TO MODIFY:     ";
			cin >> ch;

			switch (ch)
			{
			case 1:
				fflush(stdin); // clears the input buffer
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tOLD NAME:" << bank.name << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW NAME:";
				cin.getline(bank.name, 50);
				break;
			case 2:
				fflush(stdin);
				cout << "\n\t\t\t\t\t\t\t\t\t\t\tOLD DOB:" << bank.dob << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW DOB(DD/MM/YYYY):";
				cin.getline(bank.dob, 11);
				break;
			case 3:
				fflush(stdin);
				cout << "\t\t\t\t\t\t\t\t\t\t\tOLD AGE:" << bank.age << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW AGE:";
				bank.age = bank.agevalidate();
				break;
			case 4:
				fflush(stdin);
				cout << "\t\t\t\t\t\t\t\t\t\t\tOLD OCUUPATION:" << bank.occupation << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW OCCUPATION:";
				cin.getline(bank.occupation, 30);
				break;
			case 5:
				fflush(stdin);
				cout << "\t\t\t\t\t\t\t\t\t\t\tOLD ADDRESS:" << bank.address << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE NEW ADDRESS:";
				cin.getline(bank.address, 100);
				break;
			case 6:
				fflush(stdin);
				cout << "\t\t\t\t\t\t\t\t\t\t\tOld Contact: +91" << bank.phn_no << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\tEnter the New Contact:(+91)";
				cin.getline(phno, 11);
				do
				{
					if (phnvalidate(phno))                                                         //this function returns 1 if the phone number is not already existing in the file
					{
						strcpy(bank.phn_no, phno);
						break;
					}
				} while (1);
				break;
			case 7:
				return bank;
			default:
				cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t=============================" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE CORRECT OPTION" << endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t\t=============================" << endl;
			}
			system("pause");
		}
	}
	
	
	void modifyinfo()                                                                                       //function to modify the details
	{
		
		int pos, flag;
		
		Bankdata bank;                                                                                     //object creation
		fstream modify;                                                                                    //object is created for fstream class
		modify.open("bankdatabase.dat", ios::in | ios::binary | ios::out);                               //opens the file in read and write mode
		if (!modify)                                                                                     //if the file is not created or error in opening the file
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();                                                                                        //sets the font colour to red
			cout << "\t\t\t\t\t\t\t\t\t\t\tERROR!!IN THE SERVER...................................." << endl;
			reset();                                                                                       //resets to default font colour 
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\tENTER ACCOUNT NUMBER TO BE MODIFIED:";
		cin >> acc_no;
		while (!modify.eof())
		{
			pos = modify.tellg();                                                                                //tells the current position
			modify.read((char *)&bank, sizeof(bank));
			if (modify)
			{
				if (bank.getaccno() == acc_no)                                                                    //if input is equal to the acc no in the file
				{
					bank = modifydata(bank); 
					modify.seekp(pos);
					modify.write((char *)&bank, sizeof(bank));                                                     //the data is modified
					flag = 1; 
					break;
				}
				else
					flag = 0;
			}
		}
		modify.close();
		if (flag == 1) //if the acc no found and modified
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t===================================================================\n\t\t\t\t\t\t\t\t\t\t\tMODIFICATION OF THE ACCOUNT (account no:" << acc_no << ") IS DONE SUCESSFULLY\n\t\t\t\t\t\t\t\t\t\t\t===================================================================\n";
		else
		{
			red();
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n\t\t\t\t\t\t\t\t\t\t\tRECORD NOT FOUND !!\n\t\t\t\t\t\t\t\t\t\t\t=============================================\n";
			reset();
		}
	}
}


	void checkbalance()                                                                                                 //function to check the balance of the account holder
	{
		
		ifstream balance;										                                                       //ifstream object
		balance.open("bankdatabase.dat", ios::binary | ios::in);                                                      //open the file in read mode
		Bankdata b2;
		long pos;
		char found = 'f';
		if (!balance)                                                                                                //if there is no file
		{
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t***********************************************************************************************************" << endl;
			red();
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tERROR!!IN THE SERVER...................................." << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t***********************************************************************************************************" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\tENTER YOUR ACCOUNT NUMBER: ";
			cin >> acc_no;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			

			balance.seekg(0);                                                                                   //balance the current pointer
			while (!balance.eof())
			{
				pos = balance.tellg();				                                                           //gives the current pointer position
				balance.read((char *)&b2, sizeof(b2));                                                        //read the data
				if (b2.getaccno() == acc_no)		                                                          //if input matches with ths acc number
				{

					b2.dispbalance();
					balance.seekg(pos);                                                                      //search for the position and display it
					found = 't';
					break;
				}
			}
			if (found == 'f')                                                                                 //if the acc no is not found in the file
			{
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				red();
				cout << "\t\t\t\t\t\t\t\t\t\t\tACCOUNT NUMBER NOT FOUND IN THE BANK!!" << endl<< endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
			balance.close(); //close the file
		}
	}


	void delacc()                                                                                           //function to delete the account
	{
		
		int pos, flag = 0;
		Bankdata b3;                                                                                        //object creation
		ifstream org;										                                                //ifstream object
		org.open("bankdatabase.dat", ios::in | ios::binary);                                               //open the old file in read mode
		ofstream temp;										                                              //ofstream object
		temp.open("temp.dat", ios::out | ios::binary);		                                              //open temp file in write mode

		if (!org)                                                                                        //if there is no file
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
			red();
			cout << "\n\t\t\t\t\t\t\t\t\t\t\tERROR!!IN THE SERVER...................................." << endl;
			reset();
			cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t\t\t\tENTER THE ACCOUNT NUMBER TO BE DELETED:";                          //get the acc number to be deleted
			cin >> acc_no;
			cout << "\n\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			
			while (!org.eof())
			{
				org.read((char *)&b3, sizeof(b3));
				if (org) // if(org)checks the buffer record in the file
				{
					if (b3.getaccno() == acc_no) //comparing the roll no with roll no of record to be deleted
					{
						flag = 1;
						cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
						cout << "\t\t\t\t\t\t\t\t\t\t\tTHE DELETED RECORD IS: " << endl;
						b3.putdata(); // display the record
						cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					}
					else
					{
						temp.write((char *)&b3, sizeof(b3));                                                  // copy the record of "bankdatbase" file to "temp" file                                       
						                                    
					}
				}
			}
			temp.close();                                                                                    //close the files
			org.close();
			remove("bankdatabase.dat");				                                                         // delete the old file
			rename("temp.dat", "bankdatabase.dat");                                                          // rename new file to the older file

			if (flag == 1) //if the acc no is found and deleted
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
				cout << "\t\t\t\t\t\t\t\t\t\t\tRECORD IS NOT FOUND TO BE DELETED" << endl
					 << endl;
				reset();
				cout << "\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
		}
	}
};



class account : public Bankdata
{
	
public:
	
	void display()                                                                                       //function to display the details of the customer
	{
		cout << "\n\t\t\t\t\t\t\t\t\t\t\t================================================" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tACCOUNT NUMBER: " << acc_no << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tUSER NAME:" << name << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tDOB:" << dob << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tAGE:" << age << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tOCCUPATION:" << occupation << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tADDRESS:" << address << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tCONTACT: +91" << phn_no << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\tBALANCE:" << total_balance << endl;
	}
};


void display_account_details()                                                                       //function to search and display the details of the customer
{
	
	int n=0;
	account a;
	cout << "\n\n\t\t\t\t\t\t\t\t\t\t\tACCOUNT DETAILS" << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t================================================" << endl;
	ifstream f("bankdatabase.dat", ios::in | ios::binary);                                           //file is opened in read mode
	if(!f)                                                                                          //if the file is not created or error in opening the file
	{
	cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
	red();
	cout << "\n\t\t\t\t\t\t\t\t\t\t\tTHERE ARE NO RECORD IN THE BANK..................................." << endl;
	reset();
	cout << "\t\t\t\t\t\t\t\t\t\t\t*****************************************************************************************************" << endl;
    }
   else
    {
	while (f.read((char *)&a, sizeof(a)))
	{
	n=1;
	a.display();
    }
    f.close();
    }
if(n==0)                                                                                          //if there is no records in the file
	{
		cout<<"\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t\tTHERE ARE NO RECORDS IN THE BANK"<<endl;
		cout<<"\t\t\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	} 
}
