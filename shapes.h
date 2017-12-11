#pragma once
#include "conslib.h"

class Shape {
public:
	int x, y;

	Shape();
	~Shape();
	Shape(int height_figure, int width_figure, int difference_x_figure, int difference_y_figure);
	void virtual figure(bool draw) = 0 ;
	void speed();
	friend void paint_pair(Shape* figure[], int size);
protected:	
	int difference_x , difference_y ;
	int fix_height_figure, fix_width_figure;
	const int width = 80, height = 30;
  };

class Rectangle :public Shape {
public:
	Rectangle();
	void figure(bool draw);
};

class Quadratic :public Shape {
public:
	Quadratic();
	void figure(bool draw);
};