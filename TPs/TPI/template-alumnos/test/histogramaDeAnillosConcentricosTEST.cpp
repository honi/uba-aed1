#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

pair<eph_h, eph_i> encuesta_prueba(vector<pair<int, int>> pos);


TEST(histogramaDeAnillosConcentricosTEST, primeroYUltimo) {
    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};

    pair<eph_h, eph_i> p = encuesta_prueba({
        {1, 1},     // 1.41
        {3, 5},     // 5.83
        {53, 5},    // 52.24
        {101, 21},  // 103.16
    });

    vector<int> res = {2, 0, 0, 1};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(p.first, p.second, centro, distancias));
}

TEST(histogramaDeAnillosConcentricosTEST, cuatroCuadrantes) {

    vector<int> distancias = {10, 20, 50, 100};

    pair<int, int> centro = {0, 0};

    pair<eph_h, eph_i> p = encuesta_prueba({
        {11, 11},
        {-11, -11},
        {-11, 11},
        {11, -11}
    });

    vector<int> res = {0, 4, 0, 0};

    EXPECT_EQ(res, histogramaDeAnillosConcentricos(p.first, p.second, centro, distancias));
}


pair<eph_h, eph_i> encuesta_prueba(vector<pair<int, int>> pos) {
    eph_h th = {{22114, 2020,   3,  319611, 629088, 3,  41, 0,  1,  3,  1,  2},
                {31117, 2020,   3,  332870, 642475, 3,  40, 0,  1,  6,  6,  2},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  1,  2,  2,  2},
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  2}};

    eph_i ti = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  10},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  10},
                {31117, 2020,   1,  0,  3,  1,  58, 1,  3,  22000,  1},
                {31117, 2020,   2,  0,  3,  2,  54, 1,  1,  -1,     1},
                {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   1},
                {31117, 2020,   5,  0,  3,  2,  15, 0,  0,  5000,   10},
                {31117, 2020,   6,  0,  3,  1,  7,  0,  0,  0,      10},
                {31117, 2020,   8,  0,  3,  2,  11, 0,  0,  0,      10},
                {31117, 2020,   9,  0,  3,  1,  50, 0,  2,  0,      10},
                {31117, 2020,   10, 0,  3,  1,  28, 1,  3,  5000,   1},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  10},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  10}};

    for(int i=0; i<pos.size(); i++) {
        th[i][HOGLATITUD] = pos[i].first;
        th[i][HOGLONGITUD] = pos[i].second;
    }

    return make_pair(th, ti);
}