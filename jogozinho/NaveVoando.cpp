#include "NaveVoando.h"
#include "NaveCaindo.h"

void NaveVoando::QuandoASolto()
{
	dados.estado = new NaveCaindo(dados);
	delete this;
}