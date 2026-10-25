#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x02060fe4 (0xd8 bytes): a constructor-like initializer that
 * runs two list constructors (func_0205d6f8, +0x00 and +0x38) and one sub-object constructor
 * (func_0205569c, +0x70), then sets the plain fields. No vptr store of its own, so it is plain C.
 */

/* One 16-bit angle component; the original copies each component as a one-member struct. */
typedef struct {
    u16 v;
} A16;

typedef struct {
    A16 a;
    A16 b;
    A16 c;
} Trip;

typedef struct {
    s32 x, y, z;
} V3;

typedef struct {
    u8 pad[0x494];
    s32 f494;
    u16 rot[3]; /* 0x498: set from the 0x38e temp */
    s32 f4a0, f4a4, f4a8;
    u8 f4ac;
    V3 vec; /* 0x4b0 */
    u8 f4bc;
    s32 f4c0;
} Obj;

void *func_0205d6f8(void *, s32);
void *func_0205569c(void *);

Obj *func_02060fe4(Obj *self) {
    Trip m;
    Trip l;
    V3 tmp;
    func_0205d6f8(self, 10);
    func_0205d6f8((u8 *) self + 0x38, 10);
    func_0205569c((u8 *) self + 0x70);
    self->f494   = 0;
    self->f4a0   = 0;
    self->f4a4   = 0;
    self->f4a8   = 0;
    self->vec.x  = 0;
    self->vec.y  = 0;
    self->vec.z  = 0;
    m.c.v        = 0x38e;
    l.c          = m.c;
    self->rot[0] = l.c.v;
    m.b.v        = 0x38e;
    l.b          = m.b;
    self->rot[1] = l.b.v;
    m.a.v        = 0x38e;
    l.a          = m.a;
    self->rot[2] = l.a.v;
    self->f4ac   = 1;
    tmp.x        = 0;
    tmp.y        = 0;
    tmp.z        = 0;
    {
        /* vec = tmp with the self-assignment check of the V3 copy operator */
        V3 *o = &tmp;
        if (&self->vec != o) {
            self->vec.x = o->x;
            self->vec.y = o->y;
            self->vec.z = o->z;
        }
    }
    self->f4bc = 0;
    self->f4c0 = 16;
    return self;
}
