#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <windows.h> 

//Paz Exequiel 1k5 Leg 53382


/* En un negocio de venta de artículos para el hogar se registra el stock o existencia de sus productos en un vector
de estructuras que tiene los siguientes datos:
	
? Código. //Código producto 5 dígitos.
? Artículo. //Nombre del producto.
? Cantidad mínima. //es el stock mínimo que puede tener el producto.
? Fecha Última Compra. (anidar) //Fecha última Compra realizada.
? Existencia Actual. //Cantidad disponible del producto para la venta.
? Precio //Monto de venta final al público.

Se PIDE:
	
definir las estructuras necesarias para

a. Ingresar como mínimo 10 productos.

b. Ingresado un determinado código, actualizar su existencia actual y la fecha de compra.
Usar función que recibe entre otros datos necesarios el código del producto, 
fecha de compra, cantidad comprada. 
En caso de no encontrar el código del producto mostrar un mensaje de error.

c. Realizar la venta de un determinado producto solicitando su código y 
mostrar en pantalla su descripción, precio, solicitar la cantidad comprada y 
mostrar el monto a pagar. Controlar que la Venta no sea mayor a la Existencia actual. 
Usar función.

Ejemplo:
Código		Descripción						Precio/Unitario		Cantidad Solicitada		Monto Pagar
-----------------------------------------------------------------------------------------------------
			mostrar la info del registo		Mostrar la info del registro				precio*cantidad
			
d. Usando una función mostrar por pantallas todos los productos que tienen una existencia Actual menor a la cantidad
mínima para realizar el pedido o compra de los productos y reponer su stock.
*/

typedef char cadena[100];

struct fecha
{
	int dia,mes,anio;
};

struct registro
{
	cadena codigo,articulo;
	int cantidadMinima;
	fecha fechaUltimaCompra;
	int stock;
	float precioProducto;
};

void gotoxy(int x,int y);

void cargarf(registro productos[100],int &n);

void actualizarf(registro productos[100],int n);

void ventaf(registro productos[100],int n);

void listarf(registro productos[100],int n);

main()
{
	registro productos[100];
	int n=0, option;
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	system("color 1A");	
	
	do
	{
		gotoxy(18,0);
		printf("Menu");
		printf("\n----------------------------------------");
		printf("\n----------------------------------------");
		printf("\n1) Ingresar productos.");
		printf("\n2) Actualizar existencia actual de un producto.");
		printf("\n3) Venta de un producto.");
		printf("\n4) Listar productos con bajo stock.");
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
					cargarf(productos,n);
					break;
				}
			case 2:
				{
					if(n!=0)
					{
						actualizarf	(productos,n);
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
						ventaf(productos,n);
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
						listarf(productos,n);
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

void cargarf(registro productos[100],int &n)
{
	char b;
	
	do//uso n en el subindice porque así si necesito cargar otro producto no piso el registro anterior
	{
		gotoxy(10,0);
		printf("Ingreso de productos");
		printf("\n----------------------------------------");
		printf("\nCodigo: ");
		_flushall();
		gets(productos[n].codigo);
		printf("Nombre de articulo: ");
		gets(productos[n].articulo);
		printf("Ingresar fecha de ultima compra (dd/mm/aaa)");
		printf("\nDia: ");
		scanf("%d",&productos[n].fechaUltimaCompra.dia);
		printf("Mes: ");
		scanf("%d",&productos[n].fechaUltimaCompra.mes);
		printf("Anio: ");
		scanf("%d",&productos[n].fechaUltimaCompra.anio);
		printf("Stock: ");
		scanf("%d",&productos[n].stock);
		printf("Precio del producto: ");
		scanf("%f",&productos[n].precioProducto);
		do
		{
			printf("\nDesea continuar ingresando productos? S/N\n");
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
}

void actualizarf(registro productos[100],int n)
{
	cadena producto;
	int comparar,b=0;	
	
	
	gotoxy(12,0);
	do
	{
		printf("Actualizar stock");
		printf("\n----------------------------------------");
		printf("\nCodigo de producto: ");
		_flushall();
		gets(producto);
		for(int i=0;i<n;i++)
		{
			comparar=strcmp(producto,productos[i].codigo);
			if(comparar==0)
			{
				printf("\n%s",productos[i].articulo);
				printf("\nIngresar fecha de compra (dd/mm/aaa)");
				printf("\nDia: ");
				scanf("%d",&productos[i].fechaUltimaCompra.dia);
				printf("Mes: ");
				scanf("%d",&productos[i].fechaUltimaCompra.mes);
				printf("Anio: ");
				scanf("%d",&productos[i].fechaUltimaCompra.anio);
				printf("Stock: ");
				scanf("%d",&productos[i].stock);
				printf("Precio del producto: ");
				scanf("%f",&productos[i].precioProducto);
				b++;
				printf("\nStock Actualizado con Exito!\n");
				getch();
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
				getch();
				system("cls");
			}
	}
	while(b==0);	
}

void ventaf(registro productos[100],int n)
{
	cadena producto;
	int comparar,b=0, cantidad, x=0,y=0, pos;
	float totalAbonar=0;
	
	
	gotoxy(11,0);
	do
	{
		printf("Venta de Productos");
		printf("\n----------------------------------------");
		printf("\nCodigo de producto: ");
		_flushall();
		gets(producto);
		for(int i=0;i<n;i++)
		{
			comparar=strcmp(producto,productos[i].codigo);
			if(comparar==0)
			{
				printf("\n%s",productos[i].articulo);
				do
				{
					printf("\nCantidad de unidades: ");
					scanf("%d",&cantidad);
					if(cantidad>productos[i].stock)
					{
						printf("\nLa cantidad no puede superar %d.",productos[i].stock);
						getch();
						system("cls");
					}
				}
				while(cantidad>productos[i].stock);
				
				
				b++;
				pos=i;
				getch();
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
				getch();
				system("cls");
			}	
	}
	while(b==0);
	if(b==1)
	{
		gotoxy(x,y);
		printf("\|Codigo");	
		gotoxy(x+11,y);
		printf("\|Descripcion");
		gotoxy(x+27,y);
		printf("\|Precio/Unitario");
		gotoxy(x+47,y);
		printf("\|Cantidad Solicitada");
		gotoxy(x+71,y);
		printf("\|Monto Pagar\|");
		gotoxy(x,y+1);
		printf("----------------------------------------------------------------------------------");
		gotoxy(x,y+2);
		printf("\|%s",productos[pos].codigo);	
		gotoxy(x+11,y+2);
		printf("\|%s",productos[pos].articulo);
		gotoxy(x+27,y+2);
		printf("\|$%.2f",productos[pos].precioProducto);
		gotoxy(x+47,y+2);
		printf("\|%dU",cantidad);
		totalAbonar=(float)productos[pos].precioProducto*cantidad;
		gotoxy(x+71,y+2);
		printf("\|$%.2f",totalAbonar);
		productos[pos].stock=productos[pos].stock-cantidad;
		gotoxy(x+83,y+2);
		printf("\|");
		getch();
		system("cls");
	}	
}

void listarf(registro productos[100],int n)
{
	const int stockMinimo=1000;
	int x=0,y=0, comprar[100];
	
	gotoxy(x,y);
	printf("\|Codigo");	
	gotoxy(x+11,y);
	printf("\|Descripcion");
	gotoxy(x+27,y);
	printf("\|Precio/Unitario");
	gotoxy(x+47,y);
	printf("\|Stock actual");
	gotoxy(x+64,y);
	printf("\|Cantidad Minima de Compra\|");
	y=1;
	gotoxy(x,y);
	printf("-----------------------------------------------------------------------------------------");
	for(int i=0;i<n;i++)
	{
		if(productos[i].stock<stockMinimo)
		{
			y++;
			gotoxy(x,y);
			printf("\|%s",productos[i].codigo);	
			gotoxy(x+11,y);
			printf("\|%s",productos[i].articulo);
			gotoxy(x+27,y);
			printf("\|$%.2f",productos[i].precioProducto);
			gotoxy(x+47,y);
			printf("\|%dU",productos[i].stock);
			comprar[i]=stockMinimo-productos[i].stock;
			gotoxy(x+64,y);
			printf("\|%dU",comprar[i]);
			gotoxy(x+90,y);	
			printf("\|"	);	
		}
	}
	getch();
	system("cls");
}
