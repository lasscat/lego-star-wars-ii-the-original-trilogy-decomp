#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
// The polymorphic member of the owner object lives at owner + 0x70.
class Sub70 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(u8 *);
};

extern "C" u8 *func_0205e80c(s32, s32, s32);
extern "C" u8 *func_0209435c(u8 *dst, u8 *src, u32 a2, u8 *a3);
extern "C" void func_020949b8(u8 *self, u8 *a1, u8 a2, u32 a3);
extern "C" void func_02095bd0(u8 *self, u8 *a1, u8 *a2);

extern "C" void func_02094930(u8 *self, u8 *a1, u32 a2, u8 *cmd) {
    u8 *sub = (u8 *) self + 0x70;
    if (M2C_FIELD(cmd, u8 *, 0x3) == 1) {
        func_020949b8(self, a1, M2C_FIELD(cmd, u8 *, 0x4), 1);
        return;
    }
    if (M2C_FIELD(cmd, u8 *, 0x2) == 0) {
        u8 *obj = func_0205e80c(0x14, 3, 4);
        if (obj != 0) {
            obj = func_0209435c(obj, a1, a2, cmd);
        }
        ((Sub70 *) sub)->unknown08(obj);
    } else {
        func_02095bd0(self, a1, cmd);
    }
}
