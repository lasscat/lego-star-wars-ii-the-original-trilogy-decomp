#include "m2c.h"

extern M2C_UNK data_0210930c[];

u32 func_02027124(s32, ...);
u32 func_0207513c(s32, u32, u32, u32);
u8 func_02027240(s32);

u8 func_02027098(s32 *obj, s32 a1, s32 a2, s32 a3) {
    u32 v;
    u32 r2;
    u32 r1;
    if (*(s32 *)obj == 0) {
        *(s32 *)obj = *(s32 *)((u8 *)data_0210930c + 0x3c);
    }
    *(u8 *)((u8 *)obj + 0x54) = 0;
    *(u8 *)((u8 *)obj + 0x56) = 0;
    r1 = func_02027124(obj, a1);
    if (r1 != 0) {
        r2 = func_02027124(obj, a2);
        if (r2 != 0) {
            v = func_0207513c(*(s32 *)obj, r1, r2, a3);
            *(u8 *)((u8 *)obj + 0x54) = v;
            if ((v & 0xff) == 1) {
                *(u8 *)((u8 *)obj + 0x55) = func_02027240(obj);
            }
        }
    }
    return *(u8 *)((u8 *)obj + 0x54);
}
