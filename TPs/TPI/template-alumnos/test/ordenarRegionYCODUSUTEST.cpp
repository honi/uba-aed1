#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "../auxiliares.h"

using namespace std;


TEST(ordenarRegionYCODUSUTEST, regionesDistintas) {

    eph_h th = {
        {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
        {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
    };

    eph_i ti = {
        {334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
        {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
        {960,  2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
        {960,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6}
    };

    eph_h th_esperado = {
        {960,  2017, 1, 1, 1, 0, 1, 4, 1, 2},
        {334,  2017, 1, 1, 2, 0, 1, 3, 1, 2},
    };

    eph_i ti_esperado = {
        {960,  1, 2017, 1, 0, 2, 19, 0,  0, 0,     6},
        {960,  2, 2017, 1, 0, 2, 20, 1,  3, 7000,  1},
        {960,  3, 2017, 1, 1, 2, 51, 1,  4, 1280,  1},
        {334,  1, 2017, 1, 0, 1, 36, 1,  3, 16300, 1},
    };


    ordenarRegionYCODUSU(th, ti);
    EXPECT_EQ(th_esperado, th);
    EXPECT_EQ(ti_esperado, ti);

}
