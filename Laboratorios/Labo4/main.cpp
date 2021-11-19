#include <sstream>
#include "generador.h"
#include "vectores.h"

using namespace std;

string vectorToString(vector<int> v) {
    stringstream ss;
    copy(v.begin(), v.end(), ostream_iterator<int>(ss, ", "));
    string result = ss.str();
    return "<" + result.substr(0, result.length() - 2) + ">";
}

int main() {
//    generarDatosLaboratorio();
//    holaModuloVectores();
    vector<int> v = {3, 6, 9, 12};
    cout << "3 divide a " << vectorToString(v) << ": " << divide(v, 3) << endl;
    cout << "2 divide a " << vectorToString(v) << ": " << divide(v, 2) << endl;
    cout << "mayor " << vectorToString(v) << ": " << mayor(v) << endl;
    cout << "reverso " << vectorToString(v) << ": " << vectorToString(reverso(v)) << endl;
    cout << "rotar " << vectorToString(v) << ": " << vectorToString(rotar(v, 1)) << endl;
    cout << "factoresPrimos " << 60 << ": " << vectorToString(factoresPrimos(60)) << endl;
    cout << "factoresPrimos " << 13 << ": " << vectorToString(factoresPrimos(13)) << endl;
    return 0;
}
