#include <thread>
#include <iostream>
#include "city.h"
City::City() : numberOfRailsSquare(0)
{
	fillCity();
	allSquare = n * m;
	std::cout << "All square: " << allSquare << std::endl;
	fillRailsVector();
}
City::City(ull n, ull m, ull k) : n(n), m(m), k(k), numberOfRailsSquare(0)
{
	std::cout << "constructor City" << std::endl;
	std::cout << "n: " << this->n << std::endl;
	std::cout << "m: " << this->m << std::endl;
	std::cout << "k: " << this->k << std::endl;
	allSquare = n * m;
	std::cout << "allSquare: " << allSquare << std::endl;
	fillRailsVector();
}
City::~City()
{
	// std::cout << "Destructor City" << std::endl;
}
void City::fillCity()
{
	std::cout << "Insert rows, cols, value of rails:" << std::endl;
	std::cin >> n >> m >> k;
	if((n < MIN_VALUE_ROW_COL || m < MIN_VALUE_ROW_COL || k < MIN_VALUE_RAILS) ||  
   	   (n > MAX_VALUE_ROW_COL || m > MAX_VALUE_ROW_COL || k > MAX_VALUE_RAILS))
	{
		std::cout << "Invalid values, rows and cols must be bigger or equal 1 and less or equal 10^9" << std::endl;
		std::cout << "Value of rails must be bigger or equal 0 and less or equal 1000" << std::endl;
		std::cin.clear(); // reset error
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removal of everything from the buffer before line feed
		fillCity();
	}
	else 
	{
		std::cout << "rows: " << n << " cols: " << m << " rails: " << k << std::endl;
		return;
	}
}
void City::fillRailsVector()
{
	rails.clear();
	for(ull i = 0; i < k; ++i)
	{
		rails.push_back(new TramRails());
		std::cout << "insert " << i + 1 << " rails position, begin, end" << std::endl;
		std::cin >> rails.at(i)->rowNumber >> rails.at(i)->begin >> rails.at(i)->end;
		if(rails.at(i)->rowNumber > n || rails.at(i)->rowNumber < 1 || rails.at(i)->begin > m || rails.at(i)->begin < 1 ||
		   rails.at(i)->end > m || (rails.at(i)->begin > rails.at(i)->end))
		{
			std::cout << "rails values is incorrect" << std:: endl; 
			std::cin.clear(); // reset error
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removal of everything from the buffer before line feed
			delete rails.at(i);
			rails.pop_back();
			--i;
			continue;
		}
		numberOfRailsSquare += (rails.at(i)->end - (rails.at(i)->begin - 1));
	}
	std::cout << "Occupied cells by rails: " << numberOfRailsSquare << std::endl;
	streetLight = allSquare - numberOfRailsSquare;
	std::cout << "Street Light: " << streetLight << std::endl;
}