#include "m2c.h"

// The three words copied from the argument block.
struct FieldsAA91C {
    void *f00;
    void *f04;
    void *f08;
};

// The object this function creates.
struct NewAA91C {
    FieldsAA91C *self; // 0x00: points at the field block below.
    FieldsAA91C fields; // 0x04.
    void *f10;
    void *f14;
    void *f18;
    void *f1c;
    void *f20;
    s32 type; // 0x24.
    u8 flag28; // 0x28.
    u8 flag29; // 0x29.
};

struct ObjAA91C;

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class SubAA91C {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(NewAA91C *arg); // Slot 0x08.
};

struct ObjAA91C {
    u8 pad000[0x300];
    u16 pad300[0x4a];
    SubAA91C sub; // 0x394.
};

extern "C" void *data_020ffbd4[];

extern "C" void *func_0205e824(u32 size);

extern "C" NewAA91C *func_020aa91c(ObjAA91C *obj, FieldsAA91C *args, s32 type, s32 index, u8 a, u8 b) {
    NewAA91C *p = (NewAA91C *) func_0205e824(0x2c);
    if (p != 0) {
        p->fields.f00 = 0;
        p->fields.f04 = 0;
        p->fields.f08 = 0;
        p->f10        = 0;
        p->f14        = 0;
        p->f18        = 0;
        p->f1c        = 0;
        p->f20        = 0;
        p->flag28     = 0xff;
        p->flag29     = 0;
    }
    p->f1c = 0;
    if ((type == 0 || type == 6) && M2C_FIELD(obj, u16 *, 0x3a0) == 0) {
        p->f1c = data_020ffbd4[index];
    }
    p->f20 = data_020ffbd4[index];
    if (&p->fields != args) {
        p->fields.f00 = args->f00;
        p->fields.f04 = args->f04;
        p->fields.f08 = args->f08;
    }
    p->self   = &p->fields;
    p->type   = type;
    p->flag28 = a;
    p->flag29 = b;
    obj->sub.unknown08(p);
    return p;
}
