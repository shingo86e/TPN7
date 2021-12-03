#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Paz Exequiel 1k5 Leg 53382

/*En un colegio secundario los datos de los alumnos están en un registro que contiene los siguientes miembros
(campos):
	
? Nro. de Documento.
? Apellido y nombre.
? Fecha Nacimiento. (es un registro de 3 campos: día, mes, año. Año tiene 4 dígitos)
? Notas Trimestrales (es un registro de 4 campos: Primer Trimestre, Segundo Trimestre, Tercer Trimestre y promedio
anual)

Se pide:
a) Definir de manera apropiada cada uno de los registros y vincular de manera de crear registro de jerarquía.

b) Realizar la carga de N alumnos. Teniendo en cuenta que el campo promedio anual, no se lo pide su ingreso, se
calcula de los tres trimestres que tiene el alumno.

c) A medida que se realiza la carga determinar y mostrar en main, cuántos alumnos están por arriba de un promedio ocho.*/

struct fecha
{
	int dia,mes,anio;
};

struct notas
{
	float primerC,segundoC,tercerC,promedioAnual;
};

struct registro
{
	int DNI;
	char apeNom[50];
	fecha fechaNac;
	notas notasAlum;
};

void cargarf(registro alumnos[50], int n);

void mostarf(registro alumnos[50], int n);

main()
{
	int n;
	registro alumnos[50];
	
	printf("Ingrese la cantidad de alumnos: ");
	scanf("%d",&n);
	cargarf(alumnos,n);
	mostarf(alumnos,n);
	printf("\n\n");
	system("pause");
}

void cargarf(registro alumnos[50], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nIngrese DNI del alumno: ");
		scanf("%d",&alumnos[i].DNI);
		printf("\nIngrese Apellido y Nombre: ");
		_flushall();
		gets(alumnos[i].apeNom);
		printf("\nIngrese fecha de Nacimiento:(dd/mm/aaaa)");
		printf("\nDia: ");
		scanf("%d",&alumnos[i].fechaNac.dia);
		printf("\nMes: ");
		scanf("%d",&alumnos[i].fechaNac.mes);
		printf("\nAnio: ");
		scanf("%d",&alumnos[i].fechaNac.anio);
		printf("\nIngrese Notas del alumno");
		printf("\nPrimer Cuatrimestre: ");
		scanf("%f",&alumnos[i].notasAlum.primerC);
		printf("\nSegundo Cuatrimestre: ");
		scanf("%f",&alumnos[i].notasAlum.segundoC);
		printf("\nTercer Cuatrimestre: ");
		scanf("%f",&alumnos[i].notasAlum.tercerC);
		alumnos[i].notasAlum.promedioAnual=(alumnos[i].notasAlum.primerC+alumnos[i].notasAlum.segundoC+alumnos[i].notasAlum.tercerC)/3;
		printf("\n");
	}
	
}
void mostarf(registro alumnos[50], int n)
{
	int contar=0;
	for(int i=0;i<n;i++)
	{
		if(alumnos[i].notasAlum.promedioAnual>8)
		{
			contar++;
		}
	}
	printf("\nLa cantidad de alumnos con promedio anual superior a 8 son: %d",contar);
	printf("\n\nEl listado de alumnos con promedio superior a 8 es: \n");
	
	for(int i=0;i<n;i++)
	{
		if(alumnos[i].notasAlum.promedioAnual>8)
		{
			printf("\nApellido y Nombre: %s",alumnos[i].apeNom);
			printf("\nFecha de Nacimiento: %d/%d/%d",alumnos[i].fechaNac.dia,alumnos[i].fechaNac.mes,alumnos[i].fechaNac.anio);
			printf("\nNotas: ");
			printf("\nPrimer Cuatrimestre: %.2f",alumnos[i].notasAlum.primerC);
			printf("\nSegundo Cuatrimestre: %.2f",alumnos[i].notasAlum.segundoC);
			printf("\nTercer Cuatrimestre: %.2f",alumnos[i].notasAlum.tercerC);
			printf("\nPromedio Anual: %.2f",alumnos[i].notasAlum.promedioAnual);
			printf("\n");
		}
		
	}
	
}
