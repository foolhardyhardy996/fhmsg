#pragma once 

#define FHMSG_DEBUG_ENABLE
#define FHMSG_PRINTF_AVALIABLE

#if defined(FHMSG_DEBUG_ENABLE) && defined(FHMSG_PRINTF_AVALIABLE) 
#define FHMSG_DEBUG_printf(...) \
do {\
    printf(__VA_ARGS__);\
} while(0)
#else 
#define FHMSG_DEBUG_printf(...)
#endif