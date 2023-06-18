#include "ComplexFigure.h"
#include "Circle.h"
#include "Pentagon.h"
using namespace std;
ComplexFigure::ComplexFigure(Circle* _c, Pentagon* _p){
	if ((_c->x == _p->x) && (_c->y == _p->y) && (_c->R == _p->R)) {
		pentagon.x = _p->x;
		pentagon.y = _p->y;
		pentagon.R = _p->R;
		pentagon.colors = _p->colors;
		circle.x = _c->x;
		circle.y = _c->y;
		circle.R = _c->R;
		circle.colors = _c->colors;
	}
	else {
		throw ShapeException("Координаты фигур отличаются");
	}
};
void ComplexFigure::show() {
	pentagon.show();
	circle.show();
}
void ComplexFigure::hide() {
	circle.hide();
	pentagon.hide();
}
void ComplexFigure::moveTo(int x1, int y1) {
	circle.moveTo(x1, y1);
	pentagon.moveTo(x1, y1);
	pentagon.show();
	circle.show();
	
}