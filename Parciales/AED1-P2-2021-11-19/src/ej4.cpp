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

vector<posicion> offsetVecinos = {
        {-1, 0},
        {1,  0},
        {0,  -1},
        {0,  1},
};

altura getAltura(mapa &m, posicion &p) {
    return m[p.first][p.second].first;
}

void setAltura(mapa &m, posicion &p, altura nuevaAltura) {
    m[p.first][p.second].first = nuevaAltura;
}

bool posicionEnRango(mapa &m, posicion &p) {
    bool filaEnRango = 0 <= p.first && p.first < m.size();
    bool columnaEnRango = 0 <= p.second && p.second < m[0].size();
    return filaEnRango && columnaEnRango;
}

bool esValle(mapa m, posicion p) {
    bool res = true;
    altura alturaReferencia = getAltura(m, p);
    for (int i = 0; i < offsetVecinos.size(); i++) {
        posicion vecino = {
                p.first + offsetVecinos[i].first,
                p.second + offsetVecinos[i].second,
        };
        if (posicionEnRango(m, vecino)) {
            altura alturaVecino = getAltura(m, vecino);
            res &= alturaReferencia <= alturaVecino;
        }
    }
    return res;
}

int promediarAlturaDeLosVecinos(mapa &m, posicion p) {
    altura sumaAlturaDeLosVecinos = 0;
    int cantidadVecinos = 0;
    for (int i = 0; i < offsetVecinos.size(); i++) {
        posicion vecino = {
                p.first + offsetVecinos[i].first,
                p.second + offsetVecinos[i].second,
        };
        if (posicionEnRango(m, vecino)) {
            sumaAlturaDeLosVecinos += getAltura(m, vecino);
            cantidadVecinos++;
        }
    }
    return sumaAlturaDeLosVecinos / cantidadVecinos; // Siempre hay al menos 1 vecino.
}

int rellenarValles(mapa &m) {
    vector<pair<posicion, altura>> nuevasAlturas;
    for (int fila = 0; fila < m.size(); fila++) {
        for (int columna = 0; columna < m[0].size(); columna++) {
            posicion p = {fila, columna};
            if (esValle(m, p)) {
                altura nuevaAltura = promediarAlturaDeLosVecinos(m, p);
                nuevasAlturas.push_back({p, nuevaAltura});
            }
        }
    }

    int metrosElevados = 0;
    for (int i = 0; i < nuevasAlturas.size(); i++) {
        posicion p = nuevasAlturas[i].first;
        altura nuevasAltura = nuevasAlturas[i].second;
        metrosElevados += nuevasAltura - getAltura(m, p);
        setAltura(m, p, nuevasAltura);
    }
    return metrosElevados;
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
    int res = rellenarValles(m);

    // Imprimo la salida
    cout << res << endl;
    cout << m.size() << endl;
    cout << m[0].size() << endl;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[0].size();j++) {
            cout << "("<< m[i][j].first << "," << m[i][j].second << ") ";
        }
        cout << endl;
    }

    return 0;
}
