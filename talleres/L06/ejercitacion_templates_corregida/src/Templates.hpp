#include<string>

using namespace std;

// Ejercicio 1: Pasar a templates
template<class T>
T cuadrado(T x) {
  return x * x;
}

// Ejercicio 2: Pasar a templates
template<class Contenedor, class Elem>
bool contiene(Contenedor c, Elem e) {
  for (int i = 0; i < c.size(); i++) {
    if (c[i] == e) {
      return true;
    }
  }
  return false;
}

// Ejercicio 3: Funcion es prefijo con un template contenedor
template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b){
    bool res;
    int dif = b.size() - a.size();
    if(dif > 0){
        // a tiene menos elementos que b
        int k = 0;
        res = false;
        while(k <= dif && !res){
        //for(int k=0; k<dif; k++){
            res = true;
            for(int j=0; j<a.size(); j++){
                res = res && (a[j] == b[j+k]);
            }
            k++;
        }
    }else{
        res = false;
    }
    return res;
}

// Ejercicio 4: Función maximo con un template contenedor y uno elemento
template<class Contenedor, class Elem>
Elem maximo(Contenedor c){
    Elem maximo;
    for(int i=0; i<c.size(); i++){
        if(i==0){
            maximo=c[0];
        }
        else{
            if (maximo < c[i]){
                maximo = c[i];
            }
        }
    }
    return maximo;
}