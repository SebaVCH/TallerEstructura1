//
// Created by sebav on 31-03-2024.
//

#include "Evento.h"

Evento::Evento(string tipo, string fecha, string tema, string ubicacion) {
    this -> tipo = tipo;
    this -> fecha = fecha;
    this -> tema = tema;
    this -> ubicacion = ubicacion;
}

void Evento::registrarAsistente() {

}

void Evento::generarInforme() {
    cout << "**Evento:** " << tipo << endl;
    cout << "**Fecha:** " << fecha << endl;
    cout << "**Ubicación:** " << ubicacion << endl;
    cout << "**Tema:** " << tema << endl;
    cout << "**Asistentes:**" << endl;
    //For para recorrer la informacion de los invitados/asistentes
//    for (auto asistente : asistentes) {
//        asistente->imprimirInformacion();
//    }
}
