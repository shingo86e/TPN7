#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>
#include <windows.h> 

//Paz Exequiel 1k5 Leg 53382

/*Una empresa registra los datos de sus vendedores en un registro y 
uno de su miembro es un arreglo (vector) que representa el monto de venta realizado 
por el vendedor de lunes a viernes. La estructura de dicho registro es la siguiente:
	
? Apellido y nombre
? Numero de documento
? Fecha Ingreso (o de contrato)
? Venta Semanal //Es un vector de 5 posiciones, posición 0 es el día Lunes, posición 1 día martes…………. y posición 4 es el día viernes

SE PIDE: Defina el registro de vectores de manera apropiada según la descripción 
de los datos y por medio de un menú de opciones realizar las
siguientes operaciones.

a) Registrar como mínimo 5 empleados, sin registrar ventas.

b) Registrar el total de venta al final del día. 
La registración se hará por medio de una función que reciba el apellido y nombre, 
el día de la venta (Lunes, martes,…, viernes), 
y el monto a registrar. 
(Si hubo un error porque apellido y nombre no figura mostrar un mensaje indicando el error)

c) Listar por pantalla las ventas de la semana y el monto total vendido por cada uno de los empleados. Observe el
modelo de listado que debe realizar. (Para este tipo de listado, deberá investigar la máscara o formato que se
aplica a los datos de salida).
Documento	Apellido y nombre		Lunes		Martes		Miércoles	Jueves	Viernes	Total
xx.xxx.xxx	xxxxxxxxx xxxxxxxxxx	xxxx.xx		xxxx.xx		xxxx.xx		xxxx.xx xxxx.xx xxxxx.xx
xx.xxx.xxx	xxxxxxxxx xxxxxxxxxx 	xxxx.xx		xxxx.xx		xxxx.xx		xxxx.xx xxxx.xx xxxxx.xx

d) Modificación de los Datos ventas, se realizara por medio de una función, 
que recibirá entre otros datos necesarios, el Nro. de documento del empleado, 
día a modificar (lunes, martes, etc.) y el monto a cambiar.*/

struct fecha
{
	int dia,mes,anio;
};

struct registro
{
	char apeNom[100];
	int DNI;
	fecha ingreso;
	float ventaSemana[100];
};

void gotoxy(int x,int y);
 
void cargarf(registro vendedores[50],int &n);

void ventasf (registro vendedores[50],int n);

void listarf(registro vendedores[50],int n);

void modificarf(registro vendedores[50],int n);

main()
{
	registro vendedores[100];
	int option=0;
	int n=0;
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	system("color 1A");
	do
	{
		gotoxy(18,0);
		printf("Menu");
		printf("\n----------------------------------------");
		printf("\n----------------------------------------");
		printf("\n1) Ingresar datos de vendedores.");
		printf("\n2) Registrar las ventas por vendedor y dia.");
		printf("\n3) Listar ventas semanal.");
		printf("\n4) Modificar Dato de Venta.");
		printf("\n0) Salir del programa.");
		printf("\n----------------------------------------");
		printf("\n----------------------------------------");
		printf("\nOpcion: ");
		scanf("%d",&option);
		system("cls");
		switch(option)
		{
			case 1:
				{
					cargarf(vendedores,n);
					break;
				}
			case 2:
				{
					ventasf(vendedores,n);
					break;
				}
			case 3:
				{
					listarf(vendedores,n);
					break;
				}
			case 4:
				{
					modificarf(vendedores,n);
					break;
				}
			default:
				{
					if(option!=0)
					{
						printf("\nOpcion no valida");
					}
					else
					{
						printf("\nSaliendo del programa...");
					}
					printf("\n\n");
					system("pause");
				}	
		}
		
	
	}
	while(option!=0);	
	getch();
}

void gotoxy(int x,int y)
{  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
} 
 
void cargarf(registro vendedores[50],int &n)
{
	
	printf("Ingrese la cantidad de vendedores\n(si no desea ingresar ninguno 0)");
	printf("\nVendedores: ");
	scanf("%d",&n);
	
	if(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			printf("\nApellido y Nombre: ");
			_flushall();
			gets(vendedores[i].apeNom);
			printf("\nDNI: ");
			scanf("%d",&vendedores[i].DNI);
			printf("\nFecha de Ingreso(dd/mm/aaaa)");
			printf("\nDia: ");
			scanf("%d",&vendedores[i].ingreso.dia);
			printf("\nMes: ");
			scanf("%d",&vendedores[i].ingreso.mes);
			printf("\nAnio: ");
			scanf("%d",&vendedores[i].ingreso.anio);
		}
	}
	else
	{
		printf("\nVolviendo al menu principal...\n");
	}
	printf("\n\n");
	system("pause");
	//system("cls");
}

void ventasf (registro vendedores[50],int n)
{
	char vendedor[100];
	int comparar, dia=0, encontrar=0,aux[10],j=0, contador=0;
	if(n!=0)
	{
		do
		{
			printf("Ingrese el nombre del vendedor: ");	
			_flushall();
			gets(vendedor);
			for(int i=0;i<n;i++)
			{
				comparar=strcmp(vendedor,vendedores[i].apeNom);
				if(comparar==0)
				{
					do
					{
						printf("\nIngrese el dia: para terminar la carga por dia \"5\"");
						printf("\n0)Lunes.");
						printf("\n1)Martes.");
						printf("\n2)Miercoles.");
						printf("\n3)Jueves.");
						printf("\n4)Viernes.");
						printf("\nOpcion: ");
						scanf("%d",&dia);
						if(dia<0 or dia>5)
						{
							printf("\nLa opcion no es valida\n\n");
							system("pause");
							system("cls");
						}
					}
					while(dia<0 or dia>5);
					aux[j]=dia;
					while(dia!=5)
					{
						printf("\nRegistre el monto de venta total del dia \"%d\": ",dia);
						scanf("%f",&vendedores[i].ventaSemana[dia]);
						system("cls");
						contador++;
						j++;
						do
						{
							printf("\nIngrese el dia: para terminar la carga por dia \"5\"");
							printf("\n0)Lunes.");
							printf("\n1)Martes.");
							printf("\n2)Miercoles.");
							printf("\n3)Jueves.");
							printf("\n4)Viernes.");
							printf("\nOpcion: ");
							scanf("%d",&dia);
							if(dia<0 or dia>5)
							{
								printf("\nLa opcion no es valida\n\n");
								system("pause");
								system("cls");
							}
						}
						while(dia<0 or dia>5);
						for(j=0;j<contador;j++)
						{
							while(aux[j]==dia)
							{
								printf("\nYa ingreso ese dia, ingrese otro.");
								printf("\nIngrese el dia: para terminar la carga por dia \"5\"");
								printf("\n0)Lunes.");
								printf("\n1)Martes.");
								printf("\n2)Miercoles.");
								printf("\n3)Jueves.");
								printf("\n4)Viernes.");
								printf("\nOpcion: ");
								scanf("%d",&dia);								
							}
						}
						
						aux[j]=dia;					
					}
					encontrar++;
				}
				
			}
			if(encontrar==0)
			{
				printf("\nError! El nombre ingresado es incorrecto\n\n");
				system("pause");
				system("cls");
			}
		}
		while(encontrar==0);
	}
	else
	{
		printf("\nAun no se registraron vendedores, volviendo al menu principal...");
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

void listarf(registro vendedores[50],int n)
{
	if(n!=0)
	{
		gotoxy(0,0);
		printf("Documento");
		gotoxy(14,0);
		printf("Apellido y Nombre");
		gotoxy(36,0);
		printf("Lunes");
		gotoxy(46,0);
		printf("Martes");
		gotoxy(57,0);
		printf("Miercoles");
		gotoxy(71,0);
		printf("Jueves");
		gotoxy(82,0);
		printf("viernes");
		gotoxy(94,0);
		printf("Total");	
		printf("\n---------------------------------------------------------------------------------------------------------\n");
		printf("---------------------------------------------------------------------------------------------------------\n");
		for(int i=0;i<n;i++)
		{
			gotoxy(0,3+i);
			printf("%d",vendedores[i].DNI);
			gotoxy(14,3+i);
			printf("%s",vendedores[i].apeNom);
			gotoxy(36,3+i);
			printf("%.2f",vendedores[i].ventaSemana[0]);
			gotoxy(46,3+i);
			printf("%.2f",vendedores[i].ventaSemana[1]);
			gotoxy(57,3+i);
			printf("%.2f",vendedores[i].ventaSemana[2]);
			gotoxy(71,3+i);
			printf("%.2f",vendedores[i].ventaSemana[3]);
			gotoxy(82,3+i);
			printf("%.2f",vendedores[i].ventaSemana[4]);
			vendedores[i].ventaSemana[5]=vendedores[i].ventaSemana[0]+vendedores[i].ventaSemana[1]+vendedores[i].ventaSemana[2]+vendedores[i].ventaSemana[3]+vendedores[i].ventaSemana[4];
			gotoxy(94,3+i);
			printf("%.2f",vendedores[i].ventaSemana[5]);
		
		}
	}
	else
	{
		printf("\nAun no se registraron vendedores, volviendo al menu principal...");
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

void modificarf(registro vendedores[50],int n)
{
	int DNI,dia, encontrar=0;
	
	if(n!=0)
	{
		printf("Modificacion de venta\n\n");
		do
		{
			printf("Ingrese el DNI del empleado: ");
			scanf("%d",&DNI);
			for(int i=0;i<n;i++)
			{
				if(vendedores[i].DNI==DNI)
				{
					
					do
					{
						printf("\nIngrese el dia de la venta a modificar, para terminar \"5\"");
						printf("\n0)Lunes.");
						printf("\n1)Martes.");
						printf("\n2)Miercoles.");
						printf("\n3)Jueves.");
						printf("\n4)Viernes.");
						printf("\nOpcion: ");
						scanf("%d",&dia);
						if(dia<0 or dia>5)
						{
							printf("\nLa opcion no es valida\n\n");
							system("pause");
							system("cls");
						}
						else
						{
							printf("\nRegistre el monto de venta total del dia \"%d\": ",dia);
							scanf("%f",&vendedores[i].ventaSemana[dia]);
							printf("\nModificacion exitosa!");
							printf("\nvolviendo al menu principal...");
						}
					}
					while(dia<0 or dia>5);
					encontrar++;
					
				}
				else
				{
					printf("\nError! El DNI ingresado no se encuentra en la base de datos\n\n");
					system("pause");
					system("cls");
				}
			}
			
			
		}
		while(encontrar==0);
	}
	else
	{
		printf("\nAun no se registraron vendedores, volviendo al menu principal...");
	}
	printf("\n\n");
	system("pause");
	system("cls");
}
