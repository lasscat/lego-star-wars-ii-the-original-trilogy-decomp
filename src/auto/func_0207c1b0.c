#include "m2c.h"

typedef struct {
    u8 unk_00[0xd0];
    M2C_UNK *unk_d0[3];
    u8 unk_dc;
} Unk_0207c1b0;

M2C_UNK func_02053c2c(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02060cd0(void *, M2C_UNK, M2C_UNK);                             /* extern */
M2C_UNK func_0206574c(void *, M2C_UNK, M2C_UNK);                             /* extern */
M2C_UNK func_02065be8(void *, M2C_UNK, M2C_UNK, M2C_UNK, void *, M2C_UNK); /* extern */
s32 func_02065840(void *, void *);                                          /* extern */
void *func_02066708(M2C_UNK);                                                /* extern */
M2C_UNK func_0207c37c(s32, M2C_UNK);                                        /* extern */
M2C_UNK func_02086534(M2C_UNK *, M2C_UNK);                                   /* extern */
M2C_UNK func_0208dd40(void *, void *, M2C_UNK);                              /* extern */
extern M2C_UNK data_02104d90;
extern M2C_UNK data_02104de2;

void func_0207c1b0(Unk_0207c1b0 *arg0, s32 arg1) {
    void *var_ch;
    void *var_str;
    void *var_widget;
    s32 var_r8;
    s32 var_r9;
    s32 var_r10;
    u32 var_len;
    u8 var_buf[0x44];
    u16 var_name[5];
    u32 var_flags;
    u8 *var_e;

    if (arg0->unk_dc < 3) {
        var_ch    = arg0->unk_d0[arg0->unk_dc];
        var_flags = M2C_FIELD(var_ch, u32 *, 8);
        func_02060cd0(var_ch, 1, (var_flags & 0x80000000) ? 0 : 1);
    }
    func_02053c2c((s8 *) arg0 + 0x30, 0, 8, 0x20, 4, 0x100);
    if (arg1 == 3) {
        func_0207c37c((s32) arg0, 1);
    } else {
        var_ch = arg0->unk_d0[arg1];
        if (var_ch) {
            var_flags = M2C_FIELD(var_ch, u32 *, 8);
            func_02060cd0(var_ch, 2, (var_flags & 0x80000000) ? 0 : 1);
        }
        if (func_02086534(&data_02104d90, arg1 + 0x49)) {
            var_e       = (u8 *) &data_02104de2 + arg1 * 6;
            var_name[0] = var_e[0];
            var_name[1] = var_e[2];
            var_name[2] = var_e[1];
            var_name[3] = var_e[3];
            var_name[4] = var_e[4];
            func_0208dd40(var_name, var_buf, 0x40);
            var_str = var_buf;
        } else {
            var_str = func_02066708(0x34);
        }
        var_widget = (s8 *) arg0 + 0x38;
        var_r8     = arg1 * 0x40 + 0x40;
        var_r9     = 0x40;
        var_len    = func_02065840(var_widget, var_str);
        if (var_len >= 0xe0) {
            var_widget = (s8 *) arg0 + 0x68;
            var_r9     = var_r9 + 5;
            var_len    = func_02065840(var_widget, var_str);
        }
        var_len = var_len >> 1;
        var_r10 = 1;
        if (var_len > 0x30) {
            switch (arg1) {
                case 0:
                    var_r8  = 0x10;
                    var_r10 = 0;
                    break;
                case 1:
                    break;
                case 2:
                    var_r8  = 0xf0;
                    var_r10 = 2;
                    break;
            }
        }
        func_0206574c(var_widget, 9, 0);
        func_02065be8(var_widget, 0x1c1, var_r8, var_r9, var_str, var_r10);
        func_0207c37c((s32) arg0, 0);
    }
    arg0->unk_dc = arg1;
}
