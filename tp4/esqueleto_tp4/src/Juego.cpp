//
// Created by jack on 23/11/20.
//

#include "Juego.h"
#include "Sokoban.h"
#include "Nivel.h"
#include "Tipos.h"

Juego::Juego(vector<Nivel*> *ns) : _niveles(ns), _idxNivelActual(0) {
    // Creo un Sokoban con el primer nivel del vector de niveles

    _sokobanes = vector<Sokoban *>(ns->size());
    _sokoActual = new Sokoban(ns->operator[](0));
    _sokobanes[0] = _sokoActual;
}

Juego::~Juego() {
    for(Sokoban * s : _sokobanes){
        delete(s);
    }
}

Sokoban *Juego::nivelActual() {
    return _sokoActual;
}

//vector<Nivel> Juego::nivelesPendientes() {
//    return subsV(&_niveles, _idxNivelActual, _niveles->size());
//}

bool Juego::mover(PuntoCardinal dir) {
    _sokoActual->mover(dir);
    if(_sokoActual->gano() && _idxNivelActual!=(_sokobanes.size()-1)){
        _idxNivelActual+=1;
        _sokoActual = new Sokoban(_niveles->operator[](_idxNivelActual));
        _sokobanes[_idxNivelActual] = _sokoActual;
        return true;
    }
    return false;
}

void Juego::tirarBomba() {
    _sokoActual->tirarBomba();
}

void Juego::deshacer() {
    _sokoActual->deshacer();
}



