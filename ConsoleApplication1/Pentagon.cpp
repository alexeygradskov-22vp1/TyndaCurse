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
	int x1 = x;
	int y1 = y - R-(R*0,13);
	int x2 = x + R * cos(0.31) + (R * 0, 15);
	int y2 = y - R * sin(0.31) - (R * 0, 7);
	int x3 = x + R * cos(0.94) + (R * 0, 9);
	int y3 = y + R * sin(0.94) + (R * 0,12);
	int x5 = x - R * cos(0.31) - (R * 0, 15);
	int y5 = y - R * sin(0.31) - (R * 0, 7);
	int x4 = x - R * cos(0.94) - (R * 0, 9);
	int y4 = y + R * sin(0.94) + (R * 0, 12);
	POINT points[] = {{x1,y1}, {x2,y2},{x3,y3},{x4,y4},{x5,y5}};
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
	POINT points[] = { {x , y - R - (R * 0,13)},{x + R * cos(0.31) + (R * 0, 15),y - R * sin(0.31) - (R * 0, 7)}
		,{ x + R * cos(0.94) + (R * 0, 9), y + R * sin(0.94) + (R * 0,12)},
			{x - R * cos(0.94) - (R * 0, 9), y + R * sin(0.94) + (R * 0, 12)}
	,{x - R * cos(0.31) - (R * 0, 15),y - R * sin(0.31) - (R * 0, 7)} };
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
