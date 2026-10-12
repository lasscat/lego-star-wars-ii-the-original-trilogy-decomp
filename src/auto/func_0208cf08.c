#include "m2c.h"

M2C_UNK func_02063c18(M2C_UNK *);                   /* extern */
M2C_UNK func_02068268(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0207f4c8(s32);                         /* extern */
M2C_UNK func_0208ac98(void *);                      /* extern */
M2C_UNK func_0208cfdc();                            /* extern */
M2C_UNK func_02090d58(M2C_UNK *);                   /* extern */
M2C_UNK func_020b9c64(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104434;
extern s32 data_02104d90;
extern M2C_UNK data_02106d90;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_0210db30;
extern M2C_UNK data_027e0864;

void func_0208cf08(void *arg0) {
    data_02104d90 &= ~2;
    func_0207f4c8(M2C_FIELD(&data_02106d90, s32 *, 0xAD8));
    func_0208cfdc();
    if (M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xAD0), s32 *, 8) != 0) {
        M2C_FIELD(M2C_FIELD(&data_02106d90, void **, 0xAD0), s32 *, 8) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 8) != 0x10) {
        func_0208ac98(arg0 + 0x2C);
    }
    func_02090d58(&data_0210930c);
    func_02063c18(&data_02104434);
    func_020b9c64(&data_0210db30);
    if (M2C_FIELD(&data_02102900, s32 *, 0x48) == 4) {
        return;
    }
    func_02068268(&data_027e0864, 0xC9);
}
