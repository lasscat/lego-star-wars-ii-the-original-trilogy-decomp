#include "m2c.h"

typedef struct {
    s32 v;
} UnkVal;

void func_02012744(void *arg0, UnkVal arg1);

void func_02026138(void *arg0, UnkVal arg1, ...) {
    func_02012744(arg0, arg1);
}
