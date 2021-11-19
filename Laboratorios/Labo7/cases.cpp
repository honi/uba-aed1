#include <iostream>
#include "ejercicios.h"
#include "gtest/gtest.h"

using namespace std;


//////// Ejercicio 1 ////////////////
TEST(ProductoVectorial, Test1) {
    vector<int> u = {2,3,4};
    vector<int> v = {4,3,2};
    vector<vector<int>> expected = {
            {8,  6,  4},
            {12,  9,  6},
            {16, 12,  8}
    };
    vector<vector<int>> real = productoVectorial(u,v);
    ASSERT_EQ(expected, real);
}

TEST(ProductoVectorial, Test2) {
    vector<int> u = {6,7,8,9};
    vector<int> v = {1,2,3};
    vector<vector<int>> expected = {
            { 6, 12, 18},
            {7, 14, 21},
            {8, 16, 24},
            {9, 18, 27}
    };
    vector<vector<int>> real = productoVectorial(u,v);
    ASSERT_EQ(expected, real);
}

TEST(ProductoVectorial, Test3) {
    vector<int> u = {6};
    vector<int> v = {2};
    vector<vector<int>> expected = {
            {12}
    };
    vector<vector<int>> real = productoVectorial(u,v);
    ASSERT_EQ(expected, real);
}

////// Ejercicio 2 ////////////////
TEST(Trasponer, Test1)  {
	vector<vector<int>> vec(4,vector<int>(4,0)), res(4,vector<int>(4,0));
	vec[0][1] = res[1][0] = 1;
	vec[0][2] = res[2][0] = 2;
	vec[0][3] = res[3][0] = 3;
    vec[1][0] = res[0][1] = 8;
	vec[1][2] = res[2][1] = 4;
	vec[1][3] = res[3][1] = 5;
    vec[2][0] = res[0][2] = 0;
    vec[2][1] = res[1][2] = 15;
	vec[2][3] = res[3][2] = 6;
    vec[3][0] = res[0][3] = 4;
    vec[3][1] = res[1][3] = 13;
    vec[3][2] = res[2][3] = 10;
	vec[0][0] = res[0][0] = vec[1][1] = res[1][1] = 10;
	vec[2][2] = res[2][2] = vec[3][3] = res[3][3] = 20;
	trasponer(vec);
    ASSERT_EQ(vec, res);
}

TEST(Trasponer, Test2) {
	vector<vector<int>> vec(5,vector<int>(5));
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			vec[i][j] = i+j;
		}
	}
	vector<vector<int>> res = vec;
	trasponer(vec);
    ASSERT_EQ(vec, res);
}

TEST(Trasponer, Test3) {
	vector<vector<int>> vec(6,vector<int>(6)), res(6,vector<int>(6));
	for(int i=0;i<6;i++) {
		for(int j=0;j<=i;j++) {
			vec[i][j] = (i*13+j*17)%19;
			res[j][i] = vec[i][j];
		}
	}
	trasponer(vec);
    ASSERT_EQ(vec, res);
}

//////// Ejercicio 3 ////////////////
TEST(Multiplicar, Test1) {
	vector<vector<int>> m1(3,vector<int>(4)), m2(4,vector<int>(5)), res(3,vector<int>(5));
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[0][2] = 3;
	m1[0][3] = 4;
	m1[1][0] = 5;
	m1[1][1] = 6;
	m1[1][2] = 7;
	m1[1][3] = 8;
	m1[2][0] = 9;
	m1[2][1] = 10;
	m1[2][2] = 11;
	m1[2][3] = 12;

	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[0][2] = 3;
	m2[0][3] = 1;
	m2[0][4] = 2;
	m2[1][0] = 3;
	m2[1][1] = 1;
	m2[1][2] = 2;
	m2[1][3] = 3;
	m2[1][4] = 1;
	m2[2][0] = 2;
	m2[2][1] = 3;
	m2[2][2] = 1;
	m2[2][3] = 2;
	m2[2][4] = 3;
	m2[3][0] = 1;
	m2[3][1] = 2;
	m2[3][2] = 3;
	m2[3][3] = 1;
	m2[3][4] = 2;

	res[0][0] = 17;
	res[0][1] = 21;
	res[0][2] = 22;
	res[0][3] = 17;
	res[0][4] = 21;

	res[1][0] = 45;
	res[1][1] = 53;
	res[1][2] = 58;
	res[1][3] = 45;
	res[1][4] = 53;

	res[2][0] = 73;
	res[2][1] = 85;
	res[2][2] = 94;
	res[2][3] = 73;
	res[2][4] = 85;

    EXPECT_EQ(multiplicar(m1,m2), res);
}

TEST(Multiplicar, Test2) {
	vector<vector<int>> m1(5,vector<int>(5,0)), m2(5,vector<int>(5)), res;
	m1[0][0] = m1[1][1] = m1[2][2] = m1[3][3] = m1[4][4] = 1;
	m2[0][0] = 1;
	m2[0][1] = 2;
	m2[0][2] = 3;
	m2[0][3] = 1;
	m2[0][4] = 2;
	m2[1][0] = 3;
	m2[1][1] = 1;
	m2[1][2] = 2;
	m2[1][3] = 3;
	m2[1][4] = 1;
	m2[2][0] = 2;
	m2[2][1] = 3;
	m2[2][2] = 1;
	m2[2][3] = 2;
	m2[2][4] = 3;
	m2[3][0] = 1;
	m2[3][1] = 2;
	m2[3][2] = 3;
	m2[3][3] = 1;
	m2[3][4] = 2;
	m2[4][0] = 1;
	m2[4][1] = 2;
	m2[4][2] = 3;
	m2[4][3] = 1;
	m2[4][4] = 2;

	res = m2;
    EXPECT_EQ(multiplicar(m1,m2), res);
}

//////// Ejercicio 4 ////////////////
TEST(Promediar, Test1) {
	vector<vector<int>> vec(5,vector<int>(5,0));
	for(int i=0;i<5;i++) {
		vec[i][i] = 10*(i+1);
	}

	vector<vector<int>> res(5,vector<int>(5,0));
	res[0][0] = res[2][3] = res[3][2] = 7;
	res[0][1] = res[1][0] = res[1][2] = res[2][1] = 5;
	res[0][2] = res[2][0] = res[1][3] = res[3][1] = 3;
	res[1][1] = res[2][4] = res[4][2] = 6;
	res[2][2] = 10;
	res[3][3] = 13;
	res[3][4] = res[4][3] = 15;
	res[4][4] = 22;

    ASSERT_EQ(promediar(vec), res);
}

TEST(Promediar, Test2) {
	vector<vector<int>> vec(5,vector<int>(5,0)),res(5,vector<int>(5,1));
	for(int i=0;i<5;i++) {
		for(int j=0;j<5;j++) {
			if(i%2==j%2) {
				vec[i][j] = 2;
			}
		}
	}
	res[1][2] = res[3][2] = res[2][1] = res[2][3] = 0;
    ASSERT_EQ(promediar(vec), res);
}

//////// Ejercicio 5 ////////////////
TEST(ContarPicos, Test1) {
	vector<vector<int>> vec(10,vector<int>(10));
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			vec[i][j] = ((1<<i)*((j+10)*41))%13;
		}
	}
    ASSERT_EQ(contarPicos(vec), 8);
}

TEST(ContarPicos, Test2) {
	vector<vector<int>> vec(20,vector<int>(40,0));
	for(int i=0;i<10;i++) {
		for(int j=0;j<20;j++) {
			vec[2*i][2*j] = 1;
		}
	}
    ASSERT_EQ(contarPicos(vec), 200);
}

//////// Ejercicio 6 ////////////////
TEST(EsTriangular, Test1) {
    vector<vector<int>> m = {
            {1,2,0,4},
            {0,2,0,0},
            {0,0,3,4},
            {0,0,0,4}
        };
    ASSERT_EQ(esTriangular(m), true);
}

TEST(EsTriangular, Test2) {
    vector<vector<int>> m = {
            {1,0,0,0},
            {0,2,0,0},
            {0,8,3,0},
            {0,0,0,4}
    };
    ASSERT_EQ(esTriangular(m), true);
}

TEST(EsTriangular, Test3) {
    vector<vector<int>> m = {
            {1,0,0,0},
            {0,2,3,0},
            {0,0,3,0},
            {1,0,0,0}
    };
    ASSERT_EQ(esTriangular(m), false);
}

TEST(EsTriangular, Test4) {
    vector<vector<int>> m = {
            {0,0,0,4},
            {0,0,0,0},
            {0,0,0,0},
            {1,0,0,0}
    };
    ASSERT_EQ(esTriangular(m), false);
}

TEST(EsTriangular, Test5) {
    vector<vector<int>> m = {
            {1,8},
            {0,2},
    };
    ASSERT_EQ(esTriangular(m), true);
}

////////// Ejercicio 7 ////////////////
TEST(HayAmenaza, Test1)  {
	vector<vector<int>> vec(8,vector<int>(8,0));
	vec[0][2] = vec[1][5] = vec[2][3] = vec[3][0] = vec[4][7] = vec[5][4] = vec[6][6] = vec[7][1] = 1;
    ASSERT_EQ(hayAmenaza(vec), 0);
}

TEST(HayAmenaza, Test2)  {
	vector<vector<int>> vec(8,vector<int>(8,0));
	vec[0][2] = vec[1][5] = vec[2][3] = vec[3][0] = vec[4][7] = vec[5][1] = vec[6][6] = vec[7][4] = 1;
    ASSERT_EQ(hayAmenaza(vec), 1);
}

TEST(HayAmenaza, Test3) {
	vector<vector<int>> vec(3,vector<int>(4,0));
	vec[0][0] = vec[1][3] = vec[2][1] = 1;
    ASSERT_EQ(hayAmenaza(vec), 0);
}

TEST(HayAmenaza, Test4) {
	vector<vector<int>> vec(3,vector<int>(4,0));
	vec[0][0] = vec[2][3] = vec[2][1] = 1;
    ASSERT_EQ(hayAmenaza(vec), 1);
}

TEST(HayAmenaza, Test5) {
	vector<vector<int>> vec(3,vector<int>(4,0));
	vec[0][0] = vec[1][3] = vec[2][3] = 1;
    ASSERT_EQ(hayAmenaza(vec), 1);
}

//////// Ejercicio 8 ////////////////
TEST(DiferenciaDiagonales, Test1) {
    vector<vector<int>> m = {
            {10,2,3,4},
            {5,10,7,8},
            {10,9,8,7},
            {4,0,0,1}
    };
    ASSERT_EQ(diferenciaDiagonales(m), 5);
}

TEST(DiferenciaDiagonales, Test2) {
    vector<vector<int>> m = {
            {1,2,3,4},
            {5,6,7,8},
            {10,9,8,7},
            {0,0,0,1}
    };
    ASSERT_EQ(diferenciaDiagonales(m), 4);
}

TEST(DiferenciaDiagonales, Test3) {
    vector<vector<int>> m = {
            {1,2,3,1},
            {5,2,2,8},
            {10,3,3,7},
            {4,0,0,4}
    };
    ASSERT_EQ(diferenciaDiagonales(m), 0);
}

TEST(DiferenciaDiagonales, Test4) {
    vector<vector<int>> m = {
            {-1,2,3,-4},
            {5,-6,7,8},
            {1,-9,-8,7},
            {0,0,0,1}
    };
    ASSERT_EQ(diferenciaDiagonales(m), 8);
}

TEST(DiferenciaDiagonales, Test5) {
    vector<vector<int>> m = {
            {-1,2},
            {6,-6}
    };
    ASSERT_EQ(diferenciaDiagonales(m), 1);
}

TEST(DiferenciaDiagonales, Test6) {
    vector<vector<int>> m = {
            {-1}
    };
    ASSERT_EQ(diferenciaDiagonales(m), 0);
}