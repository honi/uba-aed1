#include <vector>

using namespace std;

/*
 i = 0
 subseq(s, 0, 8) = subseq(s0, 0, 8)
 suma = 0

 i = 1
 subseq(s, 2, 6) = subseq(s0, 2, 6)
 s[0] = s[1] = 0
 s[6] = s[7] = 0
 suma = s[0] + s[1] + s[6] + s[7]
*/

void cerearYSumar(vector<int> &s, int &suma) {
    suma = 0;
    int n = s.size();
    int i = 0;
    while (i < n / 4) {
        vector<int> indices = {
                2 * i,
                2 * i + 1,
                n - 1 - 2 * i,
                n - 1 - (2 * i + 1),
        };

        for (int j = 0; j < indices.size(); j++) {
            suma += s[indices[j]];
            s[indices[j]] = 0;
        }

        i++;
    }
}
