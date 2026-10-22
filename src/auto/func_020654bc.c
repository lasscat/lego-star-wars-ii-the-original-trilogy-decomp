#include "m2c.h"

extern u8 data_021047fc[];
extern u32 data_020edc7c[];

M2C_UNK func_0205ab30(u16);

void func_020654bc(u32 arg0, u32 arg1) {
    u8 *entry;
    u32 obj;
    u32 v;

    entry = (data_021047fc + arg0 * 0x38) + arg1 * 0x1c;
    obj   = (u32) func_0205ab30(*(u16 *) entry);
    if (*(u16 *) (entry + 2) == 0) {
        *(u32 *) (entry + 4)    = obj;
        *(u16 *) (entry + 0xa)  = *(u16 *) obj;
        *(u16 *) (entry + 0xc)  = *(u16 *) (obj + 2);
        *(u8 *) (entry + 8)     = *(u8 *) (obj + 4);
        *(u8 *) (entry + 0xe)   = (u8) data_020edc7c[arg0 * 2];
        v                       = *(u8 *) (obj + 7) + (*(u8 *) (obj + 6) << 8);
        *(u32 *) (entry + 0x10) = obj + v;
        v                       = *(u8 *) (obj + 0xb) + (*(u8 *) (obj + 0xa) << 8);
        *(u32 *) (entry + 0x14) = obj + v;
        v                       = *(u8 *) (obj + 0xf) + (*(u8 *) (obj + 0xe) << 8);
        *(u32 *) (entry + 0x18) = obj + v;
    }
    *(u16 *) (entry + 2) = *(u16 *) (entry + 2) + 1;
}
