#include "Fundo.h"

Fundo::Fundo(int alturaMapa, int alturaTela)
:
alturaMapa(alturaMapa),
alturaTela(alturaTela)
{
	imagens = new Imagem*[alturaMapa];
	imagens[0] = new Imagem("data\\PT.gui");
	imagens[1] = new Imagem("data\\Estr.gui");

	for (int i = 2; i < alturaMapa; i++)
	{
		imagens[i] = imagens[1];
	}
}

void Fundo::Desenhar(Camera& cam, const Sprite* sprite)
{
	int index = (int)(sprite->PegaY() - 600) / alturaTela;
	if (index == 0)
	{
		index = 1;
	}
	else if (index < 0)
	{
		index *= -1;
	}
	for (int i = index - 1; i <= index + 1; i++)
	{
		cam.DesenharImagem(imagens[i], 0, -i * alturaTela);
	}
}