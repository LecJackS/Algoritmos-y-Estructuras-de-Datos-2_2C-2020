#include "aed2_Juego.h"
#include "Juego.h"
#include "Nivel.h"

aed2_Juego::aed2_Juego(vector<aed2_Nivel> ns) {
    _niveles = new vector<Nivel*>(ns.size());
    convertirNiveles(ns);
    _juego = new Juego(_niveles);
}

aed2_Juego::~aed2_Juego() {
    delete(_juego);
    // TODO: Estas líneas que dejaste comentadas tienen que estar
    //  (si no, hay leaks de memoria que detecta valgrind).
    //  Esta memoria la pediste haciendo news en esta clase en el
    //  método convertirNiveles, por lo que esta misma clase tiene
    //  que encargarse de hacer los deletes correspondientes.
//    for(Nivel *n : *_niveles){
//        delete(n);
//    }
    //delete(_niveles);
}

void aed2_Juego::convertirNiveles(vector<aed2_Nivel> niv_aed2) {
    vector<Nivel*> * niveles;
    for (int i=0; i<niv_aed2.size(); i++){
        //Mapa m, Coordenada p, set<Coordenada> cs, Nat b
        Mapa *m = new Mapa(niv_aed2[i].paredes, niv_aed2[i].depositos);
        Coordenada p = niv_aed2[i].posicionInicial;
        set<Coordenada> cajas = niv_aed2[i].cajas;
        Nat b = niv_aed2[i].cantidadBombas;
        // Para cada niv_aed2[i], creo nuevo objeto Nivel con valores iniciales dados por nive_aed2[i]
        Nivel *nivel = new Nivel(m, p, cajas, b);
        _niveles->operator[](i) = nivel;
    }
}

bool aed2_Juego::hayPared(Coordenada c) const {
    return _juego->nivelActual()->mapa()->hayPared(c);
}

bool aed2_Juego::hayDeposito(Coordenada c) const {
    return _juego->nivelActual()->mapa()->hayDeposito(c);
}

bool aed2_Juego::hayCaja(Coordenada c) const {
    return _juego->nivelActual()->hayCaja(c);
}

Coordenada aed2_Juego::posicionActual() const {
    return _juego->nivelActual()->persona();
}

Nat aed2_Juego::cantidadBombas() const {
    return _juego->nivelActual()->numBombas();
}

bool aed2_Juego::sePuedeMover(PuntoCardinal pc) const {
    return _juego->nivelActual()->puedoMover(pc);
}

// IMPORTANTE: Debe devolver:
// - true si al mover se completa el nivel actual
// - false en caso contrario.
bool aed2_Juego::mover(PuntoCardinal pc) {
    return _juego->mover(pc);
}

void aed2_Juego::tirarBomba() {
    return _juego->tirarBomba();
}

void aed2_Juego::deshacer() {
    return _juego->deshacer();
}




