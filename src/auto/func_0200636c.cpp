#include "m2c.h"

// The dispatched virtual lives in a sub-object at offset 0xd4 of the object.
// Declarations only: the original vtable remains in the ROM data.
class Sub636C {
public:
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08(u32, u32, u32, u32); // Slot 0x08.
};

// Table of type descriptors: 8-byte records starting at data_020eb7b8.
struct Desc636C {
    u32 base;
    u16 unk04;
    u16 count;
};

extern "C" Desc636C data_020eb7b8[];

struct Part636C {
    u8 pad00[0x80];
    u16 field80;
};

class Obj636C {
public:
    u8 pad00[0xd4];
    Sub636C sub;
    u8 pad0d8[0x28];
    Part636C part;
    u8 pad182[0x571];
    u8 field6f3;
};

extern "C" s32 func_02010c0c(void *, s32);

extern "C" void func_0200636c(Obj636C *obj) {
    if (obj->field6f3 != 0) {
        u16 v = obj->part.field80;
        if (v != 5 && v != 0xc) {
            u32 rec = (u32) func_02010c0c(&data_020eb7b8[v], 0x78);
            obj->sub.unknown08(rec, 0, 1, 0);
        }
    }
}
