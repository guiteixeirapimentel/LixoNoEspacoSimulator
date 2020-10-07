#include "SequenciaDeImagens.h"

SequenciaDeImagens::SequenciaDeImagens(std::string nomeBase, unsigned int numImagens, unsigned int delayQuadros, PIXEL corFundo)
:
numImagens(numImagens),
delayQuadros(delayQuadros)
{
	std::string buffer(nomeBase);
	imagens = new ImagemComRetangulo*[numImagens];

	for (unsigned int i = 0; i < numImagens; i++)
	{
		char t[2];
		_itoa_s(i, t, 10);
		buffer += t;
		buffer += ".guiR";
		imagens[i] = new ImagemComRetangulo(buffer, corFundo);
		buffer = nomeBase;
	}
}

SequenciaDeImagens::~SequenciaDeImagens()
{
	for (unsigned int i = 0; i < numImagens; i++)
	{
		delete imagens[i];
	}
	delete [] imagens;
}

void SequenciaDeImagens::Desenhar(int x, int y, Camera &cam)
{
	cam.DesenharImagemComRetangulos(imagens[imagemAtual], x, y);
}

void SequenciaDeImagens::Atualizar()
{
	if (delayAtual >= delayQuadros)
	{
		delayAtual = 0;
		if (imagemAtual < numImagens - 1)
		{
			imagemAtual++;
		}
		else
		{
			imagemAtual = 0;
		}
	}
	else
	{
		delayAtual++;
	}
}