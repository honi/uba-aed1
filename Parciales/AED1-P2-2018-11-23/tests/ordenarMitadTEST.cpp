#include "gtest/gtest.h"
#include <vector>
#include "../src/ordenarMitad.cpp"

using namespace std;

TEST(ordenarMitad, happyPath) {
    vector<int> s = {2, 4, 3, 7, 6, 8, 5, 1};
    ordenarMitad(s);
    ASSERT_EQ(s, vector<int>({2, 3, 4, 7, 6, 5, 8, 1}));
}

TEST(ordenarMitad, yaEstaOrdenado) {
    vector<int> s = {1, 2, 3, 4, 5, 6, 7, 8};
    ordenarMitad(s);
    ASSERT_EQ(s, vector<int>({1, 2, 3, 4, 5, 6, 7, 8}));
}

TEST(ordenarMitad, estaOrdenadoAlReves) {
    vector<int> s = {8, 7, 6, 5, 4, 3, 2, 1};
    ordenarMitad(s);
    ASSERT_EQ(s, vector<int>({5, 6, 7, 8, 1, 2, 3, 4}));
}

TEST(ordenarMitad, vacio) {
    vector<int> s = {};
    ordenarMitad(s);
    ASSERT_EQ(s, vector<int>({}));
}