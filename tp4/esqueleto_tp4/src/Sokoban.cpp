//
// Created by jack on 23/11/20.
//

#include "Sokoban.h"

Sokoban::Sokoban(Nivel *n) : _nivel(n) {
}

Mapa Sokoban::mapa() {
    return _nivel->mapaN();
}

Coordenada Sokoban::persona() {
    return _nivel->personaN();
}

bool Sokoban::hayCaja(Coordenada coord) {
    bool res = false;
    for(Coordenada caja : _nivel->cajasN()){
        if (caja == coord){
            res = true;
        }
    }
    return res;
}

Nat Sokoban::numBombas() {
    return _nivel->numBombasN();
}

void Sokoban::deshacer() {
    Nat na = _accionFue.size();
    if (na > 0){
        if(_accionFue[na-1] == 0){
            // Acción fue Tirar Bomba
            // Solo borro la explosión y recupero la bomba
            _nivel->mapaN().borrarUltimaExplosion();
            _nivel->aumentarBombas();
        }
        else if (_accionFue[na-1] == 1){
            // Acción fue Mover Norte
            // Muevo Persona al Sur
            deshacerMover(Sur);
        }
        else if (_accionFue[na-1] == 2){
            // Acción fue Mover Este
            // Muevo Persona al Oeste

            deshacerMover(Oeste);
        }
        else if (_accionFue[na-1] == 3){
            // Acción fue Mover Sur
            // Muevo Persona al Norte
            deshacerMover(Norte);
        }
        else if (_accionFue[na-1] == 4){
            // Acción fue Mover Sur
            // Muevo Persona al Norte
            deshacerMover(Este);
        }
    }
}

void Sokoban::deshacerMover(PuntoCardinal dir) {
    _nivel->modificarPersona(_nivel->personaN() + dir);
    Nat nm = _accionMovioCaja.size();
    if (_accionMovioCaja[nm-1]){
        // Muevo la caja a donde estaba antes de ser movida
        _nivel->modificarCaja(_cajaMovida[_cajaMovida.size()-1], _nivel->personaN() + dir);
        // Borro registro
        _cajaMovida.pop_back();
    }
    // Borro registros de última acción ya borrada
    _accionFue.pop_back();
    _accionMovioCaja.pop_back();
}

void Sokoban::mover(PuntoCardinal dir) {
    if(hayCaja(_nivel->personaN())){
        _accionMovioCaja.push_back(true);
        _cajaMovida.push_back(_nivel->buscarCaja(_nivel->personaN()));
    }
    else{
        _accionMovioCaja.push_back(false);
    }
    _nivel->modificarPersona(_nivel->personaN() + dir);
}

void Sokoban::tirarBomba() {
    _nivel->mapaN().tirarBomba(_nivel->personaN());
    _accionFue.push_back(0);
}

bool Sokoban::noHayParedNiCaja(Coordenada coord) {
    return !_nivel->mapaN().hayPared(coord) && !hayCaja(coord);
}

bool Sokoban::puedoMover(PuntoCardinal dir) {
    bool res = false;
    Coordenada nuevaPos = _nivel->personaN() + dir;
    if(noHayParedNiCaja(nuevaPos)){
        res = true;
    }
    else{
        if(hayCaja(nuevaPos)){
            res = noHayParedNiCaja(nuevaPos + dir);
        }
    }
    return res;
}

bool Sokoban::gano() {
    return _nivel->cajasN()==_nivel->mapaN().depositos();
}

bool Sokoban::hayCajas(set<Coordenada> cs) {
    return cs == _nivel->cajasN();
}




