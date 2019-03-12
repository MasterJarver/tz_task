#include <thread>
#include <iostream>
#include "city.h"
#include <algorithm>
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
	}
}
void City::fillRailsVector()
{
	rails.clear();
	for(ull i = 0; i < k; i++)
	{
		rails.push_back(new TramRails());
		std::cout << "insert " << i + 1 << " rails position, begin, end" << std::endl;
		std::cin >> rails.at(i)->rowNumber >> rails.at(i)->begin >> rails.at(i)->end;
		if(rails.at(i)->rowNumber > n || rails.at(i)->rowNumber < 1 || rails.at(i)->begin > m || rails.at(i)->begin < 1 ||
		   rails.at(i)->end > m || (rails.at(i)->begin > rails.at(i)->end))
		{
			std::cout << "rails values is incorrect" << std::endl;
			std::cin.clear(); // reset error
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // removal of everything from the buffer before line feed
			delete rails.at(i);
			rails.pop_back();
			--i;
			continue;
		}
		if (i == 0)
		{
			numberOfRailsSquare += (rails.at(i)->end - (rails.at(i)->begin - 1));
		}
		else // if rails input not first
		{
			for(ull j = 0; j < rails.size() - 1; j++) // iterate over the vector
			{
				if(rails.at(i)->rowNumber == rails.at(j)->rowNumber || rails.at(i)->rowNumber == rails.at(i - 1)->rowNumber) // если есть совпадение по строкам
				{
					if(rails.at(i)->end < rails.at(j)->begin) // second end < first begin
					{
						// no inclusion, rails left side
						numberOfRailsSquare += (rails.at(i)->end - (rails.at(i)->begin - 1)); // add all cubes
						break;
					}
					else if(rails.at(i)->begin > rails.at(j)->end)
					{
						// no inclusion, rails right side
						numberOfRailsSquare += (rails.at(i)->end - (rails.at(i)->begin - 1));
						break;
					}
					else if((rails.at(i)->begin >= rails.at(j)->begin) && (rails.at(i)->end > rails.at(j)->end))
					{
						// second rails right side, partial inclusion
						numberOfRailsSquare += (rails.at(i)->end - rails.at(j)->end);
						break;
					}
					else if((rails.at(i)->end <= rails.at(j)->end) && (rails.at(i)->begin < rails.at(j)->begin))
					{
						// second rails left side, partial inclusion
						numberOfRailsSquare += (rails.at(j)->begin - rails.at(i)->begin);
						break;
					}
					else if(rails.at(i)->begin >= rails.at(j)->begin && rails.at(j)->end >= rails.at(i)->end)
					{
						// full include, nothing to add
						break;
					}
				} // if no equal rows
				else
				{
					if(j < rails.size())
					{
						numberOfRailsSquare += (rails.at(i)->end - (rails.at(i)->begin - 1)); // add all cubes
						break;
					}
				}
			}
		}
	}
	std::cout << "Occupied cells by rails: " << numberOfRailsSquare << std::endl;
	streetLight = allSquare - numberOfRailsSquare;
	std::cout << "Street Light: " << streetLight << std::endl;
}	