//
// Created by sarosi on 16/08/2020.
//

#include "Table.h"

bool Table::ncount(int y, int x) {
    int count = 0;
    int torus_y; // mivel a palya szelei osszeernek ezert a jatekter olyan mint egy torusz
    int torus_x;

    for (int i = y - 1; i < y + 2; ++i) {
        for (int j = x - 1; j < x + 2; ++j) {
            torus_y = (_height + i) % _height;
            torus_x = (_width + j) % _width;
            if (table[torus_y][torus_x])
                count++;
        }
    }

    return (table[y][x] && ((count - 1) == 2 || (count - 1) == 3)) || count == 3;
}

void Table::nextgen() {

    liveCellCnt=0;

    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++) {
            _tempTable[y][x] = ncount(y, x);
            liveCellCnt+=_tempTable[y][x]?1:0;
        }

    std::swap(table, _tempTable);
}


Table::Table(int width, int height) : _width(width), _height(height) {

    table = new bool *[height];
    _tempTable = new bool *[height];

    for (int i = 0; i < height; ++i) {
        table[i] = new bool[width];
        _tempTable[i] = new bool[width];
    }

}

