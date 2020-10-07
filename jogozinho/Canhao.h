#pragma once
#include "BalaDeCanhao.h"
#include "DadosSprite.h"
#include "Equipavel.h"

class Canhao : public Equipavel
{
public:
	Canhao(std::string nomeImg, PIXEL corFundo, std::string imgBala, PIXEL corFundoB, const DadosSprite& dados)
		:
		dados(dados),
		imagem(nomeImg, corFundo),
		imgBala(new ImagemSemFundo(imgBala, corFundoB))
	{
		this->cd = 30;
	}
	~Canhao()
	{
		delete imgBala;
	}

	void Desenhar(Camera & cam) override
	{
		for (UINT i = 0; i < balas.size(); i++)
		{
			balas[i].Desenhar(cam);
		}
		cam.DesenharImagem(&imagem, (int)dados.x + 35, (int)dados.y + 22);
	}

	void Atualizar() override
	{
		for (UINT i = 0; i < balas.size(); i++)
		{
			balas[i].Atualizar();
		}

		if (!pronto)
		{
			if (cd < cdPassado)
			{
				pronto = true;
			}
			else
			{
				cdPassado++;
			}
		}
	}

	void Usar() override
	{
		if (pronto)
		{
			Atirar(1, { dados.vx, dados.vy + -5.0f }, { 0.0f, 0.0f });
			pronto = false;
			cdPassado = 0;
		}
	}

private:
	void Atirar(UINT numBalas, VetorF velocI, VetorF alcance)
	{
		for (UINT i = 0; i < numBalas; i++)
		{
			balas.push_back(BalaDeCanhao({ float(dados.x + 65), float(dados.y + 22) }, velocI, alcance, imgBala));
		}
	}

private:
	const DadosSprite& dados;
	ImagemSemFundo imagem;
	const ImagemSemFundo* imgBala;
	std::vector<BalaDeCanhao> balas;
};