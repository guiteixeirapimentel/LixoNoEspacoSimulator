#pragma once
#include "Imagem.h"
#include "Ret.h"

class ImagemComRetangulo
{
public:
	ImagemComRetangulo(std::string nomeArquivo, PIXEL corFundo);
	~ImagemComRetangulo();
	virtual void DesenharImagem(int x, int y, D3DGraficos &dxd);
	void DesenharParte(int xInicial, int yInicial, int xFinal, int yFinal, int x, int y, D3DGraficos &dxd);

	RetanguloI** PegarRetangulos() const;
	const int PegarNRetangulos() const;
	const PIXEL* PegarPixels() const;
	unsigned int PegaLargura() const;
	unsigned int PegaAltura() const;

protected:
	unsigned int largura;
	unsigned int altura;
	PIXEL *pixels;

	PIXEL corFundo;
	RetanguloI **rets;
	int nRets;
};