#include"setRectangle.h"
//带框矩形

setRectangle::setRectangle() {}
setRectangle::setRectangle(int x1, int y1, int x2, int y2,
	COLORS frame, COLORS background, COLORS words, COLORS filled, bool stuff) : dot1{x1,y1}, dot2{ x2,y2 } {
	color->setFrameColor(frame);
	color->setBackgroundColor(background);
	color->setWordsColor(words);
	color->setFilledColor(filled);
	color->setStuff(stuff);
	ExistingRectangleNumber++;
}
setRectangle::setRectangle(const setRectangle& rectangle){
	dot1 = rectangle.dot1;
	dot2 = rectangle.dot2;
	color = new setColor{ *(rectangle.color) };
	ExistingRectangleNumber++;
}
setRectangle::~setRectangle() {
	delete color;
	ExistingRectangleNumber++;
	xyprintf(600, 0, "Now existing circle(s):%d", ExistingRectangleNumber);
}

void setRectangle::setDot1(Dot d1) { dot1 = d1; }
void setRectangle::setDot2(Dot d2) { dot2 = d2; }
Dot setRectangle::getDot1() { return dot1; }
Dot setRectangle::getDot2() { return dot2; }

void setRectangle::draw() {
	//清屏
	setbkcolor(color->getBackgroundColor());
	cleardevice();


	//重置颜色
	//setColor c{ RED,GREEN,BLACK,BROWN,true };
	setbkcolor(color->getBackgroundColor());
	setfontbkcolor(color->getWordsColor());
	if (color->getStuff()) {
		setfillcolor(color->getFilledColor());
	}
	else {
		setfillcolor(color->getBackgroundColor());
	}
	
	bar(dot1.getX(), dot1.getY(), dot2.getX(), dot2.getY());
	setcolor(color->getFrameColor());

	rectangle(dot1.getX(), dot1.getY(), dot2.getX(), dot2.getY());
	//floodfill(  (dot1->getX()+dot2->getX())/2, (dot1->getY()+dot2->getY())/2,
		//static_cast<color_t>(color->getFrameColor()));
}

