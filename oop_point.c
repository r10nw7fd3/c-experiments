#include "oop_point.h"
#include <stdio.h>

int main(void) {
	Point* a = NEW(Point, 1, 5);
	Point* b = NEW_0(Point);
	b->x = 4; b->y = 2;
	Point c;
	Point_ctor(&c, 1, 1);
	Point d;
	Point_ctor(&d, 2, 2);
	Point e;
	Point_ctor(&e, 2, 2);
	puts("init:"); CALL_0(*a, print);

	CALL(*a, add, b);
	puts("after add:"); CALL_0(*a, print);
	
	CALL(*a, sub, &c);
	puts("after sub:"); CALL_0(*a, print);

	CALL(*a, mul, &d);
	puts("after mul:"); CALL_0(*a, print);

	CALL(*a, div, &e);
	puts("after div:"); CALL_0(*a, print);

	DELETE(Point, a);
	DELETE(Point, b);
	return 0;
}

void Point_add(Point* this, const Point* point) {
	this->x += point->x;
	this->y += point->y;
}

void Point_sub(Point* this, const Point* point) {
	this->x -= point->x;
	this->y -= point->y;
}

void Point_mul(Point* this, const Point* point) {
	this->x *= point->x;
	this->y *= point->y;
}

void Point_div(Point* this, const Point* point) {
	this->x /= point->x;
	this->y /= point->y;
}

void Point_print(Point* this) {
	printf("x: %d, y: %d\n", this->x, this->y);
}

CTOR_IMPL_START(Point, int x, int y)
	this->x = x;
	this->y = y;

#include "oop/ctor_methods.h"

CTOR_IMPL_END

CTOR_IMPL_START_0(Point)
#include "oop/ctor_methods.h"
CTOR_IMPL_END_0

DTOR_IMPL_START(Point)
DTOR_IMPL_END

