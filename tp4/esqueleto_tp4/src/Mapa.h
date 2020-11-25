//
// Created by jack on 23/11/20.
//

#ifndef TP4_SOKOBAN_MAPA_H
#define TP4_SOKOBAN_MAPA_H

#include "Tipos.h"
#include <map>;
#include <vector>;

class Mapa {
        map<Nat, Coordenada> paredes;
        map<Nat, Coordenada> depositos;
        vector<Coordenada> explosiones;
        Nat cantidadBombas;
};


#endif //TP4_SOKOBAN_MAPA_H
