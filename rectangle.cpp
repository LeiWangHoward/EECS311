#include "rectangle.h"
#include<iostream>
#include<string>
using namespace std;
Rectangle::Rectangle()
{
    x=-1;
    y=-1;
    w=-1;
    h=-1;
}

Rectangle::Rectangle(string name,int x1,int y1,int w1,int h1)
{
    x=x1;
    y=y1;
    w=w1;
    h=h1;
}

Rectangle::~Rectangle()
{
    ;
}

bool Rectangle::identical(Rectangle r2)
{
    if (x==r2.get_x() && y==r2.get_y() && w==r2.get_w() && h==r2.get_h())
        return true;
    else
        return false;
}

void Rectangle::print_info()
{
    cout<<"Name: "<<name<<"\t"
    <<"Position: "<<"( "
    <<x<<" , "<<y<<" )\t"
    <<"Width: "<<w<<"\t"
    <<"Height: "<<h<<endl;
}

bool Rectangle::check_legal(int w,int h)
{
    if(w<=0 || h<=0)
        return false;
    else
        return true;
}

bool Rectangle::recIntersect(int x2,int y2,int w2,int h2) {
    return edgeIntersect(this->x, this->x+this->w, x2, x2+w2) && edgeIntersect(this->y, this->y+this->h, y2, y2+h2);
}

bool Rectangle::edgeIntersect(int l1,int h1,int l2,int h2)
{
    return !(h1 < l2 || h2 < l1);
}

void Rectangle::set_name(string rec_name)
{
    name = rec_name;
}

void Rectangle::set_x(int x_position)
{
    x = x_position;
}

void Rectangle::set_y(int y_position)
{
    y = y_position;
}

void Rectangle::set_w(int width)
{
    w = width;
}

void Rectangle::set_h(int height)
{
    h = height;
}

string Rectangle::get_name()
{
    return name;
}

int Rectangle::get_x()
{
    return x;
}

int Rectangle::get_y()
{
    return y;
}

int Rectangle::get_w()
{
    return w;
}
int Rectangle::get_h()
{
    return h;
}
