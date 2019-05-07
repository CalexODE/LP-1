#include "menu.hpp"

//Funcção que verifica se uma empresa já existe
//Uma empresa já existe se o cnpj já pertence a outra empresa
//Retorna a posição da empresa no vetor caso exista, caso contrário retorna -1
int encontrarEmpresa(string procurar);

vector<Empresa> vecEmpresas;
vector<Empresa>::iterator i;

void menu()
{
	cout<<"Manipulação de empresas e funcionarios"<<endl<<endl;

	//Variaveis para uso na manipulação das empresas
	string nome;
	string cnpj;
	Empresa emp;
	float percen_aumento;
	int posicao_empresa;

	//Variaveis para uso na manipulação dos funcionarios
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


			//menu para escolha de opções
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

					posicao_empresa = encontrarEmpresa(cnpj);

					if (posicao_empresa == -1)
					{
						vecEmpresas.push_back(emp);
					}
					else
					{
						cout<<"Empresa ja existente"<<endl;
					}
					break;
				case 2:

					cout<<"Escolher Empresa(por cnpj): ";
					cin>>procurar;

					posicao_empresa = encontrarEmpresa(procurar);

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
					
					posicao_empresa = encontrarEmpresa(procurar);
					
					if (posicao_empresa == -1)
					{
						cout<<"Empresa Não encontrada"<<endl;
					}
					else
					{
						vecEmpresas.erase(i+posicao_empresa);
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

					posicao_empresa = encontrarEmpresa(procurar);

					if (posicao_empresa == -1)
					{
						cout<<"Empresa Não encontrada"<<endl;
					}
					else
					{
						(i+posicao_empresa)->tFuncionarios();
					}
					break;
				case 6:
					cout<<"Escolher Empresa(por cnpj): ";
					cin>>procurar;
					i = vecEmpresas.begin();

					posicao_empresa = encontrarEmpresa(procurar);

					if (posicao_empresa == -1)
					{
						cout<<"Empresa Não encontrada"<<endl;
					}
					else
					{
						cout<<"Aumento em porcentagem: ";
						cin>>percen_aumento;
						(i+posicao_empresa)->aumentoSalario(percen_aumento);
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

int encontrarEmpresa(string procurar)
{
	i = vecEmpresas.begin();

	for (int cont = 0; cont < vecEmpresas.size(); cont++)
	{
		if ((i+cont)->getCNPJ().compare(procurar)==0)
		{
			cout<<"Empresa "<<(i+cont)->getNome() <<endl;
			return cont;
		}
	}
	return -1;
}