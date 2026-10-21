#include "m2c.h"
void func_02059ec0(u16 *arr, u32 n) {
    u32 i;
    for (i = 1; i < (n >> 1); i++) {
        arr[i] += arr[i - 1];
    }
}
