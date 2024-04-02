//
// Created by sebav on 31-03-2024.
//

#ifndef TALLER1_EVENTO_H
#define TALLER1_EVENTO_H

#include <iostream>
#include <vector>
#include "Persona.h"

using namespace std;
class Evento {

private:
    string tipo,fecha,tema,ubicacion;
    vector<Persona> personas;
public:
    Evento(string tipo, string fecha, string tema, string ubicacion);
    void registrarAsistente();
    void generarInforme();

};


#endif //TALLER1_EVENTO_H
