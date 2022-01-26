// 24.01.2022

#include <windows.h> // Sleep
#include <conio.h>   // _getch, __kbhit

#include "snake.h"

using namespace snake;

int main() {
  worm::InitFrame();
  worm::DrawFrame();

  while (true) {
    // if any key is hit
    if (_kbhit()) {
      switch (_getch())
      {
      case 27:
        return 0;
      case 'a':
        worm::dirSet(3);
        break;
      case 's':
        worm::dirSet(4);
        break;
      case 'w':
        worm::dirSet(2);
        break;
      case 'd':
        worm::dirSet(1);
        break;
      default:
        break;
      }
    }

    Sleep(100); // later: make different levels of speed

    worm::UpdateFrame();
    worm::DrawFrame();
  }
  return 0;
} // End of 'main' function

