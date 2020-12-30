//
// Created by Terry on 12/17/2020.
//

#ifndef LIFE_GRID_H
#define LIFE_GRID_H

#include "cell.h"

const int ROWS = 12;
const int COLS = 50;

class Grid {
private:
    Cell grid[ROWS][COLS];
    Cell nextGeneration[ROWS][COLS];
    int getLivingNeighbors(int, int);

public:
    Grid();
    void printGrid();
    void updateGrid();
    void setNextGeneration();
    void setStartingConfig();
};

#endif //LIFE_GRID_H
