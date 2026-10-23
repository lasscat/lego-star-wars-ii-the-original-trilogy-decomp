/* Reconstructed from USA ARM9 at 0x0208e874 (484 bytes).
 *
 * func_0208e874: builds the glyph list of a text menu.
 *
 * The function copies six u16 ids out of the table at data_020f4cf8 (entries
 * 4..9), replaces entry 4 by 0x2c when file->flag_e1 is set, and then walks
 * the file->count entries, measuring one string per id with func_02065be8
 * and (while file->flag_e2 is clear) handing every entry to func_02064b3c.
 *
 * The vertical position of an entry is 0x28 + i * 0x19 (the compiler keeps it
 * in a register and bumps it by 0x19 per iteration).
 */
#include "m2c.h"

extern u16 data_020f4cf8[];
extern u8 data_02106d90[];
extern u32 data_027e02a8[];

extern void func_0206574c(void *, s32, s32);
extern u32 func_02066708(u32);
extern u32 func_02065be8(void *, u32, s32, s32, u32, s32);
extern void func_02064b3c(void *, void *, void *, u16, s32);

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} UnkMenu;

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
} UnkEntry;

typedef struct {
    u8 unk_00[0x30];
    UnkMenu *menu;
    u8 unk_34[8];
    char text[0x5c];
    UnkEntry entries[6];
    u8 flag_e0;
    u8 flag_e1;
    u8 flag_e2;
    u8 flag_e3;
    u32 handle;
    u32 count;
    u32 count2;
    u32 unk_f0;
} UnkFile;

void func_0208e874(UnkFile *file, s32 flag) {
    u16 ids[6];
    u32 handle;
    u32 i;

    ids[0] = data_020f4cf8[4];
    ids[1] = data_020f4cf8[5];
    ids[2] = data_020f4cf8[6];
    ids[3] = data_020f4cf8[7];
    ids[4] = data_020f4cf8[8];
    ids[5] = data_020f4cf8[9];
    if (file->flag_e1 != 0) {
        ids[4] = 0x2c;
    }

    if (*(u8 *) (*(u32 *) (data_02106d90 + 0xbb8) + 6) != 0) {
        ids[1] = 0x3d;
        file->menu->unk_08 &= ~1u;
    } else if (data_027e02a8[0] & 0x40) {
        ids[1] = 0x3e;
        file->menu->unk_08 &= ~1u;
    } else {
        file->menu->unk_08 |= 1u;
    }

    if (flag != 0) {
        func_0206574c(file->text, 6, 6 - 8);
        file->handle = func_02065be8(file->text, 0x3c, 0x80, 8, func_02066708(0x3f), 1);
    }

    handle = file->handle;
    for (i = 0; i < file->count; i++) {
        u16 params[2];
        s32 y;

        if (i == file->count2) {
            func_0206574c(file->text, 3, -2);
        } else {
            func_0206574c(file->text, 0, -2);
        }
        y      = 0x28 + i * 0x19;
        handle = func_02065be8(file->text, handle, 0x80, y, func_02066708(ids[i]), 1);
        if (file->flag_e2 == 0) {
            params[0] = 0x80;
            params[1] = (u16) y;
            func_02064b3c(&file->entries[i], params, file->text, ids[i], 1);
        }
    }
    file->flag_e2 = 1;
}
