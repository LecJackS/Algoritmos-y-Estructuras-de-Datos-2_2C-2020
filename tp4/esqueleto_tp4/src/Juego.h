#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Tipos.h"
#include "Sokoban.h"
#include "Nivel.h"

class Juego {
public:

    Juego(vector<Nivel*> *ns);
    ~Juego();

    Sokoban* nivelActual();
//    vector<Nivel> nivelesPendientes();
    bool mover(PuntoCardinal dir);
    void tirarBomba();
    void deshacer();


private:

    vector<Nivel*> *_niveles;
    Nat _idxNivelActual;
    Sokoban *_sokoActual;
    vector<Sokoban *> _sokobanes;

};

#endif // AED2_JUEGO_H
