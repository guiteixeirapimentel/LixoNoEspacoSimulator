#pragma once
#include "Estado.h"
#include "NaveVoando.h"

class NaveVoando;

class NaveParada : public Estado
{
public:
	NaveParada(DadosSprite &dados) :Estado(dados){};
	virtual void QuandoAPrecionado()
	{
		dados.estado = new NaveVoando(dados);
		delete this;
	}

};