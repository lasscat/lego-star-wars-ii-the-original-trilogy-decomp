#include "m2c.h"

void func_0205e144(void *arg0, s32 arg1, s32 arg2) {
    u32 count;
    u32 head;
    u32 i;
    u32 p;

    count = (u32) (arg2 - 1);
    head  = (u32) ((s32 *) arg0)[arg1 + 1];
    i     = 0;
    if (count != 0) {
        p = head;
        do {
            i += 1;
            *(s32 *) (p + 4) = (s32) ((i * 0xC) + head);
            p += 0xC;
        } while (i < count);
    }
    *(s32 *) (head + arg2 * 0xC - 8) = ((s32 *) arg0)[6];
    ((s32 *) arg0)[6]                = (s32) head;
    M2C_FIELD(arg0, u16 *, 0x1E)     = (u16) (M2C_FIELD(arg0, u16 *, 0x1E) + arg2);
}
