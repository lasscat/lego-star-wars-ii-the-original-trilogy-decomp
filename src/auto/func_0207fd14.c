#include "m2c.h"

M2C_UNK func_0200171c(M2C_UNK);                     /* extern */
M2C_UNK func_02053ee8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02053f44(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02068148(M2C_UNK *);                   /* extern */
M2C_UNK func_02090ae8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02091310(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02093690(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020a99bc(s32, M2C_UNK);                /* extern */
s32 func_020aaeb4();                                /* extern */
M2C_UNK func_020ac278(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b3ab0(M2C_UNK *);                   /* extern */
M2C_UNK G3X_SetClearColor(M2C_UNK, M2C_UNK, s32, M2C_UNK, s32); /* extern */
extern M2C_UNK data_02101b78;
extern M2C_UNK data_021027f8;
extern M2C_UNK data_0210930c;
extern M2C_UNK data_02109358;
extern M2C_UNK data_027e0864;
extern M2C_UNK data_027e0874;
extern M2C_UNK data_027e0bd0;

void func_0207fd14(void *arg0) {
    func_020ac278(&data_027e0874, 2, 0x1800);
    func_0200171c(1);
    func_02053ee8(&data_02101b78, 0, 1);
    func_02053f44(&data_02101b78, 0x1100);
    G3X_SetClearColor(0, 0, 0x7FFF, 0x3F, 0);
    func_020a99bc(func_020aaeb4(), 0);
    func_02068148(&data_027e0864);
    func_020b3ab0(&data_027e0bd0);
    func_02090ae8(&data_0210930c, 0xF, 1);
    func_02091310(&data_0210930c, 0);
    func_02093690(&data_0210930c, *((M2C_UNK *) ((s8 *) &data_02109358 + (M2C_FIELD(&data_021027f8, u8 *, 0x2A) * 4))));
    M2C_FIELD(arg0, s8 *, 0x28) = 1;
}
