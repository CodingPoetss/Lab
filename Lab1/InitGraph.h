#pragma once
//初始化
#include <graphics.h>
class InitGraph {
private:
    int Width{ 0 };
    int Height{ 0 };

public:
    InitGraph();
    InitGraph(int w, int h);
    
~InitGraph();
    

    //重载一个清屏函数，可输入清屏的颜色
void clean();
void clean(COLORS c);


void setSize(int w, int h);

int getWidth();

int getHeight();
  

};