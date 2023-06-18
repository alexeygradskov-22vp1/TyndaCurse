#include"Stack.h"
bool Stack::is_empty() 
{
	return figures.empty();
}

void Stack::push(Shape* figr)
{
	figures.push(figr);
}

Shape* Stack::pop()
{
	Shape* result = figures.top();
	figures.pop();
	return result;
}

void Stack::clear()
{
	while (!figures.empty())
	{
		figures.pop();
	}
}

void Stack::showAll()
{
	while (!is_empty()) {
		figures.top()->show();
		figures.pop();
	}

}

void Stack::hideAll()
{
	while (!is_empty()) {
		figures.top()->hide();
		figures.pop();
	}
}