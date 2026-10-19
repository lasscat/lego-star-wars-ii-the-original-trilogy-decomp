#include "m2c.h"
typedef struct {
    u16 a;
    u8 b;
    u8 c;
} E;
extern E data_020edca2[];

u32 func_02066bbc(u32 arg0) {
    u32 i;
    if (arg0 == 0) {
        return 0;
    }
    for (i = 0; i < 0x3f; i++) {
        if (arg0 == data_020edca2[i].b) {
            return data_020edca2[i].a;
        }
    }
    if (arg0 >= 0x20U && arg0 <= 0x7AU) {
        return arg0;
    }
    switch (arg0) {
        case 0xAU:
            return arg0;
        default:
            return 0x2DU;
    }
}
