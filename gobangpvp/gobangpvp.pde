boolean chessColor; //<>// //<>//
int chessboard[][] = null;
boolean winstate;
boolean _1pchess = false;
int _1p = 0, _2p = 0;

void setup() {
  smooth();
  chessboard = new int[15][15];
  winstate = false;
  chessColor = false;
  background(255, 204, 0);
  size(800, 620);
  textSize(10);
  fill(0);
  for (int i = 30; i <= 590; i+=40) {
    line(i, 30, i, 590);
    line(30, i, 590, i);
    text((i-15)/40, i, 15);
    text((i-15)/40, 10, i);
  }
  textSize(16);
  text("Turn:", 625, 45);
  text("1P:  " + _1p, 650, 125);
  text("2P:  " + _2p, 650, 155);
  text("Press 'C' to clear all.", 625, 200);
  ellipse(150, 150, 4, 4);
  ellipse(150, 470, 4, 4);
  ellipse(470, 150, 4, 4);
  ellipse(470, 470, 4, 4);
  ellipse(310, 310, 4, 4);
  fill(_1pchess?255:0);
  ellipse(635, 120, 20, 20);
  fill(_1pchess?0:255);
  ellipse(635, 150, 20, 20);
}
void draw() {
  fill(0);
  if (chessColor) fill(255);
  else fill(0);
  ellipse(700, 40, 20, 20);
}

void mouseClicked() {
  if (winstate) {
    this.clear();
    setup();
  } else {
    int x = (mouseX - 15)/40;
    int y = (mouseY - 15)/40;
    if (x>14||x<0||y>14||y<0) return;
    if (chessboard[x][y] != 0) return;
    if (chessColor) fill(255);
    else fill(0);
    ellipse(x*40+30, y*40+30, 20, 20);
    chessboard[x][y] = (chessColor ? 1 : 0) + 1;
    if (win(x, y)) {
      textSize(24);
      String str = chessColor ? "White" : "Black";
      text(str + " win.", 640, 500);
      textSize(16);
      text("Click anywhere to \nstart a new game.", 620, 530);
      winstate = !winstate;
      if (_1pchess == chessColor) _1p++;
      else _2p++;
      _1pchess = !_1pchess;
    }
    chessColor = !chessColor;
  }
}

void keyPressed(){
  if (key == 'C' || key == 'c'){
    _1pchess = false;
    _1p = _2p = 0;
    this.clear();
    setup();
  }
}

boolean win(int x, int y) {
  if (((checkline(x, y)==0)||
    (checkcol(x, y)==0)||
    (checkld(x, y)==0)||
    (checkrd(x, y)==0))) {
    return true;
  } else return false;
}

//The four funcs below can obviously be simplified into one. 
int checkline(int x, int y) {
  int t = 1;
  int pos = x;
  while (++pos < 15 && chessboard[pos][y] == chessboard[x][y]) {
    t++;
  }
  pos = x;
  while (--pos >= 0 && chessboard[pos][y] == chessboard[x][y]) {
    t++;
  }
  if (t>=5) {
    return 0;
  }
  return t;
}

int checkcol(int x, int y) {
  int t = 1;
  int pos = y;
  while (++pos < 15 && chessboard[x][pos] == chessboard[x][y]) {
    t++;
  }
  pos = y;
  while (--pos >= 0 && chessboard[x][pos] == chessboard[x][y]) {
    t++;
  }
  if (t>=5) {
    return 0;
  }
  return t;
}

int checkrd(int x, int y) {
  int t = 1;
  int posX = x;
  int posY = y;
  while (++posX < 15 && ++ posY < 15 && chessboard[posX][posY] == chessboard[x][y]) {
    t++;
  }
  posX = x;
  posY = y;
  while (--posX >= 0 && --posY >= 0 && chessboard[posX][posY] == chessboard[x][y]) {
    t++;
  }
  if (t>=5) {
    return 0;
  }
  return t;
}

int checkld(int x, int y) {
  int t = 1;
  int posX = x;
  int posY = y;
  while (--posX >= 0 && ++posY < 15 && chessboard[posX][posY] == chessboard[x][y]) {
    t++;
  }
  posX = x;
  posY = y;
  while (++posX < 15 && --posY >= 0 && chessboard[posX][posY] == chessboard[x][y]) {
    t++;
  }
  if (t>=5) {
    return 0;
  }
  return t;
}