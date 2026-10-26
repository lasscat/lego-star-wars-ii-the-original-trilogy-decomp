#include "m2c.h"

s8 func_02077174(void *);
s32 func_02086588(void *, s32);
s32 func_02086534(char *, s32);
s32 func_0208671c(short *, s32);
void func_02077d04(void *, s32);
void func_02077e60(s32, s32);
void func_02077f04(s32, s32);
void func_02077b7c(void *);
void func_0207788c(void *);
void func_020779a8(void *);
void func_02077a88(void *);

extern M2C_UNK data_02104d90;

typedef struct {
    u32 f_0;
    u8 pad[0x10];
} Rec;

extern Rec data_020eedb0[];
extern u32 data_020ee388[];
extern u32 data_020ee2f4[];

enum {
    MODE_OFFSET   = 0xD0,
    LABEL_BASE_A  = 0x1CB,
    LABEL_DEFAULT = 0x29A,
    LABEL_BASE_B  = 0x261,
    LABEL_BASE_C  = 0x243,
    BIAS_MODE0    = 0x16,
};

/* Refreshes the item widget for the current slot according to its mode byte. */
/* local names guessed from callers */
void func_02077414(void *arg0) {
    s8 idx;
    s32 tab_val;
    s32 bias;
    s32 bit;

    idx = func_02077174(arg0);
    if (M2C_FIELD(arg0, u8 *, MODE_OFFSET) == 1) {
        if (func_02086588(&data_02104d90, idx) == 0) {
            func_02077d04(arg0, 0);
        } else {
            func_02077d04(arg0, data_020eedb0[idx].f_0);
        }
        if (func_02086588(&data_02104d90, idx) != 0 || func_02086534(&data_02104d90, idx) != 0) {
            func_02077e60(arg0, idx + LABEL_BASE_A);
        } else {
            func_02077e60(arg0, LABEL_DEFAULT);
        }
        func_02077b7c(arg0);
    } else if (M2C_FIELD(arg0, u8 *, MODE_OFFSET) == 0 || M2C_FIELD(arg0, u8 *, MODE_OFFSET) == 2) {
        tab_val = data_020ee388[idx];
        bias    = 0;
        if (M2C_FIELD(arg0, u8 *, MODE_OFFSET) == 0) {
            tab_val = data_020ee2f4[idx];
            bias    = BIAS_MODE0;
        }
        bit = idx + bias;
        if (func_0208671c(&data_02104d90, bit) != 0) {
            func_02077d04(arg0, 0);
        } else {
            func_02077d04(arg0, tab_val);
        }
        if (M2C_FIELD(arg0, u8 *, MODE_OFFSET) == 0 && func_0208671c(&data_02104d90, bit) != 0) {
            func_02077f04(arg0, idx + LABEL_BASE_B);
        } else {
            func_02077e60(arg0, bit + LABEL_BASE_C);
        }
        if (M2C_FIELD(arg0, u8 *, MODE_OFFSET) == 0) {
            func_0207788c(arg0);
        } else {
            func_020779a8(arg0);
        }
    } else {
        func_02077a88(arg0);
    }
}
