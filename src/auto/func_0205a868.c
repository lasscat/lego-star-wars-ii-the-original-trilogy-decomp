#include "m2c.h"

extern M2C_UNK data_020fe4f4;

typedef struct {
    s32 a;
    s32 b;
} S2;

void func_0205a868(void *arg0) {
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0xC);
    switch (temp_r1) {                              /* irregular */
        case 2:
            *(S2 *) ((u8 *) arg0 + 0x14) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x50);
            *(S2 *) ((u8 *) arg0 + 0x1C) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x48);
            *(S2 *) ((u8 *) arg0 + 0x24) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x40);
            return;
        case 3:
            *(S2 *) ((u8 *) arg0 + 0x14) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x38);
            *(S2 *) ((u8 *) arg0 + 0x1C) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x30);
            *(S2 *) ((u8 *) arg0 + 0x24) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x28);
            return;
        case 7:
            *(S2 *) ((u8 *) arg0 + 0x14) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x20);
            *(S2 *) ((u8 *) arg0 + 0x1C) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x18);
            *(S2 *) ((u8 *) arg0 + 0x24) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x10);
            return;
        default:
            *(S2 *) ((u8 *) arg0 + 0x14) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x8);
            *(S2 *) ((u8 *) arg0 + 0x1C) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x0);
            *(S2 *) ((u8 *) arg0 + 0x24) = *(S2 *) ((u8 *) &data_020fe4f4 + 0x58);
            return;
    }
}
