#include <stdio.h>
#include <stdlib.h>

#define VECTOR_DEFINE_FOR_TYPE(type) \
	typedef struct { \
		type* data; \
		size_t size; \
		size_t capacity; \
\
		int (*append)(void*, type); \
		int (*pop)(void*, type*); \
		void (*free)(void*); \
	} Vector_##type; \
\
	int vector_##type##_append(void*, type); \
	int vector_##type##_pop(void*, type*); \
	void vector_##type##_free(void*); \
\
	int vector_##type##_init(Vector_##type* vec, size_t capacity) { \
		vec->append = vector_##type##_append; \
		vec->pop = vector_##type##_pop; \
		vec->free = vector_##type##_free; \
\
		vec->data = malloc(sizeof(type) * capacity); \
		if(!vec->data) \
			return 1; \
\
		vec->size = 0; \
		vec->capacity = capacity; \
		return 0; \
	} \
\
	int vector_##type##_append(void* vec_, type value) { \
		Vector_##type* vec = vec_; \
		if(vec->size + 1 > vec->capacity) { \
			size_t new_capacity = vec->capacity + 20; \
			int* new_data = realloc(vec->data, sizeof(type) * new_capacity); \
			if(!new_data) \
				return 1; \
\
			vec->data = new_data; \
			vec->capacity = new_capacity; \
		} \
\
		vec->data[vec->size++] = value; \
		return 0; \
	} \
\
	int vector_##type##_pop(void* vec_, type* out) { \
		Vector_##type* vec = vec_; \
		if(vec->size <= 0) \
			return 1; \
\
		if(out) \
			*out = vec->data[vec->size]; \
		--vec->size; \
		return 0; \
	} \
\
	void vector_##type##_free(void* vec_) { \
		Vector_##type* vec = vec_; \
		free(vec->data); \
		vec->data = NULL; \
		vec->size = 0; \
		vec->capacity = 0; \
	}

#define vector_append(vec, value) \
	vec.append(&vec, value);
#define vector_pop(vec, out) \
	vec.pop(&vec, out);
#define vector_free(vec) \
	vec.free(&vec);

VECTOR_DEFINE_FOR_TYPE(int)

int main(void) {
	Vector_int vec;
	if(vector_int_init(&vec, 5))
		return 1;

	vector_append(vec, 1);
	vector_append(vec, 2);
	vector_append(vec, 3);
	vector_append(vec, 4);
	vector_append(vec, 5);

	vector_append(vec, 6);

	for(size_t i = 0; i < vec.size; ++i)
		printf("%i ", vec.data[i]);
	printf("\n");

	vector_pop(vec, NULL);
	vector_pop(vec, NULL);
	
	for(size_t i = 0; i < vec.size; ++i)
		printf("%i ", vec.data[i]);
	printf("\n");

	vector_free(vec);

	return 0;
}
