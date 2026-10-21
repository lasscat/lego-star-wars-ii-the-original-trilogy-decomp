#include "m2c.h"

/* A 12-byte vector of 4.12 fixed point coordinates. */
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3;

typedef struct {
    u8 pad_000[0xB0];
    Vec3 pos;
} UnkObject;

M2C_UNK func_02067080(M2C_UNK, u8, u8);        /* extern */
extern Vec3 data_021090d4[];

void func_02056190(M2C_UNK arg0, M2C_UNK arg1) {
    u8 *keys = (u8 *) arg1;
    M2C_UNK obj;
    Vec3 *slot;
    Vec3 *pos;
    u8 index;

    obj = func_02067080(arg0, keys[1], keys[2]);
    if (obj == 0) {
        return;
    }
    index = keys[0];
    pos   = &((UnkObject *) obj)->pos;
    slot  = &data_021090d4[index];
    if (slot == pos) {
        return;
    }
    slot->x = pos->x;
    slot->y = pos->y;
    slot->z = pos->z;
}
