#include "ejercicios.h"

using namespace std;

int main() {
    int n = 0;
    int hasta = 1000;
    int paso = 1;

    ofstream fout;
    fout.open("datos.csv");
    fout << "n\t" << "tiempo" << endl;

    while(n < hasta){
        vector<int> v = construir_vector(n, "azar");

        double t0 = clock();
        v.size();
        double t1 = clock();

        float tiempo = double(t1-t0) / CLOCKS_PER_SEC;
        fout << n << "\t" << tiempo << endl;

        n += paso;
    }

    fout.close();

    return 0;
}