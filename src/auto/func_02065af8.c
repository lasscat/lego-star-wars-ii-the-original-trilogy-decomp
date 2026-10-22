#include "m2c.h"

/* func_02065af8 (0x02065af8, 0xf0 bytes)
 *
 * Copies one formatted field of the input string into a local buffer and
 * hands it to func_02065be8().  The '@' escape is passed through to the
 * buffer, but only one character is counted against the remaining width
 * (the counter at *arg7).  Afterwards a newline and any spaces in front of
 * the next field are skipped.
 */

s32 func_020658e4(void *, u8 *, s32);            /* extern */
s32 func_02065be8(M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */

s32 func_02065af8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 **arg5, s32 arg6, s32 *arg7) {
    u8 buf[96];
    u8 *p;
    u8 *end;
    u8 *d;
    u8 c;
    s32 ret = arg1;

    end = func_020658e4(arg0, *arg5, arg4);
    if (end != 0) {
        p = *arg5;
        d = buf;
        while (p != end && *arg7 != 0) {
            c = *p;
            if (c == '@') {
                p++;
                *d++ = c;
            }
            *d++  = *p++;
            *arg7 = *arg7 - 1;
        }
        *d    = 0;
        *arg5 = p;
        ret   = func_02065be8(arg0, arg1, arg2, arg3, (s32) buf, arg6);
        if (**arg5 == '\n') {
            *arg5 = *arg5 + 1;
        }
        while (**arg5 == ' ') {
            *arg5 = *arg5 + 1;
        }
    }
    return ret;
}
