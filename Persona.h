//
// Created by sebav on 31-03-2024.
//

#ifndef TALLER1_PERSONA_H
#define TALLER1_PERSONA_H

#include <iostream>
using namespace std;
class Persona {
private:
    string nombre,tipo,ocupacion,rut, password;
    int edad;
public:
    Persona(string nombre, string password,string rut ,int edad,string tipo, string ocupacion);
    void imprimirInformacion();
    string getNombre();
    string getPass();
    string getRut();
    int getEdad();
    string getTipo();
    string getOcupacion();

};


#endif //TALLER1_PERSONA_H
