#include "Imagem.h"

Imagem::Imagem(std::string nomeArquivo)
{
	char larg[10];
	char alt[10];

	std::ifstream arq(nomeArquivo, std::ios::binary);

	unsigned int i = 0;
	do
	{
		arq.get(larg[i]);
		i++;
	} while (larg[i - 1] != '/');
	larg[i - 1] = 0;
	i = 0;
	do
	{
		arq.get(alt[i]);
		i++;
	} while (alt[i - 1] != '/');
	alt[i - 1] = 0;
	largura = atoi(larg);
	altura = atoi(alt);
	pixels = new PIXEL[largura * altura];

	char pix;
	i = 0;
	while (i < largura*altura)
	{
		arq.get(pix);
		pixels[i].r = pix;
		arq.get(pix);
		pixels[i].g = pix;
		arq.get(pix);
		pixels[i].b = pix;
		i++;
	}
}

Imagem::Imagem(unsigned int largura, unsigned int altura, PIXEL* pixels)
:
pixels(pixels),
largura(largura),
altura(altura)
{}

Imagem::~Imagem()
{
	delete pixels;
}

void Imagem::DesenharImagem(int x, int y, D3DGraficos& dxd)
{
	for (unsigned int iy = 0; iy < altura; iy++)
	{
		for (unsigned int ix = 0; ix < largura; ix++)
		{
			char r = pixels[ix + iy * largura].r;
			char g = pixels[ix + iy * largura].g;
			char b = pixels[ix + iy * largura].b;
			dxd.ColocarPixel(ix + x, iy + y, D3DCOLOR_XRGB(r, g, b));
		}
	}
}

void Imagem::DesenharParte(int xInicial, int yInicial, int xFinal, int yFinal, int x, int y, D3DGraficos &dxd) const
{
	for (int iy = yInicial; iy < yFinal; iy++)
	{
		for (int ix = xInicial; ix < xFinal; ix++)
		{
			char r = pixels[ix + iy * largura].r;
			char g = pixels[ix + iy * largura].g;
			char b = pixels[ix + iy * largura].b;
			dxd.ColocarPixel(ix + x, iy + y, D3DCOLOR_XRGB(r, g, b));
		}
	}
}

unsigned int Imagem::PegaAltura() const
{
	return altura;
}

unsigned int Imagem::PegaLargura() const
{
	return largura;
}

const PIXEL* Imagem::PegarPixels() const
{
	return pixels;
}