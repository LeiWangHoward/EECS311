#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
#include <iostream>
using namespace std;
class Rectangle
{
  public:
    Rectangle();
    Rectangle(string name,int x,int y,int w,int h);
    ~Rectangle();
    bool recIntersect(int x2, int y2, int w2, int h2);
    bool edgeIntersect(int l1, int h1, int l2, int h2);
    void print_info();
    bool identical(Rectangle r2);	
    bool check_legal(int w, int h);
    string get_name();
    int get_x();
    int get_y();
    int get_w();
    int get_h();
    void set_name(string name);
    void set_x(int x);
    void set_y(int y);
    void set_w(int w);
    void set_h(int h);
  private:
    string name;
    int x;
    int y;
    int w;
    int h;
};
#endif
