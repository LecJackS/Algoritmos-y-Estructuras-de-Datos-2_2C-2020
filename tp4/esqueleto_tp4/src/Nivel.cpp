//
// Created by jack on 23/11/20.
//

#include "Nivel.h"

Nivel::Nivel(Mapa *m, Coordenada p, set<Coordenada> cs, Nat b){
    _mapa = m;
    _persona = p;
    _bombas = b;
    for(Coordenada caja : cs){
        _cajas.push_back(caja);
    }
    _setCajas = new set<Coordenada>();
}

Nivel::~Nivel() {
//    if (_setCajas != nullptr){
//        delete(_setCajas);
//    }
    delete(_setCajas);
    delete(_mapa);
}

Mapa* Nivel::mapaN() {
    return _mapa;
}

Coordenada Nivel::personaN() {
    return _persona;
}

set<Coordenada>* Nivel::cajasN() {
    if (_setCajas != nullptr){
        _setCajas->clear();
    }
    for(Coordenada caja : _cajas){
        _setCajas->insert(caja);
    }
    return _setCajas;
}

Nat Nivel::numBombasN() {
    return _bombas;
}

void Nivel::modificarCaja(int idCaja, Coordenada nueva_coord) {
    //_cajas.erase(itCaja);
    //_cajas.insert(itCaja, nueva_coord);
    _cajas[idCaja] = nueva_coord;
}

void Nivel::modificarPersona(Coordenada coord) {
    _persona = coord;
}

void Nivel::reducirBombas() {
    if (_bombas > 0){
        _bombas -= 1;
    }

}

void Nivel::aumentarBombas() {
    _bombas += 1;
}

int Nivel::buscarCaja(Coordenada coord) {
    // Iterador a elemento del set
    int id = 0;
    while(id < _cajas.size() && _cajas[id]!=coord){
        id++;
    }
    return id;
}




