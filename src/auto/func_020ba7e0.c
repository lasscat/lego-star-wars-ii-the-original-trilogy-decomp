#include "m2c.h"

extern u32 data_027e02a8;
extern M2C_UNK data_02101d7c;
extern void MIi_LockCard(void);
extern s32 CARDi_ReadRomID(void);
extern void MIi_UnlockCard(void);
extern void func_02054e78(s32);

void func_020ba7e0(s32 a0) {
    u32 v;
    s32 r0;
    if (*(u32 *)&data_027e02a8 & 0x800) {
        MIi_LockCard();
        v = CARDi_ReadRomID();
        MIi_UnlockCard();
        if (v != *(u32 *) &data_02101d7c) {
            r0 = 1;
            goto L1;
        }
    }
    r0 = 0;
L1:
    if (r0 != 0) {
        func_02054e78(0);
        for (;;) {
        }
    }
}
