//
// Created by Terry on 12/17/2020.
//

#ifndef LIFE_CELL_H
#define LIFE_CELL_H

class Cell {
private:
    bool state;

public:
    Cell() { state = false; }
    bool getState() { return state; }
    void setState(bool s) { state = s; }
};

#endif //LIFE_CELL_H
