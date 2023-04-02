#include <iostream>

using namespace std;

int main()
{
	int opc, num, sn;
	char desc[100], gen[30], clas[30], con[20];
	float precio = 0;

	cout << "\t MENU DE OPCIONES \n 1.-Alta \n 2.-Modificacion \n 3.-Baja \n 4.-Lista \n 5.-Limpiar pantalla \n 6.-Salir \n";
	cin >> opc;

	switch (opc)
	{
	case 1:cout << "Numero de item: ";
		cin >> num;
		cout << "Descripcion: ";
		cin >> desc;
		cout << "Genero: ";
		cin >> gen;
		cout << "Clasificacion: ";
		cin >> clas;
		cout << "Consola: ";
		cin >> con;
		cout << "Precio: ";
		cin >> precio;
		precio = precio - (precio * 60) / 100;
		cout << "Desea ingresar otro articulo?\n1.-Si\t2.-No\n";
		cin >> sn;
		if (sn == 1)
		{
			return main();
		}
		else
		{
			return main();
		}

		break;

	case 2:break;

	case 3:break;

	case 4:break;

	case 5: system("cls");
		return main();
		break;

	case 6: exit(1);
		break;

	default: cout << "\n Numero invalido";
		return main();

	}

}