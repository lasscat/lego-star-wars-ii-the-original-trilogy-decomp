#include "m2c.h"

extern u8 *data_020ece94[];
extern void func_02004b78(s32, u8);

typedef struct {
    s32 unk_0;
    s32 unk_4;
    u8 unk_8[4];
    u8 unk_c;
    u8 unk_d;
    u8 unk_e;
    u8 unk_f;
} Object;

void func_0202be00(Object *obj) {
    u8 value = data_020ece94[obj->unk_e][obj->unk_f];

    if (value == 5) {
        obj->unk_c |= 1;
    } else {
        func_02004b78(obj->unk_4, value);
        obj->unk_f++;
    }
}
