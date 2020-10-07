#include "ImagemComRetangulo.h"

ImagemComRetangulo::ImagemComRetangulo(std::string nomeArquivo, PIXEL corFundo)
:
corFundo(corFundo)
{
	char larg[10];
	char alt[10];
	char nRetangulos[10];

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

	i = 0;
	do
	{
		arq.get(nRetangulos[i]);
		i++;
	} while (nRetangulos[i - 1] != '/');
	nRetangulos[i - 1] = 0;
	i = 0;

	int nRet = atoi(nRetangulos);
	nRets = nRet;
	rets = new RetanguloI*[nRet];

	for (int id = 0; id < nRet; id++)
	{
		char t[1];
		arq.get(t[0]);
		if (t[0] != '{')
		{
			MessageBox(NULL, L"Erro ao abrir imagem com retangulos, Reinstale o jogo!", L"Erro: Loop nRet i++", 0);
			PostQuitMessage(0);
			break;
		}
		char cima[10];
		char baixo[10];
		char esquerda[10];
		char direita[10];
		do
		{
			arq.get(cima[i]);
			i++;
		} while (cima[i - 1] != ',');
		cima[i - 1] = 0;
		i = 0;
		do
		{
			arq.get(baixo[i]);
			i++;
		} while (baixo[i - 1] != ',');
		baixo[i - 1] = 0;
		i = 0;
		do
		{
			arq.get(esquerda[i]);
			i++;
		} while (esquerda[i - 1] != ',');
		esquerda[i - 1] = 0;
		i = 0;
		do
		{
			arq.get(direita[i]);
			i++;
		} while (direita[i - 1] != '}');
		direita[i - 1] = 0;
		i = 0;
		rets[id] = new RetanguloI(atoi(cima), atoi(baixo), atoi(esquerda), atoi(direita));
	}
	char x;
	arq.get(x);
	if (x != '/')
	{
		MessageBox(NULL, L"Erro ao abrir imagem com retangulos, Reinstale o jogo!", L"Erro: x != /", 0);
		PostQuitMessage(0);
	}
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

ImagemComRetangulo::~ImagemComRetangulo()
{
	delete pixels;
	for (int i = 0; i < nRets; i++)
	{
		delete rets[i];
	}
	delete[] rets;
}

void ImagemComRetangulo::DesenharImagem(int x, int y, D3DGraficos &dxd)
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

void ImagemComRetangulo::DesenharParte(int xInicial, int yInicial, int xFinal, int yFinal, 
	int x, int y, D3DGraficos &dxd)
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

unsigned int ImagemComRetangulo::PegaAltura() const
{
	return altura;
}

unsigned int ImagemComRetangulo::PegaLargura() const
{
	return largura;
}

const PIXEL* ImagemComRetangulo::PegarPixels() const
{
	return pixels;
}

RetanguloI** ImagemComRetangulo::PegarRetangulos() const
{
	return rets;
}

const int ImagemComRetangulo::PegarNRetangulos() const
{
	return nRets;
}