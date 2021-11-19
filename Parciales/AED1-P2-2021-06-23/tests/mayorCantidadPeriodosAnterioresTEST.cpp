#include "gtest/gtest.h"
#include <vector>
#include "../src/mayorCantidadPeriodosAnteriores.cpp"

using namespace std;

TEST(mayorCantidadPeriodosAnteriores, happyPath) {
    mapa m = {
            {{0, 1}, {0, 2}, {0, 3}},
            {{0, 4}, {0, 4}, {0, 4}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    vector<posicion> res = {
            {1, 0},
            {1, 1},
            {1, 2},
    };
    ASSERT_EQ(mayorCantidadPeriodosAnteriores(m), res);
}

TEST(mayorCantidadPeriodosAnteriores, nadieLoEscucho) {
    mapa m = {
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    vector<posicion> res = {
            {0, 0}, {0, 1}, {0, 2},
            {1, 0}, {1, 1}, {1, 2},
            {2, 0}, {2, 1}, {2, 2},
    };
    ASSERT_EQ(mayorCantidadPeriodosAnteriores(m), res);
}