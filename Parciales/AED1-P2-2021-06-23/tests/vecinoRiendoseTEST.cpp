#include "gtest/gtest.h"
#include <vector>
#include "../src/vecinoRiendose.cpp"

using namespace std;

TEST(vecinoRiendose, happyPath) {
    mapa m = {
            {{0, 0}, {1, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
            {{0, 0}, {0, 0}, {0, 0}},
    };
    ASSERT_TRUE(vecinoRiendose(m, {1, 1}));
    ASSERT_FALSE(vecinoRiendose(m, {2, 0}));
}