#include "m2c.h"

// One slot of the two slot arrays: 0x340 bytes of payload and a count byte at 0x340 (0x344 bytes in all).
struct Slot {
    u8 data[0x340];
    u8 count;
    u8 pad[3];
};

// Member subobject constructed by func_0208d1f8 (0x3c bytes, starts at this+4).
struct Member {
    u8 data[0x3c];
};

struct Obj {
    void *vptr;
    Member member;
    u8 tbl[4][10]; // 0x40: four rows of ten bytes, cleared after construction
    u8 f68;
    u8 pad69;
    u16 f6a;
    u8 pad6c[4];
    Slot a[3]; // 0x70
    Slot b[4]; // 0xa3c
    u8 d[3];   // 0x174c
};

// The original binary stores these two vtable addresses in turn; only the addresses are needed here.
extern "C" u32 data_02100984;
extern "C" u32 data_02100968;
extern "C" Member *func_0208d1f8(Member *self);
extern "C" Slot *func_020b02a8(Slot *self);
extern "C" void func_020b02c8(Slot *self);

// Plain-name constructor of an object with two vptr stores (base vtable, then the final one).
// The slot and table rows are addressed as `this + constant + i * stride` byte arithmetic: the
// original keeps `this` as a separate base register and a stride-scaled offset register per row.
extern "C" Obj *func_020b02e0(Obj *self) {
    self->vptr = &data_02100984;
    func_0208d1f8(&self->member);
    self->vptr = &data_02100968;
    self->f68  = 0;
    self->f6a  = 0;
    Slot *p    = &self->a[0];
    do {
        func_020b02a8(p);
        p++;
    } while (p < &self->b[0]);
    Slot *q = &self->b[0];
    do {
        func_020b02a8(q);
        q++;
    } while (q < &self->b[4]);
    for (int i = 0; i < 4; i++) {
        func_020b02c8((Slot *) ((u8 *) self + 0xa3c +
                                i * 0x344)); // FAKE: byte addressing preserves the separate base and scaled offset.
        for (u8 j = 0; j < 10; j++) {
            *((u8 *) self + 0x40 + i * 10 + j) = 0; // FAKE: byte addressing preserves the table row offset.
        }
    }
    for (u8 i = 0; i < 3; i++) {
        func_020b02c8(&self->a[i]);
        self->d[i] = 0;
    }
    return self;
}
