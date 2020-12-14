//
// Created by jack on 23/11/20.
//

#include "Nivel.h"

Nivel::Nivel(Mapa m, Coordenada p, set<Coordenada> cs, Nat b) {
    _mapa = m;
    _persona = p;
    _cajas = cs;
    _bombas = b;
}

Mapa Nivel::mapaN() {
    return _mapa;
}

Coordenada Nivel::personaN() {
    return _persona;
}

set<Coordenada> Nivel::cajasN() {
    set<Coordenada> *res = new set<Coordenada>();
    for(Coordenada caja : _cajas){
        res->insert(caja);
    }
    return *res;
}

Nat Nivel::numBombasN() {
    return _bombas;
}

void Nivel::modificarCaja(Coordenada *caja, Coordenada nueva_coord) {
    caja->first = nueva_coord.first;
    caja->second = nueva_coord.second;
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

Coordenada *Nivel::buscarCaja(Coordenada coord) {
    Nat nc = _cajas.size();
    Coordenada *res = NULL;
    //auto res = _cajas.find(coord);
//    set<Coordenada>::iterator it = _cajas.begin();
//    while(it != _cajas.end()){
//        if(*it == coord){
//            res = &(*it);
//        }
//        it++;
//    }
    // TODO:
    return res;
}


