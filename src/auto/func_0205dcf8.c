/* Reconstructed from USA ARM9 at 0x0205dcf8 (184 bytes).
 *
 * Walks one of the four link chains of a node and returns the last node of
 * that chain.  "type" selects the link field (0 -> 0x0C, 1 -> 0x08,
 * 2 -> 0x14, 3 -> 0x10); for the types 0 and 1 the stored link points four
 * bytes behind the next node, so it is corrected before it is followed.
 */
#include "m2c.h"

s32 func_0205dcf8(M2C_UNK unused, u32 cur, s32 type) {
    s32 result = 0;
    u32 next;

    switch (type) {
        case 0:
        case 1:
            if (cur != 0) {
                result = (s32) cur;
                switch (type) {
                    case 0:
                        next = M2C_FIELD(cur, u32 *, 0xC);
                        break;
                    default:
                        next = M2C_FIELD(cur, u32 *, 0x8);
                        break;
                }
                if (next != 0) {
                    next -= 4;
                }
                while (next != 0) {
                    cur    = next;
                    result = (s32) cur;
                    switch (type) {
                        case 0:
                            next = M2C_FIELD(cur, u32 *, 0xC);
                            break;
                        default:
                            next = M2C_FIELD(cur, u32 *, 0x8);
                            break;
                    }
                    if (next != 0) {
                        next -= 4;
                    }
                }
            }
            break;
        case 2:
        case 3:
            if (cur != 0) {
                result = (s32) cur;
                next   = (type == 2) ? M2C_FIELD(cur, u32 *, 0x14) : M2C_FIELD(cur, u32 *, 0x10);
                while (next != 0) {
                    cur    = next;
                    result = (s32) cur;
                    next   = (type == 2) ? M2C_FIELD(cur, u32 *, 0x14) : M2C_FIELD(cur, u32 *, 0x10);
                }
            }
            break;
    }
    return result;
}
