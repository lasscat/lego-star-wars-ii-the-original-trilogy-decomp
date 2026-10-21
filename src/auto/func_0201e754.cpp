#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Entity1E754 {
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
    virtual void interact(Entity1E754 *, int, int); // Slot 0x2c.
};

extern "C" void func_02011384(Entity1E754 *, int, int, int);
extern "C" M2C_UNK data_020fd398;

extern "C" Entity1E754 *func_0201e754(Entity1E754 *self, int arg1, int arg2, int arg3, u8 arg4) {
    // Eight-byte scratch buffer the original function leaves on the stack.
    // Both words hold 0x4000 and are read back by the callee.
    u8 buf[8];

    func_02011384(self, arg1, arg2, arg3);
    M2C_FIELD(self, u32 *, 0x0)   = (u32) &data_020fd398;
    M2C_FIELD(self, u8 *, 0x216)  = arg4;
    M2C_FIELD(self, u8 *, 0x217)  = 0;
    M2C_FIELD(self, u8 *, 0x218)  = 0;
    M2C_FIELD(self, u32 *, 0x21c) = 0x3c;
    M2C_FIELD(self, u8 *, 0x1bc)  = 0;
    if (M2C_FIELD(self, u16 *, 0x212) != 0x19 && M2C_FIELD(self, u16 *, 0x212) != 0x60) {
        M2C_FIELD(self, u32 *, 0x178) = 0x4000;
        M2C_FIELD(buf, s32 *, 4)      = 0x4000;
        M2C_FIELD(buf, s32 *, 0)      = 0x4000;
        // Slot 0x24 is called with four explicit arguments on top of `this`.
        // The last of them travels in the outgoing argument slot at [sp], and
        // the scratch buffer occupies the two stack words above it, so seven
        // words are laid out for the callee in total.
        self->action(0x8a, 0, 1, 0);
    }
    if ((u32) (arg1 - 274) <= 1) {
        M2C_FIELD(self, u32 *, 0x8) &= ~0x1000000;
    }
    if (arg1 == 0x61) {
        M2C_FIELD(self, u32 *, 0x8) |= 0x4000000;
    }
    switch ((s32) M2C_FIELD(self, u16 *, 0xe8)) {
        case 0x107:
        case 0x10e:
        case 0x2f5:
        case 0x3c0:
        case 0x4f4:
        case 0x4fc:
        case 0x4ff:
        case 0x50a:
        case 0x511:
        case 0x577:
        case 0x773:
        case 0x788:
        case 0x791:
        case 0xa96:
        case 0x1128:
        case 0x13a4:

            M2C_FIELD(self, u8 *, 0x218) = 1;
            break;
    }
    return self;
}
