#include "m2c.h"

/* Declaration-only partial interface of the entity class: the observed
 * vtable slots are preserved, no method is defined here (no vtable data). */
class Entity34 {
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
    virtual void unknown2c();
    virtual void unknown30(int, int); // Slot 0x30.
    virtual void unknown34(int); // Slot 0x34.
};

/* One-word aggregate.  The callee (func_0209f948) reloads its second
 * argument from the incoming register save area, so that argument is a
 * by-value aggregate, not a plain scalar. */
typedef struct {
    s32 v;
} UnkVal;

#define ENT(o) (*(Entity34 **) ((s8 *) (o) + 4))

extern "C" void func_02064fa0(void *);
extern "C" s32 func_0201ca1c(s32);
extern "C" void func_020ab40c(void *, s32);
extern "C" void func_0201c7a0(void *, s32);
extern "C" s32 func_020ab574(void *, void *, s32);
extern "C" void func_0209f948(void *, UnkVal);

extern "C" void func_0203b574(void *self, s32 arg1) {
    Entity34 *e = ENT(self);
    u16 v       = M2C_FIELD(e, u16 *, 0x180);
    if ((v == 0x11) && (arg1 != 0)) {
        return;
    }
    if ((v == M2C_FIELD(self, u32 *, 0x1c)) && (arg1 == 0)) {
        return;
    }
    UnkVal sp4;
    s32 *p = M2C_FIELD(e, s32 **, 0x148);
    if (p) {
        sp4.v = *p;
    } else {
        sp4.v = 0;
    }
    if (arg1 != 0) {
        void *q = M2C_FIELD(e, void **, 0xe0);
        if (q != 0) {
            func_02064fa0(q);
        }
    }
    ENT(self)->unknown30(arg1 != 0 ? 0x11 : (s32) M2C_FIELD(self, u32 *, 0x1c), 0);
    if (arg1 == 0) {
        Entity34 *e2 = ENT(self);
        func_020ab40c((void *) ((u8 *) e2 + 0xd8), func_0201ca1c(M2C_FIELD(e2, u16 *, 0x180)));
        s32 sp8[3];
        func_0201c7a0(sp8, (s32) ((u8 *) self + 0x24));
        func_020ab574((void *) ((u8 *) ENT(self) + 0xd8), sp8, 1);
    }
    ENT(self)->unknown34(1);
    ENT(self)->action(0x19, 0, 1, 0);
    func_0209f948((void *) ((u8 *) ENT(self) + 0xd4), sp4);
}
