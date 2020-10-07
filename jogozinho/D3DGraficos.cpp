#include "D3DGraficos.h"
#pragma comment( lib,"d3d9.lib" )

D3DGraficos::D3DGraficos(HWND janela)
:
pDirect3D(NULL),
pDirectDevice9(NULL),
pBackBuffer(NULL),
bufferSistema(NULL)
{
	HRESULT result;

	pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);
	assert(pDirect3D != NULL);

	D3DPRESENT_PARAMETERS d3pp;
	ZeroMemory(&d3pp, sizeof(d3pp));
	d3pp.Windowed = TRUE;
	d3pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3pp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3pp.BackBufferWidth = D3DGraficos::LARGURA;    
	d3pp.BackBufferHeight = D3DGraficos::ALTURA;
	d3pp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3pp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

	result = pDirect3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, janela,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE, &d3pp, &pDirectDevice9);
	assert(!FAILED(result));

	result = pDirectDevice9->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer);
	assert(!FAILED(result));

	bufferSistema = new D3DCOLOR[LARGURA * ALTURA];
}

D3DGraficos::~D3DGraficos()
{
	if (pDirectDevice9)
	{
		pDirectDevice9->Release();
		pDirectDevice9 = NULL;
	}
	if (pDirect3D)
	{
		pDirect3D->Release();
		pDirect3D = NULL;
	}
	if (pBackBuffer)
	{
		pBackBuffer->Release();
		pBackBuffer = NULL;
	}
	if (bufferSistema)
	{
		delete bufferSistema;
		bufferSistema = NULL;
	}
}

void D3DGraficos::IniciaFrame()
{
	memset(bufferSistema, corFundo, sizeof(D3DCOLOR)* LARGURA * ALTURA);
}

void D3DGraficos::FechaFrame()
{
	HRESULT result;
	D3DLOCKED_RECT backRet;

	result = pBackBuffer->LockRect(&backRet, NULL, NULL);
	assert(!FAILED(result));

	for (int y = 0; y < ALTURA; y++)
	{
		memcpy(&((BYTE*)backRet.pBits)[backRet.Pitch * y], &bufferSistema[LARGURA * y], sizeof(D3DCOLOR)*LARGURA);
	}
	
	result = pBackBuffer->UnlockRect();
	assert(!FAILED(result));

	result = pDirectDevice9->Present(NULL, NULL, NULL, NULL);
	assert(!FAILED(result));
}

void D3DGraficos::ColocarPixel(int x, int y, D3DCOLOR cor)
{
	assert(x >= 0);
	assert(x < LARGURA);
	assert(y >= 0);
	assert(y < ALTURA);
	bufferSistema[LARGURA*y + x] = cor;
}