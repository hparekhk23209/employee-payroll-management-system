#include <iostream>
using namespace std;

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "staff.h"
#include "company.h"
#include "peyroll.h"


class menu
{
public:
    staff s;
    company c;
    payroll p;

    void mainmenu()
    {
        int ch;
        char x;
        do
        {
            cout << "\n\n\n\n\n\t\t\t\t\t &*&*&*&*&*&***MAIN MENU***&*&*&*&*&*&";
            cout << "\n\n\t\t\t\t\t\t 1.Add Employee Details ";
            cout << "\n\n\t\t\t\t\t\t 2.Display Employee Details ";
            cout << "\n\n\t\t\t\t\t\t 3.Display Company Details ";
            cout << "\n\n\t\t\t\t\t\t 4.Search Employee Details ";
            cout << "\n\n\t\t\t\t\t\t 5.Generate Payroll ";
            cout << "\n\n\t\t\t\t\t\t 6.Modify Employee Details";
            cout << "\n\n\t\t\t\t\t\t 7.Delete Employee Details";
            cout << "\n\n\t\t\t\t\t\t 0.Exit ";

            cout << "\n\n\n\t\t\t\t Enter your choice : ";
            cin >> ch;

            switch (ch)
            {
            case 1:
              do
            {
                
                s.add(); 
                cout << "\n\n\t\t\t Add Another Employee Record Press  (Y, N) : ";
                cin >> x; 
            } while (x == 'y' || x == 'Y');
            // s.add();
              
            break;
            case 2:
                s.Display();
                break;

            case 3:
                c.display();
                break;

            case 4:
                s.search();
                break;

            case 5:
                p.genPayroll();
                break;

            case 6:
                s.modify();
                break;

            case 7:
                s.Delete();
                break;
            
                

            case 0:
                cout << "\n\n\n\n\t\t\t\t\t:) :) :) :) :) :) :) :) :) :) :) :) :) :) :)";
                cout << "\n\t\t\t\t\t;)                                        ;)";
                cout << "\n\t\t\t\t\t;)     Thank you for your visit........   ;)";
                cout << "\n\t\t\t\t\t;)                Exited...               ;)";
                cout << "\n\t\t\t\t\t;)                                        ;)";
                cout << "\n\t\t\t\t\t:) :) :) :) :) :) :) :) :) :) :) :) :) :) :)";
                break;
            }
        } while (ch != 0);
    }
};

void staff ::add()
{
    system("cls");
    empID = 0;
    std::fstream file;
    file.open("employee_Record.txt");
    while (file)                  
  //  file >> empID >> fname >> lname >> /*g >> */age >> addr >> c >> cont >>  qual >> exp  >> no_of_WDays  >> ds;
    file >> empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >> exp  >> no_of_WDays  >> ds;

    file.close();                                                                                                                                                                 // closes the file
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl; // displays "----------"
    cout << "------------------------------------------------------------- Employee Insert Data -----------------------------------------------------------------" << endl;        // displays"------ Patient Insert Data------"
    cout << "\n\t Enter Employees Details...";
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n\t Enter Employee Id            : ";
    cin >> empID;

    cout << "\n\t Enter Employee Fname         : ";
    cin >> fname;

    cout << "\n\t Enter Employee Lname         : ";
    cin >> lname;

   cout << "\n\t Enter Employee Gender        : ";
    cin >> g;
    //   cout << "\n\t Renter Employee Gender       : ";
    //     cin >> g;
    //  while (g != "F" && g != "M")
    while ((strcmp(g, "f") != 0) && (strcmp(g, "m") != 0))
    {
        cout << "\n\t Renter Employee Gender       : ";
        cin >> g;
    }

    cout << "\n\t Enter Employee Age           : ";
    cin >> age;
    if (age >= 70 || age < 18)
    {
        cout << "\n\t Sorry !!! you can't get employement...";
        // exit(1);
    }

    cout << "\n\t Enter Employee Address       : ";
    cin >> addr;

    cout << "\n\t Enter Employee City          : ";
    cin >> c;

    cout << "\n\t Enter Employee Contact       : ";
    cin >> cont;
    // while (strlen(cont) > 10 || strlen(cont) < 10)
    // {
    //     cout << "\n\t Re-enter Employee Contact    : ";
    //     cin >> cont;
    // }

    cout << "\n\t Enter Employee Qualification : ";
    cin >> qual;

    cout << "\n\t Enter Employee Experience    : ";
    cin >> exp;

    cout << "\n\t Enter Employee Working Days  : ";
    cin >> no_of_WDays;
    cout << "\n---------------------------------------------------";
    cout << "\n\n\t Select Designation From Given List...";
    cout << "\n\t -> Manager";
    cout << "\n\t -> Employee";
    cout << "\n\t -> Worker";
    cout << "\n---------------------------------------------------";

    cout << "\n\t Enter Employee Designation   : ";
    cin >> ds;

    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";

    empID++; // increments patient's id by 1
    file.open("employee_Record.txt", ios::app | ios::out);
    file <<endl<< empID <<endl<< fname <<endl<< lname <<endl<< g <<endl<< age <<endl<< addr <<endl<< c <<endl<< cont <<endl<<  qual <<endl<< exp  <<endl<< no_of_WDays  <<endl<< ds;

    // file << empID << endl
    //      << age << endl
    //      << exp << endl
    //      << no_of_WDays << endl
    //      << sal << endl
    //      << fname[30] << endl
    //      << lname[30] << endl
    //      << g[6] << endl
    //      << addr[70] << endl
    //      << c[50] << endl
    //      << qual[80] << endl
    //      << ds[30] << endl
    //      << cont[10];
    file.close();     
}

void staff ::Display()
{
   
    system("cls");

    int total = 0;

    std::fstream file;

    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------- Employee Record Data -----------------------------------------------------------------" << endl;

    file.open("employee_Record.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";

        file.close();
    }
    else
    {
    file >> empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >>exp  >> ds;
        // cout << "\n -----------------------------------------------------------------------------------------------------------------------------------------------";
        // cout << "\n  empID || age || exp || no_of_WDays || sal || fname[30] || lname[30] || g[6] || addr[70] || c[50] || qual[80] || ds[30] || cont[10] ";
while(file >> variable)
         {
            cout<<endl;
    cout << "\n\t Employee Id             : " << empID;
    cout << "\n\t Employee First Name     : " << fname;
    cout << "\n\t Employee Last Name      : " << lname;
     cout << "\n\t Employee Gender         : " << g;
    cout << "\n\t Employee Age            : " << age;
    cout << "\n\t Employee Address        : " << addr;
    cout << "\n\t Employee City           : " << c;
    cout << "\n\t Employee Contact        : " << cont;
    cout << "\n\t Employee Qualification  : " << qual;
    cout << "\n\t Employee Experience     : " << exp;
 //   cout << "\n\t Employee Designation    : " << ds;
        file >> empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >>exp  >> ds;
         }
            
    }
    file.close();

      /*  while(file >> variable)
        {
        cout << "\n";
        cout <<"\t"<< empID <<"\t"<< fname <<"\t"<< lname <<"\t"<< g <<"\t"<< age <<"\t"<< addr <<"\t"<< c <<"\t"<< cont <<"\t"<<  qual <<"\t"<<exp  <<"\t"<< ds;
        // cout <<" EMPLOYEE-"<< empID <<"\t"<< age <<"\t"<< exp <<"\t"<< sal <<"\t"<< fname <<"\t"<< lname <<"\t"<< g <<"\t\t"<< addr <<"\t\t"<< c <<"\t\t"<< qual <<"\t\t"<< ds <<"\t\t"<< cont;;
        file >> empID  >> fname 
         >> lname  >>  g
         >> age   >> addr >> c  >> cont  >> qual
         >> exp  >> ds;
  
        }
     
         
    }  file.close();*/
    //TO CLOSE THE FILE
    //WAIT FOR A USER INPUT TO CLOSE
    // cout << "\n\n\t Employee Details";
    // cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    // cout << "\n\t Employee Id             : " << empID;
    // cout << "\n\t Employee First Name     : " << fname;
    // cout << "\n\t Employee Last Name      : " << lname;
    // cout << "\n\t Employee Gender         : " << g;
    // cout << "\n\t Employee Age            : " << age;
    // cout << "\n\t Employee Address        : " << addr;
    // cout << "\n\t Employee City           : " << c;
    // cout << "\n\t Employee Contact        : " << cont;
    // cout << "\n\t Employee Qualification  : " << qual;
    // cout << "\n\t Employee Experience     : " << exp;
    // cout << "\n\t Employee Contact        : " << cont;
    // cout << "\n\t Employee Designation    : " << ds;
    // cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
//  getch(); 
}

void staff ::search()
{
        system("cls");

    fstream file;

    int checkId,x,found=0;
    string checkname;

	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------- Employee Search Data -----------------------------------------------------------------" << endl;
   
    file.open("employee_Record.txt", ios::in); 
    loop : 

	cout << "\n\t\t\t-| Press [1] for search by id |-"<<endl; 
    cout << "\t\t\t-| Press [2] for search by name |-"<<endl; 
    cout << "Enter your option : "<< endl; 
    cin >> x; 

	if(x==1)
    {
		cout << "\n\nEnter Employee\'s ID: EMPLOYEE-"; 
    	cin >> checkId;
	}
	
    else if(x==2){ 

		cout << "\n\nEnter Employee\'s name : "; 
    	cin >> checkname; 
	}

	else{
		cout << "\nInvalid Input.. Please Try Again.."; 
		goto loop;
	}
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... "; 
        file.close(); 
    }
    else
    {
    file >> empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >> exp   >> ds;

        while (!file.eof()) 
        {

            if (checkId == empID || checkname == fname) 
            {
            
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n\t Employee Id             : " << empID;
    cout << "\n\t Employee First Name     : " << fname;
    cout << "\n\t Employee Last Name      : " << lname;
    cout << "\n\t Employee Gender         : " << g;
    cout << "\n\t Employee Age            : " << age;
    cout << "\n\t Employee Address        : " << addr;
    cout << "\n\t Employee City           : " << c;
    cout << "\n\t Employee Contact        : " << cont;
    cout << "\n\t Employee Qualification  : " << qual;
    cout << "\n\t Employee Experience     : " << exp;
    cout << "\n\t Employee Contact        : " << cont;
   // cout << "\n\t Employee Designation    : " << ds;
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
             found ++;
                 enter();
                break;
            }

    file >> empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >> exp  >> ds;
        }
    
        if (!found)  
        {
            cout << "\n\n\tPatient\'s ID Not Found.. Please Try Again"; 
        }
    }
    file.close();


}

void staff :: enter()
{
    cout << "\n\nPress enter to go back: ";
    cin.get();
}
void company ::display()
{
        system("cls");

    Name = "HONESTY INFOTECH";
    regNo = "bh123BH45";
    cont = 7990289201;
    add = "RAJKOT - 360004, GUJARAT - INDIA.";
    TEmp = 200;

    cout << "\n\t Company Details...";
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n\t Company Name             : " << Name;
    cout << "\n\t ComapanyRegistration No. : " << regNo;
    cout << "\n\t Company Contact No.      : " << fixed << setprecision(0) <<cont;
    cout << "\n\t Company Address          : " << add;
    cout << "\n\t Company Total Employees  : " << TEmp;
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    getch();
}

void staff ::Delete()
{
 
    system("cls"); 

    int checkId;

  std::  fstream file, file1;

    int found = 0;
    
    cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;//delete -------'
    cout << "------------------------------------------------------------- Employee Delete Data -----------------------------------------------------------------" << endl;// delete ----- patient  data----
    file.open("employee_Record.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee\'s Id : EMPLOYEE-";
        cin >> checkId;

        file1.open("record.txt", ios::out);
    file >> empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >> exp  >> no_of_WDays  >> ds;
        while (!file.eof())
        {
            if (checkId != empID)
            {
     file <<endl<< empID <<endl<< fname <<endl<< lname <<endl<< g <<endl<< age <<endl<< addr <<endl<< c <<endl<< cont <<endl<<  qual <<endl<< exp   <<endl<< ds;
          }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data"; 
            }
    file >> empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >> exp  >> no_of_WDays  >> ds;
        }
        if (found == 0)
        {
            cout << "\n\nEmployee\'s ID Not Found.. Please Try Again";
        }

    } file1.close();
        file.close();
        remove("employee_Record.txt");
        rename("record.txt", "employee_Record.txt");
}

void payroll ::genPayroll()
{ 
    cout << "\n\t Enter Employees Details To Generate Payroll...";
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    cout << "\n\t Enter Employee Id            : ";
    cin >> empID;

    cout << "\n\t Enter Employee Full Name         : ";
    cin >> lastName;

    cout << "\n\t Enter Employee Contact       : ";
    cin >> contact;
    while (strlen(contact) > 10 || strlen(contact) < 10)
    {
        cout << "\n\t Re-enter Employee Contact    : ";
        cin >> contact;
    }

    cout << "\n\t Enter Employee Basic Salary        : ";
    cin >> bSalary;

    cout << "\n\t Enter Employee Number Of Leave          : ";
    cin >> leave;

    cout << "\n\t Enter Employee House Rent Allowance : ";
    cin >> hra;

    cout << "\n\t Enter Employee Transport Allowance    : ";
    cin >> ta;

    cout << "\n\t Enter Employee Extra Working Days  : ";
    cin >> extraDay;

    cout << "\n\t Enter Employee PF  : ";
    cin >> pf;

    cout << "\n\t Enter Employee Diductable Tax Amount  : ";
    cin >> da;

    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
    getch();

    double totalGrossSalary, perDaySalary, deductibleSalaryOfLeave, hraAmount, transpotationAmount, diductibleTexAmount, PFAmount,
     extraDayAmount, totalExtraSalary, totalDeductibleSalary;

    perDaySalary = bSalary / 22;

    extraDayAmount = (extraDay * (perDaySalary * 2));

    hraAmount = (bSalary * hra) / 100;

    transpotationAmount = (bSalary * ta) / 100;

    deductibleSalaryOfLeave = perDaySalary * leave;

    diductibleTexAmount = (bSalary * da) / 100;
    
    PFAmount = (bSalary * pf) / 100;

    totalExtraSalary = hraAmount + extraDayAmount + transpotationAmount;
    totalDeductibleSalary = deductibleSalaryOfLeave + diductibleTexAmount + PFAmount;

    totalGrossSalary = ((bSalary - totalDeductibleSalary) + totalExtraSalary);

    cout << "\n\t\t\t\t*************************************************************";
    cout << "\n\t\t\t\t*                   HONESTY INFOTECH                        *";
    cout << "\n\t\t\t\t*             -----------------------------                 *";
    cout << "\n\t\t\t\t*              <Payroll Management System>                  *";
    cout << "\n\t\t\t\t*************************************************************";
    cout << "\n\t\t\t\t Employee Id                             : " << empID;
    cout << "\n\t\t\t\t Employee Full Name                      : " << lastName;
    cout << "\n\t\t\t\t Employee Basic Salary                   : " << bSalary;
    cout << "\n\t\t\t\t Employee Contact Number                 : " << contact;
    cout << "\n\t\t\t\t Employee House Rent Allowance           : " << hraAmount;
    cout << "\n\t\t\t\t Employee Transportation Allowance       : " << transpotationAmount;
    cout << "\n\t\t\t\t Employee Extra working day Amount       : " << extraDayAmount;
    cout << "\n\t\t\t\t Employee Deductable Salary Of Leave(-)  : " << deductibleSalaryOfLeave;
    cout << "\n\t\t\t\t Employee Deductable PF Amount(-)        : " << PFAmount;
    cout << "\n\t\t\t\t Employee Deductable TaxAmount(-)        : " << diductibleTexAmount;
    cout << "\n\t\t\t\t Employee Total Extra Salary             : " << totalExtraSalary;
    cout << "\n\t\t\t\t Employee Total Deductable Salary        : " << totalDeductibleSalary;
    cout << "\n\t\t\t\t***************************************************************";
    cout << "\n\t\t\t\t*                   TOTAL GROSS SALARY                        *";
    cout << "\n\t\t\t\t*            --------------------------------                 *";
    cout << "\n\t\t\t\t*                      " << fixed << setprecision(0) << totalGrossSalary << "*";
    cout << "\n\t\t\t\t***************************************************************";
    getch();
}
void staff :: modify()
{
 system("cls");
    int checkId;
	int x, y, z;   
	int found = 0;

	std::fstream file, file1;
cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------- Employee Modify Data -----------------------------------------------------------------" << endl;
   
	file.open("employee_Record.txt", ios::in);
	if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close(); // File closedg
    }
    else
    {
        cout << "\nEnter Employee\'s id: Employee-";
		cin >> checkId; 

		file1.open("record.txt", ios::out);
    
    file >>empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >> exp  >> ds;

		while (!file.eof())
        {

            if (checkId == empID)
            {
            	loop : 
				cout << "\n\tWhich data you want to modify : "<<endl;
            	cout << "\t 1. FIRST NAME" << endl;
        		cout << "\t 2. LAST NAME" << endl;
        		cout << "\t 3. GENDER" << endl;
        		cout << "\t 4. AGE " << endl;
        		cout << "\t 5. ADDRESS" << endl;
        		cout << "\t 6. CITY" << endl;
        		cout << "\t 7. CONTECT  NO: " << endl;
        		cout << "\t 8. QUALIFICATION" << endl;
        		cout << "\t 9. EXPERIENCE" << endl;
        		cout << "\t 10. DESIGNATION" << endl;
				loop2 :
				cout << "Enter your choice : ";

        		cin >> x;
                               
                               				
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                 
                                if (x==1){
                                    cout << "\n---------------------------------------------------";

                                   cout << "\n\t Enter Employee Fname         : ";
                                   cin >> fname;
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                }
                                 else if (x==2){
                                    cout << "\n---------------------------------------------------";
                                   cout << "\n\t Enter Employee Lname         : ";
                                   cin >> lname;
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                 }
                                else if (x==3){
                                    cout << "\n---------------------------------------------------";
                                  cout << "\n\t Enter Employee Gender        : ";
                                   cin >> g;
                               
                                   while ((strcmp(g, "f") != 0) && (strcmp(g, "m") != 0))
                                   {
                                       cout << "\n\t Renter Employee Gender       : ";
                                       cin >> g;
                                   }
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                }
                                else if (x==4){
                                    cout << "\n---------------------------------------------------";
                                   cout << "\n\t Enter Employee Age           : ";
                                   cin >> age;
                                   if (age >= 70 || age < 18)
                                   {
                                       cout << "\n\t Sorry !!! you can't get employement...";
                                       // exit(1);
                                       
                                   }
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                }
                                else if (x==5){
                                    cout << "\n---------------------------------------------------";
                                   cout << "\n\t Enter Employee Address       : ";
                                   cin >> addr;
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                }
                                else if (x==6){
                                    cout << "\n---------------------------------------------------";
                                   cout << "\n\t Enter Employee City          : ";
                                   cin >> c;
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                }
                                else if (x==7){
                                    cout << "\n---------------------------------------------------";
                                   cout << "\n\t Enter Employee Contact       : ";
                                   cin >> cont;
                                //    while (strlen(cont) > 10 || strlen(cont) < 10)
                                //    {
                                //        cout << "\n\t Re-enter Employee Contact    : ";
                                //        cin >> cont;
                                //        cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                //    }
                                }
                                else if (x==8){
                                    cout << "\n---------------------------------------------------";
                                   cout << "\n\t Enter Employee Qualification : ";
                                   cin >> qual;
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                }
                                else if (x==9){
                                    cout << "\n---------------------------------------------------";
                                   cout << "\n\t Enter Employee Experience    : ";
                                   cin >> exp;
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                }
                                else if (x==10){
                                
                                   cout << "\n---------------------------------------------------";
                                   cout << "\n\n\t Select Designation From Given List...";
                                   cout << "\n\t -> Manager";
                                   cout << "\n\t -> Employee";
                                   cout << "\n\t -> Worker";
                                   cout << "\n---------------------------------------------------";
                               
                                   cout << "\n\t Enter Employee Designation   : ";
                                   cin >> ds;
                               
                                   cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+";
                                }
                                else{
					                cout << "\nInvalid Input.. Please Try Again..";  
					                 goto loop2; //start from the loop2
				                    }
                               
                cout << "\n\nSuccessfully Modify Details Of Patient";
                cout << "\n\n\t\t\t If you want to modify another data :-"<<endl;
                cout << "\t\t\t\t 1. Press (1) for Yes"<<endl;
                cout << "\t\t\t\t 2. press (0) for No "<< endl;
                loop1 :
				cout << " Enter your choice : ";
				cin >> z;
                
				if(z==1){
                	system("cls");
cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------- Employee Modify Data -----------------------------------------------------------------" << endl;
                   	goto loop;
				}
				else if(z==0){
                file1 <<endl<< empID <<endl<< fname <<endl<< lname <<endl<< g <<endl<< age <<endl<< addr <<endl<< c <<endl<< cont <<endl<<  qual <<endl<<   exp<< endl<< ds  ;
                found++;
                break;  
				}
				else{
					cout << "\nInvalid Input.. Please Try Again.."; 
                    
					goto loop1; 
				}
            }
            else
            {
                file1 <<endl<< empID <<endl<< fname <<endl<< lname <<endl<< g <<endl<< age <<endl<< addr <<endl<< c <<endl<< cont <<endl<<  qual <<endl<<   exp<< endl<< ds ; 

            }
    file >>empID >> fname >> lname >> g >> age >> addr >> c >> cont >>  qual >> exp  >> ds;
        }
        if (found == 0)
        {
            cout << "\n\n\t employee\'s ID Not Found.. Please Try Again"; 
                    }

        file1.close(); //Close file
        file.close(); //Close file
        remove("employee_Record.txt");

        rename("record.txt", "employee_Record.txt");
    }
}

int main()
{
    int i;
    char username[20], pass[20], ch;

    cout << "\n\t\t\t\t*************************************************************";
    cout << "\n\t\t\t\t*                   HONESTY INFOTECH                        *";
    cout << "\n\t\t\t\t*             -----------------------------                 *";
    cout << "\n\t\t\t\t*              <Payroll Management System>                  *";
    cout << "\n\t\t\t\t*************************************************************";

    cout << "\n\n\t\t\t\t\t.............................................";
    cout << "\n\n\t\t\t\t\t\t Enter User Name : ";
    cin >> username;
    cout << "\n\t\t\t\t\t\t Enter password  : ";

    for (i = 0; i < 20; i++)
    {
        ch = getch();
        if (ch == 13)
        {
            break;
        }

        pass[i] = ch;
        ch = '*';
        cout << ch;
    }
    pass[i] = '\0';
    cout << "\n\n\t\t\t\t\t.............................................";

    if (strcmp(username, "deep") == 0 && strcmp(pass, "sarvaiya") == 0)
    {
        cout << "\n\n\t\t\t\t\t\t Login Successfully.........";
        getch();
        menu m;

        m.mainmenu();
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t Invalid Login...";
        // exit(0);
    }
    getch();
}