#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h> 
#include <wchar.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct productos
{
	int num;
	char gen[50], clas[50], con[50], nom[50], descrip[500];
	string status;
	float precio = 0, IVA = 0, preciot = 0;
};
int n, opc;


productos* juegos;

void alta();
void modificacion();
void baja();
void lista();
void archivos();


int main()
{
	do {

		printf("\n\t MENU DE OPCIONES \n1.-Alta\n2.-Modificacion \n3.-Baja \n4.-Lista \n5.-Limpiar pantalla \n6.-Salir \n");
		scanf_s("%d", &opc);

		switch (opc)
		{
		case 1:
			alta();
			break;

		case 2:
			modificacion();
			break;

		case 3:
			baja();
			break;

		case 4:
			lista();
			break;

		case 5:
			system("cls");
			return main();
			break;

		case 6:
			archivos();
			exit(1);
			break;

		default: printf("\nNumero invalido\n");
			return main();

		}

	} while (opc != 6);



}

void alta()
{

	printf("\n¿cuantos registros desea dar de alta?: ");
	scanf_s("%d", &n);
	juegos = new productos[n];

	for (int i = 1; i <= n; i++)
	{
		printf("\n\tREGISTRO %d\n", i);

		juegos[i].num = i;
		printf("Numero de item: %d", juegos[i].num);

		cin.ignore();
		printf("\nNombre del juego: ");
		cin.getline(juegos[i].nom, 50);

		cin.ignore();
		printf("Descripcion: ");
		cin.getline(juegos[i].descrip, 500);

		printf("Genero: ");
		cin.getline(juegos[i].gen, 50);

		printf("Clasificacion: ");
		cin.getline(juegos[i].clas, 50);

		printf("Consola: ");
		cin.getline(juegos[i].con, 50);

		printf("Precio: ");
		scanf_s("%f", &juegos[i].precio);


	}
}

void modificacion()
{
	int j, op, op2;
	do
	{
		cin.ignore();
		printf("\nIngrese el numero de registro que quiere modificar: ");
		scanf_s("%d", &j);

		for (int i = j; i == j; i++)
		{
			if ((juegos[i].status == "ELIMINADO"))
			{
				printf("\nREGISTRO %d ELIMINADO", j);
				printf("\nIngrese un registro valido\n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);

	cin.ignore();
	printf("\n\t¿Que desea modificar?\n1.-Nombre\n2.-Descripcion\n3.-Genero\n4.-Clasificacion\n5.-Consola\n6.-Precio\n");
	scanf_s("%d", &op);

	switch (op)
	{
	case 1:

		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("\nIngrese el nombre: ");
			cin.getline(juegos[i].nom, 50);
		}
		break;

	case 2:

		for (int i = j; i == j; i++)
		{
			cin.ignore();
			printf("\nIngrese la nueva descripcion: ");
			cin.getline(juegos[i].descrip, 500);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("\nIngrese el genero: ");
			cin.getline(juegos[i].gen, 50);
		}
		break;

	case 4:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("\nIngrese la clasificacion: ");
			cin.getline(juegos[i].clas, 50);
		}
		break;

	case 5:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n');
			printf("\nIngrese la consola: ");
			cin.getline(juegos[i].con, 50);
		}
		break;

	case 6:
		for (int i = j; i == j; i++)
		{
			cin.ignore();
			printf("\nIngrese el precio: ");
			scanf_s("%f", &juegos[i].precio);
		}
		break;

	default:
		printf("Ingrese un numero valido");
		break;

	}


}

void lista()
{
	int filtro, fil;
	char buscar[80];

	printf("¿Desea imprimir toda la lista de registros o hacerlo por filtro?\n1.-Lista Completa\n2.-Por filtro\n");
	scanf_s("%d", &fil);

	switch (fil)
	{

	case 1:

		for (int i = 1; i <= n; i++)
		{
			if (juegos[i].status == "ELIMINADO")
			{
				printf("----- REGISTRO %d ELIMINADO -----\n", i);
			}
			else
			{
				printf("----- REGISTRO %d -----\n", i);
				printf("# Item: %d\n", juegos[i].num);
				printf("Nombre: %s\n", juegos[i].nom);
				printf("Descripcion: %s\n", juegos[i].descrip);
				printf("Genero: %s\n", juegos[i].gen);
				printf("Clasificacion: %s\n", juegos[i].clas);
				printf("Consola: %s\n", juegos[i].con);

				juegos[i].IVA = (juegos[i].precio * 16) / 100;
				juegos[i].preciot = juegos[i].precio + juegos[i].IVA;
				printf("Precio Base: %5.2f\nIVA: %5.2f\nPrecio Total: %5.2f\n\n", juegos[i].precio, juegos[i].IVA, juegos[i].preciot);
			}
		}
		break;

	case 2:
		printf("\n\t¿Por cual opción desea buscar?\n1.-Genero\n2.-Consola\n3.-Clasificacion\n");
		scanf_s("%d", &filtro);

		switch (filtro)
		{
		case 1:
			printf("\nIngrese el genero que desea buscar: ");
			scanf_s("%s", buscar, 80);

			for (int i = 1; i <= n; i++)
			{
				if ((strcmp(buscar, juegos[i].gen) == 0) && (juegos[i].status != "ELIMINADO"))
				{

					printf("----- REGISTRO %d -----\n", i);
					printf("# Item: %d\n", juegos[i].num);
					printf("Nombre: %s\n", juegos[i].nom);
					printf("Descripcion: %s\n", juegos[i].descrip);
					printf("Genero: %s\n", juegos[i].gen);
					printf("Clasificacion: %s\n", juegos[i].clas);
					printf("Consola: %s\n", juegos[i].con);

					juegos[i].IVA = (juegos[i].precio * 16) / 100;
					juegos[i].preciot = juegos[i].precio + juegos[i].IVA;
					printf("Precio Base: %5.2f\nIVA: %5.2f\nPrecio Total: %5.2f\n\n", juegos[i].precio, juegos[i].IVA, juegos[i].preciot);

				}
			}

			break;

		case 2:
			printf("\nIngrese la consola que desea buscar: ");
			scanf_s("%s", buscar, 80);

			for (int i = 1; i <= n; i++)
			{
				if ((strcmp(buscar, juegos[i].con) == 0) && (juegos[i].status != "ELIMINADO"))
				{

					printf("----- REGISTRO %d -----\n", i);
					printf("# Item: %d\n", juegos[i].num);
					printf("Nombre: %s\n", juegos[i].nom);
					printf("Descripcion: %s\n", juegos[i].descrip);
					printf("Genero: %s\n", juegos[i].gen);
					printf("Clasificacion: %s\n", juegos[i].clas);
					printf("Consola: %s\n", juegos[i].con);

					juegos[i].IVA = (juegos[i].precio * 16) / 100;
					juegos[i].preciot = juegos[i].precio + juegos[i].IVA;
					printf("Precio Base: %5.2f\nIVA: %5.2f\nPrecio Total: %5.2f\n\n", juegos[i].precio, juegos[i].IVA, juegos[i].preciot);

				}

			}
			break;


		case 3:
			printf("\nIngrese la clasificacion que desea buscar: ");
			scanf_s("%s", buscar, 80);

			for (int i = 1; i <= n; i++)
			{
				if ((strcmp(buscar, juegos[i].clas) == 0) && (juegos[i].status != "ELIMINADO"))
				{

					printf("----- REGISTRO %d -----\n", i);
					printf("# Item: %d\n", juegos[i].num);
					printf("Nombre: %s\n", juegos[i].nom);
					printf("Descripcion: %s\n", juegos[i].descrip);
					printf("Genero: %s\n", juegos[i].gen);
					printf("Clasificacion: %s\n", juegos[i].clas);
					printf("Consola: %s\n", juegos[i].con);

					juegos[i].IVA = (juegos[i].precio * 16) / 100;
					juegos[i].preciot = juegos[i].precio + juegos[i].IVA;
					printf("Precio Base: %5.2f\nIVA: %5.2f\nPrecio Total: %5.2f\n\n", juegos[i].precio, juegos[i].IVA, juegos[i].preciot);

				}
			}
			break;

		default: printf("\nNúmero invalido\n");
			break;

		}


	}

}



void baja()
{
	int j;
	printf("¿Que registro desea eliminar?: ");
	scanf_s("%d", &j);

	for (int i = j; i == j; i++)
	{

		printf("\nEliminando registro %d...\n", j);
		juegos[i].status = "ELIMINADO";


	}
}

void archivos()
{
	ofstream archivo;
	string nomarch;

	nomarch = "Videojuegos.txt";

	archivo.open(nomarch.c_str(), ios::out);

	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}

	for (int i = 1; i <= n; i++)
	{
		if (juegos[i].status == "ELIMINADO")
		{
			archivo << "REGISTRO " << i << " ELIMINADO" << endl;
		}
		else
		{
			archivo << "\n----- REGISTRO " << i << " -----" << endl;
			archivo << "# ITEM: " << juegos[i].num << endl;
			archivo << "NOMBRE: " << juegos[i].nom << endl;
			archivo << "DESCRIPCION: " << juegos[i].descrip << endl;
			archivo << "GENERO: " << juegos[i].gen << endl;
			archivo << "CLASIFICACION: " << juegos[i].clas << endl;
			archivo << "CONSOLA: " << juegos[i].con << endl;
			archivo << "PRECIO: " << juegos[i].precio << endl;
			archivo << "IVA: " << juegos[i].IVA << endl;
			archivo << "PRECIO TOTAL: " << juegos[i].preciot << endl;
		}

	}




	archivo.close();
}
