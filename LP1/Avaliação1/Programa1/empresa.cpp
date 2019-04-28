#include "empresa.hpp"

Empresa::Empresa()
{
	std::cout << "Empresa OK!" << std::endl;
}
void Empresa::setNome(string nome)
{
	this->nome = nome;
}
string Empresa::getNome()
{
	return this->nome;
}

void Empresa::setCNPJ(string CNPJ)
{
	this->CNPJ = CNPJ;
}
string Empresa::getCNPJ()
{
	return this->CNPJ;
}

void Empresa::novoFuncionario(string nome, string cpf, float salario)
{
	Funcionario func(nome, cpf, salario);
	
	vector<Funcionario>::iterator ponteiroVec;
	ponteiroVec = vetFunc.begin();
	bool existencia = false;


	cout << vetFunc.size()<< endl;
	
	if(vetFunc.size() == 0)
	{
		vetFunc.push_back(func);
	}
	else
	{
		for (int i = 0; i <= vetFunc.size(); i++)
		{
			cout << "i: " << i <<" "<<vetFunc.size()<<endl;
			if(*(ponteiroVec+i) == func)
			{
				cout << "existe" << endl;
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

	//func.setNome(nome);
	//func.setCpf(cpf);
	//func.setSalario(salario);

}

void Empresa::mostraFunc(int n)
{
	vector<Funcionario>::iterator i;
	i = vetFunc.begin();
	cout << " size: "<<vetFunc.size()<<endl;
	cout<<"Nome: "<<(i+n)->getNome()<<" CPF: "<<(i+n)->getCpf()<<" Salario: "<<(i+n)->getSalario()<<endl;
}