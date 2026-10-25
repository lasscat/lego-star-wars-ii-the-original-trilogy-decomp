#include "m2c.h"

M2C_UNK func_02068134(M2C_UNK *);                   /* extern */
M2C_UNK func_02068148(M2C_UNK *);                   /* extern */
M2C_UNK func_02068260(M2C_UNK *, u8);               /* extern */
M2C_UNK func_020b90e4(u32, u8);                     /* extern */
M2C_UNK func_020b918c();                            /* extern */
M2C_UNK func_020b91c8();                            /* extern */
M2C_UNK func_020b9248();                            /* extern */
extern volatile u8 data_0210db14[];
extern M2C_UNK data_027e0864;

static inline u32 is_idle(void) {
    return data_0210db14[0xA] == 0;
}

void func_020b3998(u8 *arg0, u32 arg1) {
    u8 temp;
    u8 v = arg1;
    u8 *p;

    arg0[1]               = v;
    arg0[0x10]            = v;
    *(s32 *) (arg0 + 0xC) = 0;
    *(s32 *) (arg0 + 8)   = 0xA;
    temp                  = arg0[0x12];
    if (temp != arg0[0x16]) {
        if (temp == 0x1D) {
            func_020b9248();
            if (is_idle() & 1) { // FAKE: '& 1' reproduces the tst r0,#1 test on the materialised flag
                func_020b918c();
                arg0[6]    = 1;
                arg0[0x16] = 0;
            }
        } else {
            func_020b9248();
            if (arg0[6] != 0) {
                func_020b91c8();
                arg0[6] = 0;
            } else {
                func_020b90e4(arg0[0x12], (arg0 + arg0[1])[0x17]);
            }
            arg0[0x16] = arg0[0x12];
            arg0[3]    = 0;
            p          = arg0 + 0x17;
            p[arg0[1]] += 1;
            if (p[arg0[1]] >= 3) {
                p[arg0[1]] = 0;
            }
        }
    }
    temp = arg0[0x15];
    if (temp == 1) {
        func_02068148(&data_027e0864);
    } else if (temp != 2) {
        func_02068260(&data_027e0864, temp);
        func_02068134(&data_027e0864);
    }
}
