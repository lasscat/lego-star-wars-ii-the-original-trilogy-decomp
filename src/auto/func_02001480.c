#include "m2c.h"

extern M2C_UNK data_021092f4;
extern M2C_UNK data_02102900;
extern M2C_UNK data_0210b348;
extern M2C_UNK data_027e02a8;
extern M2C_UNK data_02101d7c;

extern void func_02072cd0(void);
extern void func_0205ecc4(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
extern void func_020b01a8(void);
extern u16 func_020b01bc(void);
extern void func_020b8df0(void);
extern void func_020d403c(M2C_UNK, M2C_UNK, M2C_UNK);
extern void func_020b8e18(void);
extern void MIi_LockCard(void);
extern M2C_UNK CARDi_ReadRomID(void);
extern void MIi_UnlockCard(void);
extern void PM_ForceToPowerOff(s32);
extern void OS_Halt(void);

typedef s32 (*Method)(s32 *self);

typedef struct {
    Method *vtable;
} Obj;

#define SELF (*(Obj **) &data_0210b348)

void func_02001480(void) {
    u8 flag;
    s32 *p;
    s32 v;
    s32 r0;

    flag = (u8) ((s32) (*(u16 *) 0x027FFFA8 & 0x8000) >> 0xF);
    if (flag != 1) {
        return;
    }
    if (*(s32 *) &data_021092f4 != 0) {
        func_02072cd0();
        func_0205ecc4(&data_02102900, 0xf, 0, 0, 0, 0);
        func_0205ecc4(&data_02102900, 0x26, 1, 0, 0, 0);
        M2C_FIELD(&data_02102900, s32 *, 0x84) = 1;
        M2C_FIELD(&data_02102900, s32 *, 0x64) = 1;
    }
    p = M2C_FIELD(&data_02102900, s32 *, 0x4);
    if ((p != 0 ? M2C_FIELD(p, s32 *, 0x4) : 0) == 0x24) {
        func_020b01a8();
        for (;;) {
            if (func_020b01bc() == 0) {
                break;
            }
            if (func_020b01bc() == 5) {
                break;
            }
            if (func_020b01bc() == 1) {
                break;
            }
        }
        SELF->vtable[1]((s32 *) SELF);
        if (SELF->vtable[20]((s32 *) SELF) == 0) {
            do {
                SELF->vtable[2]((s32 *) SELF);
            } while (SELF->vtable[20]((s32 *) SELF) == 0);
        }
        func_0205ecc4(&data_02102900, 0xf, 0, 0, 0, 0);
        func_0205ecc4(&data_02102900, 0x26, 1, 0, 0, 0);
        M2C_FIELD(&data_02102900, s32 *, 0x84) = 1;
        M2C_FIELD(&data_02102900, s32 *, 0x64) = 1;
    }
    if (*(u32 *) &data_027e02a8 & 0x100) {
        return;
    }
    func_020b8df0();
    func_020d403c(0xc, 0, 0);
    func_020b8e18();
    r0 = 0;
    if (*(u32 *) &data_027e02a8 & 0x800) {
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
        PM_ForceToPowerOff(r0);
        OS_Halt();
        for (;;) {
        }
    }
}
