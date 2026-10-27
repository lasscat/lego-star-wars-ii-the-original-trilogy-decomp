#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u16 v;
} UnkVal;

typedef struct {
    u8 pad[0x194];
    u32 flags;
} Other;

// Only the slot at vtable offset 0x44 is called here.
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
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual s32 unknown44(); // Slot 0x44.

    u8 pad04[0x2c];
    u8 *f30;
    u8 pad34[0x7c];
    Vec3 fb0;
    u8 padbc[0x5d2 - 0xbc];
    u16 f5d2;
    u8 pad5d4[6];
    u8 f5da;
    u8 pad5db[0x6ac - 0x5db];
    Other *f6ac;
    u8 pad6b0[4];
    u16 f6b4;
    u8 pad6b6[5];
    u8 f6bb;
    u8 pad6bc[5];
    u8 f6c1;
    u8 f6c2;
    u8 f6c3;
    u8 f6c4;
    u8 pad6c5[0x6ea - 0x6c5];
    u16 f6ea;
};

extern "C" u32 func_0205d060(s32, s32, s32);
extern "C" void func_02004758(void *);
extern "C" void func_02004908(Obj *, s32);
extern "C" void func_020049cc(Obj *, int);
extern "C" void func_02004b78(Obj *, s32);
extern "C" void func_02005854(Obj *, u8, s32, s32, s32);
extern "C" void func_02007914(Obj *, UnkVal, s32, s32, s32 *, s32 *, s32 *);
extern "C" void func_02010c6c(void *a0, s32 a1, s32 a2, s32 a3, u8 a4, void *a5, s32 a6, s32 a7);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

// Table of 10-byte records holding u16 flag words; func_0205d060 tests a mask
// in the record selected by its third argument (4 = the table's current slot).
extern "C" M2C_UNK data_021027f8;

// Rows of 0x24 bytes indexed by self->f6c3; each extern is one byte or
// halfword column of the same row layout (read-only data).
typedef struct {
    u8 v;
    u8 pad[0x23];
} Row8;

typedef struct {
    u16 v;
    u8 pad[0x22];
} Row16;

extern "C" const Row8 data_020f6bab[];
extern "C" const Row8 data_020f6bac[];
extern "C" const Row8 data_020f6bc0[];
extern "C" const Row16 data_020f6bc2[];

// Per-update handler reached through the pointer table data_020fcf28.
// Steps: count down f6c1; when f6ea is 0x47, clear f6c2 unless flag 0x800 is set
// in the data_021027f8 record chosen by f5da. Flag bit 1 in f6c4 skips the body;
// bit 2 (without bit 4) only calls func_020049cc when f5d2 has 0x800. If the row's
// first column is 1 and the 0x800 flag stays set while f6ea is 0x47, f6c2 counts
// up and at 10 calls func_02004b78(self, 0x28), func_02004758 and resets it.
// Otherwise, with 0x800 in f5d2 and the row column equal to 1, func_02007914 fills
// three outputs: a nonzero second output calls func_02004b78(self, 10); else, once
// f6c1 reaches 0, values 0x54..0x63 in f6bb call func_02010c6c with a position
// (fb0, or the Vec3 at f30 + 4) and the slot-0x44 virtual result, other values call
// func_02005854 with 5 (and 4 when the row's halfword has 0x20), and f6c1 is
// reloaded from the row. With bit 1 of f5d2 instead, func_02004908 runs unless
// f6ac has any of 0x1400700 set or f6c4 has bit 4. func_02004758 always ends it.
extern "C" void func_0200e1c4(Obj *self) {
    s32 out_a;
    s32 out_b;
    s32 out_c;
    u8 flags;

    if (self->f6c1 != 0) {
        self->f6c1 = self->f6c1 - 1;
    }
    if (self->f6ea == 0x47) {
        if (func_0205d060((s32) &data_021027f8, 0x800, self->f5da) == 0) {
            self->f6c2 = 0;
        }
    }
    flags = self->f6c4;
    if (flags & 1) {
        goto done;
    }
    if (!(flags & 4) && (flags & 2)) {
        if (self->f5d2 & 0x800) {
            func_020049cc(self, 0);
        }
        goto done;
    }
    if (data_020f6bab[self->f6c3].v == 1 && self->f6ea == 0x47 &&
        func_0205d060((s32) &data_021027f8, 0x800, self->f5da) != 0) {
        self->f6c2++;
        if (self->f6c2 >= 10) {
            func_02004b78(self, 0x28);
            func_02004758(self);
            self->f6c2 = 0;
            return;
        }
    }
    if (self->f5d2 & 0x800) {
        if (data_020f6bab[self->f6c3].v == 1) {
            func_02007914(self, *(UnkVal *) &self->f6b4, 0, 3, &out_a, &out_b, &out_c);
            if (out_b != 0) {
                func_02004b78(self, 10);
            } else if (self->f6c1 == 0) {
                if (self->f6bb >= 0x54 && self->f6bb <= 0x63) {
                    Vec3 pos;
                    u8 *other = self->f30;
                    s32 slot44_result;
                    u8 idx;
                    pos.x = self->fb0.x;
                    pos.y = self->fb0.y;
                    pos.z = self->fb0.z;
                    if (other != NULL) {
                        vec_set(&pos, (const Vec3 *) (other + 4));
                    }
                    idx           = self->f6c3;
                    slot44_result = self->unknown44();
                    func_02010c6c(self, data_020f6bac[idx].v, 0, slot44_result, self->f5da, &pos, out_c, 0);
                } else {
                    func_02005854(self, data_020f6bac[self->f6c3].v, 0, 5, out_c);
                    if (data_020f6bc2[self->f6c3].v & 0x20) {
                        func_02005854(self, data_020f6bac[self->f6c3].v, 0, 4, out_c);
                    }
                }
                self->f6c1 = data_020f6bc0[self->f6c3].v;
            }
        }
    } else if (self->f5d2 & 1) {
        if (self->f6ac == NULL || !(self->f6ac->flags & 0x1400700)) {
            if (!(self->f6c4 & 4)) {
                func_02004908(self, 0);
            }
        }
    }
done:
    func_02004758(self);
}
