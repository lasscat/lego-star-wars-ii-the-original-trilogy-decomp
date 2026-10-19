#include "m2c.h"

s32 func_0205e540(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_0205e5b0(s32);                         /* extern */
M2C_UNK func_0205e6e0(s32, s32, s32);               /* extern */
M2C_UNK GX_BeginLoadBGExtPltt();                            /* extern */
M2C_UNK GX_LoadBGExtPltt(s32, s32, s32);               /* extern */
M2C_UNK GX_EndLoadBGExtPltt();                            /* extern */
M2C_UNK GX_BeginLoadOBJExtPltt();                            /* extern */
M2C_UNK GX_LoadOBJExtPltt(s32, s32, s32);               /* extern */
M2C_UNK GX_EndLoadOBJExtPltt();                            /* extern */
M2C_UNK GXS_BeginLoadBGExtPltt();                            /* extern */
M2C_UNK GXS_LoadBGExtPltt(s32, s32, s32);               /* extern */
M2C_UNK GXS_EndLoadBGExtPltt();                            /* extern */
M2C_UNK GXS_BeginLoadOBJExtPltt();                            /* extern */
M2C_UNK GXS_LoadOBJExtPltt(s32, s32, s32);               /* extern */
M2C_UNK GXS_EndLoadOBJExtPltt();                            /* extern */
M2C_UNK DC_FlushRange(s32, s32);                    /* extern */

void func_02055d58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 var_r5;
    s32 var_r9;

    var_r9 = arg0;
    var_r5 = 0;
    if (var_r9 & 3) {
        temp_r4 = arg3 * 2;
        temp_r0 = func_0205e540(temp_r4, 3, 4);
        var_r5  = temp_r0;
        func_0205e6e0(temp_r0, var_r9, temp_r4);
        var_r9 = var_r5;
    }
    temp_r4_2 = arg3 * 2;
    DC_FlushRange(var_r9, temp_r4_2);
    if (arg5 == 0) {
        if (arg4 == 0) {
            GX_BeginLoadBGExtPltt();
            GX_LoadBGExtPltt(var_r9, (arg2 + (arg1 << 0xC)) * 2, temp_r4_2);
            GX_EndLoadBGExtPltt();
        } else if (arg4 == 1) {
            GX_BeginLoadOBJExtPltt();
            GX_LoadOBJExtPltt(var_r9, (arg2 + (arg1 << 0xC)) * 2, temp_r4_2);
            GX_EndLoadOBJExtPltt();
        }
    } else if (arg4 == 0) {
        GXS_BeginLoadBGExtPltt();
        GXS_LoadBGExtPltt(var_r9, (arg2 + (arg1 << 0xC)) * 2, temp_r4_2);
        GXS_EndLoadBGExtPltt();
    } else if (arg4 == 1) {
        GXS_BeginLoadOBJExtPltt();
        GXS_LoadOBJExtPltt(var_r9, (arg2 + (arg1 << 0xC)) * 2, temp_r4_2);
        GXS_EndLoadOBJExtPltt();
    }
    if (var_r5 == 0) {
        return;
    }
    func_0205e5b0(var_r5);
}
