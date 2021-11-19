#include "gtest/gtest.h"
#include <vector>
#include "../src/situacionComica.cpp"

using namespace std;

TEST(situacionComica, todosRiendo) {
    mapa m = {
            {{1, 0}, {1, 0}, {1, 0}},
            {{1, 0}, {1, 0}, {1, 0}},
            {{1, 0}, {1, 0}, {1, 0}},
    };
    int riendo = 0;
    int aburridos = 0;
    int nuncaEscucharon = 0;
    situacionComica(m, riendo, aburridos, nuncaEscucharon);
    ASSERT_EQ(riendo, 9);
    ASSERT_EQ(aburridos, 0);
    ASSERT_EQ(nuncaEscucharon, 0);
}

TEST(situacionComica, todosAburridos) {
    mapa m = {
            {{0, 1}, {0, 1}, {0, 1}},
            {{0, 1}, {0, 1}, {0, 1}},
            {{0, 1}, {0, 1}, {0, 1}},
    };
    int riendo = 0;
    int aburridos = 0;
    int nuncaEscucharon = 0;
    situacionComica(m, riendo, aburridos, nuncaEscucharon);
    ASSERT_EQ(riendo, 0);
    ASSERT_EQ(aburridos, 9);
    ASSERT_EQ(nuncaEscucharon, 0);
}

TEST(situacionComica, nadieEscucho) {
    mapa m = {
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    int riendo = 0;
    int aburridos = 0;
    int nuncaEscucharon = 0;
    situacionComica(m, riendo, aburridos, nuncaEscucharon);
    ASSERT_EQ(riendo, 0);
    ASSERT_EQ(aburridos, 0);
    ASSERT_EQ(nuncaEscucharon, 9);
}

TEST(situacionComica, deTodoUnPoco) {
    mapa m = {
            {{1, 0}, {1, 0}, {1, 0}},
            {{0, 1}, {0, 1}, {0, 1}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    int riendo = 0;
    int aburridos = 0;
    int nuncaEscucharon = 0;
    situacionComica(m, riendo, aburridos, nuncaEscucharon);
    ASSERT_EQ(riendo, 3);
    ASSERT_EQ(aburridos, 3);
    ASSERT_EQ(nuncaEscucharon, 3);
}