#pragma once
#include "EstadoM.h"
#include "EstadoJogoRodando.h"
#include "Particula.h"

class EstadoJogoMenu : public EstadoM
{
public:
	EstadoJogoMenu(D3DGraficos &dxd, ControleXBCliente &controle, HWND janela);
	~EstadoJogoMenu();

	void Desenhar();
	void Update(DadosJogo &dados);
private:
	D3DGraficos &dxd;
	ControleXBCliente &controle;
	HWND janela;

	Imagem fundo;
	ImagemSemFundo nomeJogo;

	Imagem tJogarS; // Texto Jogar Selecionado
	Imagem tJogarNS; // Texto Jogar NÂO Selecionado

	Imagem tCreditosS;
	Imagem tCreditosNS;
	Imagem CreditosTexto;

	int selecionado = 0;

	bool creditos = false;

	bool apertado;
	bool apertado1 = false;
};