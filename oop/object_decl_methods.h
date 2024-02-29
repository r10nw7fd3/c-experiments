#define ENUMERATE_METHOD(typename, name, ret_type, ...) ret_type(*_##name)(typename*, __VA_ARGS__);
#define ENUMERATE_METHOD_0(typename, name, ret_type) ret_type(*_##name)(typename*);
ENUMERATE_METHODS
#undef ENUMERATE_METHOD
#undef ENUMERATE_METHOD_0
