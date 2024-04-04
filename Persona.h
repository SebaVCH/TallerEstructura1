//
// Created by sebav on 31-03-2024.
//

#ifndef TALLER1_PERSONA_H
#define TALLER1_PERSONA_H

#include <iostream>
using namespace std;
class Persona {
private:
    string nombre,tipo,ocupacion,rut, password,eventoAsignado;
    int edad;
public:
    Persona(string nombre, string password,string rut ,int edad,string tipo, string ocupacion, string eventoAsignado);
    string getNombre();
    string getPass();
    string getRut();
    int getEdad();
    string getTipo();
    string getOcupacion();
    string getEvento();
    void setEvento(string evento);

    ~Persona();

};


#endif //TALLER1_PERSONA_H
