#ifndef CARDATAMANAGER_H
#define CARDATAMANAGER_H
#include<iostream>
#include<fstream>
#include<sstream>
#include"Log.h"
#include<string>
#include<iomanip>
using namespace std;


//////////////////////////////////
class CarData {
	public:
		int serialNumber;
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
	 string Numberofunitsavalible;
	 string locationofavlibility1;
	 string locationofavlibility2;
};





////////////////////////////////////////////////////////////////
class AVLNode {
	public:
		CarData data;
		AVLNode* left;
		AVLNode* right;
		int height;
		AVLNode(const CarData& data) : data(data), left(nullptr), right(nullptr), height(1) {}
		~AVLNode() {
			delete left;
			delete right;
		}
};


/////////////////////////////////////////////////
class AVLTree1 {
	public:
		AVLNode* root;
		AVLTree1() : root(nullptr) {}
		~AVLTree1() {
			delete root;
		}
		////////////////////////////////
		int height(AVLNode* node) const {
			return node ? node->height : 0;
		}
		/////////////////////////////////
		int balanceFactor(AVLNode* node) const {
			return node ? height(node->left) - height(node->right) : 0;
		}
		////////////////////////
		inline void updateHeight(AVLNode* node) {
			node->height = 1 + std::max(height(node->left), height(node->right));
		}
		//////////////////
		AVLNode* rotateRight(AVLNode* y) {
			AVLNode* x = y->left;
			AVLNode* T2 = x->right;
			x->right = y;
			y->left = T2;
			updateHeight(y);
			updateHeight(x);
			return x;
		}
		/////////////////////////////
		AVLNode* rotateLeft(AVLNode* x) {
			AVLNode* y = x->right;
			AVLNode* T2 = y->left;
			y->left = x;
			x->right = T2;
			updateHeight(x);
			updateHeight(y);
			return y;
		}
		///////////////////////
		AVLNode* balance(AVLNode* node) {
			updateHeight(node);
			if (balanceFactor(node) > 1) {
				if (balanceFactor(node->left) < 0) {
					node->left = rotateLeft(node->left);
				}
				return rotateRight(node);
			}
			if (balanceFactor(node) < -1) {
				if (balanceFactor(node->right) > 0) {
					node->right = rotateRight(node->right);
				}
				return rotateLeft(node);
			}
			return node;
		}
		////////////////////////////////////
		AVLNode* insert(AVLNode* node, const CarData& data) {
			if (!node) {
				return new AVLNode(data);
			}
			if (data.serialNumber < node->data.serialNumber) {
				node->left = insert(node->left, data);
			} else {
				node->right = insert(node->right, data);
			}
			return balance(node);
		}
		///////////////////////////////
		inline void insert(const CarData& data) {
			root = insert(root, data);
		}
		///////////////////////////////////
		inline void inOrder(AVLNode* node) const {
			if (node) {
				inOrder(node->left);
				printCarData(node->data);
				inOrder(node->right);
			}
		}
		////////////////////////////////////////
		inline void printInOrder() const {
			inOrder(root);
		}
		//////////////////////////////////////////////////////////////
	inline void printCarData(const CarData& car) const {
    const char* BLINK = "\033[5m";
    const char* RESET = "\033[0m";
    const char* RED = "\033[31m";
    const char* GREEN = "\033[32m";
    const char* YELLOW = "\033[33m";
    const char* BLUE = "\033[34m";
    const char* MAGENTA = "\033[35m";
    const char* CYAN = "\033[36m";
    std::cout << BLINK << RED <<setw(20)<< "Serial Number: " << car.serialNumber << RESET << "\n"
              << BLINK << GREEN <<setw(20)<< "Make: " << car.make << RESET << "\n"
              << BLINK << YELLOW <<setw(20)<< "Model: " << car.model << RESET << "\n"
              << BLINK << BLUE <<setw(20)<< "Launch Year: " << car.launchYear << RESET << "\n"
              << BLINK << MAGENTA <<setw(20)<< "Launch Price: " << car.launchPrice << RESET << "\n"
              << BLINK << CYAN << setw(20)<<"Discontinue Year: " << car.discontinueYear << RESET << "\n"
              << BLINK << RED <<setw(20)<< "Discontinue Price: " << car.discontinuePrice << RESET << "\n"
              << BLINK << GREEN << setw(20)<<"Number Sold: " << car.numberSold << RESET << "\n"
              << BLINK << YELLOW << setw(20)<<"Engine Size: " << car.engineSize << RESET << "\n"
              << BLINK << BLUE << setw(20)<<"Class: " << car.carClass << RESET << "\n"
              << BLINK << MAGENTA << setw(20)<<"Rim Size: " << car.rimSize << RESET << "\n"
              << BLINK << CYAN << setw(20)<<"Fuel Type: " << car.fuelType << RESET << "\n"
              << BLINK << RED <<setw(20)<< "Drivetrain: " << car.drivetrain << RESET << "\n"
              << BLINK << GREEN <<setw(20)<< "Unit Available: " << car.Numberofunitsavalible << RESET << "\n"
              << BLINK << YELLOW <<setw(20)<< "Location of Availability 1: " << car.locationofavlibility1 << RESET << "\n"
              << BLINK << BLUE <<setw(20)<< "Location of Availability 2: " << car.locationofavlibility2 << RESET << "\n"
              << "----------------------------------\n";
}
};


/////////////////////////////////////////////
class CarDataManager {
	
	//////////////////
	private:
		AVLTree1 carTree;
		
		
		/////////////////////////////
	public:
		
		///////////////////////////////////
		inline void parseAndStoreData(const std::string& fileName) {
		 ifstream file(fileName);
			if (!file.is_open()) {
			 cerr << "Unable to open file " << fileName << std::endl;
				return;
			}
		 string line;
		 getline(file, line);
		 LOG_INFO("CarDataManagernewfile.h header file is opened.");
			while (std::getline(file, line)) {
			 istringstream ss(line);
				CarData car;
				ss >> car.serialNumber;
				ss.ignore(); 
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
			 getline(ss, car.Numberofunitsavalible, '\t');
			 getline(ss, car.locationofavlibility1, '\t');
			 getline(ss, car.locationofavlibility2, '\t');
				carTree.insert(car);
			}
			file.close();
		}
		
		/////////////////////////////////////////////
		inline void printCarData() const {
				system("color 09");
    cout << "-------------------------------------------" << endl;
    cout << "          Car Details               " << endl;
    cout << "-------------------------------------------" << endl;
			carTree.printInOrder();
		}
		
		//////////////////////////////////////////////////////////////////
		inline void fileRead(const std::string& fileName) {
			parseAndStoreData(fileName);
			printCarData();
		}
};
#endif 
