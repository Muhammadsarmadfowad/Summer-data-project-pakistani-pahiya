#ifndef UTILS_H
#define UTILS_H

#include<fstream>
#include"User.h"
#include"Car.h"
#include"Car.cpp"
#include<thread> 
#include"CarDataManagernewfile.h"
#include<conio.h>
#include"car_avl_tree.h"
#include<ctime>  
#include"Log.h"


//////////////////////////////////////////////
int QWE =0;
string attribute ;
string order;
bool ascending;



////////////////////////////////////////
inline void loadUsers(const char* filename, Stack &stack) {
	ifstream file(filename);
	if (!file) {
		LOG_ERROR("Code: File userpassword didn't open here");
		cerr << "Could not open file: " << filename << endl;
		sleep(2);
		system("cls");
		return;
	}

	User user;
	while (file >> user.username >> user.password) {
		stack.push(user);
	}
	file.close();
}


////////////////////////////////////////////////////////////////////////////////////////////////
inline void saveUser(const User &user, const char* filename) {
	ofstream file(filename, ios::app);
	if (!file) {
		LOG_ERROR("Code: File save-user password didn't open here");
		cerr << "Could not open file: " << filename << endl;
		sleep(2);
		system("cls");
		return;
	}

	file << user.username << " " << user.password << endl;
	file.close();
}

// ADMIN   fujnction code
/*
inline void Admincall() {
	int choice=0;
	do {
		cout << "Menu:\n";
		cout << "1. Attribute search\n";
		cout << "2. add a new car 2\n";
		cout << "4. show all cars data in the way data stored in the AVL tree 3\n";
		cout << "3. show all cars data simple as in file stored 3\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;
		AVLTree carTree;
		CarDataManager manager;

		if(choice==1) {
			string filename = "1234.txt";
			readFileAndInsertIntoAVLTree(filename, carTree);
			string attribute, value;
			cout << "Enter attribute to search (serialNumber; model; launchYear; launchPrice; discontinueYear; discontinuePrice; numberSold; engineSize; carClass; rimSize; fuelType; drivetrain; numberOfUnitsAvailable; location1; location2;): ";
			cin >> attribute;
			cout << "Enter value for the attribute: ";
			cin >> value;
			carTree.displaySpecific(attribute, value);
			getch();
		}
		//choice 02

		else if(choice==2) {

			string filename = "1234.txt";
			readFileAndInsertIntoAVLTree(filename, carTree);
			carTree.displayAll();
			getch();
		}

		else if(choice==3) {

			manager.fileRead("1234.txt");
			getch();
		} else if(choice==4) {
			string filename = "1234.txt";
			readFileAndInsertIntoAVLTree(filename, carTree);
			Car newCar = readCarFromUser();
			carTree.insert(newCar);
			writeCarToFile(filename, newCar);
			cout << "Car added successfully!" << endl;
			getch();
		}

		else if(choice==5) {
			cout << "Exiting...\n";
		}



	} while (choice != 5);
*/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////88888*****************************************************************************
inline void setConsoleColor(const string &color) {
	cout << color;
}



/////////////////////////////////
inline void resetConsoleColor() {
	cout << "\033[0m"; // Reset to default color
}

//////////////////////////////////////////////////

inline void blinkText(const string &text, const string &color1, const string &color2, int times, int delay) {
	for (int i = 0; i < times; ++i) {
		setConsoleColor(color1);
		cout << text << flush;
		this_thread::sleep_for(chrono::milliseconds(delay));
		cout << "\r" << string(text.length(), ' ') << "\r" << flush;
		setConsoleColor(color2);
		this_thread::sleep_for(chrono::milliseconds(delay));
	}
	setConsoleColor(color1); // Set to final color
	cout << text << endl;
	resetConsoleColor();
}


/////////////////////////////////////
inline void Admincall() {
	LOG_INFO("Admin sub-menu open");
	int choice = 0;
	AVLTree carTree;
	CarDataManager manager;
	vector<string> colors = {"\033[32m", "\033[31m", "\033[33m", "\033[36m", "\033[35m"}; // Green, Red, Yellow, Cyan, Magenta

	do {
		setConsoleColor(colors[rand() % colors.size()]);
		cout << "\n********** 'ADMIN' Car Management System **************\n";
		cout << "* 1. Attribute Search                                *\n";
		cout << "* 2. Show All Cars (AVL Tree Order)                  *\n";
		cout << "* 3. ADD new ADMIN                                   *\n";
		// cout << "* 3. Show All Cars (File Data)                        *\n";
		cout << "* 4. Add a New Car                                   *\n";
		cout << "* 5. Arrange by Serial Number (Ascending)            *\n";
		cout << "* 6. Arrange by Launch Year (Ascending)              *\n";
		cout << "* 7. Arrange by Launch Price (Ascending)             *\n";
		cout << "* 8. Arrange by Discontinue Year (Ascending)         *\n";
		cout << "* 9. Arrange by Discontinue Price (Ascending)        *\n";
		cout << "* 10. Arrange by Number Sold (Ascending)             *\n";
		cout << "* 11. Arrange by Units Available (Ascending)         *\n";
		cout << "* 12. Arrange by Serial Number (Descending)          *\n";
		cout << "* 13. Arrange by Launch Year (Descending)            *\n";
		cout << "* 14. Arrange by Launch Price (Descending)           *\n";
		cout << "* 15. Arrange by Discontinue Year (Descending)       *\n";
		cout << "* 16. Arrange by Discontinue Price (Descending)      *\n";
		cout << "* 17. Arrange by Number Sold (Descending)            *\n";
		cout << "* 18. Arrange by Units Available (Descending)        *\n";
		cout << "* 19. Print Heap Tree Depth and Height               *\n";
		cout << "* 20. Frequency                                          *\n";
		cout << "* 100. Exit                                          *\n";
		cout << "**************************************************\n";
		cout << "Enter your choice: ";
		resetConsoleColor();
		cin >> choice;
		sleep(2);
		system("cls");
		switch (choice) {
			case 1: {
				LOG_INFO("Admin sub-menu option:01 opened");
				string filename = "1234.txt";
				readFileAndInsertIntoAVLTree(filename, carTree);
				string attribute, value;
				cout << "Enter attribute to search (e.g., serialNumber; model; launchYear; launchPrice; discontinueYear; discontinuePrice; numberSold; engineSize; carClass; rimSize; fuelType; drivetrain; numberOfUnitsAvailable; location1; location2;): ";
				cin >> attribute;
				
			/////////////////////
				
				
				cout << "Enter value for the attribute: ";
				cin >> value;
				carTree.displaySpecific(attribute, value);
				sleep(2);
				system("cls");
				break;
			}
			
			
			
			/////////////////////////////
			case 2: {
				LOG_INFO("Admin sub-menu option:02 opened");
				string filename = "1234.txt";
				readFileAndInsertIntoAVLTree(filename, carTree);
				carTree.displayAll();
				sleep(2);
				system("cls");
				break;
			}
			
			
			////////////////////////////////////////
			case 3: {
				LOG_INFO("Admin sub-menu option:03 opened to add new admin");
				system("color 0B");
				string filePath = "admin.txt"; 
				string adminnamen;
				int passk;
				cout << "\nEnter name to add: ";
				cin >> adminnamen;
				cout << "Enter value to add: ";
				cin >> passk;
				ofstream writeFile(filePath,   ios_base::app); 
				if (!writeFile.is_open()) {
					LOG_INFO("Admin sub-menu option:03 opened to add new admin   file didn't opened'");
					cerr << "Unable to open file: " << filePath <<   endl;
					//  return ;
				}
				
				
				
				//////////////////////////////////////////////////////////
				writeFile << adminnamen << " " << passk <<   endl;
				writeFile.close();
				sleep(2);
				system("cls");
				break;
			}
			/*  case 3: {
			  		LOG_INFO("Admin sub-menu option:03 opened");
			      manager.fileRead("123.txt");
			      getch();
			      break;
			  }*/
			  
			  
			  
			  ////////////////////////////////////////////////
			case 4: {
				LOG_INFO("Admin sub-menu option:04 opened");
				string filename = "1234.txt";
				readFileAndInsertIntoAVLTree(filename, carTree);
				Car newCar = readCarFromUser();
				carTree.insert(newCar);
				writeCarToFile(filename, newCar);
				blinkText("Car added successfully!", "\033[32m", "\033[33m", 5, 500); // Green and Yellow blink
				sleep(2);
				system("cls");
				break;
			}
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:
			case 18: {
				string filename = "heapfile.txt"; 
				vector<Carheap> cars = readDataFromFile(filename);
				string attribute;
				bool ascending;
				if (choice >= 5 && choice <= 11) {
					attribute = (choice == 5) ? "serialNumber":
					            (choice == 6) ? "launchYear" :
					            (choice == 7) ? "launchPrice" :
					            (choice == 8) ? "discontinueYear" :
					            (choice == 9) ? "discontinuePrice" :
					            (choice == 10) ? "numberSold" : "numberOfUnitsAvailable";
					ascending = true;
					LOG_INFO("Admin sub-menu option:05-10 opened to print data in acending pattern");
					sleep(2);
					system("cls");
				} else {
					attribute = (choice == 12) ? "serialNumber" :
					            (choice == 13) ? "launchYear" :
					            (choice == 14) ? "launchPrice" :
					            (choice == 15) ? "discontinueYear" :
					            (choice == 16) ? "discontinuePrice" :
					            (choice == 17) ? "numberSold" : "numberOfUnitsAvailable";
					ascending = false;
					LOG_INFO("Admin sub-menu option:05-10 opened to print data in decending pattern");
				}
				heapSort(cars, attribute, ascending);
				printCarData(cars);
				sleep(2);
				system("cls");
				break;
			}
			
			
			
			
			
			
			
			
			////////////////////////////////////////////////////////////////////
			case 19: {
				LOG_INFO("Admin sub-menu option:19 opened to print height and deapth of heap data");
				string filename = "heapfile.txt"; 
				vector<Carheap> cars = readDataFromFile(filename);
				printDepthAndHeight(cars.size());
				sleep(2);
				system("cls");
				break;
			}
			
			
			
			
			
			//////////////////////////////////////////////////
			case 20: {
				system("color 0A");
				std::ifstream file("log.txt");
				if (!file.is_open()) {
					std::cerr << "Error opening file!" << std::endl;

				}

				const int MAX_LINES = 1000; // Adjust  as needed
				LineFrequency lineFrequencies[MAX_LINES];
				int uniqueLines = 0;

				std::string line;
				while (std::getline(file, line)) {
					std::string relevantData = extractRelevantData(line);
					if (relevantData.empty()) {
						continue;
					}

					bool found = false;
					for (int i = 0; i < uniqueLines; ++i) {
						if (lineFrequencies[i].line == relevantData) {
							lineFrequencies[i].frequency++;
							found = true;
							break;
						}
					}
					if (!found) {
						lineFrequencies[uniqueLines].line = relevantData;
						lineFrequencies[uniqueLines].frequency = 1;
						uniqueLines++;
					}
				}

				file.close();

				sortLineFrequencies(lineFrequencies, uniqueLines);

				std::cout << "The line with the highest frequency (" << lineFrequencies[0].frequency << " occurrences):" << std::endl;
				std::cout << lineFrequencies[0].line << std::endl << std::endl;

				std::cout << "All lines sorted by frequency:" << std::endl;
				for (int i = 0; i < uniqueLines; ++i) {
					std::cout << lineFrequencies[i].frequency << " - " << lineFrequencies[i].line << std::endl;
				}
				sleep(2);
				system("cls");
				break;
			}
			case 100:
				LOG_INFO("Admin sub-menu option:100 opened to exit this Admin menu");
				blinkText("Thank you for using the Car Management System. Goodbye!", "\033[31m", "\033[36m", 5, 500); // Red and Cyan blink
				sleep(2);
				system("cls");
				break;
			default:
				LOG_WARNING("Enter wrong Choice for choice of Admin main menu.");
				blinkText("Invalid choice. Please try again.", "\033[31m", "\033[33m", 3, 500); // Red and Yellow blink
				sleep(2);
				system("cls");
				break;
		}
	} while (choice != 100);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////88888*****************************************************************************




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////88888*****************************************************************************
// user   fujnction code
inline void usercall() {
	LOG_INFO("User sub-menu open");
	int choice = 0;
	AVLTree carTree;
	CarDataManager manager;
	vector<string> colors = {"\033[32m", "\033[31m", "\033[33m", "\033[36m", "\033[35m"}; // Green, Red, Yellow, Cyan, Magenta

	do {
		setConsoleColor(colors[rand() % colors.size()]);
		cout << "\n********** 'USER' Car Management System ***********\n";
		cout << "* 1. Attribute Search                            *\n";
		cout << "* 2. Show All Cars (AVL Tree Order)              *\n";
		// cout << "* 3. Show All Cars (File Data)             *\n";
		// cout << "* . Add a New Car                          *\n";
		cout << "* 3. Arrange by Serial Number (Ascending)        *\n";
		cout << "* 4. Arrange by Launch Year (Ascending)          *\n";
		cout << "* 5. Arrange by Launch Price (Ascending)         *\n";
		cout << "* 6. Arrange by Discontinue Year (Ascending)     *\n";
		cout << "* 7. Arrange by Discontinue Price (Ascending)    *\n";
		cout << "* 8. Arrange by Number Sold (Ascending)          *\n";
		cout << "* 9. Arrange by Units Available (Ascending)      *\n";
		cout << "* 10. Arrange by Serial Number (Descending)      *\n";
		cout << "* 11. Arrange by Launch Year (Descending)        *\n";
		cout << "* 12. Arrange by Launch Price (Descending)       *\n";
		cout << "* 13. Arrange by Discontinue Year (Descending)   *\n";
		cout << "* 14. Arrange by Discontinue Price (Descending)  *\n";
		cout << "* 15. Arrange by Number Sold (Descending)        *\n";
		cout << "* 16. Arrange by Units Available (Descending)    *\n";
		cout << "* 17. Print Heap Tree Depth and Height           *\n";
		cout << "* 100. Exit                                      *\n";
		cout << "**************************************************\n";
		cout << "Enter your choice: ";
		resetConsoleColor();
		cin >> choice;
		sleep(2);
		system("cls");
		switch (choice) {
			case 1: {
				LOG_INFO("User sub-menu option:01 opened");
				string filename = "1234.txt";
				readFileAndInsertIntoAVLTree(filename, carTree);
				string attribute, value;
				cout << "Enter attribute to search (e.g., serialNumber; model; launchYear; launchPrice; discontinueYear; discontinuePrice; numberSold; engineSize; carClass; rimSize; fuelType; drivetrain; numberOfUnitsAvailable; location1; location2;): ";
				cin >> attribute;
				cout << "Enter value for the attribute: ";
				cin >> value;
				carTree.displaySpecific(attribute, value);
				sleep(2);
				system("cls");
				break;
			}
			case 2: {
				LOG_INFO("User sub-menu option:02 opened");
				string filename = "1234.txt";
				readFileAndInsertIntoAVLTree(filename, carTree);
				carTree.displayAll();
				sleep(2);
				system("cls");
				break;
			}
			/*         case 3: {
			         		LOG_INFO("User sub-menu option:03 opened");
			             manager.fileRead("123.txt");
			             getch();
			             break;
			         }
			         case 4: {
			         		LOG_INFO("User sub-menu option:04 opened");
			             string filename = "1234.txt";
			             readFileAndInsertIntoAVLTree(filename, carTree);
			             Car newCar = readCarFromUser();
			             carTree.insert(newCar);
			             writeCarToFile(filename, newCar);
			             blinkText("Car added successfully!", "\033[32m", "\033[33m", 5, 500); // Green and Yellow blink
			             getch();
			             break;
			         }*/
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16: {
				string filename = "heapfile.txt";
				vector<Carheap> cars = readDataFromFile(filename);
				string attribute;
				bool ascending;
				if (choice >= 3 && choice <= 9) {
					attribute = (choice == 3) ? "serialNumber":
					            (choice == 4) ? "launchYear" :
					            (choice == 5) ? "launchPrice" :
					            (choice == 6) ? "discontinueYear" :
					            (choice == 7) ? "discontinuePrice" :
					            (choice == 8) ? "numberSold" : "numberOfUnitsAvailable";
					ascending = true;
					LOG_INFO("User sub-menu option:05-10 opened to print data in acending pattern");
					sleep(2);
					system("cls");
				} else {
					attribute = (choice == 10) ? "serialNumber" :
					            (choice == 11) ? "launchYear" :
					            (choice == 12) ? "launchPrice" :
					            (choice == 13) ? "discontinueYear" :
					            (choice == 14) ? "discontinuePrice" :
					            (choice == 15) ? "numberSold" : "numberOfUnitsAvailable";
					ascending = false;
					LOG_INFO("User sub-menu option:05-10 opened to print data in decending pattern");
				}
				heapSort(cars, attribute, ascending);
				printCarData(cars);
				sleep(2);
				system("cls");
				break;
			}
			case 17: {
				LOG_INFO("User sub-menu option:19 opened to print height and deapth of heap data");
				string filename = "heapfile.txt"; 
				vector<Carheap> cars = readDataFromFile(filename);
				printDepthAndHeight(cars.size());
				sleep(3);
				system("cls");
				break;
			}
			case 100:
				LOG_INFO("User sub-menu option:100 opened to exit this User menu");
				blinkText("Thank you for using the Car Management System. Goodbye!", "\033[31m", "\033[36m", 5, 500); // Red and Cyan blink
				sleep(2);
				system("cls");
				break;
			default:
				LOG_WARNING("Enter wrong Choice for choice of User main menu.");
				blinkText("Invalid choice. Please try again.", "\033[31m", "\033[33m", 3, 500); // Red and Yellow blink
				sleep(2);
				system("cls");
				break;
		}
	} while (choice != 100);
}

//124134444444444444444444444444444444444445246347645467898765434567898765432346777777777777777777777777777777777777777777777777777777777890-==================)****************




inline void loginUser(Stack &stack, const char* username, const char* password) {
	if (stack.findUser(username, password)) {
		cout << "Login successful!\n";
		LOG_INFO(" Logged in as successful");
		sleep(2);
		system("cls");
		// ADMIN
		if(QWE==1) {
			LOG_INFO(" Login as successful as admin");
			srand((unsigned)time(0));// seed randome number generator 
			Admincall();

		}

		// USER
		srand((unsigned)time(0)); // // seed randome number generator 
		if(QWE==2) {
			LOG_INFO(" Login as successful as user");
			usercall();

		}

	} else {
		LOG_WARNING(" Enter Invalid credentials.");
		cout << "Invalid credentials.\n";
		sleep(2);
		system("cls");
	}
}

/////////////////////////////////////////////////////////////////////

inline void loginMenu(Stack &adminStack, Stack &userStack) {
	LOG_INFO(" Login Menu apper");
	int choice;
	cout <<setw(77)<< "\033[1;36m**************************************\033[0m\n"; // Cyan
	cout <<setw(77)<< "\033[1;36m*                                    *\033[0m\n";
	cout <<setw(88)<< "\033[1;36m*           \033[1;33mLOGIN MENU\033[1;36m               *\033[0m\n"; // Yellow
	cout <<setw(77)<< "\033[1;36m*                                    *\033[0m\n";
	cout <<setw(77)<< "\033[1;36m**************************************\033[0m\n";
	cout <<setw(77)<< "\033[1;32mLogin as: \033[0m\n"; // Green
	cout <<setw(77)<< "1. Admin\n";
	cout <<setw(77)<< "2. User\n";
	cout <<setw(77)<< "3. Return to main menu\n";
	cout <<setw(100)<< "\033[1;36m**************************************\033[0m\n";
	cout <<setw(77)<< "\033[1;32mEnter your choice: \033[0m";
	cin >> choice;
	sleep(2);
	system("cls");

	char username[50], password[50];
	if (choice == 1) {
		LOG_INFO(" Admin Login Menu apper");
		cout <<setw(77)<< "\033[1;35m**************************************\033[0m\n"; // Magenta
		cout << setw(77)<<"\033[1;35m*           ADMIN LOGIN              *\033[0m\n";
		cout <<setw(77)<< "\033[1;35m**************************************\033[0m\n";
		cout << setw(77)<<"\033[1;32mAdmin Username: \033[0m";
		cin >> username;
		cout <<setw(77)<< "\033[1;32mAdmin Password: \033[0m";
		cin >> password;
		QWE=choice;
		sleep(2);
		system("cls");
		loginUser(adminStack, username, password);
	} else if (choice == 2) {
		LOG_INFO(" User Login Menu apper");
		cout << setw(77)<<"\033[1;34m**************************************\033[0m\n"; // Blue
		cout <<setw(77)<< "\033[1;34m*            USER LOGIN              *\033[0m\n";
		cout <<setw(77)<< "\033[1;34m**************************************\033[0m\n";
		cout <<setw(77)<< "\033[1;32mUser Username: \033[0m";
		cin >> username;
		cout <<setw(77)<< "\033[1;32mUser Password: \033[0m";
		cin >> password;
		QWE=choice;
		sleep(2);
		system("cls");
		loginUser(userStack, username, password);
	} else if (choice == 3) {
		LOG_WARNING("Returning to main menu");
		cout << "\033[1;31mReturning to main menu...\033[0m\n"; // Red

		sleep(2);
		system("cls");
	} else {
		LOG_ERROR("Invalid choice enterd in the login menu");
		cout << "\033[1;31mInvalid choice, please try again.\033[0m\n"; // Red
		sleep(2);
		system("cls");
	}
}



//////////////////////////////////////////////////////////
inline void newRegistration(Stack &userStack, const char* userFile) {
	LOG_INFO(" NEW User Login IS UNDER REGISTRATION process started");
	char username[50], password[50];
	cout << "Enter new username: ";
	cin >> username;
	cout << "Enter new password: ";
	cin >> password;

	User newUser;
	strcpy(newUser.username, username);
	strcpy(newUser.password, password);

	saveUser(newUser, userFile);
	userStack.push(newUser);
	cout << "User registration successful!\n";

	sleep(2);
	system("cls");


}

#endif
