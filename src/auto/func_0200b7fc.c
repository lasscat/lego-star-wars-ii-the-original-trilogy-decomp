#include "m2c.h"

extern void *func_0205e80c(s32 size, s32 heap, s32 flags);
extern void func_020accac(void *s, void *a1, void *a2, void *a3);
extern void *func_020029c4(void *p, s32 a, s32 b, s32 c, void *s);
extern void func_020043f4(void *p);
extern void func_020351c0(void *v, void *a, s32 b);
extern void func_020344e0(void *v, s32 a);
extern void func_02034f88(void *v, s32 a, s32 b, s32 c);
extern void func_020344e8(void *v, s32 a);

typedef struct {
    u8 f00[0x48];
} S;

typedef struct {
    u8 f00[0xe];
    u8 f0e;
} V;

typedef struct {
    u8 f00[0x5f8];
    V *f5f8;
} Big;

typedef struct {
    u8 f00[0x8];
    u32 f08;
    u8 f0c[0xc8];
    void *fd4;
    u8 fd8[0x1a];
    u8 ff2;
    u8 ff3;
    u8 ff4;
    u8 ff5;
} Obj;

Big *func_0200b7fc(Obj *obj, s32 *a1, u16 a2, s32 a3, ...) {
    Big *p = func_0205e80c(0x6f8, 0, 4);

    if (p != 0) {
        u16 buf[4];
        u32 arr[3];
        S s;

        buf[0] = 0;
        buf[1] = *(u16 *) &a2;
        buf[2] = 0;
        arr[0] = 0x1000;
        arr[1] = 0x1000;
        arr[2] = 0x1000;
        func_020accac(&s, a1, buf, arr);
        {
            s32 flag = 1;
            S *ps    = &s;

            if (obj->f08 & 0x80000000) {
                flag = 0;
            }
            p = func_020029c4(p, 2, obj->ff3, flag, ps);
        }
    }
    func_020043f4(p);
    if ((u8) (obj->ff3 + 0xa1) <= 1) {
        V *v = p->f5f8;

        if (v != 0 && v->f0e == 3) {
            switch (obj->ff5) {
                case 0:
                    func_020351c0(v, obj->fd4, a3);
                    func_020344e0(v, 0);
                    break;
                case 1:
                    func_02034f88(v, obj->ff2, 1, 1);
                    func_020344e8(v, 1);
                    break;
            }
        }
    }
    return p;
}
