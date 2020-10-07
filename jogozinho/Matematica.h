#pragma once
#include <math.h>
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif
#define PI (float)M_PI
//Gravitação UNIVERSAL
const float G = (float)(6.67*10e-11);

template <typename T>
inline T AoQuadrado(const T& num)
{
	return num * num;
}