#pragma once
#include "D3DGraficos.h"
#include "DadosSprite.h"
#include "Equipavel.h"

class Sprite
{
public:
	virtual ~Sprite() = 0;
	virtual void Desenhar(D3DGraficos &dxd){};
	virtual void Atualizar(){};

	void MoverCameraPara(Camera& cam)
	{
		cam.MudarPosicao((int)dados.x, (int)dados.y);
	}
	int PegaY() const
	{
		return (int)dados.y;
	}
	int PegaX() const
	{
		return (int)dados.x;
	}
	Estado &PegaEstado() const
	{
		return *dados.estado;
	}
	RetanguloI** PegaRetCol() const
	{
		return dados.atual->PegarRetangulos();
	}
	int PegarNRetangulos() const
	{
		return dados.atual->PegarNRetangulos();
	}
	Equipavel& PegaEquipavel() const
	{
		return *equipavel;
	}

protected:
	Equipavel* equipavel = NULL;
	DadosSprite dados;
};