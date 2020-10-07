#pragma once
#define WIN32_LEAN_AND_MEAN // We don't want the extra stuff like MFC and such
#include <Windows.h>
#include <Xinput.h>
#include <queue>
#pragma comment(lib, "Xinput9_1_0.lib")

typedef enum
{
	Controle_A = 0,
	Controle_B = 1,
	Controle_X = 2,
	Controle_Y = 3,
	Controle_LB = 4,
	Controle_LT = 5,
	Controle_RT = 6,
	Controle_RB = 7,
	Controle_Back = 8,
	Controle_Start = 9,
	Controle_Setas_Cima = 10,
	Controle_Setas_Baixo = 11,
	Controle_Setas_Direita = 12,
	Controle_Setas_Esquerda = 13,
	Controle_Direcional_Esquerdo_Cima = 14,
	Controle_Direcional_Esquerdo_Baixo = 15,
	Controle_Direcional_Esquerdo_Direita = 16,
	Controle_Direcional_Esquerdo_Esquerda = 17,
	Controle_Direcional_Direito_Cima = 18,
	Controle_Direcional_Direito_Baixo = 19,
	Controle_Direcional_Direito_Direita = 20,
	Controle_Direcional_Direito_Esquerda = 21,
	NUM_TECLAS = 22
};
struct Analogico
{
	float px;
	float py;
};

class ControleXBCliente;

class ControleXBServer
{
	friend ControleXBCliente;
public:
	ControleXBServer(UINT id);
	void Checar();
private:
	void Vibrar(float vlEsq = 0.0f, float vlDir = 0.0f);
	void ChecarTeclas();
	void ChecarPosJG();
	Analogico PegaAnalogico(int n) const;
private:
	XINPUT_STATE estadoCtrl;
	DWORD ultimoValorPacote;
	bool teclas[NUM_TECLAS - 1];
	Analogico analogicoEsq;
	Analogico analogicoDir;
	const unsigned int id;
};

class ControleXBCliente
{
public:
	ControleXBCliente(ControleXBServer &ctrlServer);
	bool BotaoEstaPrecionado(unsigned int botao) const;
	void Vibrar(float vlEsq = 0.0f, float vlDir = 0.0f) const;
	Analogico PegaAnalogico(int n) const;
private:
	ControleXBServer &ctrlServer;
};