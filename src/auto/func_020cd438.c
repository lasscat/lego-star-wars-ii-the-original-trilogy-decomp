#include "m2c.h"

M2C_UNK func_020cd014(s32, void *);                 /* extern */
M2C_UNK func_020cd0f8(void *);                      /* extern */
M2C_UNK func_020cd4e4(void *);                      /* extern */
M2C_UNK func_020cd59c();                            /* extern */
M2C_UNK func_020cd74c();                            /* extern */
M2C_UNK func_020cd780();                            /* extern */
M2C_UNK func_020cdbcc(void *);                      /* extern */
M2C_UNK func_020cea74();                            /* extern */
extern M2C_UNK data_02115424;

void func_020cd438(void) {
    s32 temp_r0;
    void *temp_r4;

    temp_r4 = *M2C_FIELD(&data_02115424, void ***, 8);
    func_020cd74c();
    func_020cdbcc(temp_r4);
    temp_r0 = M2C_FIELD(temp_r4, s32 *, 0x78);
    if (temp_r0 != 0) {
        func_020cd014(temp_r0, temp_r4);
    }
    func_020cd0f8(temp_r4);
    M2C_FIELD(temp_r4, s32 *, 0x64) = 2;
    func_020cd4e4(temp_r4 + 0x9C);
    func_020cd780();
    func_020cd59c();
    func_020cea74();
}
