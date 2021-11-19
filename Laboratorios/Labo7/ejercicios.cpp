#include "ejercicios.h"

vector<vector<int>> productoVectorial(vector<int> u, vector<int> v) {
	vector<vector<int>> res;
	for (int i=0; i < u.size(); i++) {
	    vector<int> fila;
	    for (int j=0; j < v.size(); j++) {
	        fila.push_back(u[i] * v[j]);
	    }
	    res.push_back(fila);
	}
	return res;
}

void trasponer(vector<vector<int>> &m) {
    vector<vector<int>> res(m.size(), vector<int>(m.size()));
    for (int i=0; i < m.size(); i++) {
        for (int j=0; j < m[i].size(); j++) {
            res[j][i] = m[i][j];
        }
    }
    m = res;
}

vector<vector<int>> multiplicar(vector<vector<int>> m1, vector<vector<int>> m2) {
	vector<vector<int>> res(m1.size(), vector<int>());
	for (int i=0; i < m1.size(); i++) {
	    for (int j=0; j < m2[0].size(); j++) {
            int x = 0;
	        for (int k=0; k < m1[i].size(); k++) {
	            x += m1[i][k] * m2[k][j];
	        }
            res[i].push_back(x);
	    }
    }
	return res;
}

vector<vector<int>> promediar(vector<vector<int>> m) {
	vector<vector<int>> res(m.size(), vector<int>(m[0].size()));
	for (int i = 0; i < m.size(); i++) {
	    for (int j = 0; j < m[i].size(); j++) {
	        res[i][j] = m[i][j];
	        int vecinos = 1;
	        for (int k = i-1; k <= i+1; k++) {
	            for (int l = j-1; l <= j+1; l++) {
	                if (k >= 0 && k < m.size() && l >= 0 && l < m[i].size() && !(k == i && l == j)) {
	                    res[i][j] += m[k][l];
	                    vecinos++;
	                }
	            }
	        }
	        res[i][j] /= vecinos;
	    }
    }
	return res;
}

int contarPicos(vector<vector<int>> m) {
    int res = 0;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            bool esPico = true;
            for (int k = i-1; k <= i+1; k++) {
                for (int l = j-1; l <= j+1; l++) {
                    if (k >= 0 && k < m.size() && l >= 0 && l < m[i].size() && !(k == i && l == j)) {
                        esPico = esPico && m[i][j] > m[k][l];
                    }
                }
            }
            if (esPico) res++;
        }
    }
    return res;
}

bool esTriangular(vector<vector<int>> m) {
    bool triangularInferior = true;
    bool triangularSuperior = true;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < i; j++) {
            triangularInferior = triangularInferior && m[i][j] == 0;
            triangularSuperior = triangularSuperior && m[m.size() - i - 1][m[i].size() - j - 1] == 0;
        }
    }
    return triangularInferior || triangularSuperior;
}

bool ataqueValido(int i1, int j1, int i2, int j2) {
    return i1 == i2 || j1 == j2 || abs(i1 - i2) == abs(j1 - j2);
}

bool esReina(vector<vector<int>>& m, int i1, int j1) {
    return m[i1][j1] == 1;
}

bool hayAmenaza(vector<vector<int>> m) {
    bool res = false;
    vector<tuple<int, int>> reinas;
    for (int i1 = 0; i1 < m.size(); i1++) {
        for (int j1 = 0; j1 < m[i1].size(); j1++) {
            if (esReina(m, i1, j1)) {
                for (int k = 0; k < reinas.size(); k++) {
                    auto [i2, j2] = reinas[k];
                    if (ataqueValido(i1, j1, i2, j2)) {
                        res = true;
                    }
                }
                reinas.emplace_back(i1, j1);
            }
        }
    }
    return res;
}

int diferenciaDiagonales(vector<vector<int>> m) {}