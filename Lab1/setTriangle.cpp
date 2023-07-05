#include"setTriangle.h"
//Èý½ÇÐÎÀà

    setTriangle::setTriangle() {}
    setTriangle::setTriangle(Dot d1, Dot d2, Dot d3, setColor c) :color{ c } {
        setLine{ d1,d2 };
        setLine{ d2,d3 };
        setLine{ d3,d1 };

    }

