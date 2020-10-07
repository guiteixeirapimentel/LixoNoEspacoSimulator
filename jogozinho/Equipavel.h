#pragma once
#include "Camera.h"

class Equipavel
{
public:
	virtual void Usar() = 0;
	virtual void Desenhar(Camera &cam) = 0;
	virtual void Atualizar() = 0;
public:
	bool vazio = true;
protected:
	//COOLDOWN = TEMPO DE ESPERA - PADRAO 60 FRAMES(1 SEG)
	UINT cd = 60;
	UINT cdPassado = 0;

	bool pronto = true;
};