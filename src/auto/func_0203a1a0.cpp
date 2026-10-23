#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void action(int, int, int, int); // Slot 0x24.
    virtual void unknown28();
    virtual void interact(Entity *, int, int); // Slot 0x2c.
};

// The object reached through the pointer at obj+0x10 owns a vtable of its own;
// only the method at slot 0x38 is observed here.
class C3A1A0Target {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38(void *); // Slot 0x38.
};

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

extern "C" void func_0203a438(void *obj);
extern "C" void func_02006b74(void *sub, Vec3 v);
extern "C" void func_02018200(void *sub, void *target, s32 arg2);
extern "C" void *func_020aaeb4();
extern "C" void *func_020aa8f0(void *arg0, void *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5);
extern "C" void func_020aa7c0(void *arg0, void *arg1);
extern M2C_UNK data_021027f8;

extern "C" void func_0203a1a0(void *obj) {
    func_0203a438(obj);

    switch (M2C_FIELD(obj, u8 *, 0xd)) {
        case 0: {
            s32 flags = M2C_FIELD(M2C_FIELD(obj, void **, 4), s32 *, 0x1b8);
            if (flags & 0x800) {
                u8 *q = (u8 *) M2C_FIELD(obj, void **, 0x10);
                u8 *q2;
                void *res;
                if (q != 0) {
                    q -= 4;
                }
                if (q != 0) {
                    M2C_FIELD(obj, Entity **, 4)->action(0x1a, 1, 1, 0);
                    q2 = (u8 *) M2C_FIELD(obj, void **, 0x10);
                    if (q2 != 0) {
                        q2 -= 4;
                    }
                    ((C3A1A0Target *) q2)->unknown38(M2C_FIELD(obj, void **, 4));
                    if (M2C_FIELD(M2C_FIELD(obj, void **, 4), u8 *, 0x5da) == M2C_FIELD(&data_021027f8, u8 *, 0x2a)) {
                        q2 = (u8 *) M2C_FIELD(obj, void **, 0x10);
                        if (q2 != 0) {
                            q2 -= 4;
                        }
                        res = func_020aa8f0(func_020aaeb4(), q2 + 0xb0, 1, 0, 0xff, 0);
                    } else {
                        res = 0;
                    }
                    M2C_FIELD(obj, void **, 0x20) = res;
                    M2C_FIELD(obj, u8 *, 0xd)     = 1;
                    return;
                }
            }
            M2C_FIELD(M2C_FIELD(obj, void **, 4), u8 *, 0x6ba) = 0;
            M2C_FIELD(obj, u8 *, 0xc) |= 1;
            return;
        }
        case 1: {
            u8 *p = (u8 *) M2C_FIELD(obj, void **, 0x10);
            u8 *q = p;
            if (p != 0) {
                q = p - 4;
            }
            if (q == 0) {
                M2C_FIELD(M2C_FIELD(obj, void **, 4), u8 *, 0x6ba) = 0;
                M2C_FIELD(obj, u8 *, 0xc) |= 1;
            }
            {
                u8 *r = (u8 *) M2C_FIELD(obj, void **, 0x10);
                u8 *s = r;
                s32 flag;
                if (r != 0) {
                    s = r - 4;
                }
                if (M2C_FIELD(s, void **, 0x34) != 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
                if (flag != 0) {
                    u8 *t = (u8 *) M2C_FIELD(obj, void **, 0x10);
                    if (t != 0) {
                        t -= 4;
                    }
                    func_02006b74(M2C_FIELD(obj, void **, 4), *(Vec3 *) ((u8 *) M2C_FIELD(t, void **, 0x34) + 4));
                } else {
                    u8 *t = (u8 *) M2C_FIELD(obj, void **, 0x10);
                    if (t != 0) {
                        t -= 4;
                    }
                    func_02006b74(M2C_FIELD(obj, void **, 4), *(Vec3 *) (t + 0xb0));
                }
            }
            {
                u8 *t = (u8 *) M2C_FIELD(obj, void **, 0x10);
                if (t != 0) {
                    t -= 4;
                }
                func_02018200(M2C_FIELD(obj, void **, 4), t, 0);
            }
            return;
        }
        case 4: {
            void *p = M2C_FIELD(obj, void **, 0x20);
            if (p != 0) {
                func_020aa7c0(func_020aaeb4(), p);
            }
            M2C_FIELD(M2C_FIELD(obj, void **, 4), u8 *, 0x6ba) = 0;
            M2C_FIELD(obj, Entity **, 4)->action(0, 1, 1, 0);
            M2C_FIELD(obj, u8 *, 0xc) |= 1;
            return;
        }
        default:
            return;
    }
}
