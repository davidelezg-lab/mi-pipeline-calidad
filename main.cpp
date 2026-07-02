#include <iostream>
#include <cstdio>

int suma(int a, int b) {
    return a + b;
}

int main() {

    char buffer[10];

    fgets(buffer, sizeof(buffer), stdin);

    std::cout << buffer << std::endl;

    return 0;
}
