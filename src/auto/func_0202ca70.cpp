#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtables remain in the ROM data.
//
// self: the "Actor" hierarchy; this function observes slot 0x1c and the
// pointers at 0x04 (list head) and 0x18.
class Actor2 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void *unknown1c(void *, s32); // Slot 0x1c.
};

// The objects at self->field18 and behind each list node: slot 0x18 takes
// two arguments.
class Actor2Child {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual s32 unknown18(void *, void *); // Slot 0x18.
};

extern "C" void func_01ff90a8(void *);

extern "C" s32 func_0202ca70(Actor2 *self, void *arg1, void *arg2, s32 arg3) {
    s32 result;
    s32 index       = 0;
    Actor2Child *st = *(Actor2Child **) ((s8 *) self + 0x18);
    if (st != 0 && st->unknown18(arg1, arg2) == 1) {
        func_01ff90a8(self);
        if ((arg3 & 1) == 0) {
            return 1;
        }
    }
    u8 *n = *(u8 **) ((s8 *) self + 4);
    if (n != 0) {
        n = n - 4;
    }
    result = 0;
    while (n != 0) {
        s32 flag = arg3 & 1;
        u8 *arg  = n;
        if (n != 0) {
            arg = n + 4;
        }
        u8 *next       = (u8 *) self->unknown1c(arg, index);
        Actor2Child *c = *(Actor2Child **) (n + 4);
        if (next != 0) {
            next = next - 4;
        }
        if (c->unknown18(arg1, arg2) == 1) {
            if (flag == 0) {
                return 1;
            }
            result = 1;
        }
        n = next;
    }
    return result;
}
