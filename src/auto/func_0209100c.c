#include "m2c.h"

typedef struct {
    u16 e[7];
} A7;

extern A7 data_020f50ce;
extern u16 data_020f50cc;

void func_0205ab1c(M2C_UNK);
void func_0205ab6c(M2C_UNK);
void func_020b938c(M2C_UNK);
void func_020b93e0(M2C_UNK);

void func_0209100c(void *arg0, s32 arg1) {
    volatile u16 head;
    A7 v;
    u32 i;

    v    = data_020f50ce;
    head = data_020f50cc;

    if (arg1 != 0) {
        for (i = 0; i < 7; i++) {
            func_0205ab1c(v.e[i]);
        }
        func_020b938c(head);
    } else {
        for (i = 0; i < 7; i++) {
            func_0205ab6c(v.e[i]);
        }
        func_020b93e0(head);
    }
}
