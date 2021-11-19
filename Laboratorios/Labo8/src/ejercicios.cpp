#include "ejercicios.h"

using namespace std;

vector<string> split(string s, char delim) {
    vector<string> v;
    int i = 0;
    string palabra = "";
    while (i < s.size()) {
        if (s[i] != delim) {
            palabra += s[i];
        }
        if (s[i] == delim || i == s.size() - 1) {
            if (palabra.size() > 0) v.push_back(palabra);
            palabra = "";
        }
        i++;
    }
    return v;
}

string darVueltaPalabra(string s) {
    string res;
    vector<string> palabras = split(s, ' ');
    int i = palabras.size() - 1;
    while (i >= 0) {
        res += palabras[i];
        if (i > 0) res += " ";
        i--;
    }
    return res;
}

// Decidir si s1 es substring o subsecuencia de s2
bool subsecuencia(string s1, string s2) {
    int i = 0;
    int j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            i++;
        }
        j++;
    }
    return i == s1.size();
}

int cantidadApariciones(string s, char x) {
    int res = 0;
    int i = 0;
    while (i < s.size()) {
        if (s[i] == x) res++;
        i++;
    }
    return res;
}

bool esAnagrama(string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    bool res = true;
    int i = 0;
    while (i < s1.size()) {
        res = res && cantidadApariciones(s1, s1[i]) == cantidadApariciones(s2, s1[i]);
        i++;
    }
    return res;
}

// Mismo orden relativo de conjunto de anagramas y dentro de cada vector y con repetidos
vector<vector<string> > agruparAnagramas(vector<string> v) {
    vector<vector<string>> res;
    int i = 0;
    while (i < v.size()) {
        int j = 0;
        while (j < res.size() && !esAnagrama(res[j][0], v[i])) {
            j++;
        }
        if (j < res.size()) {
            res[j].push_back(v[i]);
        } else {
            res.push_back({v[i]});
        }
        i++;
    }
    return res;
}

bool esPalindromo(string s) {
    bool cumple = true;
    int i = 0;
    while (i < s.size() / 2) {
        cumple = cumple && s[i] == s[s.size() - i - 1];
        i++;
    }
    return cumple;
}

bool tieneRepetidos(string s) {
    if (s.size() <= 1) return false;
    int i = 0;
    int j = s.size();
    while (i < s.size() - 1 && j == s.size()) {
        j = i + 1;
        while (j < s.size() && s[i] != s[j]) {
            j++;
        }
        i++;
    }
    return j < s.size();
}

string rotar(string s, int j) {
    string res(s);
    int i = 0;
    while (i < s.size()) {
        res[i] = s[(s.size() - (j % s.size()) + i) % s.size()];
        i++;
    }
    return res;
}

// no se puede usar substring
string darVueltaK(string s, int k) {
    string res;
    int i = 0;
    while (i < s.size()) {
        int j = i + k - 1;
        if (j >= s.size()) j = s.size() - 1;
        while (j >= i) {
            res += s[j];
            j--;
        }
        i += k;
    }
    return res;
}

string abueloLaino(string s) {
    string res = "S";
    int i = 0;
    while (i < s.size()) {
        if (s[i] == 'i') res = 'N';
        i++;
    }
    return res;
}

int cantidadDeFelicitaciones(vector<string> v) {
    int c = 0; // Cantidad de "DR" autocontenidos dentro de cada palabra
    int rs = 0; // Cantidad de palabras que empiezan con R
    int de = 0; // Cantidad de palabras que terminan con D
    int i = 0;
    const char EMPTY = '-'; // Uso cualquier caracter (que no sea D o R) para representar un char "vacío"

    while (i < v.size()) {
        int j = 0;
        char a = EMPTY;
        char b = EMPTY;
        while (j < v[i].size()) {
            char x = v[i][j];
            if (x == 'D' || x == 'R') {
                b = x;
                if (a == EMPTY && b == 'R') rs++;
                if (a == 'D' && b == 'R') c++;
                a = b;
            }
            j++;
        }
        if (b == 'D') de++;
        i++;
    }

    // Cantidad de uniones posibles entre palabras
    int cu = rs <= de ? rs : de;

    return c + cu;
}

int middleOut(string s, string t) {
    int n = s.size();

    if (!esAnagrama(s, t)) {
        return -1;
    }

    int maxSub = 0;
    int i = 0;
    while (i < n) {
        int j = 0;
        int k = 0;
        int sub = 0;
        while (i + j < n && k < n) {
            if (s[i + j] == t[k]) {
                j++;
                k++;
                sub++;
            } else {
                if (j == 0) {
                    k++;
                } else {
                    j++;
                }
            }
        }
        if (sub > maxSub) {
            maxSub = sub;
        }
        i++;
    }

    return n - maxSub;
}
