#include "m2c.h"

typedef struct {
    s32 x, y, z;
} V3;

extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210930c;

void func_0200ee24(void *);
void func_0200e8f0(void *, s32);
M2C_UNK *func_020aaeb4(void);
void func_020aa84c(void *, s32 *);
u8 func_020917b4(void *);
u8 func_02093fd0(s32);
s32 func_0206704c(void *);
void func_020a3458(void *, s8);
void *func_02091b88(void *, s32, u8, void *, void *);
void func_0200b938(s32, s32);
void func_02004b00(void *);
void func_02048a54(void *, s32);

void func_020380e4(void *this) {
    V3 v;
    V3 w;
    u8 sp4[4];
    void *o = M2C_FIELD(this, void **, 0x4);
    void *r5;
    s16 *q;
    u16 a;
    u16 b;
    u16 c;
    u8 fl;
    s32 t0, t1, t2;

    func_0200ee24(o);
    func_0200e8f0(o, 0);
    if (M2C_FIELD(o, u8 *, 0x5da) == M2C_FIELD(&data_021027f8, u8 *, 0x2a)) {
        func_020aa84c(func_020aaeb4(), (s32 *) ((u8 *) o + 0xb0));
    }
    v.x = M2C_FIELD(o, s32 *, 0x6a0);
    v.y = M2C_FIELD(o, s32 *, 0x6a4);
    v.z = M2C_FIELD(o, s32 *, 0x6a8);
    if (func_02093fd0(func_020917b4(&data_0210930c)) == 0x11) {
        q   = *(s16 **) func_0206704c(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38c));
        t2  = q[2] << 12;
        t1  = q[1] << 12;
        t0  = q[0] << 12;
        w.x = t0;
        w.y = t1;
        w.z = t2;
        if ((s32 *) &v != (s32 *) &w) {
            v.x = t0;
            v.y = t1;
            v.z = t2;
        }
        func_020a3458(func_020aaeb4(), 1);
    }
    r5 = func_02091b88(&data_0210930c, M2C_FIELD(o, u8 *, 0x5da), M2C_FIELD(o, u8 *, 0x6bb), &v, 0);
    if ((s32 *) ((u8 *) r5 + 0x6a0) != (s32 *) ((u8 *) o + 0x6a0)) {
        M2C_FIELD(r5, s32 *, 0x6a0) = M2C_FIELD(o, s32 *, 0x6a0);
        M2C_FIELD(r5, s32 *, 0x6a4) = M2C_FIELD(o, s32 *, 0x6a4);
        M2C_FIELD(r5, s32 *, 0x6a8) = M2C_FIELD(o, s32 *, 0x6a8);
    }
    M2C_FIELD(r5, u8 *, 0x6be) = 0x53;
    func_0200b938((s32) ((u8 *) r5 + 0x69c), 2);
    a                        = M2C_FIELD(o, u16 *, 0xca);
    b                        = M2C_FIELD(r5, u16 *, 0xca);
    M2C_FIELD(sp4, u16 *, 2) = a;
    if (b != a) {
        M2C_FIELD(r5, u16 *, 0xca) = a;
        M2C_FIELD(r5, u8 *, 0xd0)  = 1;
    }
    c                           = M2C_FIELD(o, u16 *, 0x6b4);
    M2C_FIELD(r5, u16 *, 0x6b4) = c;
    M2C_FIELD(r5, u8 *, 0x6bf)  = 0x1e;
    M2C_FIELD(r5, s32 *, 0x8) &= ~1;
    M2C_FIELD(r5, u8 *, 0x5d6) = 1;
    M2C_FIELD(r5, s32 *, 0x84) = 0x1d;
    fl                         = M2C_FIELD(o, u8 *, 0x6c4);
    M2C_FIELD(sp4, u16 *, 0)   = c;
    if (!(fl & 2)) {
        func_02004b00(r5);
    }
    {
        void *p  = M2C_FIELD(o, void **, 0x5f8);
        void *q2 = M2C_FIELD(r5, void **, 0x5f8);
        if ((p != NULL) && (q2 != NULL) && (M2C_FIELD(p, u8 *, 0xe) == 1) && (M2C_FIELD(q2, u8 *, 0xe) == 1)) {
            func_02048a54(q2, M2C_FIELD(p, u8 *, 0x30));
            M2C_FIELD(q2, u8 *, 0x1c) = M2C_FIELD(p, u8 *, 0x1c);
        }
    }
    M2C_FIELD(this, void **, 0x14) = r5;
    M2C_FIELD(this, u16 *, 0x10)   = 0x14;
}
