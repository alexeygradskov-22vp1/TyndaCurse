#pragma once
#include"Shape.h"
class Pentagon:public Shape {
private:
	POINT points[5];
public:
	Pentagon() {};
	Pentagon(int x1, int y1, int R1, COLORREF color);
	void show() override;
	void hide() override;
	void moveTo(int x1, int y1) override;
	virtual~Pentagon() {};
};
