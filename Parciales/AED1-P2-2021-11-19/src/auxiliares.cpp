#include <vector>
#include <iostream>

using namespace std;

vector<int> construir_vector(int n, string disposicion) {
    vector<int> res;
    srand(time(NULL));
    int numero;

    if (disposicion == "asc") {
        for (int i = 0; i < n; i++) {
            res.push_back(i);
        }
    } else if (disposicion == "desc") {
        for (int i = n - 1; i >= 0; i--) {
            res.push_back(i);
        }
    } else if (disposicion == "azar") {
        for (int i = 0; i < n; i++) {
            numero = rand() % 100;
            res.push_back(numero);
        }
    } else if (disposicion == "iguales") {
        numero = rand() % 100;
        for (int i = 0; i < n; i++) {
            res.push_back(numero);
        }
    } else {
        cout << "Dispocisión no válida" << endl;
    }

    return res;
}