//
// Created by jack on 23/11/20.
//

#ifndef TP4_SOKOBAN_SOKOBAN_H
#define TP4_SOKOBAN_SOKOBAN_H

#include <vector>
#include "Nivel.h"
#include "Tipos.h"

using namespace std;

class Sokoban {
public:
    Sokoban(Nivel* n);

    ~Sokoban();

    Mapa* mapa();
    Coordenada persona();
    bool hayCaja(Coordenada coord);
    Nat numBombas();
    void deshacer();

    void mover(PuntoCardinal dir);
    void tirarBomba();

    bool noHayParedNiCaja(Coordenada c);
    bool puedoMover(PuntoCardinal);

    bool gano();
    bool hayCajas(set<Coordenada> cs);

private:
    void deshacerMover(PuntoCardinal dir);
    Nivel *_nivel;
    vector<Nat> _accionFue;
    vector<bool> _accionMovioCaja;
    //vector<set<Coordenada>::iterator> _cajaMovida;
    vector<int> _cajaMovida;
};


#endif //TP4_SOKOBAN_SOKOBAN_H
