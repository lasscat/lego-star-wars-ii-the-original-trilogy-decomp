#include "m2c.h"

typedef struct Vec3 {
    s32 x, y, z;
} Vec3;

typedef struct Vec3s {
    s16 x, y, z;
} Vec3s;

typedef struct Node {
    union {
        s32 dist;
        struct {
            u32 leaf : 1;
            u32 skip : 1;
            u32 rest : 30;
        } f;
    } d;
    union {
        struct {
            u32 axis : 2;
            u32 neg : 1;
            u32 pad : 29;
        } a;
        s32 kind;
        struct {
            Vec3s n;
            u16 child;
        } n;
    } p;
} Node;

typedef struct Tree {
    u8 pad0[0x10];
    s32 nodes;
} Tree;

typedef struct World {
    u8 pad0[4];
    Tree *tree;
    Vec3 pos;
} World;

typedef struct Entry {
    u16 node;
    u16 pad;
    u16 extra[2];
} Entry;

void func_0204c74c(void *arg0, void *arg1, void *arg2);

static inline void VecNeg(Vec3 *d, const Vec3 *s) {
    s32 z = -s->z;
    s32 y = -s->y;
    s32 x = -s->x;
    d->x  = x;
    d->y  = y;
    d->z  = z;
}

static inline void BoxSupport(Vec3 *out, s32 (*box)[2], const Vec3s *n) {
    out->z = box[2][n->z >= 0];
    out->x = box[0][n->x >= 0];
    out->y = box[1][n->y >= 0];
}

static inline s32 *PickP(s32 *row, s16 v) {
    row += v >= 0;
    return row;
}

static inline void BoxSupportFar(Vec3 *out, s32 (*box)[2], const Vec3s *n) {
    s32 *pz;
    s32 ix;
    s32 *py;

    pz     = PickP(box[2], n->z);
    ix     = n->x >= 0 ? 1 : 0;
    py     = PickP(box[1], n->y);
    out->z = *pz;
    out->x = box[0][ix];
    out->y = *py;
}

static inline s32 DotSc(const Vec3 *a, const Vec3s *b) {
    return (s32) (((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z + 0x800) >> 12);
}

static inline s32 DotNc(const Vec3 *a, const Node *b) {
    return (s32) (((s64) a->x * b->p.n.n.x + (s64) a->y * b->p.n.n.y + (s64) a->z * b->p.n.n.z + 0x800) >> 12);
}

/* Node words at or above this value are axis-aligned split nodes (axis/neg bitfields);
 * smaller values hold a plane normal. */
enum {
    AXIS_SPLIT_KIND = 0x40000000
};

/* Builds a min/max box from box and the negated world position (func_0204c74c), then walks
 * the node tree with an explicit stack. Each node gives a near and a far signed distance of
 * the box against the node plane. Returns 1 when near <= 0 at a leaf node, otherwise 0. */
s32 func_0204c8a8(World *world, s32 *box) {
    s32 out[3][2];
    Vec3 neg;
    Entry stack[40];
    Entry *e;
    u16 idx;
    Node *node;
    Entry *sp;
    s32 d;
    Node *nodes;
    s32 *o;
    u16 *x;

    o = out[0];
    do {
        *o++ = 0;
    } while (o < out[0] + 6);
    VecNeg(&neg, &world->pos);
    func_0204c74c(box, &neg, out);
    nodes = (Node *) ((u8 *) world->tree + world->tree->nodes);
    e     = stack;
    do {
        x = e->extra;
        do {
            *x++ = 0;
        } while (x < e->extra + 2);
        e++;
    } while (e < stack + 40);
    sp       = stack;
    sp->node = 0;
    do {
        s32 near;
        s32 far;
        idx = sp->node;
        sp--;
        node = &nodes[idx];
        d    = node->d.dist;
        if (node->p.kind >= AXIS_SPLIT_KIND) {
            u32 axis = node->p.a.axis;
            u32 sgn  = node->p.a.neg;
            if (sgn) {
                near = d + out[axis][sgn == 0];
                far  = d + out[axis][sgn];
            } else {
                near = d - out[axis][sgn == 0];
                far  = d - out[axis][sgn];
            }
        } else {
            Vec3 cn;
            Vec3 cf;
            Vec3s m;
            const Vec3s *n = &node->p.n.n;
            s16 z, y, x;
            z   = node->p.n.n.z;
            y   = node->p.n.n.y;
            x   = node->p.n.n.x;
            z   = -z;
            y   = -y;
            x   = -x;
            m.x = x;
            m.y = y;
            m.z = z;
            BoxSupport(&cn, out, &m);
            near = d + DotSc(&cn, n);
            BoxSupportFar(&cf, out, &node->p.n.n);
            far = d + DotNc(&cf, node);
        }
        if (far >= 0 && !node->d.f.skip) {
            (++sp)->node = node->d.f.leaf ? idx + 1 : node->p.n.child;
        }
        if (near <= 0) {
            if (!node->d.f.leaf) {
                sp++;
                sp->node = idx + 1;
            } else {
                return 1;
            }
        }
    } while (sp >= stack);
    return 0;
}
