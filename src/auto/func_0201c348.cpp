#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class C1c348Object;

class C1c348Other {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual s32 unknown08(C1c348Object *self, s32 a, s32 b);
};

class C1c348Object {
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
    u8 pad[0x7c];
    C1c348Other *other;
    s32 f84;
    s32 f88;
    s32 f8c;
    s32 f90;
    s32 f94;
};

// 4-byte value passed by value.
struct C1c348Val {
    s32 v;
};

struct C1c348Data {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
    u8 pad[0x29];
    u16 f2a;
    u16 f2c;
};

extern "C" C1c348Data data_021044a4;
extern "C" void func_0201ae44(C1c348Object *self, C1c348Val val);

extern "C" void func_0201c348(C1c348Object *self, C1c348Val arg1) {
    if (data_021044a4.b2) {
        self->f8c = data_021044a4.f2a << 12;
        self->f90 = data_021044a4.f2c << 12;
        switch (self->f94) {
            case 1:
                self->unknown20();
                break;
            case 0:
                if (self->other->unknown08(self, self->f8c, self->f90) == 0) {
                    self->f94 = 2;
                } else {
                    self->f84 = self->f8c;
                    self->f88 = self->f90;
                    self->unknown1c();
                    self->f94 = 1;
                }
                break;
            case 2:
                break;
        }
    } else {
        if (self->f94 == 1) {
            self->unknown24();
            if (self->other->unknown08(self, self->f8c, self->f90) != 0) {
                self->unknown28();
            }
        }
        self->f94 = 0;
    }
    func_0201ae44(self, arg1);
}
