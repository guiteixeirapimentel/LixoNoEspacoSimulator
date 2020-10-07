#pragma once
#include "Camera.h"
#include "ImagemSemFundo.h"

class Particula
{
public:
	Particula(const ImagemSemFundo *imagem, float x, float y, float vX, float vY, float aX, float aY, int tempoDeVida)
		:
		posX(x),
		posY(y),
		vX(vX),
		vY(vY),
		aX(aX),
		aY(aY),
		tempoDeVida(tempoDeVida),
		imagem(imagem)
	{}
	void Desenhar(Camera& cam)
	{
		cam.DesenharParticula(*this);
	}
	//Atualiza Velocidade e TempoDevida
	//Retorna TRUE se a Particula Morreu
	bool Atualizar()
	{
		if (tempoDeVida > 0)
		{
			tempoDeVida--;

			vX += aX;
			vY += aY;
			posX += vX;
			posY += vY;
			return false;
		}
			return true;
	}

	const ImagemSemFundo* PegaImagem() const
	{
		return imagem;
	}
public:
	float posX;
	float posY;

	float vX;
	float vY;

	float aX;
	float aY;

	int tempoDeVida;
	
	const ImagemSemFundo *imagem;
};