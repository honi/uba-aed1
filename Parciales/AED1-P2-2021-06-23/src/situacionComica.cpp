#include "types.h"

using namespace std;

void situacionComica(mapa m, int &riendo, int &aburridos, int &nuncaEscucharon) {
    riendo = 0;
    aburridos = 0;
    nuncaEscucharon = 0;

    int N = m.size();
    int M = m[0].size();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int duracionPeriodoActual = m[y][x].first;
            int cantidadPeriodosAnteriores = m[y][x].second;
            if (duracionPeriodoActual > 0) {
                riendo++;
            } else if (duracionPeriodoActual == 0 && cantidadPeriodosAnteriores > 0) {
                aburridos++;
            } else {
                nuncaEscucharon++;
            }
        }
    }
}