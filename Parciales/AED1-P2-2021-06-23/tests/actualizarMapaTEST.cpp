#include "gtest/gtest.h"
#include <vector>
#include "../src/actualizarMapa.cpp"

using namespace std;

TEST(actualizarMapa, noPasaNada) {
    mapa m = {
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    mapa mEsperado = {
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    actualizarMapa(m);
    ASSERT_EQ(m, mEsperado);
}

TEST(actualizarMapa, nuevosVecinosSeRien) {
    mapa m = {
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {1, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    mapa mEsperado = {
            {{0, 0}, {1, 0}, {0, 0}},
            {{1, 0}, {2, 0}, {1, 0}},
            {{0, 0}, {1, 0}, {0, 0}},
    };
    actualizarMapa(m);
    ASSERT_EQ(m, mEsperado);
}

TEST(actualizarMapa, seDejanDeReir) {
    mapa m = {
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {15, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    mapa mEsperado = {
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 1}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    actualizarMapa(m);
    ASSERT_EQ(m, mEsperado);
}