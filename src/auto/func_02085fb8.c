/* Reconstructed from USA ARM9 at 0x02085fb8 (460 bytes).
 *
 * Serialises one object (arg0) into the message stream that is managed by the
 * global state block data_02104364.  arg1 selects the slot the object belongs
 * to; it is the index into the slot arrays data_0210436f and data_02104374 and
 * the index of the 12 byte record of data_02104388.
 *
 * The read side of the same data is func_02085e88, which uses the matching
 * read helpers (func_02063118) instead of the write helpers (func_020632b4)
 * used here.
 */
#include "m2c.h"

extern s32 data_027e02a8;
extern M2C_UNK data_021027f8;
extern u32 data_02104374[];
extern u8 data_0210436f[];
extern M2C_UNK data_02104388;

M2C_UNK func_02085594(s32 *);          /* extern */
void func_02087124(s32);                /* extern */
M2C_UNK func_02063468(void);            /* extern */
void func_020631fc(s32);                /* extern */
void func_02085e00(s32, s16 *);         /* extern */
void func_0208f0c8(s32);                /* extern */
void func_0208c820(s32);                /* extern */
void func_020632b4(s32, s32);           /* extern */
M2C_UNK func_0205e6e0(u8 *, s32, s32);  /* extern */
void func_0206325c(s32);                /* extern */
s32 func_020631b8(s32);                 /* extern */

s32 func_02085fb8(s32 arg0, u8 arg1) {
    u32 buf[2];
    u32 magic;
    s32 k;

    data_027e02a8 |= 0x100;
    data_02104374[arg1] = func_02085594((s32 *) ((M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 0xC) + (arg0 + 4)));
    func_02087124(arg0);
    data_0210436f[arg1] = M2C_FIELD(arg0, u8 *, 0x455F);
    if (func_02063468() == 0) {
        return 0;
    }
    func_020631fc(arg1);
    func_02085e00(arg0, (arg1 * 0xC) + (s32) &data_02104388);
    func_0208f0c8((M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 0xC) + (arg0 + 4));
    func_0208c820(arg0 + 0x34);
    func_020632b4(arg0 + 0x52, 0x12);
    for (k = 0; k < 2; k++) {
        buf[k] = 0;
    }
    func_0205e6e0((u8 *) buf, arg0 + 0x4488, 8);
    buf[0] &= ~0x800;
    buf[0] &= ~0x400;
    func_020632b4((s32) buf, 8);
    func_020632b4(arg0 + 0x44CC, 0xD);
    func_020632b4(arg0 + 0x44DC, 0xD);
    func_020632b4(arg0 + 0x44EC, 0x20);
    func_020632b4(arg0 + 0x450C, 5);
    func_020632b4(arg0 + 0x4514, 4);
    func_020632b4(arg0 + 0x4518, 4);
    func_020632b4(arg0 + 0x451C, 3);
    func_020632b4(arg0 + 0x4520, 3);
    magic = 0x075BCD15;
    func_020632b4((s32) &magic, 4);
    func_0206325c(arg1);
    return func_020631b8(arg1) ? 1 : 0;
}
