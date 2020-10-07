#pragma once
#include <string>
#include <fstream>
#include "D3DGraficos.h"
#include "Camera.h"

class PIXEL
{
public:
	#define ExtractAlpha(x) ((x>>24)&255)
	#define ExtractRed(x) ((x>>16)&255)
	#define ExtractGreen(x) ((x>>12)&255)
	#define ExtractBlue(x) (x&255)
public:
	PIXEL(unsigned char r, unsigned char g, unsigned char b)
		:
		r(r),
		g(g),
		b(b)
	{}
	PIXEL()
		:
		r(0),
		g(0),
		b(0)
	{}
	bool operator !=(PIXEL& ldir)
	{
		if (r == ldir.r && g == ldir.g && b == ldir.b)
		{
			return false;
		}
		return true;
	}
	bool operator ==(PIXEL& ldir)
	{
		if (r == ldir.r && g == ldir.g && b == ldir.b)
		{
			return true;
		}
		return false;
	}

	PIXEL& operator =(const D3DCOLOR& rhs)
	{
		r = ExtractRed(rhs);
		g = ExtractGreen(rhs);
		b = ExtractBlue(rhs);
		return *this;
	}
	operator D3DCOLOR() const
	{
		return D3DCOLOR_XRGB(r, g, b);
	}
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Imagem
{
public:
	Imagem(std::string nomeArquivo);
	~Imagem();

	virtual void DesenharImagem(int x, int y, D3DGraficos &dxd);
	virtual void DesenharParte(int xInicial, int yInicial, int xFinal, int yFinal, int x, int y, D3DGraficos &dxd) const;
	const PIXEL* PegarPixels() const;

	unsigned int PegaLargura() const;
	unsigned int PegaAltura() const;

protected:
	Imagem(unsigned int largura, unsigned int altura, PIXEL* pixels);

protected:
	unsigned int largura;
	unsigned int altura;
	PIXEL *pixels;
};