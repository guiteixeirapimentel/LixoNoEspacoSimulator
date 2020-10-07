#include "Mapa.h"

Mapa::Mapa(int alturaMapa, int alturaTela, const Sprite* sprite, DSound &som)
:
fundo(alturaMapa, alturaTela),
sprite(sprite),
som(som)
{
	lixos = new Lixo*[18];

	for (int i = 0; i < 4; i++)
	{
		lixos[i] = new Lixo("data\\lx0.guiR", PIXEL(0, 0, 0), -200, 0);
	}
	for (int i = 4; i < 6; i++)
	{
		lixos[i] = new Lixo("data\\lx1.guiR", PIXEL(0, 0, 0), -200, 0);
	}
	for (int i = 6; i < 8; i++)
	{
		lixos[i] = new Lixo("data\\lx2.guiR", PIXEL(123, 123, 123), -200, 0);
	}
	for (int i = 8; i < 9; i++)
	{
		lixos[i] = new Lixo("data\\lx3.guiR", PIXEL(123, 123, 123), -200, 0);
	}

	for (int i = 9; i < 10; i++)
	{
		lixos[i] = new Lixo("data\\lx0.guiR", PIXEL(0, 0, 0), -200, -25000);
	}
	for (int i = 10; i < 12; i++)
	{
		lixos[i] = new Lixo("data\\lx1.guiR", PIXEL(0, 0, 0), -200, -25000);
	}
	for (int i = 12; i < 14; i++)
	{
		lixos[i] = new Lixo("data\\lx2.guiR", PIXEL(123, 123, 123), -200, -25000);
	}
	for (int i = 14; i < 18; i++)
	{
		lixos[i] = new Lixo("data\\lx3.guiR", PIXEL(123, 123, 123), -200, -25000);
	}

	//musica = som.CreateSound("mus.wav");

	//musica.Play();
	somTempos = GetTickCount();
	ultimoTempo = GetTickCount();
}

Mapa::~Mapa()
{
	for (int i = 0; i < 9; i++)
	{
		delete lixos[i];
	}
	delete[] lixos;
}

void Mapa::Desenhar(Camera &cam)
{
#if NDEBUG
	fundo.Desenhar(cam, sprite);
#endif

	for (int i = 0; i < 18; i++)
	{
		lixos[i]->Desenhar(cam);
	}
}

void Mapa::Atualizar()
{
	for (int i = 0; i < 18; i++)
	{
		lixos[i]->Atualizar(sprite);
	}
	/*if (ultimoTempo < somTempos+ 33000)
	{
		ultimoTempo = GetTickCount();
	}
	else
	{
		somTempos = GetTickCount();
		ultimoTempo = GetTickCount();
		//musica.Play();
	}*/
}

bool Mapa::EstaColidindo()
{
	for (int i = 0; i < 18; i++)
	{
		if (lixos[i]->EstaColidindoCom(sprite))
		{
			return true;
		}
	}
	return false;
}
