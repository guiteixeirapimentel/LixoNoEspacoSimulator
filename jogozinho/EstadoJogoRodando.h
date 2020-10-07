#pragma once
#include "EstadoM.h"
#include "MaquinaDeParticulas.h"
#include "Canhao.h"

class EstadoJogoMenu;

class EstadoJogoRodando : public EstadoM
{
public:
	EstadoJogoRodando(ControleXBCliente &controle, D3DGraficos &dxd, HWND janela);
	~EstadoJogoRodando();
	void Desenhar();
	void Update(DadosJogo &dados);

private:
	D3DGraficos &dxd;
	ControleXBCliente &controle;
	HWND janela;
	Fonte Fixedsys;
	PortoDeVisao porto;
	Camera cam;
	ControleDeSprite controleNave;
	DSound som;


	MaquinaDeParticulas m;

	Nave nave;
	Mapa mapa;
	int Score;

	bool perdeu = false;
	bool intro = true;
	ImagemSemFundo TextoIntro; // 283 174
	ImagemSemFundo TextoPerdeu; // 283 174
};