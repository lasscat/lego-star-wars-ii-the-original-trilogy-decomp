#include "m2c.h"

// Partial interface: the observed vtable slots of the objects handled here.
// Declarations only: the original vtable remains in the ROM data.
class Obj4C80 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual s32 unknown08(); // Slot 0x08.
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void interact(Obj4C80 *, s32, s32); // Slot 0x2c.
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual s32 unknown44(); // Slot 0x44.
};

extern "C" s32 func_02006af8(s32 *, s32);
extern "C" void func_02006b44(s32 *, s32);
extern "C" s32 func_0204a880(void *);
extern "C" void func_020b95bc(s32, M2C_UNK);
extern "C" u8 data_020f6bb1[];

extern "C" void func_02004c80(Obj4C80 *arg0, Obj4C80 **arg1) {
    Obj4C80 *other = *arg1;
    u16 kind       = M2C_FIELD(other, u16 *, 0xc);
    if (kind != 1 && kind != 2) {
        return;
    }
    if (arg0 == other) {
        return;
    }
    if (func_02006af8((s32 *) arg0, other->unknown08()) != 0) {
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x2a7) == 0 && M2C_FIELD(arg0, u8 *, 0x27f) == 0) {
        func_020b95bc(92, (s32) arg0);
    }
    func_02006b44((s32 *) arg0, other->unknown08());
    if (M2C_FIELD(arg0, u16 *, 0xc) == 1 && M2C_FIELD(other, u16 *, 0xc) == 1) {
        if (func_0204a880((u8 *) arg0 + 0xce + 0x500) == 0) {
            return;
        }
    }
    if (func_0204a880((u8 *) arg0 + 0xce + 0x500) != 0) {
        goto alt;
    }
    if (func_0204a880((u8 *) other + 0xce + 0x500) != 0) {
        goto alt;
    }
    if (M2C_FIELD(arg0, u8 *, 0x6bb) == 55) {
        goto alt;
    }
    other->interact(arg0, arg0->unknown44(), 12);
    return;
alt: {
    u32 idx = M2C_FIELD(arg0, u16 *, 0x182) - 36;
    u8 val  = data_020f6bb1[M2C_FIELD(arg0, u8 *, 0x6c3) * 36];
    if (idx <= 2) {
        val = 7;
    }
    other->interact(arg0, arg0->unknown44(), val);
}
}
