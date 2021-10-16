#include "opera.h"
#define f 5
#define t 2
#define m "Мама"
#define p "Папа"
#define kv(i) i*i
void treug();
float DlinStor(float, float, float, float);
void treugprepr();

int main()
{
	system("chcp 1251>nul");
	int otv;
	float z;
	while (1)
	{
		printf("Выбор задания:\n");
		scanf_s("%d", &otv);
		switch (otv)
		{
		case 1:
			printf("вызвал функцию из stdio.h\n");
			break;
		case 2:
			printf("2+5 = %d\n2-5 = %d\n3*5 = %d\n8:2 = %d\n", sum(t, f), raz(t, f), umn(3, f), del(8, t));
			break;
		case 3:
			printf("%s", obed(m, p));
			break;
		case 4:
			printf("Перевод числа 5 в строку = %s\n", ChiVStr(f));
			printf("Перевод числа 36 в строку = %d\n", StrVChisl("36"));
			break;
		case 5: //расстояние между точками
		z = DlinStor(f,t,7,8);
			printf("Расстояние между точками (%d; %d) и (%d; %d) = %f\n", f, t, 7, 8,z);
			break;
		case 6:
			treug();
			break;
		case 7:
			treugprepr();
			break;
		}
	}
}

void treug()
{
	float ax = vvod("Введите x для A: "), ay = vvod("Введите y для A: "), bx = vvod("Введите x для B: "), by = vvod("Введите y для B: "), cx = vvod("Введите x для C: "), cy = vvod("Введите y для C: ");
	float ab = DlinStor(ax, ay, bx, by), bc = DlinStor(bx, by, cx, cy), ca = DlinStor(cx, cy, ax, ay);
	if (ab > 0 && bc > 0 && ca > 0 && ab + bc > ca && bc + ca > ab && ca + ab > bc) //определяем существует ли треугольник через длинны сторон
	{
		float P = ab + bc + ca, pp = P / 2, s = sqrt(pp * (pp - ab) * (pp - bc) * (pp - ca));
		printf("Периметр треугольника = %f, Площадь = %f\n",P,s);
	}
	else
		printf("Такого треугольника не существует!\n");
}

void treugprepr()
{
#define ax 2 //т.к препроцессорное условие работает только с константами - задал значения так
#define ay 3 
#define	bx 3
#define by 2
#define	cx 2
#define	cy 4

#define n 0

	int i = 0;
	float ab = DlinStor(ax, ay, bx, by), bc = DlinStor(bx, by, cx, cy), ca = DlinStor(cx, cy, ax, ay); 
	if (ab > 0 && bc > 0 && ca > 0 && ab + bc > ca && bc + ca > ab && ca + ab > bc)//проверяем существование по длинне сторон (проще и точнее) для проверки условия в препроцессоре
	{
		i = 1;
		printf("Существует:\n");
	}
#define pr i
//#if (abb > n && bcc > n & caa > n && abb + bcc > caa && bcc + caa > abb && caa + abb > bcc)
#if ((ax!=bx||ax!=cx||bx!=cx)&&(ay!=by||ay!=cy||by!=cy)&&!(((ax==bx)&&(ay==by))||((ax==cx)&&(ay==cy))||((bx==cx)&&(by==cy)))&&!((cx - ax) / (bx - ax) == (cy - ay) / (by - ay))) //константная проверка через расположение точек
	{ //пришлось поменять условие, т.к sqrt в препроцессорном условии не работает
		float P = ab + bc + ca, pp = P / 2, s = sqrt(pp * (pp - ab) * (pp - bc) * (pp - ca));
		printf("Периметр треугольника = %f, Площадь = %f\n", P, s);
	}
#else
	printf("Такого треугольника не существует!\n");
#endif
}

float DlinStor(float x1, float y1, float x2, float y2)
{
	return sqrt(kv((x2 - x1)) + kv((y2 - y1)));
}


char* obed(char* c1, char* c2)
{
	int schet=0;
	char* c_nach = c1;
	while (*c_nach != '\0')
	{
		schet++;
		c_nach++;
	}
	c_nach = c2;
	while (*c_nach != '\0')
	{
		schet++;
		c_nach++;
	}
	char* sim = malloc(sizeof(char)*(schet+1));
	int i = 0;
	while (c1[i] != '\0')
	{
		sim[i] = c1[i];
		i++;
	}
	int i2 = 0;
	while (c2[i2]!= '\0')
	{
		sim[i] = c2[i2];
		i++;
		i2++;
	}
	sim[i] = '\0';
	return sim;
}

int StrVChisl(char* c)
{
	return atoi(c);
}
char* ChiVStr(int c)
{
	return 	itoa(c);
}


