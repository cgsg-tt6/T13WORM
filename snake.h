// 24.01.2022

#ifndef __SNAKE_H_
#define __SNAKE_H_

struct pnt {
  int X=0, Y=0;
};

namespace snake {
  // 2d snake realization.
  class worm {
  private:
    static void SetApple();
    
    static bool d(pnt a);
    static bool u(pnt a);
    static bool r(pnt a);
    static bool l(pnt a);
  public:
    static void InitFrame();
    static void DrawFrame();
    static void dirSet(int a);
    static void UpdateFrame();
    static void Move();
  }; // End of 'worm' class

} // End of 'snake' namespace

#endif //__SNAKE_H_
