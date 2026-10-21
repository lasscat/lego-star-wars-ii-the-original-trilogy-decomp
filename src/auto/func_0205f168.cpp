#include "m2c.h"

// Partial interface for the object that owns the helper slot at 0x24.
// Declarations only: the original vtables stay in the ROM data.
class Obj5F1 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(); // Slot 0x0c.
};

// Partial interface for the helper object stored at offset 0x24.
class Helper5F1 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(); // Slot 0x08.
};

extern "C" void func_0205ffb8(void *);
extern "C" void func_0205eb98(void *);

extern "C" void func_0205f168(void *arg0, s32 index) {
    // Declaration order matters: it decides the r4/r5 split of the two
    // pointers in the generated code (helper in r5, obj in r4).
    Helper5F1 *helper;
    Obj5F1 *obj;

    func_0205ffb8(arg0);
    if (M2C_FIELD(arg0, u32 *, index * 32 + 0x48) != 0) {
        return;
    }
    obj = (Obj5F1 *) M2C_FIELD(arg0, u32 *, index * 4);
    if (obj == 0) {
        return;
    }
    helper = (Helper5F1 *) M2C_FIELD(obj, void **, 0x24);
    if (helper != 0) {
        if (M2C_FIELD(helper, u16 *, 0x8) & 1) {
            func_0205eb98(obj);
            helper = 0;
        }
    }
    if ((M2C_FIELD(obj, u32 *, 0x20) & 2) == 0) {
        obj->unknown0c();
    }
    if (helper != 0) {
        helper->unknown08();
    }
}
