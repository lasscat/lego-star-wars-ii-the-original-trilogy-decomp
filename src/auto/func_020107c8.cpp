#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class C107C8Object {
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
    virtual void unknown24(s32, s32, s32, u8); // Slot 0x24: this function.
    virtual void unknown28(s32, s32, s32, u8); // Slot 0x28.
};

typedef struct {
    u32 words[2];
} TableEntry;

extern "C" TableEntry data_020eb7b8[];
extern "C" s32 func_02010c0c(TableEntry *, s32);

extern "C" void func_020107c8(C107C8Object *self, s32 value, s32 arg2, s32 arg3, u8 arg4) {
    u16 index = M2C_FIELD(self, u16 *, 0x180);
    s32 res   = func_02010c0c(&data_020eb7b8[index], value);
    if (res == 0) {
        return;
    }
    self->unknown28(res, arg2, arg3, arg4);
}
