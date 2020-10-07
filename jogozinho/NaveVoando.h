#pragma once
#include "Estado.h"
class NaveCaindo;

class NaveVoando : public Estado
{
public:
	NaveVoando(DadosSprite &dados) :Estado(dados)
	{
		dados.atual = dados.seqImg[1];
	}
	virtual void QuandoASolto();
	virtual void QuandoDirPrecionado()
	{
		if (dados.vx < velMaximaX)
		{
			dados.vx += aceX;
		}
		dados.virando = true;
	}
	virtual void QuandoEsqPrecionado()
	{
		if (-dados.vx < velMaximaX)
		{
			dados.vx -= aceX;
		}
		dados.virando = true;
	}
	virtual void QuandoAtualizar()
	{
		if (dados.vy > velMaximaY)
		{
			dados.vy += aceY;
		}
		if (!dados.virando)
		{
			dados.vx *= 0.97f;
		}
		if (dados.x < 0)
		{
			dados.x = 0;
			dados.vx = 0.0f;
		}
		else if (dados.x > D3DGraficos::LARGURA - dados.atual->PegaLargura())
		{
			dados.x = float(D3DGraficos::LARGURA - dados.atual->PegaLargura());
			dados.vx = 0.0f;
		}
		dados.y += dados.vy;
		dados.x += dados.vx;

		dados.m->CriarParticulas(2, dados.x, dados.y + dados.atual->PegaAltura(), (float)dados.atual->PegaLargura());

		if (dados.y > 607)
		{
			dados.y = 607;
			dados.vy = 0.0f;
		}
	}
	virtual void QuandoDirecionalEsq(float vx)
	{
		if (vx < 0)
		{
			if (-dados.vx < velMaximaX)
			{
				dados.vx += (vx*aceX);
				dados.virando = true;
			}
		}
		else if (vx == 0)
		{
			dados.virando = false;
		}
		else
		{
			if (dados.vx < velMaximaX)
			{
				dados.vx += (vx*aceX);
				dados.virando = true;
			}
		}
	}
protected:
	const float velMaximaY = -10.5f;
	const float velMaximaX = 3.5f;
	float aceX = 0.50f;
	float aceY = -0.03f;
};