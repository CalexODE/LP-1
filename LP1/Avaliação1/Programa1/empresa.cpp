#include "empresa.hpp"



//Construtor(es)
Empresa::Empresa()
{
	//std::cout << "Empresa OK!" << std::endl;
}

//Nome da empresa
void Empresa::setNome(string nome)
{
	this->nome = nome;
}
string Empresa::getNome()
{
	return this->nome;
}

//CNPJ
void Empresa::setCNPJ(string CNPJ)
{
	this->CNPJ = CNPJ;
}
string Empresa::getCNPJ()
{
	return this->CNPJ;
}


//Adicionar novo funcionario
int Empresa::novoFuncionario(string nome, string cpf, float salario)
{
	Funcionario func(nome, cpf, salario);
	
	vector<Funcionario>::iterator ponteiroVec;
	ponteiroVec = vetFunc.begin();
	bool existencia = false;


	//cout << vetFunc.size()<< endl;
	
	if(vetFunc.size() == 0)
	{
		vetFunc.push_back(func);
		return 1;
	}
	else
	{
		for (int i = 0; i <= vetFunc.size(); i++)
		{
			//cout << "i: " << i <<" "<<vetFunc.size()<<endl;
			if(*(ponteiroVec+i) == func)
			{
				//cout << "existe" << endl;
				existencia = true;
				break;
			}
		}
		if(existencia)
		{
			return 0;
		}
		else
		{
			vetFunc.push_back(func);
			return 1;
		}
	}

}

/*
void Empresa::mostraFuncionario(int n)
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();
	cout << " size: "<<vetFunc.size()<<endl;
	cout<<"Nome: "<<(i+n)->getNome()<<" CPF: "<<(i+n)->getCpf()<<" Salario: "<<(i+n)->getSalario();
	(i+n)->getData();
}
*/


//Aumento de todos os funcionarios de uma empresa
//Baseado em uma porcentagem
void Empresa::aumentoSalario(float perc)
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();

	//float salario = i->getSalario();
	//cout << salario << endl; 
	for (int cont = 0; cont < vetFunc.size(); cont++)
	{

		//cout <<"Salario antes do aumento: "<< cont << "  "<< (i+cont)->getSalario()<<endl;
		(i+cont)->setSalario((i+cont)->getSalario() + (((i+cont)->getSalario()) * (perc/100)));
		//cout << "Salario Atual: " << (i+cont)->getSalario()<< endl;
	}
}

void Empresa::tFuncionarios()
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();

	for (int cont = 0; cont < vetFunc.size(); cont++)
	{
		cout << *(i+cont) << endl;
	}
}

//funcionarios de até 90 dias de admissão

void Empresa::tFuncionariosNovos()
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();
	double dias_admissao, dias_totais;

	time_t timer;
	struct tm *horarioLocal;

	time(&timer); // Obtem informações de data e hora
	horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

	int dia = horarioLocal->tm_mday;
	int mes = horarioLocal->tm_mon + 1;
	int ano = horarioLocal->tm_year + 1900;
	
	dias_totais = (ano * 365) + (mes * 30) + dia;

	bool mostrar = false;
	for (int cont = 0; cont <= vetFunc.size()-1; cont++)
	{
		dias_admissao = ((i+cont)->getAno_ad() * 365) + (i+cont)->getMes_ad() * 30 + ((i+cont)->getDia_ad());
		if ((dias_totais - dias_admissao) <= 90)
		{
			cout << *(i+cont) << endl;
		}
	}
}

int Empresa::numeroDeFuncionarios()
{
	return vetFunc.size();
}

