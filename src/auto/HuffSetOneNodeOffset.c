/* Reconstructed from USA ARM9 at 0x020d02ac (396 bytes).
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

void HuffSetOneNodeOffset(s32 arg0, s32 arg1) {
    u16 v;
    s16 idx;
    u8 fl = 0;
    u16 cnt;
    s32 cidx;

    if (arg1 != 0) {
        v                           = HuffTreeTop.elems6[arg0].f4;
        HuffTreeTop.elems6[arg0].f1 = 0;
    } else {
        v                           = HuffTreeTop.elems6[arg0].f2;
        HuffTreeTop.elems6[arg0].f0 = 0;
    }

    idx = HuffTreeTop.elems24[v].f8;
    if (HuffTreeTop.elems24[idx].fe == 0) {
        fl |= 0x80;
        HuffTreeTop.codes[HuffTreeTop.count * 2] = (u8) idx;
        cnt                                      = HuffTreeTop.count;
        HuffTreeTop.elems6[cnt].f2               = (u8) HuffTreeTop.elems24[v].f8;
        HuffTreeTop.elems6[cnt].f0               = 0;
    } else {
        cnt                        = HuffTreeTop.count;
        HuffTreeTop.elems6[cnt].f2 = idx;
    }

    idx = HuffTreeTop.elems24[v].fa;
    if (HuffTreeTop.elems24[idx].fe == 0) {
        fl |= 0x40;
        HuffTreeTop.codes[HuffTreeTop.count * 2 + 1] = (u8) idx;
        cnt                                          = HuffTreeTop.count;
        HuffTreeTop.elems6[cnt].f4                   = (u8) HuffTreeTop.elems24[v].fa;
        HuffTreeTop.elems6[cnt].f1                   = 0;
    } else {
        cnt                        = HuffTreeTop.count;
        HuffTreeTop.elems6[cnt].f4 = idx;
    }

    cidx                    = arg1 + arg0 * 2;
    HuffTreeTop.codes[cidx] = fl | (u8) (HuffTreeTop.count - arg0 - 1);
    HuffTreeTop.count++;
}
