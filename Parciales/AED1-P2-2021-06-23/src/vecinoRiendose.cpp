#include "types.h"

using namespace std;

bool estaRiendo(mapa m, posicion p) {
    int N = m.size();
    int M = m[0].size();
    int y = p.first;
    int x = p.second;
    bool yEnRango = 0 <= y && y < N;
    bool xEnRango = 0 <= x && x < M;
    int duracionPeriodoActual = 0;
    if (yEnRango && xEnRango) {
        duracionPeriodoActual = m[y][x].first;
    }
    return duracionPeriodoActual > 0;
}

bool vecinoRiendose(mapa m, posicion p) {
    int y = p.first;
    int x = p.second;
    return estaRiendo(m, {y, x - 1})
           || estaRiendo(m, {y, x + 1})
           || estaRiendo(m, {y - 1, x})
           || estaRiendo(m, {y + 1, x});
}
