#include <iostream>

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int dividir(int a, int b) {

    if (b == 0) {
        return 0;
    }

    return a / b;
}

int main() {

    // SUMA

    if (suma(2, 3) != 5) return 1;
    if (suma(-2, 2) != 0) return 1;

    // RESTA

    if (resta(10, 4) != 6) return 1;
    if (resta(5, 8) != -3) return 1;

    // MULTIPLICAR

    if (multiplicar(3, 4) != 12) return 1;
    if (multiplicar(5, 0) != 0) return 1;

    // DIVIDIR

    if (dividir(20, 4) != 5) return 1;
    if (dividir(10, 0) != 0) return 1;

    std::cout << "Todos los tests han pasado correctamente" << std::endl;

    return 0;
}
