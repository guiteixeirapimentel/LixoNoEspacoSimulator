#include "ImagemSemFundo.h"

ImagemSemFundo::ImagemSemFundo(std::string nomeArquivo, PIXEL corFundo)
:
Imagem(nomeArquivo),
corFundo(corFundo)
{}

void ImagemSemFundo::DesenharImagem(int x, int y, D3DGraficos &dxd) const
{
	for (unsigned int iy = 0; iy < altura; iy++)
	{
		for (unsigned int ix = 0; ix < largura; ix++)
		{
			unsigned int i = ix + iy*largura;
			if (pixels[i] != corFundo)
			{
				char r = pixels[ix + iy * largura].r;
				char g = pixels[ix + iy * largura].g;
				char b = pixels[ix + iy * largura].b;
				dxd.ColocarPixel(ix + x, iy + y, D3DCOLOR_XRGB(r, g, b));
			}
		}
	}
}

void ImagemSemFundo::DesenharParte(int xInicial, int yInicial, int xFinal, int yFinal, int x, int y, D3DGraficos &dxd) const
{
	for (int iy = yInicial; iy < yFinal; iy++)
	{
		for (int ix = xInicial; ix < xFinal; ix++)
		{
			int i = ix + iy*largura;
			if (pixels[i] != corFundo)
			{
				char r = pixels[ix + iy * largura].r;
				char g = pixels[ix + iy * largura].g;
				char b = pixels[ix + iy * largura].b;
				dxd.ColocarPixel(ix + x, iy + y, D3DCOLOR_XRGB(r, g, b));
			}
		}
	}
}