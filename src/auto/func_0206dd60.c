#include "m2c.h"

M2C_UNK func_02053d90(M2C_UNK *);                   /* extern */
M2C_UNK func_02053ee8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02053f24(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02053f44(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02053f60(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02053f80(M2C_UNK *);                   /* extern */
M2C_UNK func_0206ae4c(s32);                         /* extern */
M2C_UNK func_0208d458(M2C_UNK *);                   /* extern */
M2C_UNK func_020c9ab4(M2C_UNK);                     /* extern */
M2C_UNK func_020ca724();                            /* extern */
s32 func_020ca890();                                /* extern */
s32 func_020ca8a0();                                /* extern */
M2C_UNK func_020ce878();                            /* extern */
extern M2C_UNK data_02101b78;
extern M2C_UNK data_02101b98;
extern M2C_UNK data_02104d18;
extern M2C_UNK data_02106d90;
extern M2C_UNK data_021093a0;

void func_0206dd60(void) {
    func_0206ae4c(M2C_FIELD(&data_02106d90, s32 *, 0xAD4));
    func_0208d458(&data_021093a0);
    func_02053f80(&data_02101b98);
    func_02053ee8(&data_02101b98, 0, 0);
    func_02053d90(&data_02101b98);
    M2C_FIELD(&data_02104d18, s32 *, 0) = func_020ca8a0();
    func_020ca724();
    *(s32 *)0x04000064 = 0x80360808;
    func_020ce878();
    func_020ce878();
    func_02053f24(&data_02101b78, 5);
    func_02053f60(&data_02101b78, 0x200);
    func_02053f44(&data_02101b78, 0x400);
    func_02053d90(&data_02101b78);
    M2C_FIELD(&data_02104d18, s32 *, 4) = func_020ca890();
    func_020c9ab4(4);
    *(u16 *)0x0400000C = (*(u16 *)0x0400000C & 0x43) | 0x6284;
    *(u16 *)0x0400000C = (*(u16 *)0x0400000C & ~3) | 2;
}
