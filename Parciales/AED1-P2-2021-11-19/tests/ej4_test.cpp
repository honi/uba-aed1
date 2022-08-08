#include <vector>
#include "gtest/gtest.h"
#include "../src/ej4.cpp"

using namespace std;

TEST(rellenarValles, casoFacil) {
    mapa m = {
            {{10, 105}, {40,  120}},
            {{30, 150}, {500, 160}},
    };
    mapa mapaEsperado = {
            {{35, 105}, {40,  120}},
            {{30, 150}, {500, 160}},
    };
    int metros = rellenarValles(m);
    ASSERT_EQ(metros, 25);
    ASSERT_EQ(m, mapaEsperado);
}

TEST(rellenarValles, multiplesVallesAislados) {
    mapa m = {
            {{1,  1}, {10, 1}, {10, 1}},
            {{10, 1}, {10, 1}, {10, 1}},
            {{10, 1}, {10, 1}, {1,  1}},
    };
    mapa mapaEsperado = {
            {{10, 1}, {10, 1}, {10, 1}},
            {{10, 1}, {10, 1}, {10, 1}},
            {{10, 1}, {10, 1}, {10, 1}},
    };
    int metros = rellenarValles(m);
    ASSERT_EQ(metros, 18);
    ASSERT_EQ(m, mapaEsperado);
}

TEST(rellenarValles, multiplesVallesSuperpuestos) {
    mapa m = {
            {{1,  1}, {10, 1}, {10, 1}},
            {{10, 1}, {1, 1}, {10, 1}},
            {{10, 1}, {10, 1}, {1,  1}},
    };
    mapa mapaEsperado = {
            {{10, 1}, {10, 1}, {10, 1}},
            {{10, 1}, {10, 1}, {10, 1}},
            {{10, 1}, {10, 1}, {10, 1}},
    };
    int metros = rellenarValles(m);
    ASSERT_EQ(metros, 27);
    ASSERT_EQ(m, mapaEsperado);
}