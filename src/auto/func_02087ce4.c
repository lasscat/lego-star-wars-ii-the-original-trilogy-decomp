#include "m2c.h"

u32 func_0208c72c(M2C_UNK, s32, s32);    /* extern */
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02104dc4;

#define ROW(a) ((u16 *) ((u8 *) *(void **) ((s8 *) (a) + 0xd8) + 0x600))

void func_02087ce4(void *arg0, s32 arg1, s32 arg2) {
    u32 v;
    u16 *dst;
    s32 idx;
    u8 flag;

    idx  = arg1 + (arg2 << 5);
    flag = *(u8 *) (*(void **) ((s8 *) &data_0210930c + 0x68) + 0x47a);
    dst  = (u16 *) (*(u8 **) ((s8 *) arg0 + 0xd8) + idx * 2);
    v    = func_0208c72c(&data_02104dc4, flag, idx);
    if (*(u8 *) ((s8 *) arg0 + 0xcf) != (u8) v) {
        *(u8 *) ((s8 *) arg0 + 0xcf) = (u8) v;
        if (v > 9) {
            dst[0]    = ROW(arg0)[1];
            dst[0x20] = ROW(arg0)[0x21];
            dst[1]    = ROW(arg0)[0];
            dst[0x21] = ROW(arg0)[0x20];
        } else {
            dst[1]    = ROW(arg0)[v];
            dst[0x21] = ROW(arg0)[v + 0x20];
        }
    }
    if (*(u8 *) ((s8 *) arg0 + 0xcb) != 0) {
        return;
    }
    *(u8 *) ((s8 *) arg0 + 0xcb) = 1;
    dst[2]                       = ROW(arg0)[10];
    dst[0x22]                    = ROW(arg0)[0x2A];
    dst[3]                       = ROW(arg0)[1];
    dst[0x23]                    = ROW(arg0)[0x21];
    dst[4]                       = ROW(arg0)[0];
    dst[0x24]                    = ROW(arg0)[0x20];
}
