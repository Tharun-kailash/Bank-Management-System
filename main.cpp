#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstring>
#include<time.h>
#include<cstdio>

using namespace std;
void reset () 
{
  system("color 00");                                                                              //sets the colour to default colour(black)
}

void red ()
 {
  system("color 04");                                                                              //sets the colour to red
}

void yellow() 
{
  system("color 06");                                                                             //sets the colour to yellow
}


#include "PROJECT 1.cpp"                                                                           //linking the other files 
#include "Loan.cpp"
#include "fd.cpp"
#include "manager_menu.cpp"
#include "Employee_menu.cpp"
#include "date.cpp"
 
void newuser(Bankdata &cus)                                                                       //function to perform the operations of a new customer
{
	
	int ch;
	do
	{
		system("cls");                                                                          //clears the output screen before new user menu 
	    cout <<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tWELCOME TO THE NEW USER MENU"<<endl;
	    cout <<"\t\t\t\t\t\t\t\t\t\t\t===========================================================" << endl<<endl;
	    cout <<"\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tYOU ARE JUST A STEP BEFORE ONLINE BANKING!!!!!!!" << endl<<endl;
	    cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl;
	    red();                                                                                  //sets the font colour to red 
		cout<<"\t\t\t\t\t\t\t\t\t\t\t|1.Click the option Create New Account if you are a above 18 and not created an account|\n\t\t\t\t\t\t\t\t\t\t\t|2.Click the option Loan Form if you want apply for loan                               |\n\t\t\t\t\t\t\t\t\t\t\t|3.Click the option FD form if you want to deposit amount                              |\n\n";
		cout<<"\n\t\t\t\t\t\t\t\t\t\t\t|NOTE: Please enter your correct address so that the kit which contains[ATM card, check book,\n\t\t\t\t\t\t\t\t\t\t\tnetbanking pin] will be delivered to your address because of pandemic|";
		reset();                                                                               // resets the default colour
    	cout <<"\t\t\t\t\t\t\t\t\t\t\t=======================================================" << endl<<endl;
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t[1]Create New Account\n\n\t\t\t\t\t\t\t\t\t\t\t[2]Loan Form\n\n\t\t\t\t\t\t\t\t\t\t\t[3]FD Form\n\n\t\t\t\t\t\t\t\t\t\t\t[0]Exit"<<endl;
    	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tENTER THE OPTION TOU ARE SEARCHING FOR   ";
    	cin>>ch;
    	switch(ch)
    	{
        	case 0:
        	return;
            break;
                      
        	case 1:
        	cus.get_and_create();                                                            //gets the details from the user and writes into the file
        	break;
        	
			case 2:
        	apply_loan();                                                                    //gets the details from the user and writes into the file
        	break;
        	
			case 3:
        	apply_fd();                                                                         //gets the details from the user and writes into the file
        	break;
		}
		system("pause");
	}while(1);
		
}



void olduser(Bankdata &cus)                                                                     //function to perform the operations of old user
{  

	int ch;
	do
	{
		system("cls");                                                                         //clears the output screen

		cout <<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tWELCOME TO EXISITING USER MENU"<<endl;
    	cout <<"\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl<<endl;
    	red();                                                                                 //sets the font colour to red
		cout <<"\t\t\t\t\t\t\t\t\t\t\t|1.Click the option View Details to view your details                |\n\t\t\t\t\t\t\t\t\t\t\t|2.Click the option Deposit Amount to deposit your amount            |\n\t\t\t\t\t\t\t\t\t\t\t|3.Click the option Withdraw Amount to withdraw your amount          |\n\t\t\t\t\t\t\t\t\t\t\t|4.Click the option Modify Details and enter the field name to modify|\n\t\t\t\t\t\t\t\t\t\t\t|5.Click the option Balance Enquiry to check your balance            |" << endl<<endl;
		reset();                                                                              //resets the default colour
		cout <<"\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl<<endl;
    	cout<<"\t\t\t\t\t\t\t\t\t\t\t          __________________________"<<endl;
        cout << "\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[1]View Details\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[2]Deposit Amount\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[3]Withdraw Amount\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[4]MODIFY DETAILS\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[5]BALANCE ENQUIRY\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[6]DELETE ACCOUNT\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[0]EXIT\n"<<endl;
        cout<<"\t\t\t\t\t\t\t\t\t\t\t          __________________________"<<endl;
		cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tHOW CAN I HELP YOU???\n\n\t\t\t\t\t\t\t\t\t\tPLEASE SELECT YOUR NEED BY ENTERING THE RESPECTIVE OPTIONS!!!!!!    ";
        cin>>ch;
        switch(ch)
        {
        	case 0:
        	return;
            break;

        	case 1:
        	cus.read_details();                                                              //search and display the specific user details after entering acc no
        	break;

        	case 2:
        	cus.deposit();                                                                   // the amount is added to the main balance
        	break;

        	case 3: 
        	cus.withdrawl();                                                                // the amount is subtracted from the main menu
        	break;

        	case 4:
        	cus.modifyinfo();                                                              // modifies the details of user based on the field name given
        	break;

        	case 5:
        	cus.checkbalance();                                                            //displays the current balance of the customer
        	break;
        	
        	case 6:
        	cus.delacc();                                                                 // closing an account
        	break;
        	
		}
		system("pause");
	}while(1);
}


void usermenu()                                                                         //function to perform the operation of a user
{
	
	int ch;
	Bankdata cus;                                                                        //object creation
	do
	{
		
		system("cls");                                                                   //clears the output screen
    	cout <<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tWELCOME  TO  USER   MENU"<<endl;
    	cout <<"\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl<<endl;
    	red();                                                                           //sets the font colour to red
		cout<<"\t\t\t\t\t\t\t\t\t\t\t|1.Click the option New User to fill the details of your's|\n\t\t\t\t\t\t\t\t\t\t\t|2.Click the option Old User to proceed further           |\n";
		reset();                                                                        //resets to the default colour
		cout <<"\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl<<endl;
    	cout<<"\t\t\t\t\t\t\t\t\t\t\t          __________________________"<<endl;
    	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t[1]New User\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[2]Old User\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[0]Exit"<<endl;
    	cout<<"\t\t\t\t\t\t\t\t\t\t\t          __________________________"<<endl;
    	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tHOW CAN I HELP YOU???\n\n\t\t\t\t\t\t\t\t\t\tPLEASE SELECT YOUR NEED BY ENTERING THE RESPECTIVE OPTIONS!!!!!!    ";
    	cin >> ch;
    	switch(ch)
    	{
    		case 1:
    			newuser(cus);                                                         //displays the menu for new customer
    			break;
    			
    		case 2:
    			olduser(cus);                                                          //displays the menu for existing customer
    			break;
    			
    		case 0:
    			return;
    			
    		default:
    			cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
				red();
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE CORRECT OPTION"<<endl;
				reset();
				cout<<"\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
		}
		
		system("pause");
	}while(1);
	
}



void officermenu()                                                                        //function to display the officer menu
{
	
	int ch;
	do
	{
		system("cls"); //clears the output screen
		cout <<"\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tWELCOME  TO  STAFF   MENU"<<endl;
    	cout <<"\t\t\t\t\t\t\t\t\t\t\t=============================================" << endl<<endl;
    	cout<<"\t\t\t\t\t\t\t\t\t\t\t          __________________________"<<endl;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[1] Manager\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[2] Employee\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t[0] Exit\n";
		cout<<"\t\t\t\t\t\t\t\t\t\t\t          __________________________"<<endl;
    	cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tHOW CAN I HELP YOU???\n\n\t\t\t\t\t\t\t\t\t\tPLEASE SELECT YOUR NEED BY ENTERING THE RESPECTIVE OPTIONS!!!!!!    ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				manager_menu();                                                          // displays the manager menu
				break;
			case 2:
				employee_menu();                                                          //displays the employee menu
				break;
			case 0:
				return;
			default:
				cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
				red();
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE CORRECT OPTION"<<endl;
				reset();
				cout<<"\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
		}
		system("pause");
	}while(1);
}

void mainmenu()
{
	int ch;
	do
	{
	   
	    cout << "*******************************************************************************************************************************************************************************************************************"<<endl;
		cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t*****************************************************************" << endl;
		yellow();                                                                                    //sets the font colour to yellow
    	cout << "\t\t\t\t\t\t\t\t\t\t\t        BANK OF COIMBATORE" << endl;
		reset();                                                                                      //resets to the default colour 
    	cout << "\t\t\t\t\t\t\t\t\t*****************************************************************" << endl<< endl;
    	cout << "\t\t\t\t\t\t\t\t\t================================================================="<<endl;
    	cout << "\t\t\t\t\t\t\t\t\t\t\t        23,CITY ROAD,\n\t\t\t\t\t\t\t\t\t\t\t        COIMBATORE"<<endl;
    	cout << "\t\t\t\t\t\t\t\t\t=================================================================="<<endl<<endl<<endl;
    	cout << "\t\t\t\t\t\t\t\t\t\t\t 25 YEARS OF EXCELLENCE!!!!!!!"<<endl;
		cout << "\t\t\t\t\t\t\t\t\t___________________________________________________________________"<<endl<<endl<<endl;
    	cout<<"\t\t\t\t\t\t\t\t\t\t\t __________________________"<<endl;
	    cout<<"\t\t\t\t\t\t\t\t\t\t\t| BANKING AT YOUR HAND !!! |"<<endl;
	    cout<<"\t\t\t\t\t\t\t\t\t\t\t|__________________________|"<<endl;
    	cout<<"\t\t\t\t\t\t\t\t\t\t\t      HOME OF SERVICES "<<endl;
    	cout << "\t\t\t\t\t\t\t\t\t___________________________________________________________________"<<endl<<endl<<endl;
		red();                                                                                       //sets the font colour to red
		cout<<"\t\t\t\t\t\t\t\t\t|1.Click the option USER to fullfil your needs              |\n\t\t\t\t\t\t\t\t\t|2.Click the option OFFICER if you are a staff of this bank |\n";
		reset();                                                                                    // resets the default font colour
		cout << "\t\t\t\t\t\t\t\t\t___________________________________________________________________"<<endl<<endl<<endl;
    	cout <<"\t\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl<< endl;
    	cout <<"\t\t\t\t\t\t\t\t\t\t\t\t[1]USER\n\t\t\t\t\t\t\t\t\t\t\t\t[2]OFFICER\n\t\t\t\t\t\t\t\t\t\t\t\t[0]Exit"<<endl<<endl<<endl;
    	cout << "\t\t\t\t\t\t\t\t\tENTER OPTION FOR YOUR NEED  ";
    	cin >> ch;    
    	switch(ch)
    	{
    	
    		case 0:
    			return;
    			break;
    			
    		case 1:
				usermenu();                                                                   //displays the menu for user
					break;
					
			case 2:
				officermenu();                                                                  //displays the menu for officer
				break;
				
				
			default:
				cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
				red();
				cout<<"\t\t\t\t\t\t\t\t\t\t\tENTER THE CORRECT OPTION"<<endl;
				reset();
				cout<<"\t\t\t\t\t\t\t\t\t\t\t============================="<<endl;
		}
		
    	system("pause");
    	system("cls");    
	}while(1);
}


int main()
{
	mainmenu();
}
