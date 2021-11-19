#include <vector>

using namespace std;

tuple<int, int, int> cuboDeUnos(vector<vector<vector<int>>> s) {
    int N = s.size();
    int M = s[0].size();
    int T = s[0][0].size();
    int L = min({N, M, T});
    for (int l = L; l >= 1; l--) {
        for (int n = 0; n <= N - l; n++) {
            for (int m = 0; m <= M - l; m++) {
                for (int t = 0; t <= T - l; t++) {
                    bool todosUnos = true;
                    for (int i = n; i < n + l; i++) {
                        for (int j = m; j < m + l; j++) {
                            for (int k = t; k < t + l; k++) {
                                todosUnos &= s[i][j][k] == 1;
                            }
                        }
                    }
                    if (todosUnos) {
                        return make_tuple(n, m, t);
                    }
                }
            }
        }
    }
}
