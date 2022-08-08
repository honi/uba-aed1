#include <vector>
#include "gtest/gtest.h"
#include "../src/ej1.cpp"

using namespace std;

TEST(esValle, esquinaPositivo) {
    mapa m = {
            {{10, 100}, {40,  100}},
            {{30, 100}, {500, 100}},
    };
    posicion p = {0, 0};
    ASSERT_TRUE(esValle(m, p));
}

TEST(esValle, medioPositivo) {
    mapa m = {
            {{10, 100}, {10, 100}, {10, 100}},
            {{10, 100}, {1,  100}, {10, 100}},
            {{10, 100}, {10, 100}, {10, 100}},
    };
    posicion p = {1, 1};
    ASSERT_TRUE(esValle(m, p));
}

TEST(esValle, medioNegativo) {
    mapa m = {
            {{10, 100}, {10, 100}, {10, 100}},
            {{10, 100}, {20, 100}, {10, 100}},
            {{10, 100}, {10, 100}, {10, 100}},
    };
    posicion p = {1, 1};
    ASSERT_FALSE(esValle(m, p));
}