#include "m2c.h"

M2C_UNK func_020cb098(void *);                      /* extern */
extern M2C_UNK data_0210a0ec;

void func_020acad0(s32 arg0, s32 arg1) {
    func_020cb098((M2C_UNK *)((s8 *)&data_0210a0ec + (arg1 << 5)));
}
