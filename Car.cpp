#include"Car.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include"Log.h"

using namespace std;


vector<Carheap> readDataFromFile(string& filename) {
	LOG_INFO("Car.h/Car.cpp header file is open to read data from file");
	vector<Carheap> cars;
	ifstream file(filename);
	string line;
	getline(file, line);
	while (  getline(file, line)) {
		stringstream ss(line);
		Carheap car;
		ss >> car.serialNumber >> car.make >> car.model >> car.launchYear
		   >> car.launchPrice >> car.discontinueYear >> car.discontinuePrice
		   >> car.numberSold >> car.engineSize >> car.carClass >> car.rimSize
		   >> car.fuelType >> car.drivetrain >> car.numberOfUnitsAvailable
		   >> car.locationOfAvailability1 >> car.locationOfAvailability2;
		cars.push_back(car);
	}
	return cars;
}
bool compareCars(const Carheap& a, const Carheap& b, const   string& attribute, bool ascending) {
	LOG_INFO("Car.h/Car.cpp header file is open to compare compareCars");
	if (attribute == "serialNumber")
		return ascending ? a.serialNumber < b.serialNumber : a.serialNumber > b.serialNumber;
	if (attribute == "launchYear")
		return ascending ? a.launchYear < b.launchYear : a.launchYear > b.launchYear;
	if (attribute == "launchPrice")
		return ascending ? a.launchPrice < b.launchPrice : a.launchPrice > b.launchPrice;
	if (attribute == "discontinueYear")
		return ascending ? a.discontinueYear < b.discontinueYear : a.discontinueYear > b.discontinueYear;
	if (attribute == "discontinuePrice")
		return ascending ? a.discontinuePrice < b.discontinuePrice : a.discontinuePrice > b.discontinuePrice;
	if (attribute == "numberSold")
		return ascending ? a.numberSold < b.numberSold : a.numberSold > b.numberSold;
	if (attribute == "numberOfUnitsAvailable")
		return ascending ? a.numberOfUnitsAvailable < b.numberOfUnitsAvailable : a.numberOfUnitsAvailable > b.numberOfUnitsAvailable;
	// Add more attributes here
	return false; 
}
inline void heapify(  vector<Carheap>& cars, int n, int i, const   string& attribute, bool ascending) {
	LOG_INFO("Car.h/Car.cpp header file is open to apply heapify");
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && compareCars(cars[left], cars[largest], attribute, !ascending))
		largest = left;
	if (right < n && compareCars(cars[right], cars[largest], attribute, !ascending))
		largest = right;
	if (largest != i) {
		swap(cars[i], cars[largest]);
		heapify(cars, n, largest, attribute, ascending);
	}
}
inline void heapSort(  vector<Carheap>& cars, const   string& attribute, bool ascending) {
	LOG_INFO("Car.h/Car.cpp header file is open to heapSort ");
	int n = cars.size();
	lolipop=attribute;
	// Building heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(cars, n, i, attribute, ascending);
	// extraction
	for (int i = n - 1; i >= 0; i--) {
		swap(cars[0], cars[i]);
		heapify(cars, i, 0, attribute, ascending);
	}
}
inline void printCarData(const   vector<Carheap>& cars) {
	LOG_INFO("Car.h/Car.cpp header file is open to printCarData");
	srand(static_cast<unsigned>(  time(0)));
	const   string colors[] = {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m"};
	const   string resetColor = "\033[0m";
	cout << "********** Detailed Car Data **********\n";
	for (const auto& car: cars) {
		cout << "----------------------------------------\n";
		cout << colors[rand() % 7] <<   left <<   setw(20) << "Serial Number"      << ": " << car.serialNumber << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Make"               << ": " << car.make << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Model"              << ": " << car.model << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Launch Year"        << ": " << car.launchYear << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Launch Price"       << ": $" << car.launchPrice << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Discontinue Year"   << ": " << car.discontinueYear << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Discontinue Price"  << ": $" << car.discontinuePrice << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Number Sold"        << ": " << car.numberSold << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Engine Size"        << ": " << car.engineSize << "L" << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Class"              << ": " << car.carClass << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Rim Size"           << ": " << car.rimSize << " inches" << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Fuel Type"          << ": " << car.fuelType << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Drivetrain"         << ": " << car.drivetrain << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Units Available"    << ": " << car.numberOfUnitsAvailable << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Location 1"         << ": " << car.locationOfAvailability1 << resetColor << "\n"
		     << colors[rand() % 7] <<   setw(20) << "Location 2"         << ": " << car.locationOfAvailability2 << resetColor << "\n";
		cout << "----------------------------------------\n";
	}
	cout << "********** End of Data **********\n";
}
inline void printDepthAndHeight(int n) {
	LOG_INFO("Car.h/Car.cpp header file is open to printDepthAndHeight");
	int height = static_cast<int>(  floor(  log2(n)));
	cout << "Height of the heap: " << height <<   endl;
	cout << "Depth of the heap: " << height <<   endl;
}


