#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Paz Exequiel 1k5 Leg 53382

/*Las coordenadas de dos puntos en un plano deben guardarse en un registro. 
Hacer un programa con menú de
opciones que permita registrar los dos puntos P1 y P2, representados como registros:
:
1. Cargar dos puntos por teclado.
2. Mostrar los dos puntos en forma de par ordenado. Ej: P1(x1,y1) ; P2(x2,y2)
3. Calcular la distancia del punto P1 al origen de coordenadas (usar teorema de Pitágoras).
4. Calcular y mostrar en pantalla, la longitud del segmento de recta que une los dos puntos.
d(P1,P2) = sqrt( (x2 – x1)2
+ (y2 – y1)2
)*/

struct coordenadas
{
	int x[50];
	int y[50];
};

void mostrarf(coordenadas punto[50]);

int calcularP(coordenadas punto[50]);

void calcularMostrarf(coordenadas punto[50]);

main()
{
	coordenadas punto[50];
	float distanciaP1;
	system("color 1A");
	for(int i=0;i<2;i++)
	{
		printf("Ingrese las coordenadas del Punto %d: \n",i);
		printf("x%d: ",i);
		scanf("%d",&punto[i].x[i]);
		printf("y%d: ",i);
		scanf("%d",&punto[i].y[i]);
	}
	mostrarf(punto);
	distanciaP1=calcularP(punto);
	printf("\n\nLa distancia del punto 0 al origen es: %.2f",distanciaP1);
	calcularMostrarf(punto);
	printf("\n\n");
	system("pause");	
}

void mostrarf(coordenadas punto[50])
{

	for(int i=0;i<2;i++)
	{
		printf("\nPunto %d(%d,%d)",i,punto[i].x[i],punto[i].y[i]);
	}
}

int calcularP(coordenadas punto[50])
{
	int d1=0;
	d1=(float)sqrt(pow(punto[0].x[0],2)+pow(punto[0].y[0],2));
}

void calcularMostrarf(coordenadas punto[50])
{
	float d=0;
	d=(float)sqrt(pow((punto[1].x[1]-punto[0].x[0]),2)+ pow((punto[1].y[1]-punto[0].y[0]),2));
	printf("\n\nLa longitud del segmento de recta que une los dos puntos es: %.2f",d);	
}

