#include "m2c.h"

typedef struct {
    u8 pad[8];
    u8 language : 7;
    u8 loaded : 1;
} Settings;

extern void OS_GetOwnerInfo(void *);
extern void func_0205ab1c(u16);
extern void func_0205ab6c(u16);
extern void func_0205ccf8(void);

extern Settings data_02104364;
extern u8 data_020edda0[];
extern u16 data_020edca0[];
extern u8 data_02104914[];

void func_02066634(s32 arg0) {
    u8 info[0x50];
    s32 cur;

    if (!data_02104364.loaded) {
        OS_GetOwnerInfo(info);
        arg0                   = data_020edda0[info[0]];
        data_02104364.language = arg0;
        data_02104364.loaded   = 1;
    }
    if (arg0 >= 1) {
        arg0 = 0;
    }
    cur = data_02104914[0];
    if (cur != arg0) {
        if (cur != 1) {
            func_0205ab6c(data_020edca0[cur]);
        }
        func_0205ab1c(data_020edca0[arg0]);
        func_0205ccf8();
        data_02104914[0] = arg0;
    }
    data_02104914[1] = 0x2c;
}
