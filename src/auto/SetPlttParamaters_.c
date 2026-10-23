/* Reconstructed from USA ARM9 at 0x020c7a4c (80 bytes).
 *
 * Fills the palette parameter (+0x14) of a GFD texture parameter block.
 * The palette entry is looked up in the table referenced by the u16 offset
 * at +0x34 of arg0. The entry holds a 16 bit colour value at +0 and flags
 * at +2; when the flag bit 0 is clear both the entry colour and the 16 bit
 * parameter at +0x2C of arg0 are halved before they are summed.
 */
#include "m2c.h"

extern M2C_UNK func_020c631c(M2C_UNK);

s32 SetPlttParamaters_(s32 arg0, s32 arg1, s32 arg2) {
    u16 *entry;
    u32 value;
    u32 other;
    u16 flags;

    entry = (u16 *) func_020c631c((u8 *) arg0 + *(u16 *) ((u8 *) arg0 + 0x34));
    other = (u16) * (u32 *) ((u8 *) arg0 + 0x2C);
    flags = entry[1];
    value = entry[0];
    if ((flags & 1) == 0) {
        value = (u16) ((u32) value / 2);
        other = (u16) ((u32) other / 2);
    }
    value += other;
    *(u32 *) ((u8 *) arg2 + 0x14) = value;
    return value;
}
