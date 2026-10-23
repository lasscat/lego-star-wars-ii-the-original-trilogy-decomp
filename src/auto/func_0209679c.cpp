#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// Element of the child list.  The flag word at offset 0x28 is the one that
// src/auto/func_0209678c.c sets with "| 1"; only slot 0x04 is dispatched here.
class Elem9679C {
public:
    virtual void unknown00();
    virtual void unknown04(); // Slot 0x04.
};

// Child list node: { element, next node, sub list }.
class Node9679C {
public:
    Elem9679C *elem;  // Offset 0x00.
    Node9679C *next;  // Offset 0x04.
    Node9679C *sub;   // Offset 0x08.
};

// Owner of the child list: vtable at offset 0x00, list head at offset 0x04.
// Only slot 0x0c is dispatched here.
class Owner9679C {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(Elem9679C *); // Slot 0x0c.
    Node9679C *head;                     // Offset 0x04.
};

extern "C" void func_0209679c(Owner9679C *self) {
    Node9679C *cur = self->head;
    while (cur != 0) {
        if ((M2C_FIELD(cur->elem, u32 *, 0x28) & 1) == 1) {
            Elem9679C *e = cur->elem;
            bool first   = true;
            if (cur != self->head) {
                cur   = cur->sub;
                first = false;
            }
            self->unknown0c(e);
            if (e != 0) {
                e->unknown04();
            }
            if (first) {
                cur = self->head;
            }
        }
        if (cur != 0) {
            cur = cur->next;
        }
    }
}
