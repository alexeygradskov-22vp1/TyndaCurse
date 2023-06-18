#pragma once
#include<iostream>
#include<stack>
#include "Shape.h"
#include <list>
using namespace std;
class Stack { // Класс стека на основе списка
private:
	stack<Shape*,list <Shape*>> figures; //Объявление списка
public:
	Stack() {};
	void push(Shape*); //Добавление фигуры в стек
	Shape* pop(); //Удаление последнего элемента из стека
	bool is_empty(); //Проверка, пуст ли стек
	void clear(); //Очищение стека
	void showAll(); //Показать все фигуры из стека
	void hideAll(); //Спрятать все фигуры из стека
};
