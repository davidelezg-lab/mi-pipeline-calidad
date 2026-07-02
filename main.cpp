#include <iostream>
#include <cstdio>

int main() {

    char buffer[10];

    fgets(buffer, sizeof(buffer), stdin);

    std::cout << buffer << std::endl;

    return 0;
}

int multiplicar(int a, int b) {
    return a * b;
}
