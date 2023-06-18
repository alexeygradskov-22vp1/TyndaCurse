#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Pentagon.h"
class ComplexFigure : public Shape {
private:
	Pentagon pentagon;
	Circle circle;
public:
	ComplexFigure(){};
	ComplexFigure(Circle* _c, Pentagon* _p);
	void show()override;
	void hide()override;
	void moveTo(int x1, int y1);
};
