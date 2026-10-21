/* Reconstructed from USA ARM9 at 0x0208c360 (360 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern void func_0208c588(s32, s32, M2C_UNK, s32);      /* extern */
extern void func_0206574c(void *, s32, s32);              /* extern */
extern M2C_UNK *func_02066708(M2C_UNK);                  /* extern */
extern s32 func_02065980(M2C_UNK, s32, M2C_UNK);         /* extern */
extern s32 func_02065a78(void *, s32, M2C_UNK, s32, s32, u8 *, s32); /* extern */
extern u8 data_021027f8[];                               /* extern */
extern u8 *data_02109358[];                              /* extern */

s32 func_0208c360(s32 *arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    u8 *var_r4;
    u8 *var_r8;
    s32 var_r0;
    s32 var_r4_2;
    s32 var_r6;

    func_0208c588(arg0, arg1, arg2, arg3);
    func_0206574c(arg3, 3, 3 - 5);
    if (arg6 < 0x535) {
        var_r4 = (u8 *) func_02066708(arg6);
        var_r0 = func_02065980(arg3, (s32) var_r4, 0xF0);
        var_r6 = 0;
        if (var_r0 > 2) {
            var_r6 = -12;
        }
        arg4 = func_02065a78(arg3, arg4, M2C_FIELD(arg0 + arg1, u8 *, 0xE), M2C_FIELD(arg0 + arg1, u8 *, 0xF) + var_r6, 0xF0,
                             var_r4, arg5);
    }
    if (arg7 < 0x535) {
        var_r4 = (u8 *) func_02066708(arg7);
        var_r0 = func_02065980(arg3, (s32) var_r4, 0xF0);
        var_r6 = 0;
        if (var_r0 > 1) {
            var_r6 = -12;
        }
        arg4 = func_02065a78(arg3, arg4, M2C_FIELD(arg0 + arg1, u8 *, 0xE), M2C_FIELD(arg0 + arg1, u8 *, 0xF) + 0x14 + var_r6,
                             0xF0, var_r4, arg5);
    }
    M2C_FIELD(arg0 + arg1, u8 *, 0xC) = 1;
    if (arg1 == 0) {
        M2C_FIELD(arg0 + arg1, u8 *, 0xD) = 0xA;
        var_r8                            = (u8 *) data_02109358[data_021027f8[0x2A]] + 0xB0;
        if ((u8 *) arg0 != var_r8) {
            arg0[0] = ((s32 *) var_r8)[0];
            arg0[1] = ((s32 *) var_r8)[1];
            arg0[2] = ((s32 *) var_r8)[2];
        }
    }
    return arg4;
}
