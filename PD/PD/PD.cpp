#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>

void myFunction() {
    for (int i = 0; i < 1000000000; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Iteration: " << i << std::endl;

    }
}


void processFunction(void(*func) (void), int value) {
    std::thread workerThread(func);

    std::this_thread::sleep_for(std::chrono::seconds(value));

    if (workerThread.joinable()) {
        std::cout << "Function timed out or ended" << std::endl;
        exit(1);
    }

}


int main() {
    processFunction(myFunction, 10);

    return 0;
}