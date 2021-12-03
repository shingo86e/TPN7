#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <windows.h> 

//Paz Exequiel 1k5 Leg 53382

/*Una empresa lleva los datos de sus empleados en un arreglo (vector), tener en cuenta que la empresa puede
tener un número máximo de 20 empleados. Los datos que se registran tiene la siguiente información.

? Apellido y Nombre
? Domicilio
? Fecha de Ingreso (anidar) //el año tiene 4 dígitos.
? Fecha de Proceso (anidar) //el año tiene 4 dígitos.
? Antigüedad (Se calcula durante el ingreso de los datos Fecha de Proceso – Fecha de Ingreso).

SE PIDE: definir las estructuras necesarias para

a) Ingresar los datos de los empleados hasta que se decida terminar el ingreso 
o se hayan cargado todos los empleados. (para continuar se deberá preguntar si continua o no)

b) Terminada la carga, calcular y mostrar el promedio de Antigüedad de todos los empleados. Usar una función.

c) Ingresado un determinado apellido y nombre y por medio de una función Listar por pantalla su Antigüedad. En
caso de no existir el empleado mostrar un mensaje de error.

d) Listar todos los empleados de la empresa.*/

typedef char cadena[100];

struct fecha
{
	int dia,mes,anio;
};

struct registro
{
	cadena apeNom, domicilio;
	fecha fechaIngreso, fechaProceso, antiguedad;	
};

void gotoxy(int x,int y);

void cargarEmpleadosf(registro empleados[20], int &n);

void calcularPromedioTotalf(registro empleados[20], int n);

void antiguedadEmpleadof(registro empleados[20], int n);

void listarEmpleadof(registro empleados[20], int n);

main()
{
	registro empleados[20];
	int n=0, option;
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	system("color 1A");	
	do
	{
		gotoxy(18,0);
		printf("Menu");
		printf("\n----------------------------------------");
		printf("\n----------------------------------------");
		printf("\n1) Ingresar datos de empleados.");
		printf("\n2) promedio de antiguedad de todos los empleados.");
		printf("\n3) Mostrar antiguedad de un empleado.");
		printf("\n4) Listar empleados.");
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
					cargarEmpleadosf(empleados,n);
					break;
				}
			case 2:
				{
					if(n!=0)
					{
						calcularPromedioTotalf(empleados,n);
					}
					else
					{
						printf("\nAun no se ingresaron propietarios.");
						printf("\nVolviendo al menu principal...\n");
					}
					getch();
					system("cls");	
					
					break;
				}
			case 3:
				{
					if(n!=0)
					{
						antiguedadEmpleadof(empleados,n);
					}
					else
					{
						printf("\nAun no se ingresaron propietarios.");
						printf("\nVolviendo al menu principal...\n");
					}
					getch();
					system("cls");
					break;
				}
			case 4:
				{
					if(n!=0)
					{
						listarEmpleadof(empleados,n);
					}
					else
					{
						printf("\nAun no se ingresaron propietarios.");
						printf("\nVolviendo al menu principal...\n");
					}
					getch();
					system("cls");
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
					getch();
					system("cls");
				}	
		}	
	}
	while(option!=0);	
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

void cargarEmpleadosf(registro empleados[20], int &n)
{
	int i=0;
	char b;
	
	do	
	{
		gotoxy(11,0);
		printf("Carga de Empleados");
		printf("\n----------------------------------------");
		printf("\nEmpleado (%d)",i);
		printf("\nApellido y Nombre: ");
		_flushall();
		gets(empleados[i].apeNom);
		printf("Domicilio: ");
		gets(empleados[i].domicilio);
		printf("Fecha de Ingreso: (dd/mm/aaaa)");
		printf("\nDia: ");
		scanf("%d",&empleados[i].fechaIngreso.dia);
		printf("Mes: ");
		scanf("%d",&empleados[i].fechaIngreso.mes);
		printf("Anio: ");
		scanf("%d",&empleados[i].fechaIngreso.anio);
		printf("Fecha de Proceso: (dd/mm/aaaa)");
		printf("\nDia: ");
		scanf("%d",&empleados[i].fechaProceso.dia);
		printf("Mes: "); 
		scanf("%d",&empleados[i].fechaProceso.mes);
		printf("Anio: ");
		scanf("%d",&empleados[i].fechaProceso.anio);
		empleados[i].antiguedad.dia=empleados[i].fechaProceso.dia-empleados[i].fechaIngreso.dia;
		empleados[i].antiguedad.mes=empleados[i].fechaProceso.mes-empleados[i].fechaIngreso.mes;
		empleados[i].antiguedad.anio=empleados[i].fechaProceso.anio-empleados[i].fechaIngreso.anio;
		printf("\n\nDesea ingresar otro empleado? S/N ");
		b=getch();
		i++;		
		system("cls");
	}
	while(i<20 && b!='n');
	n=i;
}

void calcularPromedioTotalf(registro empleados[20], int n)
{
	float promedioDia, promedioMes, promedioAnio;
	registro sumaAntiguedad;
	
	printf("Promedio de antiguedad de todos los empleados");
	printf("\n---------------------------------------------");
	sumaAntiguedad.antiguedad.dia=0;
	sumaAntiguedad.antiguedad.mes=0;
	sumaAntiguedad.antiguedad.anio=0;
	for(int i=0;i<n;i++)
	{
		sumaAntiguedad.antiguedad.dia=sumaAntiguedad.antiguedad.dia+empleados[i].antiguedad.dia;
		sumaAntiguedad.antiguedad.mes=sumaAntiguedad.antiguedad.mes+empleados[i].antiguedad.mes;
		sumaAntiguedad.antiguedad.anio=sumaAntiguedad.antiguedad.anio+empleados[i].antiguedad.anio;
	}
	promedioDia=(float)sumaAntiguedad.antiguedad.dia/n;
	promedioMes=(float)sumaAntiguedad.antiguedad.mes/n;
	promedioAnio=(float)sumaAntiguedad.antiguedad.anio/n;
	printf("\nDias: %.2f",promedioDia);
	printf("\nMeses: %.2f",promedioMes);
	printf("\nAnios: %.2f",promedioAnio);

}

void antiguedadEmpleadof(registro empleados[20], int n)
{
	cadena empleado;
	int comparar,b=0;
	int dias,meses,anios;
	do
	{
		gotoxy(9,0);
		printf("Antiguedad por Empleado");
		printf("\n----------------------------------------");
		printf("\nIngrese el apellido y nombre del empleado: ");
		_flushall();
		gets(empleado);
		for(int i=0;i<n;i++)
		{
			comparar=strcmp(empleado,empleados[i].apeNom);
			if(comparar==0)
			{
				printf("\nDias: %d",empleados[i].antiguedad.dia);
				printf("\nMeses: %d",empleados[i].antiguedad.mes);
				printf("\nAnios: %d",empleados[i].antiguedad.anio);
				b++;				
			}
		}
		if(b==0)
		{
			printf("\nNo se encontro el apellido y nombre en la base de datos");
			printf("\nIngresar nuevamente el apellido y nombre?");
			printf("\nSI - presione \"0\".");
			printf("\nNO - presione \"1\".\n");
			scanf("%d",&b);
			printf("\n");
			system("pause");
			system("cls");
		}
		
	}
	while(b!=1);
}

void listarEmpleadof(registro empleados[20], int n)
{
	char option;
	int bandera=0;
	
	do
	{
		printf("Mostrar en formato de lista o tabla?\n");
		printf("Lista presione l\n");
		printf("Tabla presione t\n");
		option=getch();
		system("cls");
		if(option=='l')
		{
			gotoxy(11,0);
			printf("Lista de Empleados");
			printf("\n----------------------------------------");
			for(int i=0;i<n;i++)
			{
				printf("\nEmpleado %d",i);
				printf("\nApellido y Nombre: %s",empleados[i].apeNom);
				printf("\nDomicilio: %s",empleados[i].domicilio);
				printf("\nFecha de Ingreso (dd/mm/aaaa): %d/%d/%d",empleados[i].fechaIngreso.dia,empleados[i].fechaIngreso.mes,empleados[i].fechaIngreso.anio);
				printf("\nFecha de Proceso (dd/mm/aaaa): %d/%d/%d",empleados[i].fechaProceso.dia,empleados[i].fechaProceso.mes,empleados[i].fechaProceso.anio);
				printf("\nAntiguedad: %d Anios, %d meses y %d dias",empleados[i].antiguedad.anio,empleados[i].antiguedad.mes,empleados[i].antiguedad.dia);
				printf("\n");
			}
			bandera++;
		}
		if(option=='t')
		{
			printf("Lista de Empleados");
			gotoxy(0,0);
			printf("Apellido y Nombre");
			gotoxy(25,0);
			printf("Domicilio");
			gotoxy(45,0);
			printf("Fecha de Ingreso");
			gotoxy(65,0);
			printf("Fecha de Proceso");
			gotoxy(85,0);
			printf("Antiguedad");			
			printf("\n--------------------------------------------------------------------------------------------------------------\n");
			printf("--------------------------------------------------------------------------------------------------------------\n");
			for(int i=0;i<n;i++)
			{
				gotoxy(0,3+i);
				printf("%s",empleados[i].apeNom);
				gotoxy(25,3+i);
				printf("%s",empleados[i].domicilio);
				gotoxy(45,3+i);
				printf("%d/%d/%d",empleados[i].fechaIngreso.dia,empleados[i].fechaIngreso.mes,empleados[i].fechaIngreso.anio);
				gotoxy(65,3+i);
				printf("%d/%d/%d",empleados[i].fechaProceso.dia,empleados[i].fechaProceso.mes,empleados[i].fechaProceso.anio);
				gotoxy(85,3+i);
				printf("%d Anios, %d meses y %d dias",empleados[i].antiguedad.anio,empleados[i].antiguedad.mes,empleados[i].antiguedad.dia);
						
			}
			bandera++;
		}
		if(option!='l' && option!='t')
		{
			printf("Opcion no valida!\n\n");			
			system("pause");
			system("cls");
		}
		
	}
	while(bandera==0);
}

