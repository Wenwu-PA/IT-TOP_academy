#include <iostream>

int main()
{
	std::cout << "input coordinate: ";
	int row{};
	int col{};
	std::cin >> row >> col;

	std::cout << "input coordinate: ";
	int row2{};
	int col2{};
	std::cin >> row2 >> col2;

	if (row == row2)
	{
		std::cout << "Yes\n";
	}
	else if (col == col2)
	{
		std::cout << "Yes\n";
	}
	else if (std::abs(row == row2) == std::abs(col - col2))
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No\n";
	}
	return 0;
}