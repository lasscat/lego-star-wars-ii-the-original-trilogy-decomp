#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x02053398 (328 bytes).
 *
 * func_02053398 flushes one 0x38 byte table entry of data_02101bb8
 * (a [][4] array of 0xe0 byte groups) into the NDS 2D palette RAM at
 * 0x04000000:
 *
 *     entry = &data_02101bb8[a][b];
 *     if (data_027e02a8 & 0x200) a = 0;      // global "no rows" mask
 *     if (entry->field_34 & 4)  palette[4 + b]          = entry->field_00;
 *     if (entry->field_34 & 1)  palette[8 + 2*b]        = entry->field_08 >> 12;
 *                                palette[9 + 2*b]        = entry->field_0C >> 12;
 *     if (entry->field_34 & 2)  palette[0x10 .. 0x17]    = entry->field_22..30;
 *                                (b == 3 uses 0x18 .. 0x1F)
 *
 * The bit field in field_34 is cleared after every group is written, so each
 * group is pushed to the palette exactly once.
 *
 * The u16 store targets are written as indexed u16 accesses so that the
 * compiler folds the constant part of the index into the base address and
 * keeps the variable part in the scaled index register; that reproduces the
 * original "add base,#imm" / "lsl index" / "strh [base,index]" addressing.
 * The palette row base is a byte address, so the u16 index of the first
 * group is (8 + b) halfwords and the second group is (0x10 + b*4) bytes.
 */
typedef struct {
    u16 field_00;
    u8 pad_02[6];
    s32 field_08;
    s32 field_0C;
    u8 pad_10[0x12];
    u16 field_22;
    u16 field_24;
    u16 field_26;
    u16 field_28;
    u8 pad_2A[2];
    s32 field_2C;
    s32 field_30;
    u32 field_34;
} TableEntry;

extern TableEntry data_02101bb8[][4];
extern s32 data_027e02a8;

void func_02053398(s32 a, s32 b) {
    TableEntry *e = &data_02101bb8[a][b];

    if (data_027e02a8 & 0x200) {
        a = 0;
    }

    if (e->field_34 & 4) {
        *((u16 *) (0x04000000 + (a << 12) + 8) + b) = e->field_00;
        e->field_34 &= ~4;
    }

    if (e->field_34 & 1) {
        *((u16 *) (0x04000000 + (a << 12) + 0x10) + b * 2) = e->field_08 >> 12;
        *((u16 *) (0x04000000 + (a << 12) + 0x12) + b * 2) = e->field_0C >> 12;
        e->field_34 &= ~1;
    }

    if (e->field_34 & 2) {
        if (b == 2) {
            *(u16 *) (0x04000000 + (a << 12) + 0x20) = e->field_22;
            *(u16 *) (0x04000000 + (a << 12) + 0x22) = e->field_24;
            *(u16 *) (0x04000000 + (a << 12) + 0x24) = e->field_26;
            *(u16 *) (0x04000000 + (a << 12) + 0x26) = e->field_28;
            *(u32 *) (0x04000000 + (a << 12) + 0x28) = e->field_2C;
            *(u32 *) (0x04000000 + (a << 12) + 0x2C) = e->field_30;
        } else if (b == 3) {
            *(u16 *) (0x04000000 + (a << 12) + 0x30) = e->field_22;
            *(u16 *) (0x04000000 + (a << 12) + 0x32) = e->field_24;
            *(u16 *) (0x04000000 + (a << 12) + 0x34) = e->field_26;
            *(u16 *) (0x04000000 + (a << 12) + 0x36) = e->field_28;
            *(u32 *) (0x04000000 + (a << 12) + 0x38) = e->field_2C;
            *(u32 *) (0x04000000 + (a << 12) + 0x3C) = e->field_30;
        }
        e->field_34 &= ~2;
    }
}
