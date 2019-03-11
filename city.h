#ifndef CITY_H
#define CITY_H
#include <vector>
#include <iostream>
typedef unsigned long long ull;
class TramRails // rails config class, location, begin and end
{
	public:
	TramRails() : rowNumber(0), begin(0), end(0) {}
	TramRails(ull rowNumber, ull begin, ull end) : rowNumber(rowNumber), begin(begin), end(end) {}
	~TramRails() {/* std::cout << "TramRails destructor" << std::endl; */}
	ull rowNumber; // location
	ull begin; // begining 
	ull end; // ending
};
class City
{
public:
	City();
	City(ull n, ull m, ull k);
	~City();
	void fillCity();
private:
	const ull MIN_VALUE_ROW_COL = 1;
	const ull MAX_VALUE_ROW_COL = 1000000000;
	const ull MIN_VALUE_RAILS = 0;
	const ull MAX_VALUE_RAILS = 1000;
	ull m; // cols
	ull n; // rows
	ull k; // value of rails path
	ull allSquare; // value of all squares in city
	ull streetLight; // value of street light
	ull numberOfRailsSquare; // number of squares occupied by rails
	std::vector<TramRails*> rails; // container of rails
	void fillRailsVector(); // fill container of rails with info
};
#endif