#include "gtest/gtest.h"
#include <vector>
#include "../src/cuboDeUnos.cpp"

using namespace std;

TEST(cuboDeUnos, todosUnos) {
    vector<vector<vector<int>>> s = {
            {
                    {1, 1, 1},
                    {1, 1, 1},
            },
            {
                    {1, 1, 1},
                    {1, 1, 1},
            },
            {
                    {1, 1, 1},
                    {1, 1, 1},
            },
            {
                    {1, 1, 1},
                    {1, 1, 1},
            },
    };
    auto vertice = cuboDeUnos(s);
    ASSERT_EQ(vertice, make_tuple(0, 0, 0));
}

TEST(cuboDeUnos, casoGeneral) {
    vector<vector<vector<int>>> s = {
            {
                    {0, 0, 0},
                    {0, 0, 0},
            },
            {
                    {0, 0, 0},
                    {0, 0, 0},
            },
            {
                    {0, 1, 1},
                    {0, 1, 1},
            },
            {
                    {0, 1, 1},
                    {0, 1, 1},
            },
    };
    auto vertice = cuboDeUnos(s);
    ASSERT_EQ(vertice, make_tuple(2, 0, 1));
}

TEST(cuboDeUnos, unUnicoUno) {
    vector<vector<vector<int>>> s = {
            {
                    {0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0},
            },
            {
                    {0, 0, 0},
                    {0, 1, 0},
                    {0, 0, 0},
            },
            {
                    {0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0},
            },
    };
    auto vertice = cuboDeUnos(s);
    ASSERT_EQ(vertice, make_tuple(1, 1, 1));
}