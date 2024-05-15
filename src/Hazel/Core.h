#pragma once

#define BIT(x) (1 << x)

#define HZ_ENABLE_ASSERTS

#ifdef HZ_ENABLE_ASSERTS
#define HZ_ASSERT(x, ...)                                   \
    {                                                       \
        if (!(x))                                           \
        {                                                   \
            HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            return;                                         \
        }                                                   \
    }
#define HZ_CORE_ASSERT(x, ...)                                   \
    {                                                            \
        if (!(x))                                                \
        {                                                        \
            HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            return;                                              \
        }                                                        \
    }
#else
#define HZ_ASSERT(x, ...)
#define HZ_CORE_ASSERT(x, ...)
#endif
