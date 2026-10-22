#include "m2c.h"

/* func_02087bf4 (0x02087bf4, 0xf0 bytes)
 *
 * Per frame update of the object: it flushes a pending "rebuild" request,
 * checks the zoom ratio against the current camera distance and drops the
 * "dirty" flag of the sub object at +0xd4 when the ratio gets too small.
 * Finally the cached value at +0xdc is refreshed and the object is updated.
 *
 * The original code keeps two copies of the Q12 constant 100.0 in the
 * outgoing argument slots of the frame; the address taken locals below
 * reproduce those two stores.  The scale factor is read through a volatile
 * access because the original code loads it before the call to
 * func_0208559c() and keeps it in a callee saved register across the call.
 */

s32 func_0208559c(void *);                    /* extern */
s32 FX_Div(s32, s32);                         /* extern */
void func_02087ce4(void *, s32, s32, s32);    /* extern */
void func_02087e14(void *);                   /* extern */
extern M2C_UNK data_02104d94;

void func_02087bf4(void *p) {
    s32 scale;
    s32 scale2;
    s32 v;
    s32 w;

    if (M2C_FIELD(p, u8 *, 0xca) != 0) {
        return;
    }
    if (M2C_FIELD(p, u8 *, 0xcc) != 0) {
        M2C_FIELD(p, u8 *, 0xcc) = 0;
        func_02087ce4(p, 5, 1, 0);
    }
    if ((M2C_FIELD(M2C_FIELD(p, void **, 0xd4), u32 *, 8) & 1) == 1) {
        s32 den                      = M2C_FIELD(p, volatile s32 *, 0xe0) << 12;
        s32 q                        = FX_Div(func_0208559c(&data_02104d94) << 12, den);
        M2C_FIELD(&scale, s32 *, 0)  = 100 << 12;
        M2C_FIELD(&scale2, s32 *, 0) = 100 << 12;
        v                            = ((s32) (((((s64) q * scale) + 0x800) >> 12))) >> 12;
        if (v < 100) {
            M2C_FIELD(M2C_FIELD(p, void **, 0xd4), u32 *, 8) &= ~1;
        }
    }
    if ((M2C_FIELD(M2C_FIELD(p, void **, 0xd4), u32 *, 8) & 1) == 1) {
        return;
    }
    w = func_0208559c(&data_02104d94);
    if (w == M2C_FIELD(p, s32 *, 0xdc)) {
        return;
    }
    M2C_FIELD(p, s32 *, 0xdc) = w;
    func_02087e14(p);
}
