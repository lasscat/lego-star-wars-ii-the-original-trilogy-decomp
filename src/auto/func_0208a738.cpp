#include "m2c.h"

struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
};

typedef struct {
    Vec3 pos;
    s32 id;
    u8 key0;
    u8 key1;
    u8 mode;
    u8 arg;
    u32 pad;
} Entry;

typedef struct {
    u16 first;
    s16 end;
    u8 pad4[4];
    s8 id;
    u8 active;
} Zone;

typedef struct {
    Entry entries[434];
    u8 pad_28b0[0x28c4 - 434 * 0x18];
    Zone zones[7];
} Mgr;

// Partial interface: unknown virtuals keep their observed vtable slots.
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
    virtual void unknown24();
    virtual void unknown28();
    virtual void unknown2c();
    virtual void unknown30();
    virtual void unknown34();
    virtual void unknown38();
    virtual void unknown3c();
    virtual void unknown40();
    virtual void unknown44();
    virtual void unknown48();
    virtual void unknown4c();
    virtual void unknown50();
    virtual void unknown54();
    virtual void unknown58(u8 arg); // Slot 0x58.

    u8 pad_04[4];
    u32 flags;
    u16 type;
    u8 pad_0e[0x88 - 0xe];
    u8 key0;
    u8 key1;
    u8 pad_8a[0xb0 - 0x8a];
    Vec3 pos;
    u8 pad_bc[0xd1 - 0xbc];
    u8 dirty;
    u8 pad_d2[0x1b4 - 0xd2];
    s32 id;
    u8 pad_1b8[0x5e0 - 0x1b8];
    u8 sub[1];
};

typedef struct {
    u8 pad_00[0x4c];
    Obj *objs[4];
} Glob;

extern "C" void func_0202c498(void *, u8);
extern "C" Glob data_0210930c;

/* Byte offsets into Mgr used by the raw zone accesses (as in func_02089e60.c). */
enum {
    ZONE_SIZE      = 10,     /* sizeof(Zone) */
    ZONE_FIRST_OFS = 0x28c4, /* zones[0].first */
    ZONE_END_OFS   = 0x28c6  /* zones[0].end */
};

static inline int vec_ne(const Vec3 *a, const Vec3 *b) {
    if (a->x != b->x || a->y != b->y || a->z != b->z) {
        return 1;
    }
    return 0;
}

static inline void vec_set(Vec3 *d, const Vec3 *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline void apply_entry(Obj *obj, Entry *e) {
    if (vec_ne(&obj->pos, &e->pos)) {
        vec_set(&obj->pos, &e->pos);
        obj->dirty = 1;
    }
    obj->id = e->id;
    if (obj->type == 4) {
        obj->unknown58(e->arg);
    } else if (obj->type == 2) {
        if (e->arg != 0xb) {
            func_0202c498(obj->sub, e->arg);
        }
    }
}

/*
 * Called by func_02089e60 for every object on its two node lists. Skips
 * objects without flag 0x100000, objects held in data_0210930c.objs[0..3]
 * and objects with key1 == 0. Otherwise scans the entries of zone `slot`
 * ([first, end), stopping at an entry with key1 == 0) for one whose
 * key0/key1 equal the object's; on a hit it marks seen[i] and applies the
 * entry (position, id, then a type-specific call with entry->arg). With no
 * hit, flag 2 is set on the object.
 */
extern "C" void func_0208a738(Mgr *mgr, s32 slot, Obj *obj, u8 *seen) {
    u8 hit;
    u16 i;
    u8 found;
    u8 j;

    if (!(obj->flags & 0x100000)) {
        return;
    }
    found = 0;
    for (j = 0; j < 4; j++) {
        if (obj == data_0210930c.objs[j]) {
            found = 1;
            break;
        }
    }
    if (found) {
        return;
    }
    if (obj->key1 == 0) {
        return;
    }
    hit = 0;
    for (i = *(u16 *) ((u8 *) mgr + slot * ZONE_SIZE + ZONE_FIRST_OFS);
         i < *(s16 *) ((u8 *) mgr + slot * ZONE_SIZE + ZONE_END_OFS); i++) {
        if (mgr->entries[i].key1 == 0) {
            break;
        }
        if (obj->key0 == mgr->entries[i].key0 && obj->key1 == mgr->entries[i].key1) {
            seen[i] = 1;
            apply_entry(obj, &mgr->entries[i]);
            hit = 1;
            break;
        }
    }
    if (hit == 0) {
        obj->flags |= 2;
    }
}
