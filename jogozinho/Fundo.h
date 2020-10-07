#pragma once
#include "Camera.h"
#include "Sprite.h"

class Fundo
{
public:
	Fundo(int alturaMapa, int alturaTela);
	void Desenhar(Camera& cam, const Sprite* sprite);
private:
	Imagem **imagens;
	const int alturaMapa; // EM TELAS
	const int alturaTela;
};