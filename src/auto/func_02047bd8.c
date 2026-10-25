#include "m2c.h"

typedef struct {
    u16 v;
} HalfVal;

typedef struct {
    u16 flag_a : 1;
    u16 flag_b : 1;
} Flags;

typedef struct {
    s32 v;
} Fx;

typedef struct {
    Fx a;
    Fx b;
} Pair;

typedef struct {
    u8 pad0[0x14e];
    Flags flags;
    u8 pad150[0x58];
    u16 mask;
    u8 pad1aa[0x50a];
    HalfVal turn;
} Entity;

typedef struct {
    u8 pad0[4];
    Entity *ent;
    u8 pad8[4];
    u8 flag;
    u8 state;
} Obj;

extern s32 func_02018210(Entity *, HalfVal, HalfVal, s32);

/* Reconstructed from USA ARM9 at 0x02047bd8 (192 bytes).
 *
 * While the object is in state 0, calls func_02018210 with the entity, its turn
 * halfword, a scaled angle and a 0x2000 fixed point value. The 0x2000 pair lives
 * in a stack aggregate of single-field members (as in func_02032a78) so the
 * multiplier is not constant folded; the struct copy p.a = p.b is a real
 * assignment, with no dead stores or other steering. When the entity's flag_b is
 * set, its mask loses bit 0x80 and the object's flag gets bit 0.
 */
void func_02047bd8(Obj *self) {
    HalfVal ang;
    Pair p;

    if (self->state != 0) {
        return;
    }
    p.b.v = 0x2000;
    p.a   = p.b;
    ang.v = (((s64) p.a.v * 0xe38 + 0x800) >> 12);
    func_02018210(self->ent, self->ent->turn, ang, p.a.v);
    if (self->ent->flags.flag_b == 1) {
        self->ent->mask &= ~0x80;
        self->flag |= 1;
    }
}
