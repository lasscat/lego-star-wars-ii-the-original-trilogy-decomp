#include "m2c.h"

extern s32 data_027e02a8;
extern void **data_021092f4;

typedef void *(*VFunc)(void **, M2C_UNK);

void func_020aae4c(s16 *out, void *a1, u8 a2) {
    if (data_027e02a8 & 0x40) {
        VFunc fnptr = (VFunc) M2C_FIELD(*data_021092f4, VFunc(**)(void **, M2C_UNK), 0);
        out[0]      = M2C_FIELD(fnptr(data_021092f4, a2), u16 *, 0x6a);
    } else if (a2 == 0) {
        out[0] = M2C_FIELD(a1, u16 *, 0x42);
    } else {
        out[0] = 0;
    }
}
