#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtables remain in the ROM data.

// The object reached through field18; it owns a byte of flags at 0x0c.
class ActorExFlags {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void unknown10(); // Slot 0x10.
    u8 pad04[8]; // 0x04..0x0b.
    u8 flags;    // 0x0c.
};

// Same family as the "Actor" class of func_0202c0cc, but this interface also
// exposes slot 0x38 and the pointer fields at 0x08 and 0x18.
class ActorEx {
public:
    virtual void unknown00();
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
    virtual void unknown30();
    virtual u32 *unknown34(ActorEx *); // Slot 0x34.
    virtual void unknown38(ActorEx *, u32 *, ActorEx *); // Slot 0x38.
    u8 pad04[4];           // 0x04..0x07.
    u32 *field08;          // 0x08.
    u8 pad0c[12];          // 0x0c..0x17.
    ActorExFlags *field18; // 0x18.
};

extern "C" void func_0202c118(ActorEx *self, ActorEx *a1, ActorEx *a2, ActorEx *a3) {
    u32 *p      = self->field08;
    a1->field08 = (u32 *) a2;
    if (a2 != 0) {
        p = self->unknown34(a2);
        if (p != 0) {
            p += 1;
        }
        if (p == 0) {
            p = self->field08;
        }
    }
    if (p != 0) {
        p -= 1;
    }
    self->unknown38(a1, p, a3);
    ActorExFlags *f = self->field18;
    if (f != 0) {
        f->flags &= ~2;
        self->field18->unknown10();
    }
}
