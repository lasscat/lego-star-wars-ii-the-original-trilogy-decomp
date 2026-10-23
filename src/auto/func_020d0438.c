#include "m2c.h"

typedef struct {
    u8 pad0[8];
    u16 f8;
    u16 fa;
    u16 count;
    u16 fe;
    u8 pad10[8];
} HuffElem24;

typedef struct {
    u8 count;
    u8 pad1[3];
    u8 *codes;
    void *elems6;
    HuffElem24 *elems24;
} HuffTree;

extern HuffTree HuffTreeTop;

void func_020d0438(s32 arg0, s32 arg1) {
    HuffTreeTop.elems24[arg0].count++;
    HuffTreeTop.elems24[arg1].count++;
    if (HuffTreeTop.elems24[arg0].fe != 0) {
        func_020d0438(HuffTreeTop.elems24[arg0].f8, HuffTreeTop.elems24[arg0].fa);
    }
    if (HuffTreeTop.elems24[arg1].fe != 0) {
        func_020d0438(HuffTreeTop.elems24[arg1].f8, HuffTreeTop.elems24[arg1].fa);
    }
}
