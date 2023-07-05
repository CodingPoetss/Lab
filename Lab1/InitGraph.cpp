#include"InitGraph.h"



//初始化

    InitGraph::InitGraph() {}
    InitGraph::InitGraph(int w, int h) :Width{ w }, Height{ h } {
        initgraph(w, h);
    }
    InitGraph::~InitGraph() {
        closegraph();
    }


    //重载一个清屏函数，可输入清屏的颜色
    void InitGraph::clean() {
        cleardevice();
    }
    void InitGraph::clean(COLORS c) {
        setbkcolor_f(c);
        cleardevice();
    }


    void InitGraph::setSize(int w, int h) {
        closegraph();
        initgraph(w, h);
        Width = w;
        Height = h;
    }

    int InitGraph::getWidth() {
        return Width;
    }

    int InitGraph::getHeight() {
        return Height;
    }

