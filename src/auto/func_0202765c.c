#include "m2c.h"

extern M2C_UNK data_0210930c;

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u16 f0;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
} OutVec;

extern s32 func_02067b0c(s32 *, s32);
extern u32 func_02067b18(void *);
extern void func_0202732c(void *);
extern void func_02027348(void *, void *);
extern void func_020274e8(void *, void *, void *);
extern s32 func_0200aef8(s32 *, s32 *, UnkVal);
extern s32 func_0201eec4(s32 *, s32 *, UnkVal);

void func_0202765c(void *arg0, void *arg1, s32 arg2, u8 *arg3, s32 arg4, u8 arg5, u8 arg6, u8 *arg7) {
    UnkVal md;
    OutVec out;
    s32 v[3];
    u8 *base;
    s32 *node;
    s16 *pv;
    s32 a, b, c;
    u8 changed;

    base = (u8 *) M2C_FIELD(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, u8 **, 0x68), u8 **, 0x38C), s32 *, 4), s32 *, 0x34);
    md.v = 0xf000;
    pv   = (s16 *) func_02067b0c((s32 *) (base + arg2 * 8), *arg3);
    node = (s32 *) (base + arg2 * 8);
    c    = pv[2] << 12;
    b    = pv[1] << 12;
    a    = pv[0] << 12;
    v[0] = a;
    v[1] = b;
    v[2] = c;
    func_0202732c(arg0);
    changed = 0;
    if (arg7) {
        *arg7 = 0;
    }
    if (arg6 == 0) {
        if (func_0200aef8(v, (s32 *) ((u8 *) arg1 + 0xB0), md)) {
            goto do_switch;
        }
    }
    if (arg6 != 0) {
        if (func_0201eec4(v, (s32 *) ((u8 *) arg1 + 0xB0), md)) {
            goto do_switch;
        }
    }
    goto end;
do_switch:
    switch (arg4) {
        case 0:
        case 3:
            if (arg5) {
                u32 max;
                *arg3 = *arg3 + 1;
                max   = func_02067b18((void *) node);
                if (*arg3 >= max) {
                    *arg3 = 0;
                }
            } else {
                *arg3 = *arg3 - 1;
                if (*arg3 == 0) {
                    *arg3 = func_02067b18((void *) node) - 1;
                }
            }
            break;
        case 1:
        case 4:
            if (arg5) {
                u32 max = func_02067b18((void *) node);
                if (*arg3 >= max - 1) {
                    if (arg7) {
                        *arg7 = 1;
                    }
                    return;
                }
                *arg3 = *arg3 + 1;
            } else {
                if (*arg3 == 0) {
                    if (arg7) {
                        *arg7 = 1;
                    }
                    return;
                }
                *arg3 = *arg3 - 1;
            }
            break;
        case 2:
        case 5:
            if (arg5) {
                u32 max = func_02067b18((void *) node);
                if (*arg3 < max - 1) {
                    *arg3 = *arg3 + 1;
                } else {
                    *arg3   = *arg3 - 1;
                    changed = 1;
                }
            } else {
                if (*arg3 == 0) {
                    *arg3   = *arg3 + 1;
                    changed = 1;
                    break;
                }
                *arg3 = *arg3 - 1;
            }
            break;
    }
end:
    func_020274e8(&out, arg1, v);
    func_02027348(arg0, &out);
    if (changed == 1) {
        M2C_FIELD(arg0, u8 *, 3) = 1;
    }
}
