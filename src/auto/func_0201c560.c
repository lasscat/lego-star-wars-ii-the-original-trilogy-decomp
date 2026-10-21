#include "m2c.h"

/* Distance check: the point (a2, a3) against the position held in a1
   (fields 0x4c / 0x50) and the limit held in a0 (field 8). */
s32 func_0201c560(s32 a0, s32 a1, s32 a2, s32 a3, ...) {
    s32 dx;
    s32 dy;
    s32 sx;
    s32 sy;
    dx = *(s32 *) &a2 - M2C_FIELD(a1, s32 *, 0x4c);
    dy = *(s32 *) &a3 - M2C_FIELD(a1, s32 *, 0x50);
    sx = (s32) (((s64) dx * dx + 0x800) >> 12);
    sy = (s32) (((s64) dy * dy + 0x800) >> 12);
    return sx + sy <= M2C_FIELD(a0, s32 *, 8) ? 1 : 0;
}
