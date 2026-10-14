#include "m2c.h"

M2C_UNK func_020ad528(); /* extern */
M2C_UNK func_020ad7a4();                     /* extern */
M2C_UNK func_020ad8b4();                            /* extern */
s32 func_020ae63c();                                /* extern */
s32 func_020ae868();                                /* extern */
M2C_UNK func_020cdd00();          /* extern */
extern M2C_UNK data_021001b8;
extern M2C_UNK data_021001f0;
extern M2C_UNK data_02100208;
extern M2C_UNK data_0210021c;
extern M2C_UNK data_0210b320;
extern M2C_UNK data_0210b460;

void func_020ae704(void *arg0) {
    u16 temp_r0;

    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020ad8b4();
        func_020ad7a4(9);
        return;
    }
    if (M2C_FIELD(&data_0210b320, s32 *, 0x20) != 2) {
        return;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 8);
    switch (temp_r0) {                              /* irregular */
        case 3:
            return;
        case 5:
            func_020ad528(&data_021001b8, M2C_FIELD(arg0, u8 *, 0xA), M2C_FIELD(arg0, u8 *, 0xB), M2C_FIELD(arg0, u8 *, 0xC),
                          (s32) M2C_FIELD(arg0, u8 *, 0xD), (s32) M2C_FIELD(arg0, u8 *, 0xE),
                          (s32) M2C_FIELD(arg0, u8 *, 0xF));
            if (((u32) M2C_FIELD(arg0, u16 *, 0x36) < 8U) ||
                (M2C_FIELD(arg0, s32 *, 0x3C) != M2C_FIELD(&data_0210b320, s32 *, 0x88))) {
                func_020ad528(&data_021001f0);
                goto block_19;
            }
            if (!(M2C_FIELD(arg0, u8 *, 0x43) & 1)) {
                func_020ad528(&data_02100208);
                goto block_19;
            }
            func_020ad528(&data_0210021c);
            func_020cdd00(&data_0210b460, 0xC0);
            if (M2C_FIELD(&data_0210b320, M2C_UNK(**)(M2C_UNK *), 0x34) != NULL) {
                M2C_FIELD(&data_0210b320, M2C_UNK(**)(M2C_UNK *), 0x34)(&data_0210b460);
            }
            if (M2C_FIELD(&data_0210b320, u16 *, 4) != 0) {
                if (func_020ae868() != 0) {
                    return;
                }
                func_020ad7a4(9);
                return;
            }
        default:
        case 4:
        block_19:
            if (func_020ae63c() != 0) {
                return;
            }
            func_020ad7a4(9);
            return;
    }
}
