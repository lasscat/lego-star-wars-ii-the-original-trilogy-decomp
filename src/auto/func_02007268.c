#include "m2c.h"

M2C_UNK func_020111b0(void *, s32);                /* extern */
void func_02004b78(void *, s32);                   /* extern */

void func_02007268(void *arg0) {
    u32 v;
    void *p;

    if (M2C_FIELD(arg0, u8 *, 0x6ba) == 0 && M2C_FIELD(arg0, u8 *, 0x1ad) == 0) {
        v = (u32) func_020111b0(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x6ac), u32 *, 0x194));
        switch (v) {
            case 0x100:
            case 0x1000:
                func_02004b78(arg0, 0x1e);
                break;
            case 0x200:
            case 0x400:
            case 0x400000:
            case 0x1000000:
                func_02004b78(arg0, 0x24);
                break;
            case 0x800:
                func_02004b78(arg0, 0x2b);
                break;
            case 0x800000:
                func_02004b78(arg0, 0x2a);
                break;
            case 0x4000000:
                func_02004b78(arg0, 0x2a);
                break;
            case 0x2000:
            case 0x4000:
            case 0x8000:
            case 0x10000:
            case 0x40000:
            case 0x80000:
            case 0x200000:
            case 0x8000000:
            case 0x10000000:
                func_02004b78(arg0, 0x2f);
                break;
            case 0x20:
                p = M2C_FIELD(arg0, void **, 0x6ac);
                if (M2C_FIELD(p, u16 *, 0xc) == 4) {
                    M2C_FIELD(*(M2C_UNK **) p, void (**)(void *, void *), 0x38)(p, arg0);
                }
                break;
        }
    }
}
