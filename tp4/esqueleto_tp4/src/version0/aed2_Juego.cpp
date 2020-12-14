#include "aed2_Juego.h"

aed2_Juego::aed2_Juego(vector<aed2_Nivel> ns) {
    _niveles = ns;
    _nivelActual = 0;
    iniciar_Nivel(ns.front());
}

void aed2_Juego::iniciar_Nivel(aed2_Nivel n){
    _posicionActual = n.posicionInicial;
    _cantidadBombas = n.cantidadBombas;
    _posicionActual = n.posicionInicial;
    _cantidadBombas = n.cantidadBombas;
    _accionFue = vector<PuntoCardinal>();
    _accionMovioCaja = vector<bool>();
    _coordDeBomba = vector<Coordenada>();
    _explosiones = set<Coordenada>();
}

bool aed2_Juego::hayPared(Coordenada c) const {
    aed2_Nivel nivel = _niveles[_nivelActual];
    bool res;
    if(nivel.paredes.count(c) > 0){
        res = true;
        for (Coordenada exp : _explosiones){
            if (exp.first==c.first || exp.second==c.second){
                // Esta pared ya ha explotado
                res = false;
            }
        }
    }
    else{
        res = false;
    }
    return res;
}

bool aed2_Juego::hayDeposito(Coordenada c) const {
    aed2_Nivel nivel = _niveles[_nivelActual];
    bool res;
    if(nivel.depositos.count(c) > 0){
        res = true;
    }
    else{
        res = false;
    }
    return res;
}

bool aed2_Juego::hayCaja(Coordenada c) const {
    aed2_Nivel nivel = _niveles[_nivelActual];
    bool res;
    if(nivel.cajas.count(c) > 0){
        res = true;
    }
    else{
        res = false;
    }
    return res;
}

Coordenada aed2_Juego::posicionActual() const {
    return _posicionActual;
}

Nat aed2_Juego::cantidadBombas() const {
    return _cantidadBombas;
}
const Coordenada aed2_Juego::pcACoord(PuntoCardinal pc) const{
    Coordenada paso;
    if(pc == Norte){
        paso = Coordenada(0,1);
    }else if(pc == Este){
        paso = Coordenada(1,0);
    }else if(pc == Sur){
        paso = Coordenada(0,-1);
    }else if(pc == Oeste){
        paso = Coordenada(-1,0);
    }else{
        paso = Coordenada(0,0);
    }
    return paso;
}

bool aed2_Juego::sePuedeMover(PuntoCardinal pc) const {
    bool res = true;
    Coordenada pos_futura;
    Coordenada paso = pcACoord(pc);
    pos_futura = Coordenada(_posicionActual.first + paso.first,
                            _posicionActual.second + paso.second );
    if (hayPared(pos_futura)){
        res = false;
    }
    else if(hayCaja(pos_futura)){
        // Chequeo si se puede mover
        Coordenada pos_futura_caja = Coordenada(_posicionActual.first + 2*paso.first,
                                                _posicionActual.second + 2*paso.second );
        if(!hayPared(pos_futura_caja) && !hayCaja(pos_futura_caja)){
            res = true;
        }
        else{
            res = false;
        }
    }
    return res;
}

// IMPORTANTE: Debe devolver:
// - true si al mover se completa el nivel actual
// - false en caso contrario.
bool aed2_Juego::mover(PuntoCardinal pc) {
    bool completado = false;
    if (sePuedeMover(pc)){
        _accionFue.push_back(pc);
        Coordenada paso = pcACoord(pc);
        Coordenada pos_futura = Coordenada(_posicionActual.first + paso.first,
                                _posicionActual.second + paso.second );
        // Muevo Caja
        if (_niveles[_nivelActual].cajas.count(pos_futura) > 0){
            // Hay caja en esa posicion, la muevo
            Coordenada pos_futura_caja = Coordenada(_posicionActual.first + 2 * paso.first,
                                                    _posicionActual.second + 2 * paso.second );
            _niveles[_nivelActual].cajas.erase(pos_futura);
            _niveles[_nivelActual].cajas.insert(pos_futura_caja);
            _accionMovioCaja.push_back(true);
        }
        else{
            _accionMovioCaja.push_back(false);
        }
        // Muevo el PJ
        _posicionActual = pos_futura;
        completado = _niveles[_nivelActual].cajas == _niveles[_nivelActual].depositos;
        if (completado){
            _nivelActual +=1;
            iniciar_Nivel(_niveles[_nivelActual]);
        }
    }
    return completado;
}

void aed2_Juego::tirarBomba() {
    if (_cantidadBombas>0){
        _cantidadBombas -= 1;
        _accionFue.push_back(Explotar);
        _coordDeBomba.push_back(_posicionActual);
        _explosiones.insert(_posicionActual);
    }

}

void aed2_Juego::deshacer() {
    if (_accionFue.size() == 0){
        // No hay nada que deshacer
        return;
    }
    if (_accionFue.back()==Explotar){
        // Fue tirar bomba
        _cantidadBombas += 1;
        _accionFue.pop_back();
        _explosiones.erase(_coordDeBomba.back());
        _coordDeBomba.pop_back();
    }else{
        Coordenada paso;
        if(_accionFue.back() == 0) {
             paso = Coordenada(0, 1);
        }else if (_accionFue.back() == 1) {
            paso =  Coordenada(1, 0);
        }else if (_accionFue.back() == 2) {
            paso =  Coordenada(0, -1);
        }else if (_accionFue.back() == 3) {
            paso =  Coordenada(-1, 0);
        }
        // Actualizo pos de caja
        if(_accionMovioCaja.back()){
            Coordenada pos_caja = Coordenada(_posicionActual.first + paso.first,
                                             _posicionActual.second + paso.second );

            _niveles[_nivelActual].cajas.erase(pos_caja);
            _niveles[_nivelActual].cajas.insert(_posicionActual);

        }
        _accionMovioCaja.pop_back();
        // Actualizo pos de persona
        _posicionActual = Coordenada(_posicionActual.first - paso.first,
                                    _posicionActual.second - paso.second );

        _accionFue.pop_back();
    }
}

