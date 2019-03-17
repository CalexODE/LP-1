#include <string.h>

class CadastrodeClientes
{
private:
	string nome;
	string telefone;
	string email;
public:
	void setNome(string);
	string getNome(void);
	
	void setTelefone(string);
	string getTelefone(void);

	void setEmail(string);
	string getEmail(void);

};