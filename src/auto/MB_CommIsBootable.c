#include "engine.h"
#include "m2c.h"

M2C_UNK IsChildAidValid(M2C_UNK);

extern s32 mbc;

s32 MB_CommIsBootable(s32 arg0) {
    if ((mbc != 0) && (IsChildAidValid(arg0) != 0) && (M2C_FIELD((mbc + ((arg0 - 1) * 4)), s32 *, 0x14E8) == 7)) {
        return 1;
    }
    return 0;
}
