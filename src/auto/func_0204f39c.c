#include "m2c.h"

extern s32 *func_0204c5fc(s32 *, M2C_UNK, M2C_UNK);
extern void func_01ffa338(void *, void *, void *, void *, void *, void *);

extern s32 data_020ff9b4[];

typedef struct Obj Obj;
typedef void (*Fn)(Obj *, void *);

struct Obj {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0c;
    Fn f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 *f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s32 f3c;
    u8 f40;
};

typedef struct {
    s32 *p;
    u8 status;
    u8 pad[3];
} Result;

typedef struct {
    s32 f0;
    s32 f1;
    s32 f2;
    s32 f3;
    s32 f4;
    s32 f5;
    Obj *f6;
} Local;

void func_0204f39c(s32 *out, Obj *obj, s32 *vec, Obj *arg4) {
    s32 mat[6];
    Local loc;
    Result res;
    s32 *f20;

    f20 = obj->f20;
    func_0204c5fc(mat, f20 + 1, f20 + 5);
    obj->f40 = 0;
    loc.f0   = 0;
    loc.f1   = 0;
    loc.f2   = 0;
    loc.f3   = 0;
    loc.f5   = 0;
    loc.f6   = 0;
    loc.f4   = 0x2000;
    func_01ffa338(obj, f20, mat, vec, (s32) arg4, (s32) &loc);
    if (loc.f4 <= 0x1000) {
        res.p = (s32 *) loc.f6;
        if (loc.f6 == 0) {
            if (loc.f2 >= 0xb33) {
                res.status = 1;
                obj->f40   = 1;
            } else {
                res.status = 2;
            }
        }
        obj->f10(obj, &res);
        if (loc.f6 != 0) {
            res.p = (s32 *) obj;
            loc.f6->f10(loc.f6, &res);
        }
        out[0] = data_020ff9b4[0];
        out[1] = data_020ff9b4[1];
        out[2] = data_020ff9b4[2];
        return;
    }
    out[0] = vec[0];
    out[1] = vec[1];
    out[2] = vec[2];
}
