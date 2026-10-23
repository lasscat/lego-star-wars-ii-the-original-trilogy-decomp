#include "m2c.h"

/* 12-byte vector of 4.12 fixed point coordinates. */
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

/* 0x2c-byte element of the tracked list. */
typedef struct {
    Vec3 pos;
    s32 f0c;
    s32 f10;
    Vec3 aux;
    s32 f20;
    s32 f24;
    s32 f28;
} Elem;

/* Object with a list of elements, a cursor and two vectors. */
typedef struct {
    Elem *elems;
    u16 count;
    u16 index;
    s32 f08;
    u16 f0c;
    u8 flag;
    u8 f0f;
    Vec3 v1;
    Vec3 out;
    s32 f28;
} Obj;

M2C_UNK func_02055700(void *, void *);                 /* extern */
extern M2C_UNK data_027e0410;

void func_02062550(Obj *self) {
    if (self->count > 2) {
        Elem *e;
        Vec3 tmp;
        s32 tx, ty, tz;

        self->index = self->index + 1;
        if (self->index >= self->count) {
            self->index = 0;
        }
        if (self->flag) {
            e     = &self->elems[self->index];
            tx    = e->pos.x + self->v1.x;
            tz    = e->pos.z + self->v1.z;
            ty    = e->pos.y + self->v1.y;
            tmp.x = tx;
            tmp.y = ty;
            tmp.z = tz;
            if (&self->out != &tmp) {
                self->out.x = tmp.x;
                self->out.y = tmp.y;
                self->out.z = tmp.z;
            }
        }
        func_02055700(&data_027e0410, self);
    } else {
        Elem *e;
        Vec3 tmp;
        s32 tx, ty, tz;

        if (!self->flag) {
            return;
        }
        e     = &self->elems[self->index];
        tx    = e->pos.x + self->v1.x;
        tz    = e->pos.z + self->v1.z;
        ty    = e->pos.y + self->v1.y;
        tmp.x = tx;
        tmp.y = ty;
        tmp.z = tz;
        if (&self->out != &tmp) {
            self->out.x = tmp.x;
            self->out.y = tmp.y;
            self->out.z = tmp.z;
        }
        func_02055700(&data_027e0410, self);
    }
}
