#include "m2c.h"

/* data_021044a4 is the shared timer/state block: one-bit flags in byte 0. */
struct S_0209f04c_Data {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};
typedef struct {
    u8 pad[0x28];
    s32 f28;
    s32 f2c;
    u8 f30;
    u8 pad2[0x37];
    void *f68[4];
} S_0209f04c_Self;

extern struct S_0209f04c_Data data_021044a4;
void func_0201b318(void *arg0, u8 arg1);
s32 func_020648e4(void *arg0, void *arg1, void *arg2);

void func_0209f04c(S_0209f04c_Self *obj) {
    s32 i;
    s32 a[2], b[2];
    s32 dx, dy;
    for (i = 0; i < 4; i++) {
        func_0201b318(obj->f68[i], 0);
    }
    obj->f30 = 0;
    if (data_021044a4.b2 == 0) {
        return;
    }
    a[0] = 0;
    a[1] = 0;
    b[0] = 0;
    b[1] = 0;
    if (func_020648e4(&data_021044a4, a, b) == 0) {
        return;
    }
    obj->f30 = 1;
    dx       = a[0] - b[0];
    dy       = a[1] - b[1];
    obj->f28 = dx;
    obj->f2c = dy;
    if (obj->f28 < 0) {
        func_0201b318(obj->f68[3], 1);
    }
    if (obj->f28 > 0) {
        func_0201b318(obj->f68[2], 1);
    }
    if (obj->f2c > 0) {
        func_0201b318(obj->f68[0], 1);
    }
    if (obj->f2c < 0) {
        func_0201b318(obj->f68[1], 1);
    }
}
