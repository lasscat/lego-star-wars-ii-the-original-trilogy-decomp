#include "m2c.h"

// Partial interface: only the observed vtable slot is declared.
// Declarations only: the original vtable remains in the ROM data.
class ObjABE14 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(void *); // Slot 0x08.
};

extern "C" u32 func_0201c9e8(void *);
extern "C" s32 func_020abf08(void *, s32);
extern "C" void *func_020abc9c(void *, void *, s32);
extern "C" s32 func_020abda4(s32, s32);
extern "C" s32 func_0205e80c(s32, s32, s32);

extern "C" void func_020abe14(ObjABE14 *arg0, void *arg1, s32 arg2) {
    s32 p = 0;

    if (func_0201c9e8((void *) arg2) != 0) {
        p = func_020abf08(arg0, arg2);
    }
    if (p != 0) {
        func_020abda4(p, 1);
        return;
    }
    p = func_0205e80c(0x20, 0, 4);
    if (p != 0) {
        p = (s32) func_020abc9c((void *) p, arg1, arg2);
    }
    arg0->unknown08((void *) p);
    func_020abda4(p, 0);
}
