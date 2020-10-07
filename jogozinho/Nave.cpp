#include "Nave.h"

Nave::Nave(std::string nomeBase, unsigned int numImagens, unsigned int delay, PIXEL corFundo, float x, float y, MaquinaDeParticulas *m)
{
	dados.x = x;
	dados.y = y;
	dados.estado = new NaveParada(dados);
	dados.virando = false;

	dados.vx = 0;
	dados.vy = 0;

	dados.seqImg = new SequenciaDeImagens*[2];
	dados.seqImg[0] = new SequenciaDeImagens("Nave\\naveP", 1, 60, PIXEL(0, 0, 0));
	dados.seqImg[1] = new SequenciaDeImagens("Nave\\naveV", 1, 60, PIXEL(0, 0, 0));
	dados.atual = dados.seqImg[0];
	dados.m = m;

	equipavel = new Canhao("data\\canhao\\Canhao.gui", PIXEL(0, 0, 0), "data\\canhao\\BolaCanhao.gui", PIXEL(123, 0, 123), dados);
}

Nave::~Nave()
{
	delete dados.seqImg[0];
	delete dados.seqImg[1];
	delete[] dados.seqImg;

	if (equipavel != NULL)
	{
		delete equipavel;
	}
}

void Nave::Desenhar(Camera &cam)
{
	dados.atual->Desenhar((int)dados.x, (int)dados.y, cam);
	equipavel->Desenhar(cam);
}

void Nave::Atualizar()
{
	dados.atual->Atualizar();
	RetanguloI ** ret = dados.atual->PegarRetangulos();
	int numRet = dados.atual->PegarNRetangulos();
	for (int i = 0; i < numRet; i++)
	{
		ret[i]->MoverPara(int(dados.x + ret[i]->esquerdaC), int(dados.y + ret[i]->cimaC));
	}
	equipavel->Atualizar();
}