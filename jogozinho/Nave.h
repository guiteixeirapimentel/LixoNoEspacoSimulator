#pragma once
#include "Sprite.h"
#include "Estado.h"
#include "NaveParada.h"
#include "Camera.h"
#include "Equipavel.h"
#include "Canhao.h"

class Nave : public Sprite
{
public:
	Nave(std::string nomeBase, unsigned int numImagens, unsigned int delay, PIXEL corFundo,
		float x, float y, MaquinaDeParticulas *m);
	~Nave();

	void Desenhar(Camera &cam);
	void Atualizar();
};