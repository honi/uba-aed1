#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores() {
    cout << "El módulo vectores fue cargado correctamente" << endl;
}

//Ejercicio
bool divide(vector<int> v, int a) {
    // Dados un vector v y un int a, decide si a divide a todos los numeros de v.
    bool result = true;
    int i = 0;
    while (i < v.size() && result) {
        if (v[i] % a != 0) result = false;
        i++;
    }
    return result;

//    bool result = true;
//    for (int i = 0; i < v.size() && result; i++) {
//        if (v[i] % a != 0) result = false;
//    }
//    return result;
}

//Ejercicio
int mayor(vector<int> v) {
	// Dado un vector v, devuelve el valor maximo encontrado.
	int max = 0;
	for (int i = 0; i < v.size(); i++) {
	    if (v[i] > max) max = v[i];
	}
	return max;
}

//Ejercicio
vector<int> reverso(vector<int> v) {
	// Dado un vector v, devuelve el reverso.

//    vector<int> result;
//    for (int i = 0; i < v.size(); i++) {
//        result.push_back(v[v.size() - 1 - i]);
//    }
//    return result;

//    vector<int> result;
//    for (int i = v.size() - 1; i >= 0; i--) {
//        result.push_back(v[i]);
//    }
//    return result;

    vector<int> result;
    int i = v.size() - 1;
    while (i >= 0) {
        result.push_back(v[i]);
        i--;
    }
    return result;
}

//Ejercicio
vector<int> rotar(vector<int> v, int k) {
	// Dado un vector v y un entero k, rotar k posiciones los elementos de v.
	// [1,2,3,4,5,6] rotado 2, deberia dar [3,4,5,6,1,2].

	vector<int> result;
	for (int i = k; i < v.size(); i++) {
	    result.push_back(v[i]);
	}
	for (int i = 0; i < k; i++) {
	    result.push_back(v[i]);
	}
	return result;
}

//Ejercicio
bool esPrimo(int n) {
    bool result = true;
    int k = 2;
    while (k < n && result) {
        if (n % k == 0) result = false;
        k++;
    }
    return result;
}

vector<int> factoresPrimos(int n) {
	// Dado un entero devuelve un vector con los factores primos del mismo
	vector<int> result;
	int k = 2;
	while (k <= n) {
	    if (n % k == 0 && esPrimo(k)) result.push_back(k);
	    k++;
	}
	return result;
}

//Ejercicio
void mostrarVector(vector<int> v) {
	// Dado un vector de enteros muestra por la salida estándar, el vector
	// Ejemplo: si el vector es <1, 2, 5, 65> se debe mostrar en pantalla [1, 2, 5, 65]
}
