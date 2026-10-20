#include "m2c.h"

M2C_UNK func_02063118(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_0205e624(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern M2C_UNK data_02104364;

/* One 12 byte record per slot, the array starts at data_02104388. */
typedef struct {
    u8 data[12];
} Slot;
extern Slot data_02104388[];

/* One flag byte per slot, the array starts at data_021043ac. */
extern u8 data_021043ac[];

void func_020630b8(s32 arg0) {
    if (data_021043ac[arg0] != 0) {
        /* Rewind the streaming writer to the start of the shared buffer and
         * drop the partial byte, then copy the buffer into the slot. */
        M2C_FIELD(&data_02104364, s32 *, 0x50) = M2C_FIELD(&data_02104364, s32 *, 0x20);
        M2C_FIELD(&data_02104364, s32 *, 0x54) = 0;
        func_02063118(&data_02104388[arg0], sizeof(Slot));
    } else {
        func_0205e624(&data_02104388[arg0], 0, sizeof(Slot));
    }
}
