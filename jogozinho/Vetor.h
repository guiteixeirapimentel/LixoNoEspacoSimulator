#pragma once
#include "Matematica.h"

template<typename T>
class Vetor
{
public:
	Vetor(T x, T y)
		:
		x(x),
		y(y)
	{}
	Vetor(const Vetor& v)
		:
		Vetor(v.x, v.y)
	{}
	Vetor()
		:
		x(0),
		y(0)
	{}

	template<typename T2>
	inline operator Vetor<T2>() const
	{
		return{ (T2)x, (T2)y };
	}

	inline Vetor& operator +=(const Vetor& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}
	inline Vetor operator +(const Vetor &rhs) const
	{
		return Vetor(*this) += rhs;
	}
	inline Vetor& operator -=(const Vetor &rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}
	inline Vetor operator -(const Vetor& rhs) const
	{
		return Vetor(*this) -= rhs;
	}
	inline Vetor operator -()
	{
		return Vetor(-x, -y);
	}
	inline Vetor& operator =(const Vetor& rhs)
	{
		this->x = rhs.x;
		this->y = rhs.y;
		return *this;
	}
	inline Vetor& operator *=(const T& rhs)
	{
		this->x *= rhs;
		this->y *= rhs;
		return *this;
	}
	inline Vetor operator *(const T& rhs) const
	{
		return Vetor(this->x, this->y) *= rhs;
	}
	inline Vetor& operator /=(const T& rhs)
	{
		this->x /= rhs;
		this->y /= rhs;
		return *this;
	}
	inline Vetor operator /(const T& rhs)
	{
		return Vetor(this->x, this->y) /= rhs;
	}
	inline bool operator ==(const Vetor& rhs)
	{
		return x == rhs.x && y == rhs.y;
	}
	inline bool operator !=(const Vetor& rhs)
	{
		return !(*this == rhs);
	}
	inline T operator *(const Vetor& rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}

	inline T ModuloAoQuadrado() const
	{
		return *this * *this;
	}
	inline T Modulo() const
	{
		return sqrt(ModuloAoQuadrado());
	}
	//Transformar em normal(x e y divididos por Modulo |v|
	inline Vetor& Normalizar()
	{
		const T length = Modulo();
		x /= length;
		y /= length;
		return *this;
	}
	inline Vetor& Girar90GrausEsq()
	{
		T temp = y;
		y = -x;
		x = temp;
		return *this;
	}
	inline Vetor& Girar90GrausDir()
	{
		T temp = y;
		y = x;
		x = -temp;
		return *this;
	}

	inline Vetor PontoMedio(const Vetor& p2)
	{
		return Vetor((x + p2.x) / 2.0f, (y + p2.y) / 2.0f);
	}

	inline Vetor& Trocar(Vetor& v2)
	{
		const Vetor temp = v2;
		v2 = *this;
		*this = temp;
		return *this;
	}

	inline Vetor Girar(const float angulo) const
	{
		Vetor<T> res;
		float cosA = cosf(angulo);
		float senA = sinf(angulo);
		res.x = x * cosA - y * senA;
		res.y = x * senA + y * cosA;
		return res;
	}

	inline bool EstaContidoLinha(const Vetor &v1, const Vetor &v2) const
	{
		return x >= min(v1.x, v2.x) && x <= max(v1.x, v2.x) && y >= min(v1.y, v2.y) && y <= max(v1.y, v2.y);
	}


public:
	T x;
	T y;
};

typedef Vetor<float> VetorF;