#include "m2c.h"
typedef struct {
    u16 v;
} H;
void func_02029120(s32 a0, H a1) {
    u16 v = a1.v;
    if (a0 == 0) {
        return;
    }
    if (*(u16 *) (a0 + 0xca) != v) {
        *(u16 *) (a0 + 0xca) = v;
        *(u8 *) (a0 + 0xd0)  = 1;
    }
    *(u16 *) (a0 + 0x6b4) = v;
}
