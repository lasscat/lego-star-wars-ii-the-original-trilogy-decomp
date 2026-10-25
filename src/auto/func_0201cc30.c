#include "m2c.h"

typedef struct {
    s32 x, y, z;
} Vec3;

typedef struct {
    u8 pad[0x38];
    u8 *anims;
} Shared4;

typedef struct {
    u8 pad[4];
    Shared4 *s4;
} Shared;

typedef struct {
    u8 pad[0x68];
    u8 *g68;
} Globals;

typedef struct {
    u8 pad[0x1d1];
    u8 f1d1;
    u8 f1d2;
    u8 f1d3;
    u8 f1d4;
    u8 f1d5;
} Obj;

typedef struct {
    u8 pad[0x5da];
    u8 slot;
} Owner;

extern void *func_020aaeb4(void);
extern void func_020a0418(void *, void *, s8);
extern void func_020a98f8(void *, Vec3 *);
extern void func_020a95d4(void *, s32, s32);
extern void func_020675d8(void *, u8);
extern Globals data_0210930c;
extern Obj *data_02101b24[];

void func_0201cc30(Obj *obj, Owner *owner) {
    u8 slot    = owner->slot;
    void *eng  = func_020aaeb4();
    Shared *sh = *(Shared **) (data_0210930c.g68 + 0x38c);
    u8 t;

    if (obj == data_02101b24[slot]) {
        return;
    }
    t = obj->f1d3;
    if (t != 0) {
        func_020a0418(eng, sh->s4->anims + (t - 1) * 8, 1);
    } else {
        t = obj->f1d4;
        if (t != 0) {
            func_020a0418(eng, sh->s4->anims + (t - 1) * 8, 0);
        }
    }
    t = obj->f1d5;
    if (t != 0) {
        Vec3 v;
        v.x = 0;
        v.y = (t - 1) << 12;
        v.z = 0;
        func_020a98f8(eng, &v);
    }
    t = obj->f1d1;
    if (t != 0) {
        func_020a95d4(eng, t - 1, 0x1e);
    }
    t = obj->f1d2;
    if (t != 0) {
        func_020675d8((u8 *) (*(Shared **) (data_0210930c.g68 + 0x38c))->s4 + 0x28, t);
    }
    data_02101b24[slot] = obj;
}
