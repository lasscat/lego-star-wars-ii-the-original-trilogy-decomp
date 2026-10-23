/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 data_020e6064[];
extern u8 data_020f5158[];
extern u8 data_020f5180[];

const u32 data_020f55ac[6] = {(u32) &data_020e6064, 0x00000660,           (u32) &data_020e6064,
                              0x00000661,           (u32) &data_020e6064, 0x00000662};
const u32 data_020f55c4[7] = {0x00C9190F, 0x15A90032,           0x15ABFFFF,          0xFFFFFFFF,
                              0x00000001, (u32) &data_020f5158, (u32) &data_020f5180};
