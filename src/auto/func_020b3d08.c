#include "m2c.h"

enum {
    NO_ENTRY          = 0xFFFF,
    CHAN_SIZE         = 0x6BC,
    FLAG_DYNAMIC      = 4,
    CARD_ID_CHECK_BIT = 0x800,
    SEQ_END_MARK      = 0xFE,
    CHAN_INIT_LOOP_A  = 0x20,
    CHAN_INIT_LOOP_B  = 0x10,
    F2D_FLAG          = 0x80,
};

typedef struct Chan {
    u8 pad0[8];
    u8 *seq;
    u8 pad1[0x18 - 0x0C];
    u32 x18;
    u8 pad2[0x25 - 0x1C];
    u8 f25;
    u8 f26;
    u8 pad3[2];
    u8 f29;
    u8 pad4[3];
    u8 f2d;
    u8 f2e;
    u8 pad5[0x39 - 0x2f];
    u8 id;
} Chan;

typedef struct Pool {
    Chan *cur;
    u32 pad;
    u8 *base;
    Chan *slots[3];
    u32 used;
    u32 limit;
} Pool;

extern Pool data_0210daf0;
extern s32 data_027e02a8;
extern u32 data_02101d7c;

extern void func_02054e78(s32);
extern s32 func_0205e540(s32 first, s32 second, s32 value);
extern void *func_0205e624(void *dst, u32 value, u32 size);
extern void func_020b3fd0(s32 arg0);
extern void func_020b4080(s32 arg0);
extern void func_020b4364(s32 arg0, u8 arg1, u32 arg2);
extern void func_020b4564(s32 arg0);
extern void func_020b47c4(s32 a, s32 b);
extern void func_020b8cd0(s32 arg0);
extern void func_020b8d2c(s32 arg0);
extern void MIi_LockCard(void);
extern void MIi_UnlockCard(void);
extern u32 CARDi_ReadRomID(void);

static inline s32 rom_id_mismatch(void) {
    u32 id;

    if ((data_027e02a8 & CARD_ID_CHECK_BIT) != 0) {
        MIi_LockCard();
        id = CARDi_ReadRomID();
        MIi_UnlockCard();
        if (id != data_02101d7c) {
            return 1;
        }
    }
    return 0;
}

/* Sets up record arg0 (0..2): takes CHAN_SIZE bytes from the heap when the
   dynamic flag is set (arg0 != 0 forces it), otherwise from the static pool,
   zeroes it, runs the 0x20 + 0x10 init loops, then steps its position index
   past arg3 end marks in its sequence data. Halts if allocation fails/overflows
   and the card ROM ID check differs. No-op when arg1 == NO_ENTRY. */
void func_020b3d08(s32 arg0, u16 arg1, u8 arg2, u8 arg3) {
    s32 i;
    s32 j;
    s32 hasDyn;
    u32 n;
    u32 flags;
    Chan *c;

    hasDyn = 0;
    if (arg1 == NO_ENTRY) {
        return;
    }
    flags = arg2;
    if (arg0 != 0) {
        flags |= FLAG_DYNAMIC;
    }
    if ((flags & FLAG_DYNAMIC) != 0) {
        hasDyn = 1;
    }
    switch (arg0) {
        case 0:
            func_020b4080(0);
            func_020b4080(1);
            break;
        case 1:
            func_020b4080(1);
            func_020b3fd0(0);
            break;
        case 2:
            func_020b4080(2);
            break;
    }
    if (hasDyn) {
        data_0210daf0.slots[arg0] = (Chan *) func_0205e540(CHAN_SIZE, 3, 4);
        if (data_0210daf0.slots[arg0] == NULL) {
            if (rom_id_mismatch()) {
                func_02054e78(0);
                while (1) {
                }
            }
        }
    } else {
        data_0210daf0.slots[arg0] = (Chan *) (data_0210daf0.base + data_0210daf0.used);
        data_0210daf0.used        = data_0210daf0.used + CHAN_SIZE;
        if (data_0210daf0.used >= data_0210daf0.limit) {
            if (rom_id_mismatch()) {
                func_02054e78(0);
                while (1) {
                }
            }
        }
    }
    data_0210daf0.cur = data_0210daf0.slots[arg0];
    func_0205e624(data_0210daf0.cur, 0, CHAN_SIZE);
    data_0210daf0.cur->id = arg0;
    for (i = 0; i < CHAN_INIT_LOOP_A; i++) {
        func_020b8cd0(i & 0xFF);
    }
    for (j = 0; j < CHAN_INIT_LOOP_B; j++) {
        func_020b8d2c(j & 0xFF);
    }
    func_020b47c4(arg1, hasDyn);
    data_0210daf0.cur->f26 = flags;
    data_0210daf0.cur->f2d |= F2D_FLAG;
    func_020b4564(data_0210daf0.cur->id);
    hasDyn                 = 0;
    data_0210daf0.cur->f29 = 0;
    if ((u32) hasDyn < arg3) {
        do {
            c = data_0210daf0.cur;
            if (c->f29 >= c->f2e) {
                c->f29 = 0;
                break;
            }
            if (c->seq[c->f29] == SEQ_END_MARK) {
                hasDyn++;
            }
            c->f29++;
        } while ((u32) hasDyn < arg3);
    }
    if (data_0210daf0.cur->seq[data_0210daf0.cur->f29] == SEQ_END_MARK) {
        data_0210daf0.cur->f29 = 0;
    }
    func_020b4364(data_0210daf0.cur->id, data_0210daf0.cur->f29, 0);
    data_0210daf0.cur->x18 = 0;
    data_0210daf0.cur->f25 = 1;
}
