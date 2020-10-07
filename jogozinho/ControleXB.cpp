#include "ControleXB.h"

ControleXBServer::ControleXBServer(UINT id)
:
id(id)
{
	memset(&teclas, false, NUM_TECLAS - 1);
}

void ControleXBServer::Checar()
{
	memset(&estadoCtrl, 0, sizeof(XINPUT_STATE));
	DWORD resultado = XInputGetState(id, &estadoCtrl);

	if (resultado != ERROR_SUCCESS)
	{
		MessageBox(NULL, L"Erro ao conectar ao controle!", L"Não foi possivel conectar ao controle!", 1);
		return;
	}
	if (estadoCtrl.dwPacketNumber != ultimoValorPacote)//Se o pacote atual é igual entao nada aconteceu
	{
		ultimoValorPacote = estadoCtrl.dwPacketNumber;
		
		ChecarTeclas();
		ChecarPosJG();
	}
}

//Checa Teclas(A,B,Y,X,Direcional)
void ControleXBServer::ChecarTeclas()
{
	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_A)
	{
		teclas[Controle_A] = true;
	}
	else
	{
		teclas[Controle_A] = false;
	}

	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_B)
	{
		teclas[Controle_B] = true;
	}
	else
	{
		teclas[Controle_B] = false;
	}
	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_X)
	{
		teclas[Controle_X] = true;
	}
	else
	{
		teclas[Controle_X] = false;
	}
	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_Y)
	{
		teclas[Controle_Y] = true;
	}
	else
	{
		teclas[Controle_Y] = false;
	}
	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
	{
		teclas[Controle_Setas_Cima] = true;
	}
	else
	{
		teclas[Controle_Setas_Cima] = false;
	}
	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
	{
		teclas[Controle_Setas_Baixo] = true;
	}
	else
	{
		teclas[Controle_Setas_Baixo] = false;
	}
	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
	{
		teclas[Controle_Setas_Direita] = true;
	}
	else
	{
		teclas[Controle_Setas_Direita] = false;
	}
	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
	{
		teclas[Controle_Setas_Esquerda] = true;
	}
	else
	{
		teclas[Controle_Setas_Esquerda] = false;
	}
	if (estadoCtrl.Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		teclas[Controle_Start] = true;
	}
	else
	{
		teclas[Controle_Start] = false;
	}
}

//Checa gatilhos e analogico
void ControleXBServer::ChecarPosJG()
{
	if (estadoCtrl.Gamepad.bRightTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		teclas[Controle_RB] = true;
	}
	else
	{
		teclas[Controle_RB] = false;
	}

	if (estadoCtrl.Gamepad.bLeftTrigger < XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
	{
		teclas[Controle_RT] = true;
	}
	else
	{
		teclas[Controle_RT] = false;
	}

	if ((estadoCtrl.Gamepad.sThumbLX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		estadoCtrl.Gamepad.sThumbLX > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE) &&
		(estadoCtrl.Gamepad.sThumbLY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE &&
		estadoCtrl.Gamepad.sThumbLY > -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE))
	{
		estadoCtrl.Gamepad.sThumbLX = 0;
		estadoCtrl.Gamepad.sThumbLY = 0;
	}

	// Check left thumbStick

	float LX = estadoCtrl.Gamepad.sThumbLX;
	float LY = estadoCtrl.Gamepad.sThumbLY;
	if (LX != 0 || LY != 0)
	{
		//determine how far the controller is pushed
		//float magnitude = sqrt(LX*LX + LY*LY);

		//determine the direction the controller is pushed
		float normalizedLX = LX / (32727 - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);  // magnitude;
		float normalizedLY = LY / (32727 - XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
		analogicoEsq = { normalizedLX, normalizedLY };
	}
	else
	{
		analogicoEsq = { 0, 0 };
	}
}

void ControleXBServer::Vibrar(float vlEsq, float vlDir)
{
	XINPUT_VIBRATION vibracao;
	vibracao.wLeftMotorSpeed = (WORD)vlEsq * 65535;
	vibracao.wRightMotorSpeed = (WORD)vlDir * 65535;
	XInputSetState(id, &vibracao);
}

Analogico ControleXBServer::PegaAnalogico(int n) const
{
	switch (n)
	{
	case 0:
		return analogicoEsq;
		break;
	case 1:
		return analogicoDir;
			break;
	default:
		return analogicoEsq;
		break;
	}
}

ControleXBCliente::ControleXBCliente(ControleXBServer& ctrlServer)
:
ctrlServer(ctrlServer)
{}

bool ControleXBCliente::BotaoEstaPrecionado(unsigned int botao) const
{
	return ctrlServer.teclas[botao];
}
void ControleXBCliente::Vibrar(float vlEsq, float vlDir) const
{
	ctrlServer.Vibrar(vlEsq, vlDir);
}
Analogico ControleXBCliente::PegaAnalogico(int n) const
{
	return ctrlServer.PegaAnalogico(n);
}