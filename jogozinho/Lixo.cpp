#include "Lixo.h"

Lixo::Lixo(std::string nome, PIXEL corFundo, float x, float y)
:
x(x),
y(y)
{
	imagem = new ImagemComRetangulo(nome, corFundo);

	RetanguloI ** ret = imagem->PegarRetangulos();
	int numRet = imagem->PegarNRetangulos();
	for (int i = 0; i < numRet; i++)
	{
		ret[i]->MoverPara((int)x + ret[i]->esquerda, (int)y + ret[i]->cima);
	}
}

void Lixo::Desenhar(Camera &cam)
{
	cam.DesenharImagemComRetangulos(imagem, (int)x, (int)y);
}

bool Lixo::EstaColidindoCom(const Sprite* sprite) const
{
	const int nRet = sprite->PegarNRetangulos();
	RetanguloI** rets = sprite->PegaRetCol();
	for (int i = 0; i < nRet; i++)
	{
		const int nRetD = imagem->PegarNRetangulos();
		RetanguloI** retsD = imagem->PegarRetangulos();
		for (int id = 0; id < nRetD; id++)
		{
			if (rets[i]->EstaColidindoCom(retsD[id]))
			{
				return true;
			}
		}		
	}
	return false;
}

void Lixo::Atualizar(const Sprite* sprite)
{
	if (sprite->PegaY() < y - 900)
	{
		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> distx(0, D3DGraficos::LARGURA);
		std::uniform_int_distribution<int> disty(500, D3DGraficos::ALTURA);
		x = (float)distx(mt);

		while(y > sprite->PegaY() - 700)
		{
			y = (float)disty(mt);
			y *= (((sprite->PegaY() * -1) / D3DGraficos::ALTURA) + 3);
			y *= -1;
		}

		RetanguloI ** ret = imagem->PegarRetangulos();
		int numRet = imagem->PegarNRetangulos();
		for (int i = 0; i < numRet; i++)
		{
			ret[i]->MoverPara(int(x + ret[i]->esquerdaC), int(y + ret[i]->cimaC));
		}
	}
}