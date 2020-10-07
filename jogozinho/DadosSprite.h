#pragma once
#include "SequenciaDeImagens.h"
#include "MaquinaDeParticulas.h"

class DadosSprite
{
public:
	float x;
	float y;

	float vx;
	float vy;

	SequenciaDeImagens **seqImg;
	SequenciaDeImagens *atual;

	bool virando;

	class Estado *estado;

	MaquinaDeParticulas *m;
};