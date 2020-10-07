#pragma once
#include "Imagem.h"

class ImagemSemFundo : public Imagem
{
public:
	ImagemSemFundo(std::string nomeArquivo, PIXEL corFundo);

	virtual void DesenharImagem(int x, int y, D3DGraficos &dxd) const;
	virtual void DesenharParte(int xInicial, int yInicial, int xFinal, int yFinal, int x, int y, D3DGraficos &dxd) const;

protected:
	PIXEL corFundo;
};