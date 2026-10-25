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

extern void func_02053ee8(void *, s32, s32);
extern void func_02053f44(void *, s32);
extern void func_020534e0(void *);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, ShortPair *, Quad);

extern M2C_UNK data_02101b78;
extern HalfWord data_020edec0;

void func_0206e7b4(void) {
    Vec obj;
    Vec out;
    ShortPair pair;
    Quad q;

    func_02053ee8(&data_02101b78, 0, 0);
    func_02053f44(&data_02101b78, 0x1000);
    func_020534e0(&obj);
    func_020534f4(&obj, 0, 1, data_020edec0);
    pair.a = 0;
    pair.b = 0;
    q.a    = 0;
    q.b    = 0;
    q.c    = 0;
    q.d    = 0;
    func_02054c80(&out, &obj, 0x1398, 0, 0, 0, 0, 0x10, &pair, q);
}
