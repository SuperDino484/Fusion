#pragma once

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#ifdef FN_ENABLE_ASSERTS
#define FN_ASSERT(x, ...) { if(!x) { FN_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define FN_CORE_ASSERT(x, ...) { if(!x) { FN_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define FN_ASSERT(x, ...)
#define FN_CORE_ASSERT(x, ...)
#endif