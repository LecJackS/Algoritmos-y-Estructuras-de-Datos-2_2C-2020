//
// Created by jack on 23/11/20.
//

#include "Mapa.h"
#include <algorithm>

Mapa::Mapa(){
    _setDepositos = new set<Coordenada>();
}

Mapa::Mapa(set<Coordenada> paredes, set<Coordenada> depositos){
    _setDepositos = new set<Coordenada>;
    for(Coordenada pared : paredes){
        agregarParedOrd(pared);
    }
    for(Coordenada depo : depositos){
        agregarDepositoOrd(depo);
    }
}

Mapa::~Mapa() {
    delete(_setDepositos);
}

bool Mapa::hayPared(Coordenada c) {
    bool res;
    res=busquedaBinaria("pared", c);
    for (Coordenada exp: _explosiones){
        if(exp.first == c.first || exp.second==c.second){
            // Esta pared fue explotada => Ya no existe
            res = false;
        }
    }
    return res;
}

bool Mapa::hayDeposito(Coordenada c) {
    return busquedaBinaria("deposito", c);
}

// TODO: en los métodos agregarParedOrd y agregarDepositoOrd
//  hay código repetido que podría abstraerse a un método auxiliar.
void Mapa::agregarParedOrd(Coordenada nueva_coord) {
    vector<Coordenada> nuevasParedesOrd;
    Nat pos = buscarPosicion("pared", nueva_coord);
    for(int i=0; i < 1 + _paredesOrd.size(); i++){
        if(i < pos){
            nuevasParedesOrd.push_back(_paredesOrd[i]);
        }
        else if(i == pos){
            nuevasParedesOrd.push_back(nueva_coord);
        }
        else {
            nuevasParedesOrd.push_back(_paredesOrd[i-1]);
        }
    }

    for(int i=0; i < _paredesOrd.size(); i++){
        _paredesOrd[i] = nuevasParedesOrd[i];
    }
    int last = nuevasParedesOrd.size()-1;
    _paredesOrd.push_back(nuevasParedesOrd[last]);
}

void Mapa::agregarDepositoOrd(Coordenada nueva_coord) {
    vector<Coordenada> nuevosDepositosOrd;
    Nat pos = buscarPosicion("deposito", nueva_coord);
    for(int i=0; i < 1 + _depositosOrd.size(); i++){
        if(i < pos){
            nuevosDepositosOrd.push_back(_depositosOrd[i]);
        }
        else if(i == pos){
            nuevosDepositosOrd.push_back(nueva_coord);
        }
        else {
            nuevosDepositosOrd.push_back(_depositosOrd[i-1]);
        }
    }
    for(int i=0; i < _depositosOrd.size(); i++){
        _depositosOrd[i] = nuevosDepositosOrd[i];
    }
    int last = nuevosDepositosOrd.size()-1;
    _depositosOrd.push_back(nuevosDepositosOrd[last]);
}

void Mapa::tirarBomba(Coordenada c) {
    _explosiones.push_back(c);
}

void Mapa::borrarUltimaExplosion() {
    _explosiones.pop_back();
}

// TODO: está muy bien que buscarPosicion y busquedaBinaria sean
//  métodos auxiliares para no repetir código.
//  Pero en lugar de pasarle un string que indique el tipo de objeto,
//  sería más claro hacer el chequeo en los métodos que lo llaman y
//  pasarle a este método el vector en el que se quiere buscar
//  (pasandolo por referencia).
Nat Mapa::buscarPosicion(string objeto, Coordenada nueva_coord) {
    Nat pos = 0;
    vector<Coordenada> *v;
    if(objeto == "pared"){
        v = &_paredesOrd;
    } else if (objeto == "deposito"){
        v = &_depositosOrd;
    }
    for (int i=0; i<v->size(); i++){
        Coordenada c = v->at(i);
        if (nueva_coord.first < c.first){
            pos = i;
            return pos;
        }
        else if (c.first == nueva_coord.first) {
            if (nueva_coord.second < c.second){
                pos = i;
                return pos;
            } else{

            }
        }
    }
    pos = v->size();
    return pos;
}

bool Mapa::busquedaBinaria(string objeto, Coordenada c) {
    vector<Coordenada> *v;
    if(objeto == "pared"){
        v = &_paredesOrd;
    } else if (objeto == "deposito"){
        v = &_depositosOrd;
    }
    return binary_search(v->begin(), v->end(), c);
}

set<Coordenada> Mapa::depositos() {
    if (_setDepositos != nullptr){
        _setDepositos->clear();
    }
    for(Coordenada depo : _depositosOrd){
        _setDepositos->insert(depo);
    }

    return *_setDepositos;
}









