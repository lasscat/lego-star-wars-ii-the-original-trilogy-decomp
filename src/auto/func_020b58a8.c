#include "m2c.h"

typedef struct {
    u8 pad0[0xc];
    s32 *fc;
    s32 f10;
    s32 pad1;
    s32 pad2;
    s32 pad3;
    u8 pad2b[0x31 - 0x20];
    u8 b31;
} S;

typedef struct {
    S *f0;
    s32 pad0;
    s32 f8;
    s32 pad1;
    s32 pad2;
    s32 pad3;
    u32 f18;
    u32 f1c;
} G;

extern G data_0210daf0;
extern u32 data_027e02a8;
extern u32 data_02101d7c;
extern s32 data_0210dbd0[];

extern s32 func_020ba798(s32, M2C_UNK);
extern void func_020ba778(M2C_UNK, M2C_UNK);
extern s32 func_0205e540(s32, s32, s32);
extern void func_02054e78(M2C_UNK);
extern void MIi_LockCard(void);
extern void MIi_UnlockCard(void);
extern M2C_UNK CARDi_ReadRomID(void);

#define CARD_CHECK(lbl)                     \
    do {                                    \
        s32 bad;                            \
        s32 romid;                          \
        if ((data_027e02a8 & 0x800) != 0) { \
            MIi_LockCard();                 \
            romid = CARDi_ReadRomID();      \
            MIi_UnlockCard();               \
            if (romid != data_02101d7c) {   \
                bad = 1;                    \
                goto lbl;                   \
            }                               \
        }                                   \
        bad = 0;                            \
    lbl:                                    \
        if (bad != 0) {                     \
            func_02054e78(0);               \
            for (;;) {                      \
            }                               \
        }                                   \
    } while (0)

void func_020b58a8(s32 arg0) {
    s32 i;
    s32 v1;
    s32 v0;
    u16 table[256];

    func_020ba798((s32) table, data_0210daf0.f0->b31 * 2);
    if (arg0 != 0) {
        s32 t                = func_0205e540(data_0210daf0.f0->b31 * 4, 3, 4);
        data_0210daf0.f0->fc = (s32 *) t;
        if (data_0210daf0.f0->fc == 0) {
            CARD_CHECK(cardchk1);
        }
        data_0210daf0.f0->f10 = 0;
    } else {
        data_0210daf0.f0->fc = (s32 *) (data_0210daf0.f8 + data_0210daf0.f18);
        data_0210daf0.f18    = data_0210daf0.f18 + data_0210daf0.f0->b31 * 4;
        if (data_0210daf0.f18 >= data_0210daf0.f1c) {
            CARD_CHECK(cardchk2);
        }
    }
    for (i = 0; i < data_0210daf0.f0->b31; i++) {
        func_020ba778(data_0210dbd0[3] + table[i] * 4, 0);
        func_020ba798((s32) &v1, 4);
        func_020ba778(v1, 0);
        func_020ba798((s32) &v0, 4);
        if (arg0 != 0) {
            s32 t                   = func_0205e540(v0 + 1, 3, 4);
            data_0210daf0.f0->fc[i] = t;
            if (data_0210daf0.f0->fc[i] == 0) {
                CARD_CHECK(cardchk3);
            }
        } else {
            data_0210daf0.f0->fc[i] = data_0210daf0.f8 + data_0210daf0.f18;
            data_0210daf0.f18       = data_0210daf0.f18 + ((v0 + 4) & ~3);
            if (data_0210daf0.f18 >= data_0210daf0.f1c) {
                CARD_CHECK(cardchk4);
            }
        }
        data_0210daf0.f0->fc[i] = func_020ba798(data_0210daf0.f0->fc[i], v0 + 1);
    }
}
