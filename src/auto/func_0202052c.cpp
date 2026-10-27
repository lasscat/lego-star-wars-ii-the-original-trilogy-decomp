#include "m2c.h"

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
    virtual void action(s32, s32, s32, s32); // Slot 0x24.
};

typedef struct {
    s32 v;
} UnkVal;

typedef struct {
    s32 x, y, z;
} Vec;

extern "C" void func_02012744(void *, UnkVal);

static inline int vec_ne(const Vec *a, const Vec *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec *d, const Vec *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void vec_sub(Vec *o, const Vec *a, const Vec *b) {
    s32 z = a->z - b->z;
    s32 y = a->y - b->y;
    s32 x = a->x - b->x;
    o->x  = x;
    o->y  = y;
    o->z  = z;
}

static inline int is_set(const void *p) {
    int r = 0;
    if (p != 0) {
        r = 1;
    }
    return r;
}

enum {
    FLAG_SKIP_STATE_MACHINE = 0x800, // Bit in +0x194: update only, no states.
    ACTION_CODE             = 0x56,  // First argument of every slot 0x24 call.
    TIMER_RELOAD            = 0x78,  // Countdown value restored after a toggle.
};

// Per-tick update of a two-object pair (owner and the object at +0x224,
// which shares the +0x1be halfword layout).
//  - Unless FLAG_SKIP_STATE_MACHINE is set, step a state byte at +0x1bc:
//    states 0 and 1 count +0x1be down and, once it has run out, flip to
//    the other state, issue the slot 0x24 action (last argument 0 or 1)
//    and reload the countdown; states 3 and 4 watch the partner's +0x1be
//    against the copy cached at +0x218 and move between states 3 and 4.
//  - Run the common update func_02012744 with the forwarded argument.
//  - Then sync the partner: with an object at +0x3c, store (that object's
//    vector at +4 minus the partner's +0xb0 vector) into the partner's
//    +0x60 vector; without it, copy the owner's +0xb0 vector into the
//    partner's +0xb0 and set the partner's +0xd1 byte when it changed.
extern "C" void func_0202052c(Obj *obj, UnkVal a1, ...) {
    u8 *partner;
    u8 *anchor;
    u32 has_anchor;
    if (M2C_FIELD(obj, u32 *, 0x194) & FLAG_SKIP_STATE_MACHINE) {
        func_02012744(obj, a1);
        return;
    }
    switch (M2C_FIELD(obj, u8 *, 0x1bc)) {
        case 0: {
            s16 timer                    = M2C_FIELD(obj, s16 *, 0x1be);
            M2C_FIELD(obj, s16 *, 0x1be) = timer - 1;
            if (timer > 0) {
                break;
            }
            M2C_FIELD(obj, u8 *, 0x1bc) = 1;
            obj->action(ACTION_CODE, 0, 1, 0);
            M2C_FIELD(obj, s16 *, 0x1be) = TIMER_RELOAD;
            break;
        }
        case 1: {
            s16 timer                    = M2C_FIELD(obj, s16 *, 0x1be);
            M2C_FIELD(obj, s16 *, 0x1be) = timer - 1;
            if (timer > 0) {
                break;
            }
            M2C_FIELD(obj, u8 *, 0x1bc) = 0;
            obj->action(ACTION_CODE, 0, 1, 1);
            M2C_FIELD(obj, s16 *, 0x1be) = TIMER_RELOAD;
            break;
        }
        case 3:
            if (M2C_FIELD(obj, s32 *, 0x218) != M2C_FIELD(M2C_FIELD(obj, u8 **, 0x224), s16 *, 0x1be)) {
                if (M2C_FIELD(obj, s32 *, 0x218) == 0xf) {
                    obj->action(ACTION_CODE, 0, 1, 0);
                    M2C_FIELD(obj, u8 *, 0x1bc) = 4;
                }
                M2C_FIELD(obj, s32 *, 0x218) = M2C_FIELD(M2C_FIELD(obj, u8 **, 0x224), s16 *, 0x1be);
            } else {
                M2C_FIELD(obj, s32 *, 0x21c)                          = 0;
                M2C_FIELD(M2C_FIELD(obj, u8 **, 0x224), s16 *, 0x1be) = 0;
                M2C_FIELD(obj, s32 *, 0x218)                          = 0;
            }
            break;
        case 4:
            if (M2C_FIELD(obj, s32 *, 0x218) != M2C_FIELD(M2C_FIELD(obj, u8 **, 0x224), s16 *, 0x1be)) {
                M2C_FIELD(obj, s32 *, 0x218) = M2C_FIELD(M2C_FIELD(obj, u8 **, 0x224), s16 *, 0x1be);
            } else {
                M2C_FIELD(obj, s32 *, 0x21c)                          = 0;
                M2C_FIELD(M2C_FIELD(obj, u8 **, 0x224), s16 *, 0x1be) = 0;
                M2C_FIELD(obj, s32 *, 0x218)                          = 0;
                obj->action(ACTION_CODE, 0, 1, 1);
                M2C_FIELD(obj, u8 *, 0x1bc) = 3;
            }
            break;
        case 2:
        case 5:
        case 6:
        case 7:
            break;
    }
    func_02012744(obj, a1);
    partner = M2C_FIELD(obj, u8 **, 0x224);
    if (partner == 0) {
        return;
    }
    anchor     = M2C_FIELD(obj, u8 **, 0x3c);
    has_anchor = anchor != 0;
    if (has_anchor) {
        Vec t;
        vec_sub(&t, (Vec *) (anchor + 4), (Vec *) (partner + 0xb0));
        vec_set((Vec *) (M2C_FIELD(obj, u8 **, 0x224) + 0x60), &t);
    } else {
        Vec *src = (Vec *) ((u8 *) obj + 0xb0);
        if (vec_ne((Vec *) (partner + 0xb0), src)) {
            vec_set((Vec *) (partner + 0xb0), src);
            M2C_FIELD(partner, u8 *, 0xd1) = 1;
        }
    }
}
