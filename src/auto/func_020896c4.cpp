#include "m2c.h"
struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
};
struct Sub {
    u8 pad00[8];
    u8 f08;
};
struct Obj {
    u8 pad04[4];
    u32 flags08;
    u16 kind0c;
    u8 pad0e[0x88 - 0x0e];
    u8 f88;
    u8 f89;
    u8 pad8a[0xb0 - 0x8a];
    Vec3 pos;
    u8 padbc[0x5fc - 0xbc];
    Sub *sub5fc;
    virtual void v0();
    virtual void v1();
    virtual void *get_ref();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual u8 get_kind();
};
struct Entry {
    Vec3 pos;
    void *ref;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    u8 f14;
    u8 pad15[3];
};
static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}
extern "C" void func_020896c4(Entry *entries, u16 *count, Obj *obj) {
    Entry *e;
    Vec3 *src;
    if (obj == NULL) {
        return;
    }
    if ((obj->kind0c & 7) == 0 || obj->f89 == 0) {
        return;
    }
    if (obj->flags08 & 0x802) {
        return;
    }
    e                   = &entries[*count];
    e->f10              = obj->f88;
    e->f11              = obj->f89;
    entries[*count].f12 = 0;
    src                 = &obj->pos;
    vec_set(&entries[*count].pos, src);
    entries[*count].ref = obj->get_ref();
    entries[*count].f14 = obj->kind0c;
    if (obj->kind0c == 4) {
        entries[*count].f13 = obj->get_kind();
    } else if (obj->kind0c == 2) {
        if (obj->sub5fc != NULL) {
            entries[*count].f13 = obj->sub5fc->f08;
        } else {
            entries[*count].f13 = 11;
        }
    }
    *count += 1;
}
