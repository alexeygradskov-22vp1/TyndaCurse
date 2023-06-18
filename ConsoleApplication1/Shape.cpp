#include "Shape.h"
using namespace std;
Shape::Shape() {
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &rt);
}

Shape::Shape(int x1, int y1, int R1) {
	this->x = x1;
	this->y = y1;
	this->R = R1;
	GetClientRect(hwnd, &rt);
}
Shape::~Shape() {
	ReleaseDC(hwnd, hdc); 
}



