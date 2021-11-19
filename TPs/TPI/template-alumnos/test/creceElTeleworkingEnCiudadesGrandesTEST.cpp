#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace std;

TEST(creceElTeleworkingEnCiudadesGrandesTEST, crece) {


//                                                        +500  Tipo       Lugar para trabajar
//                                                           v   v           v
    eph_h t1h = {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2}, // Esta no: Sin lugar para trabajar
                {31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                {22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},// Esta no: Hotel
                {20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1}};// Esta no: menos 500

//                                                                   Ubicación
//                                                                   v
    eph_i t1i = {{20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6}, // Esta no: Hotel
                {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
                {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};


//                                                        +500  Tipo       Lugar para trabajar
//                                                           v   v           v
    eph_h t2h = {{22114, 2020,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2}, // Esta no: Sin lugar para trabajar
                {31117, 2020,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                {22866, 2020,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},// Esta no: Hotel
                {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1}};// Esta no: menos 500

    eph_i t2i = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6}, // Esta no: Hotel
                {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                {31117, 2020,   5,  0,  3,  2,  15, 1,  0,  5000,   6},
                {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};

    EXPECT_TRUE(esEncuestaValida(t1h, t1i));
    EXPECT_TRUE(esEncuestaValida(t2h, t2i));

    EXPECT_EQ( true, creceElTeleworkingEnCiudadesGrandes(t1h, t1i, t2h, t2i) );
}


TEST(creceElTeleworkingEnCiudadesGrandesTEST, nocrece) {

//                                                        +500  Tipo       Lugar para trabajar
//                                                           v   v           v
    eph_h t1h = {{22114, 2018,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2}, // Esta no: Sin lugar para trabajar
                 {31117, 2018,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                 {22866, 2018,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},// Esta no: Hotel
                 {20957, 2018,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1}};// Esta no: menos 500

//                                                                   Ubicación
//                                                                   v
    eph_i t1i = {{20957, 2018,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                 {20957, 2018,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                 {22866, 2018,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                 {22866, 2018,   2,  1,  3,  2,  28, 1,  3,  0,      6}, // Esta no: Hotel
                 {31117, 2018,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                 {31117, 2018,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                 {31117, 2018,   5,  0,  3,  2,  15, 0,  0,  5000,   1},
                 {22114, 2018,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};


//                                                        +500  Tipo       Lugar para trabajar
//                                                           v   v           v
    eph_h t2h = {{22114, 2020,   3,  319611, 629088, 3,  41, 1,  1,  3,  1,  2}, // Esta no: Sin lugar para trabajar
                 {31117, 2020,   3,  332870, 642475, 3,  40, 1,  1,  6,  6,  1},
                 {22866, 2020,   3,  317157, 627217, 2,  42, 1,  3,  2,  2,  1},// Esta no: Hotel
                 {20957, 2020,   3,  313965, 623297, 1,  43, 0,  1,  3,  1,  1}};// Esta no: menos 500

    eph_i t2i = {{20957, 2020,   1,  1,  3,  1,  88, 0,  0,  90000,  1},
                 {20957, 2020,   2,  1,  3,  2,  82, 0,  0,  25000,  1},
                 {22866, 2020,   1,  0,  3,  1,  31, 1,  3,  59000,  1},
                 {22866, 2020,   2,  1,  3,  2,  28, 1,  3,  0,      6}, // Esta no: Hotel
                 {31117, 2020,   3,  0,  3,  2,  46, 1,  3,  17000,  1},
                 {31117, 2020,   4,  0,  3,  1,  20, 1,  3,  5000,   6},
                 {31117, 2020,   5,  0,  3,  2,  15, -1,  0,  5000,   6}, // estado no informado
                 {22114, 2020,   1,  0,  3,  1,  18, 0,  0,  20000,  1}};

    EXPECT_EQ( false, creceElTeleworkingEnCiudadesGrandes(t1h, t1i, t2h, t2i) );
}

TEST(creceElTeleworkingEnCiudadesGrandesTEST, eph2016a2018) {
    eph_h t1h;
    eph_i t1i;
    leerEncuesta ( "eph_3c_2018_1000", t1h, t1i );

    eph_h t2h;
    eph_i t2i;
    leerEncuesta ( "eph_3c_2020_1000", t2h, t2i );

    EXPECT_EQ( true, creceElTeleworkingEnCiudadesGrandes(t1h, t1i, t2h, t2i) );
}
