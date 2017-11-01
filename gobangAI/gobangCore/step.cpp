//
//  step.cpp
//  gobang
//
//  Created by mac on 16/3/31.
//  Copyright © 2016年 Ownsky. All rights reserved.
//

#include "stdafx.h"
#include "step.hpp"
#include <iostream>
#include <vector>

#define BLACK 1
#define WHITE 2

int chessboard[15][15] = {0};
extern int valueboard[15][15];

using namespace std;

int oneStep(int* x, int* y){
    vector <int> maxXlist;
    vector<int> maxYlist;
    int max=0;
    for (int xx=0; xx<15; xx++) {
        for (int yy=0; yy<15; yy++) {
            if (valueboard[xx][yy] > max) {
                max = valueboard[xx][yy];
                maxXlist.clear();
                maxYlist.clear();
                maxXlist.push_back(xx);
                maxYlist.push_back(yy);
            } else if(valueboard[xx][yy] == max) {
                maxXlist.push_back(xx);
                maxYlist.push_back(yy);
            }
        }
    }
    int t;
    t = rand() % maxXlist.size();
    *x = maxXlist[t];
    *y = maxYlist[t];
    return 0;
    
}

void push(int x, int y, bool ord){
    chessboard[x][y] = ord + 1;
    valueboard[x][y] = 0;
}