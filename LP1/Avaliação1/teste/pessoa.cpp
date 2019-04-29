#include "pessoa.hpp"

Pessoa::Pessoa(float altura)
{
	this->altura = altura;
}
void Pessoa::chutarBola()
{
	Bola b;
	b.encher();
}