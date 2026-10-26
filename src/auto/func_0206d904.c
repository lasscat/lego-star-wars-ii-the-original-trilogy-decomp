#include "m2c.h"

typedef struct {
    u16 v;
} HalfWord;
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Quad;
typedef struct {
    s16 a;
    s16 b;
} ShortPair;
typedef struct {
    s32 x;
    s32 y;
} Vec;

typedef struct {
    s32 pad0;
    s32 state;
} Node; /* name guessed from callers */

typedef struct {
    s32 pad0;
    Node *node;
    u8 pad8[0x60];
    s32 mode;
} Globals;

extern void func_020ac278(void *, s32, s32);
extern void func_02053f80(void *);
extern void func_02053ee8(void *, s32, s32);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_020534e0(void *);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(s32 *, s32);
extern void func_020536ec(void *, void *);
extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, ShortPair *, Quad);

extern Globals data_02102900;
extern M2C_UNK data_027e0874;
extern s32 data_027e02a4;
extern u8 data_02101b78[];
extern HalfWord data_020edebc;

enum {
    STATE_B      = 0xB,
    STATE_C      = 0xC,
    SPRITE_ID    = 0x1399,
    SPRITE_SIZE  = 0x20,
    SPRITE_FLAGS = 0xE0,
    SLOT_STRIDE  = 0x20,
    POS_Y        = -0x20000,
};

/* Resets the slot's table entry and, if arg0 has a sprite object, places it at the slot's 2D position. */
void func_0206d904(void *arg0) {
    Vec obj;
    Vec pos;
    Vec out;
    ShortPair pair;
    Quad q;

    if ((data_02102900.node != NULL ? data_02102900.node->state : 0) == STATE_C ||
        (data_02102900.node != NULL ? data_02102900.node->state : 0) == STATE_B || (u32) (data_02102900.mode - STATE_B) <= 1) {
        func_020ac278(&data_027e0874, 4, 0);
    }
    func_02053f80(data_02101b78 + data_027e02a4 * SLOT_STRIDE);
    func_02053ee8(data_02101b78 + data_027e02a4 * SLOT_STRIDE, 0, 0);
    func_0206d6cc(arg0 + 0x28);
    func_0206d7fc(arg0 + 0x28, 1);
    if (M2C_FIELD(arg0, s32 *, 8) == 0) {
        return;
    }
    func_020534e0(&obj);
    func_020534f4(&obj, data_027e02a4, 1, data_020edebc);
    func_0205365c((s32 *) &obj, 0);
    pos.x = 0;
    pos.y = POS_Y;
    func_020536ec(&obj, &pos);
    pair.a = 0;
    pair.b = 0;
    q.a    = 0;
    q.b    = 0;
    q.c    = 0;
    q.d    = 0;
    func_02054c80(&out, &obj, SPRITE_ID, 0, 1, SPRITE_SIZE, SPRITE_SIZE, SPRITE_FLAGS, &pair, q);
}
