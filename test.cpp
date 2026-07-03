#include <iostream>

int suma(int a, int b) {
    return a + b;
}

int resta(int a, int b) {
    return a - b;
}

/*
 * MISMO ERROR QUE EXISTE EN main.cpp
 * Simulamos que el código productivo está roto.
 */
int multiplicar(int a, int b) {
    return a + b;
}

int dividir(int a, int b) {

    if (b == 0) {
        return 0;
    }

    return a / b;
}

int main() {

    if (suma(2, 3) != 5) {
        std::cerr << "ERROR SUMA" << std::endl;
        return 1;
    }

    if (resta(10, 4) != 6) {
        std::cerr << "ERROR RESTA" << std::endl;
        return 1;
    }

    if (multiplicar(3, 4) != 12) {
        std::cerr << "ERROR MULTIPLICAR" << std::endl;
        return 1;
    }

    if (dividir(20, 4) != 5) {
        std::cerr << "ERROR DIVIDIR" << std::endl;
        return 1;
    }

    std::cout << "Todos los tests han pasado correctamente" << std::endl;

    return 0;
}
