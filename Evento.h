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
    string nombre,tipo,fecha,tema,ubicacion;
    vector<Persona*> personas;
public:
    Evento(string nombre,string tipo, string fecha, string tema, string ubicacion);
    void registrarAsistente(Persona* persona);
    void generarInformeIndividual();
    void listadoAsistentes();
    string getNombreEvento();
    string getTipo();
    string getTema();
    string getFecha();
    string getUbicacion();
    int cantidadPersonas();
    ~Evento();
};


#endif //TALLER1_EVENTO_H
