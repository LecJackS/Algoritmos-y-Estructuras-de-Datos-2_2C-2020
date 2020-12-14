#ifndef TIPOS_H
#define TIPOS_H

#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

using Nat = unsigned int;

using Coordenada = pair<int, int>;

enum PuntoCardinal {
    Norte, Este, Sur, Oeste, Explotar
};

inline Coordenada operator+(const Coordenada & l, const Coordenada & r) {
    return {l.first + r.first,l.second + r.second};
}

inline Coordenada operator+(const Coordenada & l, const PuntoCardinal dir) {
    Coordenada paso;
    switch (dir) {
        case Norte:
            paso = Coordenada(0,1);
            break;
        case Este:
            paso = Coordenada(1,0);
            break;
        case Sur:
            paso = Coordenada(0,-1);
            break;
        case Oeste:
            paso = Coordenada(-1,0);
            break;
    }

    return l + paso;
}

// subsV(vector, desde, hasta) : Devuelvo vector[desde:hasta]
//template<typename T>
//vector<T> subsV(vector<T> const &v, int m, int n) {
//    auto first = v.begin() + m;
//    auto last = v.begin() + n + 1;
//    vector<T> vector(first, last);
//    return vector;
//}


struct aed2_Nivel {
    set<Coordenada> paredes;
    set<Coordenada> depositos;
    set<Coordenada> cajas;
    Coordenada posicionInicial;
    Nat cantidadBombas;
};

#define COMPLETAR(fn)   cerr << "COMPLETAR: " << #fn << endl; exit(1); assert(false);

#endif // TIPOS_H
