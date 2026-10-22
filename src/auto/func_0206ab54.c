/* Reconstructed from USA ARM9 at 0x0206ab54 (304 bytes).
 *
 * Sets up the text/label table entry held at self+0x48: it re-initialises the
 * font index pair at self+0x38, resets the object reached through the pointer
 * at self+0x8c, installs the halfword taken from data_020ede9c into the table
 * entry and then loads a 2D placement (0x1399, 1, 0x20, 0x20, 0xe0) into it.
 *
 * The last argument of func_02054c80 is a four byte structure passed by
 * value, so it travels in the outgoing argument area and is copied byte by
 * byte; the argument before it is a pointer to a two halfword structure.
 */
#include "m2c.h"

/* One halfword structure passed by value (see src/auto/func_020534f4.c). */
typedef struct {
    u16 v;
} HalfWord;

/* The global holds two halfwords; the second one is the table index. */
typedef struct {
    u16 a;
    HalfWord b;
} HwPair;

/* Two 32 bit values, used for the fixed point placement of the table entry. */
typedef struct {
    s32 x;
    s32 y;
} Vec;

/* Four bytes passed by value as the last argument of func_02054c80. */
typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Quad;

/* Two halfwords, handed over as a pointer to func_02054c80. */
typedef struct {
    s16 a;
    s16 b;
} ShortPair;

extern void func_0205365c(s32 *, s32);
extern void func_0206d6cc(void *);
extern void func_0206d7fc(void *, s8);
extern void func_020534f4(void *, s32, s32, HalfWord);
extern void func_020536a8(void *, s32);
extern void func_02054c80(void *, void *, s32, s32, s32, s32, s32, s32, ShortPair *, Quad);
extern void func_02053888(s32 *, u32);
extern void func_020536ec(void *, void *);
extern void func_02053808(void *, void *);
extern void func_02063a90(s32, s32);
extern HwPair data_020ede9c;

void func_0206ab54(void *arg0) {
    Vec out;
    ShortPair pair;
    Quad q;
    Vec pos;
    Vec size;

    func_0205365c((s32 *) (arg0 + 0x38), 0);
    func_0206d6cc(*(void **) ((s8 *) arg0 + 0x8c));
    func_0206d7fc(*(void **) ((s8 *) arg0 + 0x8c), 1);
    func_020534f4(arg0 + 0x48, 1, 3, data_020ede9c.b);
    func_020536a8(arg0 + 0x48, 0);
    func_0205365c((s32 *) (arg0 + 0x48), 0);
    pair.a = 0;
    pair.b = 0;
    q.a    = 0;
    q.b    = 0;
    q.c    = 0;
    q.d    = 0;
    func_02054c80(&out, arg0 + 0x48, 0x1399, 0, 1, 0x20, 0x20, 0xe0, &pair, q);
    func_02053888((s32 *) (arg0 + 0x48), M2C_FIELD(arg0, u32 *, 0x30));
    pos.x = -0x80000;
    pos.y = -0x40000;
    func_020536ec(arg0 + 0x48, &pos);
    size.x = 0x80000;
    size.y = 0x40000;
    func_02053808(arg0 + 0x48, &size);
    *(u8 *) (arg0 + 0x81) = 0;
    func_02063a90(1, 0);
}
