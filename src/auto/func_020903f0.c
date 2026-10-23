#include "m2c.h"

void *func_02017800(void *, s32); /* extern */

typedef struct Node {
    M2C_UNK **item;
    struct Node **next;
} Node;

void func_020903f0(M2C_UNK *arg0, Node *arg1, s32 arg2) {
    Node *node;
    M2C_UNK *item;
    void *arr;
    s32 slot;
    u32 count;
    u32 n;
    u8 used;

    for (node = M2C_FIELD(arg1, Node **, 4); node != 0; node = M2C_FIELD(node, Node **, 4)) {
        item = M2C_FIELD(node, M2C_UNK **, 0);
        if (M2C_FIELD(item, u16 *, 0xc) != 4) {
            continue;
        }
        arr = func_02017800(item, 0);
        if (arr == 0) {
            continue;
        }
        if (arg2 == 0) {
            count = 0;
            slot  = 1;
            /* The counting index has its own scope: that keeps the register
               allocator from moving it out of the shared callee-saved slot. */
            {
                u32 i;
                for (i = 0; i < 0x19; i++) {
                    if ((((u8 *) arr)[0x1de + i * 2] == 0xFF) || (((u8 *) arr)[0x1df + i * 2] == 0)) {
                        used = 0;
                    } else {
                        used = 1;
                    }
                    if (used != 0) {
                        count += 1;
                    }
                }
            }
            if (count != 0) {
                n = 0;
                while (n < count) {
                    if (item == func_02017800(arr, n)) {
                        slot = 0;
                        break;
                    }
                    n += 1;
                }
            }
            if (slot == 0) {
                continue;
            }
            slot = 1;
            while (slot < 0x19) {
                if ((((u8 *) arr)[0x1de + slot * 2] == 0xFF) || (((u8 *) arr)[0x1df + slot * 2] == 0)) {
                    used = 0;
                } else {
                    used = 1;
                }
                if (used == 0) {
                    ((u8 *) arr)[0x1de + slot * 2] = M2C_FIELD(item, u8 *, 0x88);
                    ((u8 *) arr)[0x1df + slot * 2] = M2C_FIELD(item, u8 *, 0x89);
                    break;
                }
                slot += 1;
            }
            M2C_FIELD(arr, u8 *, 0x1dc) = M2C_FIELD(arr, u8 *, 0x1dc) + 1;
        } else {
            slot = 1;
            while (slot < 0x19) {
                if ((((u8 *) arr)[0x1de + slot * 2] == 0xFF) || (((u8 *) arr)[0x1df + slot * 2] == 0)) {
                    used = 0;
                } else {
                    used = 1;
                }
                if (used == 0) {
                    ((u8 *) arr)[0x1de + slot * 2] = M2C_FIELD(item, u8 *, 0x88);
                    ((u8 *) arr)[0x1df + slot * 2] = M2C_FIELD(item, u8 *, 0x89);
                    break;
                }
                slot += 1;
            }
            M2C_FIELD(arr, u8 *, 0x1dc) = M2C_FIELD(arr, u8 *, 0x1dc) + 1;
        }
    }
}
