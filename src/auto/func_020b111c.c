#include "m2c.h"

M2C_UNK func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32);
M2C_UNK func_02072bc8();
M2C_UNK func_020861bc(M2C_UNK *, M2C_UNK);
M2C_UNK func_02088b84(M2C_UNK *, u8);
u32 func_020917b4(M2C_UNK *);
extern M2C_UNK data_02102900;
extern M2C_UNK data_02104d90;
extern M2C_UNK data_02104df4;
extern M2C_UNK data_0210930c;

void func_020b111c(void *arg0, s32 arg1) {
    if ((M2C_FIELD(arg0, u8 *, 8) != 0) && (arg1 != 0)) {
        func_02088b84(&data_02104df4, func_020917b4(&data_0210930c));
        func_0205ecc4(&data_02102900, 4, 0, 0xE, (s32) func_020917b4(&data_0210930c), 0);
    }
    func_02072bc8();
    M2C_FIELD(arg0, s8 *, 6)   = 0;
    M2C_FIELD(arg0, s8 *, 7)   = 0;
    M2C_FIELD(arg0, u8 *, 8)   = 0U;
    M2C_FIELD(arg0, s8 *, 0xD) = 0;
    func_020861bc(&data_02104d90, 0xB);
}
