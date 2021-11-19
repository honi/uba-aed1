#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(quitarIndividuosTEST, SacaUnIndividuoHogaresSinModificacion) {
    eph_h th = {
            {22010, 2020, 3, 319938, 629513, 1, 41, 0, 1, 4, 3, 2},
            {20101, 2020, 3, 315773, 625696, 1, 41, 0, 1, 2, 2, 2},
    };

    eph_i ti = {
            {22010, 2020, 1,  0, 3, 1, 65, 1, 2, 15000, 8}, // este se borra
            {22010, 2020, 7,  0, 3, 2, 22, 0, 0, 10000, 10},
            {22010, 2020, 9,  0, 3, 1, 9,  0, 0, 0,     10},
            {22010, 2020, 10, 0, 3, 2, 9,  0, 0, 0,     10},
            {22010, 2020, 11, 0, 3, 2, 2,  0, 0, 0,     10},
            {22010, 2020, 12, 0, 3, 2, 17, 0, 0, 0,     10},
            {20101, 2020, 1,  0, 3, 2, 46, 1, 3, 3900,  0},  // este no se borra, que tiene el mismo nro de componente
            {20101, 2020, 2,  0, 3, 1, 24, 0, 3, 6000,  10},
    };

    EXPECT_TRUE(esEncuestaValida(th, ti));

    vector<pair<int, dato>> busqueda = {
            {PP04G,      8},
            {COMPONENTE, 1}
    };

    eph_h th0 = eph_h(th);
    eph_i ti0 = eph_i(ti);

    pair<eph_h, eph_i> res = quitarIndividuos(ti, th, busqueda);

    eph_h th_res = {{22010, 2020, 3, 319938, 629513, 1, 41, 0, 1, 4, 3, 2}};
    eph_i ti_res = {{22010, 2020, 1, 0, 3, 1, 65, 1, 2, 15000, 8}};
    //verificacion de salida
    EXPECT_EQ(th_res, res.first);
    EXPECT_EQ(ti_res, res.second);

    // verificacion de encuesta resultante
    EXPECT_TRUE(esEncuestaValida(th, ti));
    ti0.erase(ti0.begin()); // borro el primer elemento que era el que cumplia el criterio
    // ordeno para que no importe el orden
    sort(th.begin(), th.end());
    sort(ti.begin(), ti.end());

    sort(th0.begin(), th0.end());
    sort(ti0.begin(), ti0.end());

    EXPECT_EQ(th, th0);
    EXPECT_EQ(ti, ti0);

}

TEST(quitarIndividuosTEST, SacaTodosIndividuosYHogarVacio) {
    eph_h th = {
            {22010, 2020, 3, 319938, 629513, 1, 41, 0, 1, 4, 3, 2},
            {20101, 2020, 3, 315773, 625696, 1, 41, 0, 1, 2, 2, 2},
    };

    eph_i ti = {
            {22010, 2020, 1,  0, 3, 1, 65, 1, 2, 15000, 8},
            {22010, 2020, 7,  0, 3, 2, 22, 0, 0, 10000, 10},
            {22010, 2020, 9,  0, 3, 1, 9,  0, 0, 0,     10},
            {22010, 2020, 10, 0, 3, 2, 9,  0, 0, 0,     10},
            {22010, 2020, 11, 0, 3, 2, 2,  0, 0, 0,     10},
            {22010, 2020, 12, 0, 3, 2, 17, 0, 0, 0,     10},
            {20101, 2020, 1,  0, 3, 2, 46, 1, 3, 3900,  0},
            {20101, 2020, 2,  0, 3, 1, 24, 0, 3, 6000,  10},
    };

    vector<pair<int, dato>> busqueda = {
            {INDCODUSU, 22010}
    };


    eph_h th_res = {
            {22010, 2020, 3, 319938, 629513, 1, 41, 0, 1, 4, 3, 2}
    };

    eph_i ti_res = {
            {22010, 2020, 1,  0, 3, 1, 65, 1, 2, 15000, 8},
            {22010, 2020, 7,  0, 3, 2, 22, 0, 0, 10000, 10},
            {22010, 2020, 9,  0, 3, 1, 9,  0, 0, 0,     10},
            {22010, 2020, 10, 0, 3, 2, 9,  0, 0, 0,     10},
            {22010, 2020, 11, 0, 3, 2, 2,  0, 0, 0,     10},
            {22010, 2020, 12, 0, 3, 2, 17, 0, 0, 0,     10}
    };

    eph_h th_out = {
            {20101, 2020, 3, 315773, 625696, 1, 41, 0, 1, 2, 2, 2}
    };

    eph_i ti_out = {
            {20101, 2020, 2, 0, 3, 1, 24, 0, 3, 6000, 10},
            {20101, 2020, 1, 0, 3, 2, 46, 1, 3, 3900, 0},
    };

    pair<eph_h, eph_i> res = quitarIndividuos(ti, th, busqueda);

    // verificacion de encuesta resultante
    EXPECT_TRUE(esEncuestaValida(th, ti));
    //verificacion de salida de hogares (un solo elemento)
    EXPECT_EQ(th_res, res.first);
    EXPECT_EQ(th_out, th);

    // verificacion de salida de individuos (varios elementos)
    // ordeno para que no importe el orden
    sort(ti_out.begin(), ti_out.end());

    EXPECT_EQ(ti, ti_out);
}
