#include "m2c.h"

typedef struct {
    u16 v;
    u8 b;
    u8 pad;
} Ent;

extern M2C_UNK data_020edca2;
extern M2C_UNK data_020edca4;

u8 func_02066c18(u32 arg0) {
    u32 var_ip;

    if (arg0 == 0) {
        return 0U;
    }
    for (var_ip = 0; var_ip < 0x3FU; var_ip++) {
        if (arg0 == ((Ent *) &data_020edca2)[var_ip].v) {
            return ((u8 *) &data_020edca4)[var_ip * 4];
        }
    }
    if (((arg0 >= 0x20U) && (arg0 <= 0x7AU)) || (arg0 == 0xAU)) {
        return (u8) arg0;
    }
    return 0x2DU;
}
