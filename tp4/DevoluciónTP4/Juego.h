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

    // TODO: en general, es más cómodo no usar punteros y memoria dinámica
    //  salvo cuando es necesario (por ejemplo, cuando hay estructuras
    //  recursivas como en los talleres). Es decir, en este caso se podría
    //  usar un vector de niveles para los niveles en lugar de un puntero
    //  a un vector de punteros. Lo mismo con el resto de las variables
    //  internas.
    vector<Nivel*> *_niveles;
    Nat _idxNivelActual;
    Sokoban *_sokoActual;
    vector<Sokoban *> _sokobanes;

};

#endif // AED2_JUEGO_H
