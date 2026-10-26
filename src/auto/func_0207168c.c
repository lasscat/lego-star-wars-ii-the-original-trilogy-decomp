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

extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_020536a8(void *, s32);
extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, ShortPair *, Quad);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206574c(void *, s32, s32);
extern void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern void func_02055a18(s32, s32, s32, s32, s32, s32);
extern void func_020719e0(void *);
extern void func_0201ad50(void *, s32, void *, UnkVal, UnkVal, u8, void *);
extern void OS_GetOwnerInfo(void *);
extern void func_0209bd08(s32, s32, void *, s32);

extern M2C_UNK data_02101b98;
extern HalfWord data_020edf84[];
extern HalfWord data_020edf88[];
extern u8 data_02106d90[];

enum {
    SPRITE_A_OFF   = 0x28,
    SPRITE_B_OFF   = 0x30,
    SUBOBJ_OFF     = 0x38,
    UI_PART_OFF    = 0x64,
    TEXT_OFF       = 0x94,
    TEXT_PTR_OFF   = 0x98,
    BUF_SIZE       = 0x1000,
    SPRITE_ID      = 0xed2,
    TEXT_SIZE_VAL  = 0x55000,
    TEXT_POS_VAL   = 0x1e000,
    OWNER_NAME_OFF = 0x4,   /* name inside the OS_GetOwnerInfo record */
    OWNER_LEN_OFF  = 0x18,  /* u16 name length inside that record */
    OWNERS_PTR_OFF = 0xad0, /* pointer in data_02106d90 to the slot records */
};

/* Initialises a screen object: sets up the sprite at +0x30 and the
 * sub-object at +0x38, a second sprite at +0x28 that feeds the UI part at
 * +0x64, two text fields at +0x94 and +0x98 (20.12 fixed point values), then
 * stores the console owner's name into slot 0 of the slot records
 * (func_0209bd08, as in func_02072250). Roles of the fields at +0xa0,
 * +0xb6 and +0xb8 are not established. */
void func_0207168c(void *self) {
    Vec out;
    ShortPair pair;
    Quad q;
    UnkVal uv;
    UnkVal sz;
    UnkVal uv2;
    UnkVal sz2;
    u8 owner[0x50];

    func_02053ee8(&data_02101b98, 0, 0);
    func_02053f44(&data_02101b98, BUF_SIZE);
    func_0206d6cc((u8 *) self + SUBOBJ_OFF);
    func_0206d7fc((u8 *) self + 0x38, 1);
    func_020534f4((u8 *) self + SPRITE_B_OFF, 1, 1, data_020edf84[1]);

    pair.a = 0;
    pair.b = 0;
    q.a    = 0;
    q.b    = 0;
    q.c    = 0;
    q.d    = 0;
    func_02054c80(&out, (u8 *) self + SPRITE_B_OFF, SPRITE_ID, 0x100, 1, 0x20, 0, 0x10, &pair, q);
    func_020536a8((u8 *) self + SPRITE_B_OFF, 0);

    func_020534f4((u8 *) self + SPRITE_A_OFF, 1, 0, data_020edf84[0]);
    func_0205365c((u8 *) self + SPRITE_A_OFF, 0);
    func_02065600((u8 *) self + UI_PART_OFF, 4);
    func_02065658((u8 *) self + UI_PART_OFF, (u8 *) self + SPRITE_A_OFF);
    func_0206574c((u8 *) self + UI_PART_OFF, 3, -1);
    func_0206653c(1, 0, 1, 3, 6, 7, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 15);
    func_0206574c((u8 *) self + UI_PART_OFF, 0, -2);
    func_020719e0(self);

    sz.v = 0x4000;
    uv.v = 0xee000;
    func_0201ad50((u8 *) self + TEXT_OFF, 0, &data_020edf88[3], uv, sz, 0, (void *) 1);
    sz2.v = TEXT_SIZE_VAL;
    uv2.v = TEXT_POS_VAL;
    func_0201ad50((u8 *) self + TEXT_PTR_OFF, 1, &data_020edf88[0], uv2, sz2, 0, (void *) 1);

    M2C_FIELD(self, s32 *, 0xa0) = 0;
    M2C_FIELD(self, u8 *, 0xb6)  = M2C_FIELD(self, s32 *, 0x10);
    M2C_FIELD(self, s32 *, 0xb8) = 1;
    OS_GetOwnerInfo(owner);
    func_0209bd08(*(s32 *) (data_02106d90 + OWNERS_PTR_OFF), 0, owner + OWNER_NAME_OFF,
                  (u8) * (u16 *) (owner + OWNER_LEN_OFF));
}
