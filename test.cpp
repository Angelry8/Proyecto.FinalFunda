#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>

using namespace std;

// Estructura para almacenar datos de un estudiante
// Incluye nombre, apellidos, ciclo, cedula, calificaciones, promedio y estado de aprobaci√≥n
struct Estudiante {
    string primerNombre;
    string primerApellido;
    string segundoApellido;
    int ciclo;
    int cedula;
    double calificaciones[5];
    double promedio;
    bool aprobado;
    
// constructor para los datos del estudiante
    Estudiante() : ciclo(0), cedula(0), promedio(0.0), aprobado(false) {
        for(int i = 0; i < 5; i++) {
            calificaciones[i] = 0.0;
        }
    }
};

// Funcion para mostrar encabezado del sistema
void Encabezado() {
	cout << "\n";
	cout << "************************************************************\n";
	cout << "*           SISTEMA DE CALIFICACIONES ESTUDIANTILES        *\n";
	cout << "*              UNIVERSIDAD NACIONAL - SEDE Nicoya          *\n";
	cout << "************************************************************\n";
	cout << "\n";
}

// Funcion para mostrar encabezado de secciÛn de estudiantes
void EncabezadoEstudiantes(int numeroEstudiante) {
	cout << "\n";
	cout << "+--------------------------------------------------------+\n";
	cout << "*               ESTUDIANTE #" << setfill('0') << setw(2) << numeroEstudiante << "                           *\n";
	cout << "+--------------------------------------------------------+\n";
	cout << "\n";
}
return 0;

// Funcion para validar que una cadena solo contenga letras y espacios
bool soloLetrasYEspacios(const string& texto) {
	if (texto.empty()) {
		return false; // No permite espacios vacÌos
	}
	
	for (char c : texto) {
		// Permite solo letras may˙sculas, min˙sculas y espacios
		if (!isalpha(c) && c != ' ') {
			return false;
		}
	}
	
	// Verificar que no sea solo espacios
	bool tieneLetras = false;
	for (char c : texto) {
		if (isalpha(c)) {
			tieneLetras = true;
			break;
		}
	}
	
	return tieneLetras;
}

// Funcion para validar nombres (solo letras y espacios)
string validarNombre(const string& mensaje) {
	string nombre;
	while (true) {
		cout << mensaje;
		getline(cin, nombre);
		
		if (soloLetrasYEspacios(nombre)) {
			return nombre;
		} else {
			cout << " ERROR: Los nombres solo pueden contener letras y espacios.\n";
		}
	}
}

