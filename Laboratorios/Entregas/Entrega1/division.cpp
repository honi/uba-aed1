#include <iostream>

using namespace std;

// Modificar el pasaje de parametros de ser necesario para que calcule el cociente y resto. Deben se por copia o referencia??
void division(int dividendo, int divisor, int &cociente, int &resto) {
    cociente = 0;
    while (dividendo >= divisor) {
        cociente++;
        dividendo -= divisor;
    }
    resto = dividendo;
}

int main() {
    // Leo la entrada
    int divisor, dividendo, cociente, resto;
    cin >> dividendo >> divisor;

    // Calculo la division
    division(dividendo, divisor, cociente, resto);

    // Salida
    cout << cociente << " " << resto;

    return 0;
}