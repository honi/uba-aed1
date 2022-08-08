#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

// DEFINICIONES DE TIPO
typedef pair<int, int> posicion;
typedef int altura;
typedef int poblacion;
typedef pair<altura, poblacion> zona;
typedef vector<vector<zona > > mapa;

altura getAltura(mapa &m, posicion &p) {
    return m[p.first][p.second].first;
}

poblacion getPoblacion(mapa &m, posicion &p) {
    return m[p.first][p.second].second;
}

void vivenEnAltura(mapa m, int &alt, int &cantCarpinchos) {
    altura maxAltura = 0;
    for (int fila = 0; fila < m.size(); fila++) {
        for (int columna = 0; columna < m[0].size(); columna++) {
            posicion p = {fila, columna};
            altura alturaDeLaPosicion = getAltura(m, p);
            if (alturaDeLaPosicion > maxAltura) {
                maxAltura = alturaDeLaPosicion;
                cantCarpinchos = 0;
            }
            if (alturaDeLaPosicion == maxAltura) {
                cantCarpinchos += getPoblacion(m, p);
            }
        }
    }
    alt = maxAltura;
}

// Renombrar a "main" para subir a la plataforma de entrega.
int mainParaSubir() {
    /* No hace falta modificar el main */

    // El mapa 1
    int f;
    cin >> f;
    int c;
    cin >> c;
    mapa m;
    char aux;
    int alt;
    int pob;
    for (int i = 0; i < f; i++) {
        vector<zona> fila;
        for (int j = 0; j < c; j++) {
            cin >> aux;
            cin >> alt;
            cin >> aux;
            cin >> pob;
            cin >> aux;
            fila.push_back(make_pair(alt, pob));
        }

        m.push_back(fila);
    }

    // Invoco la función
    int altura;
    int cantGente;
    vivenEnAltura(m, altura, cantGente);

    // Imprimo la salida
    cout << altura << " " << cantGente << endl;

    return 0;
}
