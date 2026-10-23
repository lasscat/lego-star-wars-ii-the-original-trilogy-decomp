#include "m2c.h"
extern void func_020ad528(char *a, ...);
extern void func_020ad8b4(s32);
extern void func_020ad7a4(s32);
extern s32 func_020aeca8(void);
extern s32 WM_StartDataSharing(void *, s32, s32, s32, s32);
extern char data_0210014c[];
extern char data_0210035c[];
extern char data_02100384[];
extern u8 data_0210b720[];
extern u8 data_0210b320[];
void func_020aeba4(void *arg0) {
    u16 v = M2C_FIELD(arg0, u16 *, 2);
    if (v != 0) {
        if (v == 0xf || v == 9 || v == 0xd) {
            return;
        }
        func_020ad8b4(v);
        return;
    }
    switch (M2C_FIELD(arg0, u16 *, 4) - 10) {
        case 0:
            if (M2C_FIELD(&data_0210b320, s32 *, 0x44) == 3) {
                if (M2C_FIELD(&data_0210b320, s32 *, 0x20) == 6) {
                    return;
                }
                if (M2C_FIELD(&data_0210b320, s32 *, 0x20) == 4) {
                    if (func_020aeca8() != 0) {
                        return;
                    }
                    func_020ad528(data_0210035c);
                    return;
                }
            } else if (M2C_FIELD(&data_0210b320, s32 *, 0x44) == 5) {
                s32 r = WM_StartDataSharing(data_0210b720, 0xd, 0xf, 0x7c, M2C_FIELD(&data_0210b320, u8 *, 0));
                if (r != 0) {
                    func_020ad8b4(r);
                    return;
                }
                func_020ad528(data_02100384);
                func_020ad7a4(5);
                return;
            }
            func_020ad7a4(4);
            return;
        case 2:
        case 3:
            break;
        case 1:
        default:
            func_020ad528(data_0210014c, *((u16 *) arg0 + 2));
            break;
    }
}
