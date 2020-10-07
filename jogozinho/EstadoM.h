#pragma once
#include "DadosJogo.h"
#include "ImagemSemFundo.h"
#include "Fonte.h"
#include "Nave.h"
#include "ControleDeSprite.h"
#include "Camera.h"
#include "Mapa.h"

class EstadoM
{
public:
	virtual ~EstadoM() = 0;
	virtual void Update(DadosJogo &dados){};
	virtual void Desenhar(){};
};