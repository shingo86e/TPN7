#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Paz Exequiel 1k5 Leg 53382

/*Una concesionaria de autos registra el día sábado las ventas realizadas en la semana. 
El registro tiene la siguiente estructura jerarquizada:
	
struct fecha{
int dia;
int mes;
int anio;
};
struct datosCliente{
char ApeNom[40]; //apellido y nombre del cliente
char dire[60]; //domicilio particular del cliente
float monVehi; //Monto del vehículo.
fecha fecVenta; //Fecha de venta del vehículo.
};

Se pide:
a) Ingresar las N ventas realizadas en la semana.

b) A medida que se registran las ventas, por medio de una función, determinar en qué fecha se vendió menos.

c) Haciendo uso de una función a medida que se ingresa los datos de un cliente mostrar en pantalla los datos ingresados.
*/

struct fecha
{
int dia;
int mes;
int anio;
};
struct datosCliente
{
char ApeNom[40]; //apellido y nombre del cliente
char dire[60]; //domicilio particular del cliente
float monVehi; //Monto del vehículo.
fecha fecVenta; //Fecha de venta del vehículo.
};

int menorf(datosCliente ventas[50], int n);

void cargarf(datosCliente ventas[50], int n, int &pos);

void mostrarf(datosCliente ventas[50], int n);

main()
{
	int n, pos=0;
	datosCliente ventas[50];
	printf("Ingrese la cantidad de ventas realizadas en la semana: \n");
	scanf("%d",&n);
	cargarf(ventas,n,pos);
	printf("La fecha que se vendio menos fue: %d/%d/%d\n\n",ventas[pos].fecVenta.dia,ventas[pos].fecVenta.mes,ventas[pos].fecVenta.anio);
	mostrarf(ventas,n);
	printf("\n\n");
	system("pause");
}

int menorf(datosCliente ventas[50], int n)
{
	int pos;
	float  suma[50], men,may;
	for(int i=0;i<n;i++)
	{
		suma[i]=ventas[i].monVehi;
		for(int j=0;j<n;j++)
		{
			if(ventas[i].fecVenta.dia==ventas[j+1].fecVenta.dia && ventas[i].fecVenta.mes==ventas[j+1].fecVenta.mes && ventas[i].fecVenta.anio==ventas[j+1].fecVenta.anio)
			{
				suma[i]= suma[i] + ventas[j+1].monVehi;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(suma[i]>may)
		{
			may=suma[i];
		}
	}
	men=may;// me aseguro de que men se inicia antes de la compracion con el mayor valor del array
	for(int i=0;i<n;i++)
	{
		if(suma[i]<men)
		{
			men=suma[i];
			pos=i;
		}
	}
	
	return pos;
}

void cargarf(datosCliente ventas[50], int n, int &pos)
{
	for(int i=0;i<n;i++)
	{
		printf("\n");
		printf("cliente Nro: %d",i);
		printf("\nIngrese Apellido y Nombre: ");
		_flushall();
		gets(ventas[i].ApeNom);
		printf("\nIngrese Domicilio Particular del cliente: ");
		gets(ventas[i].dire);
		printf("\nIngrese Monto del Vehiculo: ");
		scanf("%f",&ventas[i].monVehi);		
		printf("\nIngrese fecha de venta: \n");		
		printf("Dia: ");
		scanf("%d",&ventas[i].fecVenta.dia);
		printf("Mes: ");
		scanf("%d",&ventas[i].fecVenta.mes);
		printf("Anio: ");
		scanf("%d",&ventas[i].fecVenta.anio);
		system("pause");
		system("cls");
	}
	pos=menorf(ventas,n);
}

void mostrarf(datosCliente ventas[50], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\n");
		printf("cliente Nro: %d",i);
		printf("\nApellido y Nombre: %s",ventas[i].ApeNom);
		printf("\nDomicilio Particular del cliente: %s",ventas[i].dire);
		printf("\nMonto del Vehiculo: $%.2f",ventas[i].monVehi);
		printf("\nFecha de venta: : %d/%d/%d",ventas[i].fecVenta.dia,ventas[i].fecVenta.mes,ventas[i].fecVenta.anio);
		printf("\n");
	}
}
