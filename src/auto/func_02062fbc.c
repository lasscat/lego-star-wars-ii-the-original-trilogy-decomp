#include "m2c.h"

extern void func_02054e58(s32 arg0);
extern s32 func_020c987c(s32 enable);
extern void OS_Terminate(void);

void func_02062fbc(void) {
    func_02054e58(1);
    func_020c987c(1);
    func_020c987c(1);
    OS_Terminate();
    while (1) {
    }
}
