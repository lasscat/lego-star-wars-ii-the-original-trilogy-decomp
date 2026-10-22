#include "m2c.h"

typedef struct {
    u8 pad0[0x1c];
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 f1f;
    u8 f20;
    u8 f21;
    u8 f22;
    u8 f23;
    u8 f24;
    u8 f25;
    u8 pad26[2];
} Obj;

extern Obj *func_0205e80c(u32, u32, u32);
extern Obj *func_0208345c(Obj *, u8, void *, void *);
extern void func_02083c08(void *, Obj *);
extern void func_020834e0(Obj *);

Obj *func_02083b14(void *arg0, u8 arg1, void *arg2, void *arg3, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u32 arg10,
                   u32 arg11, u32 arg12, u32 arg13) {
    Obj *obj = func_0205e80c(0x28, 3, 4);

    if (obj != 0) {
        obj = func_0208345c(obj, arg1, arg2, arg3);
    }
    obj->f1d = (arg5 == 0) ? 0 : arg5 - 1;
    obj->f1e = (arg6 == 0) ? 0 : arg5 - 1;
    obj->f1f = (arg7 == 0) ? 0 : arg5 - 1;
    obj->f20 = arg8;
    obj->f21 = arg9;
    obj->f22 = arg10;
    obj->f23 = arg11;
    obj->f24 = arg12;
    obj->f25 = arg13;
    func_02083c08(arg0, obj);
    func_020834e0(obj);
    return obj;
}
