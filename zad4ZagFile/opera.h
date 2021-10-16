#pragma once
#pragma once
#include <stdio.h>
#include <math.h>
int sum(int, int);
int raz(int, int);
int umn(int, int);
int del(int, int);
char* obed(char*, char*);
int StrVChisl(char*);
char* ChiVStr(int);
float vvod(char*);

int sum(int a, int b)
{
	return a + b;
}
int raz(int a, int b)
{
	return a - b;
}
int umn(int a, int b)
{
	return b * a;
}
int del(int a, int b)
{
	return a / b;
}
float vvod(char* strvv)
{
		printf("%s", strvv);
		float i;
		scanf_s("%f", &i);
		return i;
}