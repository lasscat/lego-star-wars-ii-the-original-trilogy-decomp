#include "m2c.h"

M2C_UNK func_020536a8(s32, M2C_UNK); /* extern */
M2C_UNK func_0206e2a0(void *);       /* extern */
s8 func_02086f20(M2C_UNK *, s32);    /* extern */
extern M2C_UNK data_020fe77c;
extern M2C_UNK data_020fe938;
extern M2C_UNK data_02104d90;

/* Initialize the 0x2C-byte object created by func_02087a54: install its
 * data-backed type pointer, copy the wrapper's object references and values,
 * derive a membership byte from the feature-bit table, then initialize and
 * enable its associated graphics resource. */
void *func_0206e1e8(void *node, s32 arg1, s32 arg2, s32 arg3, s32 feature_bit_index, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    M2C_FIELD(node, M2C_UNK **, 0) = &data_020fe77c;
    M2C_FIELD(node, s32 *, 4)      = arg1;
    M2C_FIELD(node, s16 *, 8)      = 0;
    M2C_FIELD(node, M2C_UNK **, 0) = &data_020fe938;
    M2C_FIELD(node, s32 *, 0xC)    = arg3;
    M2C_FIELD(node, s32 *, 0x10)   = arg2;
    M2C_FIELD(node, s32 *, 0x14)   = feature_bit_index;
    M2C_FIELD(node, s32 *, 0x18)   = arg5;
    M2C_FIELD(node, s32 *, 0x1C)   = arg6;
    M2C_FIELD(node, s32 *, 0x20)   = 0x8C;
    M2C_FIELD(node, s8 *, 0x25)    = 0;
    M2C_FIELD(node, s8 *, 0x29)    = (s8) arg7;
    M2C_FIELD(node, s8 *, 0x2A)    = (s8) arg8;
    M2C_FIELD(node, s8 *, 0x28)    = 3;
    M2C_FIELD(node, s8 *, 0x24)    = func_02086f20(&data_02104d90, M2C_FIELD(node, s32 *, 0x14));
    func_0206e2a0(node);
    func_020536a8(M2C_FIELD(node, s32 *, 0x10), 1);
    return node;
}
