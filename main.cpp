#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "Persona.h"
#include "Evento.h"

using namespace std;

//Menus
void menuGeneral();
void menuAdmin(vector<Persona*> &Personas,vector<Evento*> &Eventos);

//Lectura y escritura de archivos;
void cargarArchivos(vector<Persona*> &Personas,vector<Evento*> &Eventos);
void sobreEscritura(vector<Persona*> &Personas,vector<Evento*> &Eventos);

//Otros
bool inicioSesion(vector<Persona*> Personas);
void mostrarEventos(vector<Evento*> Eventos);

//Menu admin
void crearEvento(vector<Evento*> &Eventos);
void registrarAsistentes(vector<Persona*> Personas,vector<Evento*> Eventos);
void consultarAsistentes(vector<Evento*> Eventos);
void generarInformesTotales(vector<Evento*> Eventos);

int main() {

    menuGeneral();

    return 0;
}


//Codigos de las funciones
void menuGeneral(){
    vector<Persona*> PersonasTotales;
    vector<Evento*> EventosTotales;
    cargarArchivos(PersonasTotales,EventosTotales);
    mostrarEventos(EventosTotales);

    cout << "Deseas acceder al menu de administrador? (S/N)" << endl;
    string opcion;
    cin >> opcion;
    transform(opcion.begin(), opcion.end(), opcion.begin(), ::toupper);
    if (opcion == "S" ){
        bool inicio = inicioSesion(PersonasTotales);
        if (inicio == true){
            menuAdmin(PersonasTotales,EventosTotales);
            sobreEscritura(PersonasTotales,EventosTotales);
        } else {
            cout << "Acceso denegado... " << endl;
        }

    } else {
        while (opcion != "S"){
            cout << "Deseas volver a ver los eventos? (S/N)" << endl;
            cin >> opcion;
            if(opcion == "S"){
                mostrarEventos(EventosTotales);
            } else {
                cout << "Terminando el programa" << endl;
                break;
            }

        }

    }

}

void mostrarEventos(vector<Evento*> Eventos) {

    cout << "**Listado de eventos**"<< endl;

    for(Evento *evento: Eventos){
        if(evento != nullptr){
            evento->generarInformeIndividual();
        }
        cout << endl;
    }

}

void menuAdmin(vector<Persona*> &Personas, vector<Evento*> &Eventos){

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
                crearEvento(Eventos);
                break;
            case 2:
                registrarAsistentes(Personas,Eventos);
                break;
            case 3:
                consultarAsistentes(Eventos);
                break;
            case 4:
                generarInformesTotales(Eventos);
                break;
            case 0:
                cout << "Saliendo... " << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    }
}

void generarInformesTotales(vector<Evento*> Eventos) {

    int cantidadEventosTotales = Eventos.size();
    int asistentesTotales = 0;
    int edad = 0;

    for(Evento *evento: Eventos){
        asistentesTotales += evento->cantidadPersonas();
        for (Persona *persona: evento->getListaPersonas()){
            edad += persona->getEdad();
        }
    }

    cout << "Total de eventos: " << cantidadEventosTotales<< endl;
    cout << "Total asistentes: " << asistentesTotales<< endl;
    cout << "Edad promedio de todos los eventos: " << edad/asistentesTotales << endl;

    cout << "**Lista de asistentes por cada evento**" << endl;
    for(Evento *evento: Eventos){
        cout << "Nombre del evento: " << evento->getNombreEvento() << endl;
        cout << "Numero de asistentes totales: " << evento->cantidadPersonas() << endl;
        evento->listadoAsistentes();
        cout << endl;
    }

}

void consultarAsistentes(vector<Evento*> Eventos) {

    cout << "**Listado de eventos**" << endl;
    for (Evento *evento: Eventos) {
        cout << "Nombre del evento: " << evento->getNombreEvento() << " Tipo del evento: " << evento->getTipo() << endl;
    }

    cout << endl;

    string eventoSeleccionado;
    cout << "Indique el nombre del evento al que desea ver la lista de asistentes: " << endl;
    cin.ignore();
    getline(cin, eventoSeleccionado);

    for (Evento *evento : Eventos) {
        if (evento->getNombreEvento() == eventoSeleccionado) {
            evento->listadoAsistentes();
        }
    }
}

void cargarArchivos(vector<Persona*>& Personas, vector<Evento*>& Eventos) {
    ifstream archivoPersonas("personas.txt");

    if (archivoPersonas.is_open()) {
        string linea;
        while (getline(archivoPersonas, linea)) {
            stringstream ss(linea);
            string nombre, password, rut, tipo, ocupacion, evento;
            int edad;

            getline(ss, nombre, ',');
            getline(ss, password, ',');
            getline(ss, rut, ',');
            ss >> edad; ss.ignore();
            getline(ss, tipo, ',');
            getline(ss, ocupacion, ',');
            getline(ss, evento, ',');

            Personas.push_back(new Persona(nombre, password, rut, edad, tipo, ocupacion, evento));
        }
        archivoPersonas.close();
    } else {
        cout << "Error al abrir el archivo de personas" << endl;
    }

    ifstream archivoEventos("eventos.txt");

    if (archivoEventos.is_open()) {
        string linea;
        while (getline(archivoEventos, linea)) {
            stringstream ss(linea);
            string nombre, tipo, fecha, tema, ubicacion;

            getline(ss, nombre, ',');
            getline(ss, tipo, ',');
            getline(ss, fecha, ',');
            getline(ss, tema, ',');
            getline(ss, ubicacion, ',');

            Eventos.push_back(new Evento(nombre, tipo, fecha, tema, ubicacion));
        }
        archivoEventos.close();
    } else {
        cout << "Error al abrir el archivo de eventos" << endl;
    }

    for(Evento *evento: Eventos) {
        for(Persona *persona: Personas){
            if(evento->getNombreEvento() == persona->getEvento()){
                evento->registrarAsistente(persona);
            }
        }
    }

}

bool inicioSesion(vector<Persona*> Personas){

    string nombreUsuario;
    string password;

    cout << "Ingrese el nombre de usuario: ";
    cin >> nombreUsuario;
    cout << "Ingrese la contraseña: ";
    cin >> password;

    for(Persona *personita: Personas){
        if (nombreUsuario == personita->getNombre() && password == personita->getPass()){
            cout << "usuario encontrado" <<endl;
            if(personita->getTipo() == "admin") {
                return true;
            }
        }
    }

    cout << "Usuario no encontrado o no es administrador" << endl;

    return false;

}

void crearEvento(vector<Evento*> &Eventos) {

    string nombre,tipo,fecha,tema,ubicacion;
    cout << "Indique el nombre del evento" << endl;
    cin >> nombre;
    cout << "Indique el tipo del evento" << endl;
    cin >> tipo;
    cout << "Indique la fecha del evento (Dia-Mes-Año)" << endl;
    cin >> fecha;
    cout << "Indique el tema del evento" << endl;
    cin >> tema;
    cout << "Indique la ubicacion" << endl;
    cin >> ubicacion;

    Evento* nuevoEvento = new Evento(nombre,tipo,fecha,tema,ubicacion);

    Eventos.push_back(nuevoEvento);

    cout << "Se agrego correctamente" << endl;

}

void registrarAsistentes(vector<Persona*> Personas,vector<Evento*> Eventos){

    string nombrePersona,nombreEvento;
    cout << "**Listado de personas**" << endl;
    for(Persona *persona: Personas) {
        cout << "Nombre: " << persona->getNombre() << " Evento actual: " << persona->getEvento() << endl;
    }

    cout << "Indique el nombre de la persona que desea agregar: " << endl;
    cin >> nombrePersona;

    cout << "**Listado de eventos**" << endl;
    for (Evento *evento: Eventos) {
        cout << "Nombre del evento: " << evento->getNombreEvento() << " Tipo del evento: " << evento->getTipo() << endl;
    }

    cout << "Indique el nombre del evento al que desea asignar la persona: " << endl;
    cin.ignore();
    getline(cin,nombreEvento);

    for(Evento *evento: Eventos) {
        for(Persona *persona: Personas){
            if(nombreEvento == evento->getNombreEvento() && persona->getNombre() == nombrePersona){
                persona->setEvento(nombreEvento);
                evento->registrarAsistente(persona);
            }
        }
    }

}

void sobreEscritura(vector<Persona*> &Personas, vector<Evento*> &Eventos){

    ofstream archivoPersonas("personas.txt");
    ofstream archivoEventos("eventos.txt");


    for (Persona* persona : Personas) {
        archivoPersonas << persona->getNombre() << "," << persona->getPass() << "," << persona->getRut() << ","
                        << persona->getEdad() << "," << persona->getTipo() << "," << persona->getOcupacion() << ","
                        << persona->getEvento() << endl;
    }


    for (Evento* evento : Eventos) {
        archivoEventos << evento->getNombreEvento() << "," << evento->getTipo() << "," << evento->getFecha() << ","
                       << evento->getTema() << "," << evento->getUbicacion() << endl;
    }

    archivoPersonas.close();
    archivoEventos.close();

    for(Persona *persona: Personas){
        delete persona;
    }
    for(Evento *evento: Eventos){
        delete evento;
    }

}


