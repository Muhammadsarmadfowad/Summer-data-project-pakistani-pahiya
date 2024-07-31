#ifndef CAR_H
#define CAR_H
#include<string>
#include<vector>
#include<iomanip>
#include<ctime>
#include"Log.h"
string lolipop;
using namespace std;

struct Carheap {
	int serialNumber;
	string make;
	string model;
	int launchYear;
	int launchPrice;
	int discontinueYear;
	int discontinuePrice;
	int numberSold;
	string engineSize;
	string carClass;
	string rimSize;
	string fuelType;
	string drivetrain;
	int numberOfUnitsAvailable;
	string locationOfAvailability1;
	string locationOfAvailability2;
};
vector<Carheap> readDataFromFile( string& filename);
bool compareCars(const Carheap& a, const Carheap& b, const   string& attribute, bool ascending);
inline void heapify(  vector<Carheap>& cars, int n, int i, const   string& attribute, bool ascending);
void heapSort(  vector<Carheap>& cars, const   string& attribute, bool ascending);
inline void printCarData(const   vector<Carheap>& cars);
inline void printDepthAndHeight(int n);

#endif
