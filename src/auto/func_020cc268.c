#include "m2c.h"
#include "engine.h"

void func_020ca56c(M2C_UNK);
void func_020cee9c(M2C_UNK);

extern s32 data_0210153c;
extern s32 data_02115384;

void func_020cc268(void) {
    if (data_0210153c != -1) {
        func_020cee9c(data_0210153c);
    }
    func_020ca56c(data_02115384);
    data_02115384 = 0;
}
