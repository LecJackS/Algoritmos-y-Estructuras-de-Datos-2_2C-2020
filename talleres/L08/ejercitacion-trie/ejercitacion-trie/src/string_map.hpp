
#include "string_map.h"

template <typename T>
string_map<T>::string_map() : _size(0){
    raiz = new Nodo;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // borro anterior
    // piso con lo nuevo
    // Si habia algo, lo borro primero
    erase_all_next(raiz);
    delete(raiz->definicion);

    //recorro tod o el dicc y argego uno a uno
    int i = 0;
    for(const string key : keys(d.raiz, "")){
        pair<string, T> elem;
        elem.first = key;
        elem.second = d.at(key);
        insert(elem);
    }
    return *this;
}

template <typename T>
const set<string> string_map<T>::keys() {
    const set<string> keys = keys(raiz, "");
    return keys;
}

template <typename T>
const set<string> string_map<T>::keys(Nodo* nodo_actual, string clave) {
    set<string> out;
    int i = 0;
    string c;
    if(nodo_actual->definicion != nullptr){
        out.insert(clave);
    }

    for(Nodo* sig : nodo_actual->siguientes){
        if(sig != nullptr){
            // Inserto todos los siguients a este nodo
            c = char(i);
            for(string key : keys(sig, clave + c)){
                out.insert(key);
            }
        }
        i++;
    }
    return out;
}

template <typename T>
string_map<T>::~string_map(){
    erase_all_next(raiz);
    delete(raiz);
}

template<typename T>
string_map<T>::Nodo::~Nodo() {
    delete(definicion);
    //delete(&siguientes);
    definicion = nullptr;
    // Intento setear cada elemento del nodo a nullptr, pero no funciona
    for(int i=0; i<siguientes.size(); i++){
        if(siguientes[i] != nullptr){
            siguientes[i] = nullptr;
        }
    }

}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* nodo_actual = raiz;
    for(int i=0; i<clave.length(); i++){
        int idx = int(clave[i]);
        if((nodo_actual->siguientes)[idx] == nullptr){
            return 0;
        }
        else{
            nodo_actual = nodo_actual->siguientes[idx];
        }
    }
    if(nodo_actual->definicion == nullptr){
        return 0;
    }
    else{
        return 1;
    }

}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* nodo_actual = raiz;
    for(int i=0; i<clave.length(); i++){
        int idx = int(clave[i]);
        nodo_actual = nodo_actual->siguientes[idx];
    }
    return *(nodo_actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* nodo_actual = raiz;
    int idx;
    for(int i=0; i<clave.length(); i++){
        idx = int(clave[i]);
        nodo_actual = nodo_actual->siguientes[idx];
    }
    return *(nodo_actual->definicion);
}

template<typename T>
void string_map<T>::insert(const pair<string, T> &tupla) {
    string clave = tupla.first;
    T valor = tupla.second;
    Nodo* nodo_actual = raiz;
    for(int i=0; i<clave.length(); i++){
        int idx = int(clave[i]);
        if(nodo_actual->siguientes[idx] == nullptr){
            nodo_actual->siguientes[idx] = new Nodo();
        }
        nodo_actual = nodo_actual->siguientes[idx];
    }
    if(nodo_actual->definicion == nullptr){
        _size+=1;
    }else{
        delete(nodo_actual->definicion);
    }
    nodo_actual->definicion = new T(valor);
}

template <typename T>
void string_map<T>::erase_all_next(Nodo* nodo_actual) {
    for(Nodo* sig : nodo_actual->siguientes){
        if(sig != nullptr){
            // Borro todos los siguients a este nuevo nodo
            erase_all_next(sig);
            delete(sig);
        }
    }
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* nodo_actual = raiz;
    Nodo* nodo_anterior;
    bool act_no_tiene_siguientes, ant_no_tiene_siguientes;
    bool no_tiene_definicion;
    int idx;
    for(int i=0; i<clave.length(); i++){
        idx = int(clave[i]);
        nodo_anterior = nodo_actual;
        nodo_actual = nodo_actual->siguientes[idx];
    }
    // Recorro posibles hijos y si no tiene, borro el nodo
    act_no_tiene_siguientes = true;
    for(Nodo* sig : nodo_actual->siguientes){
        if(sig != nullptr){
            act_no_tiene_siguientes = false;
        }
    }
    //if(act_no_tiene_siguientes){
    if(nodo_actual->definicion != nullptr) {
        _size -= 1;
    }
    //}
    if(nodo_actual == raiz){

    }
    else{
        // Recorro nodo anterior y si no tiene, borro el nodo
        no_tiene_definicion = true;
        no_tiene_definicion = nodo_anterior->definicion == nullptr;
        if(no_tiene_definicion){
            // Recorro posibles siguientes y si no tiene, borro el nodo
            ant_no_tiene_siguientes = true;
            for(Nodo* sig : nodo_anterior->siguientes){
                if(sig != nullptr && sig != nodo_actual){
                    ant_no_tiene_siguientes = false;
                }
            }
            if(ant_no_tiene_siguientes && nodo_actual != raiz){
                // llamado recursivo a borrar la palabra sin ultimo caracter
                erase(clave.substr(0, clave.size() - 1));

            }
        }
        if(act_no_tiene_siguientes){
            // Borro referencia del nodo anterior al actual
            //delete((nodo_anterior->siguientes)[idx]);
            (nodo_anterior->siguientes)[idx] = nullptr;
            // Borro nodo actual
            delete(nodo_actual);
        }
        else{
            // Solo borro su definicion
            delete(nodo_actual->definicion);// = nullptr;
            nodo_actual->definicion = nullptr;
        }
    }
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}


