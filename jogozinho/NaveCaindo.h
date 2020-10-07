#pragma once
#include "Estado.h"
#include "NaveParada.h"
#include "NaveVoando.h"

class NaveCaindo : public Estado
{
public:
	NaveCaindo(DadosSprite &dados) :Estado(dados)
	{
		dados.atual = dados.seqImg[0];
	}
	virtual void QuandoAPrecionado()
	{
		dados.estado = new NaveVoando(dados);
		delete this;
	}

	virtual void QuandoAtualizar()
	{
		if (velM > dados.vy)
		{
			dados.vy += gravidade;
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
		if (dados.y > 607)
		{
			dados.y = 607;
			dados.vy = 0.0f;
			dados.vx = 0.0f;
			dados.estado = new NaveParada(dados);
			delete this;
			return;
		}
	}

	virtual void QuandoDirPrecionado()
	{
		if (dados.vx < velMaximaX)
		{
			dados.vx += aceX;
		}
		dados.virando = true;
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
	virtual void QuandoEsqPrecionado()
	{
		if (-dados.vx < velMaximaX)
		{
			dados.vx -= aceX;
			dados.virando = true;
		}
	}

protected:
	const float gravidade = 0.10f;
	const float velM = 10.5f;
	const float velMaximaX = 3.5f;
	float aceX = 0.5f;
	float aceY = 0.05f;
};