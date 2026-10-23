#include "m2c.h"

class Obj552AC {
public:
    virtual void unknown00();
    virtual void unknown04(void *); // Slot 0x04.
};

extern "C" s32 func_0201aaec(void);

extern "C" void func_020552ac(s32 arg0, Obj552AC *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5) {
    s32 buf[6];
    s32 *p = buf;

    do {
        *p++ = 0;
    } while (p < buf + 6);
    arg1->unknown04(buf);
    *arg2 = buf[0] >> (func_0201aaec() + 5);
    *arg3 = buf[1] >> (func_0201aaec() + 5);
    *arg4 = buf[4] >> (func_0201aaec() + 5);
    *arg5 = buf[5] >> (func_0201aaec() + 5);
}
