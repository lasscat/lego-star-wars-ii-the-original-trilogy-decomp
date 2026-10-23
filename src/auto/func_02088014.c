#include "m2c.h"

extern M2C_UNK data_0210930c;
extern M2C_UNK data_02104dc4;

extern void func_02087a54(void *, s32, void *, void *);
extern void func_02087ce4(void *, s32, s32);
extern void func_02087e14(void *);
extern s32 func_0208c77c(s32 *, u32);
extern void func_020b8f70(s32, s32, s32);
extern void func_020881d0(void);

s32 func_02088014(void *a0, u32 a1, void *a2, void *a3) {
    s32 res;
    u32 v;
    u8 *p;
    u32 *q;
    u32 *r;

    switch (a1) {
        case 0x16:
            M2C_FIELD(a0, u8 *, 0xcc) = 1;
            func_020b8f70(0x66, 0, 1);
            return 1;
        case 0x13:
            if (M2C_FIELD(a0, u8 *, 0xca) == 0) {
                break;
            }
            v = M2C_FIELD(a2, u32 *, 0);
            if (v >= 9 && v <= 0xe) {
                break;
            }
            M2C_FIELD(a0, u8 *, 0xca) = 0;
            r                         = M2C_FIELD(a0, u32 **, 0xd0);
            v                         = M2C_FIELD(r, u32 *, 8) | 1;
            M2C_FIELD(r, u32 *, 8)    = v;
            p                         = M2C_FIELD(&data_0210930c, u8 **, 0x68);
            res                       = func_0208c77c((s32 *) &data_02104dc4, p[0x47a]);
            q                         = M2C_FIELD(a0, u32 **, 0xd4);
            if (res != 0) {
                M2C_FIELD(q, u32 *, 8) |= 1;
            } else {
                M2C_FIELD(q, u32 *, 8) &= ~1;
            }
            func_02087ce4(a0, 5, 1);
            func_02087e14(a0);
            break;
        case 0x17:
            func_02087a54(a0, 0, a3, a2);
            return 1;
        case 0x18:
            func_02087a54(a0, 1, a3, a2);
            return 1;
        case 0xb:
            func_02087a54(a0, 3, a3, a2);
            break;
        case 0x1b:
            break;
        case 0x1c:
            func_020881d0();
            return 1;
        default:
            return 0;
    }
    return 0;
}
