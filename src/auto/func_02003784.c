#include "m2c.h"

u8 func_02003948(s32, const u8 *);                  /* extern */
u8 func_02003970(s32, const u8 *);                  /* extern */
u32 func_02062ae4(s32);                             /* extern */
void func_02004404(M2C_UNK, M2C_UNK);               /* extern */
void func_020063d4(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
extern u8 *data_020ee838[4][6];

void func_02003784(void *arg0, s32 arg1, void *arg2) {
    u16 idx = (u16) (arg1 - 0x50);
    u8 *str;
    u8 ch;
    u32 n;

    str = data_020ee838[idx][0];
    if (str != NULL) {
        n                            = func_02003948((s32) arg0, str);
        n                            = (u16) (n - 1);
        n                            = func_02062ae4(n);
        ch                           = str[n];
        M2C_FIELD(arg0, u8 *, 0x6c3) = ch;
        func_02004404(arg0, ch);
    }

    str = data_020ee838[idx][1];
    if (str != NULL) {
        n = func_02003970((s32) arg0, str);
        if (n != 0) {
            n  = (u16) (n - 1);
            n  = func_02062ae4(n);
            ch = str[n];
            func_020063d4(arg0, ch, arg2);
        }
    }

    str = data_020ee838[idx][2];
    if (str != NULL) {
        n = func_02003970((s32) arg0, str);
        if (n != 0) {
            n  = (u16) (n - 1);
            n  = func_02062ae4(n);
            ch = str[n];
            func_020063d4(arg0, ch, arg2);
        }
    }

    str = data_020ee838[idx][3];
    if (str != NULL) {
        n = func_02003970((s32) arg0, str);
        if (n != 0) {
            n  = (u16) (n - 1);
            n  = func_02062ae4(n);
            ch = str[n];
            func_020063d4(arg0, ch, arg2);
        }
    }

    str = data_020ee838[idx][4];
    if (str != NULL) {
        n = func_02003970((s32) arg0, str);
        if (n != 0) {
            n  = (u16) (n - 1);
            n  = func_02062ae4(n);
            ch = str[n];
            func_020063d4(arg0, ch, arg2);
        }
    }

    str = data_020ee838[idx][5];
    if (str == NULL) {
        return;
    }
    n = func_02003970((s32) arg0, str);
    if (n == 0) {
        return;
    }
    {
        u32 m = func_02062ae4(n);
        if (m == n) {
            return;
        }
        ch = str[m];
        func_020063d4(arg0, ch, arg2);
    }
}
