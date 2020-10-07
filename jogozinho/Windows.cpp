#include <Windows.h>
#include "D3DGraficos.h"
#include "Jogo.h"
#include "resource.h"

TecladoServidor tecladoS;

LRESULT CALLBACK Mensagens(HWND jnl, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_QUIT:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		tecladoS.BotaoFoiApertado(wparam);
		break;
	case WM_KEYUP:
		tecladoS.BotaoFoiSolto(wparam);
		break;
	case WM_CHAR:
		tecladoS.AddFilaChars(wparam);
		break;
	}
	return DefWindowProc(jnl, msg, wparam, lparam);
}

int WINAPI wWinMain(HINSTANCE inst, HINSTANCE inst2, LPWSTR cmd, int nCmd)
{
	WNDCLASSEX classeJanela;
	classeJanela.cbClsExtra = NULL;
	classeJanela.cbSize = sizeof(classeJanela);
	classeJanela.cbWndExtra = NULL;
	classeJanela.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	classeJanela.hCursor = NULL;
	classeJanela.hIcon = LoadIcon(inst, MAKEINTRESOURCE(IDI_APPLICATION));
	classeJanela.hInstance = inst;
	classeJanela.lpfnWndProc = Mensagens;
	classeJanela.lpszClassName = L"Jogozinho";
	classeJanela.lpszMenuName = L"Lixo no Espaço Simulator";
	classeJanela.style = CS_HREDRAW | CS_VREDRAW;
	
	classeJanela.hIconSm = (HICON)LoadImage(inst, MAKEINTRESOURCE(IDI_APPICON16), IMAGE_ICON, 16, 16, 0);
	classeJanela.hIcon = (HICON)LoadImage(inst, MAKEINTRESOURCE(IDI_APPICON32), IMAGE_ICON, 32, 32, 0);

	RegisterClassEx(&classeJanela);

	HWND janela = CreateWindowEx(NULL, L"Jogozinho", L"Lixo no Espaço Simulator", WS_EX_TOPMOST | WS_POPUP,
		0, 0, D3DGraficos::LARGURA, D3DGraficos::ALTURA, NULL, NULL, inst, NULL);

	ShowWindow(janela, 1);
	UpdateWindow(janela);

	MSG msg;
	TecladoCliente tecladoC(tecladoS);

	ControleXBServer controleS(0);
	ControleXBCliente controleC(controleS);

	 Jogo jogo(janela, tecladoC, controleC);
	ZeroMemory(&msg, sizeof(msg));

	ShowCursor(false);

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		jogo.Vai();
		controleS.Checar();
	}	

	UnregisterClass(L"Jogozinho", classeJanela.hInstance);

	return 0;
}