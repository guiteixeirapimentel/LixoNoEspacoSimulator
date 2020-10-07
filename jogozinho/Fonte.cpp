#include "Fonte.h"

Fonte::Fonte(std::string nomeArquivo, int larguraFonte, int alturaFonte, int letrasPorLinha)
:
larguraFonte(larguraFonte),
alturaFonte(alturaFonte),
imagem(nomeArquivo, PIXEL(255, 255, 255)),
letrasPorLinha(letrasPorLinha)
{

}

void Fonte::EscreverLetra(int x, int y, char letra, PIXEL cor, D3DGraficos &dxd)
{
	const char index = letra - ' ';
	const char coluna = index % letrasPorLinha;
	const char linha = index / letrasPorLinha;
	const int linhaxaltura = linha * alturaFonte;
	const int colunaxlargura = coluna*larguraFonte;

	for (int iy = linhaxaltura; iy < (linhaxaltura)+alturaFonte; iy++)
	{
		for (int ix = colunaxlargura; ix < colunaxlargura + larguraFonte; ix++)
		{
			PIXEL t (imagem.PegarPixels()[iy * imagem.PegaLargura() + ix]);
			if (t != PIXEL(255, 255, 255))
			{
				dxd.ColocarPixel(ix + x - colunaxlargura, iy + y - linhaxaltura, D3DCOLOR_XRGB(cor.r, cor.g, cor.b));
			}
		}
	}

}

void Fonte::EscreverFrase(int x, int y, std::string frase, PIXEL cor, D3DGraficos &dxd)
{
	const int tamanho = frase.length();
	for (int i = 0; i < tamanho; i++)
	{
		EscreverLetra(i*larguraFonte + x, y, frase.c_str()[i], cor, dxd);
	}
}