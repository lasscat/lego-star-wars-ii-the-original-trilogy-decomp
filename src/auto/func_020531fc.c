#include "m2c.h"

extern const s16 data_020f88c4[];

typedef struct UnkTransform {
    s32 unk_00;
    volatile s32 flags;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 scale;
    u16 angle;
    s16 off_x;
    s16 off_y;
    s16 m00;
    s16 m01;
    s16 m10;
    s16 m11;
    s32 out_x;
    s32 out_y;
    s32 flags2;
} UnkTransform;

void func_020531fc(UnkTransform *t) {
    if (t->flags & 2) {
        t->flags = t->flags & ~2;
        t->flags2 |= 1;
    }
    if (t->flags & 4) {
        t->x += t->dx;
        t->y += t->dy;
        t->flags2 |= 1;
    }
    if (t->flags & 1) {
        u16 ang  = t->angle;
        s16 sinv = data_020f88c4[(ang >> 4) * 2];
        s16 cosv = data_020f88c4[(ang >> 4) * 2 + 1];
        volatile s16 tmp;

        t->m00   = (s16) ((s32) ((((s64) cosv * t->scale) + 0x800) >> 12) >> 4);
        t->m01   = (s16) ((s32) ((((s64) sinv * t->scale) + 0x800) >> 12) >> 4);
        tmp      = ang;
        t->m10   = (s16) ((s32) ((((s64) -sinv * t->scale) + 0x800) >> 12) >> 4);
        t->m11   = (s16) ((s32) ((((s64) cosv * t->scale) + 0x800) >> 12) >> 4);
        t->out_x = t->m00 * (t->x >> 12) + (t->off_x << 8) + t->m01 * (t->y >> 12);
        t->out_y = t->m10 * (t->x >> (0 + 12)) + (t->off_y << 8) + t->m11 * (t->y >> 12);
        t->flags2 |= 2;
        t->flags = t->flags & ~1;
    }
}
