#ifndef CAR_AVL_TREE_H
#define CAR_AVL_TREE_H
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include"Log.h"
using namespace std;
struct Car {
	string serialNumber;
	string make;
	string model;
	string launchYear;
	string launchPrice;
	string discontinueYear;
	string discontinuePrice;
	string numberSold;
	string engineSize;
	string carClass;
	string rimSize;
	string fuelType;
	string drivetrain;
	string numberOfUnitsAvailable;
	string location1;
	string location2;
};
struct Node {
	Car car;
	Node* left;
	Node* right;
	int height;
};
class AVLTree {
	private:
		Node* root;
		int height(Node* N) {
			if (N == nullptr)
				return 0;
			return N->height;
		}
		
		
		////////////////////
		Node* newNode(Car car) {
			LOG_INFO("car_avl_tree.h header file is open to make new node");
			Node* node = new Node();
			node->car = car;
			node->left = nullptr;
			node->right = nullptr;
			node->height = 1; // new node is initially added at leaf
			return node;
		}
		
		
		//////////////////////////
		Node* rightRotate(Node* y) {
			LOG_INFO("car_avl_tree.h header file is open to make rightRotate");
			Node* x = y->left;
			Node* T2 = x->right;
			x->right = y;
			y->left = T2;
			y->height = max(height(y->left), height(y->right)) + 1;
			x->height = max(height(x->left), height(x->right)) + 1;
			return x;
		}
		
		
		///////////////////////
		Node* leftRotate(Node* x) {
			LOG_INFO("car_avl_tree.h header file is open to make leftRotate");
			Node* y = x->right;
			Node* T2 = y->left;
			y->left = x;
			x->right = T2;
			x->height = max(height(x->left), height(x->right)) + 1;
			y->height = max(height(y->left), height(y->right)) + 1;
			return y;
		}
		
		//////////////////////////
		///////////
		int getBalance(Node* N) {
			LOG_INFO("car_avl_tree.h header file is open to make getBalance");
			if (N == nullptr)
				return 0;
			return height(N->left) - height(N->right);
		}
		
		
		
		///////////////////
		Node* insert(Node* node, Car car) {
			LOG_INFO("car_avl_tree.h header file is open to make insertion");
			if (node == nullptr)
				return newNode(car);
			if (car.serialNumber < node->car.serialNumber)
				node->left = insert(node->left, car);
			else if (car.serialNumber > node->car.serialNumber)
				node->right = insert(node->right, car);
			else
				return node;
			node->height = 1 + max(height(node->left), height(node->right));
			int balance = getBalance(node);
			if (balance > 1 && car.serialNumber < node->left->car.serialNumber)
				return rightRotate(node);
			if (balance < -1 && car.serialNumber > node->right->car.serialNumber)
				return leftRotate(node);
			if (balance > 1 && car.serialNumber > node->left->car.serialNumber) {
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
			if (balance < -1 && car.serialNumber < node->right->car.serialNumber) {
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
			return node;
		}
		
		
		
		/////////////////////////////
		inline void preOrder(Node* root) {
			LOG_INFO("car_avl_tree.h header file is open to print the DATA");
			if (root != nullptr) {
				string RESET   = "\033[0m";
				string RED     = "\033[31m";
				string GREEN   = "\033[32m";
				string YELLOW  = "\033[33m";
				string BLUE    = "\033[34m";
				string MAGENTA = "\033[35m";
				string CYAN    = "\033[36m";
				string WHITE   = "\033[37m";
				cout << WHITE << "-----------------------------------" << RESET << "\n"
				     << WHITE << "           Car Details             " << RESET << "\n"
				     << WHITE << "-----------------------------------" << RESET << "\n"
				     << RED     << "Serial Number         : " << root->car.serialNumber << RESET << "\n"
				     << GREEN   << "Make                  : " << root->car.make << RESET << "\n"
				     << YELLOW  << "Model                 : " << root->car.model << RESET << "\n"
				     << BLUE    << "Launch Year           : " << root->car.launchYear << RESET << "\n"
				     << MAGENTA << "Launch Price          : $" << root->car.launchPrice << RESET << "\n"
				     << CYAN    << "Discontinue Year      : " << root->car.discontinueYear << RESET << "\n"
				     << RED     << "Discontinue Price     : $" << root->car.discontinuePrice << RESET << "\n"
				     << GREEN   << "Number Sold           : " << root->car.numberSold << RESET << "\n"
				     << YELLOW  << "Engine Size           : " << root->car.engineSize << " L" << RESET << "\n"
				     << BLUE    << "Class                 : " << root->car.carClass << RESET << "\n"
				     << MAGENTA << "Rim Size              : " << root->car.rimSize << " inches" << RESET << "\n"
				     << CYAN    << "Fuel Type             : " << root->car.fuelType << RESET << "\n"
				     << RED     << "Drivetrain            : " << root->car.drivetrain << RESET << "\n"
				     << GREEN   << "Units Available       : " << root->car.numberOfUnitsAvailable << RESET << "\n"
				     << YELLOW  << "Location 1            : " << root->car.location1 << RESET << "\n"
				     << BLUE    << "Location 2            : " << root->car.location2 << RESET << "\n"
				     << WHITE   << "-----------------------------------" << RESET <<   endl;
				preOrder(root->left);
				preOrder(root->right);
			}
		}
		
		
		
		///////////////////////////////////////////
		inline void search(Node* root, const string& attribute, const string& value, vector<Car>& result) {
			LOG_INFO("car_avl_tree.h header file is open to make search");
			if (root == nullptr) return;
			if (		(attribute == "serialNumber" && root->car.serialNumber == value) ||
			            (attribute == "make" && root->car.make == value) ||
			            (attribute == "model" && root->car.model == value) ||
			            (attribute == "launchYear" && root->car.launchYear == value) ||
			            (attribute == "launchPrice" && root->car.launchPrice == value) ||
			            (attribute == "discontinueYear" && root->car.discontinueYear == value) ||
			            (attribute == "discontinuePrice" && root->car.discontinuePrice == value) ||
			            (attribute == "numberSold" && root->car.numberSold == value) ||
			            (attribute == "engineSize" && root->car.engineSize == value) ||
			            (attribute == "carClass" && root->car.carClass == value) ||
			            (attribute == "rimSize" && root->car.rimSize == value) ||
			            (attribute == "fuelType" && root->car.fuelType == value) ||
			            (attribute == "drivetrain" && root->car.drivetrain == value) ||
			            (attribute == "numberOfUnitsAvailable" && root->car.numberOfUnitsAvailable == value) ||
			            (attribute == "location1" && root->car.location1 == value) ||
			            (attribute == "location2" && root->car.location2 == value)
			   ) {
				result.push_back(root->car);
			}
			search(root->left, attribute, value, result);
			search(root->right, attribute, value, result);
		}
		
		/////////////////////////////////////////////////////
		
		
		
	public:
		AVLTree() : root(nullptr) {}
		inline void insert(Car car) {
			root = insert(root, car);
		}
		
		
		///////////////////////////////
		inline void displayAll() {
			preOrder(root);
		}
		
		
		
		///////////////////////////////
		inline void displaySpecific(const string& attribute, const string& value) {
			LOG_INFO("car_avl_tree.h header file is open to displaySpecific");
			vector<Car> result;
			search(root, attribute, value, result);
			if (!result.empty()) {
				for (const auto& car : result) {
					string RESET   = "\033[0m";
					string RED     = "\033[31m";
					string GREEN   = "\033[32m";
					string YELLOW  = "\033[33m";
					string BLUE    = "\033[34m";
					string MAGENTA = "\033[35m";
					string CYAN    = "\033[36m";
					string WHITE   = "\033[37m";
					cout << WHITE << "-----------------------------------" << RESET << "\n"
					     << WHITE << "           Car Details             " << RESET << "\n"
					     << WHITE << "-----------------------------------" << RESET << "\n"
					     << RED     << "Serial Number         : " << car.serialNumber << RESET << "\n"
					     << GREEN   << "Make                  : " << car.make << RESET << "\n"
					     << YELLOW  << "Model                 : " << car.model << RESET << "\n"
					     << BLUE    << "Launch Year           : " << car.launchYear << RESET << "\n"
					     << MAGENTA << "Launch Price          : $" << car.launchPrice << RESET << "\n"
					     << CYAN    << "Discontinue Year      : " << car.discontinueYear << RESET << "\n"
					     << RED     << "Discontinue Price     : $" << car.discontinuePrice << RESET << "\n"
					     << GREEN   << "Number Sold           : " << car.numberSold << RESET << "\n"
					     << YELLOW  << "Engine Size           : " << car.engineSize << " L" << RESET << "\n"
					     << BLUE    << "Class                 : " << car.carClass << RESET << "\n"
					     << MAGENTA << "Rim Size              : " << car.rimSize << " inches" << RESET << "\n"
					     << CYAN    << "Fuel Type             : " << car.fuelType << RESET << "\n"
					     << RED     << "Drivetrain            : " << car.drivetrain << RESET << "\n"
					     << GREEN   << "Units Available       : " << car.numberOfUnitsAvailable << RESET << "\n"
					     << YELLOW  << "Location 1            : " << car.location1 << RESET << "\n"
					     << BLUE    << "Location 2            : " << car.location2 << RESET << "\n"
					     << WHITE   << "-----------------------------------" << RESET <<   endl;
				}
			} else {
				system("color 03");
				cout << "No car found with " << attribute << " = " << value << endl;
			}
		}
};


////////////////////////////////////////////
inline void readFileAndInsertIntoAVLTree(const string& filename, AVLTree& tree) {
	LOG_INFO("car_avl_tree.h header file is open to readFileAndInsertIntoAVLTree");
	ifstream file(filename);
	if (!file.is_open()) {
		system("color 03");
		cerr << "Could not open the file!" << endl;
		return;
	}
	string line;
	while (getline(file, line)) {
		stringstream ss(line);
		Car car;
		getline(ss, car.serialNumber, '\t');
		getline(ss, car.make, '\t');
		getline(ss, car.model, '\t');
		getline(ss, car.launchYear, '\t');
		getline(ss, car.launchPrice, '\t');
		getline(ss, car.discontinueYear, '\t');
		getline(ss, car.discontinuePrice, '\t');
		getline(ss, car.numberSold, '\t');
		getline(ss, car.engineSize, '\t');
		getline(ss, car.carClass, '\t');
		getline(ss, car.rimSize, '\t');
		getline(ss, car.fuelType, '\t');
		getline(ss, car.drivetrain, '\t');
		getline(ss, car.numberOfUnitsAvailable, '\t');
		getline(ss, car.location1, '\t');
		getline(ss, car.location2, '\t');
		tree.insert(car);
	}
	file.close();
}



///////////////////////////////////// 
inline void writeCarToFile(const string& filename, const Car& car) {
	LOG_INFO("car_avl_tree.h header file is open to write Car To File");
	ofstream file(filename, ios::app);
	if (!file.is_open()) {
		system("color 03");
		cerr << "Could not open the file!" << endl;
		return;
	}
	file << car.serialNumber << '\t'
	     << car.make << '\t'
	     << car.model << '\t'
	     << car.launchYear << '\t'
	     << car.launchPrice << '\t'
	     << car.discontinueYear << '\t'
	     << car.discontinuePrice << '\t'
	     << car.numberSold << '\t'
	     << car.engineSize << '\t'
	     << car.carClass << '\t'
	     << car.rimSize << '\t'
	     << car.fuelType << '\t'
	     << car.drivetrain << '\t'
	     << car.numberOfUnitsAvailable << '\t'
	     << car.location1 << '\t'
	     << car.location2 << '\n';
	file.close();
}



/////////////////////////////////////////////////////////
Car readCarFromUser() {
	LOG_INFO("car_avl_tree.h header file is open to read Car From User");
	Car car;
	system("color 09");
	cout << "-------------------------------------------" << endl;
	cout << "           Enter Car Details               " << endl;
	cout << "-------------------------------------------" << endl;
	cout << "Serial Number: ";
	cin >> car.serialNumber;
	cout << "Make: ";
	cin.ignore();
	getline(cin, car.make);
	cout << "Model: ";
	getline(cin, car.model);
	cout << "Launch Year: ";
	cin >> car.launchYear;
	cout << "Launch Price: $";
	cin >> car.launchPrice;
	cout << "Discontinue Year: ";
	cin >> car.discontinueYear;
	cout << "Discontinue Price: $";
	cin >> car.discontinuePrice;
	cout << "Number Sold: ";
	cin >> car.numberSold;
	cout << "Engine Size (in liters): ";
	cin >> car.engineSize;
	cout << "Class (e.g., Sedan, SUV): ";
	cin.ignore();
	getline(cin, car.carClass);
	cout << "Rim Size (in inches): ";
	cin >> car.rimSize;
	cout << "Fuel Type (e.g., Petrol, Diesel, Electric): ";
	cin.ignore();
	getline(cin, car.fuelType);
	cout << "Drivetrain (e.g., FWD, RWD, AWD): ";
	getline(cin, car.drivetrain);
	cout << "Number of Units Available: ";
	cin >> car.numberOfUnitsAvailable;
	cout << "Location of Availability 1: ";
	cin.ignore();
	getline(cin, car.location1);
	cout << "Location of Availability 2: ";
	getline(cin, car.location2);
	cout << "-------------------------------------------" << endl;
	cout << "       Thank you for providing details!    " << endl;
	cout << "-------------------------------------------" << endl;
	return car;
}
#endif 