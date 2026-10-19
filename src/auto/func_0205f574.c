/* Reconstructed from USA ARM9 at 0x0205f574 (2276 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

void *func_0205e80c(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_02067bc0(void *, M2C_UNK *);                      /* extern */
void *func_02067d3c(void *, u32, s32, s32, s32);    /* extern */
void *func_02069db8(void *, u32, s32, s32, s32);    /* extern */
void *func_0206d13c(void *, u32, s32, s32, s32);    /* extern */
void *func_0206d88c(void *, u32, s32, s32, s32);    /* extern */
void *func_0206e8c0(void *, u32, s32, s32, s32);    /* extern */
void *func_0206ecbc(void *, u32, s32, s32, s32);    /* extern */
void *func_0206f354(void *, u32, s32, s32, s32);    /* extern */
void *func_0206fd30(void *, u32, s32, s32, s32);    /* extern */
void *func_02070a38(void *, u32, s32, s32, s32);    /* extern */
void *func_02070dfc(void *, u32, s32, s32, s32);    /* extern */
void *func_020714bc(void *, u32, s32, s32, s32);    /* extern */
void *func_02072560(void *, u32, s32, s32, s32);    /* extern */
void *func_020730e0(void *, u32, s32, s32, s32);    /* extern */
void *func_02073a00(void *, u32, s32, s32, s32);    /* extern */
void *func_02074a3c(void *, u32, s32, s32, s32);    /* extern */
void *func_02076008(void *, u32, s32, s32, s32);    /* extern */
void *func_02076d2c(void *, u32, s32, s32, s32);    /* extern */
void *func_0207b71c(void *, u32, s32, s32, s32);    /* extern */
void *func_0207c49c(void *, u32, s32, s32, s32);    /* extern */
void *func_0207d168(void *, u32, s32, s32, s32);    /* extern */
void *func_0207fcd4(void *, u32, s32, s32, s32);    /* extern */
void *func_020801d8(void *, u32, s32, s32, s32);    /* extern */
void *func_02083d08(void *, u32, s32, s32, s32);    /* extern */
void *func_020872b4(void *, u32, s32, s32, s32);    /* extern */
M2C_UNK func_0208a938(void *, M2C_UNK *);                      /* extern */
void *func_0208e260(void *, u32, s32, s32, s32);    /* extern */
void *func_02098790(void *, u32, s32, s32, s32);    /* extern */
void *func_02099db4(void *, u32, s32, s32, s32);    /* extern */
void *func_0209bd78(void *, u32, s32, s32, s32);    /* extern */
void *func_0209c720(void *, u32, s32, s32, s32);    /* extern */
void *func_0209d948(void *, u32, s32, s32, s32);    /* extern */
void *func_0209ee58(void *, u32, s32, s32, s32);    /* extern */
extern M2C_UNK data_020fe6d0;
extern M2C_UNK data_020fe6f0;
extern M2C_UNK data_020fe908;
extern M2C_UNK data_020fe960;
extern M2C_UNK data_020ff478;

void *func_0205f574(void *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r4;
    void *temp_r0;
    void *temp_r0_10;
    void *temp_r0_11;
    void *temp_r0_12;
    void *temp_r0_13;
    void *temp_r0_14;
    void *temp_r0_15;
    void *temp_r0_16;
    void *temp_r0_17;
    void *temp_r0_18;
    void *temp_r0_19;
    void *temp_r0_20;
    void *temp_r0_21;
    void *temp_r0_22;
    void *temp_r0_23;
    void *temp_r0_24;
    void *temp_r0_25;
    void *temp_r0_26;
    void *temp_r0_27;
    void *temp_r0_28;
    void *temp_r0_29;
    void *temp_r0_2;
    void *temp_r0_30;
    void *temp_r0_31;
    void *temp_r0_3;
    void *temp_r0_4;
    void *temp_r0_5;
    void *temp_r0_6;
    void *temp_r0_7;
    void *temp_r0_8;
    void *temp_r0_9;
    void *var_r5;

    var_r5 = NULL;
    switch (arg1) {
        default:
            break;
        case 0xF:
            var_r5 = func_0205e80c(0x28, 3, 4);
            if (var_r5 != NULL) {
                M2C_FIELD(var_r5, M2C_UNK **, 0) = &data_020fe6d0;
                M2C_FIELD(var_r5, u32 *, 4)      = arg1;
                M2C_FIELD(var_r5, s32 *, 8)      = 0;
                M2C_FIELD(var_r5, s32 *, 0xC)    = 0;
                M2C_FIELD(var_r5, s32 *, 0x10)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x14)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x18)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x1C)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x20)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x24)   = 0;
                M2C_FIELD(var_r5, M2C_UNK **, 0) = &data_020fe6f0;
            }
            break;
        case 0x6:
            temp_r0 = func_0205e80c(0x90, 3, 4);
            var_r5  = temp_r0;
            if (var_r5 != NULL) {
                var_r5 = func_02069db8(temp_r0, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x11:
            temp_r0_2 = func_0205e80c(0xAC, 3, 4);
            var_r5    = temp_r0_2;
            if (var_r5 != NULL) {
                var_r5 = func_02073a00(temp_r0_2, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x13:
            temp_r0_3 = func_0205e80c(0x90, 3, 4);
            var_r5    = temp_r0_3;
            if (var_r5 != NULL) {
                var_r5 = func_0206d13c(temp_r0_3, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x39:
            var_r5 = func_0205e80c(0x28, 3, 4);
            if (var_r5 != NULL) {
                M2C_FIELD(var_r5, M2C_UNK **, 0) = &data_020fe6d0;
                M2C_FIELD(var_r5, u32 *, 4)      = arg1;
                M2C_FIELD(var_r5, s32 *, 8)      = arg2;
                M2C_FIELD(var_r5, s32 *, 0xC)    = arg3;
                M2C_FIELD(var_r5, s32 *, 0x10)   = arg4;
                M2C_FIELD(var_r5, s32 *, 0x14)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x18)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x1C)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x20)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x24)   = 0;
                M2C_FIELD(var_r5, M2C_UNK **, 0) = &data_020fe960;
            }
            break;
        case 0x1F:
            temp_r0_4 = func_0205e80c(0x54, 3, 4);
            var_r5    = temp_r0_4;
            if (var_r5 != NULL) {
                var_r5 = func_0206d88c(temp_r0_4, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x4:
            var_r5 = func_0205e80c(0xC0, 3, 4);
            if (var_r5 != NULL) {
                temp_r4                          = M2C_FIELD(arg0, s32 *, 0x58);
                M2C_FIELD(var_r5, M2C_UNK **, 0) = &data_020fe6d0;
                M2C_FIELD(var_r5, u32 *, 4)      = arg1;
                M2C_FIELD(var_r5, s32 *, 8)      = arg2;
                M2C_FIELD(var_r5, s32 *, 0xC)    = arg3;
                M2C_FIELD(var_r5, s32 *, 0x10)   = arg4;
                M2C_FIELD(var_r5, s32 *, 0x14)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x18)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x1C)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x20)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x24)   = 0;
                M2C_FIELD(var_r5, M2C_UNK **, 0) = &data_020ff478;
                func_0208a938(var_r5 + 0x2C, &data_020ff478);
                M2C_FIELD(var_r5, s32 *, 0x14) = temp_r4;
                M2C_FIELD(var_r5, s8 *, 0xBC)  = 0;
            }
            break;
        case 0x30:
            temp_r0_5 = func_0205e80c(0x100, 3, 4);
            var_r5    = temp_r0_5;
            if (var_r5 != NULL) {
                var_r5 = func_020872b4(temp_r0_5, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x9:
            temp_r0_6 = func_0205e80c(0x2C, 3, 4);
            var_r5    = temp_r0_6;
            if (var_r5 != NULL) {
                var_r5 = func_0207fcd4(temp_r0_6, arg1, arg2, arg3, arg4);
            }
            break;
        case 0xA:
            temp_r0_7 = func_0205e80c(0x164, 3, 4);
            var_r5    = temp_r0_7;
            if (var_r5 != NULL) {
                var_r5 = func_020801d8(temp_r0_7, arg1, arg2, arg3, arg4);
            }
            break;
        case 0xB:
        case 0xC:
            temp_r0_8 = func_0205e80c(0xE4, 3, 4);
            var_r5    = temp_r0_8;
            if (var_r5 != NULL) {
                var_r5 = func_0207b71c(temp_r0_8, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x1E:
            var_r5 = func_0205e80c(0x48, 3, 4);
            if (var_r5 != NULL) {
                M2C_FIELD(var_r5, M2C_UNK **, 0) = &data_020fe6d0;
                M2C_FIELD(var_r5, u32 *, 4)      = arg1;
                M2C_FIELD(var_r5, s32 *, 8)      = arg2;
                M2C_FIELD(var_r5, s32 *, 0xC)    = arg3;
                M2C_FIELD(var_r5, s32 *, 0x10)   = arg4;
                M2C_FIELD(var_r5, s32 *, 0x14)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x18)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x1C)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x20)   = 0;
                M2C_FIELD(var_r5, s32 *, 0x24)   = 0;
                M2C_FIELD(var_r5, M2C_UNK **, 0) = &data_020fe908;
                func_02067bc0(var_r5 + 0x2C, &data_020fe908);
                M2C_FIELD(var_r5, s32 *, 0x44) = arg2;
            }
            break;
        case 0x31:
            temp_r0_9 = func_0205e80c(0x14C, 3, 4);
            var_r5    = temp_r0_9;
            if (var_r5 != NULL) {
                var_r5 = func_02076d2c(temp_r0_9, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x32:
            temp_r0_10 = func_0205e80c(0x88, 3, 4);
            var_r5     = temp_r0_10;
            if (var_r5 != NULL) {
                var_r5 = func_02076008(temp_r0_10, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x33:
            temp_r0_11 = func_0205e80c(0xB4, 3, 4);
            var_r5     = temp_r0_11;
            if (var_r5 != NULL) {
                var_r5 = func_0207c49c(temp_r0_11, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x34:
            temp_r0_12 = func_0205e80c(0xE0, 3, 4);
            var_r5     = temp_r0_12;
            if (var_r5 != NULL) {
                var_r5 = func_0207d168(temp_r0_12, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x1C:
            temp_r0_13 = func_0205e80c(0xEBC, 3, 4);
            var_r5     = temp_r0_13;
            if (var_r5 != NULL) {
                var_r5 = func_02083d08(temp_r0_13, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x20:
            temp_r0_14 = func_0205e80c(0x94, 3, 4);
            var_r5     = temp_r0_14;
            if (var_r5 != NULL) {
                var_r5 = func_02070dfc(temp_r0_14, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x21:
            temp_r0_15 = func_0205e80c(0xA4, 3, 4);
            var_r5     = temp_r0_15;
            if (var_r5 != NULL) {
                var_r5 = func_0206f354(temp_r0_15, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x23:
            temp_r0_16 = func_0205e80c(0x94, 3, 4);
            var_r5     = temp_r0_16;
            if (var_r5 != NULL) {
                var_r5 = func_0206ecbc(temp_r0_16, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x24:
            temp_r0_17 = func_0205e80c(0x278, 3, 4);
            var_r5     = temp_r0_17;
            if (var_r5 != NULL) {
                var_r5 = func_020714bc(temp_r0_17, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x28:
            temp_r0_18 = func_0205e80c(0xE0B4, 3, 4);
            var_r5     = temp_r0_18;
            if (var_r5 != NULL) {
                var_r5 = func_020730e0(temp_r0_18, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x27:
            temp_r0_19 = func_0205e80c(0x8C, 3, 4);
            var_r5     = temp_r0_19;
            if (var_r5 != NULL) {
                var_r5 = func_02070a38(temp_r0_19, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x22:
            temp_r0_20 = func_0205e80c(0xA4, 3, 4);
            var_r5     = temp_r0_20;
            if (var_r5 != NULL) {
                var_r5 = func_0206fd30(temp_r0_20, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x29:
            temp_r0_21 = func_0205e80c(0x2B20, 3, 4);
            var_r5     = temp_r0_21;
            if (var_r5 != NULL) {
                var_r5 = func_02098790(temp_r0_21, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x26:
            temp_r0_22 = func_0205e80c(0x9C, 3, 4);
            var_r5     = temp_r0_22;
            if (var_r5 != NULL) {
                var_r5 = func_0206e8c0(temp_r0_22, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x25:
            temp_r0_23 = func_0205e80c(0x34, 3, 4);
            var_r5     = temp_r0_23;
            if (var_r5 != NULL) {
                var_r5 = func_02072560(temp_r0_23, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x36:
            temp_r0_24 = func_0205e80c(0xBC, 3, 4);
            var_r5     = temp_r0_24;
            if (var_r5 != NULL) {
                var_r5 = func_0209d948(temp_r0_24, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x2A:
            temp_r0_25 = func_0205e80c(0xF0, 3, 4);
            var_r5     = temp_r0_25;
            if (var_r5 != NULL) {
                var_r5 = func_02099db4(temp_r0_25, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x2B:
            temp_r0_26 = func_0205e80c(0xB8, 3, 4);
            var_r5     = temp_r0_26;
            if (var_r5 != NULL) {
                var_r5 = func_0209bd78(temp_r0_26, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x2C:
            temp_r0_27 = func_0205e80c(0x90, 3, 4);
            var_r5     = temp_r0_27;
            if (var_r5 != NULL) {
                var_r5 = func_0209c720(temp_r0_27, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x37:
            temp_r0_28 = func_0205e80c(0x68, 3, 4);
            var_r5     = temp_r0_28;
            if (var_r5 != NULL) {
                var_r5 = func_02074a3c(temp_r0_28, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x38:
            temp_r0_29 = func_0205e80c(0x90, 3, 4);
            var_r5     = temp_r0_29;
            if (var_r5 != NULL) {
                var_r5 = func_02067d3c(temp_r0_29, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x2E:
            temp_r0_30 = func_0205e80c(0x78, 3, 4);
            var_r5     = temp_r0_30;
            if (var_r5 != NULL) {
                var_r5 = func_0209ee58(temp_r0_30, arg1, arg2, arg3, arg4);
            }
            break;
        case 0x35:
            temp_r0_31 = func_0205e80c(0xF4, 3, 4);
            var_r5     = temp_r0_31;
            if (var_r5 != NULL) {
                var_r5 = func_0208e260(temp_r0_31, arg1, arg2, arg3, arg4);
            }
            break;
    }
    return var_r5;
}
