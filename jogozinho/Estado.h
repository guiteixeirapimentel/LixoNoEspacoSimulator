#pragma once
#include "Som.h"
#include "Sprite.h"
#include "DadosSprite.h"

class Estado
{
public:
	Estado(DadosSprite &dados):dados(dados){}
	virtual ~Estado(){};
	virtual void QuandoAtualizar(){};
	virtual void QuandoAPrecionado(){};
	virtual void QuandoASolto(){};
	virtual void QuandoDirPrecionado(){}
	virtual void QuandoDirSolto(){ dados.virando = false; }
	virtual void QuandoEsqPrecionado(){};
	virtual void QuandoEsqSolto(){ dados.virando = false; }
	virtual void QuandoDirecionalEsq(float vx){}
	virtual void QuandoDirecionalDir(float vx){}
protected:
	DadosSprite &dados;
};