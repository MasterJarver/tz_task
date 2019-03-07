#ifndef CITY_H
#define CITY_H
#include <vector>
#include <iostream>
class TramRails // rails config class, location, begin and end
{
	public:
	TramRails() : rowNumber(0), begin(0), end(0) {}
	TramRails(int rowNumber, int begin, int end) : rowNumber(rowNumber), begin(begin), end(end) {}
	~TramRails() {/* std::cout << "TramRails destructor" << std::endl; */}
	int rowNumber; // location
	int begin; // begining 
	int end; // ending
};
class City
{
public:
	City();
	City(int n, int m, int k);
	~City();
	void fillCity();
private:
	const int MIN_VALUE_ROW_COL = 1;
	const int MAX_VALUE_ROW_COL = 1000000000;
	const int MIN_VALUE_RAILS = 0;
	const int MAX_VALUE_RAILS = 1000;
	int m; // cols
	int n; // rows
	int k; // value of rails path
	int allSquare; // value of all squares in city
	int streetLight; // value of street light
	int numberOfRailsSquare; // number of squares occupied by rails
	std::vector<TramRails*> rails; // container of rails
	void fillRailsVector(); // fill container of rails with info
};
#endif