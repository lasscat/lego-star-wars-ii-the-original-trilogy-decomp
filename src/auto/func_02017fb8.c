#include "m2c.h"

/* A halfword-sized argument that the callee reads back as a u16. */
typedef struct {
    u16 v;
} HalfWordArg;

/* A word-sized argument (a radius) passed by value. */
typedef struct {
    s32 v;
} WordArg;

extern s32 func_02018010(void *, void *, HalfWordArg);
extern s32 func_0200aef8(void *, void *, WordArg);

/* Checks whether the two objects are close enough: the threshold test comes
 * first, the distance check (done on the positions at +0xb0) afterwards. */
s32 func_02017fb8(void *a0, void *a1, WordArg a2, HalfWordArg a3) {
    if (func_02018010(a0, a1, a3) == 0) {
        return 0;
    }
    return func_0200aef8(a0 + 0xb0, a1 + 0xb0, a2);
}
