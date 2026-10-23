/* Reconstructed from USA ARM9 at 0x02017310 (588 bytes).
 * Spawns a companion entity for the three self types 0x74, 0x75 and 0x6f and
 * copies the position of self over to it.
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
    u8 mid[0x13e];
    u16 type;
} Ent;

extern void func_020accac(void *, void *, void *, void *);
extern void *func_02015138(s32, s32, void *);

void func_02017310(Ent *self) {
    s32 v[3];
    u16 type = self->type;

    if (type == 0x74) {
        u16 p[4];
        Tpl t;
        Ent *obj;
        s32 *sp;
        int var;
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
        p[0] = 0;
        p[1] = self->tpl.w[1];
        p[2] = 0;
        func_020accac(&t, &self->tpl.pos, p, v);
        obj = func_02015138(0x7f, 0, &t);
        sp  = (s32 *) &self->tpl.pos;
        if ((obj->tpl.pos.x != sp[0]) || (obj->tpl.pos.y != sp[1]) || (obj->tpl.pos.z != sp[2])) {
            var = 1;
        } else {
            var = 0;
        }
        if (var == 0) {
            return;
        }
        if ((void *) &obj->tpl.pos != (void *) sp) {
            obj->tpl.pos.x = sp[0];
            obj->tpl.pos.y = sp[1];
            obj->tpl.pos.z = sp[2];
        }
        obj->tpl.f[1] = 1;
    } else if (type == 0x75) {
        u16 p[4];
        Tpl t;
        Ent *obj;
        s32 *sp;
        int var;
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
        p[0] = 0;
        p[1] = self->tpl.w[1];
        p[2] = 0;
        func_020accac(&t, &self->tpl.pos, p, v);
        obj = func_02015138(0x80, 0, &t);
        sp  = (s32 *) &self->tpl.pos;
        if ((obj->tpl.pos.x != sp[0]) || (obj->tpl.pos.y != sp[1]) || (obj->tpl.pos.z != sp[2])) {
            var = 1;
        } else {
            var = 0;
        }
        if (var == 0) {
            return;
        }
        if ((void *) &obj->tpl.pos != (void *) sp) {
            obj->tpl.pos.x = sp[0];
            obj->tpl.pos.y = sp[1];
            obj->tpl.pos.z = sp[2];
        }
        obj->tpl.f[1] = 1;
    } else if (type == 0x6f) {
        u16 p[4];
        Tpl t;
        Ent *obj;
        s32 *sp;
        int var;
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
        p[0] = 0;
        p[1] = self->tpl.w[1];
        p[2] = 0;
        func_020accac(&t, &self->tpl.pos, p, v);
        obj = func_02015138(0x7e, 0, &t);
        sp  = (s32 *) &self->tpl.pos;
        if ((obj->tpl.pos.x != sp[0]) || (obj->tpl.pos.y != sp[1]) || (obj->tpl.pos.z != sp[2])) {
            var = 1;
        } else {
            var = 0;
        }
        if (var == 0) {
            return;
        }
        if ((void *) &obj->tpl.pos != (void *) sp) {
            obj->tpl.pos.x = sp[0];
            obj->tpl.pos.y = sp[1];
            obj->tpl.pos.z = sp[2];
        }
        obj->tpl.f[1] = 1;
    }
}
