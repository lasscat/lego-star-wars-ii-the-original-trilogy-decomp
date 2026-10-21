#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable (address point data_020fe614)
// remains in the ROM data.  Slot 0x1c (func_0205d518) takes the current
// node pointer and a flag, and returns the next node pointer.
class Entity5DList {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual s32 unknown1c(s32, s32); // Slot 0x1c.
};

// Searches the list for the node whose key field equals `key` and returns
// that node, or 0.  The list pointer at +0x04 points at the key field, so
// the node base is one 4-byte unit below it; the same +/-4 stepping is
// applied around the slot 0x1c call, each step guarded by its own null test.
extern "C" s32 func_0205dbbc(Entity5DList *self, s32 key) {
    s32 cur = M2C_FIELD(self, s32 *, 4);
    if (cur != 0) {
        cur -= 4;
    }
    s32 result = 0;
    while (cur != 0) {
        if (M2C_FIELD(cur, s32 *, 4) == key) {
            result = cur;
            break;
        }
        if (cur != 0) {
            cur += 4;
        }
        cur = self->unknown1c(cur, 0);
        if (cur != 0) {
            cur -= 4;
        }
    }
    return result;
}
