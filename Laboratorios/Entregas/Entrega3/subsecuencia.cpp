#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s, string t) {
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s.size();
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;
    
    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

