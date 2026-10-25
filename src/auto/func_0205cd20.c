#include "m2c.h"

typedef struct HuffNode {
    u16 child[2];
} HuffNode;

typedef struct HuffState {
    u32 *offsets;
    u8 *data;
    HuffNode *tree;
} HuffState;

extern HuffState data_020fe5c8;

s32 func_0205cd20(s32 idx, u8 *out, s32 size) {
    u8 *buf;
    u8 *src;
    u32 n;
    u32 bit;
    s32 bits;
    u16 val;
    u32 pending;
    u32 node;
    u8 b;

    val     = 0;
    pending = 0;
    buf     = data_020fe5c8.data;
    if (buf == NULL) {
        return 1;
    }
    n    = 0;
    bit  = 0;
    src  = buf + data_020fe5c8.offsets[idx];
    bits = *src;
    src++;
    do {
        node = 0x100;
        do {
            if ((bits >> bit) & 1) {
                node = data_020fe5c8.tree[node - 0x100].child[1];
            } else {
                node = data_020fe5c8.tree[node - 0x100].child[0];
            }
            bit++;
            if (bit == 8) {
                bits = *src++;
                bit  = 0;
            }
        } while (node >= 0x100);
        b        = (u8) node;
        out[n++] = b;
        if (b >= 0xf0 && pending == 0) {
            val     = (u16) (b << 8);
            pending = 1;
        } else if (pending != 0) {
            val |= (u8) node;
            pending = 0;
        } else if (pending == 0) { // FAKE: redundant re-test, reproduces predicated eq block
            val = 0;
            val |= (u8) node; // FAKE: zero then OR of the low byte reproduces the orr #0 in the original
        }
        if (out[n - 1] != 0 && n == size) {
            return 2;
        }
    } while (val != 0);
    return 0;
}
