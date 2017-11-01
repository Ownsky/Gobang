//
//  main.cpp
//  gobang
//
//  Created by mac on 16/3/31.
//  Copyright © 2016年 Ownsky. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "step.hpp"
#include "analyse.hpp"

using namespace::std;

extern int chessboard[15][15];
extern int valueboard[15][15];
bool ord;

int main(int argc, const char * argv[]) {
    std::cout << "machine first: 1; you first: 0.\n";
    int x,y;
    for (int i=0; i<225; i++) {
        valueboard[i/15][i%15] = 1;
    }
    cin>>ord;
    /*
    chessboard[0][1] = chessboard[0][2] = chessboard[0][3] = chessboard[0][4] = 2;
    cout<<aboutToWin(0, 0)<<endl;
    cout<<aboutToWin(0, 5)<<endl;
    */
    if (ord) {
        srand((int)time(0));
        x = rand() % 8 + 4;
        y = rand() % 8 + 4;
        push(x, y, 1);
        value(x, y);
        cout<<x<<","<<y<<endl;
    }
    while (1) {
        cin>>x>>y;
        if (chessboard[x][y]) {
            cout<<"wrong step."<<endl;
            continue;
        }
        push(x, y, !ord);//
        value(x, y);
        if (win(x,y)) {
            cout<<"you win."<<endl;
            break;
        }
        oneStep(&x, &y);
        push(x, y, ord);//
        value(x, y);
        cout<<x<<","<<y<<endl;
        if (win(x,y)) {
            cout<<"computer win."<<endl;
            break;
        }
    }
    return 0;
}
