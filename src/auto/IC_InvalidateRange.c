/* Reconstructed from USA ARM9 at 0x0201c0ac (312 bytes).
 *
 * Picks one of the two entry-table appenders (func_02055b84 and
 * func_02055be8).  The choice depends on bit 0x200 of the global mode word
 * data_027e02a8 and on bit 0x80000000 of the word at arg0+0x8, while the
 * arguments of the appender depend on the packed flag word at arg0+0x10.
 */
#include "m2c.h"

extern s32 data_027e02a8;

extern void func_02055b84(s32, u32, u32, s32); /* extern */
extern void func_02055be8(s32, u32, u32, s32); /* extern */

/* Mode selector: the global mode word and the arg0+0x8 word together pick
 * between 0 and 1. */
#define IC_MODE(v)                                       \
    if (data_027e02a8 & 0x200) {                         \
        (v) = 0;                                         \
    } else if (M2C_FIELD(arg0, s32 *, 8) & 0x80000000) { \
        (v) = 0;                                         \
    } else {                                             \
        (v) = 1;                                         \
    }

/* Bit 13 of the packed flag word at arg0+0x10. */
#define IC_FLAG() (((u32) (M2C_FIELD(arg0, s32 *, 0x10) << 0x12) >> 0x1F) == 1)

/* Nibble at bits 12..15 of the word at arg0+0x14, scaled by 16. */
#define IC_SCALE() (((u32) (M2C_FIELD(arg0, s32 *, 0x14) << 0x10) >> 0x1C) << 0x4)

void IC_InvalidateRange(void *arg0, void *arg1) {
    u32 val = M2C_FIELD(arg1, u16 *, 4);
    s32 mode0, mode1, mode2, mode3, mode4;

    if (val == 0xFFFF) {
        return;
    }
    IC_MODE(mode0);
    if (data_027e02a8 & (4 << mode0)) {
        if (IC_FLAG()) {
            IC_MODE(mode1);
            func_02055b84(val, 0, 0x100, mode1);
        } else {
            IC_MODE(mode2);
            func_02055b84(val, IC_SCALE(), 0x10, mode2);
        }
    } else {
        if (IC_FLAG()) {
            IC_MODE(mode3);
            func_02055be8(val, 0, 0x100, mode3);
        } else {
            IC_MODE(mode4);
            func_02055be8(val, IC_SCALE(), 0x10, mode4);
        }
    }
}
