//
//  analyse.hpp
//  gobang
//
//  Created by mac on 16/3/31.
//  Copyright © 2016年 Ownsky. All rights reserved.
//

#ifndef analyse_hpp
#define analyse_hpp

int checkline(int x, int y, int* c);
int checkcol(int x, int y, int* c);
int checkrd(int x, int y, int* c);
int checkld(int x, int y, int* c);
void value(int x, int y);
int win(int x, int y);
int pointValue(int a, int b);
int aboutToWin(int x, int y);
int checklineL(int x, int y, int* c);
int checklineR(int x, int y, int* c);
int checkcolU(int x, int y, int* c);
int checkcolD(int x, int y, int* c);
int checkrdU(int x, int y, int* c);
int checkrdD(int x, int y, int* c);
int checkldU(int x, int y, int* c);
int checkldD(int x, int y, int* c);
bool actFour(int x, int y);

#endif /* analyse_hpp */
