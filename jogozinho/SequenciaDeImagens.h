#pragma once
#include "D3DGraficos.h"
#include "Camera.h"
#include "ImagemComRetangulo.h"

class SequenciaDeImagens
{
public:
	SequenciaDeImagens(std::string nomeBase, unsigned int numImagens, unsigned int delayQuadros, PIXEL corFundo);
	~SequenciaDeImagens();
	void Atualizar();
	void Desenhar(int x, int y, Camera &cam);
	unsigned int PegaAltura()
	{
		return imagens[imagemAtual]->PegaAltura();
	}
	unsigned int PegaLargura()
	{
		return imagens[imagemAtual]->PegaLargura();
	}
	RetanguloI ** PegarRetangulos() const
	{
		return imagens[imagemAtual]->PegarRetangulos();
	}
	int PegarNRetangulos() const
	{
		return imagens[imagemAtual]->PegarNRetangulos();
	}
private:
	ImagemComRetangulo **imagens;
	const unsigned int numImagens;
	unsigned int imagemAtual = 0;
	const unsigned int delayQuadros;
	unsigned int delayAtual = 0;
};