#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Manager90584 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual s32 unknown1c(); // Slot 0x1c.
};

struct Event {
    u16 field00;
    u8 field02;
    u8 field03;
    u8 field04[0x18];
};

extern "C" Manager90584 *data_021092f4;
extern "C" M2C_UNK data_021027f8;
extern "C" M2C_UNK data_0210794c;
extern "C" s32 data_027e02a8;

extern "C" s32 func_02073044(void);
extern "C" void func_0206763c(s32, s32);
extern "C" void func_020675d8(s32, s32);
extern "C" M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, u8 *, M2C_UNK);

extern "C" void func_02090584(void *self, u16 arg1, u8 arg2) {
    if ((data_027e02a8 & 0x40) == 0 || func_02073044() > 2) {
        if (arg1 != 0) {
            func_0206763c(M2C_FIELD(M2C_FIELD(self, u32 *, 0x38c), u32 *, 4) + 0x28, arg1);
        }
        if (arg2 != 0) {
            func_020675d8(M2C_FIELD(M2C_FIELD(self, u32 *, 0x38c), u32 *, 4) + 0x28, arg2);
        }
        return;
    }
    if (data_021092f4->unknown1c() != 0) {
        return;
    }
    if (arg1 == 0 && arg2 == 0) {
        return;
    }
    Event event;
    event.field00 = arg1;
    event.field02 = arg2;
    event.field03 = M2C_FIELD(&data_021027f8, u8 *, 0x2a);
    func_020b04f0(&data_0210794c, 0x1a, (u8 *) &event, 0xff);
}
