#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;
typedef struct {
    s32 value;
} Fixed;
typedef struct {
    Fixed x, y, z;
} Scale;
typedef struct {
    u16 mode;
    u16 pad;
    u32 result;
    u64 input;
} CPRegs;

// Declarations only: unknown virtuals keep their observed vtable slots.
class Actor {
public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0c();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1c();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void vfunc28();
    virtual void vfunc2c();
    virtual void vfunc30();
    virtual void vfunc34();
    virtual void vfunc38();
    virtual void vfunc3c();
    virtual void release(Actor *other); // Slot 0x40.

    u8 unknown04[8];
    u16 kind;
    u8 unknown0e[0x7e];
    s32 matrix[9];
    Vec3 position;
    Scale scale;
    u16 rotation[4];
    u8 rotationDirty;
    u8 matrixDirty;
    u8 unknownd2[0x5e9];
    u8 variant;
};
typedef struct {
    u8 unknown00[0x1bc];
    Vec3 start;
    Vec3 end;
} Link;
typedef struct {
    Link *link;
    s32 height;
    u8 corner;
} Segment;
typedef struct {
    Actor *owner;
    u32 unknown04;
    Segment segs[8];
    u8 count;
} Chain;
typedef struct {
    u8 unknown00[4];
    Actor *actor;
    u8 unknown08[0x2c];
    Chain *chain;
} Self;

extern "C" void func_01ffa6f8(void *, const void *);
extern "C" void func_01ffa958(Vec3 *, const void *, const Vec3 *);
extern "C" void func_02001b28(Link *);
extern "C" void func_0200d6d0(Vec3 *, const Vec3 *, s32);
extern "C" void func_02049854(Self *);
extern "C" s32 func_02049cf4(Self *, Vec3 *);
extern "C" void *func_0204a0c4(Chain *);
extern "C" void func_0205e84c(Chain *);
extern "C" void func_020b9584(s32, Vec3 *);
extern "C" void func_0204a124(Vec3 *, const Vec3 *, const void *);

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}
static inline void vec_sub(Vec3 *out, const Vec3 *a, const Vec3 *b) {
    s32 z  = a->z - b->z;
    s32 y  = a->y - b->y;
    s32 x  = a->x - b->x;
    out->x = x;
    out->y = y;
    out->z = z;
}
static inline Vec3 *vec_init(Vec3 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}
static inline s32 multiplyFixed(s32 value, const Fixed *scale) {
    return (s32) (((s64) value * scale->value + 0x800) >> 12);
}
static inline Vec3 *worldOffset(Vec3 *result, Actor *actor, const Vec3 *offset) {
    if (actor->rotationDirty) {
        actor->matrixDirty   = 1;
        actor->rotationDirty = 0;
        func_01ffa6f8(actor->matrix, actor->rotation);
    }
    func_01ffa958(result, actor->matrix, offset);
    if (actor->scale.x.value != 0x1000 || actor->scale.y.value != 0x1000 || actor->scale.z.value != 0x1000) {
        Fixed x   = actor->scale.x;
        result->x = multiplyFixed(result->x, &x);
        Fixed y   = actor->scale.y;
        result->y = multiplyFixed(result->y, &y);
        Fixed z   = actor->scale.z;
        result->z = multiplyFixed(result->z, &z);
    }
    result->x += actor->position.x;
    result->y += actor->position.y;
    result->z += actor->position.z;
    return result;
}
static inline void releaseTo(Actor *actor, Actor *other) {
    actor->release(other);
}
static inline void setLink(Link *link, const Vec3 *start, const Vec3 *end) {
    vec_set(&link->start, start);
    vec_set(&link->end, end);
}
static inline void destroyChain(Self *self) {
    Chain *chain = self->chain;
    if (chain != 0) {
        func_0204a0c4(chain);
        func_0205e84c(chain);
    }
    self->chain = 0;
}

extern "C" void func_02049180(Self *self) {
    Vec3 corners[5];
    Vec3 size;
    Vec3 cur;
    Vec3 prev;
    Vec3 tmp;
    Vec3 box;
    Vec3 p0;
    Vec3 q;
    Vec3 qs;
    Vec3 w0;
    Vec3 w1;
    Vec3 lastPos;
    Vec3 last;
    Vec3 lastScaled;
    Actor *actor = self->chain->owner;
    Actor *owner;
    Segment *seg;
    int i;
    Segment *prevSeg;
    Link *link;
    Vec3 *a;
    Vec3 *b;

    {
        Vec3 *c = corners;
        vec_init(c, -0x1000, 0, -0x1000);
        c = &corners[1];
        vec_init(c, 0x1000, 0, -0x1000);
        c = &corners[2];
        vec_init(c, 0x1000, 0, 0x1000);
        c = &corners[3];
        vec_init(c, -0x1000, 0, 0x1000);
        vec_init(&size, 0, 0, 0);
        c = &corners[4];
        vec_init(c, 0, 0, 0);
    }

    owner = self->chain->owner;
    if (owner->kind == 2 && owner->variant == 0x54) {
        vec_set(&size, vec_init(&tmp, 0x2000, 0, 0x5000));
        func_0204a124(&box, &size, &actor->scale);
        if (func_02049cf4(self, &box)) {
            releaseTo(owner, self->actor);
            destroyChain(self);
            return;
        }
        {
            Segment *s          = &self->chain->segs[self->chain->count - 1];
            Link *l             = s->link;
            volatile CPRegs *cp = (CPRegs *) 0x40002b0;
            Vec3 d;
            s64 t;
            vec_sub(&d, &l->end, &l->start);
            t         = (s64) d.z * d.z;
            t         = (s64) d.x * d.x + (s64) d.y * d.y + t;
            cp->mode  = 1;
            cp->input = t << 2;
            while (cp->mode & 0x8000) {
            }
            if ((s32) (*(volatile u32 *) 0x40002b4 + 1) >> 1 >= 0x2d000) {
                func_020b9584(0xaf, &s->link->start);
                destroyChain(self);
                return;
            }
        }
    }
    func_02049854(self);

    seg = &self->chain->segs[0];
    func_0204a124(&p0, &corners[seg->corner], &size);
    func_0200d6d0(&cur, &p0, seg->height);
    for (i = 0; i < self->chain->count - 1; i++) {
        prev.x  = cur.x;
        prev.y  = cur.y;
        prev.z  = cur.z;
        prevSeg = seg;
        seg     = &self->chain->segs[i + 1];
        func_0204a124(&qs, &corners[seg->corner], &size);
        func_0200d6d0(&q, &qs, seg->height);
        vec_set(&cur, &q);
        a    = worldOffset(&w0, actor, &prev);
        b    = worldOffset(&w1, actor, &cur);
        link = prevSeg->link;
        setLink(link, a, b);
        func_02001b28(link);
    }
    seg = &self->chain->segs[self->chain->count - 1];
    func_0204a124(&lastScaled, &corners[seg->corner], &size);
    func_0200d6d0(&last, &lastScaled, seg->height);
    a    = worldOffset(&lastPos, actor, &last);
    link = seg->link;
    setLink(link, a, &self->actor->position);
    func_02001b28(link);
}
