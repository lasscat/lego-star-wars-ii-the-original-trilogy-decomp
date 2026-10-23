#include "m2c.h"

typedef s32 fx32;

fx32 func_020c93c8(fx32 num, fx32 mod);

typedef struct {
    s32 hours;
    s32 minutes;
    s32 seconds;
} TimeStruct;

void func_020bb964(TimeStruct *out, s32 *in) {
    TimeStruct t;
    s32 v = *in;
    fx32 secs;
    fx32 rem;

    if (v < 0) {
        secs = func_020c93c8(v + 0x80000000, 86400);
    } else {
        secs = func_020c93c8(v + 0x2D7F, 86400);
    }
    rem       = func_020c93c8(secs, 3600);
    t.hours   = secs / 3600;
    t.minutes = rem / 60;
    t.seconds = func_020c93c8(rem, 60);
    *out      = t;
}
