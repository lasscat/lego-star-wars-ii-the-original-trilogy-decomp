#include "m2c.h"

M2C_UNK func_02017908(void *, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_020e46bc(void *, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_020fcd70;
extern M2C_UNK func_0200b23c;
extern M2C_UNK func_0200b24c;

/* Initializes the object, initializes three embedded 8-byte reference/list
 * entries through the two supplied callbacks, and stores five caller-provided
 * bytes at +0xF2..+0xF6. */
void *func_0200b174(void *object, M2C_UNK init_value, s8 byte_f3, s8 byte_f5, s32 value_f2, s32 value_f4, u8 byte_f6) {
    u8 initial_config[0x48];

    M2C_FIELD(initial_config, s32 *, 0x24) = 0;
    M2C_FIELD(initial_config, s32 *, 0x28) = 0;
    M2C_FIELD(initial_config, s32 *, 0x2C) = 0;
    M2C_FIELD(initial_config, s32 *, 0x30) = 0x1000;
    M2C_FIELD(initial_config, s32 *, 0x34) = 0x1000;
    M2C_FIELD(initial_config, s32 *, 0x38) = 0x1000;
    M2C_FIELD(initial_config, u16 *, 0x3C) = 0;
    M2C_FIELD(initial_config, u16 *, 0x3E) = 0;
    M2C_FIELD(initial_config, u16 *, 0x40) = 0;
    M2C_FIELD(initial_config, s8 *, 0x44)  = 1;
    M2C_FIELD(initial_config, s8 *, 0x45)  = 1;
    func_02017908(object, 0x80, init_value, (M2C_UNK *) initial_config);
    M2C_FIELD(object, M2C_UNK **, 0) = &data_020fcd70;
    M2C_FIELD(object, s32 *, 0xD4)   = 0;
    func_020e46bc(object + 0xD8, 3, 8, &func_0200b23c, &func_0200b24c);
    M2C_FIELD(object, s16 *, 0xF0) = 0;
    M2C_FIELD(object, s8 *, 0xF2)  = (s8) value_f2;
    M2C_FIELD(object, s8 *, 0xF3)  = byte_f3;
    M2C_FIELD(object, s8 *, 0xF4)  = (s8) value_f4;
    M2C_FIELD(object, s8 *, 0xF5)  = byte_f5;
    M2C_FIELD(object, u8 *, 0xF6)  = byte_f6;
    return object;
}
