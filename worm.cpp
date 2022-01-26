// 24.01.2022

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "snake.h"

const int FrameW = 40,
          FrameH = 10;
int Frame[FrameW][FrameH];
bool isAp = false;
int dir = 1; // 1 - r, 2 - u, 3 - l, 4 - d
pnt Head;
pnt Apple;

using namespace std;

namespace snake {
  class worm;

  void worm::SetApple() {
    srand(clock());
    if (isAp) {
      return;
    }
    Apple.X = rand() % (FrameW - 2) + 1;
    Apple.Y = rand() % (FrameH - 2) + 1;
    Frame[Apple.X][Apple.Y] = 3;
    isAp = true;
  } // End of 'worm::SetApple' function

  void worm::InitFrame() {
    srand(clock());
    // Field init
    // frame
    for (int i = 0; i < FrameW; i++) {
      Frame[i][0] = -1;
      Frame[i][FrameH - 1] = -1;
    }
    for (int j = 0; j < FrameH; j++) {
      Frame[0][j] = -1;
      Frame[FrameW - 1][j] = -1;
    }
    // others
    for (int j = 1; j < FrameH - 1; j++) {
      for (int i = 1; i < FrameW - 1; i++) {
        Frame[i][j] = 0;
      }
    }
    // Head init
    Head.X = rand() * clock() % (FrameW - 2) + 1;
    Head.Y = rand() * clock() % (FrameH - 2) + 1;
    Frame[Head.X][Head.Y] = 1;
    // Apple init
    worm::SetApple();
  } // End of 'worm::InitFrame' function

  void worm::DrawFrame() {
    // clear screen.
    system("cls");

    // Put numbers to screen.
    // -1 - frame - '#'
    //  0 - field - ' '
    //  1 - head  - 'X' (?)
    //  2 - body  - 'x' (?)
    //  3 - apple - '@'
    for (int j = 0; j < FrameH; j++) {
      for (int i = 0; i < FrameW; i++) {
        switch (Frame[i][j]) {
        case -1:
          cout << "#";
          break;
        case 0:
          cout << " ";
          break;
        case 1:
          cout << "X";
          break;
        case 3:
          cout << "@";
          break;
        default:
          cout << "?";
          break;
        }
      }
      cout << endl;
    }
  } // End of 'worm::DrawFrame' function

  // can we go to right ?
  bool worm::r( pnt a )
  {
    if (Frame[a.X + 1][a.Y] >= 0)
      return true;
    return false;
  }

  bool worm::u(pnt a)
  {
    if (Frame[a.X][a.Y - 1] >= 0)
      return true;
    return false;
  }

  bool worm::l(pnt a)
  {
    if (Frame[a.X - 1][a.Y] >= 0)
      return true;
    return false;
  }

  bool worm::d(pnt a)
  {
    if (Frame[a.X][a.Y + 1] >= 0)
      return true;
    return false;
  }

  void worm::Move()
  {
    Frame[Head.X][Head.Y] = 0;
    switch (dir) // 1 - r, 2 - u, 3 - l, 4 - d
    {
    case 1:
      if (r(Head))
        Head.X += 1;
      break;
    case 2:
      if (u(Head))
        Head.Y -= 1;
      break;
    case 3:
      if (l(Head))
        Head.X -= 1;
      break;
    case 4:
      if (d(Head))
        Head.Y += 1;
      break;
    default:
      break;
    }
    Frame[Head.X][Head.Y] = 1;
  }

  void worm::dirSet(int a) {
    dir = a;                  // later надо загнать почти все константы в приват класса
  }

  void worm::UpdateFrame() {
    worm::Move();

    if (Frame[Apple.X][Apple.Y] != 3) {
       isAp = false; // later написать функцию съедено ли €блоко и если съедено то хвост прибавл€етс€
                     // а может и не надо, а надо удалить его нахрен
       worm::SetApple();
    }

  } // End of 'worm::UpdateFrame' function

} // End of 'snake' namespace

