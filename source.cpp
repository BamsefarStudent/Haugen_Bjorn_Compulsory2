#include <iostream>
#include "functions.h"
#include <list>
#include <string>

using namespace std;

list<int> polynomialList1;
list<int> polynomialList2;

#pragma region Declaring Functions

void MakeLists();
void MakeList1();
void MakeList2();

#pragma endregion


int main()
{
	bool running = true;

	while (running)
	{
		int choice = AskUserForOperation();
		double a, b;
		int i;
		unsigned long long int f;

		switch (choice)
		{
		case 1:
			a = GetDouble("First value: ");
			b = GetDouble("Second value: ");

			std::cout << a << " + " << b << " = " << Add(a, b) << "\n";

			break;
		case 2:
			a = GetDouble("First value: ");
			b = GetDouble("Second value: ");

			std::cout << a << " - " << b << " = " << Subtract(a, b) << "\n";

			break;
		case 3:
			a = GetDouble("First value: ");
			b = GetDouble("Second value: ");

			std::cout << a << " * " << b << " = " << Multiply(a, b) << "\n";

			break;
		case 4:
			a = GetDouble("First value: ");
			b = GetDouble("Second value: ");

			std::cout << a << " / " << b << " = " << Divide(a, b) << "\n";

			break;
		case 5:
			i = GetInt("Value: ");

			if (i < 0)
			{
				std::cout << "ERROR! The number cannot be negative!";
				break;
			}

			f = Factorial(i);

			if (f == 0) std::cout << "ERROR! The number was too large to compute!";
			else std::cout << i << "! = " << f << "\n";

			break;
		case 6:
			MakeLists();

			AddPolynomials(polynomialList1, polynomialList2);

			break;
		case 7:
			MakeLists();

			MultiplyPolynomials(polynomialList1, polynomialList2);

			break;

		case 8:
			MakeList1();

			DerivatePolynomial(polynomialList1);

			break;

		case 9:

			running = false;

			break;

		case 0:
			//Input was not accepted

			break;

		default:

			std::cout << "That input is not accepted!";
		}
	}

	return 0;
}

/// <summary>
/// Lets user set length and values of two lists
/// </summary>
void MakeLists()
{
	MakeList1();
	MakeList2();
}

/// <summary>
/// Lets user set length and values for list 1
/// </summary>
void MakeList1()
{
	polynomialList1.clear();

	int l = GetPositiveInt("What is the length of the polynomial? ");
	int val;

	for (int i = 0; i < l; i++)
	{
		string t = "Value " + to_string(i) + ": ";

		char const* n_char = t.c_str();

		val = GetInt(n_char);

		polynomialList1.push_back(val);
	}
}

/// <summary>
/// Lets user set length and values for list 2
/// </summary>
void MakeList2()
{
	polynomialList2.clear();

	int l = GetPositiveInt("What is the length of the second polynomial? ");
	int val;

	for (int i = 0; i < l; i++)
	{
		string t = "Value " + to_string(i) + ": ";

		char const* n_char = t.c_str();

		val = GetInt(n_char);

		polynomialList2.push_back(val);
	}
}