#include "m2c.h"

s32 func_020bba5c(s32); /* extern */

/* Build three signed vector components from per-axis settings. When an axis
 * flag is set, its component is scale * byte - stored offset; otherwise it
 * is a bounded random value in [-stored offset, stored offset). The source
 * fields provide no evidence for a physical unit, so these remain raw values.
 */
void func_020bda0c(void *outVector, void *axisSettings) {
    s32 zRange;
    s32 xRange;
    s32 yRange;
    s32 xComponent;
    s32 yComponent;

    M2C_FIELD(outVector, s32 *, 0) = 0;
    M2C_FIELD(outVector, s32 *, 4) = 0;
    M2C_FIELD(outVector, s32 *, 8) = 0;
    if (M2C_FIELD(axisSettings, u8 *, 0x4C) != 0) {
        xComponent = (M2C_FIELD(axisSettings, u8 *, 0x4D) * M2C_FIELD(axisSettings, s32 *, 0x48)) -
                     M2C_FIELD(axisSettings, s32 *, 0x68);
    } else {
        xRange     = M2C_FIELD(axisSettings, s32 *, 0x68);
        xComponent = func_020bba5c(xRange * 2) - xRange;
    }
    M2C_FIELD(outVector, s32 *, 0) = xComponent;
    if (M2C_FIELD(axisSettings, u8 *, 0x54) != 0) {
        yComponent = (M2C_FIELD(axisSettings, u8 *, 0x55) * M2C_FIELD(axisSettings, s32 *, 0x50)) -
                     M2C_FIELD(axisSettings, s32 *, 0x6C);
    } else {
        yRange     = M2C_FIELD(axisSettings, s32 *, 0x6C);
        yComponent = func_020bba5c(yRange * 2) - yRange;
    }
    M2C_FIELD(outVector, s32 *, 4) = yComponent;
    if (M2C_FIELD(axisSettings, u8 *, 0x5C) != 0) {
        M2C_FIELD(outVector, s32 *, 8) = (s32) ((M2C_FIELD(axisSettings, u8 *, 0x5D) * M2C_FIELD(axisSettings, s32 *, 0x58)) -
                                                M2C_FIELD(axisSettings, s32 *, 0x70));
        return;
    }
    zRange                         = M2C_FIELD(axisSettings, s32 *, 0x70);
    M2C_FIELD(outVector, s32 *, 8) = (s32) (func_020bba5c(zRange * 2) - zRange);
}
