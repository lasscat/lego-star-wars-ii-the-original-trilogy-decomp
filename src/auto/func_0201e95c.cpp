#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Actor0201e95c {
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
    virtual void unknown24(s32, s32, s32, s32); // Slot 0x24.
};

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    u8 pad[0x4c];
    void *slot[8];
} Table;

extern "C" M2C_UNK data_021027f8;
extern "C" M2C_UNK data_0210930c;
extern "C" void func_02010384(void *, UnkVal, ...);
extern "C" s32 func_0201eec4(s32 *, s32 *, UnkVal);
extern "C" void *func_020931b0(s32, s32);
extern "C" void func_020b8f70(M2C_UNK, s32);

enum {
    PROXIMITY_RADIUS = 0x12000, // radius handed to the XZ distance test
    LOOKUP_TYPE_ID   = 0x37,    // value matched against byte 0x6bb by func_020931b0
    WAIT_FRAMES      = 0x14,    // countdown loaded into field 0x21c
    STATUS_MASK      = 0x802,   // bits tested in the found object's word 0x08
};

// Per-frame update for an object driven by a small state machine in byte 0x1bc
// (states 0, 1, 3, 5, 6 handled; others fall through). Every path ends in the
// shared update tail func_02010384 with the forwarded argument.
//  - state 0: once byte 0x1d8 (signed) reaches byte 0x1dc, scan the object table
//    (count at data_021027f8+0x29, entries at data_0210930c+0x4c); the first entry
//    whose position (+0xb0) lies within PROXIMITY_RADIUS of ours in the XZ plane
//    (func_0201eec4 compares the squared x/z distance with radius squared) fires
//    virtual slot 0x24 with 0x56, moves to state 1 and calls func_020b8f70(0xba, 0).
//  - state 1: when bit 1 of halfword 0x14e is set, fire slot 0x24 (0x58, plus
//    0x8b if halfword 0x212 is 0xa7), optionally set bit 21 / clear bit 0 of word
//    0x08, then go to state 4.
//  - state 3: set bit 0 / clear bit 21 of word 0x08; when bit 1 of 0x14e is set,
//    pick state 6 (start the WAIT_FRAMES countdown, write 0xf4 into the object
//    found by func_020931b0), state 5 (fire slot 0x24 with 0x5c) or state 0.
//  - state 5: back to state 0 when bit 1 of 0x14e is set.
//  - state 6: count field 0x21c down; when it expires, go to state 4 if the found
//    object has any STATUS_MASK bit set, else to state 1 firing slot 0x24 with 0x5a.
extern "C" void func_0201e95c(Actor0201e95c *obj, UnkVal arg1, ...) {
    UnkVal radius;
    s32 other_pos[3];
    radius.v = PROXIMITY_RADIUS;
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 0: {
            u32 i;
            if (M2C_FIELD(obj, s8 *, 0x1d8) < M2C_FIELD(obj, u8 *, 0x1dc)) {
                break;
            }
            for (i = 0; i < M2C_FIELD(&data_021027f8, u8 *, 0x29); i++) {
                void *other = ((Table *) &data_0210930c)->slot[i];
                if (other != 0) {
                    other_pos[0] = M2C_FIELD(other, s32 *, 0xb0);
                    other_pos[1] = M2C_FIELD(other, s32 *, 0xb4);
                    other_pos[2] = M2C_FIELD(other, s32 *, 0xb8);
                    if (func_0201eec4(&M2C_FIELD(obj, s32 *, 0xb0), other_pos, radius) != 0) {
                        obj->unknown24(0x56, 0, 1, 0);
                        M2C_FIELD(obj, u8 *, 0x1bc) = 1;
                        func_020b8f70(0xba, 0);
                        break;
                    }
                }
            }
            break;
        }
        case 1:
            if (((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30 >> 31) != 1 /* bit 1 */) {
                break;
            }
            obj->unknown24(0x58, 0, 1, 1);
            if (M2C_FIELD(obj, u16 *, 0x212) == 0xa7) {
                obj->unknown24(0x8b, 0, 1, 0);
            }
            if (M2C_FIELD(obj, u8 *, 0x218) != 0) {
                M2C_FIELD(obj, u32 *, 8) = (M2C_FIELD(obj, u32 *, 8) | 0x200000) & ~1;
            }
            M2C_FIELD(obj, u8 *, 0x1bc) = 4;
            break;
        case 3:
            M2C_FIELD(obj, u32 *, 8) = (M2C_FIELD(obj, u32 *, 8) | 1) & ~0x200000;
            if (((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30 >> 31) != 1) {
                break;
            }
            if (M2C_FIELD(obj, u8 *, 0x216) != 0) {
                if (M2C_FIELD(obj, u8 *, 0x217) != 0) {
                    void *p = func_020931b0((s32) &data_0210930c, LOOKUP_TYPE_ID);
                    if (p != 0) {
                        M2C_FIELD(p, u8 *, 0x6be) = 0xf4;
                    }
                    M2C_FIELD(obj, s32 *, 0x21c) = WAIT_FRAMES;
                    M2C_FIELD(obj, u8 *, 0x1bc)  = 6;
                } else {
                    M2C_FIELD(obj, u8 *, 0x1bc) = 5;
                    obj->unknown24(0x5c, 0, 1, 0);
                }
            } else {
                M2C_FIELD(obj, u8 *, 0x1bc) = 0;
            }
            break;
        case 5:
            if (((u32) M2C_FIELD(obj, u16 *, 0x14e) << 30 >> 31) == 1) {
                M2C_FIELD(obj, u8 *, 0x1bc) = 0;
            }
            break;
        case 6: {
            s32 frames_left = M2C_FIELD(obj, s32 *, 0x21c);
            void *p;
            M2C_FIELD(obj, s32 *, 0x21c) = frames_left - 1;
            if (frames_left != 0) {
                break;
            }
            p = func_020931b0((s32) &data_0210930c, LOOKUP_TYPE_ID);
            if (p != 0) {
                if ((M2C_FIELD(p, u32 *, 8) & STATUS_MASK) != 0) {
                    M2C_FIELD(obj, u8 *, 0x1bc) = 4;
                    break;
                }
            }
            M2C_FIELD(obj, u8 *, 0x1bc) = 1;
            obj->unknown24(0x5a, 0, 1, 1);
            break;
        }
    }
    func_02010384(obj, arg1);
}
