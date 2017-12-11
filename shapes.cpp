#include <iostream>
#include "shapes.h"

using namespace std;

Shape::Shape() {};

Shape::~Shape() {};

Shape::Shape(int height_figure, int width_figure, int difference_x_figure, int difference_y_figure) {
	this->fix_height_figure = height_figure;
	this->fix_width_figure = width_figure;
	this->difference_x = difference_x_figure;
	this->difference_y = difference_y_figure;
};

Rectangle::Rectangle() :Shape(4, 8, 1, 1) {};

Quadratic::Quadratic() :Shape(4, 4 , 1 , 1) {};

void Shape::speed() {
	x += difference_x;
	y -= difference_y;

	if (x <= 0) {
		difference_x *= (-1);
		x = 0;
	}

	if (x + fix_width_figure > width) {
		difference_x *= (-1);
		x = width - fix_width_figure;
	}

	if (y <= 0) {
		difference_y *= (-1);
		y = 0;
	}

	if (y + fix_height_figure > height) {
		difference_y *= (-1);
		y = height - fix_height_figure;
	}

}

void Rectangle::figure(bool draw) {
	int i = x;
	int j = y; 
	for (i ; i < (x + 8); ++i) {
		for (j = y; j < (y + 4); ++j)
			printat(i, j, draw?"$":" ");
	}
}

void Quadratic::figure(bool draw) {
	int i = x;
	int j = y;
	for (i; i < (x + 4); ++i) {
		for (j = y; j < (y + 4); ++j)
			printat(i, j, draw?"$":" ");
	}
}

void paint_pair(Shape* figure[], int size /*A, Shape* B*/) {
	for (int i = 0; i < 1000; ++i) {
		/*A->speed();
		B->speed();*/
		for (int k = 0; k < size; ++k)
		{		
			figure[k]->speed();
			figure[k]->figure(true);
		}
		pause(30);
		for (int k = 0; k < size; ++k)
		{
			figure[k]->figure(false);
		}
		///

			for (int n = 0; n < size; ++n) {
				for (int j = n+1; j < size; ++j) {
					Shape* A = figure[n];
					Shape* B = figure[j];
					if (((B->x <= A->x + A->fix_width_figure && B->x >= A->x) && (B->y > A->y - B->fix_height_figure && B->y < A->y + A->fix_height_figure)) ||
						((A->x <= B->x + B->fix_width_figure && A->x >= B->x) && (A->y > B->y - A->fix_height_figure && A->y < B->y + B->fix_height_figure))) {
						A->difference_x *= -1;
						B->difference_x *= -1;
					}
					if (((B->y <= A->y + A->fix_height_figure && B->y >= A->y) && (B->x > A->x - B->fix_width_figure && B->x < A->x + A->fix_width_figure)) ||
						((A->y <= B->y + B->fix_height_figure && A->y >= B->y) && (A->x > B->x - A->fix_width_figure && A->x < B->x + B->fix_width_figure))) {
						A->difference_y *= -1;
						B->difference_y *= -1;
					}
				}
			//system("cls");
		}
		/*figure[0]->speed();
		figure[1]->speed();
		figure[2]->speed();*/
	
	}
}

int main() {
	setCursorVisibility(false); 
	//Shape* shape1 = nullptr;
	//shape1 = new Rectangle();
	//Shape* shape2 = nullptr;
	//shape2 = new Quadratic();
	Shape* figures[3] = { new Rectangle(), new Quadratic(), new Rectangle() };
	figures[0]->x = 1;
	figures[0]->y = 10;
	figures[1]->x = 19;
	figures[1]->y = 12;
	figures[2]->x = 2;
	figures[2]->y = 4;
	//shape1->x = 1;
	//shape1->y = 10;
	//shape2->x = 19;
	//shape2->y = 12;
	
	paint_pair(figures/*shape1, shape2*/, 3);
	system("pause");
	return 0;
}
