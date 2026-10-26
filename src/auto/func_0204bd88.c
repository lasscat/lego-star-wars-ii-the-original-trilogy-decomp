#include "m2c.h"

M2C_UNK func_020c8228(M2C_UNK *, s16, s16);
M2C_UNK func_020c8244(M2C_UNK *, s16, s16);
M2C_UNK func_020c8260(M2C_UNK *, void *, void *);
extern M2C_UNK data_020f88c4;
static inline s16 TAB(s32 i) {
    return *(s16 *) ((s8 *) &data_020f88c4 + i * 2);
}

typedef struct {
    u16 v[4];
} Rot;

static inline void rot_mtx(M2C_UNK *m, Rot r) {
    s32 i2 = (r.v[3] >> 4) * 2;
    func_020c8228(m, TAB(i2), TAB(i2 + 1));
}

static inline u16 deg_to_ang(s32 d) {
    return (u16) (((s64) d * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
}

void func_0204bd88(void *arg0) {
    Rot r;
    M2C_UNK m[9];
    M2C_UNK m2[9];
    s32 i2;
    s16 sn;
    s16 cs;
    s32 *flags;
    s32 sel;
    s32 idx;
    void *p;
    void *q;
    void *obj;

    p = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x2C);
    if (M2C_FIELD(arg0, s32 *, 8) & 0x10) {
        sel = M2C_FIELD(arg0, u8 *, 0xAE);
    } else {
        sel = -1;
    }
    if (M2C_FIELD(p, s8 *, 0x14) == sel) {
        obj = M2C_FIELD(arg0, void **, 0xB4);
        *(s32 *) obj &= ~2;
        idx = deg_to_ang(M2C_FIELD(p, s32 *, 0x18));
        idx = idx >> 4;
        i2  = idx * 2;
        sn  = TAB(i2);
        cs  = TAB(i2 + 1);
        if (M2C_FIELD((u8 *) M2C_FIELD(p, void **, 0x10) + 0x200, u16 *, 0x12) == 0x5D ||
            M2C_FIELD((u8 *) M2C_FIELD(p, void **, 0x10) + 0x200, u16 *, 0x12) == 0x68) {
            func_020c8228(m, sn, cs);
        } else {
            func_020c8244(m, sn, cs);
        }
        q = (u8 *) obj + 0x28;
        func_020c8260(m, q, q);
    }
    if (M2C_FIELD(arg0, s32 *, 8) & 0x10) {
        sel = M2C_FIELD(arg0, u8 *, 0xAE);
    } else {
        sel = -1;
    }
    if (M2C_FIELD(p, s8 *, 0x15) != sel) {
        return;
    }
    M2C_FIELD(&r, u16 *, 6) = deg_to_ang(M2C_FIELD(p, s32 *, 0x1C));
    if (M2C_FIELD((u8 *) M2C_FIELD(p, void **, 0x10) + 0x200, u16 *, 0x12) == 0x166) {
        M2C_FIELD(&r, u16 *, 4) = -M2C_FIELD(&r, u16 *, 6);
        M2C_FIELD(&r, u16 *, 2) = M2C_FIELD(&r, u16 *, 6);
        M2C_FIELD(&r, u16 *, 0) = M2C_FIELD(&r, u16 *, 4);
        M2C_FIELD(&r, u16 *, 6) = M2C_FIELD(&r, u16 *, 0);
    }
    i2  = (M2C_FIELD(&r, u16 *, 6) >> 4) * 2;
    obj = M2C_FIELD(arg0, void **, 0xB4);
    func_020c8228(m2, TAB(i2), TAB(i2 + 1));
    q = (u8 *) obj + 0x28;
    func_020c8260(m2, q, q);
}
