#include "m2c.h"

/* Partial interface: unknown virtuals retain their observed vtable slots.
 * Declarations only: the original vtable remains in the ROM data.
 *
 * Class of the object handled by func_020966e8.  Its vtable lives at
 * data_020fe5dc (twelve slots, 0x00..0x2c) and it keeps a list of child
 * objects at offset 0x04 and a flag byte at offset 0x38.
 */
class Actor966E8 {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18(); // Slot 0x18.
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
};

/* Element class of the child list.  Only slot 0x04 is observed here. */
class Child {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

/* Child list node: { child object, next node }. */
struct ListNode966E8 {
    Child *child;
    ListNode966E8 *next;
};

extern "C" void func_020966e8(Actor966E8 *self) {
    if (M2C_FIELD(self, u8 *, 0x38) == 0) {
        return;
    }
    ListNode966E8 *node = M2C_FIELD(self, ListNode966E8 **, 0x4);
    while (node != 0) {
        Child *child = M2C_FIELD(node, Child **, 0);
        if (child != 0) {
            child->unknown04();
        }
        node = M2C_FIELD(node, ListNode966E8 **, 4);
    }
    self->unknown18();
    M2C_FIELD(self, u8 *, 0x38) = 0;
}
