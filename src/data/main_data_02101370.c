/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 NNSi_G3dSendJointSRTBasic[];
extern u8 NNSi_G3dSendJointSRTMaya[];

u32 G3d_gSRTTransformHandlers[3] = {(u32) &NNSi_G3dSendJointSRTBasic, (u32) &NNSi_G3dSendJointSRTMaya, 0x00000000};
