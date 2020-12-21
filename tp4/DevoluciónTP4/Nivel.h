#include "Tipos.h"
#include "Mapa.h"


#ifndef TP4_SOKOBAN_NIVEL_H
#define TP4_SOKOBAN_NIVEL_H



class Nivel {
public:
    Nivel(Mapa *m, Coordenada p, set<Coordenada> cs, Nat b);
    ~Nivel();

    Mapa* mapaN();
    Coordenada personaN();
    set<Coordenada>* cajasN();
    Nat numBombasN();

    void modificarCaja(int idCaja, Coordenada nueva_coord);
    void modificarPersona(Coordenada coord);
    void reducirBombas();
    void aumentarBombas();

    int buscarCaja(Coordenada coord);

private:
    // TODO: En vez de tener como variable interna un puntero a Mapa,
    //  podrías tener directamente un Mapa, para no tener que hacer
    //  news y deletes.
    Mapa *_mapa;
    Coordenada _persona;
    vector<Coordenada> _cajas;
    Nat _bombas;
    set<Coordenada> *_setCajas;
    // TODO: Con el set de Cajas pasa lo mismo que con el set de
    //  depósitos en la clase Mapa.
};



#endif //TP4_SOKOBAN_NIVEL_H
