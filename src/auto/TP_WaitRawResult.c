#include "m2c.h"

typedef struct S8 {
    u16 f[4];
} S8;

M2C_UNK TP_WaitBusy(s32);
extern M2C_UNK data_02117450;

s32 TP_WaitRawResult(S8 *arg0) {
    TP_WaitBusy(1);
    if (M2C_FIELD(&data_02117450, u16 *, 0x38) & 1) {
        return 1;
    }
    *arg0 = *(S8 *) ((u8 *) &data_02117450 + 8);
    return 0;
}
