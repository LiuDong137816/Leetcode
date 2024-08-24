#include <iostream>

struct Conversion
{
	operator float() { return 0.33; }
};

void main()
{
	Conversion con;
	std::cout << float(con) << std::endl;
	std::cin.get();
}