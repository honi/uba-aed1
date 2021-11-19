#include <iostream>
#include <vector>

using namespace std;

bool estaOrdenado(vector<int> v) {
    bool result = true;

    // Si hay 0 o 1 elementos entonces siempre está ordenado
    if (v.size() >= 2) {
        // Encuentro la primer posición donde v[i] != v[i+1]
        int i = 0;
        while (i < v.size() - 1 && v[i] == v[i+1]) {
            i++;
        }

        // Determino si está ordenado creciente o decreciente
        bool ordenCreciente = v[i] < v[i+1];

        for (int i = 0; i < v.size() - 1; i++) {
            if ((v[i] > v[i+1] && ordenCreciente) || (v[i] < v[i+1] && !ordenCreciente)) {
                result = false;
            }
        }
    }

    return result;
}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n;
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Evaluo si el vector v esta ordenado
    bool res = estaOrdenado(v);

    // Imprimo la salida
    cout << (res?"True":"False");

    return 0;
}