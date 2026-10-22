/* Reconstructed from USA ARM9 at 0x020d01fc (176 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    u8 f0;
    u8 f1;
    u16 f2;
    u16 f4;
} HuffElem6;

typedef struct {
    u8 pad0[8];
    s16 f8;
    s16 fa;
    u8 padc[2];
    u16 fe;
    u8 pad10[8];
} HuffElem24;

typedef struct {
    u8 count;
    u8 pad1[3];
    u8 *codes;
    HuffElem6 *elems6;
    HuffElem24 *elems24;
} HuffTree;

extern HuffTree HuffTreeTop;

s32 HuffRemainingNodeCanSetOffset(s32 arg0) {
    u8 count = HuffTreeTop.count;
    u8 i;
    s16 rem = 0x40 - arg0;

    for (i = 0; i < count; i++) {
        if (HuffTreeTop.elems6[i].f0 != 0) {
            if (count - i <= rem) {
                rem = rem - 1;
            } else {
                return 0;
            }
        }
        if (HuffTreeTop.elems6[i].f1 != 0) {
            if (count - i <= rem) {
                rem = rem - 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}
