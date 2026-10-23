#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class GlobalManager {
public:
    virtual s32 unknown00();    // Slot 0x00.
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
    virtual void unknown30(s32); // Slot 0x30.
    virtual void unknown34();
    virtual s32 unknown38();     // Slot 0x38.
    virtual void unknown3c();    // Slot 0x3c.
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48(s32); // Slot 0x48.
};

extern "C" GlobalManager *data_0210b348;
extern "C" M2C_UNK data_02104d2c;

extern "C" void func_02065600(void *, s32);
extern "C" void func_0206574c(void *, s32, s32);
extern "C" void func_02065be8(void *, s32, s32, s32, void *, s32);
extern "C" void *func_02066708(s32);
extern "C" s32 func_020ad310(void);
extern "C" void func_020afcbc(void *, u16);

extern "C" void func_020719e0(void *self) {
    data_0210b348->unknown30(0x400141);
    data_0210b348->unknown48(0x7d0);
    if (data_0210b348->unknown00() == 0) {
        return;
    }
    data_0210b348->unknown3c();
    func_0206574c((u8 *) self + 0x64, 6, -2);
    func_02065600((u8 *) self + 0x64, 4);
    func_02065be8((u8 *) self + 0x64, 1, 0x7f, 0xc, func_02066708(0x67), 1);
    func_0206574c((u8 *) self + 0x64, 0, -2);
    func_02065be8((u8 *) self + 0x64, 0x61, 0x56, 0x98, func_02066708(0x69), 1);
    func_02065be8((u8 *) self + 0x64, 1 + 0x100, 0xaa, 0x98, func_02066708(0x8a), 1);
    func_02065600((u8 *) self + 0x64, 3);
    func_0206574c((u8 *) self + 0x64, 9, -2);
    *(u8 *) ((s8 *) &data_02104d2c + 6)  = 0;
    *(u16 *) ((s8 *) &data_02104d2c + 2) = 0;
    for (;;) {
        if (func_020ad310() == 7) {
            break;
        }
        if (func_020ad310() != 9) {
            continue;
        }
        break;
    }
    if (func_020ad310() == 7) {
        *(u32 *) ((s8 *) self + 0xa8) = data_0210b348->unknown38();
    }
    *(u16 *) ((s8 *) self + 0xb4) = *(u16 *) ((s8 *) self + 0xb4) + 1;
    func_020afcbc(*(void **) ((s8 *) self + 0xd0), (u16) ((*(u16 *) ((s8 *) self + 0xb4) << 2) | 2));
    *(u32 *) ((s8 *) self + 0xa4) = 1;
}
