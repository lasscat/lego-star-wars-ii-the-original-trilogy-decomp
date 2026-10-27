#include "m2c.h"

typedef struct Half {
    u16 v;
} Half;

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

extern void func_02004b78(void *, s32);
extern void func_02007f24(s32 *, M2C_UNK, M2C_UNK);
typedef struct WordArg {
    s32 v;
} WordArg;

extern s32 func_0200aef8(void *, void *, WordArg);
extern void func_0201811c(void *, void *, s32, s32);
extern void func_0202bd60(void *);
extern void func_0202bd80(void *, s8);
extern s32 func_0202cb44(void *);
extern u8 func_0202cb7c(void *);
extern u32 func_0202cca0(void *);
extern void func_020451c4(void *);
extern s32 func_020451dc(void *, s32);
extern void func_0204a62c(void *, void *);
extern s32 func_0204a880(void *);
extern u16 func_0204fa30(void *);
extern s32 func_02062a7c(s32, s32);
extern M2C_UNK data_0210930c;

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

/*
 * Per-frame update of a controller whose +4 field points at an object (obj).
 * Evidence: calls func_02004b78(obj, n) to request a state change (0xC, 0x12,
 * 0x15, 0x1D, or the value returned by func_0202cca0) and, when nothing
 * changes, finishes with func_0204a62c(obj + 0x5CE, obj). +0x10 is a
 * countdown (u16) re-armed with func_02062a7c(lo, hi); +0x12 is a flag that
 * is set when a state change is requested and cleared on the next call.
 */
void func_02044ed0(void *arg0) {
    s32 flag;
    u8 *obj;
    u8 *p;
    s32 r;
    u32 kind;
    WordArg spec;
    Half b;
    Half h;

    if (M2C_FIELD(arg0, u8 *, 0x12) != 0) {
        M2C_FIELD(arg0, u8 *, 0x12) = 0;
        func_0202bd60(M2C_FIELD(arg0, u8 **, 4) + 0x608);
    }
    if (M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 0x40) == 0) {
        func_02004b78(M2C_FIELD(arg0, u8 **, 4), 0xC);
        func_020451c4(arg0);
        return;
    }
    if (func_0204fa30(M2C_FIELD(arg0, u8 **, 4) + 0x40) == 3 && M2C_FIELD(M2C_FIELD(arg0, u8 **, 4), u8 *, 0x6BB) != 0x12) {
        func_02004b78(M2C_FIELD(arg0, u8 **, 4), 0x12);
        return;
    }
    obj  = M2C_FIELD(arg0, u8 **, 4);
    flag = 0;
    if (obj[0x40] != 0 && obj[0x41] != 0) {
        p = *(u8 **) (obj + 0x54);
        if (p != NULL) {
            p = p - 4;
        }
        if (p != NULL) {
            flag = 1;
        }
    }
    if (flag == 0 && func_0204fa30(obj + 0x40) != 5) {
        Vec3 *src;
        Vec3 *dst;
        obj = M2C_FIELD(arg0, u8 **, 4);
        src = (Vec3 *) (obj + 0xB0);
        dst = (Vec3 *) (obj + 0x6A0);
        vec_set(dst, src);
    }
    if (M2C_FIELD(arg0, u16 *, 0x10) != 0) {
        M2C_FIELD(arg0, u16 *, 0x10) = M2C_FIELD(arg0, u16 *, 0x10) - 1;
        r                            = func_0202cb44(M2C_FIELD(arg0, u8 **, 4) + 0x5E0);
        if (r != 0) {
            obj = M2C_FIELD(arg0, u8 **, 4);
            if (obj[0x5DB] == 0) {
                func_0201811c(&b, obj, r, 0);
                h                                                         = b;
                M2C_FIELD(M2C_FIELD(arg0, u8 **, 4) + 0x600, u16 *, 0xB4) = h.v;
            }
        }
    } else if (func_0204a880(M2C_FIELD(arg0, u8 **, 4) + 0x5CE) == 0) {
        obj = M2C_FIELD(arg0, u8 **, 4);
        if (*(s32 *) (obj + 0x5FC) != 0 && obj[0x694] == 2) {
            if (func_0202cb44(obj + 0x5E0) != 0 && func_0202cb7c(M2C_FIELD(arg0, u8 **, 4) + 0x5E0) >= 3) {
                u8 *o2;
                u8 *tab;
                tab = *(u8 **) ((u8 *) &data_0210930c + 0x4C);
                o2  = M2C_FIELD(arg0, u8 **, 4);
                func_02007f24(&spec.v, 0, 0x40340000);
                if (func_0200aef8(o2 + 0xB0, tab + 0xB0, spec) != 0) {
                    kind = func_0202cca0(*(void **) (M2C_FIELD(arg0, u8 **, 4) + 0x5FC));
                    if (kind == 1 || kind == 3) {
                        M2C_FIELD(arg0, u16 *, 0x10) = func_02062a7c(0x64, 0xC8);
                    } else if (kind == 2) {
                        M2C_FIELD(arg0, u16 *, 0x10) = func_02062a7c(0xA, 0x28);
                    } else if (kind != 0) {
                        M2C_FIELD(arg0, u8 *, 0x12) = 1;
                        func_0202bd80(M2C_FIELD(arg0, u8 **, 4) + 0x608, 0);
                        if (func_020451dc(arg0, kind) != 0) {
                            kind = 0x15;
                        }
                        func_02004b78(M2C_FIELD(arg0, u8 **, 4), kind);
                        return;
                    }
                    goto done;
                }
            }
            obj = M2C_FIELD(arg0, u8 **, 4);
            if (M2C_FIELD(obj, u16 *, 0xC) == 1 && func_0202cb7c(obj + 0x5E0) == 0 &&
                func_0202cb44(M2C_FIELD(arg0, u8 **, 4) + 0x5E0) == 0) {
                obj = M2C_FIELD(arg0, u8 **, 4);
                if ((obj[0x6C4] & 7) == 0) {
                    func_02004b78(obj, 0x1D);
                    return;
                }
            }
        }
    }
done:
    func_0204a62c(M2C_FIELD(arg0, u8 **, 4) + 0x5CE, M2C_FIELD(arg0, u8 **, 4));
}
