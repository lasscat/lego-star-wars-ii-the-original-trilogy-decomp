#include "m2c.h"

typedef struct {
    u8 x;
    u8 y;
    u8 cols;
    u8 rows;
} P4;

typedef struct {
    s32 x;
    s32 y;
} Fixed;

typedef struct {
    s32 x;
    s32 y;
} Out;

s32 func_02054158(s32 arg0, s32 arg1);
void func_02054178(void *dst, const void *src);
void func_020541dc(void *a0, s32 a1, s32 a2, s32 a3, P4 p, s16 *hdr, u32 add, u32 add2, u32 add3);
void func_0205427c(void *a0, s32 a1, s32 a2, s32 a3, P4 p, s16 *hdr, u32 add);
void func_0205435c(void *a0, s32 a1, s32 a2, s32 a3, P4 p, s16 *hdr, u32 add, u32 add2);

void func_02054674(Out *out, u8 *a1, s32 a2, s32 a3, s32 a4, P4 p, s16 *hdr, u32 add, u32 add2, u32 add3) {
    Fixed c;
    s32 base;

    base = func_02054158(a2, add3);
    func_02054178(&c, a1);
    if (p.x == 0 && p.y == 0 && p.cols == 0 && p.rows == 0) {
        p.cols = (u8) (c.x >> 12);
        p.rows = (u8) (c.y >> 12);
    }
    if (p.cols > (c.x >> 12) - p.x) {
        p.cols = (u8) ((c.x >> 12) - p.x);
    }
    if (p.rows > (c.y >> 12) - p.y) {
        p.rows = (u8) ((c.y >> 12) - p.y);
    }
    if (a4 == 2) {
        s16 h2[2];
        h2[0] = hdr[0];
        h2[1] = hdr[1];
        func_020541dc(a1 + 4, c.x >> 12, base, a3, p, h2, add, add2, add3);
    } else if (a4 == 1) {
        s16 h1[2];
        h1[0] = hdr[0];
        h1[1] = hdr[1];
        func_0205427c(a1 + 4, c.x >> 12, base, a3, p, h1, add);
    } else {
        s16 h0[2];
        h0[0] = hdr[0];
        h0[1] = hdr[1];
        func_0205435c(a1 + 4, c.x >> 12, base, a3, p, h0, add, add2);
    }
    out->x = p.cols << 12;
    out->y = p.rows << 12;
}
