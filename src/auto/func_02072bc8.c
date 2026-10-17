#include "m2c.h"

M2C_UNK func_0205ce5c(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0205cf50(M2C_UNK *);                   /* extern */
M2C_UNK func_0205e84c();                            /* extern */
M2C_UNK func_02073054(M2C_UNK);                     /* extern */
M2C_UNK func_020730d0(M2C_UNK);                     /* extern */
M2C_UNK func_020861bc(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020871f0(M2C_UNK *);                   /* extern */
M2C_UNK func_0209b7cc(s32);                         /* extern */
M2C_UNK func_020b11b0(s32);                         /* extern */
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02104d90;
extern M2C_UNK data_02106d90;
extern s32 data_021092f4;
extern void **data_0210b348;
extern s32 data_027e02a8;

void func_02072bc8(void) {
    func_0209b7cc(M2C_FIELD(&data_02106d90, s32 *, 0xAD0));
    M2C_FIELD(*data_0210b348, M2C_UNK(**)(), 4)(data_0210b348);
    if (M2C_FIELD(*data_0210b348, s32(**)(), 0x50)(data_0210b348) == 0) {
        M2C_FIELD(*data_0210b348, M2C_UNK(**)(), 8)(data_0210b348);
        do {

        } while (M2C_FIELD(*data_0210b348, s32(**)(), 0x50)(data_0210b348) == 0);
    }
    data_027e02a8 &= ~0x40;
    func_020861bc(&data_02104d90, 0xB, 0);
    if (data_021092f4 != 0) {
        func_0205e84c();
    }
    data_021092f4                         = 0;
    M2C_FIELD(&data_021027f8, s8 *, 0x2A) = 0;
    func_0205ce5c(&data_021027f8, 1);
    func_02073054(-1);
    func_020730d0(-1);
    func_0205cf50(&data_021027f8);
    func_020b11b0(M2C_FIELD(&data_02106d90, s32 *, 0xBB8));
    func_020871f0(&data_02104d90);
}
