#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable (address point data_020ff2a0)
// remains in the ROM data.
class C57CF8Object {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14(); // Slot 0x14.
};

extern "C" void func_02001990(void *, s32);

extern "C" void func_02057cf8(void *arg0, C57CF8Object *obj, s32 mode, s32 flag) {
    switch (mode) {
        case 0:
            obj->unknown14();
            break;
        case 1:
            if (flag == 1) {
                M2C_FIELD(obj, u32 *, 8) |= 1;
            } else {
                M2C_FIELD(obj, u32 *, 8) &= 0xfffffffe;
            }
            break;
        case 2:
            func_02001990(obj, flag ? 1 : 0);
            break;
    }
}
