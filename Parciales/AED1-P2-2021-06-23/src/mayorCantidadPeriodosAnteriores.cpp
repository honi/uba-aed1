#include "types.h"

using namespace std;

vector<posicion> mayorCantidadPeriodosAnteriores(mapa m) {
    vector<posicion> posiciones = {};
    int periodoMaximo = 0;

    int N = m.size();
    int M = m[0].size();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int cantidadPeriodosAnteriores = m[y][x].second;
            if (cantidadPeriodosAnteriores > periodoMaximo) {
                periodoMaximo = cantidadPeriodosAnteriores;
                posiciones = {};
            }
            if (cantidadPeriodosAnteriores == periodoMaximo) {
                posiciones.push_back({y, x});
            }
        }
    }

    return posiciones;
}