#include "m2c.h"

void func_0201b254(s32, u8);

typedef struct {
    s32 *array;
    u16 count;
} Obj;

void func_0205ea84(Obj *obj, s32 arg1) {
    u32 i;
    for (i = 0; i < obj->count; i++) {
        s32 p = obj->array[i];
        if (p != 0) {
            func_0201b254(p, (u8) arg1);
        }
    }
}
