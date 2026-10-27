#include "m2c.h"

/* func_02098898 - initialiser for a screen/menu object: sets up its
 * sub-objects (sprite at +0x2A98, part at +0x2ACC, object at +0x2AA0), runs
 * func_02098bd4/func_02099914 on it, clears the per-slot byte arrays at
 * +0x2B10/+0x2B14, builds two text objects via func_0201ad50 and finally
 * flags the four entries of the table at data_0210930c + 0x4C. Field roles
 * beyond that are not proven, so names stay positional. */

enum {
    TEXT_SIZE_VAL  = 0x27000,
    TEXT_A_POS_VAL = 0x10000,
    TEXT_B_POS_VAL = 0xD7000,
    ENT_FLAG_SET   = 0x800000,
    ENT_FLAG_CLEAR = 1,
};

typedef struct {
    u16 v;
} HalfWord;

typedef struct {
    s32 v;
} UnkVal;

typedef struct Obj {
    u8 pad0[0x28];
    s32 f28;
    u8 pad2c[0x2A98 - 0x2C];
    u8 a98[8];
    u8 aa0[0x2C];
    u8 acc[0x36];
    u8 b02;
    u8 pad_b03[3];
    u8 b06;
    s8 b07;
    u8 b08[4];
    u8 b0c[4];
    u8 b10[4];
    u8 b14[4];
    void *b18;
    void *b1c;
} Obj;

extern u8 *func_020aaeb4(void);
extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s32);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206574c(void *, s32, s32);
extern void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern void func_02098bd4(Obj *);
extern void func_02072f30(s32, s32, s32, s32);
extern void func_020a99bc(void *, s32);
extern void *func_02093154(void *, s32);
extern void func_020a0370(void *, void *);
extern void func_02099914(Obj *);
extern void func_0201ad50(void *, s32, void *, UnkVal, UnkVal, u8, s32);

extern u8 data_02101b98[];
extern HalfWord data_020f76bc[];
extern u8 data_020f76c4[];
extern s32 data_027e02a4;
typedef struct Ent {
    u8 pad[8];
    u32 flags;
} Ent;
extern struct {
    u8 pad[0x4C];
    Ent *ents[4];
} data_0210930c;
extern u8 data_02108d90[];

void func_02098898(Obj *self) {
    u8 i;
    UnkVal uv, sz, uv2, sz2;

    func_020aaeb4()[0x25C] = 1;
    func_02053ee8(data_02101b98, 0, 0);
    func_02053f44(data_02101b98, 0x1000);
    func_0206d6cc(self->aa0);
    func_0206d7fc(self->aa0, 1);
    func_020534f4(self->a98, 1, 0, data_020f76bc[0]);
    func_0205365c(self->a98, 0);
    func_02065600(self->acc, 4);
    func_02065658(self->acc, self->a98);
    func_0206574c(self->acc, 3, -1);
    func_0206653c(1, 6, 1, 4, 3, 5, 0);
    func_0206574c(self->acc, 0, -2);
    func_02098bd4(self);
    func_02072f30(data_027e02a4, 0xEE, 4, 0);
    self->f28 = 0;
    self->b07 = 0;
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    func_020a99bc(func_020aaeb4(), 6);
    self->b1c = func_02093154(&data_0210930c, self->b07 + 0x32);
    if (self->b1c != 0) {
        func_020a0370(func_020aaeb4(), self->b1c);
    }
    if (data_027e02a4 == 0) {
        data_027e02a4 = 1;
    } else {
        data_027e02a4 = 0;
    }
    for (i = 0; i < 4; i++) {
        self->b14[i] = 0;
        self->b10[i] = 0;
    }
    func_02099914(self);
    sz.v = TEXT_SIZE_VAL;
    uv.v = TEXT_A_POS_VAL;
    func_0201ad50(self->b08, 1, data_020f76c4, uv, sz, 0, data_027e02a4);
    sz2.v = TEXT_SIZE_VAL;
    uv2.v = TEXT_B_POS_VAL;
    func_0201ad50(self->b0c, 1, &data_020f76bc[1], uv2, sz2, 0, data_027e02a4);
    self->b06 = 0;
    self->b02 = 0;
    self->b18 = *(void **) (data_02108d90 + 0x4C8);
    for (i = 0; i < 4; i++) {
        Ent *e = data_0210930c.ents[i];
        if (e != 0) {
            e->flags |= ENT_FLAG_SET;
            e = data_0210930c.ents[i];
            e->flags &= ~ENT_FLAG_CLEAR;
        }
    }
}
