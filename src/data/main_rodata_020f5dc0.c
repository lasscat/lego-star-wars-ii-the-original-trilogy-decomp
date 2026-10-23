/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 data_020e6064[];
extern u8 data_020f52b4[];
extern u8 data_020f53d4[];

const u32 data_020f5dc0[7] = {0x00C9160C, 0x12020132,           0x1203FFFF,          0xFFFF1206,
                              0x00000002, (u32) &data_020f52b4, (u32) &data_020f53d4};
const u32 data_020f5ddc[8] = {(u32) &data_020e6064, 0x00000EAC, (u32) &data_020e6064, 0x00000EAD,
                              (u32) &data_020e6064, 0x00000EAE, (u32) &data_020e6064, 0x00000EAF};
