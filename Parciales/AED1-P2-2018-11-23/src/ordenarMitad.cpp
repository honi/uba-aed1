#include <vector>

using namespace std;

/*
 s0 = {2,4,3,7,6,8,5,1}
 s  = {2,3,4,7,6,5,8,1}
*/

void ordenarMitad(vector<int> &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        int indiceSwap = i;
        for (int j = i + 1; j < n / 2; j++) {
            if (s[j] < s[i]) {
                indiceSwap = j;
            }
        }
        if (indiceSwap != i) {
            swap(s[i], s[indiceSwap]);
            swap(s[n / 2 + i], s[n / 2 + indiceSwap]);
        }
    }
}
