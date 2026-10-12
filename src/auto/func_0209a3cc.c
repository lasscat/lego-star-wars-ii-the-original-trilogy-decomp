#include "m2c.h"
#include "engine.h"

void func_02072f94(void);
void func_0209a40c(M2C_UNK);
void func_0209aaa4(M2C_UNK);
void func_0209af38(M2C_UNK);
void func_0209b0b8(M2C_UNK);

void func_0209a3cc(s32 arg0) {
    s32 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s32 *, 0xE8);
    if (temp_r1 == 0) {
        func_0209b0b8(arg0);
    } else if (temp_r1 == 1) {
        func_0209af38(arg0);
    }
    func_0209aaa4(arg0);
    func_02072f94();
    func_0209a40c(arg0);
}
