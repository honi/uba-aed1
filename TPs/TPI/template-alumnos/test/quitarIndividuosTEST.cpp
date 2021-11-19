#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(quitarIndividuosTEST, SacaUnIndividuo) {
    eph_h th = {
        {22010,2020,3,319938,629513,1,41,0,1,4,3,2},
        {20101,2020,3,315773,625696,1,41,0,1,2,2,2},
    };

    eph_i ti = {
        {22010,2020,1,0,3,1,65,1,2,15000,8},
        {22010,2020,7,0,3,2,22,0,0,10000,10},
        {22010,2020,9,0,3,1,9,0,0,0,10},
        {22010,2020,10,0,3,2,9,0,0,0,10},
        {22010,2020,11,0,3,2,2,0,0,0,10},
        {22010,2020,12,0,3,2,17,0,0,0,10},
        {20101,2020,1,0,3,2,46,1,3,3900,0},
        {20101,2020,2,0,3,1,24,0,3,6000,10},
    };

    vector<pair<int, dato>> busqueda = {
        {PP04G, 8},
        {COMPONENTE, 1}
    };

    eph_h th0 = th;
    eph_i ti0 = ti;

    pair<eph_h, eph_i> res = quitarIndividuos(ti, th, busqueda);

    hogar h = {22010,2020,3,319938,629513,1,41,0,1,4,3,2};
    individuo ind = {22010,2020,1,0,3,1,65,1,2,15000,8};

    EXPECT_EQ(1, res.first.size());
    EXPECT_EQ(1, res.second.size());

    EXPECT_EQ(h, res.first[0]);
    EXPECT_EQ(ind, res.second[0]);

    EXPECT_EQ(th0, th);

    ti.insert(ti.begin(), ind);
    EXPECT_EQ(ti0, ti);
}

TEST(quitarIndividuosTEST, SacaTodosIndividuos) {
    eph_h th = {
        {22010,2020,3,319938,629513,1,41,0,1,4,3,2},
        {20101,2020,3,315773,625696,1,41,0,1,2,2,2},
    };

    eph_i ti = {
        {22010,2020,1,0,3,1,65,1,2,15000,8},
        {22010,2020,7,0,3,2,22,0,0,10000,10},
        {22010,2020,9,0,3,1,9,0,0,0,10},
        {22010,2020,10,0,3,2,9,0,0,0,10},
        {22010,2020,11,0,3,2,2,0,0,0,10},
        {22010,2020,12,0,3,2,17,0,0,0,10},
        {20101,2020,1,0,3,2,46,1,3,3900,0},
        {20101,2020,2,0,3,1,24,0,3,6000,10},
    };

    vector<pair<int, dato>> busqueda = {
        {INDCODUSU, 22010}
    };

    pair<eph_h, eph_i> res = quitarIndividuos(ti, th, busqueda);

    EXPECT_EQ(1, res.first.size());
    EXPECT_EQ(6, res.second.size());

    EXPECT_EQ(1, th.size());
    EXPECT_EQ(2, ti.size());
}
