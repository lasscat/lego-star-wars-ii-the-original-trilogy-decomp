#include "m2c.h"

typedef s16 fx16;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u16 *face;
    s32 dist;
} Res;

typedef struct {
    fx16 x;
    fx16 y;
    fx16 z;
} VecFx16;

typedef struct {
    union {
        s32 d;
        struct {
            u32 leaf : 1;
            u32 noback : 1;
            u32 : 30;
        } f;
    } w0;
    union {
        struct {
            VecFx16 n;
            u16 child;
        } p;
        struct {
            u32 axis : 2;
            u32 positive : 1;
            u32 : 29;
        } a;
        s32 kind;
    } w1;
} Node;

typedef struct {
    u8 pad[0x10];
    s32 nodeOff;
    s32 leafOff[1];
} Table;

typedef struct {
    s32 f0;
    Table *tab;
    Vec3 pos;
} Model;

typedef struct {
    u16 id;
    u16 pad;
} LeafFace;

typedef struct {
    u16 count;
    LeafFace face[1];
} Leaf;

typedef struct {
    u16 node;
    u16 plane;
    fx16 t[2];
} Entry;

typedef struct {
    fx16 v;
} Fx16;

typedef struct {
    Fx16 a;
    Fx16 b;
} Fx16Pair;

extern s32 data_027e022c;
void func_0204c74c(void *box, void *v, void *out);
s32 FX_Div(s32, s32);

static inline s32 fx_mul(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline fx16 pair_min(const Fx16Pair *r, fx16 limit) {
    Fx16Pair q;
    q.a = r->a;
    // FAKE: q.b is never read; the target keeps this store of the limit
    q.b.v = limit;
    return (q.a.v > limit) ? limit : q.a.v;
}

static inline s32 dotc(s32 x, s32 y, s32 z, const VecFx16 *n) {
    return (s32) (((s64) x * n->x + (s64) y * n->y + (s64) z * n->z + 0x800) >> 12);
}

typedef struct {
    s32 d;
    VecFx16 n;
    u16 child;
} PlaneNode;

// FAKE: node_normal and node_plane are extra views of nd->w1.p.n (same address); the target loads the normal again for the
// near and far corners, and one shared access path lets the compiler reuse the first loads
static inline VecFx16 *node_normal(Node *n) {
    return (VecFx16 *) &n->w1;
}

static inline PlaneNode *node_plane(Node *n) {
    return (PlaneNode *) n;
}

/*
 * Sweeps a box along dir through the model's plane tree. Nodes are visited with an explicit stack; each entry holds the
 * part of the sweep (t[0]..t[1], Q12, 0x1000 = all of dir) that is still inside the node, and the last plane crossed.
 * At a leaf, the crossed planes are looked up in the leaf's face list. The entry with the smallest t[0] wins:
 * res->face points to its id and res->dist is its t[0]. Without a hit, face is NULL and dist is 0x2000 (above any t).
 * A zero dir is never a hit.
 */
void func_01ff9188(Res *res, Model *model, s32 (*box)[2], s32 *dir) {
    Entry *sp;
    Node *nd;
    s32 dn;
    fx16 t0;
    u16 node;
    s32 near;
    s32 tb;
    s32 ta;
    Entry *e;
    s32 *q;
    Node *nodes;
    Entry stack[40];
    u16 *found;
    fx16 *p;
    u16 plane;
    fx16 t1;
    Leaf *leaf;
    Table *tab;
    s32 d;
    s32 i;
    u16 id;
    s32 cnt;
    s32 b[3][2];
    u32 positive;
    s32 far;
    Vec3 neg;
    u32 axis;

    res->face = NULL;
    res->dist = 0x2000;
    if (dir[0] == 0 && dir[1] == 0 && dir[2] == 0) {
        return;
    }

    q = &b[0][0];
    do {
        *q++ = 0;
    } while (q < (s32 *) (b + 3));
    {
        s32 z = -model->pos.z;
        s32 y = -model->pos.y;
        s32 x = -model->pos.x;
        neg.x = x;
        neg.y = y;
        neg.z = z;
    }
    // b = box moved into model space; one {low, high} pair for each axis
    func_0204c74c(box, &neg, b);

    tab   = model->tab;
    nodes = (Node *) ((u8 *) tab + tab->nodeOff);
    e     = stack;
    do {
        p = e->t;
        e++;
        do {
            *p++ = 0;
        } while (p < (fx16 *) e);
    } while (e < stack + 40);
    sp        = stack;
    sp->node  = 0;
    sp->plane = 0xffff;
    sp->t[0]  = 0;
    sp->t[1]  = 0x1000;

    do {
        e     = sp--;
        node  = e->node;
        plane = e->plane;
        t0    = e->t[0];
        t1    = e->t[1];
        if (res->dist <= t0) {
            continue;
        }
        // dn: movement along the node normal. near/far: smallest/largest signed plane distance over the box corners
        nd = &nodes[node];
        d  = nd->w0.d;
        if (nd->w1.kind >= 0x40000000) {
            axis     = nd->w1.a.axis;
            positive = nd->w1.a.positive;
            if (positive) {
                dn   = dir[axis];
                near = d + b[axis][!positive];
                far  = d + b[axis][positive];
            } else {
                dn   = -dir[axis];
                near = d - b[axis][!positive];
                far  = d - b[axis][positive];
            }
        } else {
            fx16 nx;
            fx16 ny;
            fx16 nz;
            dn   = (s32) (((s64) dir[0] * nd->w1.p.n.x + (s64) dir[1] * nd->w1.p.n.y + (s64) dir[2] * nd->w1.p.n.z + 0x800) >>
                        12);
            nx   = node_plane(nd)->n.x;
            ny   = node_plane(nd)->n.y;
            nz   = node_plane(nd)->n.z;
            ny   = -ny;
            nz   = -nz;
            nx   = -nx;
            near = d + dotc(b[0][nx >= 0], b[1][ny >= 0], b[2][nz >= 0], &nd->w1.p.n);
            // FAKE: the no-op (s32 *) row casts give every row its own base address
            far = d + dotc(((s32 *) b[0])[node_normal(nd)->x >= 0], ((s32 *) b[1])[node_normal(nd)->y >= 0],
                           ((s32 *) b[2])[node_normal(nd)->z >= 0], node_normal(nd));
        }
        // data_027e022c: distance tolerance on both sides of the plane
        if (dn == 0) {
            if (far >= -data_027e022c && !nd->w0.f.noback) {
                (++sp)->node = nd->w0.f.leaf ? node + 1 : nd->w1.p.child;
            }
            if (near > data_027e022c) {
                continue;
            }
            (++sp)->node = node + 1;
            sp->t[0]     = t0;
            sp->t[1]     = t1;
            if (near >= -data_027e022c) {
                sp->plane = node;
            } else {
                sp->plane = plane;
            }
        } else {
            ta = fx_mul(dn, t0);
            tb = fx_mul(dn, t1);
            if (dn > 0) {
                if (tb + far >= -data_027e022c && !nd->w0.f.noback) {
                    (++sp)->node = nd->w0.f.leaf ? node + 1 : nd->w1.p.child;
                    if (-far > ta) {
                        Fx16Pair r;
                        sp->plane = node;
                        r.a.v     = FX_Div(-far, dn);
                        r.b.v     = 0x1000;
                        sp->t[0]  = pair_min(&r, 0x1000);
                    }
                }
                if (ta + near > data_027e022c) {
                    continue;
                }
                (++sp)->node = node + 1;
                sp->plane    = plane;
                sp->t[0]     = t0;
                if (-near >= tb) {
                    sp->t[1] = t1;
                } else {
                    sp->t[1] = FX_Div(-near, dn);
                }
            } else {
                if (ta + far >= -data_027e022c && !nd->w0.f.noback) {
                    (++sp)->node = nd->w0.f.leaf ? node + 1 : nd->w1.p.child;
                    if (-far > tb) {
                        sp->t[1] = FX_Div(-far, dn);
                    }
                }
                if (tb + near > data_027e022c) {
                    continue;
                }
                (++sp)->node = node + 1;
                sp->t[1]     = t1;
                if (-near < ta) {
                    Fx16Pair r;
                    sp->plane = node;
                    r.a.v     = FX_Div(-near, dn);
                    r.b.v     = 0x1000;
                    sp->t[0]  = pair_min(&r, 0x1000);
                } else {
                    sp->plane = plane;
                    sp->t[0]  = t0;
                }
            }
        }
        // A leaf: child selects the face list; walk back over the crossed planes until one is a face of this leaf
        if (nd->w0.f.leaf) {
            leaf  = (Leaf *) ((u8 *) model->tab + model->tab->leafOff[nd->w1.p.child]);
            found = NULL;
            e     = sp;
            for (;;) {
                id = e->plane;
                if (id == 0xffff) {
                    break;
                }
                cnt = leaf->count;
                for (i = 0; i < cnt; i++) {
                    if (id == leaf->face[i].id) {
                        found = &leaf->face[i].id;
                        break;
                    }
                }
                if (found != NULL) {
                    break;
                }
                while (e[-1].plane == id) {
                    e--;
                    id = e->plane;
                }
                e--;
            }
            if (sp->t[0] < res->dist && found != NULL) {
                res->face = found;
                res->dist = sp->t[0];
            }
            sp--;
        }
    } while (sp >= stack);
}
