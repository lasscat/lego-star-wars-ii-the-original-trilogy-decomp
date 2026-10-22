#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 f0 : 1;
    u16 f1 : 1;
} UnkFlags;

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void m(s32, s32, s32, s32);
};

extern "C" void func_02001990(void *, s32);
extern "C" void func_02006b74(void *, Vec3);
extern "C" void func_02018200(void *, void *, s32);
extern "C" s32 func_020aaeb4(void);
extern "C" s32 func_020aa8f0(s32, s32, s32, s32, s32, s32);
extern "C" void func_020aa84c(s32, void *);

extern "C" void func_02042da0(s32 *arg0) {
    s32 flag;

    switch (M2C_FIELD(arg0, u8 *, 0xd)) {
        case 0:
            if ((M2C_FIELD(M2C_FIELD(arg0, s32 *, 4), s32 *, 0x1b8) & 0x2000000) && M2C_FIELD(arg0, s32 *, 0x10) != 0) {
                ((Obj *) (void *) M2C_FIELD(arg0, s32 *, 4))->m(0x6b, 1, 1, 0);
                func_02001990((void *) M2C_FIELD(arg0, s32 *, 4), 0);
                M2C_FIELD(arg0, s32 *, 0x14) =
                    func_020aa8f0(func_020aaeb4(), M2C_FIELD(arg0, s32 *, 0x10) + 0xb0, 1, 0, 0xff, 0);
                func_02018200((void *) M2C_FIELD(arg0, s32 *, 4), (void *) M2C_FIELD(arg0, s32 *, 0x10), 0);
                flag = M2C_FIELD(M2C_FIELD(arg0, s32 *, 0x10), s32 *, 0x34) != 0;
                if (flag) {
                    func_02006b74((void *) M2C_FIELD(arg0, s32 *, 4),
                                  *(Vec3 *) (M2C_FIELD(M2C_FIELD(arg0, s32 *, 0x10), s32 *, 0x34) + 4));
                }
                M2C_FIELD(arg0, u8 *, 0xd) = 1;
                return;
            }
            M2C_FIELD(M2C_FIELD(arg0, s32 *, 4), u8 *, 0x6ba) = 0;
            M2C_FIELD(arg0, u8 *, 0xc) |= 1;
            return;
        case 1:
            if (((UnkFlags *) ((s8 *) M2C_FIELD(arg0, s32 *, 0x10) + 0x14e))->f1 == 1) {
                M2C_FIELD(arg0, u8 *, 0xd) = 4;
                return;
            }
            flag = M2C_FIELD(M2C_FIELD(arg0, s32 *, 0x10), s32 *, 0x34) != 0;
            if (flag) {
                func_02006b74((void *) M2C_FIELD(arg0, s32 *, 4),
                              *(Vec3 *) (M2C_FIELD(M2C_FIELD(arg0, s32 *, 0x10), s32 *, 0x34) + 4));
            }
            return;
        case 4:
            func_020aa84c(func_020aaeb4(), (void *) (M2C_FIELD(arg0, s32 *, 0x10) + 0xb0));
            M2C_FIELD(M2C_FIELD(arg0, s32 *, 4), u8 *, 0x6ba) = 0;
            ((Obj *) (void *) M2C_FIELD(arg0, s32 *, 4))->m(0, 1, 1, 0);
            func_02001990((void *) M2C_FIELD(arg0, s32 *, 4), 1);
            M2C_FIELD(arg0, u8 *, 0xc) |= 1;
            return;
        default:
            return;
    }
}
