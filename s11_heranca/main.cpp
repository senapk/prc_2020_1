
#include "medico.hpp"
#include "paciente.hpp"
#include <iostream>

int main()
{
	// Create a Patient outside the scope of the Doctor
	Patient dave{ "Dave" };
	Patient frank{ "Frank" };
	Patient betsy{ "Betsy" };
 
	Doctor james{ "James" };
	Doctor scott{ "Scott" };
 
	james.addPatient(dave);
 
	scott.addPatient(dave);
	scott.addPatient(betsy);
 
	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';
 
	return 0;
}