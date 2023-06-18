#pragma once
#include "Shape.h"
class Circle:public Shape {
public:
	Circle() {};
	Circle(int x1, int y1,int R1, COLORREF color);
	void show() override;
	void hide() override;
	void moveTo(int x1, int y1) override;
	virtual~Circle(){};
};


