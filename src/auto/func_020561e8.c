#include "m2c.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

M2C_UNK func_02067080(M2C_UNK, u8, u8);        /* extern */
extern Vec3 data_021090d4[];

void func_020561e8(M2C_UNK arg0, M2C_UNK arg1) {
    u8 *keys = (u8 *) arg1;
    M2C_UNK obj;
    Vec3 *slot;
    s32 flag;

    obj = func_02067080(arg0, keys[1], keys[2]);
    if (obj == 0) {
        return;
    }
    slot = &data_021090d4[keys[0]];
    if (M2C_FIELD(obj, s32 *, 0xb0) != slot->x || M2C_FIELD(obj, s32 *, 0xb4) != slot->y ||
        M2C_FIELD(obj, s32 *, 0xb8) != slot->z) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag != 0) {
        if ((s32 *) ((u8 *) obj + 0xb0) != (s32 *) slot) {
            M2C_FIELD(obj, s32 *, 0xb0) = slot->x;
            M2C_FIELD(obj, s32 *, 0xb4) = slot->y;
            M2C_FIELD(obj, s32 *, 0xb8) = slot->z;
        }
        M2C_FIELD(obj, u8 *, 0xd1) = 1;
    }
}
