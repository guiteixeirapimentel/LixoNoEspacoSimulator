#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Particula.h"

class MaquinaDeParticulas
{
public:
	MaquinaDeParticulas(std::string nomeImg, PIXEL corFundo, UINT numMaxP)
		:
		numMaxP(numMaxP),
		corPart(corPart),
		imagem(new ImagemSemFundo(nomeImg, corFundo))
	{
		srand((UINT)time(NULL));
	}
	~MaquinaDeParticulas()
	{
		delete imagem;
	}

	void Atualizar()
	{
		for (UINT i = 0; i < particulas.size(); i++)
		{
			if (particulas[i].Atualizar())
			{
				particulas[i] = particulas.back();
				particulas.pop_back();
				i--;
			}
		}
	}

	void Desenhar(Camera& cam)
	{
		for (UINT i = 0; i < particulas.size(); i++)
		{
			particulas[i].Desenhar(cam);
		}
	}

	void CriarParticulas(UINT num, float posX, float posY, float raio)
	{
		for (UINT i = 0; i < num; i++)
		{
			if (particulas.size() >= numMaxP)
			{
				break;
			}
			float x = float(rand() % (int)raio);
			float y = float(rand() % 20);
			float t = float((rand() % 10) + 1);
			t = t / 10;
			float vx = 0.0f;
			float vy = 0.01f;
			float ax = 0.0f;
			float ay = 0.01f * (float(rand() % 5) + 1.0f);
			particulas.push_back(Particula(imagem, posX+x, posY - 20 + y, vx, vy, ax, ay, int(60 * t)));
		}
	}

private:
	const UINT numMaxP;
	const PIXEL corPart;
	std::vector<Particula> particulas;
	const ImagemSemFundo* imagem;
};