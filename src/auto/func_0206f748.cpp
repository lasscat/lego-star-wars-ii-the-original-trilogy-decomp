#include "m2c.h"

// Partial interface: the manager object behind the global pointer
// data_0210b348 is only used through its slot 0x3c virtual here.  The
// declaration matches the one already used for the same global in
// src/auto/func_020719e0.cpp.  Declarations only: the original vtable
// remains in the ROM data.
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

#define PTR(base, off) ((void *) ((s8 *) (base) + (off)))

extern "C" GlobalManager *data_0210b348;

extern "C" void func_0206574c(void *obj, s32 a1, s32 a2);
extern "C" void func_02065600(void *obj, s32 a1);
extern "C" void *func_02066708(s32 a0);
extern "C" s32 func_02065be8(void *a0, s32 a1, s32 a2, s32 a3, void *a4, s32 a5);
extern "C" void func_02072900(s32 a0);

extern "C" void func_0206f748(void *obj) {
    data_0210b348->unknown3c();

    func_0206574c(PTR(obj, 0x5c), 6, -2);
    func_02065600(PTR(obj, 0x5c), 4);

    s32 first = func_02065be8(PTR(obj, 0x5c), 1, 127, 12, func_02066708(102), 1);
    func_0206574c(PTR(obj, 0x5c), 0, -2);
    M2C_FIELD(obj, u32 *, 0xa0) = first;

    s32 second                  = func_02065be8(PTR(obj, 0x5c), first, 86, 152, func_02066708(105), 1);
    s32 third                   = func_02065be8(PTR(obj, 0x5c), second, 170, 152, func_02066708(138), 1);
    M2C_FIELD(obj, u32 *, 0x98) = third;

    func_02065600(PTR(obj, 0x5c), 3);
    func_0206574c(PTR(obj, 0x5c), 9, -2);
    func_02072900(652);
}
