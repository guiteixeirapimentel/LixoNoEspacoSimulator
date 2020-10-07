#pragma once
#include "Fundo.h"
#include "Lixo.h"
#include "Som.h"

class Mapa
{
public:
	Mapa(int alturaMapa, int alturaTela, const Sprite* sprite, DSound &som);
	~Mapa();
	
	void Desenhar(Camera &cam);
	void Atualizar();
	bool EstaColidindo();
private:
	Fundo fundo;
	Lixo **lixos;
	DSound &som;
	Sound musica;
	const Sprite* sprite;

	int ultimoTempo;
	int somTempos;
};