#ifndef _OOP_OOP_H_
#define _OOP_OOP_H_

#include <stdlib.h>

#define NEW(typename, ...) \
	typename##_ctor(malloc(sizeof(typename)), __VA_ARGS__);

#define NEW_0(typename) \
	typename##_ctor_0(malloc(sizeof(typename)));

#define DELETE(typename, ptr) \
	do { \
		typename##_dtor(ptr); \
		free(ptr); \
	} \
	while(0);

#define CTOR_IMPL_START(typename, ...) \
	typename* typename##_ctor(typename* this, __VA_ARGS__) { \
		if(!this) \
			return NULL;

#define CTOR_IMPL_END \
	return this; \
	}

#define CTOR_IMPL_START_0(typename) \
	typename* typename##_ctor_0(typename* this) { \
		if(!this) \
			return NULL;

#define CTOR_IMPL_END_0 \
	return this; \
	}

#define CTOR_DECL(typename, ...) \
	typename* typename##_ctor(typename*, __VA_ARGS__);

#define CTOR_DECL_0(typename) \
	typename* typename##_ctor_0(typename*);

#define DTOR_IMPL_START(typename) \
	void typename##_dtor(typename* this) { \
		(void) this;

#define DTOR_IMPL_END }

#define DTOR_DECL(typename) \
	void typename##_dtor(typename*);

#define CALL_0(object, method) \
	(object)._##method(&(object))

#define CALL(object, method, ...) \
	(object)._##method(&(object), __VA_ARGS__);

#define OBJECT_DECL(typename) \
	typedef struct typename typename;

#endif
