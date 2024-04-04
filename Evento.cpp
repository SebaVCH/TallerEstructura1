//
// Created by sebav on 31-03-2024.
//
#include <iostream>
#include "Evento.h"

Evento::Evento(string nombre, string tipo, string fecha, string tema, string ubicacion) {

    this -> nombre = nombre;
    this -> tipo = tipo;
    this -> fecha = fecha;
    this -> tema = tema;
    this -> ubicacion = ubicacion;
    this -> personas = vector<Persona*>();
}

void Evento::registrarAsistente(Persona* persona) {

    if(persona->getEvento() == nombre){
        personas.push_back(persona);
    } else {
        cout << "Evento no encontrado..." << endl;
    }

}

void Evento::generarInformeIndividual() {
    cout << "Nombre: " << nombre << endl;
    cout << "Evento: " << tipo << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Ubicacion: " << ubicacion << endl;
    cout << "Tema: " << tema << endl;
    cout << "Asistentes: " << cantidadPersonas() << endl;
}

string Evento::getNombreEvento() {
    return nombre;
}

string Evento::getTipo() {
    return tipo;
}

int Evento::cantidadPersonas() {
    int cant = 0;
    for(Persona *persona: personas){
        cant++;
    }
    return cant;
}

void Evento::listadoAsistentes() {

    for(Persona *persona: personas){
        cout << persona->getNombre() << endl;
    }

}

Evento::~Evento() {
    cout << "Se borro el evento" << endl;
}

vector<Persona*> Evento::getListaPersonas(){
    return personas;
}

string Evento::getTema() {
    return tema;
}

string Evento::getFecha() {
    return fecha;
}

string Evento::getUbicacion() {
    return ubicacion;
}
