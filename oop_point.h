#ifndef _OOP_POINT_H_
#define _OOP_POINT_H_

#include "oop/oop.h"

OBJECT_DECL(Point);

#define ENUMERATE_METHODS \
	ENUMERATE_METHOD(Point, add, void, const Point*) \
	ENUMERATE_METHOD(Point, sub, void, const Point*) \
	ENUMERATE_METHOD(Point, mul, void, const Point*) \
	ENUMERATE_METHOD(Point, div, void, const Point*) \
	ENUMERATE_METHOD_0(Point, print, void)

#include "oop/method_decls.h"
CTOR_DECL(Point, int x, int y);
CTOR_DECL_0(Point);
DTOR_DECL(Point);

struct Point {
	int x;
	int y;

#include "oop/object_decl_methods.h"
};

#endif
