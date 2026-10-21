#include "m2c.h"

M2C_UNK func_0202cb44(void *);
M2C_UNK func_0200a6c4(void *, void *, void *, s32, s32, s32);

extern M2C_UNK data_021019d8;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;
typedef struct {
    u8 pad_00[0x20];
    void *f20;
    u8 pad_24[4];
    s32 f28;
    u8 pad_2c[0x84];
    Vec3 v;
} Ent;
typedef struct {
    u8 pad_00[4];
    Ent *f4;
} Obj;
typedef struct {
    u8 pad_00[4];
    Vec3 v;
    u8 pad_10[0x16];
    u8 flag;
} Q;

s32 func_020451dc(Obj *arg0, s32 arg1) {
    Ent *ent;
    Q *q;
    Vec3 *s;
    Vec3 v1;
    Vec3 v2;
    s32 ok;

    if ((arg1 == 8) || (arg1 == 9) || (arg1 == 0xa) || (arg1 == 0x19) || (arg1 == 0x1a) || (arg1 == 0x1b) || (arg1 == 0x33)) {
        s32 p[2] = {0, 0};

        ent           = (Ent *) func_0202cb44((u8 *) arg0->f4 + 0x5e0);
        arg0->f4->f28 = M2C_FIELD(&data_021019d8, s32 *, 0) + 1;
        ent->f28      = M2C_FIELD(&data_021019d8, s32 *, 0) + 1;
        ok            = 0;

        s    = &arg0->f4->v;
        v1.x = s->x;
        v1.y = s->y;
        v1.z = s->z;
        s    = &ent->v;
        v2.x = s->x;
        v2.y = s->y;
        v2.z = s->z;
        q    = (Q *) arg0->f4->f20;
        if (q != NULL && q->flag != 0) {
            ok = 1;
        }
        if (ok) {
            s = &q->v;
            if (&v1 != s) {
                v1.x = s->x;
                v1.y = s->y;
                v1.z = s->z;
            }
        }
        ok = 0;
        q  = (Q *) ent->f20;
        if (q != NULL && q->flag != 0) {
            ok = 1;
        }
        if (ok) {
            s = &q->v;
            if (&v2 != s) {
                v2.x = s->x;
                v2.y = s->y;
                v2.z = s->z;
            }
        }

        if (func_0200a6c4(&v1, &v2, p, 2, 1, 0) != 0) {
            return 1;
        }
    }
    return 0;
}
