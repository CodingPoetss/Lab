#include"setLine.h"
//œﬂ∂Œ¿‡

setLine::setLine() {}
setLine::setLine(Dot d1, Dot d2) :dot1{ d1 }, dot2{ d2 }{
    line(d1.getX(), d1.getY(), d2.getX(), d2.getY());
}

void setLine::setDot1(Dot d1) { dot1 = d1; }
void setLine::setDot2(Dot d2) { dot2 = d2; }
Dot setLine::getDot1() { return dot1; }
Dot setLine::getDot2() { return dot2; }
