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

extern void func_020ac278(void *, s32, s32);
extern void func_0200171c(s32);
extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_0209320c(void *);
extern void G3X_SetClearColor(s32, s32, s16, s32, s32);
extern void *func_020aaeb4(void);
extern void func_020a9a24(void *, s8, s32);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_0205365c(void *, s32);
extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, ShortPair *, Quad);
extern void func_02065600(void *, s32);
extern void func_02065658(void *, void *);
extern void func_0206574c(void *, s32, s32);
extern void func_0206653c(s32, s32, s32, s32, s32, s32, s32);
extern void func_02055a18(s32, s32, s32, s32, s32, s32);
extern void func_0205e938(void *, void *, u32, s32);
extern void func_0205ea38(void *, s32);
extern void func_0205ea84(void *, s32);
extern u8 func_02093fd0(s32);
extern s32 func_02068e34(s32, s32, s32, s32, void *, void *, s32);
extern void func_020b90e4(u32, u8);

extern M2C_UNK data_027e0874;
extern M2C_UNK data_02101b78;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02104d50;
extern HalfWord data_020eff08[];
extern u8 data_020effa0[];
extern u8 data_020ef57c[];

enum {
    REG_BG0CNT_ADDR      = 0x4000008, /* BG0 control register; low 2 bits clear = priority 0 */
    BG0CNT_PRIORITY_MASK = 3,
    OFF_OBJ_A            = 0x30,  /* sub-object set up by func_020534f4 */
    OFF_OBJ_B            = 0x38,  /* sub-object set up by func_020534f4, then func_02054c80 */
    OFF_OBJ_C            = 0x40,   /* sub-object set up by func_02065600 */
    OFF_OBJ_D            = 0x70,   /* sub-object set up by func_02065600 */
    OFF_OBJ_E            = 0xa4,    /* sub-object set up by func_0205e938 */
};

/* Screen/scene setup: initialises display state, then builds the sub-objects of arg0 (a screen object). */
void func_0207c514(void *arg0) {
    Vec out;
    ShortPair pair;
    Quad q;
    u32 *ip;

    func_020ac278(&data_027e0874, 3, 0);
    func_0200171c(1);
    func_02053ee8(&data_02101b78, 0, 1);
    func_02053f44(&data_02101b78, 0x1100);
    func_0209320c(&data_0210930c);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    func_020a9a24(func_020aaeb4(), 0, 0);
    func_020a9a24(func_020aaeb4(), 0, 1);
    *(u16 *) REG_BG0CNT_ADDR &= ~BG0CNT_PRIORITY_MASK;
    func_020534f4((u8 *) arg0 + OFF_OBJ_B, 0, 3, data_020eff08[1]);
    func_0205365c((u8 *) arg0 + OFF_OBJ_B, 0);

    pair.a = 0;
    pair.b = 0;
    q.a    = 0;
    q.b    = 0;
    q.c    = 0;
    q.d    = 0;
    func_02054c80(&out, (u8 *) arg0 + OFF_OBJ_B, 0x10e0, 0x100, 1, 0x10, 0, 0x10, &pair, q);

    func_020534f4((u8 *) arg0 + OFF_OBJ_A, 0, 1, data_020eff08[3]);
    func_0205365c((u8 *) arg0 + OFF_OBJ_A, 0);
    func_02065600((u8 *) arg0 + OFF_OBJ_C, 4);
    func_02065658((u8 *) arg0 + OFF_OBJ_C, (u8 *) arg0 + OFF_OBJ_A);
    func_0206574c((u8 *) arg0 + OFF_OBJ_C, 3, -1);
    func_02065600((u8 *) arg0 + OFF_OBJ_D, 3);
    func_02065658((u8 *) arg0 + OFF_OBJ_D, (u8 *) arg0 + OFF_OBJ_A);
    func_0206574c((u8 *) arg0 + OFF_OBJ_D, 3, -1);
    func_0206653c(0, 0, 1, 3, 6, 4, 0);
    func_02055a18(0x8f9, 4, 3, 3, 6, 0xf);
    func_0205e938((u8 *) arg0 + OFF_OBJ_E, data_020effa0, 0xb, 0);
    func_0205ea38((u8 *) arg0 + OFF_OBJ_E, 0);
    func_0205ea84((u8 *) arg0 + OFF_OBJ_E, 1);
    M2C_FIELD(arg0, u32 *, 0x28) = M2C_FIELD(arg0, u32 *, 0x10);
    M2C_FIELD(arg0, u32 *, 0x2c) = func_02093fd0(M2C_FIELD(arg0, u32 *, 0x28));
    ip                           = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0xa4), u32 **, 0x20);
    ip[2] |= 1;
    M2C_FIELD(arg0, u32 *, 0xa0) = 1;
    M2C_FIELD(arg0, u32 *, 0xa0) = func_02068e34(M2C_FIELD(arg0, u32 *, 0xa0), 0x10, 0x10, 0xf, (u8 *) arg0 + OFF_OBJ_A,
                                                 data_020ef57c + M2C_FIELD(&data_02104d50, s32 *, 0xc) * 0x18 + 8, 2);
    func_020b90e4(0x12, 0xff);
}
