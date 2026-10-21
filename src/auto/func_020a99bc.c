#include "m2c.h"

typedef struct {
    u8 index;
    u8 value;
    u8 unused[0x1a];
} Unk_020a99bc;

extern s32 data_027e02a8;
extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210794c;

M2C_UNK func_020b04f0(M2C_UNK *, M2C_UNK, void *, M2C_UNK); /* extern */

void func_020a99bc(void *arg0, u8 arg1) {
    Unk_020a99bc payload;

    if (data_027e02a8 & 0x40) {
        payload.value = arg1;
        payload.index = M2C_FIELD(&data_021027f8, u8 *, 0x2A);
        func_020b04f0(&data_0210794c, 0x39, &payload, 0xFF);
    } else {
        M2C_FIELD((u8 *) arg0 + M2C_FIELD(&data_021027f8, u8 *, 0x2A), u8 *, 0x208) = arg1;
    }
}
