#include "ControleDeSprite.h"

void ControleDeSprite::Checar()
{
	if (ctrl.BotaoEstaPrecionado(Controle_A))
	{
		sprite->PegaEstado().QuandoAPrecionado();
	}
	else
	{
		sprite->PegaEstado().QuandoASolto();
	}
	if (ctrl.BotaoEstaPrecionado(Controle_Setas_Direita))
	{
		sprite->PegaEstado().QuandoDirPrecionado();
	}
	else
	{
		sprite->PegaEstado().QuandoDirSolto();
	}
	if (ctrl.BotaoEstaPrecionado(Controle_Setas_Esquerda))
	{
		sprite->PegaEstado().QuandoEsqPrecionado();
	}
	else
	{
		sprite->PegaEstado().QuandoEsqSolto();
	}
	sprite->PegaEstado().QuandoDirecionalEsq(ctrl.PegaAnalogico(0).px);

	if (ctrl.BotaoEstaPrecionado(Controle_X))
	{
		sprite->PegaEquipavel().Usar();
	}
}