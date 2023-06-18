#include <iostream>
#include "Circle.h"
#include "Pentagon.h"
#include "ComplexFigure.h"
#include "Stack.h"
#include <iostream>

const int NotUsed = system("color F0");

int main()
{
	SetConsoleTitle((LPCWSTR)L"22VP1_22_PentagonCircle");
	setlocale(LC_ALL, "Russian");
	Circle* circle = new Circle(300, 300, 60, RGB(0, 255, 127));
	Circle* circle1 = new Circle(450, 250, 60, RGB(0, 255, 127));
	Pentagon* pentagon = new Pentagon(300, 300, 60, RGB(244, 164, 96));
	Pentagon* pentagon1 = new Pentagon(150, 350, 60, RGB(244, 164, 96));
	Stack container;
	try {
		circle1->show();
		pentagon1->show();
		ComplexFigure* complex = new ComplexFigure(circle, pentagon);
		complex->show();
		Sleep(2000);
		circle1->hide();
		pentagon1->hide();
		complex->moveTo(400, 400);
	}
	catch (Shape::ShapeException& e) {
		cerr << e.what() << endl;
	}
	return 0;
}
