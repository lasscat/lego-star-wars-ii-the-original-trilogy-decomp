#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Actor {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c(int); // Slot 0x0c.
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void unknown1c();
    virtual void unknown20();
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual Actor *unknown34(Actor *); // Slot 0x34.
    u8 field04[52]; // 0x04..0x37; the element stride is 0x38.
};

extern "C" Actor *func_0202c710(Actor *, Actor *, Actor *, Actor *);
extern "C" void func_0202c698(Actor *, Actor *, s32);

extern "C" void func_0202c638(Actor *actor, Actor *other) {
    Actor *cur  = 0;
    Actor *head = actor->unknown34(other);
    cur         = head;
    if (head == 0) {
        return;
    }
    Actor *next = 0;
    do {
        next = func_0202c710(actor, head, cur, other);
        func_0202c698(actor, M2C_FIELD(cur, Actor **, 4), 0);
        cur = next;
    } while (next != 0);
}
