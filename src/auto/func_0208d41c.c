#include "m2c.h"

typedef struct {
    u16 v;
} H;

extern H data_020f1f6c[];
extern void func_020534f4(M2C_UNK, M2C_UNK, M2C_UNK, H);
extern void func_0208d478(M2C_UNK, M2C_UNK);

void func_0208d41c(M2C_UNK arg0) {
    func_020534f4(arg0, 0, 3, data_020f1f6c[0]);
    func_0208d478(arg0, 3);
}
