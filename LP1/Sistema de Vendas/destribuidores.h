#include <string>
#include "produtos.h"

using namespace std;

typedef struct
{
	string nome;
	string razao_social;
	string cnpj_cpf;
	string telefone;
	string email;
}campos;

typedef struct
{
	string id_produto;
	float valor;
}produto;

class destribuidores
{
private:
	long id;

public:
	//Faz de conta que aqui tem metodos set & get
};