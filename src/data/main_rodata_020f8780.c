/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 AllocatorAllocForFrmHeap[];
extern u8 AllocatorAllocForUnitHeap[];
extern u8 func_020c2ad8[];
extern u8 func_020c2afc[];

const u32 data_020f8780[12] = {0x00000000,
                               0x00000001,
                               0x00000002,
                               0x00000003,
                               0x00000004,
                               0x00000005,
                               0x00000006,
                               0x00000007,
                               (u32) &AllocatorAllocForUnitHeap,
                               (u32) &func_020c2afc,
                               (u32) &AllocatorAllocForFrmHeap,
                               (u32) &func_020c2ad8};
