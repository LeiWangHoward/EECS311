#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include <string>
#include <iostream>
#include "rectangle.h"
using namespace std;
const int MAX_LEVEL=20; // 2^20 is large enough
class node
{
public:
    node(Rectangle r2,int level)
    {
        this->level=level;
        r=r2;
        forward=new node *[level];
        for (int i=0; i<level; i++)//forward  index from 0 to level-1
            forward[i]=NULL;
    }
    
    ~node()
    {
        delete []forward;
    }
    
    node **forward;//used to create an forward array points to an array
    Rectangle r;
private:
    int level;
};

class skip_list
{
public:
    skip_list();
    ~skip_list();
    int random_level();
    void insert(Rectangle r);
    void remove(string name);
    void remove(int x, int y, int w, int h);
    void search(string k_name);
    void rangesearch(int x, int y, int w, int h);
    void print();
    void allintersections();
    
private:
    node *head;
    int current_level;
    float probability;
};
#endif
