//
// Created by jack on 23/11/20.
//

#include "Juego.h"
#include "Sokoban.h"
#include "Nivel.h"
#include "Tipos.h"

Juego::Juego(vector<Nivel*> *ns) : _niveles(ns), _idxNivelActual(0) {
    // Creo un Sokoban con el primer nivel del vector de niveles
    _sokoActual = new Sokoban(ns->operator[](0));
    // TODO: estoy copiando el contenido con tamaño? o debo usar heap memory?
    _sokobanes = vector<Sokoban *>(ns->size());
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
    if(_sokoActual->gano() && _sokoActual!=_sokobanes[_sokobanes.size()-1]){
        _idxNivelActual+=1;
        _sokoActual = new Sokoban(_niveles->operator[](_idxNivelActual));
        _sokobanes.push_back(_sokoActual);
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



