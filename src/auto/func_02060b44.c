#include "m2c.h"

typedef struct {
    u32 v;
} Word;

typedef struct {
    Word w[2];
} Entry;

typedef struct {
    Entry entries[0x80];
    u8 rest[0x324];
} Screen;

extern Word data_020edc50[];
extern Screen data_02103374[];
extern u8 data_02103a95[];

void func_0205e724(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);

void func_02060b44(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x80; i++) {
        data_02103374[arg0].entries[i].w[0] = data_020edc50[0];
        data_02103374[arg0].entries[i].w[1] = data_020edc50[1];
    }
    func_0205e724(3, &data_02103374[arg0], (arg0 << 10) + 0x7000000, 0x400, 0x20);
    data_02103a95[arg0 * 0x724] = 0;
}
