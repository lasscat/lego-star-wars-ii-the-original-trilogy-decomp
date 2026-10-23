#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
struct ActionFlags {
    unsigned short bit0 : 1;
    unsigned short bit1 : 1;
    unsigned short rest : 14;
};

class ActionTarget {
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
    virtual void action(s32, s32, s32, s32); // Slot 0x24.
    virtual void unknown28();

    u8 pad04[0x14A];
    ActionFlags flags; // 0x14e
};

struct AnimTarget {
    u8 pad00[0x18];
    u8 field18;
    u8 field19;
};

struct Anim7ea0c {
    u8 pad00[0x08];
    void *f8;         // 0x08
    u8 pad0c[0x08];
    void *f14;        // 0x14
    u8 pad18[0x04];
    u32 f1c;          // 0x1c
    u32 f20;          // 0x20
    u8 f24;           // 0x24
    u8 pad25[0x07];
    void *f2c;        // 0x2c
    s32 f30;          // 0x30
    s32 f34;          // 0x34
    ActionTarget *f38; // 0x38
};

extern "C" s32 func_02066118(void *, s32, s32, s32);
extern "C" void func_020661b4(void *, s32);
extern "C" void *func_02066708(s32);
extern "C" s32 func_02065be8(void *, s32, s32, s32, void *, s32);
extern "C" void func_0201b318(void *, u8);
extern "C" s32 func_0208c7e8(void *);
extern "C" M2C_UNK data_02104dc4;
extern "C" M2C_UNK data_02106d90;
extern "C" s32 data_027e02a8;

extern "C" s32 func_0207ea0c(Anim7ea0c *self) {
    if (self->f38 == 0) {
        if (self->f30 < self->f34) {
            self->f30 = self->f30 + 1;
            if (self->f30 > 100) {
                self->f30 = 100;
            }
            func_02066118(self->f8, 2, 6, 30);
            func_02066118(self->f8, 2, 7, 30);
            func_020661b4(self->f8, self->f30);
            self->f2c = (void *) func_02065be8(self->f8, 240, 128, 48, func_02066708(0x155), 1);
            if (self->f30 < 100) {
                func_0201b318(M2C_FIELD(self->f14, AnimTarget **, 0x28), (u8) (self->f30 / 10));
            }
        }
        if (self->f34 == 100) {
            AnimTarget *tgt = M2C_FIELD(self->f14, AnimTarget **, 0x28);
            tgt->field18    = 3;
            tgt->field19    = 3;
        }
        if (self->f30 >= self->f34) {
            return 0;
        }
        return 1;
    }

    if (self->f38->flags.bit1 == 1) {
        if (self->f30 < self->f34) {
            self->f30 = self->f30 + 7;
            if (self->f30 >= 100) {
                self->f30 = 100;
            }
            func_02066118(self->f8, 2, 6, 30);
            func_02066118(self->f8, 2, 7, 30);
            func_020661b4(self->f8, self->f30);
            self->f2c = (void *) func_02065be8(self->f8, 240, 128, 48, func_02066708(0x155), 1);
            if (self->f30 < 100) {
                func_0201b318(M2C_FIELD(self->f14, AnimTarget **, 0x28), (u8) (self->f30 / 10));
            }
        }
        if (self->f34 == 100) {
            AnimTarget *tgt = M2C_FIELD(self->f14, AnimTarget **, 0x28);
            tgt->field18    = 3;
            tgt->field19    = 3;
        }
        if (self->f24 == 0) {
            self->f20 = self->f20 + 1;
            if (self->f20 < self->f1c) {
                self->f38->action(self->f20 + 228, 0, 1, 0);
                self->f38->action(self->f20 + 121, 0, 1, 0);
            } else {
                if (self->f20 == 15) {
                    if (func_0208c7e8(&data_02104dc4) != 0) {
                        if ((data_027e02a8 & 0x40) == 0) {
                            goto doActions;
                        }
                    }
                    if (!((data_027e02a8 & 0x40) && ((((u8 *) &data_02106d90)[0x8D3]) != 0))) {
                        goto endActions;
                    }
                doActions:
                    self->f38->action(244, 0, 1, 0);
                    self->f38->action(137, 0, 1, 0);
                endActions:;
                }
                self->f24 = 1;
            }
        } else {
            return 0;
        }
    }
    return 1;
}
