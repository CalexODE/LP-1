#include "empresa.hpp"



//Construtores
Empresa::Empresa()
{
	std::cout << "Empresa OK!" << std::endl;
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
void Empresa::novoFuncionario(string nome, string cpf, float salario)
{
	Funcionario func(nome, cpf, salario);
	
	vector<Funcionario>::iterator ponteiroVec;
	ponteiroVec = vetFunc.begin();
	bool existencia = false;


	//cout << vetFunc.size()<< endl;
	
	if(vetFunc.size() == 0)
	{
		vetFunc.push_back(func);
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
			cout << "Funcionario já existe!!"<< endl;
		}
		else
		{
			vetFunc.push_back(func);
		}
	}

}


void Empresa::mostraFuncionario(int n)
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();
	cout << " size: "<<vetFunc.size()<<endl;
	cout<<"Nome: "<<(i+n)->getNome()<<" CPF: "<<(i+n)->getCpf()<<" Salario: "<<(i+n)->getSalario();
	(i+n)->getData();
}

void Empresa::tFuncionarios()
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();
	//cout << vetFunc.size() << endl;

	//int cont = 0;
	//while (cont <= vetFunc.size() - 1)
	//{
	//	cout <<"cont: " << cont << endl;
	//	cout << *(i+cont) << endl;
	//	cont++;

	//}

	for (int cont = 0; cont <= vetFunc.size()-1; cont++)
	{
		cout << *(i+cont) << endl;
		//cout <<"cont"<< cont << endl;
	}
	//cout << "Saiu!" << endl;
}

void Empresa::aumentoSalario(float perc)
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();

	float salario = i->getSalario();
	cout << salario << endl; 
	for (int cont = 0; cont <= vetFunc.size()-1; cont++)
	{

		cout <<"Salario antes do aumento: "<< cont << "  "<< (i+cont)->getSalario()<<endl;
		(i+cont)->setSalario((i+cont)->getSalario() + (((i+cont)->getSalario()) * (perc/100)));
		cout << "Salario Atual: " << (i+cont)->getSalario()<< endl;
	}
}