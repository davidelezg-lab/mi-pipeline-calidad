#include <iostream>

int suma(int a, int b) {
    return a - b;
}

int main() {
    if (suma(2, 3) != 5) {
        std::cerr << "ERROR: suma(2, 3) deberia devolver 5" << std::endl;
        return 1;
    }

    std::cout << "Todos los tests han pasado correctamente" << std::endl;
    return 0;
}
