#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
struct Out;

class Sub {
public:
    virtual void unknown00();
    virtual void unknown04(Out *p); // Slot 0x04.
};

struct Obj {
    u8 pad00[0x20];
    Sub *sub;
    u8 pad24[0x8c];
    s32 s0;
    s32 s1;
    s32 s2;
};

struct Out {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
    s32 w4;
    s32 w5;
};

extern "C" void func_02017e8c(Obj *obj, Out *out) {
    if (obj->sub != 0) {
        obj->sub->unknown04(out);
        return;
    }
    out->w0 = obj->s0;
    out->w1 = obj->s0;
    out->w2 = obj->s1;
    out->w3 = obj->s1;
    out->w4 = obj->s2;
    out->w5 = obj->s2;
}
