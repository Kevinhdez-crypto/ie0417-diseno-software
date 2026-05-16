#include <iostream>
#include <thread>
#include <vector>

void saludar(int id) {
    std::cout << "Hola desde el hilo " << id << std::endl;
}

int main() {
    std::vector<std::thread> hilos;

    // Crear 5 hilos
    for (int i = 0; i < 5; ++i) {
        hilos.emplace_back(saludar, i);
    }

    // Esperar a que todos los hilos terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }

    std::cout << "Todos los hilos finalizaron." << std::endl;
    return 0;
}