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
    std::vector<int> numeros = {10, 20, 30, 40, 50};

    int total = calcularTotal(numeros);

    std::cout << "Total: " << total << std::endl;

    return 0;
}
