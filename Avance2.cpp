#include <iostream>
#include <math.h> 
#include <conio.h> 
#include <stdio.h>
#include <string.h>
#include <string>
#include <wchar.h>
using namespace std;

struct productos
{
	int num, sn, n;
	char gen[50], clas[50], con[50], nom[50];
	string descrip;
	float precio = 0;
};

int main()
{
	struct productos info[3];
	int opc;

	do {
		printf("\t MENU DE OPCIONES \n 1.-Alta \n 2.-Modificacion \n 3.-Baja \n 4.-Lista \n 5.-Limpiar pantalla \n 6.-Salir \n\n");
		scanf_s("%d", &opc);

		switch (opc)
		{
		case 1:
			for (int i = 0; i < 3; i++)
			{
				cin.ignore();
				printf("\nNombre del juego: ");
				gets_s(info[i].nom);

				printf("\nNumero de item: ");
				scanf_s("%d", &info[i].num);

				cin.ignore();
				printf("\nDescripcion: ");
				getline(cin, info[i].descrip);

				printf("\nGenero: ");
				gets_s(info[i].gen);

				printf("\nClasificacion: ");
				gets_s(info[i].clas);

				printf("\nConsola: ");
				gets_s(info[i].con);

				printf("\nPrecio: ");
				scanf_s("%f", &info[i].precio);

				info[i].precio = info[i].precio + (info[i].precio * 16) / 100;

			}
			break;

		case 2:break;

		case 3:break;

		case 4: //LISTA DE ARTICULOS
			for (int i = 0; i < 3; i++)
			{
				printf("Nombre: %s\n", info[i].nom);
				printf("# Item: %d\n", info[i].num);
				printf("Descripción: %s\n", info[i].descrip.c_str());
				printf("Genero: %s\n", info[i].gen);
				printf("Clasificacion: %s\n", info[i].clas);
				printf("Consola: %s\n", info[i].con);
				printf("Precio: %5.2f\n\n", info[i].precio);

			}


			break;

		case 5: system("cls");
			return main();
			break;

		case 6: exit(1);
			break;

		default: cout << "\n Numero invalido";
			return main();

		}
	} while (opc != 6);

}