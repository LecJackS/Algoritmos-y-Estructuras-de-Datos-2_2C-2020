#include "Tipos.h"
#include "Mapa.h"


#ifndef TP4_SOKOBAN_NIVEL_H
#define TP4_SOKOBAN_NIVEL_H



class Nivel {
    Mapa mapa;
    Coordenada posicionInicial;
    Nat cantidadBombas;
    set<Coordenada> cajas;

};



#endif //TP4_SOKOBAN_NIVEL_H
