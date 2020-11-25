using namespace std;

template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr) {
    // Completar
    _cardinal = 0;
}

template <class T>
Conjunto<T>::Nodo::Nodo(const T& v) : izq(nullptr), der(nullptr), parent(nullptr){
    valor = v;
};

template <class T>
void Conjunto<T>::destruir(Nodo *x) {
    if(x != nullptr){
        destruir(x->izq);
        destruir(x->der);
        delete x;
    }
}

template <class T>
Conjunto<T>::~Conjunto() {
    destruir(_raiz);
}



template <class T>
typename  Conjunto<T>::Nodo*
Conjunto<T>::tree_search(const T &v) const {
    Nodo *x = _raiz;
    while(x != nullptr && v != x->valor){
        if(v < x->valor){
            x = x->izq;
        }
        else {
            x = x->der;
        }
    }
    return x;
}

template <class T>
void Conjunto<T>::tree_insert(const T &v) {
    Nodo* y = nullptr;
    Nodo* x = _raiz;
    Nodo* nuevo = new Nodo(v);

    while(x!= nullptr){
        y = x;
        if(nuevo->valor < x->valor){
            x = x->izq;
        }
        else {
            x = x->der;
        }
    }
    nuevo->parent = y;
    if (y == nullptr){
        _raiz = nuevo;
    }
    else if(nuevo->valor < y->valor){
        y->izq = nuevo;
    }
    else{
        y->der = nuevo;
    }

}

template <class T>
void Conjunto<T>::transplant(Nodo *a, Nodo *b) {
    if(a->parent == nullptr){
        _raiz = b;
    }
    else if(a == a->parent->izq){
        a->parent->izq = b;
    }
    else{
        a->parent->der = b;
    }
    if(b != nullptr){
        b->parent = a->parent;
    }
}

template <class T>
typename  Conjunto<T>::Nodo*
Conjunto<T>::tree_min(Nodo *x) const {
    while(x->izq!= nullptr){
        x=x->izq;
    }
    return x;
}

template <class T>
typename  Conjunto<T>::Nodo*
Conjunto<T>::tree_max(Nodo *x) const {
    while(x->der != nullptr){
        x=x->der;
    }
    return x;
}


template <class T>
void Conjunto<T>::tree_delete(Nodo *a) {
    Nodo *a_borrar = tree_search(a->valor);
    if(a_borrar->izq == nullptr){
        transplant(a_borrar, a_borrar->der);
    }
    else if(a_borrar->der == nullptr){
        transplant(a_borrar, a_borrar->izq);
    }
    else{
        Nodo *y = tree_min(a_borrar->der);
        if(y->parent != a_borrar){
            transplant(y, y->der);
            y->der=a_borrar->der;
            y->der->parent = y;
        }
        transplant(a_borrar, y);
        y->izq = a_borrar->izq;
        y->izq->parent=y;
    }
}

template <class T>
typename  Conjunto<T>::Nodo*
Conjunto<T>::tree_successor(Nodo* x) {
    if(x->der!= nullptr){
        return tree_min(x->der);
    }
    Nodo* y = x->parent;
    while(y!=nullptr && x == y->der){
        x = y;
        y = y->parent;
    }
    return y;
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    if(_cardinal==0){
        return false;
    }
    else {
        if (tree_search(clave) != nullptr){
            return true;
        }
    }
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if(!pertenece(clave)){
        tree_insert(clave);
        _cardinal++;
    }
}

template <class T>
void Conjunto<T>::remover(const T& a) {
    Nodo * a_borrar = tree_search(a);
    tree_delete(a_borrar);
    _cardinal --;
    delete(a_borrar);
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    tree_successor(tree_search(clave));
}

template <class T>
const T& Conjunto<T>::minimo() const {
    tree_min(_raiz);
}

template <class T>
const T& Conjunto<T>::maximo() const {
    tree_max(_raiz);
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

