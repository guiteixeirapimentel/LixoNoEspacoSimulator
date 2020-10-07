#include "Camera.h"
#include "Particula.h"

Camera::Camera(const PortoDeVisao& porto, const RetanguloI limites)
:
limites(limites),
porto(porto)
{
	MudarPosicao(0, 300);
}

void Camera::DesenharImagem(const Imagem* imagem, int xi, int yi)
{
	int x = xi - this->x;
	int y = yi - this->y;
	porto.DesenharImagem(imagem, x, y);
}

void Camera::DesenharImagemComRetangulos(ImagemComRetangulo* imagem, int xi, int yi)
{
	int x = xi - this->x;
	int y = yi - this->y;
	porto.DesenharImagemComRetangulos(imagem, x, y);
}

void Camera::DesenharParticula(Particula& particula)
{
	int x = (int)particula.posX - this->x;
	int y = (int)particula.posY - this->y;
	porto.DesenharParticula(particula, x, y);
}

void Camera::MudarPosicao(int nx, int ny)
{
	x = (int)(nx - porto.PegarLargura() / 2.0f);
	y = (int)(ny - porto.PegarAltura() / 2.0f);

	x = max(x, limites.esquerda);
	y = max(y, limites.cima);
	x = min(x, limites.direita - (int)porto.PegarLargura());
	y = min(y, limites.baixo - (int)porto.PegarAltura());
}