//#include "funcionario.hpp"
#include "empresa.hpp"

#include <vector>
#include <iostream>
#include <time.h>
int main()
{
	Empresa emp1;
	emp1.novoFuncionario("Alexandre", "123345567", 123.4);
	emp1.mostraFuncionario(0);

	emp1.novoFuncionario("Aline", "12345567", 234.3);
	std::cout<< "hora de mostrar"<<std::endl;
	emp1.mostraFuncionario(1);
	emp1.mostraFuncionario(0);

	emp1.tFuncionarios();

	emp1.aumentoSalario(100.0);

	/**
	std::vector<int> vetFunc;

	//Funcionario func1;
	//func1.setNome("Alexandre");
	vetFunc.push_back(12);

	std::vector<int>::iterator i;

	i = vetFunc.begin();

	std::cout << vetFunc << std::endl;

	time_t timer;
  	struct tm *horarioLocal;

  	time(&timer); // Obtem informações de data e hora
  	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  	int dia = horarioLocal->tm_mday;
  	int mes = horarioLocal->tm_mon + 1;
	int ano = horarioLocal->tm_year + 1900;

	std::cout<< dia <<"/"<<mes<<"/"<<ano<<std::endl;



	Empresa emp1;
	emp1.setNome("Netflix");
	emp1.novoFuncionario();


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
	*/
	return 0;
}