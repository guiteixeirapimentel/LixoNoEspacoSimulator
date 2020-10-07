#pragma once
#include "D3DGraficos.h"
#include "ControleXB.h"
#include "Teclado.h"
#include "EstadoJogoMenu.h"
#include "DadosJogo.h"

class Jogo
{
public:
	Jogo(HWND janela, TecladoCliente& teclado, ControleXBCliente& controle);
	~Jogo();
	void Vai();
private:
	void Desenhar();
	void Update();
private:
	D3DGraficos dxd;
	TecladoCliente &teclado;
	ControleXBCliente &controle;
	DadosJogo dados;
};