#include "aed2_Juego.h"
#include "Juego.h"
#include "Nivel.h"

aed2_Juego::aed2_Juego(vector<aed2_Nivel> ns) {
    _niveles = convertirNiveles(ns);
    _juego = new Juego(_niveles);

}

aed2_Juego::~aed2_Juego() {
    delete(_juego);
    for(Nivel *n : *_niveles){
        delete(n);
    }
    delete(_niveles);
}

vector<Nivel*> *aed2_Juego::convertirNiveles(vector<aed2_Nivel> niv_aed2) {
    vector<Nivel*> * niveles = new vector<Nivel*>(niv_aed2.size());
    for (int i=0; i<niv_aed2.size(); i++){
        //Mapa m, Coordenada p, set<Coordenada> cs, Nat b
        Mapa m = Mapa(niv_aed2[i].paredes, niv_aed2[i].depositos);
        Coordenada p = niv_aed2[i].posicionInicial;
        set<Coordenada> cajas = niv_aed2[i].cajas;
        Nat b = niv_aed2[i].cantidadBombas;

        Nivel *nivel = new Nivel(m, p, cajas, b);
        niveles->operator[](i) = nivel;
    }
    return niveles;
}

bool aed2_Juego::hayPared(Coordenada c) const {
    _juego->nivelActual()->mapa().hayPared(c);
}

bool aed2_Juego::hayDeposito(Coordenada c) const {
    _juego->nivelActual()->mapa().hayDeposito(c);
}

bool aed2_Juego::hayCaja(Coordenada c) const {
    _juego->nivelActual()->hayCaja(c);
}

Coordenada aed2_Juego::posicionActual() const {
    _juego->nivelActual()->persona();
}

Nat aed2_Juego::cantidadBombas() const {
    _juego->nivelActual()->numBombas();
}

bool aed2_Juego::sePuedeMover(PuntoCardinal pc) const {
    _juego->nivelActual()->puedoMover(pc);
}

// IMPORTANTE: Debe devolver:
// - true si al mover se completa el nivel actual
// - false en caso contrario.
bool aed2_Juego::mover(PuntoCardinal pc) {
    return _juego->mover(pc);
}

void aed2_Juego::tirarBomba() {
    _juego->tirarBomba();
}

void aed2_Juego::deshacer() {
    _juego->deshacer();
}




