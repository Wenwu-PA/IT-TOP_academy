#include <iostream>

int main()
{
	double digit;
	std::cout << "Enter digit ";
	std::cin >> digit;
	int res{ digit / 100 };
	std::cout << res << "hundread in you digit!!!" << "\n" << '\n';

}