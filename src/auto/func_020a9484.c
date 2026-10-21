#include "m2c.h"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} M2C_V;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    M2C_V v;
} M2C_S;

void func_020a9484(M2C_UNK *a0, M2C_V *a1, u16 a2, u16 a3, u16 a4, M2C_V *a5, u16 *a6, u16 *a7, u16 *a8, ...) {
    M2C_S s;
    u8 type;

    type = *(u8 *) ((u8 *) a0 + 0x30c);

    switch (type) {
        case 3:
            if (a5 != a1) {
                a5->x = a1->x;
                a5->y = a1->y;
                a5->z = a1->z;
            }
            *a6 = *(u16 *) &a2;
            *a7 = *(u16 *) &a3;
            *a8 = *(u16 *) &a4;
            break;
        case 1:
            s.v.z = a1->z + *(u32 *) ((u8 *) a0 + 0x318);
            s.v.y = a1->y + *(u32 *) ((u8 *) a0 + 0x314);
            s.v.x = a1->x + *(u32 *) ((u8 *) a0 + 0x310);
            if (a5 != &s.v) {
                a5->x = s.v.x;
                a5->y = s.v.y;
                a5->z = s.v.z;
            }
            *a6 = *(u16 *) &a2;
            *a7 = *(u16 *) &a3;
            s.c = *(u16 *) ((u8 *) a0 + 0x31c) + 0x8000;
            s.b = *(u16 *) ((u8 *) a0 + 0x31c);
            s.a = s.c;
            *a8 = s.a;
            break;
        case 2:
            if (a5 != a1) {
                a5->x = a1->x;
                a5->y = a1->y;
                a5->z = a1->z;
            }
            *a6 = *(u16 *) &a2;
            *a7 = *(u16 *) &a3;
            *a8 = *(u16 *) &a4;
            break;
    }
}
