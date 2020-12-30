//
// Created by Terry on 12/17/2020.
//

#include "grid.h"
#include <iostream>

Grid::Grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].setState(false);
            nextGeneration[i][j].setState(false);
        }
    }
}

void Grid::printGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j].getState())
                std::cout << "*";
            else
                std::cout << ".";
        }
        std::cout << "\n";
    }
}

void Grid::updateGrid() {
    for (int i = 1; i < ROWS - 1; i++) {
        for (int j = 1; j < COLS - 1; j++) {
            bool cellState = grid[i][j].getState();
            bool newState = false;
            int neighbors = getLivingNeighbors(i, j);

            if (cellState && (neighbors == 2 || neighbors == 3))
                newState = true;
            if (!cellState && neighbors == 3)
                newState = true;

            //Store in next generation
            nextGeneration[i][j].setState(newState);
        }
    }
}

int Grid::getLivingNeighbors(int i, int j) {
    int output = 0;

    //left cell
    if (grid[i][j - 1].getState())
        output++;
    //top-left cell
    if (grid[i - 1][j - 1].getState())
        output++;
    //top cell
    if (grid[i - 1][j].getState())
        output++;
    //top-right cell
    if (grid[i - 1][j + 1].getState())
        output++;
    //right cell
    if (grid[i][j + 1].getState())
        output++;
    //bottom-right cell
    if (grid[i + 1][j + 1].getState())
        output++;
    //bottom cell
    if (grid[i + 1][j].getState())
        output++;
    //bottom-left cell
    if (grid[i + 1][j - 1].getState())
        output++;

    return output;
}

void Grid::setNextGeneration() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].setState(nextGeneration[i][j].getState());
        }
    }
}

void Grid::setStartingConfig() {
    //cool starting config i found
    grid[6][4].setState(true);
    grid[6][5].setState(true);
    grid[6][6].setState(true);
    grid[6][7].setState(true);
    grid[6][8].setState(true);
    grid[6][9].setState(true);
    grid[6][10].setState(true);
    grid[6][11].setState(true);

    grid[6][13].setState(true);
    grid[6][14].setState(true);
    grid[6][15].setState(true);
    grid[6][16].setState(true);
    grid[6][17].setState(true);

    grid[6][21].setState(true);
    grid[6][22].setState(true);
    grid[6][23].setState(true);

    grid[6][30].setState(true);
    grid[6][31].setState(true);
    grid[6][32].setState(true);
    grid[6][33].setState(true);
    grid[6][34].setState(true);
    grid[6][35].setState(true);
    grid[6][36].setState(true);

    grid[6][38].setState(true);
    grid[6][39].setState(true);
    grid[6][40].setState(true);
    grid[6][41].setState(true);
    grid[6][42].setState(true);
}