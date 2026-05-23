#include <iostream>

int main() {
    int* numero = new int;

    *numero = 42;

    std::cout << "Numero: " << *numero << std::endl;

    delete numero;
    numero = nullptr;

    return 0;
}