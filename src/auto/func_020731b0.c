#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;
typedef struct {
    s16 a;
    s16 b;
} ShortPair;
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Quad;
typedef struct {
    s32 x;
    s32 y;
} Vec;
typedef struct {
    s32 v;
} UnkVal;

extern void func_020559f0(void);
extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, ShortPair *, Quad);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_020733b4(void *);
extern void func_02072f30(s32, s32, s32, s32);
extern void func_0201ad50(void *, void *, void *, UnkVal, UnkVal, u8, void *);

extern M2C_UNK data_02101b98;
extern HalfWord data_020ee018;
extern s32 data_027e02a4;

enum {
    FLAG_BYTE_A_OFF = 0xe0b0,
    FLAG_BYTE_B_OFF = 0xe0b1,
    SPRITE_OFF      = 0x30,
    SUBOBJ_OFF      = 0x38,
    TEXT_OFF        = 0x94,
    TEXT_PTR_OFF    = 0x98,
    SPRITE_ID       = 0xed2,
    BUF_SIZE        = 0x1000,
    SOUND_ID        = 0xee,
    TEXT_SIZE_VAL   = 0x55000,
    TEXT_POS_VAL    = 0x1e000,
};

/* Initialises a screen object: clears two flag bytes, sets up the sprite
 * at +0x30, the sub-object at +0x38 and the text field at +0x94
 * (positions/sizes are 20.12 fixed point). */
void func_020731b0(void *self) {
    Vec out;
    ShortPair pair;
    Quad q;
    UnkVal uv;
    UnkVal sz;

    func_020559f0();
    M2C_FIELD(self, u8 *, FLAG_BYTE_A_OFF) = 0;
    M2C_FIELD(self, u8 *, FLAG_BYTE_B_OFF) = 0;
    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, BUF_SIZE);
    func_020534f4((u8 *) self + SPRITE_OFF, 1, 1, data_020ee018);

    pair.a = 0;
    pair.b = 0;
    q.a    = 0;
    q.b    = 0;
    q.c    = 0;
    q.d    = 0;
    func_02054c80(&out, (u8 *) self + SPRITE_OFF, SPRITE_ID, 0, 1, 0, 0, 0x10, &pair, q);

    func_0206d6cc((u8 *) self + SUBOBJ_OFF);
    func_0206d7fc((u8 *) self + SUBOBJ_OFF, 1);
    func_020733b4(self);
    func_02072f30(data_027e02a4, SOUND_ID, 4, 0);

    M2C_FIELD(self, s32 *, TEXT_PTR_OFF) = 0;
    sz.v                                 = TEXT_SIZE_VAL;
    uv.v                                 = TEXT_POS_VAL;
    func_0201ad50((u8 *) self + TEXT_OFF, (void *) 2, &data_020ee018 + 1, uv, sz, 0, (void *) 1);
}
