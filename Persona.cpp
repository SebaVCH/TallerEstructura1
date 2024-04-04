//
// Created by sebav on 31-03-2024.
//

#include "Persona.h"

Persona::Persona(string nombre, string password, string rut, int edad, string tipo, string ocupacion, string eventoAsignado) {
    this -> nombre = nombre;
    this -> password = password;
    this -> rut = rut;
    this -> edad = edad;
    this -> tipo = tipo;
    this -> ocupacion = ocupacion;
    this -> eventoAsignado = eventoAsignado;
}

void Persona::imprimirInformacion() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " años" << endl;
    cout << "Evento asignado: " << eventoAsignado << endl;
    cout << "Ocupación: " << ocupacion << endl;
    cout << "Tipo: " << tipo << endl;

}


string Persona::getNombre() {
    return nombre;
}

string Persona::getRut() {
    return rut;
}

int Persona::getEdad() {
    return edad;
}

string Persona::getTipo() {
    return tipo;
}

string Persona::getOcupacion() {
    return ocupacion;
}

string Persona::getPass() {
    return password;
}

string Persona::getEvento() {
    return eventoAsignado;
}

void Persona::setEvento(string evento) {
    this -> eventoAsignado = evento;
}

Persona::~Persona() {
    cout << "Se borro la persona" << endl;
}

