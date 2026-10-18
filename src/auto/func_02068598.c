/* Reconstructed from USA ARM9 at 0x02068598 (488 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0205d0d0(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
s32 func_0205d0f8(M2C_UNK *, M2C_UNK);              /* extern */
s32 func_0205eacc(s32, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_02060158(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_02068780(void *);                          /* extern */
M2C_UNK func_020687b4(void *, s32);                 /* extern */
M2C_UNK func_02068d74(void *);                      /* extern */
s32 func_020691b4(void *, M2C_UNK);                 /* extern */
M2C_UNK func_02087044(M2C_UNK *);                   /* extern */
M2C_UNK func_020b8f70(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;

void func_02068598(void *arg0) {
    s32 temp_r0;
    s32 temp_r1;
    s32 temp_r1_2;
    s32 temp_r1_3;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r1;
    s32 var_r1_2;

    temp_r0 = func_0205eacc(arg0 + 0xC, 0xA, 0x20, 0x20);
    if (temp_r0 != -1) {
        if (temp_r0 >= 2) {
            func_020687b4(arg0, temp_r0 - 2);
            M2C_FIELD(arg0, s8 *, 0x36) = (s8) (temp_r0 - 2);
        } else {
            temp_r1 = M2C_FIELD(arg0, s32 *, 0x20);
            if (temp_r0 == 0) {
                var_r1 = temp_r1 - 1;
                {
                    s32 n;
                    n = M2C_FIELD(arg0, s32 *, 0x28);
                    if (var_r1 < (s32) M2C_FIELD(arg0, s32 *, 0x24)) {
                        var_r1 = n - 1;
                    }
                }
                M2C_FIELD(arg0, s32 *, 0x20) = var_r1;
            } else {
                temp_r1_2 = temp_r1 + 1;
                var_r0    = M2C_FIELD(arg0, s32 *, 0x24);
                if (temp_r1_2 != M2C_FIELD(arg0, s32 *, 0x28)) {
                    var_r0 = temp_r1_2;
                }
                M2C_FIELD(arg0, s32 *, 0x20) = var_r0;
            }
            func_020b8f70(0xB6, 0);
            M2C_FIELD(&data_02104d90, s8 *, 0x51) = (s8) M2C_FIELD(arg0, s32 *, 0x20);
            func_02068d74(arg0);
        }
    }
    if (func_0205d0d0(&data_021027f8, 0x200, 4) != 0) {
        var_r1_2 = M2C_FIELD(arg0, s32 *, 0x20) - 1;
        {
            s32 n;
            n = M2C_FIELD(arg0, s32 *, 0x28);
            if (var_r1_2 < (s32) M2C_FIELD(arg0, s32 *, 0x24)) {
                var_r1_2 = n - 1;
            }
        }
        M2C_FIELD(arg0, s32 *, 0x20) = var_r1_2;
        func_020b8f70(0xB6, 0);
        M2C_FIELD(&data_02104d90, s8 *, 0x51) = (s8) M2C_FIELD(arg0, s32 *, 0x20);
        func_02068d74(arg0);
    }
    if (func_0205d0d0(&data_021027f8, 0x100, 4) != 0) {
        temp_r1_3 = M2C_FIELD(arg0, s32 *, 0x20) + 1;
        var_r0_2  = M2C_FIELD(arg0, s32 *, 0x24);
        if (temp_r1_3 != M2C_FIELD(arg0, s32 *, 0x28)) {
            var_r0_2 = temp_r1_3;
        }
        M2C_FIELD(arg0, s32 *, 0x20) = var_r0_2;
        func_020b8f70(0xB6, 0);
        M2C_FIELD(&data_02104d90, s8 *, 0x51) = (s8) M2C_FIELD(arg0, s32 *, 0x20);
        func_02068d74(arg0);
    }
    if ((func_02068780(arg0) == 0) && (M2C_FIELD(arg0, u8 *, 0x35) == 0)) {
        if ((func_0205d0f8(&data_021027f8, 2) != 0) && (M2C_FIELD(&data_02104d90, s32 *, 0) & 1)) {
            func_02060158(&data_02102900, 1, 0xB, 0);
            func_02087044(&data_02104d90);
            return;
        }
        goto block_26;
    }
block_26:
    if (M2C_FIELD(arg0, u8 *, 0x35) == 0) {
        return;
    }
    if (func_020691b4(arg0, 0) == 0) {
        return;
    }
    func_02068d74(arg0);
}
