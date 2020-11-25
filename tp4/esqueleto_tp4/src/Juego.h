#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Tipos.h"

class Juego {
public:

    Juego(vector<aed2_Nivel> ns);

    bool hayPared(Coordenada c) const;

    bool hayDeposito(Coordenada c) const;

    bool hayCaja(Coordenada c) const;

    Coordenada posicionActual() const;

    Nat cantidadBombas() const;

    bool sePuedeMover(PuntoCardinal pc) const;

    // IMPORTANTE: Debe devolver:
    // - true si al mover se completa el nivel actual
    // - false en caso contrario.
    bool mover(PuntoCardinal pc);

    void tirarBomba();

    void deshacer();

private:

    // Completar

};

#endif // AED2_JUEGO_H
