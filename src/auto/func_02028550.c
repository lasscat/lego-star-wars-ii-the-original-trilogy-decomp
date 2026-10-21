/* Reconstructed from USA ARM9 at 0x02028550 (396 bytes).
 *
 * Removes an object from a linked list and updates its state.
 *
 * The node layout used here:
 *   +0x000  link    pointer to the "next" field of the previous list entry
 *   +0x004  next    next list entry
 *   +0x008  state   counter / flag word (bit 0x800 selects the removal path)
 *   +0x00c  ...
 *   +0x14e  flags   bit field, bit 1 decides whether the entry is really removed
 *   +0x180  type    compared against 17
 *   +0x5d6  state2  byte cleared when the entry is removed
 *
 * "base" is the object the link points into; the link points at offset +4 of
 * that object, so the object base is the link minus 4.
 *
 * Reconstruction notes (all of these are load bearing for the byte match):
 *  - the link field is read again (not reused from the earlier value) before
 *    the list walk; the volatile qualified access reproduces that reload.
 *  - "var_r2" is always NULL in the original, but the compiler kept the test
 *    against it, so the two assignments (one per branch) are kept as they are.
 */
#include "m2c.h"

void func_020286dc(M2C_UNK, M2C_UNK);   /* extern */
void func_02029468(s32);        /* extern */

typedef struct {
    u16 b0 : 1;
    u16 b1 : 1;
    u16 rest : 14;
} Bits;

typedef struct Node {
    u32 *f0;
    u32 *f4;
    s32 f8;
    u32 fC;
    u8 pad0[0x14E - 0x10];
    Bits f14E;
    u8 pad1[0x180 - 0x150];
    u16 f180;
    u8 pad2[0x5D6 - 0x182];
    u8 f5D6;
} Node;

void func_02028550(Node *arg0) {
    u32 *link;
    u32 *cur;
    Node *var_r2;

    {
        u8 *base;
        base = (u8 *) arg0->f0;
        if (arg0->f0 != 0) {
            base = (u8 *) arg0->f0 - 4;
        }
        if (base == 0) {
            goto L_A;
        }
    }
    {
        u8 *base;
        base = (u8 *) arg0->f0;
        if (arg0->f0 != 0) {
            base = (u8 *) arg0->f0 - 4;
        }
        if ((*(u32 *) (base + 8) & 0x800) == 0x800) {
        L_A:
            if (arg0->f0 != 0) {
                var_r2 = 0;
                link   = *(u32 *volatile *) &arg0->f0;
                cur    = link[0];
                if (cur != (u32 *) arg0) {
                    do {
                        link = cur + 1;
                        cur  = cur[1];
                    } while (cur != (u32 *) arg0);
                }
                link[0] = arg0->f4;
            } else {
                var_r2 = 0;
            }
            if (var_r2 != 0) {
                arg0->f0   = (u32 *) var_r2;
                arg0->f4   = var_r2->f0;
                var_r2->f0 = (u32 *) arg0;
            } else {
                arg0->f0 = 0;
                arg0->f4 = 0;
            }
            return;
        } else {
            u8 *base;
            base = (u8 *) arg0->f0;
            if (arg0->f0 != 0) {
                base = (u8 *) arg0->f0 - 4;
            }
            if (((Node *) base)->f14E.b1 == 1) {
                func_020286dc(arg0, 0);
                {
                    u8 *b2;
                    b2 = (u8 *) arg0->f0;
                    if (arg0->f0 != 0) {
                        b2 = (u8 *) arg0->f0 - 4;
                    }
                    func_02029468((s32) b2);
                }
                {
                    u8 *b3;
                    b3 = (u8 *) arg0->f0;
                    if (arg0->f0 != 0) {
                        b3 = (u8 *) arg0->f0 - 4;
                    }
                    ((Node *) b3)->f5D6 = 0;
                }
                {
                    u32 *link_b;
                    u32 *cur_b;
                    link_b = *(u32 *volatile *) &arg0->f0;
                    if (link_b != 0) {
                        var_r2 = 0;
                        cur_b  = link_b[0];
                        if (cur_b != (u32 *) arg0) {
                            do {
                                link_b = cur_b + 1;
                                cur_b  = cur_b[1];
                            } while (cur_b != (u32 *) arg0);
                        }
                        link_b[0] = arg0->f4;
                    } else {
                        var_r2 = 0;
                    }
                }
                if (var_r2 != 0) {
                    arg0->f0   = (u32 *) var_r2;
                    arg0->f4   = var_r2->f0;
                    var_r2->f0 = (u32 *) arg0;
                } else {
                    arg0->f0 = 0;
                    arg0->f4 = 0;
                }
            } else {
                arg0->f8 = arg0->f8 - 1;
                if (arg0->f8 > 0) {
                    return;
                }
                arg0->f8 = 2;
                {
                    u8 *b4;
                    b4 = (u8 *) arg0->f0;
                    if (arg0->f0 != 0) {
                        b4 = (u8 *) arg0->f0 - 4;
                    }
                    func_020286dc(arg0, ((Node *) b4)->f180 != 17);
                }
            }
        }
    }
}
