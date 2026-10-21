#include "m2c.h"

extern M2C_UNK HuffTreeTop;

void HuffSetOneNodeOffset(M2C_UNK, M2C_UNK);

/* Rebuilds the huffman tree of a subset: drops the child links of node arg0
 * (arg0, arg1 selects which child) and then of every node created since. */
void HuffMakeSubsetHuffTree(u8 arg0, u8 arg1) {
    u8 i = M2C_FIELD(&HuffTreeTop, u8 *, 0);

    HuffSetOneNodeOffset(arg0, arg1);

    if (arg1) {
        M2C_FIELD((u8 *) M2C_FIELD(&HuffTreeTop, s32 *, 8) + arg0 * 6 + 1, u8 *, 0) = 0;
    } else {
        M2C_FIELD((u8 *) M2C_FIELD(&HuffTreeTop, s32 *, 8) + arg0 * 6, u8 *, 0) = 0;
    }

    if (i >= M2C_FIELD(&HuffTreeTop, u8 *, 0)) {
        return;
    }

    do {
        if (M2C_FIELD((u8 *) M2C_FIELD(&HuffTreeTop, s32 *, 8) + i * 6, u8 *, 0)) {
            HuffSetOneNodeOffset(i, 0);
            M2C_FIELD((u8 *) M2C_FIELD(&HuffTreeTop, s32 *, 8) + i * 6, u8 *, 0) = 0;
        }
        if (M2C_FIELD((u8 *) M2C_FIELD(&HuffTreeTop, s32 *, 8) + i * 6 + 1, u8 *, 0)) {
            HuffSetOneNodeOffset(i, 1);
            M2C_FIELD((u8 *) M2C_FIELD(&HuffTreeTop, s32 *, 8) + i * 6 + 1, u8 *, 0) = 0;
        }
        i = (u8) (i + 1);
    } while (i < M2C_FIELD(&HuffTreeTop, u8 *, 0));
}
