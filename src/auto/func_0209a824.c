/* Reconstructed from USA ARM9 at 0x0209a824 (596 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct Flag {
    u8 pad00[0x08];
    s32 f08;
} Flag;

typedef struct Desc {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Desc;

typedef struct Pair {
    s16 a;
    s16 b;
} Pair;

typedef struct Out {
    u32 a;
    u32 b;
} Out;

typedef struct Obj {
    u8 pad00[0x30];
    u8 f30[0x34];
    Flag *f64;
    Flag *f68[4];
    Flag *f78;
    u8 f7c[4];
    u8 f80;
    u8 pad81[0x2b];
    Flag *fac[4];
    u8 padbc[0x2c];
    s32 fe8;
} Obj;

extern M2C_UNK data_021027f8;
extern u16 data_020ffa28[];

extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, void *, Desc);
extern void func_02055b24(s32, s32, s32, s32, s32);
extern void func_0209adb4(void *, s32, s32, s32, s32, s32, s32);

void func_0209a824(Obj *self) {
    Out out;
    Pair pair;
    Desc desc;
    Flag *p;
    u8 i;

    if (self->fe8 == 0) {
        pair.a = 0;
        pair.b = 0;
        desc.a = 0;
        desc.b = 0;
        desc.c = 0;
        desc.d = 0;
        func_02054c80(&out, self->f30, 0x45, 0, 0, 0x10, 0x10, 0x100, &pair, desc);
        func_02055b24(data_020ffa28[M2C_FIELD(&data_021027f8, u8 *, 0x2A)], 0x80, 0x40, 0xb0, 1);
        p = self->f64;
        if (p != 0) {
            p->f08 |= 1;
        }
        for (i = 0; i < 4; i++) {
            p = self->f68[i];
            if (p != 0) {
                if (self->f7c[i] != 0) {
                    p->f08 |= 1;
                } else {
                    p->f08 &= ~1;
                }
            }
        }
        p = self->f78;
        if (self->f80 != 0) {
            p->f08 |= 1;
        } else {
            p->f08 &= ~1;
        }
        for (i = 0; i < 4; i++) {
            p = self->fac[i];
            if (p != 0) {
                p->f08 &= ~1;
            }
        }
    } else if (self->fe8 == 1) {
        func_0209adb4(self, 0, 0x120, 0x68, 0x10, 0x88, 0x78);
        p = self->f64;
        if (p != 0) {
            p->f08 &= ~1;
        }
        for (i = 0; i < 4; i++) {
            if (self->f68[i] != 0) {
                self->f7c[i] = (self->f68[i]->f08 & 1) == 1;
                self->f68[i]->f08 &= ~1;
            }
        }
        self->f80 = (self->f78->f08 & 1) == 1;
        self->f78->f08 &= ~1;
        for (i = 0; i < 4; i++) {
            p = self->fac[i];
            if (p != 0) {
                p->f08 |= 1;
            }
        }
    }
}
