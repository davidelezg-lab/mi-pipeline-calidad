#include <iostream>

int suma(int a, int b) {
    return a + b;
}

int main() {
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;

    if (a > 0) {
        if (b > 0) {
            if (c > 0) {
                if (d > 0) {
                    if (e > 0) {
                        std::cout << suma(a, b) + c + d + e << std::endl;
                    }
                }
            }
        }
    }

    return 0;
}
