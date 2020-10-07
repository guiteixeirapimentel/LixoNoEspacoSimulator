#include "Jogo.h"

Jogo::Jogo(HWND janela, TecladoCliente &teclado, ControleXBCliente &controle)
:
dxd(janela),
teclado(teclado),
controle(controle)
{
	dados.estado = new EstadoJogoMenu(dxd, controle, janela);
}

Jogo::~Jogo()
{

}

void Jogo::Vai()
{
	Update();
	dxd.IniciaFrame();
	Desenhar();
	dxd.FechaFrame();
}

void Jogo::Update()
{
	dados.estado->Update(dados);
}

void Jogo::Desenhar()
{
	dados.estado->Desenhar();
}