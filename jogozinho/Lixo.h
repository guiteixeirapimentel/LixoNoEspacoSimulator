#pragma once
#include <string>
#include <random>
#include "Ret.h"
#include "Camera.h"
#include "ImagemSemFundo.h"
#include "Sprite.h"

class Lixo
{
public:
	Lixo(std::string nome, PIXEL corFundo, float x, float y);
	Lixo();
	
	void Desenhar(Camera& cam);
	bool EstaColidindoCom(const Sprite* sprite) const;

	void Atualizar(const Sprite* sprite);

	void MudarPosicao(int nx, int ny);
private:
	float x;
	float y;
	ImagemComRetangulo *imagem;
};