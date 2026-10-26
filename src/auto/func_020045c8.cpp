#include "m2c.h"

// Maps the object's mode (kind) to a state id, then re-seeds the position of the
// object's own timeline and of every active slot item via a virtual call (slot 0x24).

enum {
    STATE_NONE  = 0xf5,
    FIXED_ONE   = 0x1000,
    FIXED_SHIFT = 12,
    SLOT_COUNT  = 10,
};

struct UnkVal {
    s32 v;
};

struct Flags {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 b2 : 1;
    u16 hi : 13;
};

struct Info {
    u8 pad[4];
    u16 f4;
};

struct Inner {
    u8 pad[8];
    Info *f8;
};

struct Item {
    u8 pad0[0x74];
    Inner *f74;
    u8 pad1[2];
    Flags f7a;
};

struct Slot {
    Item *item;
    u8 pad[0x24];
};

class Obj {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24(s32, s32, s32, s32);
    u8 pad0[0xd4 - 4];
    u8 f0d4[0x148 - 0xd4];
    s32 *f148;
    u8 pad1[0x14e - 0x14c];
    Flags f14e;
    u8 pad2[0x182 - 0x150];
    u16 kind;
    u8 pad3[2];
    Flags f186;
    u8 pad4[0x1d0 - 0x188];
    Slot slots[SLOT_COUNT];
};

extern "C" void func_0209f948(void *, UnkVal);

extern "C" void func_020045c8(Obj *self) {
    UnkVal pos; // timeline position; name guessed from callers
    UnkVal tmp;
    s32 state; // state id; name guessed from callers
    bool saved;
    s32 i;
    u16 kind;

    kind  = self->kind;
    state = STATE_NONE;
    if (kind == 0 || kind == 9) {
        state = 0;
    } else if (kind == 1 || kind == 10) {
        state = 1;
    } else if (kind == 6 || kind == 11) {
        state = 6;
    }
    if (state == STATE_NONE) {
        return;
    }
    if (self->f148 != NULL) {
        pos.v = *self->f148;
    } else {
        pos.v = 0;
    }
    saved         = self->f186.b1;
    self->f186.b1 = 0;
    self->v24(state, self->f14e.b2 == 1, 1, 0);
    func_0209f948(self->f0d4, pos);
    for (i = 0; i < SLOT_COUNT; i++) {
        Item *item = self->slots[i].item;
        if (item != NULL && item->f7a.b0 == 1) {
            Inner *q = item->f74;
            s32 v;
            if (q != NULL) {
                v = q->f8->f4 << FIXED_SHIFT;
            } else {
                v = 0;
            }
            if (pos.v < v) {
                func_0209f948(item, pos);
            } else {
                if (q != NULL) {
                    v = q->f8->f4 << FIXED_SHIFT;
                } else {
                    v = 0;
                }
                tmp.v = v - FIXED_ONE;
                func_0209f948(item, tmp);
            }
        }
    }
    self->f186.b1 = saved;
}
