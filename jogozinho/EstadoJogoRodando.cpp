#include "EstadoJogoRodando.h"
#include "EstadoJogoMenu.h"

EstadoJogoRodando::EstadoJogoRodando(ControleXBCliente &controle, D3DGraficos &dxd, HWND janela)
:
dxd(dxd),
controle(controle),
janela(janela),
Fixedsys("data\\fonte\\Fixedsys16x28.gui", 16, 28, 32),
nave("", 1, 60, PIXEL(0, 0, 0), 656, 607, &m), //656 607
controleNave(&nave, controle),
porto(dxd, RetanguloI(0, 768, 0, 1366)),
cam(porto, { -2500000, 768, 0, 1366 }),
mapa(2000, 768, &nave, som),
som(janela),
TextoPerdeu("data\\menu\\TextoMorte.gui", PIXEL(0, 0, 0)),
TextoIntro("data\\menu\\TextoIntrodutorio.gui", PIXEL(0,0,0)),
m("data\\particulas\\fumaca.gui", PIXEL(0,0,0), 10000)
{}

EstadoJogoRodando::~EstadoJogoRodando()
{}

void EstadoJogoRodando::Update(DadosJogo &dados)
{
	/*if (perdeu)
	{
		dados.estado = new EstadoJogoGameOver(dxd, controle, janela, Score);
		delete this;
		return;
	}*/
	if (intro)
	{
		if (controle.BotaoEstaPrecionado(Controle_A))
		{
			intro = false;
		}
	}
	else if (perdeu)
	{
		if (controle.BotaoEstaPrecionado(Controle_Start))
		{
			dados.estado = new EstadoJogoMenu(dxd, controle, janela);
			delete this;
			return;
		}
	}
	else
	{
		mapa.Atualizar();
		controleNave.Checar();
		nave.Atualizar();
		nave.PegaEstado().QuandoAtualizar();
		m.Atualizar();

		if (mapa.EstaColidindo())
		{
			perdeu = true;
		}
	}
	Score = nave.PegaY();
}

void EstadoJogoRodando::Desenhar()
{
	mapa.Desenhar(cam);
	m.Desenhar(cam);
	nave.MoverCameraPara(cam);
	nave.Desenhar(cam);
	char b[20];
	Score *= -1;
	_itoa_s(Score, b, 10);
	std::string temp = "Score:";
	temp += b;
	Fixedsys.EscreverFrase(0, 0, temp, PIXEL(255, 255, 255), dxd);
	if (intro)
	{
		TextoIntro.DesenharImagem(283, 174, dxd);
	}
	else if (perdeu)
	{
		TextoPerdeu.DesenharImagem(283, 174, dxd);
	}
}