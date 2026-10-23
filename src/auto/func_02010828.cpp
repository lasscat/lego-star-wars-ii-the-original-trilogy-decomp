#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Sub10828 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(void *, s32, s32, u8); // Slot 0x8.
};

class Entity10828 {
public:
    u8 unknown00[0x0c];
    u16 field_0x0c;
    u8 unknown0e[0xc6];
    Sub10828 sub_0xd4;
    u8 unknownd8[0x70];
    u32 field_0x148;
    u8 unknown14c[0x36];
    u16 field_0x182;
};

extern "C" s32 func_02062a7c(s32 a, s32 b);
extern "C" void func_0209f948(void *a, u32 b);
extern "C" void func_02010a24(Entity10828 *, u16);

extern "C" void func_02010828(Entity10828 *self, void *arg1, s32 arg2, s32 arg3, u8 arg4) {
    if (arg1 == 0) {
        return;
    }
    u16 old_state = self->field_0x182;
    self->sub_0xd4.unknown08(arg1, arg2, arg3, arg4);
    u16 state = self->field_0x182;
    if (state == 0 || state == 9) {
        u32 f = self->field_0x0c;
        if (f - 1 <= 1) {
            if (old_state != state) {
                u32 v            = self->field_0x148;
                v                = v ? (u32) M2C_FIELD(M2C_FIELD(v, u32 *, 8), u16 *, 4) << 12 : 0;
                s32 range        = ((s32) v) >> 12;
                s32 r            = func_02062a7c(0, range - 1);
                volatile u32 val = r << 12;
                func_0209f948((u8 *) self + 0xd4, r << 12);
            }
        }
    }
    u32 w = M2C_FIELD(arg1, u16 *, 0);
    if (w < 0x78 || w > 0xa0) {
        func_02010a24(self, M2C_FIELD(arg1, u16 *, 4));
    }
}
