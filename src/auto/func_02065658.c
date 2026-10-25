#include "m2c.h"

typedef struct {
    u16 v;
} H;
extern s32 func_02053b14(void *);
extern s32 func_02053b50(void *);
extern s32 func_02053964(void *);
extern s16 func_02053a9c(void *);

static inline H getH(void *p) {
    H result;
    result.v = (u16) func_02053a9c(p);
    return result;
}

void func_02065658(void *arg0, void *arg1) {
    H value0;
    H value1;
    H value2;
    s32 index;
    M2C_FIELD(arg0, s32 *, 0x1C) = func_02053b14(arg1);
    M2C_FIELD(arg0, s32 *, 0x20) = func_02053b50(arg1);
    if (func_02053964(arg1)) {
        value0                       = getH(arg1);
        index                        = ((u32) value0.v << 16) >> 30;
        M2C_FIELD(arg0, s32 *, 0x24) = 0x10 << index;
        M2C_FIELD(arg0, s32 *, 0x28) = 0x40;
        M2C_FIELD(arg0, s32 *, 0x2C) = 1;
    } else {
        M2C_FIELD(arg0, s32 *, 0x24) = 0x20;
        value1                       = getH(arg1);
        index                        = ((u32) value1.v << 24) >> 31;
        M2C_FIELD(arg0, s32 *, 0x28) = (index + 1) << 5;
        value2                       = getH(arg1);
        M2C_FIELD(arg0, s32 *, 0x2C) = ((u32) value2.v << 24) >> 31;
    }
}
