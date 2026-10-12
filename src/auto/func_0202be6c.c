#include "m2c.h"

M2C_UNK func_02029520(void *);                      /* extern */
M2C_UNK func_0205d7d8(void *, M2C_UNK *);           /* extern */
extern M2C_UNK data_020fdc0c;
extern M2C_UNK data_02101b38;

void *func_0202be6c(void *arg0) {
    func_0205d7d8(arg0, &data_02101b38);
    M2C_FIELD(arg0, M2C_UNK **, 0) = &data_020fdc0c;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    M2C_FIELD(arg0, s32 *, 0x24) = 0;
    func_02029520(arg0 + 0x28);
    return arg0;
}
