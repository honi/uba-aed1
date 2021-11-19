#include "gtest/gtest.h"
#include <vector>
#include "../src/cerearYSumar.cpp"

using namespace std;

TEST(cerearYSumar, happyPath) {
    vector<int> s = {1, 2, 3, 4, 5, 6, 7, 8};
    int suma;
    cerearYSumar(s, suma);
    ASSERT_EQ(s, vector<int>({0, 0, 0, 0, 0, 0, 0, 0}));
    ASSERT_EQ(suma, 36);
}

TEST(cerearYSumar, vacio) {
    vector<int> s = {};
    int suma;
    cerearYSumar(s, suma);
    ASSERT_EQ(s, vector<int>({}));
    ASSERT_EQ(suma, 0);
}