#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <windows.h> 

//Paz Exequiel 1k5 Leg 53382

/*Una empresa dedicada a la fabricación de casas y edificios en registro que contienen 
la siguiente información de la documentación presentada.

? Número de expediente (alfanumérico).
? Nombre propietario.
? Cantidad de metros cuadrados construidos.
? Tipo de obra (0: vivienda básica, 1: vivienda de Lujo, 2: Edificio, 3: predio especial).
? Fecha Registración, de adelanto de obra por un periodo de 12 meses.
? Monto monetario, recibido de adelanto de obra por un periodo de 12 meses.

SE PIDE:
a) Registrar los datos solicitados al menos de 5 registros, si colocar la fecha
 y los montos de adelanto de obra.
 
b) Registrar por medio de una función el monto recibido. La función debe recibir 
por parámetro: Número de expediente, fecha del adelanto y cantidad de dinero recibido.

c) Listar por pantalla los montos recibido un determinado expediente.

Expediente: xxxxxxxxx
Propietario: xxxxxx xxxxxx xxxxxx
Tipo Obra : xxxxxxxxxxxxxx

Fecha Monto
xxxxxxxx xxxx.xx
xxxx.xx xxxx.xx
TOTAL XXXX.XX*/

typedef char cadena[100];

struct fecha
{
	int dia[50],mes[50],anio[50];
};

struct registro
{
	cadena expediente, apeNom;
	int metros;
	int tipoObra;
	fecha fechaReg;
	int pagos;
	float montoAdelanto[50];	
};

void gotoxy(int x,int y);

void cargarf(registro propietarios[50],int &n);

void registrarPago(registro propietarios[50],int n,cadena expediente,int dia,int mes,int anio,float pagos);

void listarPropietariosf(registro propietarios[50],int n,cadena expediente);

main()                   
{
	registro propietarios[50];
	int n=0, dia, mes, anio,option;
	cadena expediente;
	float pagos;
		
	do
	{
		gotoxy(18,0);
		printf("Menu");
		printf("\n----------------------------------------");
		printf("\n----------------------------------------");
		printf("\n1) Ingresar datos de propietarios.");
		printf("\n2) Registrar nuevos pagos.");
		printf("\n3) Listar propietarios.");
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
					cargarf(propietarios,n);
					break;
				}
			case 2:// La función debe recibir por parámetro: Número de expediente, fecha del adelanto y cantidad de dinero recibido.
				{
					if(n!=0)
					{
						printf("Ingrese los datos del pago: ");
						printf("Numero de Expediente: ");
						_flushall();
						gets(expediente);
						printf("\nFecha de adelanto: ");
						printf("\nDia: ");
						scanf("%d",&dia);
						printf("\nMes: ");
						scanf("%d",&mes);
						printf("\nAnio: ");
						scanf("%d",&anio);
						printf("\nMonto de dinero recibido: ");
						scanf("%f",&pagos);
						registrarPago(propietarios,n,expediente,dia,mes,anio,pagos);
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
					printf("Ingrese el expediente a listar: ");
					_flushall();
					gets(expediente);
					listarPropietariosf(propietarios,n,expediente);
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

void cargarf(registro propietarios[50],int &n)
{
	printf("\nIngrese la cantidad de propietarios a registrar\nSi no desea registrar ninguno \"0\"\n");
	scanf("%d",&n);
	if(n!=0)
	{
		for(int i=0;i<n;i++)
		{
			printf("\nExpediente: ");
			_flushall();
			gets(propietarios[i].expediente);
			printf("\nApellido y Nombre: ");
			gets(propietarios[i].apeNom);
			printf("\nCantidad de metros cuadrados por construir: ");
			scanf("%d",&propietarios[i].metros);
			printf("\nTipo de obra: \n0: vivienda basica. \n1: vivienda de Lujo. \n2: Edificio. \n3: predio especial.");
			printf("\nOPcion: ");
			scanf("%d",&propietarios[i].tipoObra);
			propietarios[i].pagos=0;
			printf("\nFecha de Registro(dd/mm/aaaa)");
			printf("\nDia: ");
			scanf("%d",&propietarios[i].fechaReg.dia[propietarios[i].pagos]);
			printf("\nMes: ");
			scanf("%d",&propietarios[i].fechaReg.mes[propietarios[i].pagos]);
			printf("\nAnio: ");
			scanf("%d",&propietarios[i].fechaReg.anio[propietarios[i].pagos]);
			printf("\nIngrese monto de adelanto: ");
			scanf("%f",&propietarios[i].montoAdelanto[propietarios[i].pagos]);			
		}
	}
	else
	{
		printf("\nNo se ingresaron propietarios.");
		printf("\nVolviendo al menu principal...\n");
	}
	printf("\n\n");
	system("pause");
	system("cls");	
}

void registrarPago(registro propietarios[50],int n,cadena expediente,int dia,int mes,int anio,float pagos)
{
	int comparar, band=0;
	
		do
		{
			
			for(int i=0;i<n;i++)
			{
				comparar=strcmp(expediente,propietarios[i].expediente);
				if(comparar==0)
				{
					propietarios[i].pagos++;
					propietarios[i].fechaReg.dia[propietarios[i].pagos]=dia;
					propietarios[i].fechaReg.mes[propietarios[i].pagos]=mes;
					propietarios[i].fechaReg.anio[propietarios[i].pagos]=anio;
					propietarios[i].montoAdelanto[propietarios[i].pagos]=pagos;
					printf("\nRegistro de pago exitoso.");
					printf("\nvolviendo al menu principal...");
					printf("\n\n");
					system("pause");
					system("cls");
					band++;			
				}
												
			}
			if(band==0)
			{
				printf("\nEl expediente ingresado no se encuentra en la base de datos");
				printf("\nSi desea volver a ingresar el expediente ingrese \"1\" \nPara volver al menu principal \"0\".\n");
				printf("Opcion: ");
				scanf("%d",&comparar);
				if(comparar==1)
				{
					printf("\nIngrese Numero de Expediente: ");
					_flushall();
					gets(expediente);
				}
				else
				{
					printf("\n\nvolviendo al menu principal...");
					printf("\n\n");
					system("pause");
					system("cls");
				}
				
			}
		}
		while(comparar!=0);
}

void listarPropietariosf(registro propietarios[50],int n,cadena expediente)
{
	int comparar, band=0;
	int x=0,y=0;
	float sumar=0;
	if(n!=0)
	{
		do
		{
			
			for(int i=0;i<n;i++)
			{
				comparar=strcmp(expediente,propietarios[i].expediente);
				if(comparar==0)
				{
					printf("\nExpediente: %s",propietarios[i].expediente);
					printf("\nPropietario: %s",propietarios[i].apeNom);
					printf("\nTipo de Obra: ");
					if(propietarios[i].tipoObra==0) printf("vivienda basica");
					if(propietarios[i].tipoObra==1) printf("vivienda de Lujo");
					if(propietarios[i].tipoObra==2) printf("Edificio");
					if(propietarios[i].tipoObra==3) printf("predio especial");
					printf("\n\n");
					y=5;
					gotoxy(x,y);
					printf("Fecha");
					gotoxy(x+20,y);
					printf("Monto");
					for(int j=0;j<=propietarios[i].pagos;j++)
					{
						y++;
						gotoxy(x,y);
						printf("%d/%d/%d",propietarios[i].fechaReg.dia[j],propietarios[i].fechaReg.mes[j],propietarios[i].fechaReg.anio[j]);
						gotoxy(x+20,y);
						printf("%.2f",propietarios[i].montoAdelanto[j]);
						sumar=sumar+propietarios[i].montoAdelanto[j];						
					}
					
					y++;
					gotoxy(x,y);
					printf("Total");
					gotoxy(x+20,y);
					printf("%.2f",sumar);
					getch();
					system("cls");
					band++;
				}
												
			}
			if(band==0)
			{
				printf("\nEl expediente ingresado no se encuentra en la base de datos");
				printf("\nSi desea volver a ingresar el expediente ingrese \"1\" \nPara volver al menu principal \"0\".\n");
				printf("Opcion: ");
				scanf("%d",&comparar);
				if(comparar==1)
				{
					printf("\nIngrese Numero de Expediente: ");
					_flushall();
					gets(expediente);
					system("cls");
				}
				else
				{
					printf("\n\nvolviendo al menu principal...");
					getch();
					system("cls");
				}
				
			}
		}
		while(comparar!=0);
	}
	else
	{
		printf("\nAun no se ingresaron propietarios.");
		printf("\nVolviendo al menu principal...\n");
		getch();
		system("cls");
	}
	
}
