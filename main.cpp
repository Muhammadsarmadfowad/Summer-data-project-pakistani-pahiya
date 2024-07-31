#include<iostream>
#include<conio.h>// for getch
#include"Graphicalll.h"
#include"User.h"
#include"Utils.h"
#include"Log.h"
#include<iomanip>



// ANSI color for console
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";


inline void  printMenu() {
	cout << BLUE << "\n"<<setw(77)<<"  ============================\n";
	cout <<  setw(50)<<"====== " << MAGENTA << setw(9) << right << "Welcome to Our Portal" << BLUE << "    ======\n";
	cout <<setw(77)<< "  ======================================\n";
	cout << setw(50)<<"====== " << GREEN << "1. Login" << BLUE << setw(19) << right << " ======\n";
	cout << setw(50)<<"====== " << YELLOW << "2. New Registration" << BLUE << setw(8) << right << "======\n";
	cout << setw(50)<<"====== " << RED << "3. Exit" << BLUE << setw(20) << right << " ======\n";
	cout <<setw(77)<< "  ======================================\n" << RESET;
	cout <<setw(77)<< "Please enter your choice: ";
}

using namespace std;
int main() {
	LOG_INFO("\n\n Program start its execution");


	system("color 0B");
	// welcome screen
	LOG_INFO("Welcome page executed");
	Graphical_functions obj;
	obj.title_main_page();
	obj.welcome();
	obj.title_main_page();
	sleep(1);
	system("cls");
		// end welcome screen
		//////////////////////////////////
		
		
		
		
	// loading screen
	LOG_INFO("Data loding page executed");
	obj.loading();
	sleep(1);
	system("cls");


	//////////////////////////////
	
	
	
	
	LOG_INFO("Data has been readed for passwords");
	const char* adminFile = "admin.txt";
	const char* userFile = "users.txt";

	Stack adminStack, userStack;
	loadUsers(adminFile, adminStack);
	loadUsers(userFile, userStack);



	int choice;
	do {
		/////////////////////////////////
		LOG_INFO("Main menu opened");
		printMenu();
		cin >> choice;
		system("cls");
		system("color 0D");



		switch (choice) {
		//////////////////////////////
			case 1:
				LOG_INFO("Sub-Main menu printed for to enter user or admin");
				cout << MAGENTA << "Redirecting to Login Menu...\n" << RESET;
				sleep(0.5);
				system("cls");
				system("color 0B");
				loginMenu(adminStack, userStack);
				break;
				
				/////////////////////////////
				
				
			case 2:
				LOG_INFO("Redirected to enter New Registration");
				cout << GREEN << "Redirecting to New Registration...\n" << RESET;
				sleep(0.5);
				system("cls");
				system("color 0B");
				newRegistration(userStack, userFile);
				break;
				
				
				//////////////////////////////////////////////
				
				
				
			case 3:
				LOG_INFO("Redirected to Exit program");
				cout << RED << "Exiting the program. Have a great day!\n" << RESET;
				sleep(0.5);
				system("cls");
				break;
				
				//////////////////////////
				
				
			default:
				LOG_WARNING("Enter wrong Choice for choice of main menu.");
				cout << YELLOW << " Invalid choice. Please try again.\n" << RESET;
		}
	} while (choice != 3);

	return 0;


	//////////////////



	//	return 0;
}