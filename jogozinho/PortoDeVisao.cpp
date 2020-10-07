#include "PortoDeVisao.h"
#include "Imagem.h"
#include "ImagemComRetangulo.h"
#include "Particula.h"

PortoDeVisao::PortoDeVisao(D3DGraficos& dxd, const RetanguloI porto)
:
dxd(dxd),
porto(porto)
{}
void PortoDeVisao::DesenharImagem(const Imagem* imagem, int xi, int yi) const
{
	int x = xi + porto.esquerda;
	int y = yi + porto.cima;

	RetanguloI t(y, y+imagem->PegaAltura(), x, x+imagem->PegaLargura());

	t.ClipPara(porto);

	const int xInicial = t.esquerda - x;
	const int yInicial = t.cima - y;
	const int xFinal = t.direita - x;
	const int yFinal = t.baixo - y;

	imagem->DesenharParte(xInicial, yInicial, xFinal, yFinal, x, y, dxd);
}
void PortoDeVisao::DesenharImagemComRetangulos(ImagemComRetangulo* imagem, int xi, int yi) const
{
	int x = xi + porto.esquerda;
	int y = yi + porto.cima;

	RetanguloI t(y, y + imagem->PegaAltura(), x, x + imagem->PegaLargura());

	t.ClipPara(porto);

	const int xInicial = t.esquerda - x;
	const int yInicial = t.cima - y;
	const int xFinal = t.direita - x;
	const int yFinal = t.baixo - y;

	imagem->DesenharParte(xInicial, yInicial, xFinal, yFinal, x, y, dxd);
}

void PortoDeVisao::DesenharParticula(Particula& particula, int x, int y) const
{
	RetanguloI t(y, y + particula.PegaImagem()->PegaAltura(), x, x + particula.PegaImagem()->PegaLargura());

	t.ClipPara(porto);

	const int xInicial = t.esquerda - x;
	const int yInicial = t.cima - y;
	const int xFinal = t.direita - x;
	const int yFinal = t.baixo - y;

	particula.PegaImagem()->DesenharParte(xInicial, yInicial, xFinal, yFinal, x, y, dxd);
}
float PortoDeVisao::PegarLargura() const
{
	return (float)(porto.direita - porto.esquerda);
}
float PortoDeVisao::PegarAltura() const
{
	return (float)(porto.baixo - porto.cima);
}