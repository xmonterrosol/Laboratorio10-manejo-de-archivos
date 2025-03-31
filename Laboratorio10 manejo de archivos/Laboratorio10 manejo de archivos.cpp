#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class MiembroClub {
private:
	string nombre;
	int edad;
	string correo;
public:
	MiembroClub(string n, int e, string c) {
		nombre = n;
		edad = e;
		correo = c;
	}
	void guardarEnArchivo() {
		ofstream archivo("club.txt", ios::app);
		if (archivo.is_open()) {
			archivo << nombre << " " << edad << " " << correo << endl;
			archivo.close();
			cout << "Datos guardados exitosamente.\n";
		}
		else {
			cout << "Error al abrir el archivo.\n";
		}
	}
	static void leerDesdeArchivo() {
		ifstream archivo("club.txt");
		string n, c;
		int e;
		if (archivo.is_open()) {
			cout << "\nLista de Miembros:\n";
			while (archivo >> n >> e >> c) {
				cout << "Nombre: " << n << ", Edad: " << e << ", Correo: " << c << endl;
			}
			archivo.close();
		}
		else {
			cout << "Error al abrir el archivo o el archivo no existe.\n";
		}
	}
	static void actualizarMiembro(string nombreBuscar, int nuevaEdad, string nuevoCorreo) {
		ifstream archivo("club.txt");
		ofstream archivoTemp("temp.txt");
		string n, c;
		int e;
		bool encontrado = false;
		if (archivo.is_open() && archivoTemp.is_open()) {
			while (archivo >> n >> e >> c) {
				if (n == nombreBuscar) {
					archivoTemp << n << " " << nuevaEdad << " " << nuevoCorreo << endl;
					encontrado = true;
				}
				else {
					archivoTemp << n << " " << e << " " << c << endl;
				}
			}
			archivo.close();
			archivoTemp.close();
			remove("club.txt");
			rename("temp.txt", "club.txt");
			if (encontrado) {
				cout << "Miembro actualizado exitosamente.\n";
			}
			else {
				cout << "Miembro no encontrado.\n";
			}
		}
		else {
			cout << "Error al abrir el archivo.\n";
		}
	}
	static void eliminarMiembro(string nombreBuscar) {
		ifstream archivo("club.txt");
		ofstream archivoTemp("temp.txt");
		string n, c;
		int e;
		bool eliminado = false;
		if (archivo.is_open() && archivoTemp.is_open()) {
			while (archivo >> n >> e >> c) {
				if (n == nombreBuscar) {
					eliminado = true;
				}
				else {
					archivoTemp << n << " " << e << " " << c << endl;
				}
			}
			archivo.close();
			archivoTemp.close();
			remove("club.txt");
			rename("temp.txt", "club.txt");
			if (eliminado) {
				cout << "Miembro eliminado exitosamente.\n";
			}
			else {
				cout << "Miembro no encontrado.\n";
			}
		}
		else {
			cout << "Error al abrir el archivo.\n";
		}
	}
};
int main() {
	int opcion;
	do {
		cout << "\n--- Menu del Club ---\n";
		cout << "1. Agregar nuevo miembro\n";
		cout << "2. Mostrar miembros\n";
		cout << "3. Actualizar miembro\n";
		cout << "4. Eliminar miembro\n";
		cout << "5. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		if (opcion == 1) {
			string nombre, correo;
			int edad;
			cout << "Ingrese nombre: ";
			cin >> nombre;
			cout << "Ingrese edad: ";
			cin >> edad;
			cout << "Ingrese correo: ";
			cin >> correo;
			MiembroClub nuevo(nombre, edad, correo);
			nuevo.guardarEnArchivo();
		}
		else if (opcion == 2) {
			MiembroClub::leerDesdeArchivo();
		}
		else if (opcion == 3) {
			string nombre;
			int edad;
			string correo;
			cout << "Ingrese nombre del miembro a actualizar: ";
			cin >> nombre;
			cout << "Ingrese nueva edad: ";
			cin >> edad;
			cout << "Ingrese nuevo correo: ";
			cin >> correo;
			MiembroClub::actualizarMiembro(nombre, edad, correo);
		}
		else if (opcion == 4) {
			string nombre;
			cout << "Ingrese nombre del miembro a eliminar: ";
			cin >> nombre;
			MiembroClub::eliminarMiembro(nombre);
		}
		else if (opcion == 5) {
			cout << "Saliendo...\n";
		}
		else {
			cout << "Opcion invalida. Intente de nuevo.\n";
		}
	} while (opcion != 5);
	return 0;
}
