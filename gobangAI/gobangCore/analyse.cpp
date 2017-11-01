//
//  analyse.cpp
//  gobang
//
//  Created by mac on 16/3/31.
//  Copyright © 2016年 Ownsky. All rights reserved.
//

#include "stdafx.h"
#include "analyse.h"
#include <cmath>

/*int gothrough [8][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0},
    {1,1},
    {-1,-1},
    {1,-1},
    {-1,1}
};*/
extern bool ord;

int valueboard[15][15];
extern int chessboard[15][15];

int win(int x, int y){
    if (!(checkline(x, y, 0)&&
          checkcol(x, y, 0)&&
          checkld(x, y, 0)&&
          checkrd(x, y, 0))) {
        return 1;
    } else return 0;
}

int aboutToWin(int x, int y){
    if (!valueboard[x][y]) return 0;
    int w = 0;
    chessboard[x][y] = ord + 1;
    if (win(x, y)/*||actFour(x, y)*/) w += 3;//2
	else if (actFour(x, y)) w += 1;////
    chessboard[x][y] = !ord + 1;
    if (win(x, y)||actFour(x, y)) w += 2;//1
    chessboard[x][y] = 0;
    return w;
}
bool actFour(int x, int y){
    int ter1, ter2;
    int t;
    t = checklineL(x, y, &ter1) + checklineR(x, y, &ter2) - 1;
    if ((t == 4)&&((ter1 + ter2) == 0)) return 1;
    t = checkcolU(x, y, &ter1) + checkcolD(x, y, &ter2) - 1;
    if ((t == 4)&&((ter1 + ter2) == 0)) return 1;
    t = checkrdU(x, y, &ter1) + checkrdD(x, y, &ter2) - 1;
    if ((t == 4)&&((ter1 + ter2) == 0)) return 1;
    t = checkldU(x, y, &ter1) + checkldD(x, y, &ter2) - 1;
    if ((t == 4)&&((ter1 + ter2) == 0)) return 1;
    return 0;
}

int checkline(int x, int y, int* c) {
//    int t = 1;
//    int pos = x;
//    while (++pos < 15 && chessboard[pos][y] == chessboard[x][y]) {
//        t++;
//    }
//    pos = x;
//    while (--pos >= 0 && chessboard[pos][y] == chessboard[x][y]) {
//        t++;
//    }
//    if (t>=5) {
//        return 0;
//    }
//    return t;
    int t = checklineL(x, y, c) + checklineR(x, y, c) - 1;
    if (t>=5) {
        return 0;
    } else return t;
}

int checklineL(int x, int y, int* c) {
    int t = 1;
    int pos = x;
    while (++pos < 15 && chessboard[pos][y] == chessboard[x][y]) {
        t++;
    }
    if (c) *c = chessboard[pos][y];
    return t;
}
int checklineR(int x, int y, int* c) {
    int t = 1;
    int pos = x;
    while (--pos >= 0 && chessboard[pos][y] == chessboard[x][y]) {
        t++;
    }
    if (c) *c = chessboard[pos][y];
    return t;
}

int checkcol(int x, int y, int* c) {
//    int t = 1;
//    int pos = y;
//    while (++pos < 15 && chessboard[x][pos] == chessboard[x][y]) {
//        t++;
//    }
//    pos = y;
//    while (--pos >= 0 && chessboard[x][pos] == chessboard[x][y]) {
//        t++;
//    }
//    if (t>=5) {
//        return 0;
//    }
//    return t;
    int t = checkcolU(x, y, c) + checkcolD(x, y, c) - 1;
    if (t>=5) {
        return 0;
    } else return t;
}

int checkcolU(int x, int y, int* c){
    int t = 1;
    int pos = y;
    while (++pos < 15 && chessboard[x][pos] == chessboard[x][y]) {
        t++;
    }
    if (c) *c = chessboard[x][pos];
    return t;
}
int checkcolD(int x, int y, int* c){
    int t = 1;
    int pos = y;
    while (--pos >= 0 && chessboard[x][pos] == chessboard[x][y]) {
        t++;
    }
    if (c) *c = chessboard[x][pos];
    return t;
}

int checkrd(int x, int y, int* c) {
//    int t = 1;
//    int posX = x;
//    int posY = y;
//    while (++posX < 15 && ++ posY < 15 && chessboard[posX][posY] == chessboard[x][y]) {
//        t++;
//    }
//    posX = x;
//    posY = y;
//    while (--posX >= 0 && --posY >= 0 && chessboard[posX][posY] == chessboard[x][y]) {
//        t++;
//    }
//    if (t>=5) {
//        return 0;
//    }
//    return t;
    int t = checkrdU(x, y, c) + checkrdD(x, y, c) - 1;
    if (t>=5) {
        return 0;
    } else return t;
}

int checkrdU(int x, int y, int* c){
    int t = 1;
    int posX = x;
    int posY = y;
    while (++posX < 15 && ++ posY < 15 && chessboard[posX][posY] == chessboard[x][y]) {
        t++;
    }
    if (c) *c = chessboard[posX][posY];
    return t;
}
int checkrdD(int x, int y, int* c){
    int t = 1;
    int posX = x;
    int posY = y;
    while (--posX >= 0 && --posY >= 0 && chessboard[posX][posY] == chessboard[x][y]) {
        t++;
    }
    if (c) *c = chessboard[posX][posY];
    return t;
}

int checkld(int x, int y, int* c) {
//    int t = 1;
//    int posX = x;
//    int posY = y;
//    while (--posX >= 0 && ++posY < 15 && chessboard[posX][posY] == chessboard[x][y]) {
//        t++;
//    }
//    posX = x;
//    posY = y;
//    while (++posX < 15 && --posY >= 0 && chessboard[posX][posY] == chessboard[x][y]) {
//        t++;
//    }
//    if (t>=5) {
//        return 0;
//    }
//    return t;
    int t = checkldU(x, y, c) + checkldD(x, y, c) - 1;
    if (t>=5) {
        return 0;
    } else return t;
}

int checkldU(int x, int y, int* c){
    int t = 1;
    int posX = x;
    int posY = y;
    while (++posX < 15 && --posY >= 0 && chessboard[posX][posY] == chessboard[x][y]) {
        t++;
    }
    if (c) *c = chessboard[posX][posY];
    return t;
}
int checkldD(int x, int y, int* c){
    int t = 1;
    int posX = x;
    int posY = y;
    while (--posX >= 0 && ++posY < 15 && chessboard[posX][posY] == chessboard[x][y]) {
        t++;
    }
    if (c) *c = chessboard[posX][posY];
    return t;
}

void value(int x, int y){
    for(int i = 0; i < 15; i++){
        valueboard[x][i] = pointValue(x, i) + 5000 * aboutToWin(x, i);
        valueboard[i][y] = pointValue(i, y) + 5000 * aboutToWin(i, y);
        if ((x+i<15) && (y+i<15)) {
            valueboard[x+i][y+i] = pointValue(x+i, y+i) + 5000 * aboutToWin(x+i, y+i);
        }
        if ((x-i>0) && (y-i>0)) {
            valueboard[x-i][y-i] = pointValue(x-i, y-i) + 5000 * aboutToWin(x-i, y-i);
        }
        if ((x+i<15) && (y-i>0)) {
            valueboard[x+i][y-i] = pointValue(x+i, y-i) + 5000 * aboutToWin(x+i, y-i);
        }
        if ((x-i>0) && (y+i<15)) {
            valueboard[x-i][y+i] = pointValue(x-i, y+i) + 5000 * aboutToWin(x-i, y+i);
        }
        
    }
    
    
//    for (int i = 0; i < 8; i++) {
//        int m = x + gothrough[i][0], n = y + gothrough[i][1];
//        if (m>14 || n>14) {
//            continue;
//        }
//        if (!chessboard[m][n]) {
//            valueboard[m][n] ++;
//        }
//    }
    
}

int pointValue(int a, int b){
    if (!valueboard[a][b]) return 0;
    int val, lineL, lineR, colU, colD, rd, ru, ld, lu, c;
    int li, co, il, ir;
    lineR = pow(((chessboard[a+1][b]&&(a+1<15))?checkline(a+1, b, &c):0) * (c?1:2), 2);
    lineL = pow(((chessboard[a-1][b]&&(a-1>0))?checkline(a-1, b, &c):0) * (c?1:2), 2);
    li = lineL + lineR;
    if (chessboard[a+1][b]&&chessboard[a-1][b]&&(chessboard[a+1][b]!=chessboard[a-1][b]))
        li /= 4;
    colU = pow(((chessboard[a][b+1]&&(b+1<15))?checkcol(a, b+1, &c):0) * (c?1:2), 2);
    colD = pow(((chessboard[a][b-1]&&(b-1>0))?checkcol(a, b-1, &c):0) * (c?1:2), 2);
    co = colU + colD;
    if (chessboard[a][b+1]&&chessboard[a][b-1]&&(chessboard[a][b+1]!=chessboard[a][b-1]))
        co /= 4;
    rd = pow(((chessboard[a+1][b+1]&&(a+1<15)&&(b+1<15))?checkrd(a+1, b+1, &c):0) * (c?1:2), 2);
    lu = pow(((chessboard[a-1][b-1]&&(a-1>0)&&(b-1>0))?checkrd(a-1, b-1, &c):0) * (c?1:2), 2);
    ir = rd + lu;
    if (chessboard[a+1][b+1]&&chessboard[a-1][b-1]&&(chessboard[a+1][b+1]!=chessboard[a-1][b-1]))
        ir /= 4;
    ru = pow(((chessboard[a+1][b-1]&&(a+1<15)&&(b-1>0))?checkld(a+1, b-1, &c):0) * (c?1:2), 2);
    ld = pow(((chessboard[a-1][b+1]&&(a-1>0)&&(b+1<15))?checkld(a-1, b+1, &c):0) * (c?1:2), 2);
    il = ru + ld;
    if (chessboard[a+1][b-1]&&chessboard[a-1][b+1]&&(chessboard[a+1][b-1]!=chessboard[a-1][b+1]))
        il /= 4;
    val = li + co + ir + il;
    return val+1;
}
