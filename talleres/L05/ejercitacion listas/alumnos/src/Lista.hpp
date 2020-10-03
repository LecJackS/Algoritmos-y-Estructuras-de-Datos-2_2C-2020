#include "Lista.h"

Lista::Lista() : _prim(nullptr), _ulti(nullptr), _longitud(0) {
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    Nodo* actual = _prim;
    Nodo* prox;
    while(actual != nullptr){
        prox = actual->sig;
        delete(actual);
        actual = prox;
    }

}

Lista::Nodo::Nodo(const int& elem) : valor(elem), prev(nullptr), sig(nullptr) {
}

Lista& Lista::operator=(const Lista& aCopiar) {
    // Si habia algo, lo borro primero
    while(_longitud > 0){
        this->eliminar(0);
    }
    // Y ahora lo lleno
    for(int i=0; i<aCopiar.longitud(); i++){
        this->agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    // Lo meto al principio y conecto
    nuevo->sig = _prim;
    if (_longitud>0){
        _prim->prev = nuevo;
    }

    _prim = nuevo;
    _longitud++;
    if (_longitud==1){
        // Si es el unico, tambien es el ultimo
        _ulti = nuevo;
    }

}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    // Lo meto al final y conecto

    nuevo->prev = _ulti;
    if (_longitud>0){
        _ulti->sig = nuevo;
    }
    _ulti = nuevo;
    _longitud++;
    if (_longitud==1){
        // Si es el unico, tambien es el primero
        _prim = nuevo;
    }
}

void Lista::eliminar(Nat i) {
    Nodo* actual;
    actual = _prim;
    for(int j=0; j<i; j++){
        actual = actual->sig;
    }
    if(i==0){
        // Borrar el primero
        if(_longitud==1){
            _ulti = nullptr;
            _prim = nullptr;
        }else{
            _prim->sig->prev = nullptr;
            _prim = _prim->sig;
        }
    }
    else if(i >= _longitud-1){
        // Borrar el ultimo (nunca es unico)
        _ulti->prev->sig = nullptr;
        _ulti = _ulti->prev;
    }
    else{
        // Es un elemento 'del medio'
        actual->sig->prev = actual->prev;
        actual->prev->sig = actual->sig;
    }

    delete(actual);
    _longitud--;
}

int Lista::longitud() const {
    return _longitud;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* actual;
    actual = _prim;
    for(int j=0; j<i; j++){
        actual = actual->sig;
    }
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    Nodo* actual;
    actual = _prim;
    for(int j=0; j<i; j++){
        actual = actual->sig;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
