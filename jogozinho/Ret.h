#pragma once
#include <minmax.h>

template<typename T>
class Retangulo
{
public:
	Retangulo(T cima, T baixo, T esquerda, T direita)
		:
		cima(cima),
		baixo(baixo),
		direita(direita),
		esquerda(esquerda),
		cimaC(cima),
		baixoC(baixo),
		direitaC(direita),
		esquerdaC(esquerda)
	{}
	Retangulo()
		:
		cima(0),
		baixo(0),
		direita(0),
		esquerda(0)
	{}

	template<class T2>
	operator Retangulo<T2>() const
	{
		return Retangulo<T2>((T2)cima, (T2)baixo, (T2)esquerda, (T2)direita);
	}

	void ClipPara(const Retangulo& ret)
	{
		cima = max(cima, ret.cima);
		baixo = min(baixo, ret.baixo);
		esquerda = max(esquerda, ret.esquerda);
		direita = min(direita, ret.direita);
	}
	void Mover(T dx, T dy)
	{
		cima += dy;
		baixo += dy;
		esquerda += dx;
		direita += dx;
	}
	void MoverPara(T x, T y)
	{
		baixo = baixo - cima + y;
		cima = y;
		direita = direita - esquerda + x;
		esquerda = x;
	}
	bool EstaColidindoCom(Retangulo<T> *ret) const
	{
		if (esquerda > ret->direita)
		{
			return false;
		}
		if (direita < ret->esquerda)
		{
			return false;
		}
		if (cima > ret->baixo)
		{
			return false;
		}
		if (baixo < ret->cima)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
public:
	T cima;
	T baixo;
	T direita;
	T esquerda;
	const T cimaC;
	const T baixoC;
	const T esquerdaC;
	const T direitaC;
};

typedef Retangulo<int> RetanguloI;
typedef Retangulo<float> RetanguloF;