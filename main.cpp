#include <iostream>

int multiplicar(int a, int b){
    return a * b;
}

int resta(int a, int b){
    return a - b;
}

int suma(int a, int b) {

    int resultado = 0;

    if (a > 0) {
        if (b > 0) {
            if (a < 100) {
                if (b < 100) {
                    resultado = a + b;
                }
            }
        }
    }

    return resultado;
}

int main() {
    int resultado = suma(10, 20);

    std::cout << resultado << std::endl;

    return 0;
}
