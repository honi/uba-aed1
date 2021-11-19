#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j) {
    string res(s);
    int i = 0;
    while (i < s.size()) {
        res[i] = s[(s.size() - (j % s.size()) + i) % s.size()];
        i++;
    }
    return res;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;
    
    string res = rotar(s, j);
    cout << res;
    return 0;
}
