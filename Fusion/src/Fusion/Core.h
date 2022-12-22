#pragma once


#ifdef FN_ENABLE_ASSERTS
#define FN_ASSERT(x, ...) { if(!x) { FN_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define FN_CORE_ASSERT(x, ...) { if(!x) { FN_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define FN_ASSERT(x, ...)
#define FN_CORE_ASSERT(x, ...)
#endif