#ifndef AED2_JUEGO_H
#define AED2_JUEGO_H

#include <vector>
#include "Tipos.h"
#include "Juego.h"

class aed2_Juego {
public:

    aed2_Juego(vector<aed2_Nivel> ns);

    ~aed2_Juego();

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
    void convertirNiveles(vector<aed2_Nivel>);
    vector<Nivel*> *_niveles;
	Juego *_juego;

};

#endif // AED2_JUEGO_H
