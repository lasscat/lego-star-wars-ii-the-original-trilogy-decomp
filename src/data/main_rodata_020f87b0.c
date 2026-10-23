/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 AllocatorAllocForExpHeap[];
extern u8 AllocatorAllocForSDKHeap[];
extern u8 AllocatorFreeForExpHeap[];
extern u8 AllocatorFreeForSDKHeap[];
extern u8 DoTransfer2dBGExtPlttMain[];
extern u8 DoTransfer2dBGPlttMain[];
extern u8 DoTransfer2dBGPlttSub[];
extern u8 DoTransfer2dObjCharMain[];
extern u8 DoTransfer2dObjCharSub[];
extern u8 DoTransfer2dObjExtPlttMain[];
extern u8 DoTransfer2dObjOamMain[];
extern u8 DoTransfer2dObjOamSub[];
extern u8 DoTransfer2dObjPlttMain[];
extern u8 DoTransfer2dObjPlttSub[];
extern u8 func_020c2bf0[];
extern u8 func_020c2c1c[];
extern u8 func_020c2c48[];
extern u8 func_020c2c6c[];
extern u8 func_020c2c90[];
extern u8 func_020c2c9c[];
extern u8 func_020c2ca8[];
extern u8 func_020c2cb4[];
extern u8 func_020c2cc0[];
extern u8 func_020c2ccc[];
extern u8 func_020c2cd8[];
extern u8 func_020c2ce4[];
extern u8 func_020c2cf0[];
extern u8 func_020c2cfc[];
extern u8 func_020c2d90[];
extern u8 func_020c2d9c[];
extern u8 func_020c2da8[];
extern u8 func_020c2db4[];
extern u8 func_020c2dc0[];
extern u8 func_020c2dcc[];
extern u8 func_020c2dd8[];
extern u8 func_020c2de4[];
extern u8 func_020c2df0[];
extern u8 func_020c2dfc[];
extern u8 func_020c2e20[];
extern u8 func_020c2e4c[];

const u32 data_020f87b0[4] = {(u32) &AllocatorAllocForExpHeap, (u32) &AllocatorFreeForExpHeap, (u32) &AllocatorAllocForSDKHeap,
                              (u32) &AllocatorFreeForSDKHeap};
const u32 data_020f87c0[36] = {(u32) &func_020c2bf0,
                               (u32) &func_020c2c1c,
                               (u32) &func_020c2c48,
                               (u32) &func_020c2c6c,
                               (u32) &func_020c2c90,
                               (u32) &func_020c2c9c,
                               (u32) &func_020c2ca8,
                               (u32) &func_020c2cb4,
                               (u32) &func_020c2cc0,
                               (u32) &func_020c2ccc,
                               (u32) &func_020c2cd8,
                               (u32) &func_020c2ce4,
                               (u32) &func_020c2cf0,
                               (u32) &func_020c2cfc,
                               (u32) &DoTransfer2dObjPlttMain,
                               (u32) &DoTransfer2dBGPlttMain,
                               (u32) &DoTransfer2dObjExtPlttMain,
                               (u32) &DoTransfer2dBGExtPlttMain,
                               (u32) &DoTransfer2dObjOamMain,
                               (u32) &DoTransfer2dObjCharMain,
                               (u32) &func_020c2d90,
                               (u32) &func_020c2d9c,
                               (u32) &func_020c2da8,
                               (u32) &func_020c2db4,
                               (u32) &func_020c2dc0,
                               (u32) &func_020c2dcc,
                               (u32) &func_020c2dd8,
                               (u32) &func_020c2de4,
                               (u32) &func_020c2df0,
                               (u32) &func_020c2dfc,
                               (u32) &DoTransfer2dObjPlttSub,
                               (u32) &DoTransfer2dBGPlttSub,
                               (u32) &func_020c2e20,
                               (u32) &func_020c2e4c,
                               (u32) &DoTransfer2dObjOamSub,
                               (u32) &DoTransfer2dObjCharSub};
