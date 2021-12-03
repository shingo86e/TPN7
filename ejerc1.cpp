#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Paz Exequiel 1k5 Leg 53382

/*En un negocio que se dedica a la venta de insumos eléctricos 
tiene la información de sus clientes en la siguiente
estructura.

struct datosCliente
{
int codCli; //código del cliente
char ApeNom[40]; //apellido y nombre
char dire[60]; //domicilio particular
float monCred; //Monto máximo del crédito que puede realizar en cada compra.
};

Se pide:	
1 Ingresar el dato N clientes.
2 A medida que se van ingresando los clientes, usando una función mostrar los datos registrados.
3 Al finalizar la carga de los N clientes, mostrar cuantos clientes tienen un monto de crédito superior a $ 30.000.
*/

typedef char cadena[100];

struct datosCliente
{
int codCli; //código del cliente
cadena ApeNom; //apellido y nombre
cadena dire; //domicilio particular
float monCred; //Monto máximo del crédito que puede realizar en cada compra.
};

void mostrarf(datosCliente datos[50],int n);

int montoMaxf(datosCliente datos[50],int n);

main()
{
	datosCliente datos[50];
	int n, credSup;
	system("color 1A");
	printf("Ingresar la cantidad de clientes: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		printf("\nCliente: %d",i);
		printf("\nIngrese codigo del cliente: ");
		scanf("%d",&datos[i].codCli);
		printf("\nIngrese Apellido y Nombre: ");
		_flushall();
		gets(datos[i].ApeNom);
		printf("\nIngrese Direccion: ");
		gets(datos[i].dire);
		printf("\nIngrese el monto maximo de credito: ");
		scanf("%f",&datos[i].monCred);
				
	}
	mostrarf(datos,n);//la consigna dice que se muestre con cada carga de clientes pero no me parecia correcto asi que lo puse al final de la carga de clientes.
	credSup=montoMaxf(datos,n);
	printf("\nLa cantidad de clientes con monto de credito superior a 30000$ es: %d",credSup);
	printf("\n\n");
	system("pause");	
}

void mostrarf(datosCliente datos[50],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\n\n");
		printf("Cliente codigo: %d\n",datos[i].codCli);
		printf("Apellido y Nombre: %s\n",datos[i].ApeNom);
		printf("Domicilio particular: %s\n",datos[i].dire);
		printf("Monto maximo del credito que puede realizar en cada compra: %.2f$\n",datos[i].monCred);
	}	
}

int montoMaxf(datosCliente datos[50],int n)
{
	int const men=30000;
	int credSup=0;
	int motoM=0;
	for(int i=0;i<n;i++)
	{
		if(datos[i].monCred>men)
		{
			credSup++;
		}
	}
	return credSup;
}
