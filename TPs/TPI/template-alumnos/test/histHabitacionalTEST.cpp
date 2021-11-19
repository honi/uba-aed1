#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(histHabitacionalTEST, vectorLargo4) {

//                                          Región  #Habitaciones
//                                            v      v
    eph_h th = {{22010,2020,3,319938,629513,1,41,0,1,4,3,2},
                {20101,2020,3,315773,625696,1,41,0,1,2,2,2},
                {20089,2020,3,315920,625586,1,41,0,1,2,1,2},
                {31281,2020,3,332103,642547,2,40,0,1,1,1,2}, // esta es de otra region
                {18229,2020,3,326496,636045,3,41,0,1,3,2,2},
                {20984,2020,3,314623,624502,1,41,0,1,4,3,2},
                {20650,2020,3,315426,625486,1,41,0,1,4,2,2}};

    eph_i ti = {{22010,2020,1,0,3,1,65,1,2,15000,8},
                {22010,2020,7,0,3,2,22,0,0,10000,10},
                {22010,2020,9,0,3,1,9,0,0,0,10},
                {22010,2020,10,0,3,2,9,0,0,0,10},
                {22010,2020,11,0,3,2,2,0,0,0,10},
                {22010,2020,12,0,3,2,17,0,0,0,10},
                {20101,2020,1,0,3,2,46,1,3,3900,0},
                {20101,2020,2,0,3,1,24,0,3,6000,10},
                {20089,2020,1,0,3,1,76,0,0,16000,10},
                {20089,2020,2,0,3,2,72,0,0,16000,10},
                {31281,2020,1,0,3,2,29,1,2,14300,8},
                {31281,2020,2,0,3,2,5,0,0,0,10},
                {18229,2020,1,0,3,2,31,1,1,34000,1},
                {18229,2020,2,0,3,1,33,1,1,20000,4},
                {18229,2020,5,0,3,2,4,0,0,0,10},
                {20984,2020,1,0,3,1,31,1,2,15000,8},
                {20984,2020,2,0,3,2,28,0,0,19560,10},
                {20984,2020,4,0,3,1,5,0,0,0,10},
                {20650,2020,1,0,3,2,58,0,0,8000,10},
                {20650,2020,2,0,3,2,33,0,0,7000,10},
                {20650,2020,7,0,3,1,7,0,0,0,10},
                {20650,2020,8,0,3,1,5,0,0,0,10}};

    if (!esEncuestaValida(th,ti)) {
        ASSERT_TRUE(esEncuestaValida(th,ti));
    }
    else {
        vector<int> resultado_esperado = {0, 2, 1, 3};
        EXPECT_EQ( resultado_esperado, histHabitacional(th, ti, 41) );
    }

}

TEST(histHabitacionalTEST, eph2020_CUYO) {
    eph_h th;
    eph_i ti;
    leerEncuesta ( "eph_3c_2020_100", th, ti );

    vector<int> resultado_esperado = { 0, 1, 1, 2, 1, 1 };
    EXPECT_EQ( resultado_esperado, histHabitacional(th, ti, 42) );
}

TEST(histHabitacionalTEST, eph2020_PAMPA) {
    eph_h th;
    eph_i ti;
    leerEncuesta ( "eph_3c_2020_100", th, ti );

    vector<int> resultado_esperado = { 4, 10, 9, 5, 1 };
    EXPECT_EQ( resultado_esperado, histHabitacional(th, ti, 43) );
}

TEST(histHabitacionalTEST, eph2020_PATAGONIA) {
    eph_h th;
    eph_i ti;
    leerEncuesta ( "eph_3c_2020_100", th, ti );


    vector<int> resultado_esperado = { 2, 3, 5, 6 };
    EXPECT_EQ( resultado_esperado, histHabitacional(th, ti, 44) );
}
