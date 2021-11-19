#include "types.h"

using namespace std;

void actualizarMapa(mapa &m) {
    int N = m.size();
    int M = m[0].size();
    vector<posicion> nuevosVecinosQueRien;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            int duracionPeriodoActual = m[y][x].first;
            if (duracionPeriodoActual == 15) {
                m[y][x].first = 0;
                m[y][x].second++;
            } else if (duracionPeriodoActual > 0) {
                m[y][x].first++;
                if (y > 0) nuevosVecinosQueRien.push_back({y - 1, x});
                if (y < N - 1) nuevosVecinosQueRien.push_back({y + 1, x});
                if (x > 0) nuevosVecinosQueRien.push_back({y, x - 1});
                if (x < M - 1) nuevosVecinosQueRien.push_back({y, x + 1});
            }
        }
    }
    for (int i = 0; i < nuevosVecinosQueRien.size(); i++) {
        int y = nuevosVecinosQueRien[i].first;
        int x = nuevosVecinosQueRien[i].second;
        m[y][x].first = 1;
    }
}