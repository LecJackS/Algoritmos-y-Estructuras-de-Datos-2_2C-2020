#include "aed2_Juego.h"

aed2_Juego::aed2_Juego(vector<aed2_Nivel> ns) {
    COMPLETAR(aed2_Juego);
}

bool aed2_Juego::hayPared(Coordenada c) const {
    COMPLETAR(hayPared);
}

bool aed2_Juego::hayDeposito(Coordenada c) const {
    COMPLETAR(hayDeposito);
}

bool aed2_Juego::hayCaja(Coordenada c) const {
    COMPLETAR(hayCaja);
}

Coordenada aed2_Juego::posicionActual() const {
    COMPLETAR(posicionActual);
}

Nat aed2_Juego::cantidadBombas() const {
    COMPLETAR(cantidadBombas);
}

bool aed2_Juego::sePuedeMover(PuntoCardinal pc) const {
    COMPLETAR(sePuedeMover);
}

// IMPORTANTE: Debe devolver:
// - true si al mover se completa el nivel actual
// - false en caso contrario.
bool aed2_Juego::mover(PuntoCardinal pc) {
    COMPLETAR(mover);
}

void aed2_Juego::tirarBomba() {
    COMPLETAR(tirarBomba);
}

void aed2_Juego::deshacer() {
    COMPLETAR(deshacer);
}

