#include <iostream>
#include <fstream>
#include <unistd.h>
#include <algorithm>
#include <sstream>
#include "Persona.h"
#include "Evento.h"

using namespace std;

//Menus
void menuGeneral();
void menuAdmin();
void mostrarEventos();

//Lectura y escritura de archivos;
void cargarArchivos(vector<Persona> &Personas,vector<Evento> &Eventos);
void sobreEscritura();

//Otros
bool inicioSesion(vector<Persona> &Personas);


int main() {

    menuGeneral();
    return 0;
}


//Codigos de las funciones
void menuGeneral(){
    vector<Persona> PersonasTotales;
    vector<Evento> EventosTotales;
    cargarArchivos(PersonasTotales,EventosTotales);
    mostrarEventos();
    cout << "Deseas acceder al menu de administrador? (S/N)" << endl;
    string opcion;
    cin >> opcion;
    transform(opcion.begin(), opcion.end(), opcion.begin(), ::tolower);
    if (opcion == "S" ){
        bool inicio = inicioSesion(PersonasTotales);
        if (inicio == true){
            menuAdmin();
        } else {
            cout << "Acceso denegado... " << endl;
        }


    } else {
        while (opcion != "S"){
            cout << "Deseas volver a ver los eventos? (S/N)" << endl;
            cin >> opcion;
            if(opcion == "S"){
                mostrarEventos();
            } else {
                cout << "Terminando el programa" << endl;
                break;
            }

        }

    }

}

void mostrarEventos() {

    cout << "Hola" << endl;

}

void menuAdmin(){

    int opcion = -1;

    while (opcion != 0){
        cout << "--------MENU--------" << endl;
        cout << "1. Crear evento" << endl;
        cout << "2. Registrar asistente" << endl;
        cout << "3. Consultar lista de asistentes" << endl;
        cout << "4. Generar informes" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                //Metodo de crear evento...
                break;
            case 2:
                //Metodo de Registrar asistente...
                break;
            case 3:
                //Metodo de consultar lista de asistentes
                break;
            case 4:
                //Generar informes
                break;
            case 0:
                cout << "Saliendo... " << endl;
                break;
        }
    }

}

void cargarArchivos(vector<Persona>  &Personas, vector<Evento> &Eventos) {
    ifstream archivoPersonas("personas.txt");

    if (archivoPersonas.is_open()) {
        string linea;
        while (getline(archivoPersonas, linea)) {
            stringstream ss(linea);
            string nombre, password, rut, tipo, ocupacion;
            int edad;

            getline(ss, nombre, ',');
            getline(ss, password, ',');
            getline(ss, rut, ',');
            ss >> edad; ss.ignore();
            getline(ss, tipo, ',');
            getline(ss, ocupacion, ',');

            Personas.push_back({nombre, password, rut, edad, tipo, ocupacion});
        }
        archivoPersonas.close();
    } else {
        cout << "Error al abrir el archivo de personas" << endl;
    }
}


void sobreEscritura(){

}

bool inicioSesion(vector<Persona> &Personas){

    string nombreUsuario;
    string password;

    cout << "Ingrese el nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese la contraseña: ";
    cin >> password;

    for(Persona personita: Personas){
        if (nombreUsuario == personita.getNombre() && password == personita.getPass()){
            return true;
        }
    }

    cout << "Usuario no encontrado..." << endl;

    return false;

}


