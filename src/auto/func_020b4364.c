#include "m2c.h"

extern void *data_0210daf0;
extern M2C_UNK data_0210dafc;

/* Interpreter for the packed shape/letter byte code stored in the object at
 * data_0210daf0.  The object keeps
 *   +0x08  a table of byte indices,
 *   +0x0c  a table of code pointers,
 *   +0x14  the current code pointer,
 *   +0x1e  a 16 bit counter,
 *   +0x28  the index selected by the caller.
 *
 * Every code byte carries its length class in the top two bits:
 *   0 -> 1 byte, 1 -> 2 bytes, 2 -> 3/4 bytes, 3 -> 3..6 bytes.
 * The loop is written with an explicit test label so that the compiled code
 * keeps the test at the end of the loop, as in the original binary.
 */
void func_020b4364(s32 arg0, u8 arg1, u32 arg2) {
    u32 i;
    u8 *p;
    u8 *q;
    u8 *t;
    u8 op;
    u8 fl;
    u8 idx;
    u8 *lut8;
    u32 *lut32;

    if (M2C_FIELD(&data_0210dafc, void **, arg0 * 4) == NULL) {
        return;
    }
    data_0210daf0                         = M2C_FIELD(&data_0210dafc, void **, arg0 * 4);
    M2C_FIELD(data_0210daf0, u8 *, 0x28)  = arg1;
    idx                                   = M2C_FIELD(data_0210daf0, u8 *, 0x28);
    lut8                                  = M2C_FIELD(data_0210daf0, u8 **, 0x8);
    lut32                                 = M2C_FIELD(data_0210daf0, u32 **, 0xC);
    q                                     = (u8 *) lut32[lut8[idx]];
    M2C_FIELD(data_0210daf0, u16 *, 0x1E) = (u16) (*q + 1);
    M2C_FIELD(data_0210daf0, u32 *, 0x14) = (u32) (q + 1);
    i                                     = 0;
    goto L_test;
L_body:
    p = (u8 *) M2C_FIELD(data_0210daf0, u32 *, 0x14);
    if (*p != 0) {
        do {
            M2C_FIELD(data_0210daf0, u32 *, 0x14) = M2C_FIELD(data_0210daf0, u32 *, 0x14) + 1;
            op                                    = *p;
            switch (op >> 6) {
                case 0:
                    break;
                case 1:
                    M2C_FIELD(data_0210daf0, u32 *, 0x14) = M2C_FIELD(data_0210daf0, u32 *, 0x14) + 1;
                    break;
                case 2:
                    if (*((u8 *) M2C_FIELD(data_0210daf0, u32 *, 0x14)) & 0x80) {
                        M2C_FIELD(data_0210daf0, u32 *, 0x14) = M2C_FIELD(data_0210daf0, u32 *, 0x14) + 1;
                    }
                    M2C_FIELD(data_0210daf0, u32 *, 0x14) = M2C_FIELD(data_0210daf0, u32 *, 0x14) + 2;
                    break;
                case 3:
                    t  = (u8 *) M2C_FIELD(data_0210daf0, u32 *, 0x14);
                    fl = *t;
                    t += 2;
                    M2C_FIELD(data_0210daf0, u32 *, 0x14) = (u32) t;
                    if (fl & 0x20) {
                        M2C_FIELD(data_0210daf0, u32 *, 0x14) = M2C_FIELD(data_0210daf0, u32 *, 0x14) + 1;
                    }
                    if (fl & 0x40) {
                        M2C_FIELD(data_0210daf0, u32 *, 0x14) = M2C_FIELD(data_0210daf0, u32 *, 0x14) + 1;
                    }
                    if (fl & 0x80) {
                        M2C_FIELD(data_0210daf0, u32 *, 0x14) = M2C_FIELD(data_0210daf0, u32 *, 0x14) + 1;
                    }
                    break;
            }
            p = (u8 *) M2C_FIELD(data_0210daf0, u32 *, 0x14);
        } while (*p != 0);
    }
    M2C_FIELD(data_0210daf0, u32 *, 0x14) = M2C_FIELD(data_0210daf0, u32 *, 0x14) + 1;
    i++;
    M2C_FIELD(data_0210daf0, u16 *, 0x1E) = (u16) (M2C_FIELD(data_0210daf0, u16 *, 0x1E) - 1);
L_test:
    if (i < arg2) {
        goto L_body;
    }
    M2C_FIELD(data_0210daf0, u8 *, 0x27) = M2C_FIELD(data_0210daf0, u8 *, 0x2C);
    M2C_FIELD(data_0210daf0, u8 *, 0x32) = 0;
    M2C_FIELD(data_0210daf0, u8 *, 0x33) = (u8) (M2C_FIELD(data_0210daf0, u8 *, 0x28) + 1);
    M2C_FIELD(data_0210daf0, u8 *, 0x34) = 0;
    M2C_FIELD(data_0210daf0, u8 *, 0x35) = 0;
}
