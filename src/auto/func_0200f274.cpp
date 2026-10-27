#include "m2c.h"

// Partial interfaces: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtables stay in the ROM data.

// Six-word box filled by the shape's slot-0x04 virtual. func_020555c4 turns
// words 0/1 and 4/5 into the two cell ranges of the grid it walks.
struct Box {
    s32 v[6];
};

// Grid-cell iterator state (func_020555c4 init, func_02055684 done,
// func_02055660 current cell list, func_02055630 advance).
struct Iter {
    s32 w[6];
};

extern "C" {
extern s32 data_021019d8;     // query stamp: bumped per query, copied into visited objects (+0x28)
extern M2C_UNK data_021094ac; // the grid walked by the iterator
extern u32 data_027e007c[];   // per-group mask of groups this one may touch
void *func_020555c4(void *arg0, s32 arg1, void *arg2);
void func_02055630(void *arg0);
s32 func_02055660(const void *object);
s32 func_02055684(void *arg0);
}

class Obj;
// The shape object hanging off an object at +0x20; fields 4/8/0xc are offset by
// the probe while its bounds are taken and the overlap tests run.
class Shape {
public:
    virtual void unknown00();
    virtual void getBounds(Box *); // Slot 0x04: fills the zeroed box.
};

// Pairwise test between two shapes; nonzero means they overlap.
extern "C" s32 func_01ff84bc(void *a, void *b);

class Obj {
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
    virtual void reportOverlap(Obj *, s32, s32); // Slot 0x2c: called on the touched object.
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual s32 unknown44(); // Slot 0x44: value forwarded to reportOverlap.
};

// One entry of a grid cell's object list.
struct Link {
    Obj *obj;
    Link *next;
};

enum {
    KIND_MASK        = 0x6,      // +0xc flags: object kinds that take part (bit 1 or bit 2)
    KIND_BIT1        = 0x2,
    KIND_BIT2        = 0x4,
    EXCLUDE_FLAGS    = 0x200802, // +0x8 flags that skip the object
    SPECIAL_GROUP    = 1,        // group accepted regardless of the mask table
    SKIPPED_TYPE_MIN = 0x54,     // +0x6bb type range skipped for bit-1 objects
    SKIPPED_TYPE_MAX = 0x63,
    OVERLAP_CODE     = 0xb,      // last argument of reportOverlap
};

// Converts a +0x60..0x68 value into the shape position units (shift left 4,
// computed through a rounded 64-bit Q16 -> Q12 step).
static inline s32 scale(s32 v) {
    return (s32) ((((s64) v << 16) + 0x800) >> 12);
}

// Sweep test: moves this object's shape by the scaled +0x60/+0x64/+0x68 offset,
// collects every object in the grid cells under the moved shape's bounds, and
// calls reportOverlap(self, self->unknown44(), 0xb) on each eligible object
// whose shape overlaps it. Each object is visited once per call (query stamp).
// The shape is moved back afterwards.
extern "C" void func_0200f274(Obj *self) {
    s32 dz = scale(M2C_FIELD(self, s32 *, 0x68));
    s32 dy = scale(M2C_FIELD(self, s32 *, 0x64));
    s32 dx = scale(M2C_FIELD(self, s32 *, 0x60));
    Box box;
    Iter it;
    Link *n;
    s32 *zp;
    Shape *shape = M2C_FIELD(self, Shape **, 0x20);

    // Temporarily move the shape to the probed position.
    M2C_FIELD(shape, s32 *, 4) += dx;
    M2C_FIELD(shape, s32 *, 8) += dy;
    M2C_FIELD(shape, s32 *, 0xc) += dz;

    zp = box.v;
    do {
        *zp++ = 0;
    } while (zp < box.v + 6);
    shape->getBounds(&box);
    data_021019d8++; // new query stamp
    func_020555c4(&it, (s32) &data_021094ac, &box);
    while (!func_02055684(&it)) {
        for (n = (Link *) func_02055660(&it); n != NULL; n = n->next) {
            Obj *o = n->obj;
            void *oshape;
            s32 group;
            u32 kind;
            u32 type;
            if ((M2C_FIELD(o, u16 *, 0xc) & KIND_MASK) && !(M2C_FIELD(o, u32 *, 8) & EXCLUDE_FLAGS) && o != self &&
                M2C_FIELD(o, s32 *, 0x28) != data_021019d8) {
                // Group filter: self's group (+0x84) mask must contain o's group.
                group = M2C_FIELD(o, s32 *, 0x84);
                if (!(data_027e007c[M2C_FIELD(self, s32 *, 0x84)] & (1 << group)) && group != SPECIAL_GROUP) {
                    continue;
                }
                M2C_FIELD(o, s32 *, 0x28) = data_021019d8; // visited in this query
                oshape                    = M2C_FIELD(o, void **, 0x20);
                if (oshape != NULL && M2C_FIELD(oshape, u8 *, 0x26) != 0 && func_01ff84bc(shape, oshape) != 0) {
                    kind = M2C_FIELD(o, u16 *, 0xc);
                    if (kind & KIND_BIT1) {
                        type = M2C_FIELD(o, u8 *, 0x6bb);
                        if (type < SKIPPED_TYPE_MIN || type > SKIPPED_TYPE_MAX) {
                            o->reportOverlap(self, self->unknown44(), OVERLAP_CODE);
                        }
                    } else if (kind & KIND_BIT2) {
                        o->reportOverlap(self, self->unknown44(), OVERLAP_CODE);
                    }
                }
            }
        }
        func_02055630(&it);
    }

    // Restore the shape position.
    M2C_FIELD(shape, s32 *, 4) -= dx;
    M2C_FIELD(shape, s32 *, 8) -= dy;
    M2C_FIELD(shape, s32 *, 0xc) -= dz;
}
