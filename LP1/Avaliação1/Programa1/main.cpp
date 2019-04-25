#include "funcionario.h"
#include <iostream>
#include "empresa.h"

int main()
{




	Empresa emp;
	emp.setNome("Coca-cola");
	std::cout << emp.getNome() << std::endl;


	Funcionario func1;
	func1.setNome("alexandre");
	func1.setCpf("12345");
	std::cout << func1.getCpf() << std::endl;

	Funcionario func2;
	func2.setCpf("12344");
	std::cout << func2.getCpf() << std::endl;


	if (func1 == func2)
	{
		std::cout << "TRUE" << std::endl;
	}
	else
	{
		std::cout << "FALSE" << std::endl; 
	}
	return 0;
}