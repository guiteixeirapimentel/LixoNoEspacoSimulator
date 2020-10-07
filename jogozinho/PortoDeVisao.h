#pragma once
#include "Ret.h"
#include "D3DGraficos.h"
class Particula;
class ImagemComRetangulo;

class PortoDeVisao
{
public:
	PortoDeVisao(D3DGraficos& dxd, const RetanguloI porto);
	void DesenharImagem(const Imagem* imagem, int x, int y) const;
	void DesenharImagemComRetangulos(ImagemComRetangulo* imagem, int x, int y) const;
	void DesenharParticula(Particula& particula, int x, int y) const;
	float PegarLargura() const;
	float PegarAltura() const;
private:
	D3DGraficos &dxd;
	RetanguloI porto;
};