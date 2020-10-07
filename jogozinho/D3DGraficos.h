#pragma once
#include <D3d9.h>
#include <assert.h>

class Imagem;

class D3DGraficos
{
public:
	D3DGraficos(HWND janela);
	~D3DGraficos();
	void IniciaFrame();
	void FechaFrame();
	void ColocarPixel(int x, int y, D3DCOLOR cor);

	void DesenharImagem(Imagem* imagem, int x, int y);
public:
	static const unsigned int LARGURA = 1366;
	static const unsigned int ALTURA = 768;
private:
	const D3DCOLOR corFundo = D3DCOLOR_XRGB(255, 255, 255);
	IDirect3D9* pDirect3D;
	IDirect3DDevice9* pDirectDevice9;
	IDirect3DSurface9* pBackBuffer;
	D3DCOLOR* bufferSistema;
};
