#include <string>

class CadastrodeClientes
{
private:
	std::string nome;
	std::string telefone;
	std::string email;
public:
	void setNome(std::string);
	std::string getNome(void);
	
	void setTelefone(std::string);
	std::string getTelefone(void);

	void setEmail(std::string);
	std::string getEmail(void);
};