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

    std::cout << suma(10,20) << std::endl;

    std::cout << resta(20,10) << std::endl;

    std::cout << multiplicar(3,4) << std::endl;

    std::cout << dividir(20,4) << std::endl;

    std::cout << dividir(10,0) << std::endl;

    return 0;
}
