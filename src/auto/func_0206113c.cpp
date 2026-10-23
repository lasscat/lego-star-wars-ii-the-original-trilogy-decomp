#include "m2c.h"

// Matched C helpers (extern "C" keeps the plain ROM entry names).
extern "C" s32 func_02062048(s32);
extern "C" void func_0205e84c(s32);

// List node: the item followed by the next-node pointer.
struct ListNode6113C {
    s32 item;
    ListNode6113C *next;
};

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class ActorList {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
    ListNode6113C *field04;        // 0x04.
};

extern "C" void func_0206113c(ActorList *obj, int flags) {
    if ((flags & 1) == 0) {
        return;
    }
    ListNode6113C *node = obj->field04;
    while (node != 0) {
        s32 item = node->item;
        node     = node->next;
        if (item != 0) {
            func_02062048(item);
            func_0205e84c(item);
        }
    }
    obj->unknown18();
}
