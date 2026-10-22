/* Reconstructed from USA ARM9 at 0x020abf98 (408 bytes).
 *
 * 3D display/geometry setup: initialises the display matrix registers at
 * 0x04000060 (MATRIX), the window input register at 0x04000050 and the
 * polygon registers at 0x04000540 / 0x04000580, then hands the scene buffer
 * to the geometry engine.
 */
#include "m2c.h"

void NNS_G3dInit(void);                              /* extern */
void func_020c5dec(s32);                            /* extern */
void func_020ac9ec(M2C_UNK);                        /* extern */
void func_020c98ec(void);                           /* extern */
void NNS_G3dGeSetBuffer(M2C_UNK);                   /* extern */
void func_020ac680(M2C_UNK);                        /* extern */
void func_020ac278(M2C_UNK, M2C_UNK, M2C_UNK);      /* extern */
void func_020ac130(M2C_UNK, M2C_UNK, M2C_UNK);      /* extern */
void func_020ac828(M2C_UNK, u32, s8);               /* extern */
void G3X_SetClearColor(s32, s32, s16, s32, s32);   /* extern */
void func_020aca80(M2C_UNK);                        /* extern */

extern M2C_UNK data_027e08cc;

/* 16-bit register with four bit fields: 5 + 5 + 5 + 1 bits. */
typedef struct {
    u16 f0 : 5;
    u16 f1 : 5;
    u16 f2 : 5;
    u16 f3 : 1;
} Regs16;

void func_020abf98(M2C_UNK arg0) {
    /* Declared in this order so that "a" lands at sp+4 and "b" at sp+6,
     * which is the layout the original code passes to func_020ac130. */
    Regs16 b, a;

    NNS_G3dInit();
    func_020c5dec(1);
    func_020ac9ec(arg0);

    *(volatile u16 *) 0x04000060 = (*(volatile u16 *) 0x04000060 & ~0x3002) | 0x2;
    *(volatile u16 *) 0x04000060 = (*(volatile u16 *) 0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *) 0x04000050 = 0;
    *(volatile u32 *) 0x04000540 = 3;
    *(volatile u16 *) 0x04000060 = *(volatile u16 *) 0x04000060 & 0xcffb;
    *(volatile u16 *) 0x04000060 = (*(volatile u16 *) 0x04000060 & ~0x3000) | 0x8;
    *(volatile u32 *) 0x04000580 = 0xbfff0000;

    func_020c98ec();

    *(volatile u32 *) 0x04001000 |= 0x10000;
    NNS_G3dGeSetBuffer(&data_027e08cc);
    func_020ac680(arg0);
    func_020ac278(arg0, 4, 0);

    a.f0 = 12;
    b.f0 = 31;
    a.f1 = 12;
    b.f1 = 31;
    a.f2 = 12;
    b.f2 = 31;
    a.f3 = 0;
    b.f3 = 0;

    func_020ac130(arg0, &b, &a);
    func_020ac828(arg0, 1, 1);
    G3X_SetClearColor(0, 0x1f, 0x7fff, 0x3f, 0);
    func_020aca80(arg0);
    *(u32 *) ((u8 *) arg0 + 0x48) = 0xd;
}
