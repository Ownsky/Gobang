//
//  main.cpp
//  gobang
//
//  Created by mac on 16/3/31.
//  Copyright © 2016年 Ownsky. All rights reserved.
//

#include "stdafx.h"
#include "gobangCore.h"
#include "core.h"
#include <iostream>
#include <time.h>
#include "step.hpp"
#include "analyse.h"

using namespace::std;

extern int chessboard[15][15];
extern int valueboard[15][15];
bool ord;
int steps = 0;

GOBANGCORE_API int gobangInit(bool order) {
	for (int i = 0; i<225; i++) {
		valueboard[i / 15][i % 15] = 1;
	}
	for (int i = 0; i<225; i++) {
		chessboard[i / 15][i % 15] = 0;
	}
	ord = order;
	steps = 0;
	return 0;
}

GOBANGCORE_API int gobangCoreS(int& x, int& y) {
	if (!steps&&ord) {
		srand((int)time(0));
		x = rand() % 8 + 4;
		y = rand() % 8 + 4;
		push(x, y, 1);
		value(x, y);
		steps++;
	}
	else if (ord == (steps % 2)) {
		if (chessboard[x][y]) {
			return -1;
		}
		push(x, y, !ord);
		value(x, y);
		steps++;
		if (win(x, y)) {
			return 2;
		}
	}
	return 0;
}
GOBANGCORE_API int gobangCoreG(int& x, int& y){
	//else {
        oneStep(&x, &y);
        push(x, y, ord);
        value(x, y);
		steps++;
        if (win(x,y)) {
			return 1;
        }
    //}
    return 0;
}

GOBANGCORE_API int getChessboard(int x, int y) {
	if (x < 0 || x>14 || y < 0 || y>14) return -1;
	return chessboard[x][y];
}
GOBANGCORE_API int getValueboard(int x, int y) {
	if (x < 0 || x>14 || y < 0 || y>14) return -1;
	return valueboard[x][y];
}


GOBANGCORE_API int getOrder() {////////
	return ord;
}