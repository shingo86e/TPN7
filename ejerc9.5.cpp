#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <windows.h> 

//Paz Exequiel 1k5 Leg 53382

/*Se desea almacenar el inventario de un comercio de artículos deportivos, en un arreglo de registro.
La descripción de cada artículo, contiene.

- Código, Descripción, cantidad en stock, precio unitario.

Desarrolla un programa controlado por un menú, que brinde opciones para:
	
a. Ingresar N registros en el arreglo.

b. Buscar un artículo, dado su código y mostrar sus datos en pantalla. 
Si el artículo es encontrado dar la posibilidad de eliminar dicho artículo del arreglo. 
En caso de no ser encontrado mostrar por pantalla informando que el artículo no
fue encontrado. 
Tener en cuenta que si se eliminó un artículo, se debe reagrupar el arreglo para no dejar celdas vacías.

c. Lista todo el inventario, ordenado alfabéticamente (decreciente) según descripción de cada artículo. El ordenamiento
se deberá realizar en otro arreglo.

d. Lista todo el inventario, ordenado crecientemente por cantidad de stock. (usar otro arreglo, puede ser el mismo que
se usó para ordenar alfabéticamente.*/

typedef char cadena[50];

struct registro
{
	cadena codigo;
	cadena descripcion;
	int stock;
	float precio;
};

void gotoxy(int x,int y);

void cargarf(registro articulos[50],int &n);

void buscarMostrarEliminarf(registro articulos[100],int &n);

void listarDecreciente(registro articulos[50],int n,registro copia[50]);

void listarCreciente(registro articulos[50],int n,registro copia[50]);

main()
{
	registro articulos[50];
	registro copia[50];
	int n=0, option;
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	system("color 1A");	
	
	do
	{
		gotoxy(18,0);
		printf("Menu");
		printf("\n----------------------------------------");
		printf("\n----------------------------------------");
		printf("\n1) Ingresar articulos.");
		printf("\n2) Buscar y mostrar en pantalla/Eliminar articulo.");
		printf("\n3) Listar y ordenar articulos alfabeticamente decreciente Z-A.");
		printf("\n4) Listar y ordenar articulos alfabeticamente creciente A-Z.");
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
					cargarf(articulos,n);
					break;
				}
			case 2:
				{
					if(n!=0)
					{
						buscarMostrarEliminarf(articulos,n);
					}
					else
					{
						printf("\nAun no se ingresaron productos.");
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
						listarDecreciente(articulos,n,copia);
					}
					else
					{
						printf("\nAun no se ingresaron productos.");
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
						listarCreciente(articulos,n,copia);
					}
					else
					{
						printf("\nAun no se ingresaron productos.");
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

void cargarf(registro articulos[50],int &n)
{
	char b;
	int x=0,y=0;
	
	do//uso n en el subindice porque así si necesito cargar otro producto no piso el registro anterior
	{
		gotoxy(10,0);
		printf("Ingreso de Articulos");
		printf("\n----------------------------------------");
		printf("\nCodigo: ");
		_flushall();
		gets(articulos[n].codigo);
		printf("Descripcion: ");
		gets(articulos[n].descripcion);
		printf("Stock: ");
		scanf("%d",&articulos[n].stock);
		printf("Precio del Articulo: ");
		scanf("%f",&articulos[n].precio);
		do
		{
			printf("\nDesea continuar ingresando Articulos? S/N\n");
			b=getch();
			if (b >= 'a' && b <= 'z')
       		b = b - 'a' + 'A';
			if(b!='S' && b!='N')
			{
				printf("\nOpcion no valida!!\n\n");
				getch();
			}
			system("cls");
		}
		while(b!='S' && b!='N');
		n++;
	}
	while(b=='S');
	gotoxy(x,y);
	printf("|Codigo");	
	gotoxy(x+11,y);
	printf("|Descripcion");
	gotoxy(x+27,y);
	printf("|Precio/Unitario");
	gotoxy(x+47,y);
	printf("|Stock actual");
	gotoxy(x+89,y);
	printf("|");
	y=1;
	gotoxy(x,y);
	printf("-----------------------------------------------------------------------------------------");
	for (int i=0;i<n;i++)
	{
		y++;
		gotoxy(x,y);
		printf("|%s",articulos[i].codigo);	
		gotoxy(x+11,y);
		printf("|%s",articulos[i].descripcion);
		gotoxy(x+27,y);
		printf("|$%.2f",articulos[i].precio);
		gotoxy(x+47,y);
		printf("|%dU",articulos[i].stock);
		gotoxy(x+89,y);
		printf("|");
	}
	getch();
	system("cls");
}

void buscarMostrarEliminarf(registro articulos[100],int &n)
{
	int comparar,b=0;
	cadena codigo;
	char c ;
	cadena cero="cero";
	do
	{
		gotoxy(11,0);
		printf("Buscar/Mostrar/Eliminar");
		printf("\n----------------------------------------");
		printf("\nCodigo de articulo: ");
		_flushall();
		gets(codigo);
		for(int i=0;i<n;i++)
		{
			comparar=strcmp(codigo,articulos[i].codigo);
			if(comparar==0)
			{
				do
				{
					printf("\n%s",articulos[i].descripcion);
					printf("\n%d",articulos[i].stock);
					printf("\n$%.2f",articulos[i].precio);
					printf("\n----------------------------------------");
					printf("\nDesea Eliminar el artículo? S/N");
					c=getch();
					if (c >= 'a' && c <= 'z')
       				c = c - 'a' + 'A';					
					if(c!='S' && c!='N')
					{
						printf("\nLa opción no es valida!");
						getch();
						system("cls");
					}
					if(c=='S')
					{
						for(i;i<n;i++)
						_flushall();
						strcpy(articulos[i].codigo,articulos[i+1].codigo);
						strcpy(articulos[i].descripcion,articulos[i+1].descripcion);
						articulos[i].stock=articulos[i+1].stock;
						articulos[i].precio=articulos[i+1].precio;
					}
				}
				while(c!='S' && c!='N');
				b++;
				system("cls");
			}		
		}
		if(b==0)
			{
				printf("\nEl codigo ingresado no es correcto");
				printf("\n");
				printf("\nDesea ingresar un nuevo codigo?");
				printf("\nContinuar \"0\"");
				printf("\nSalir \"1\"\n");
				scanf("%d",&b);
				system("cls");
			}	
	}
	while(b==0);
	if(c=='S')
	{			
		printf("\nArticulo eliminado exitosamente!");
		n--;
	}
	else
	{
		printf("\nNo se eliminaron articulos");
	}	
}

void listarDecreciente(registro articulos[50],int n,registro copia[50])
{
	int comparar,x=0,y=0;
	registro aux[50];
	bool borrado;
	
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			_flushall();
			strcpy(copia[i].descripcion,articulos[i].descripcion);
			strcpy(copia[i].codigo,articulos[i].codigo);
			copia[i].stock=articulos[i].stock;
			copia[i].precio=articulos[i].precio;
		}
	}
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			comparar=strcmp(copia[i].descripcion,copia[i+1].descripcion);
			if(comparar<0)
			{
				_flushall();
				strcpy(aux[i].codigo,copia[i].codigo);
				strcpy(copia[i].codigo,copia[i+1].codigo);
				strcpy(copia[i+1].codigo,aux[i].codigo);
				strcpy(aux[i].descripcion,copia[i].descripcion);
				strcpy(copia[i].descripcion,copia[i+1].descripcion);
				strcpy(copia[i+1].descripcion,aux[i].descripcion);
				aux[i].stock=copia[i].stock;
				copia[i].stock=copia[i+1].stock;
				copia[i+1].stock=aux[i].stock;
				aux[i].precio=copia[i].precio;
				copia[i].precio=copia[i+1].precio;
				copia[i+1].precio=aux[i].precio;
			}
		}
	}
	gotoxy(x,y);
	printf("|Codigo");	
	gotoxy(x+11,y);
	printf("|Descripcion");
	gotoxy(x+27,y);
	printf("|Precio/Unitario");
	gotoxy(x+47,y);
	printf("|Stock actual");
	gotoxy(x+89,y);
	printf("|");
	y=1;
	gotoxy(x,y);
	printf("-----------------------------------------------------------------------------------------");
	for (int i=0;i<n;i++)
	{
		y++;
		gotoxy(x,y);
		printf("|%s",copia[i].codigo);	
		gotoxy(x+11,y);
		printf("|%s",copia[i].descripcion);
		gotoxy(x+27,y);
		printf("|$%.2f",copia[i].precio);
		gotoxy(x+47,y);
		printf("|%dU",copia[i].stock);
		gotoxy(x+89,y);
		printf("|");		
	}

	
}

void listarCreciente(registro articulos[50],int n,registro copia[50])
{
	int comparar,x=0,y=0;
	registro aux[50];
	
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			_flushall();
			strcpy(copia[i].descripcion,articulos[i].descripcion);
			strcpy(copia[i].codigo,articulos[i].codigo);
			copia[i].stock=articulos[i].stock;
			copia[i].precio=articulos[i].precio;
		}
	}
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			comparar=strcmp(copia[i].descripcion,copia[i+1].descripcion);
			if(comparar>0)
			{
				_flushall();
				strcpy(aux[i].codigo,copia[i].codigo);
				strcpy(copia[i].codigo,copia[i+1].codigo);
				strcpy(copia[i+1].codigo,aux[i].codigo);
				strcpy(aux[i].descripcion,copia[i].descripcion);
				strcpy(copia[i].descripcion,copia[i+1].descripcion);
				strcpy(copia[i+1].descripcion,aux[i].descripcion);
				aux[i].stock=copia[i].stock;
				copia[i].stock=copia[i+1].stock;
				copia[i+1].stock=aux[i].stock;
				aux[i].precio=copia[i].precio;
				copia[i].precio=copia[i+1].precio;
				copia[i+1].precio=aux[i].precio;
			}
		}
	}
	
	gotoxy(x,y);
	printf("|Codigo");	
	gotoxy(x+11,y);
	printf("|Descripcion");
	gotoxy(x+27,y);
	printf("|Precio/Unitario");
	gotoxy(x+47,y);
	printf("|Stock actual");
	gotoxy(x+89,y);
	printf("|");
	y=1;
	gotoxy(x,y);
	printf("-----------------------------------------------------------------------------------------");
	for (int i=0;i<n;i++)
	{
		y++;
		gotoxy(x,y);
		printf("|%s",copia[i].codigo);
		gotoxy(x+11,y);
		printf("|%s",copia[i].descripcion);
		gotoxy(x+27,y);
		printf("|$%.2f",copia[i].precio);
		gotoxy(x+47,y);
		printf("|%dU",copia[i].stock);
		gotoxy(x+89,y);
		printf("|");	
	}	
}
