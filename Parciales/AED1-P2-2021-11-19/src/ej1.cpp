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

bool posicionEnRango(mapa &m, posicion &p) {
    bool filaEnRango = 0 <= p.first && p.first < m.size();
    bool columnaEnRango = 0 <= p.second && p.second < m[0].size();
    return filaEnRango && columnaEnRango;
}

altura getAltura(mapa &m, posicion &p) {
    return m[p.first][p.second].first;
}

bool esValle(mapa m, posicion p) {
    bool res = true;
    altura alturaReferencia = getAltura(m, p);
    vector<posicion> vecinos = {
            {-1, 0},
            {1,  0},
            {0,  -1},
            {0,  1},
    };
    for (int i = 0; i < vecinos.size(); i++) {
        posicion vecino = {
                p.first + vecinos[i].first,
                p.second + vecinos[i].second,
        };
        if (posicionEnRango(m, vecino)) {
            altura alturaVecino = getAltura(m, vecino);
            res &= alturaReferencia <= alturaVecino;
        }
    }
    return res;
}

// Renombrar a "main" para subir a la plataforma de entrega.
int mainParaSubir() {
    /* No hace falta modificar el main */

    // La posición
    int pos1;
    cin >> pos1;
    int pos2;
    cin >> pos2;
    posicion p = make_pair(pos1, pos2);

    // El mapa
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

    // Evaluo si la posición es valle
    bool res = esValle(m, p);

    // Imprimo la salida
    cout << (res ? "True" : "False") << endl;

    return 0;
}
