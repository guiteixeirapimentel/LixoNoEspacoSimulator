#pragma once
#include "PortoDeVisao.h"

class Camera
{
public:
	Camera(const PortoDeVisao& porto, const RetanguloI limites);
	void DesenharImagem(const Imagem* imagem, int x, int y);
	void DesenharImagemComRetangulos(ImagemComRetangulo* imagem, int x, int y);
	void DesenharParticula(Particula& part);
	void MudarPosicao(int nx, int ny);
private:
	const PortoDeVisao& porto;
	const RetanguloI limites;
	int x;
	int y;
};