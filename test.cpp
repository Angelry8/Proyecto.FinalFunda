#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>

using namespace std;

// Estructura para almacenar datos de un estudiante
// Incluye nombre, apellidos, ciclo, cedula, calificaciones, promedio y estado de aprobación
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

// Funcion para mostrar encabezado de secci�n de estudiantes
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
		return false; // No permite espacios vac�os
	}
	
	for (char c : texto) {
		// Permite solo letras may�sculas, min�sculas y espacios
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

// Funcion para validar numeros positivos
int validarNumerosPositivos(const string& mensaje) {
	int valor;
	while (true) {
		cout << mensaje;
		if (cin >> valor && valor > 0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return valor;
		} else {
			cout << " ERROR: Debe ingresar un n�mero entero positivo.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

// Funcion para validar calificaciones (0.0 - 100.0)
double validarCalificacion(const string& mensaje) {
	double calificacion;
	while (true) {
		cout << mensaje;
		if (cin >> calificacion && calificacion >= 0.0 && calificacion <= 100.0) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return calificacion;
		} else {
			cout << " ERROR: La calificaci�n debe estar entre 0.0 y 100.0\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

//Funcion para capturar datos de un estudiante
void DatosEstudiantes (estudiantes& estudiante, int numeroEstudiante){
	EncabezadoEstudiantes (numeroEstudiante);

	//capturar datos personales 
	cout << "DATOS PERSONALES:\n";
	cout << "-------------------\n";

	estudiante.primerNombre = validarNombre("ingrese primer nombre: ");
	estudiante.primerApellido = validarNombre("ingrese primer apellido: ");
	estudiante.segundoApellido = validarNombre("ingrese segundo apellido: ");
	estudiante.cedula = validarNumerosPositivos("ingrese numero de cedula: ");

	//Capturar calificaciones 
	cout << "\n CALIFICACIONES:\n";
	cout << "--------------------\n";

	for (int = 0; i <5; i++){
		string mensaje = "ingrese nota del examen #" + to_stringi(i + 1) + ": ";
		estudiantes.calificaciones[i] = validarCalificacion (mensaje);
	}

	//Calcular promedio
	double suma = 0.0;
	for (int i = 0; i < 5; i++){
		suma += estudiante.calificaciones[i];
	}
	estudiante.promedio = suma / 5.0;

	//Ver si esta aprobado
	estudiante.aprobado = (estudiante.promedio >= 70.0);
	cout << "\n Datos cappturados correctamente. \n";
	cout << "promedio calculado:"<< fixed << setprecision(2) << estudiante.promedio << "\n";
	cout << "estado: "<< (estudiante.aprobado ? "APROBADO": "REPROBADO") << "\n";
}

// Función para mostrar reporte de aprobados
void ReporteAprobados(const vector<Estudiante>& estudiantes) {
    cout << "\n";
    cout << "==================== APROBADOS ====================\n";
    cout << "Nombre completo           Ciclo   Cedula     Promedio\n";
    cout << "--------------------------------------------------------------\n";
    
    bool hayAprobados = false;
    for (const auto& estudiante : estudiantes) {
        if (estudiante.aprobado) {
            hayAprobados = true;
            string nombreCompleto = estudiante.primerNombre + " " + 
                                  estudiante.primerApellido + " " + 
                                  estudiante.segundoApellido;
            cout << "> " << nombreCompleto 
                 << " (" << estudiante.ciclo << ") " 
                 << estudiante.cedula << " " 
                 << fixed << setprecision(2) << estudiante.promedio << endl;
        }
    }
    
    if (!hayAprobados) {
        cout << "No hay estudiantes aprobados en este periodo.\n";
    }
}

// Función para mostrar a los reprobados
void ReporteReprobados(const vector<Estudiante>& estudiantes) {
    cout << "\n";
    cout << "==================== REPROBADOS ====================\n";
    cout << "Nombre completo           Ciclo   Cedula     Promedio\n";
    cout << "----------------------------------------------------\n";
    
    bool hayReprobados = false;
    for (const auto& estudiante : estudiantes) {
        if (!estudiante.aprobado) {
            hayReprobados = true;
            string nombreCompleto = estudiante.primerNombre + " " + 
                                  estudiante.primerApellido + " " + 
                                  estudiante.segundoApellido;
            cout << "> " << nombreCompleto 
                 << " (" << estudiante.ciclo << ") " 
                 << estudiante.cedula << " " 
                 << fixed << setprecision(2) << estudiante.promedio << endl;
        }
    }
    
    if (!hayReprobados) {
        cout << "¡Felicidades! No hay estudiantes reprobados en este periodo.\n";
    }
}