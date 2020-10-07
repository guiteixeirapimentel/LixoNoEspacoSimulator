#pragma once
#include "ImagemSemFundo.h"

class Fonte
{
public:
	Fonte(std::string nomeArquivo, int larguraFonte, int alturaFonte, int letrasPorLinha);
	void EscreverLetra(int x, int y, char letra, PIXEL cor, D3DGraficos &dxd);
	void EscreverFrase(int x, int y, std::string frase, PIXEL cor, D3DGraficos &dxd);
protected:
	ImagemSemFundo imagem;
	const int letrasPorLinha;
	const int larguraFonte;
	const int alturaFonte;
};