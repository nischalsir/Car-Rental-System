#include <iostream>
#include <istream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <conio.h>

using namespace std;

void login();
void signup();
void forgot();
void adminlogin();
void userlogin();
void adminpanel();
void addCar();
void modifyCar();
void removeCar();
void showCars();
void userPanel();
void rentCar();

//Main

main()
{
        int choice;
        cout<<"***********************************************************************\n\n";
        cout<<"              Welcome To Car Rental Management System      \n\n";
        cout<<"*********************        MENU        ******************************\n\n\n\n";
        cout<<"\t\t\t 1. Log In"<<endl;
        cout<<"\t\t\t 2. Sign Up"<<endl;
        cout<<"\t\t\t 3. Forgot Username or Password"<<endl;
        cout<<"\t\t\t 4. Exit"<<endl;
        cout<<"\n\n\nEnter your choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        login();
                        break;
                case 2:
                        signup();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:
                        cout<<"Thanks for visiting\n\n";
                        break;
                default:
                        cout<<"You've entered a wrong choice, try again!\n"<<endl;
                        cin.get();
                        cin.get();
                        system("cls");
                        main();
        }

}

//Login

void login()
{
        int choice;
        system("cls");
        cout<<"***********************************************************************\n\n";
        cout<<"                          LogIn Page      \n\n";
        cout<<"*********************        MENU        ******************************\n\n\n\n";
        cout<<"\t\t\t 1. Admin Log In"<<endl;
        cout<<"\t\t\t 2. User Log In"<<endl;
        cout<<"\t\t\t 3. Exit"<<endl;
        cout<<"\n\n\nEnter your choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        adminlogin();
                        break;
                case 2:
                        userlogin();
                        break;
                case 3:

                        cout<<"Thanks for visiting\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"You've entered a wrong choice, try again!\n"<<endl;
                        login();
        }

}

//Admin Login

void adminlogin()
{
        string admin_username = "admin";
        string admin_password = "password";
        string username, password;

        system("cls");
        cout<<"\t\t\tPlease Enter the Correct details.\n\n"<<endl;
        cout << "\t\t\t\tEnter username: ";
        cin >> username;
        cout << "\t\t\t\tEnter password: ";
        char c;
        while ((c = getch()) != '\r')
            {
               password.push_back(c);
               cout << "*";
            }
        if (username == admin_username && password == admin_password)
             {
                cout<<"\n\t\t\tHello"<<" Admin"<<"\n\t\t\tLogin Sucess!\n\n";
                cin.get();
                cin.get();
                adminpanel();
             }
        else if (username == "Nischal" && password == "Pandey")
             {
                cout<<"\n\t\t\tHello"<<" Admin"<<"\n\t\t\tLogin Success!\n\n";
                cin.get();
                cin.get();
                adminpanel();
             }
        else
        {
                cout<<"\n\t\t\tLOGIN ERROR\n\t\t\tPlease enter correct details!\n";
                main();
        }
}

//User login

void userlogin()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"\t\t\tPlease Enter the Correct details.\n\n"<<endl;
        cout<<"\t\t\t\tUsername: ";
        cin>>user;
        cout<<"\n\t\t\t\tPassword: ";
        char c;
        while ((c = getch()) != '\r')
            {
               pass.push_back(c);
               cout << "*";
            }

        ifstream input("userdetails.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\n\t\t\tHello\t"<<user<<"\n\t\t\tLogin Sucess\n\n";
                cin.get();
                cin.get();
                userPanel();
        }
        else
        {
                cout<<"\n\t\t\tLOGIN ERROR\n\t\t\tPlease check your username and password!\n";
                main();
        }
}

//Sign Up

void signup()
{
    string reguser, regpass;
    system("cls");
    bool exists = false;

    cout << "\t\t\tPlease Enter Your Specific username and password.\n\n" << endl;
    cout << "\t\t\t\tEnter the username: ";
    cin >> reguser;
    cout << "\n\t\t\t\tEnter the password: ";
    cin >> regpass;

    ifstream check("userdetails.txt");
    string line;
    while (getline(check, line))
    {
        stringstream ss(line);
        string username;
        ss >> username;
        if (username == reguser)
        {
            exists = true;
            break;
        }
    }
    check.close();

    if (exists)
    {
        cout << "\n\t\t\tUsername already exists. Please choose a different username.\n\n";
        cin.get();
        cin.get();
        system("cls");
        signup();
    }
    else
    {
        ofstream reg("userdetails.txt", ios::app);
        reg << reguser << ' ' << regpass << endl;
        reg.close();
        cout << "\n\t\t\tRegistration Successful\n\n";
        cin.get();
        cin.get();
        main();
    }
}

//Forgot password

void forgot()
{
        int ch;
        system("cls");
        cout<<" \t\t\tFind your account. \n\n";
        cout<<"\t\t\t\t 1. Search your account by username"<<endl;
        cout<<"\t\t\t\t 2. Search your account by password"<<endl;
        cout<<"\t\t\t\t 3. Main menu"<<endl;
        cout<<"\n\n\t\t\tEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\n\t\t\t\tEnter your username: ";
                        cin>>searchuser;

                        ifstream searchu("userdetails.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\n\t\t\tAccount found\n";
                                cout<<"\n\t\t\t\tYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\n\t\t\tSorry, Your userID is not found.\n";
                                cout<<"\n\t\t\tPlease contact system administrator for further support.\n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\n\t\t\t\tEnter the password :";
                        cin>>searchpass;

                        ifstream searchp("userdetails.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\n\t\t\tYour password is found in the data.\n";
                                cout<<"\n\t\t\t\tYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\t\t\tSorry, your password didn't matched to any account.\n";
                                cout<<"\n\t\t\tPlease contact system administrator for further support.\n";
                                cin.get();
                                cin.get();
                                main();
                        }

                        break;
                }

                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Please try again"<<endl;
                        forgot();
        }
}

//Admin Panel

void adminpanel()
{
	int choice;
	system("cls");
	cout<<"***********************************************************************\n\n";
    cout<<"                      Welcome to Admin Page                               \n\n";
    cout<<"*********************        MENU        ******************************\n\n\n\n";
	cout << "\t\t\t 1. Add New Car"<< endl;
	cout << "\t\t\t 2. Modify Car Details"<< endl;
	cout << "\t\t\t 3. Remove Car Details"<< endl;
	cout << "\t\t\t 4. Show All Cars"<< endl;
	cout << "\t\t\t 5. Exit"<< endl;
	cout<<"\n\n\n\t\tEnter your choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        addCar();
                        break;
                case 2:
                        modifyCar();
                        break;
                case 3:
                        removeCar();
                        break;
                case 4:
                        showCars();
                        break;
                case 5:
                        cout<<"Thanks for visiting\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"You've entered a wrong choice, try again\n"<<endl;
                        adminpanel();
        }
}

//add car

void addCar()
{
    string brand, model, color, reg_number;
    int year, mileage, price;
    char choice = 'y';

    while (tolower(choice) == 'y') {
        system("cls");

        cout<<"***********************************************************************\n\n";
        cout<<"                       Add Cars Details                                \n\n";
        cout<<"***********************************************************************\n\n\n\n";


        cout << "Enter the Brand: ";
        cin >> brand;
        cout << "\nEnter the Model: ";
        cin >> model;
        cout << "\nEnter the Color: ";
        cin >> color;
        cout << "\nEnter the Reg' Number: ";
        cin >> reg_number;
        cout << "\nEnter the Year: ";
        cin >> year;
        cout << "\nEnter the Mileage: ";
        cin >> mileage;
        cout << "\nEnter the Price (per day): ";
        cin >> price;

        ofstream add("carlist.txt", ios::app);

        if (!add)
            {
            cout << "Error: Unable to open file." << endl;
            return;
            }

        add << brand << " " << model << " " << color << " " << reg_number << " "
            << year << " " << mileage << " " << price << endl;

        add.close();

        cout << "\nCar added successfully.\n\n";
        cout << "Do you want to add another car? (y/n): ";
        cin >> choice;
        system("cls");
        addCar();
    }
}

//modify car

void modifyCar()
{
string reg_number;
    char choice = 'y';

    while (tolower(choice) == 'y') {
        system("cls");

        showCars();
        cout << "Enter registration number of car to modify: ";
        cin >> reg_number;

        ifstream in("carlist.txt");
        ofstream out("temp.txt", ios::app);

        string brand, model, color, reg, line;
        int year, mileage, price;

        bool found = false;
        while (in >> brand >> model >> color >> reg >> year >> mileage >> price) {
            if (reg == reg_number) {
                found = true;

                int choice;
                cout << "\nWhat do you want to modify?\n";
                cout << "1. Brand\n2. Model\n3. Color\n4. Registration number\n5. Year\n6. Mileage\n7. Price\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Enter new brand: ";
                    cin >> brand;
                    break;
                case 2:
                    cout << "Enter new model: ";
                    cin >> model;
                    break;
                case 3:
                    cout << "Enter new color: ";
                    cin >> color;
                    break;
                case 4:
                    cout << "Enter new registration number: ";
                    cin >> reg;
                    break;
                case 5:
                    cout << "Enter new year: ";
                    cin >> year;
                    break;
                case 6:
                    cout << "Enter new mileage: ";
                    cin >> mileage;
                    break;
                case 7:
                    cout << "Enter new price(per day): ";
                    cin >> price;
                    break;
                default:
                    cout << "Invalid choice.\n";
                    break;
                }

                out << brand << " " << model << " " << color << " " << reg << " "
                    << year << " " << mileage << " " << price << endl;
                cout << "Car data updated successfully.\n";
            }
            else
                {
                out << brand << " " << model << " " << color << " " << reg << " "
                    << year << " " << mileage << " " << price << endl;
                }
            }

        in.close();
        out.close();

        if (!found)
            {
            cout << "Car with registration number " << reg_number << " not found.\n";
            }
        else
        {
             remove("carlist.txt");
             rename("temp.txt", "carlist.txt");
        }

        cout << "Do you want to modify another car? (y/n): ";
        cin >> choice;
        adminpanel();
    }
}

//remove car details

void removeCar()
{
    string reg_number;
    char choice = 'y';

    while (tolower(choice) == 'y')
        {
        system("cls");

        cout<<"***********************************************************************\n\n";
        cout<<"                       Delete Car Details                             \n\n";
        cout<<"***********************************************************************\n\n\n\n";

        showCars();

        cout << "Enter the Registration Number of the car to delete: ";
        cin >> reg_number;

        ifstream infile("carlist.txt");
        ofstream outfile("temp.txt");

        if (!infile)
        {
            cout << "Error: Unable to open file." << endl;
            return;
        }
        if (!outfile) {
            cout << "Error: Unable to create temporary file." << endl;
            return;
        }

        bool found = false;
        string brand, model, color, temp_reg_number;
        int year, mileage, price;

        while (infile >> brand >> model >> color >> temp_reg_number >> year >> mileage >> price)
        {
            if (temp_reg_number == reg_number)
                {
                found = true;
                continue;
                }
            outfile << brand << " " << model << " " << color << " " << temp_reg_number << " "
                << year << " " << mileage << " " << price << endl;
        }

        infile.close();
        outfile.close();

        if (found)
            {
            remove("carlist.txt");
            rename("temp.txt", "carlist.txt");
            cout << "\nCar with Reg' Number " << reg_number << " deleted successfully.\n\n";
            }
        else
            {
                remove("temp.txt");
                cout << "\nCar with Reg' Number " << reg_number << " not found.\n\n";
            }
        cout << "Do you want to delete another car? (y/n): ";
        cin >> choice;
        adminpanel();
    }
}

//Car list

void showCars()
{
    string brand, model, color, reg_number;
    int year, mileage, price;

    ifstream add("carlist.txt");

    system("cls");

    cout << setw(10) << left << "Brand"
         << setw(15) << left << "Model"
         << setw(10) << left << "Color"
         << setw(15) << left << "Reg Number"
         << setw(10) << left << "Year"
         << setw(10) << left << "Mileage"
         << setw(10) << left << "Price(per day)" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    while (!add.eof()) {
        add >> brand >> model >> color >> reg_number >> year >> mileage >> price;
        if (add.eof()) {
            break;
        }
        cout << setw(10) << left << brand
             << setw(15) << left << model
             << setw(10) << left << color
             << setw(15) << left << reg_number
             << setw(10) << left << year
             << setw(10) << left << mileage
             << setw(10) << left << price << endl;
    }

    add.close();

    cout << endl;
}

//user panel

void userPanel()
{
    int choice;
	system("cls");
	cout<<"***********************************************************************\n\n";
    cout<<"                      Welcome to Costumer Page                               \n\n";
    cout<<"*********************        MENU        ******************************\n\n\n\n";
	cout << "\t\t\t 1. Show Car List"<< endl;
	cout << "\t\t\t 2. Rent Car"<< endl;
	cout << "\t\t\t 3. Exit"<< endl;
	cout<<"\n\n\nEnter your choice: ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        showCars();
                        break;
                case 2:
                        rentCar();
                        break;
                case 3:
                        cout<<"Thanks for visiting\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"You've entered a wrong choice, try again\n"<<endl;
                        userPanel();
        }
}

//rent car

void rentCar()
{
    int count;
    string brand, model, color, reg_number, year, mileage, user, r;
    int price,  numberOfDays, rent_Fee;
    char choice = 'y';

    while (tolower(choice) == 'y')
        {
        system("cls");

        cout<<"***********************************************************************\n\n";
        cout<<"                       Rent Car                            \n\n";
        cout<<"***********************************************************************\n\n\n\n";

        showCars();

        cout<< "Please provide following information!\n"<<endl;
        cout << "Please enter legal your name: ";
        cin>> user;
	    cout<<"Please enter Reg No. from given list of your choice: ";
	    cin >> reg_number;

        ifstream input("carlist.txt");
        bool available = true;
        while (input >> brand >> model >> color >> r >> year >> mileage >> price)
        {
            if (r == reg_number)
            {
                count = 1;
                ifstream rented_cars("rented_cars.txt");
                string rented_car_reg_number;
                while (rented_cars >> rented_car_reg_number)
                {
                    if (rented_car_reg_number == reg_number)
                    {
                        cout << "The car with Reg No. " << reg_number << " is already rented." << endl;
                        available = false;
                        cin.get();
                        cin.get();
                        rentCar();
                        break;
                    }
                }
                rented_cars.close();
                break;
            }
        }

        if (count == 1 && available)
        {
            cout << "Number of days you want to rent the car : ";
            cin >> numberOfDays;
            rent_Fee = numberOfDays * price;

            ofstream rented_cars("rented_cars.txt", ios::app);
            rented_cars << reg_number << endl;
            rented_cars.close();
        }
        else if (count == 0)
        {
            cout << "\nCar with Reg Number " << reg_number << " not found.\n\n";
            cin.get();
            cin.get();
            rentCar();
        }

    cin.get();
    cin.get();
    cout<<"Calculating your total amount...";
    sleep(2);
    system("cls");

    static int invoiceNumber = 1001;
    time_t now  = time(0);		//getting local time
	char *date = ctime(&now); 	//Converting to a string
	cout << setw(80) << date << endl;
	cout << "\n\t\t                       CAR RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	| Invoice No.  "<<"					|"<< setw(10) <<invoiceNumber<<" |"<<endl;
	cout << "\t\t	| Customer Name "<<"				|"<< setw(10) <<user<<" |"<<endl;
	cout << "\t\t	| Car Brand  "<<"					|"<< setw(10) <<brand<<" |"<<endl;
	cout << "\t\t	| Car Model  "<<"					|"<< setw(10) <<model<<" |"<<endl;
    cout << "\t\t	| Car color  "<<"					|"<< setw(10) <<color<<" |"<<endl;
	cout << "\t\t	| Reg' No.  "<<"					|"<< setw(10) <<reg_number<<" |"<<endl;
	cout << "\t\t	| Number of days  "<<"				|"<< setw(10) <<numberOfDays<<" |"<<endl;
	cout << "\t\t	| Rental Amount  "<<"				|"<< setw(10) <<rent_Fee<<" |"<<endl;
    cout << "\t\t	|___________________________________________________________|"<<endl;
	cout << "\t\t	| Total Rental Amount    "<<"			|"<<setw(6)<<"Rs." <<rent_Fee<<" |"<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	***************************************************************************************" << endl;
	cout << "\t\t	Please pay the amount before due date otherwise extra Rs.1000 will added daily."<<endl;
	cout << "\t\t	If any damage happens to the car extra(repair amount) amount will be added to the total."<<endl;
	cout << "\t\t	***************************************************************************************" << endl;
	invoiceNumber++;

    ofstream outFile("invoice.txt", ios::app);
    outFile << "Date: " << date<< endl;
    outFile << "Invoice Number: " << invoiceNumber << endl;
    outFile << "Customer Name: " << user << endl;
    outFile << "Car Brand: " << brand << endl;
    outFile << "Car Model: " << model << endl;
    outFile << "Reg' No: " << reg_number << endl;
    outFile << "Number of days: " << numberOfDays << endl;
    outFile << "Rental Amount: " << rent_Fee << endl;

    input.close();
    outFile.close();


    cout << "Do you want to rent another car? (y/n): ";
    cin >> choice;

	system("PAUSE");
	system ("CLS");
    userPanel();

       }
    }
