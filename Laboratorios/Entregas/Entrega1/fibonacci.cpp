#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino (empezando en 0)
// F0 = 0
// F1 = 1
// Fn = Fn−1 + Fn−2
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
int fibonacci(int n) {
    int f = 0;
    int fn_2 = 0;
    int fn_1 = 1;
    int i = 1;
    while (i <= n) {
        f = fn_2 + fn_1;
        if (i > 1) {
            fn_2 = fn_1;
            fn_1 = f;
        }
        i++;
    }
    return f;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}