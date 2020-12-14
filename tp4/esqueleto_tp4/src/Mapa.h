//
// Created by jack on 23/11/20.
//

#ifndef TP4_SOKOBAN_MAPA_H
#define TP4_SOKOBAN_MAPA_H

#include "Tipos.h"
#include <map>;
#include <vector>;

class Mapa {
public:
    Mapa();
    Mapa(set<Coordenada> paredes, set<Coordenada> depositos);

    ~Mapa();

    bool hayPared(Coordenada c);
    bool hayDeposito(Coordenada c);

    void agregarParedOrd(Coordenada c);
    void agregarDepositoOrd(Coordenada c);

    void tirarBomba(Coordenada c);

    void borrarUltimaExplosion();

    set<Coordenada> depositos();

private:
    Nat buscarPosicion(string objeto, Coordenada c);
    bool busquedaBinaria(string objeto, Coordenada c);

    vector<Coordenada> _paredesOrd;
    vector<Coordenada> _depositosOrd;
    vector<Coordenada> _explosiones;
    set<Coordenada> *_setDepositos;

};


#endif //TP4_SOKOBAN_MAPA_H
