#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
class Obj4F7C {
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
    virtual void defeated(Obj4F7C *); // Slot 0x40.
    virtual s32 unknown44();         // Slot 0x44.
};

typedef struct {
    u16 unused : 6;
    u16 frozen : 1;
} Flags186;

typedef struct Ref Ref;
typedef struct Link {
    Ref *first;
} Link;
struct Ref {
    Link *owner;
    Link next;
};

typedef struct {
    s32 v;
} DistLimit;

typedef struct {
    u8 amount;
    u8 flags;
} HitInfo;

extern "C" HitInfo data_020f0214[];
extern "C" u8 data_020eebbb[];
extern "C" u32 data_02104d90;
extern "C" M2C_UNK data_02106d90;
extern "C" M2C_UNK data_0210786c;
extern "C" M2C_UNK data_0210930c;

extern "C" {
s32 func_020917b4(void *);
u8 func_02093fd0(s32);
s32 func_020867ec(void *, s32);
void func_02004b78(Obj4F7C *, s32);
void func_02004800(Obj4F7C *);
void func_02005428(Ref *, void *);
void func_02005458(void *, void *);
void func_020063d4(Obj4F7C *, s32, s32);
void func_02006a50(Obj4F7C *, s32);
void func_0200b938(void *, s32);
void *func_0200ca7c(void *, s32, s32, void *);
void func_0201c778(u16 *);
void func_0201c858(u16 *, s32, u16);
u16 func_0201ca1c(u16);
void func_0202d5f0(void *, Obj4F7C *, s8);
s32 func_0202d7f8(Obj4F7C *, s32, Obj4F7C *, s32);
void *func_0205e80c(s32, s32, s32);
void *func_0208dad8(s32);
s32 func_020942c0(Obj4F7C *, DistLimit, void *, void *, void *);
void func_02095ee8(void *, s32, s32);
s32 func_020ab40c(void *, u16);
s32 func_020ab574(void *, u16 *, s32);
}

static inline Link *ref_link(Link *l) {
    if (l != 0) {
        l = (Link *) ((u8 *) l - 4);
    }
    if (l != 0) {
        l = (Link *) ((u8 *) l + 4);
    }
    return l;
}

static inline void ref_unlink(Ref *r) {
    Ref *cur;
    Link *l = r->owner;
    if (l != 0) {
        cur = l->first;
        while (cur != r) {
            l   = &cur->next;
            cur = l->first;
        }
        l->first = r->next.first;
    }
}

static inline void ref_attach(Ref *r, Link *l) {
    if (l != 0) {
        r->owner      = l;
        r->next.first = l->first;
        l->first      = r;
    } else {
        r->owner      = 0;
        r->next.first = 0;
    }
}

enum {
    NO_ENTRY   = 0xfa,   // Sentinel in the u8 table at data_020eebbb and in the u16 at +0x6ee.
    INVALID_ID = 0xffff, // Sentinel for the u16 ids from func_0208dad8 and func_0201ca1c.
};

// Applies one hit of type `kind` (entry in data_020f0214: amount, flags) from
// `other` to `self`. Returns early while self is flagged/immune. Otherwise it
// reports the hit via func_02095ee8 (player index, self's slot-0x44 value),
// then either calls virtual slot 0x40 with `other` (s16 at +0x6b6 <= amount)
// or subtracts the amount from that counter, with follow-up calls when it
// drops to 2 or less and an update of the object at +0x604. Finally, looks up the
// table byte for self's type at +0x6bb (stride 5) and, if it differs from the
// u16 at +0x6ee, spawns an effect object and passes the byte to func_020063d4
// (or calls func_02006a50(self, 3) for NO_ENTRY).
extern "C" void func_02004f7c(Obj4F7C *self, Obj4F7C *other, s32 player, s32 kind) {
    HitInfo *info = &data_020f0214[kind];
    s32 amount    = info->amount;
    u8 next;
    void *fx;
    u16 sound;
    u16 buf[6];

    if (M2C_FIELD(self, u32 *, 0x8) & 0x802) {
        return;
    }
    if (M2C_FIELD(self, u16 *, 0xc) == 1 && (info->flags & 4)) {
        if (func_02093fd0(func_020917b4(&data_0210930c)) != 0x11) {
            amount = 1;
        }
    }
    if (M2C_FIELD(self, u8 *, 0x6bb) == 0x37 && self != other) {
        return;
    }
    if (M2C_FIELD(self, u8 *, 0x6be) != 0) {
        return;
    }
    if (M2C_FIELD(self, u16 *, 0x1a8) & 0x10) {
        return;
    }
    if (M2C_FIELD(self, u32 *, 0x8) & 0x800800) {
        return;
    }
    if (M2C_FIELD(self, Flags186 *, 0x186).frozen) {
        return;
    }
    if (data_02104d90 & 4) {
        return;
    }
    if (func_020867ec(&data_02104d90, 1) != 0 && M2C_FIELD(self, u16 *, 0xc) == 1) {
        return;
    }
    if ((info->flags & 2) && (M2C_FIELD(self, u32 *, 0x194) & 0x1000)) {
        func_02004b78(self, 0x20);
    }
    if (M2C_FIELD(self, u8 *, 0x6bb) == 0x54) {
        return;
    }
    if (amount <= 0 && !(info->flags & 8)) {
        return;
    }
    if (M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xad0), s32 *, 0x10) != 0) {
        func_02005458(self, other);
    }
    func_02095ee8(&data_0210786c, (u8) player, self->unknown44());
    func_0200b938((u8 *) self + 0x69c, 1);

    if (M2C_FIELD(self, s16 *, 0x6b6) <= amount) {
        self->defeated(other);
    } else {
        M2C_FIELD(self, s16 *, 0x6b6) -= amount;
        if (M2C_FIELD(self, s16 *, 0x6b6) <= 2) {
            if (M2C_FIELD(self, u8 *, 0x6bb) == 9) {
                if (M2C_FIELD(self, u16 *, 0x6ea) != 0x32) {
                    func_020063d4(self, 0x32, 0);
                }
            } else if (M2C_FIELD(self, u8 *, 0x6bb) == 0x20) {
                if (M2C_FIELD(self, u16 *, 0x6ea) != 0x4b) {
                    func_020063d4(self, 0x4b, 0);
                }
            }
        }
        func_02004800(self);
        if ((M2C_FIELD(self, u32 *, 0x8) & 1) == 1) {
            u8 *tracker = M2C_FIELD(self, u8 **, 0x604);
            DistLimit lim;
            if (tracker != 0) {
                func_0202d5f0(tracker, self, 3);
                if (M2C_FIELD(other, u16 *, 0xc) & 3) {
                    s32 mine = self->unknown44();
                    if (func_0202d7f8(self, mine, other, other->unknown44()) != 0) {
                        Ref tmp;
                        Link *l;
                        func_02005428(&tmp, other);
                        l = ref_link(tmp.owner);
                        ref_unlink((Ref *) (tracker + 0xc));
                        ref_attach((Ref *) (tracker + 0xc), l);
                        ref_unlink(&tmp);
                    }
                }
                lim.v = 0x12c000;
                func_020942c0(self, lim, (void *) 0x7d0, 0, self);
            }
        }
    }

    next = data_020eebbb[M2C_FIELD(self, u8 *, 0x6bb) * 5];
    if (next == M2C_FIELD(self, u16 *, 0x6ee)) {
        return;
    }
    if (M2C_FIELD(self, u8 *, 0x6bb) > 0x47) {
        return;
    }
    if (M2C_FIELD(self, u16 *, 0x6ee) == NO_ENTRY) {
        return;
    }
    fx = func_0205e80c(0x1bc, 3, 4);
    if (fx != 0) {
        fx = func_0200ca7c(fx, M2C_FIELD(func_0208dad8(M2C_FIELD(self, u16 *, 0x6ee)), u16 *, 4), 0, (u8 *) self + 0x8c);
    }
    sound = M2C_FIELD(func_0208dad8(M2C_FIELD(self, u16 *, 0x6ee)), u16 *, 6);
    if (sound != INVALID_ID) {
        func_0201c778(buf);
        func_0201c858(buf, 0, sound);
        if (func_0201ca1c(M2C_FIELD(fx, u16 *, 0x180)) != INVALID_ID) {
            func_020ab40c((u8 *) fx + 0xd8, func_0201ca1c(M2C_FIELD(fx, u16 *, 0x180)));
            func_020ab574((u8 *) fx + 0xd8, buf, 1);
        }
    }
    if (next != NO_ENTRY) {
        func_020063d4(self, next, 0);
    } else {
        func_02006a50(self, 3);
    }
}
