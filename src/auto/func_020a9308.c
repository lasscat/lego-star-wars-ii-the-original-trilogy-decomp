#include "m2c.h"

void func_020a9308(s32 *self, s32 *v1, s32 *v2, s32 *o1, s32 *o2) {
    s32 mode = *(u8 *) ((s8 *) self + 0x30c);
    switch (mode) {
        case 3: {
            if (o1 != v1) {
                o1[0] = v1[0];
                o1[1] = v1[1];
                o1[2] = v1[2];
            }
            if (o2 != v2) {
                o2[0] = v2[0];
                o2[1] = v2[1];
                o2[2] = v2[2];
            }
            break;
        }
        case 1: {
            s32 t[3];
            s32 p = v1[0];
            s32 q = v1[1];
            s32 r = v1[2];
            s32 c = r + self[0xC6];
            s32 b = q + self[0xC5];
            s32 a = p + self[0xC4];
            t[0]  = a;
            t[1]  = b;
            t[2]  = c;
            if (o1 != t) {
                o1[0] = t[0];
                o1[1] = t[1];
                o1[2] = t[2];
            }
            if (o2 != v2) {
                o2[0] = v2[0];
                o2[1] = v2[1];
                o2[2] = v2[2];
            }
            break;
        }
        case 2: {
            s32 t[3];
            s32 u[3];
            s32 c = v1[2] + self[0xC6];
            s32 b = v1[1] + self[0xC5];
            s32 a = v1[0] + self[0xC4];
            s32 u0, u1, u2;
            t[0] = a;
            t[1] = b;
            t[2] = c;
            if (o1 != t) {
                o1[0] = t[0];
                o1[1] = t[1];
                o1[2] = t[2];
            }
            u2   = v2[2] + self[0xC6];
            u1   = v2[1] + self[0xC5];
            u0   = v2[0] + self[0xC4];
            u[0] = u0;
            u[1] = u1;
            u[2] = u2;
            if (o2 != u) {
                o2[0] = u0;
                o2[1] = u1;
                o2[2] = u2;
            }
            break;
        }
    }
}
