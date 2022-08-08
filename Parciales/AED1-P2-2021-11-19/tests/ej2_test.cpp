#include <vector>
#include "gtest/gtest.h"
#include "../src/ej2.cpp"

using namespace std;

TEST(bajaNatalidad, casoFacil) {
    mapa m1 = {
            {{10, 100}, {40,  100}},
            {{30, 100}, {500, 100}},
    };
    mapa m2 = {
            {{10, 105}, {40,  120}},
            {{30, 150}, {500, 160}},
    };
    vector<posicion> esperado = {{0, 0}};
    vector<posicion> res = bajaNatalidad(m1, m2);
    ASSERT_EQ(res, esperado);
}

TEST(bajaNatalidad, multiplesPosiciones) {
    mapa m1 = {
            {{10, 100}, {40,  100}},
            {{30, 100}, {500, 200}},
    };
    mapa m2 = {
            {{10, 105}, {40,  120}},
            {{30, 150}, {500, 205}},
    };
    vector<posicion> esperado = {{0, 0},
                                 {1, 1}};
    vector<posicion> res = bajaNatalidad(m1, m2);
    ASSERT_EQ(res, esperado);
}

TEST(bajaNatalidad, posicionesOrdenadas) {
    mapa m1 = {
            {{10, 200}, {40,  100}},
            {{30, 100}, {500, 100}},
    };
    mapa m2 = {
            {{10, 205}, {40,  120}},
            {{30, 150}, {500, 105}},
    };
    vector<posicion> esperado = {{1, 1},
                                 {0, 0}};
    vector<posicion> res = bajaNatalidad(m1, m2);
    ASSERT_EQ(res, esperado);
}

TEST(bajaNatalidad, todas) {
    mapa m1 = {
            {{10, 200}, {40,  100}},
            {{30, 100}, {500, 100}},
    };
    mapa m2 = {
            {{10, 200}, {40,  100}},
            {{30, 100}, {500, 100}},
    };
    vector<posicion> esperado = {{0, 1},
                                 {1, 0},
                                 {1, 1},
                                 {0, 0}};
    vector<posicion> res = bajaNatalidad(m1, m2);
    ASSERT_EQ(res, esperado);
}

TEST(bajaNatalidad, variosGruposDeCrecimiento) {
    mapa m1 = {
            {{10, 100}, {10, 100}},
            {{10, 100}, {10, 10}},
    };
    mapa m2 = {
            {{10, 105}, {10, 105}},
            {{10, 101}, {10, 11}},
    };
    vector<posicion> esperado = {{1, 1},
                                 {1, 0}};
    vector<posicion> res = bajaNatalidad(m1, m2);
    ASSERT_EQ(res, esperado);
}

TEST(bajaNatalidad, decrecen) {
    mapa m1 = {
            {{10, 100}, {10, 100}},
            {{10, 100}, {10, 100}},
    };
    mapa m2 = {
            {{10, 90},  {10, 100}},
            {{10, 100}, {10, 100}},
    };
    vector<posicion> esperado = {{0, 0}};
    vector<posicion> res = bajaNatalidad(m1, m2);
    ASSERT_EQ(res, esperado);
}
