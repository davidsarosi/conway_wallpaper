//
// Created by sarosi on 16/08/2020.
//

#ifndef LIFE_ON_PAPER_TABLE_H
#define LIFE_ON_PAPER_TABLE_H


#include <algorithm>

class Table {
    bool **_tempTable;
    int _width;
    int _height;

    bool ncount(int y, int x);

public:
    Table(int width, int height);
    int liveCellCnt=0;
    bool **table;
    void nextgen();
};


#endif //LIFE_ON_PAPER_TABLE_H
