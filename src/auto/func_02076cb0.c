#include "m2c.h"

/* Record of the table at data_020eedac: 20 bytes each, the first byte is the
   kind (6 means "skip this entry").  See func_02086278 / func_02086330. */
typedef struct {
    u8 kind;
    u8 pad_01[0x13];
} Rec_02076cb0;

extern Rec_02076cb0 data_020eedac[];

void func_02076cb0(u8 *buf) {
    s32 i;
    s32 idx = 0;

    for (i = 0; i < 7; i++) {
        buf[i] = i;
        while (data_020eedac[idx].kind == 6) {
            idx++;
        }
        buf[i + 7]   = idx;
        buf[i + 0xe] = i;
        idx++;
    }
    for (i = 0; i < 6; i++) {
        buf[i + 0x15] = 0;
    }
}
