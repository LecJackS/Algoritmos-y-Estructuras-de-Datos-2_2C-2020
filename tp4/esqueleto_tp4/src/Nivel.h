#include "Tipos.h"
#include "Mapa.h"


#ifndef TP4_SOKOBAN_NIVEL_H
#define TP4_SOKOBAN_NIVEL_H



class Nivel {
public:
    Nivel(Mapa m, Coordenada p, set<Coordenada> cs, Nat b);

    Mapa mapaN();
    Coordenada personaN();
    set<Coordenada> cajasN();
    Nat numBombasN();

    void modificarCaja(Coordenada *caja, Coordenada nueva_coord);
    void modificarPersona(Coordenada coord);
    void reducirBombas();
    void aumentarBombas();

    Coordenada * buscarCaja(Coordenada coord);

private:
    Mapa _mapa;
    Coordenada _persona;
    set<Coordenada> _cajas;
    Nat _bombas;

};



#endif //TP4_SOKOBAN_NIVEL_H
