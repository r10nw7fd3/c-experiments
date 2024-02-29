#define ENUMERATE_METHOD(typename, name, ret_type, ...) this->_##name = typename##_##name;
#define ENUMERATE_METHOD_0(typename, name, ret_type) this->_##name = typename##_##name;
ENUMERATE_METHODS
#undef ENUMERATE_METHOD
#undef ENUMERATE_METHOD_0
