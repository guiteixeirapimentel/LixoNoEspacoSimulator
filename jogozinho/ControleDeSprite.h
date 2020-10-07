#pragma once
#include "Sprite.h"
#include "Estado.h"
#include "ControleXB.h"
#include "MaquinaDeParticulas.h"
#include "Equipavel.h"

class ControleDeSprite
{
public:
	ControleDeSprite(Sprite *sprite, ControleXBCliente &ctrl)
		:
		ctrl(ctrl),
		sprite(sprite)
	{}
	virtual void Checar();
protected:
	Sprite *sprite;
	ControleXBCliente &ctrl;
};
