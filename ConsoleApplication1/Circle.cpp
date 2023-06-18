#include "Circle.h"
using namespace std;
Circle::Circle(int x1, int y1, int R1, COLORREF color):Shape(x1, y1, R1) {
	colors = color;
}
void Circle::show() {
	HPEN pen;
	HBRUSH brush;
	pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	brush = CreateSolidBrush(colors);
	if (((x - R) < 0) || ((x + R) >rt.right) || ((y - R) <0) || ((y + R) >rt.bottom)
		)throw ShapeException("Фигура выходит за границу окна");
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x-R, y-R,x+R,y+R);
	DeleteObject(pen);
	DeleteObject(brush);
}
void Circle::hide() {
	HPEN pen;
	HBRUSH brush;
	pen = CreatePen(PS_SOLID, 2, RGB(242,242,242));
	brush = CreateSolidBrush(RGB(242, 242, 242));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - R, y - R, x + R, y + R);
	DeleteObject(pen);
	DeleteObject(brush);
}

void Circle::moveTo(int x1, int y1) {
	this->hide();
	this->x = x1;
	this->y = y1;
	this->show();
}
