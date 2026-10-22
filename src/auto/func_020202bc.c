/* Reconstructed from USA ARM9 at 0x020202bc (516 bytes).
 * Creates the child entity for this object and copies a position into it.
 */
#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u8 pre[0x24];
    Vec pos;
    s32 s[3];
    u16 w[4];
    u8 f[2];
} Tpl;

typedef struct {
    u8 pre[0x8c];
    Tpl tpl;
    u8 mid[0xea];
    u16 f1be;
} Ent;

typedef struct {
    u8 pre[4];
    Vec pos;
} Par;

typedef struct {
    u8 pre[0x3c];
    Par *parent;
    u8 pre2[0x4c];
    Tpl tpl;
    u8 mid[0x13e];
    u16 type;
    u8 mid2[0x10];
    Ent *child;
} Obj;

extern void func_020accac(void *, void *, void *, void *);
extern void *func_02015138(s32, s32, void *);

void func_020202bc(Obj *obj) {
    u16 type = obj->type;
    s32 v[3];
    u32 var;

    if (type == 0x182) {
        u16 p[4];
        Tpl t;
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
        p[0] = 0;
        p[1] = obj->tpl.w[1];
        p[2] = 0;
        func_020accac(&t, &obj->tpl.pos, p, v);
        obj->child = func_02015138(0x198, 0, &t);
    } else if (type == 0x57) {
        u16 p[4];
        Tpl t;
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
        p[0] = 0;
        p[1] = obj->tpl.w[1];
        p[2] = 0;
        func_020accac(&t, &obj->tpl.pos, p, v);
        obj->child = func_02015138(0x19f, 0, &t);
    } else {
        u16 p[4];
        Tpl t;
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
        p[0] = 0;
        p[1] = obj->tpl.w[1];
        p[2] = 0;
        func_020accac(&t, &obj->tpl.pos, p, v);
        obj->child = func_02015138(0x197, 0, &t);
    }

    var = (obj->parent != 0);
    if (var != 0) {
        Ent *child = obj->child;
        Par *par   = obj->parent;
        if ((child->tpl.pos.x != par->pos.x) || (child->tpl.pos.y != par->pos.y) || (child->tpl.pos.z != par->pos.z)) {
            var = 1;
        } else {
            var = 0;
        }
        if (var != 0) {
            if ((void *) &child->tpl.pos != (void *) &par->pos) {
                child->tpl.pos.x = par->pos.x;
                child->tpl.pos.y = par->pos.y;
                child->tpl.pos.z = par->pos.z;
            }
            child->tpl.f[1] = 1;
        }
    } else {
        Ent *child = obj->child;
        Vec *own   = &obj->tpl.pos;
        if ((child->tpl.pos.x != own->x) || (child->tpl.pos.y != own->y) || (child->tpl.pos.z != own->z)) {
            var = 1;
        } else {
            var = 0;
        }
        if (var != 0) {
            if ((void *) &child->tpl.pos != (void *) own) {
                child->tpl.pos.x = own->x;
                child->tpl.pos.y = own->y;
                child->tpl.pos.z = own->z;
            }
            child->tpl.f[1] = 1;
        }
    }
    obj->child->f1be = 0;
}
