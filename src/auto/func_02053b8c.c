/* Reconstructed from USA ARM9 at 0x02053b8c (160 bytes).
 *
 * Writes one 16 bit palette entry into the frame buffer. The position is
 * computed from the object data (func_02053b14 gives the VRAM base,
 * func_02053ce4 the pixel size) and the two coordinates; when the object is
 * in the "packed" mode the coordinates are halved and only one byte of the
 * destination half word is replaced.
 */
#include "m2c.h"

s32 func_020539c8(s32 *);
s32 func_02053b14(s32 *);
s32 func_02053ce4(M2C_UNK);

void func_02053b8c(s32 *arg0, s32 arg1, s32 arg2, u16 arg3) {
    s32 base;
    s32 size;
    s32 x;
    s32 y;
    u16 *p;

    if (func_020539c8(arg0) != 0) {
        base = func_02053b14(arg0);
        size = func_02053ce4(arg0);
        x    = (arg2 * size) / 2;
        y    = arg1 / 2;
        p    = (u16 *) (base + 2 * x + 2 * y);
        if (arg1 & 1) {
            *p = (*p & 0xff) | (arg3 << 8);
        } else {
            *p = (*p & 0xff00) | arg3;
        }
    } else {
        base = func_02053b14(arg0);
        size = func_02053ce4(arg0);
        p    = (u16 *) base + (arg2 * size);
        p += arg1;
        *p = arg3;
    }
}
