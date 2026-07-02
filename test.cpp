#include <iostream>
#include <vector>

int suma(int a, int b) {
    return a + b;
}

int calcularTotal(const std::vector<int>& numeros) {
    int total = 0;

    for (int numero : numeros) {
        total += numero;
    }

    return total;
}

int main() {
    if (suma(2, 3) != 5) {
        std::cerr << "ERROR: suma(2, 3) deberia devolver 5" << std::endl;
        return 1;
    }

    std::vector<int> numeros = {10, 20, 30};

    if (calcularTotal(numeros) != 60) {
        std::cerr << "ERROR: calcularTotal deberia devolver 60" << std::endl;
        return 1;
    }

    std::cout << "Todos los tests han pasado correctamente" << std::endl;
    return 0;
}
