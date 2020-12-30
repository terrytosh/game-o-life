#include <iostream>
#include "grid.h"

int main() {
    Grid grid;
    grid.setStartingConfig();
    int ctr = 0;

    do {
        grid.printGrid();
        std::cout << "\n";
        grid.updateGrid();
        grid.setNextGeneration();
        ctr += 1;
        sleep(1);
    } while (ctr < 50);

    return 0;
}