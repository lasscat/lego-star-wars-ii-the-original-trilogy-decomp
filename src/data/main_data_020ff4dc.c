#include "m2c.h"
extern u8 data_020f1f9c[];
extern u8 data_020f1fce[];
extern u8 data_020f1f8c[];
extern u8 data_020f1f70[];
extern u8 data_020f1f80[];
extern u8 data_020f1f74[];
u32 data_020ff4dc[7] = {(u32) &data_020f1fce,
                        (u32) ((u8 *) &data_020f1f80 + 0x6),
                        (u32) &data_020f1f74,
                        (u32) &data_020f1f80,
                        (u32) &data_020f1f70,
                        (u32) &data_020f1f8c,
                        (u32) ((u8 *) &data_020f1f9c + 0xe)};
