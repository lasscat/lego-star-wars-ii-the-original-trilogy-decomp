#include "m2c.h"

/* FX_AtanIdxTable_[i] = atan(i / 128) in 16-bit turn units (0x10000 = 360 degrees),
 * 129 entries (i = 0..128), entry 128 is 0x2000 (45 degrees). */
extern u16 FX_AtanIdxTable_[130];
extern s32 FX_Inv(s32 x);

u16 FX_AtanIdx(s32 x) {
    if (x >= 0) {
        if (x > 0x1000) {
            return 0x4000 - (s16) FX_AtanIdxTable_[FX_Inv(x) >> 5];
        } else if (x >= 0x1000) {
            return 0x2000;
        } else {
            return FX_AtanIdxTable_[x >> 5];
        }
    } else {
        if (x < -0x1000) {
            return (s16) FX_AtanIdxTable_[FX_Inv(-x) >> 5] - 0x4000;
        } else if (x <= -0x1000) {
            return 0xe000;
        } else {
            return -(s16) FX_AtanIdxTable_[(-x) >> 5];
        }
    }
}
