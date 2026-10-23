#include "m2c.h"

extern u8 data_020eddb2[];
extern u8 data_021027f8[];
extern u8 *data_02109358[];
extern M2C_UNK data_02104d90;
extern s32 data_027e02a4;
extern s32 data_027e02a8;
extern M2C_UNK data_0210794c;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02104df4;
extern M2C_UNK data_02106f90;
extern M2C_UNK data_02106d90;
extern M2C_UNK data_02102900;

s32 func_02086534(void *, s32);
void func_020b8f70(M2C_UNK, s32);
void func_020b04f0(void *, M2C_UNK, void *, M2C_UNK);
void func_020917c8(void *, M2C_UNK, M2C_UNK);
void func_02004b78(s32, s32);
void func_02088b78(void *);
s32 func_020870d0(void *);
void func_0205ecc4(void *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
void func_02060158(void *, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_02068b90(M2C_UNK, M2C_UNK);
s32 func_02068780(void *);

typedef struct {
    u8 pad[0x14];
    u32 f14;
} Ent;

typedef struct {
    u8 pad0[0xc];
    Ent **tab;
    u8 pad1[0xc];
    s32 f1c;
    s32 f20;
    u8 pad2[0x11];
    u8 f35;
    u8 f36;
    u8 f37;
} Obj;

typedef struct {
    volatile u16 code;
    volatile u8 idx;
    u8 pad[0x19];
} Rec;

#define SETTOP(x, v) ((x) = (((x) & ~0xf000u) | (v)))

void func_020687b4(Obj *a0, s32 arg1) {
    u8 letter;
    Ent *e;
    Rec rec;
    u8 *tbl;
    s32 idx;
    u8 *obj;
    u8 idxv;
    u16 c;

    tbl    = &data_020eddb2[a0->f20 * 8];
    letter = tbl[arg1];

    if (a0->f35 != 0) {
        if (arg1 == data_021027f8[0x2a]) {
            if (a0->f36 == 0xff) {
                return;
            }
            idx = a0->f36 + 2;
            e   = a0->tab[idx];
            SETTOP(e->f14, 0xf000u);
            return;
        }
        if (a0->f36 != 0xff) {
            idx = a0->f36 + 2;
            e   = a0->tab[idx];
            SETTOP(e->f14, 0xf000u);
        }
        idx = arg1 + 2;
        e   = a0->tab[idx];
        SETTOP(e->f14, 0xd000u);
        func_020b8f70(0xb6, 0);
    } else {
        if (func_02086534(&data_02104d90, letter) != 0) {
            func_020b8f70(0xb6, 0);
            if (a0->f36 != 0xff) {
                u8 *tbl2;
                tbl2 = &data_020eddb2[a0->f20 * 8];
                if (func_02086534(&data_02104d90, tbl2[a0->f36]) != 0) {
                    idx = a0->f36 + 2;
                    e   = a0->tab[idx];
                    SETTOP(e->f14, 0xf000u);
                }
            }
            idx = arg1 + 2;
            e   = a0->tab[idx];
            SETTOP(e->f14, 0xd000u);
        } else {
            func_020b8f70(0xb7, 0);
        }
    }

    if (a0->f36 != (u8) arg1) {
        return;
    }
    if (a0->f35 != 0) {
        if (func_02068b90((M2C_UNK) a0, arg1) == 0) {
            return;
        }
        idx = arg1 + 2;
        e   = a0->tab[idx];
        SETTOP(e->f14, 0xf000u);
        return;
    }
    if (func_02086534(&data_02104d90, letter) != 0) {
        if (func_02068780((void *) a0) != 0 || a0->f1c == -1) {
            if (data_027e02a4 == 0) {
                data_027e02a4 = 1;
            } else {
                data_027e02a4 = 0;
            }
            if (data_027e02a8 & 0x40) {
                idxv     = data_021027f8[0x2a];
                rec.idx  = idxv;
                rec.code = letter;
                if (idxv == 1) {
                    c = rec.code;
                    if (c == 0x49) {
                        rec.code = 0x4c;
                    } else if (c == 0x4a) {
                        rec.code = 0x4d;
                    } else if (c == 0x4b) {
                        rec.code = 0x4e;
                    }
                }
                func_020b04f0(&data_0210794c, 7, &rec, 0xff);
            } else {
                func_020917c8(&data_0210930c, data_021027f8[0x2a], letter);
                obj = data_02109358[data_021027f8[0x2a]];
                if (obj[0x40] == 0) {
                    if (obj[0x6bb] < 0x54 || obj[0x6bb] > 0x63) {
                        func_02004b78((s32) obj, 0xd);
                    }
                }
            }
            if (data_027e02a4 == 0) {
                data_027e02a4 = 1;
            } else {
                data_027e02a4 = 0;
            }
        } else {
            func_02088b78(&data_02104df4);
            *(u16 *) ((u8 *) &data_02106f90 + 0x48) = letter;
            *(u16 *) ((u8 *) &data_02106f90 + 0x88) = func_020870d0(&data_02104d90);
            *(u8 *) ((u8 *) &data_02106d90 + 0x263) = 1;
            *(u8 *) ((u8 *) &data_02106d90 + 0x2a3) = 1;
            *(u8 *) ((u8 *) &data_02106d90 + 0x262) = 4;
            *(u8 *) ((u8 *) &data_02106d90 + 0x2a2) = 4;
            *(s8 *) ((u8 *) &data_02104d90 + 0x50)  = 0;
            *(s8 *) ((u8 *) &data_02104d90 + 0x51)  = -1;
            func_0205ecc4(&data_02102900, 4, 0, 4, a0->f1c, a0->f37);
            func_02060158(&data_02102900, 1, 0x1c, 0);
            func_02060158(&data_02102900, 1, 0xb, 0);
        }
        idx = arg1 + 2;
        e   = a0->tab[idx];
        SETTOP(e->f14, 0xf000u);
        a0->f36 = 0xff;
    } else {
        func_020b8f70(0xb7, 0);
    }
}
