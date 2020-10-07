#include "EstadoJogoMenu.h"

EstadoJogoMenu::EstadoJogoMenu(D3DGraficos &dxd, ControleXBCliente &controle, HWND janela)
:
dxd(dxd),
controle(controle),
janela(janela),
fundo("data\\menu\\Fundomenu.gui"),
tJogarS("data\\menu\\JogarS.gui"),
tJogarNS("data\\menu\\JogarNS.gui"),
tCreditosS("data\\menu\\CreditosS.gui"),
tCreditosNS("data\\menu\\CreditosNS.gui"),
nomeJogo("data\\menu\\TituloMenu210x19.gui", PIXEL(0,0,0)),
CreditosTexto("data\\menu\\CreditosT.gui")
{}

EstadoJogoMenu::~EstadoJogoMenu()
{}

void EstadoJogoMenu::Desenhar()
{
	fundo.DesenharImagem(0, 0, dxd);
	nomeJogo.DesenharImagem(219, 19, dxd);
	if (!creditos)
	{
		tJogarNS.DesenharImagem(653, 297, dxd);
		tCreditosNS.DesenharImagem(632, 398, dxd);
		switch (selecionado)
		{
		case 0:
			tJogarS.DesenharImagem(653, 297, dxd);
			break;
		case 1:
			tCreditosS.DesenharImagem(632, 398, dxd);
			break;
		}
	}
	else
	{
		CreditosTexto.DesenharImagem(387, 324, dxd);
	}

}

void EstadoJogoMenu::Update(DadosJogo &dados)
{
	if (!creditos)
	{
		if (controle.BotaoEstaPrecionado(Controle_Setas_Baixo) && !apertado)
		{
			switch (selecionado)
			{
			case 0:
				selecionado = 1;
				break;
			case 1:
				selecionado = 0;
				break;
			}
			apertado = true;
		}
		if (!controle.BotaoEstaPrecionado(Controle_Setas_Baixo))
		{
			apertado = false;
		}
		if (controle.BotaoEstaPrecionado(Controle_A) && !apertado1)
		{
			switch (selecionado)
			{
			case 0:
				dados.estado = new EstadoJogoRodando(controle, dxd, janela);
				break;
			case 1:
				creditos = true;
				apertado1 = true;
				break;
			}
		}
		else if (!controle.BotaoEstaPrecionado(Controle_A))
		{
			apertado1 = false;
		}
	}
	else
	{
		if (controle.BotaoEstaPrecionado(Controle_A))
		{
			if (!apertado1)
			{
				creditos = false;
				apertado1 = true;
			}
		}
		else
		{
			apertado1 = false;
		}
	}
}