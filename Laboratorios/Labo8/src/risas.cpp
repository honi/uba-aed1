#include <string>
#include <vector>
#include "risas.h"
#include <iostream>
#include <fstream>

using namespace std;

/* Utiles */
vector<char> leerDatos(string filename) {
    vector<char> vec;
    char c;
    ifstream f;
    f.open(filename);
    if (f.is_open()) {
        while (!f.eof()) {
            f >> c;
            vec.push_back(c);
        }
        f.close();
    }
    return vec;
}

int leerLargoReal(string filename){
    int valor;
    ifstream f;
    f.open(filename);
    if (f.is_open()) {
        f >> valor;
        f.close();
    }
    return valor;
}
/* Utiles */

/* RESOLUCION ALUMNOS */
int risaMasLarga(vector<char> s) {
    int largo = 0;
    int maxLargo = 0;
    int i = 0;
    while (i < s.size()) {
        bool risaValida = false;
        if (s[i] == 'a') {
            risaValida = largo == 0 || s[i-1] == 'h';
        } else if (s[i] == 'h') {
            risaValida = largo == 0 || s[i-1] == 'a';
        }
        if (risaValida) {
            largo++;
        } else {
            if (largo > maxLargo) {
                maxLargo = largo;
            }
            largo = 0;
        }
        i++;
    }
    return largo > maxLargo ? largo : maxLargo;
}
/* RESOLUCION ALUMNOS */
