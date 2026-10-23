/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 NNSi_G3dGetJointScaleBasic[];
extern u8 NNSi_G3dGetJointScaleMaya[];
extern u8 func_020c800c[];

u32 G3d_gScaleHandlers[3]   = {(u32) &NNSi_G3dGetJointScaleBasic, (u32) &NNSi_G3dGetJointScaleMaya, 0x00000000};
u32 G3d_gTextureHandlers[4] = {(u32) &func_020c800c, 0x00000000, 0x00000000, 0x00000000};
