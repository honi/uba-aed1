#include <vector>
#include "gtest/gtest.h"
#include "../src/ej3.cpp"

using namespace std;

TEST(vivenEnAltura, casoFacil) {
    mapa m = {
            {{10, 10}, {40,  100}},
            {{10, 10}, {10, 10}},
    };
    int altura;
    int poblacion;
    vivenEnAltura(m, altura, poblacion);
    ASSERT_EQ(altura, 40);
    ASSERT_EQ(poblacion, 100);
}

TEST(vivenEnAltura, meseta) {
    mapa m = {
            {{10, 10}, {10,  100}},
            {{10, 10}, {10, 10}},
    };
    int altura;
    int poblacion;
    vivenEnAltura(m, altura, poblacion);
    ASSERT_EQ(altura, 10);
    ASSERT_EQ(poblacion, 130);
}

TEST(vivenEnAltura, matcheanDos) {
    mapa m = {
            {{20, 10}, {10,  100}},
            {{10, 10}, {20, 10}},
    };
    int altura;
    int poblacion;
    vivenEnAltura(m, altura, poblacion);
    ASSERT_EQ(altura, 20);
    ASSERT_EQ(poblacion, 20);
}
