#include "m2c.h"

extern char data_020fe720[];
extern u8 data_02104914[];

extern int sprintf(char *, const char *, ...);
u32 func_020c93c8(u32, u32);

void func_02066c80(u8 *dest, s32 arg1) {
    s8 buf[0x20];
    s8 *p = buf;
    s32 len;
    u32 n;

    len = sprintf(p, data_020fe720, arg1);
    n   = func_020c93c8(len, 3);
    if (n == 0) {
        n = 3;
    }
    while (n-- != 0) {
        *dest++ = *p++;
        len     = len - 1;
    }
    if (len != 0) {
        do {
            len     = len - 3;
            *dest++ = *(u8 *) (data_02104914 + 1);
            *dest++ = *p++;
            *dest++ = *p++;
            *dest++ = *p++;
        } while (len != 0);
    }
    *dest = 0;
}
