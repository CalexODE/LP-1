#include "menu.hpp"

int encontrarEmpresa();

vector<Empresa> vecEmpresas;
vector<Empresa>::iterator i;

void menu()
{

	cout<<"Ola, seja bem vindo!"<<endl;

	string nome;
	string cnpj;
	Empresa emp;
	float percen_aumento;
	int posicao_empresa;

	string nome_Funcionaro;
	string cpf_Funcionario;
	float salario_Funcionario;
	int sucesso;

	float media_de_funcionarios;
	int soma=0;

	while(true)
	{
		if (vecEmpresas.size() == 0)
		{
			//Criar Função "criar Empresa"
			cout<<"Ainda não ha empresas"<<endl<<endl;
			cout<<"Adicionar Empresa:"<<endl<<"Nome: ";
			cin>>nome;
			cout<<"CNPJ: ";
			cin>>cnpj;
			emp.setNome(nome);
			emp.setCNPJ(cnpj);
			vecEmpresas.push_back(emp);
		}
		else
		{
			int escolha = 0;
			string procurar;

			cout<<endl<<"Opções: "<<endl
			<<"1 - Adicionar Nova Empresa"<<endl
			<<"2 - Adicionar Funcionario à empresa"<<endl
			<<"3 - Remover Empresa"<<endl
			<<"4 - Listar Empresas"<<endl
			<<"5 - Listar Funcionarios de Empresa"<<endl
			<<"6 - Aumento de salario em todos os Funcionarios"<<endl
			<<"7 - Media de Funcionarios por Empresa"<<endl
			<<"0 - Sair"<<endl;
			cin>>escolha;

			if (escolha == 0)
			{
				break;
			}

			switch(escolha)
			{
				case 1:
					cout<<endl<<"Nome: ";
					cin>>nome;
					cout<<"CNPJ: ";
					cin>>cnpj;
					emp.setNome(nome);
					emp.setCNPJ(cnpj);
					vecEmpresas.push_back(emp);
					break;
				case 2:
					/**
					cout<<"Escolher Empresa(por cnpj): ";
					cin>>procurar;
					i = vecEmpresas.begin();

					for (int cont = 0; cont < vecEmpresas.size(); cont++)
					{
						//cout<<"cont: "<< cont<<" quantidade de Emp: "<<vecEmpresas.size();
						//cout<< " procurar: "<< procurar;
						//cout<<" cnpj: "<<(i+cont)->getCNPJ()<<endl;

						if ((i+cont)->getCNPJ().compare(procurar)==0)
						{
						}
					}
					*/
					posicao_empresa = encontrarEmpresa();
					if (posicao_empresa == -1)
					{
						cout<<"Empresa Não encontrada"<<endl;
					}
					else
					{
						cout<<"Nome do novo Funcionario: ";
						cin>>nome_Funcionaro;
						cout<<"CPF: ";
						cin>>cpf_Funcionario;
						cout<<"Salario: ";
						cin>>salario_Funcionario;

						sucesso = (i+posicao_empresa)->novoFuncionario(nome_Funcionaro,cpf_Funcionario,salario_Funcionario);
						if (sucesso == 0)
						{
							cout<<"Não foi possivel adicionar, Funcionario ja existente"<<endl;
						}
						else
						{
							cout<<"Sucesso ao adicionar funcionario"<<endl;
						}

					}
					break;
				case 3:
					cout<<"Escolher Empresa(por cnpj): ";
					cin>>procurar;
					i = vecEmpresas.begin();

					for (int cont = 0; cont < vecEmpresas.size(); cont++)
					{
						//cout<<"cont: "<< cont<<" quantidade de Emp: "<<vecEmpresas.size();
						//cout<< " procurar: "<< procurar;
						//cout<<" cnpj: "<<(i+cont)->getCNPJ()<<endl;

						if ((i+cont)->getCNPJ().compare(procurar)==0)
						{
							cout<<"Empresa "<<(i+cont)->getNome() <<endl;
							vecEmpresas.erase(i+cont);
						}
					}
					break;
				case 4:
					i = vecEmpresas.begin();

					for (int cont = 0; cont < vecEmpresas.size(); cont++)
					{
						cout<<"Empresa: "<< (i+cont)->getNome()
						<<"   CNPJ: "<<(i+cont)->getCNPJ()<<endl;
					}
					break;
				case 5:
					cout<<"Escolher Empresa(por cnpj): ";
					cin>>procurar;
					i = vecEmpresas.begin();

					for (int cont = 0; cont < vecEmpresas.size(); cont++)
					{
						cout<<"cont: "<< cont<<" quantidade de Emp: "<<vecEmpresas.size();
						cout<< " procurar: "<< procurar;
						cout<<" cnpj: "<<(i+cont)->getCNPJ()<<endl;

						if ((i+cont)->getCNPJ().compare(procurar)==0)
						{
							cout<<"Empresa: "<<(i+cont)->getNome()<<endl;
							(i+cont)->tFuncionarios();
						}
					}
					break;
				case 6:
					cout<<"Escolher Empresa(por cnpj): ";
					cin>>procurar;
					i = vecEmpresas.begin();

					for (int cont = 0; cont < vecEmpresas.size(); cont++)
					{
						//cout<<"cont: "<< cont<<" quantidade de Emp: "<<vecEmpresas.size();
						//cout<< " procurar: "<< procurar;
						//cout<<" cnpj: "<<(i+cont)->getCNPJ()<<endl;

						if ((i+cont)->getCNPJ().compare(procurar)==0)
						{
							cout<<"Empresa: "<<(i+cont)->getNome() <<endl;
							cout<<"Aumento em porcentagem: ";
							cin>>percen_aumento;
							(i+cont)->aumentoSalario(percen_aumento);
						}
					}
					break;
				case 7:
					i = vecEmpresas.begin();

					for (int cont = 0; cont < vecEmpresas.size(); cont++)
					{
						soma+=(i+cont)->numeroDeFuncionarios();
					}

					media_de_funcionarios = soma/vecEmpresas.size();
					cout<<"Media de Funcionarios: "<<media_de_funcionarios<<endl<<endl;
					break;


				default:
					cout<<"valor Invalido!"<<endl;
			}
		}
	}
}

void menuFuncionario()
{
	cout<<"menuFuncionario"<<endl;
}
int encontrarEmpresa()
{
	string procurar;
	cout<<"Escolher Empresa(por cnpj): ";
	cin>>procurar;
	i = vecEmpresas.begin();

	for (int cont = 0; cont < vecEmpresas.size(); cont++)
	{
//cout<<"cont: "<< cont<<" quantidade de Emp: "<<vecEmpresas.size();
//cout<< " procurar: "<< procurar;
//cout<<" cnpj: "<<(i+cont)->getCNPJ()<<endl;

		if ((i+cont)->getCNPJ().compare(procurar)==0)
		{
			cout<<"Empresa "<<(i+cont)->getNome() <<endl;
			return cont;
		}
	}
	return -1;
}