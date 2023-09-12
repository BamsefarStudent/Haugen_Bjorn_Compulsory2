#pragma once

#ifndef _IOSTREAM_
#define _IOSTREAM_
#endif

#ifndef _STD_
#define _STD_
#endif

#include <list>;
#include <string>;

using namespace std;


#pragma region Declaring Functions

int AskUserForOperation();

long double Add(double a, double b);
long double Subtract(double a, double b);
long double Multiply(double a, double b);
long double Divide(double a, double b);
unsigned long long int Factorial(int i);


void MultiplyPolynomials(list <int> l, list <int> m);
void AddPolynomials(list<int> l, list<int> m);
void DerivatePolynomial(list<int> l);

bool CheckForCinFail();
int GetInt(const char* c);
void PrintList(list<int> l);
void PrintPolynomialList(list<int> l);

#pragma endregion


/// <summary>
/// Prints options to user and returns chosen option
/// </summary>
/// <returns>int - option chosen by user</returns>
int AskUserForOperation()
{
	std::cout << "\nWhat would you like to do? \n";
	std::cout << "1. Addition \n";
	std::cout << "2. Subtraction \n";
	std::cout << "3. Multiplication \n";
	std::cout << "4. Division \n";
	std::cout << "5. Factorial \n";
	std::cout << "6. Add two polynomials \n";
	std::cout << "7. Multiply two polynomials \n";
	std::cout << "8. Derivate a polynomial \n";
	std::cout << "9. End program \n";

	int choice;

	std::cin >> choice;

	if (!CheckForCinFail()) return 0;

	return choice;
}

/// <summary>
/// Adds two values
/// </summary>
/// <param name="a">- term</param>
/// <param name="b">- term</param>
/// <returns>sum of values</returns>
long double Add(double a, double b)
{
	return a + b;
}

/// <summary>
/// Subtracts two values
/// </summary>
/// <param name="a">- term</param>
/// <param name="b">- term</param>
/// <returns>difference of values</returns>
long double Subtract(double a, double b)
{
	return a - b;
}

/// <summary>
/// Multiplies two values
/// </summary>
/// <param name="a">- factor</param>
/// <param name="b">- factor</param>
/// <returns>product of values</returns>
long double Multiply(double a, double b)
{
	return a * b;
}

/// <summary>
/// Divides two values
/// </summary>
/// <param name="a">- dividend</param>
/// <param name="b">- divisor</param>
/// <returns>fraction of values</returns>
long double Divide(double a, double b)
{
	return a / b;
}

/// <summary>
/// Takes the factorial of an int
/// </summary>
/// <param name="i">- value</param>
/// <returns>factorial of value</returns>
unsigned long long int Factorial(int i)
{
	if (i > 0)
	{
		return i * Factorial(i - 1);
	}
	else
	{
		return 1;
	}
}

/// <summary>
/// Multiplies together two basic polynomials
/// </summary>
/// <param name="l">- list of values representing a polynomial</param>
/// <param name="m">- list of values representing a polynomial</param>
/// <returns>void - prints out the product of the two polynomials</returns>
void MultiplyPolynomials(list <int> l, list <int> m)
{
	list<int> productList;

	for (int i = 0; i < l.size() + m.size() - 1; i++)
	{
		productList.push_back(0);
	}

	for (int i = 0; i < l.size(); i++)
	{
		for (int j = 0; j < m.size(); j++)
		{
			int productPos = i + j;
			auto tempL = l.begin();
			auto tempM = m.begin();
			auto tempP = productList.begin();

			std::advance(tempL, i);
			std::advance(tempM, j);
			std::advance(tempP, productPos);

			*tempP += *tempL * *tempM;
		}
	}

	PrintPolynomialList(l); std::cout << "\n * "; PrintPolynomialList(m); std::cout << "\n = "; PrintPolynomialList(productList); std::cout << "\n";
}

/// <summary>
/// Adds two basic polynomials together
/// </summary>
/// <param name="l">- list of values representing a polynomial</param>
/// <param name="m">- list of values representing a polynomial</param>
/// <returns>void - prints out the sum of the two polynomials</returns>
void AddPolynomials(list<int> l, list<int> m)
{
	list<int> sumList;
	auto tempL = l.begin();
	auto tempM = m.begin();

	std::advance(tempL, l.size() - 1);
	std::advance(tempM, m.size() - 1);

	for (tempL, tempM; tempL != l.begin() && tempM != m.begin(); tempL--, tempM--)
	{
		sumList.push_front(*tempL + *tempM);
	}

	//Adds the remaining elements from the positions based on the shortest list
	sumList.push_front(*tempL + *tempM);

	//Adds remaining elements from longest list
	if (tempL != l.begin())
	{
		tempL--;
		for (tempL; tempL != l.begin(); tempL--)
		{
			sumList.push_front(*tempL);
		}
		sumList.push_front(*tempL);
	}
	else if (tempM != m.begin())
	{
		tempM--;
		for (tempM; tempM != m.begin(); tempM--)
		{
			sumList.push_front(*tempM);
		}
		sumList.push_front(*tempM);
	}

	PrintPolynomialList(l); std::cout << "\n + "; PrintPolynomialList(m); std::cout << "\n = "; PrintPolynomialList(sumList); std::cout << "\n";
}

/// <summary>
/// Derivates a basic polynomial
/// </summary>
/// <param name="l">- list of values representing a polynomial</param>
/// <returns>void - prints out the derivative of the polynomial</returns>
void DerivatePolynomial(list<int> l)
{
	list<int> derivative;

	auto tempL = l.begin();

	for (int i = 0; i < l.size() - 1; i++)
	{
		int a = *tempL;

		derivative.push_back(a * (l.size() - 1 - i));

		std::advance(tempL, 1);
	}

	std::cout << "The derivative of "; PrintPolynomialList(l); std::cout << " = "; PrintPolynomialList(derivative); std::cout << "\n";
}

/// <summary>
/// Checks if std::cin fails to run correctly, and clears the input
/// </summary>
/// <returns>bool - Whether std::cin failed to run</returns>
bool CheckForCinFail()
{
	if (std::cin.fail())
	{
		std::cout << "That is not a valid option! \n\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		return false;
	}

	return true;
}

/// <summary>
/// Loops until user inputs an integer
/// </summary>
/// <param name="c">- text to print out to user</param>
/// <returns>int</returns>
int GetInt(const char* c)
{
	int num;
	bool notNum = true;

	while (notNum)
	{
		std::cout << c;
		std::cin >> num;

		if (!CheckForCinFail())
		{
			notNum = true;
		}
		else notNum = false;
	}

	return num;
}

/// <summary>
/// Loops until user inputs a double
/// </summary>
/// <param name="c">- text to print out to user</param>
/// <returns>double</returns>
double GetDouble(const char* c)
{
	double num;
	bool notNum = true;

	while (notNum)
	{
		std::cout << c;
		std::cin >> num;

		if (!CheckForCinFail())
		{
			notNum = true;
		}
		else notNum = false;
	}

	return num;
}

/// <summary>
/// Loops until user inputs a positive integer
/// </summary>
/// <param name="c">- text to print out to user</param>
/// <returns>int >= 0</returns>
int GetPositiveInt(const char* c)
{
	int myInt;
	bool notPositive = true;
	while (notPositive)
	{
		myInt = GetInt(c);

		if (myInt < 0) notPositive = true;
		else notPositive = false;
	}

	return myInt;
}

/// <summary>
/// Prints out a list translated into a basic polynomial function
/// </summary>
/// <param name="l">- list to print as polynomial</param>
/// <returns>void - prints out polynomial</returns>
void PrintPolynomialList(std::list<int> l)
{
	auto lPos = l.begin();
	bool printOperator = false;

	//Goes through all elements of the inserted list l
	for (int i = 0; i < l.size(); i++)
	{
		if (*lPos != 0)
		{
			//Adds a + or - if this element is printed after another element
			if (printOperator)
			{
				if (*lPos < 0) std::cout << " - ";
				else std::cout << " + ";
			}
			//Prints out correct value for current element
			if (abs(*lPos) != 1 || i + 1 >= l.size())
			{
				if (i == 0) std::cout << *lPos;
				else std::cout << abs(*lPos);
			}

			//Adds x expression to printed value
			if (i + 1 < l.size())
			{
				std::cout << "x";
				if (l.size() - i - 1 > 1) std::cout << "^" << l.size() - i - 1;
			}
			printOperator = true;
		}
		std::advance(lPos, 1);
	}
}

/// <summary>
/// Prints out a list
/// </summary>
/// <param name="l">- list to print</param>
/// <returns>void - print out the list</returns>
void PrintList(std::list<int> l)
{
	list<int>::iterator it;

	for (it = l.begin(); it != l.end(); ++it)
	{
		std::cout << "\t" << *it;
	}
	std::cout << "\n";
}