/* Reconstructed from USA ARM9 at 0x020771bc (600 bytes). */
#include "m2c.h"

s8 func_02077174(void *);                       /* extern */
s32 func_02086588(void *, s32);                   /* extern */
s32 func_02086534(char *, s32);                   /* extern */
s32 func_0208671c(short *, s32);                   /* extern */
void func_02077d04(void *, s32);               /* extern */
void func_02077e60(s32, s32);                  /* extern */
void func_02077f04(s32, s32);                  /* extern */
s32 func_02078030(s32, s32);                   /* extern */
void func_02086458(void *, s32);               /* extern */
s32 func_02085cb0(void *, M2C_UNK);            /* extern */
void func_02086654(void *, s32);               /* extern */
void func_020b8f70(M2C_UNK, M2C_UNK);          /* extern */
void func_02077414(void *);                    /* extern */

extern M2C_UNK data_02104d90;

typedef struct {
    u32 f_0;
    u8 pad[0x10];
} Rec;

extern Rec data_020eedb0[];
extern u32 data_020ee388[];
extern u32 data_020ee2f4[];

void func_020771bc(void *arg0, s32 arg1) {
    s8 var_r5;
    s32 var_r4;
    u32 var_r6;
    u32 temp_r1;
    s32 temp_idx;
    s32 var_off;

    var_r5 = func_02077174(arg0);
    if (M2C_FIELD(arg0, u8 *, 0xD0) == 1) {
        if (func_02086588(&data_02104d90, var_r5) == 0) {
            func_02077d04(arg0, 0);
        } else {
            func_02077d04(arg0, data_020eedb0[var_r5].f_0);
        }
        if (func_02086588(&data_02104d90, var_r5) != 0 || func_02086534(&data_02104d90, var_r5) != 0) {
            func_02077e60(arg0, var_r5 + 0x1CB);
        } else {
            func_02077e60(arg0, 0x29A);
        }
        if (M2C_FIELD(arg0, s8 *, 0xD2) != (arg1 & 0xFF)) {
            return;
        }
        if (func_02086588(&data_02104d90, var_r5) != 0) {
            if (func_02078030(arg0, data_020eedb0[var_r5].f_0) == 0) {
                return;
            }
            func_02086458(&data_02104d90, var_r5);
            func_02077d04(arg0, 0);
            func_02077414(arg0);
            func_02085cb0(&data_02104d90, 0);
            temp_idx = arg1 + 13;
            temp_r1  = ((u32 *) ((u8 *) arg0 + 0xDC))[temp_idx];
            M2C_FIELD(temp_r1, u32 *, 0x14) &= ~0xF000;
        } else {
            func_020b8f70(0xB7, 0);
        }
    } else {
        if (M2C_FIELD(arg0, u8 *, 0xD0) != 0 && M2C_FIELD(arg0, u8 *, 0xD0) != 2) {
            return;
        }
        var_r4  = data_020ee388[var_r5];
        var_off = 0;
        if (M2C_FIELD(arg0, u8 *, 0xD0) == 0) {
            var_r4  = data_020ee2f4[var_r5];
            var_off = 0x16;
        }
        var_r6 = var_r5 + var_off;
        if (func_0208671c(&data_02104d90, var_r6) != 0) {
            func_02077d04(arg0, 0);
        } else {
            func_02077d04(arg0, var_r4);
        }
        if (M2C_FIELD(arg0, u8 *, 0xD0) == 0 && func_0208671c(&data_02104d90, var_r6) != 0) {
            func_02077f04(arg0, var_r5 + 0x261);
        } else {
            func_02077e60(arg0, var_r6 + 0x243);
        }
        if (M2C_FIELD(arg0, s8 *, 0xD2) != (arg1 & 0xFF)) {
            return;
        }
        if (func_0208671c(&data_02104d90, var_r6) != 0) {
            return;
        }
        if (func_02078030(arg0, var_r4) == 0) {
            return;
        }
        func_02086654(&data_02104d90, var_r6);
        func_02077d04(arg0, 0);
        func_02077414(arg0);
        func_02085cb0(&data_02104d90, 0);
    }
}
