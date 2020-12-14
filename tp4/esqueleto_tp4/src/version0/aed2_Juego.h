#ifndef AED2_JUEGO_H
#define AED2_JUEGO_H

#include <vector>
#include "Tipos.h"

class aed2_Juego {
public:

    aed2_Juego(vector<aed2_Nivel> ns);

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

    const Coordenada pcACoord(PuntoCardinal pc) const;
    void iniciar_Nivel(aed2_Nivel n);

	vector<aed2_Nivel> _niveles;
	int _nivelActual;
	Coordenada _posicionActual;
	Nat _cantidadBombas;
	vector<PuntoCardinal> _accionFue;
    vector<bool> _accionMovioCaja;
	vector<Coordenada> _coordDeBomba;
	set<Coordenada> _explosiones;

};

#endif // AED2_JUEGO_H
