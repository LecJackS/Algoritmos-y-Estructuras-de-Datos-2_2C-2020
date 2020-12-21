//
// Created by jack on 23/11/20.
//

#ifndef TP4_SOKOBAN_MAPA_H
#define TP4_SOKOBAN_MAPA_H

#include "Tipos.h"
#include <map>; // TODO: después de los includes no va punto y coma
#include <vector>;

class Mapa {
public:
    Mapa();
    Mapa(set<Coordenada> paredes, set<Coordenada> depositos);

    ~Mapa();

    // TODO: los métodos que no modifican la estructura interna
    //  deberían ser const.
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
    // TODO: no es necesario tener guardado el set de depósitos,
    //  ya que se crea cada vez que se llama al método depositos
    //  y se lo devuelve por copia.
    //  Además, en vez de guardar un puntero a un set, podrías
    //  guardar directamente un set.
};


#endif //TP4_SOKOBAN_MAPA_H
