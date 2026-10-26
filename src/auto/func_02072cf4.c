#include "m2c.h"

extern s32 data_027e02a8;
extern u8 data_021079b8;
extern u8 data_02104d90[];
extern u8 data_02107950[];
extern u8 data_02102900[];
extern void **data_021092f4;
extern u8 data_021027f8[];

void func_0205ecc4(void *, s32, s32, s32, s32, s32);

enum {
    FLAG_BIT_0x40 = 0x40,
    MODE_0        = 0,
    MODE_3        = 3,
};

/* Sets bit 0x40 in the dtcm flags word, resets the state, then queues
   func_0205ecc4 requests chosen by mode (0, 3 or other); finally stores the
   byte returned by virtual slot 0x1C of the data_021092f4 object into
   data_021027f8[0x2A]. */
void func_02072cf4(s32 mode) {
    u8 *flag /* name guessed from usage */ = &data_021079b8;
    *flag                                  = 0;
    data_027e02a8 |= FLAG_BIT_0x40;
    func_020861bc((s32) data_02104d90, 0xB, 1);
    func_0208d218(data_02107950);
    if (mode == MODE_0) {
        func_0205ecc4(data_02102900, 0x28, 1, 0, 0, 0);
    } else if (mode != MODE_3) {
        func_0205ecc4(data_02102900, 0xF, 0, 0, 0, 0);
        func_0205ecc4(data_02102900, 0x36, 1, mode, 0, 0);
    } else {
        *flag = 1;
        func_0205ecc4(data_02102900, 4, 0, 0x10, 9, 0);
        func_0205ecc4(data_02102900, 0x29, 1, 0, 0, 0);
    }
    data_021027f8[0x2A] = M2C_FIELD(M2C_FIELD(data_021092f4, void **, 0), u8(**)(), 0x1C)(data_021092f4);
}
