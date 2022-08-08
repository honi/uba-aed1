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
typedef vector<vector<zona> > mapa;

poblacion getPoblacion(mapa &m, posicion &p) {
    return m[p.first][p.second].second;
}

void swapPosiciones(vector<posicion> &posiciones, int i, int j) {
    posicion tmp = posiciones[i];
    posiciones[i] = posiciones[j];
    posiciones[j] = tmp;
}

vector<posicion> bajaNatalidad(mapa m1, mapa m2) {
    vector<posicion> posiciones;
    poblacion minCrecimiento = 0;
    for (int fila = 0; fila < m1.size(); fila++) {
        for (int columna = 0; columna < m1[0].size(); columna++) {
            posicion p = {fila, columna};
            poblacion poblacion1 = getPoblacion(m1, p);
            poblacion poblacion2 = getPoblacion(m2, p);
            poblacion crecimiento = poblacion2 - poblacion1;
            if ((fila == 0 && columna == 0) || crecimiento < minCrecimiento) {
                minCrecimiento = crecimiento;
                posiciones = {};
            }
            if (crecimiento == minCrecimiento) {
                posiciones.push_back(p);
                int i = posiciones.size() - 1;
                while (i > 0 && poblacion2 < getPoblacion(m2, posiciones[i - 1])) {
                    swapPosiciones(posiciones, i, i - 1);
                    i--;
                }
            }
        }
    }
    return posiciones;
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

    // El mapa 2
    int f2;
    cin >> f2;
    int c2;
    cin >> c2;
    mapa m2;
    char aux2;
    int alt2;
    int pob2;
    for (int i = 0; i < f2; i++) {
        vector<zona> fila2;
        for (int j = 0; j < c2; j++) {
            cin >> aux2;
            cin >> alt2;
            cin >> aux2;
            cin >> pob2;
            cin >> aux2;
            fila2.push_back(make_pair(alt2, pob2));
        }

        m2.push_back(fila2);
    }

    // Invoco la función
    vector<posicion> pos = bajaNatalidad(m, m2);

    // Ordeno el vector
    // Deja de ser necesario porque ahora va ordenado de acuerdo a especificación std::sort(pos.begin(), pos.end());

    // Imprimo la salida
    for (int i = 0; i < pos.size(); i++) {
        cout << "(" << pos[i].first << "," << pos[i].second << ") ";
    }

    return 0;
}
