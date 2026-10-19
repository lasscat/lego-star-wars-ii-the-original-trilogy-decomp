#include "m2c.h"

s32 func_0205b174(M2C_UNK, u16 *, void **, u8 *, u8 *); /* extern */
s32 func_0205b4e8(M2C_UNK, s32, u8, u8, u16 *);     /* extern */
extern s32 data_020fe55c;

typedef struct {
    u16 a;
    s32 c;
} S;

void *func_0205b0e8(M2C_UNK arg0, u16 *arg1) {
    u8 sp5;
    u8 sp4;
    void *sp10;
    S s;
    s32 temp_r1;

    temp_r1 = func_0205b174(arg0, arg1, &sp10, &sp5, &sp4);
    if ((sp10 == NULL) || ((u32) M2C_FIELD(sp10, u16 *, 0xC) < (u32) *arg1)) {
        s.a = *arg1;
        s.c = data_020fe55c;
        return func_0205b4e8(arg0, temp_r1, sp5, sp4, &s.a) + 0xC;
    }
    return sp10 + 0xC;
}
