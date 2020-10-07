#pragma once
#include "Vetor.h"
#include "ImagemSemFundo.h"

class BalaDeCanhao
{
public:
	BalaDeCanhao(VetorF posI, VetorF velI, VetorF alcance, const ImagemSemFundo* imagem)
		:
		pos(posI),
		vel(velI),
		imagem(imagem),
		alcance(alcance)
	{}

	void Atualizar()
	{
		vel += aceleracao;
		pos += vel;
	}

	void Desenhar(Camera& cam)
	{
		cam.DesenharImagem(imagem, (int)pos.x, (int)pos.y);
	}
private:

	VetorF pos;
	VetorF vel;
	const VetorF alcance;
	const VetorF aceleracao = { 0.0f, 0.01f };

	const ImagemSemFundo *imagem;
};