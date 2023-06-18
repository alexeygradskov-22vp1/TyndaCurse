#define _USE_MATH_DEFINES
#include "Pentagon.h"
#include <cmath>
using namespace std;
Pentagon::Pentagon(int x, int y, int R, COLORREF color) :Shape(x, y, R) {
	colors = color;
};
void Pentagon::show() {
	HPEN pen;
	HBRUSH brush;
	double angle = 2 * M_PI / 5;
	for (int i = 0; i < 5; i++) {
		int x1 = x + R * cos(i * angle - 3.14159 / 10);
		int y1 = y + R * sin(i * angle - 3.14159 / 10);
		points[i] = { x1, y1 };
	}
	if (points[0].x > rt.right ||
		points[1].y > rt.bottom || 
		points[3].x<rt.left||
		points[4].y<rt.top) {
		throw ShapeException("Пятиугольник выходит за границы окна");
	}
	pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	brush = CreateSolidBrush(colors);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Polygon(hdc, points, 5);
	DeleteObject(pen);
	DeleteObject(brush);
}
void Pentagon::hide() {
	HPEN pen;
	HBRUSH brush;
	pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));
	brush = CreateSolidBrush(RGB(242,242 ,242));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Polygon(hdc, points, 5);
	DeleteObject(pen);
	DeleteObject(brush);
}

void Pentagon::moveTo(int x1, int y1) {
	this->hide();
	this->x = x1;
	this->y = y1;
	this->show();
}
