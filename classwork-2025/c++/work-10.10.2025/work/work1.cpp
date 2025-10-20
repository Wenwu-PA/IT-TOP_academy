#include <iostream>
#include <cmath>

int main()
{
	double num1{};
	double num2{};
	char oper{};
	double res{};

	std::cout <<"input num1 oper num2 ";
	std::cin >> num1 >> oper >> num2;
	if (oper == '+')
	{
		res = num1 + num2;
	}
	else if (oper == '-')
	{
		res = num1 - num2;
	}
	else if (oper == '*')
	{
		res = num1 * num2;
	}
	else if (oper == '/')
	{
		if(!num2)
		{
			std::cout << "error";
		}
		else
		{
			res = num1 / num2;
		}
	}
	std::cout << "result " << res << "\n";
}