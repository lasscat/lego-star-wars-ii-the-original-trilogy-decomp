/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 NNSi_G3dAnmObjInitNsBca[];
extern u8 NNSi_G3dAnmObjInitNsBva[];
extern u8 func_020c73b4[];
extern u8 func_020c7808[];
extern u8 func_020c78e4[];

u32 data_02101320[1]  = {0x4D41004D};
u32 data_02101324[19] = {(u32) &func_020c73b4,
                         0x5450004D,
                         (u32) &func_020c78e4,
                         0x5441004D,
                         (u32) &func_020c7808,
                         0x56410056,
                         (u32) &NNSi_G3dAnmObjInitNsBva,
                         0x4341004A,
                         (u32) &NNSi_G3dAnmObjInitNsBca,
                         0x00000000,
                         0x00000000,
                         0x00000000,
                         0x00000000,
                         0x00000000,
                         0x00000000,
                         0x00000000,
                         0x00000000,
                         0x00000000,
                         0x00000000};
