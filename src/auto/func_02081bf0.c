#include "m2c.h"

extern void func_02067c30(void *arg0);
extern void func_02081eac(void *arg0, s32 arg1);
extern u8 data_020f020c[];

void func_02081bf0(void *arg0, s32 arg1) {
    s32 v;

    v = *(s32 *) ((u8 *) arg0 + 0x124);
    if (v != 0) {
        if (v < 0) {
            v = -v;
        }
        if (v < 0x12) {
            *(s32 *) ((u8 *) arg0 + 0x12c) = arg1;
        }
        return;
    }

    if (arg1 == -1) {
        if (*(s32 *) ((u8 *) arg0 + 4 * *(s32 *) ((u8 *) arg0 + 0x108) + 0x10c) <= 0) {
            return;
        }
        func_02067c30((u8 *) arg0 + 0x60);
        func_02067c30((u8 *) arg0 + 0x68);
        ((s32 *) ((u8 *) arg0 + 0x10c))[*((s32 *) ((u8 *) arg0 + 0x108))] =
            ((s32 *) ((u8 *) arg0 + 0x10c))[*((s32 *) ((u8 *) arg0 + 0x108))] - 1;
        *(s32 *) ((u8 *) arg0 + 0x124) = 0x25;
        func_02081eac(arg0, *(s32 *) ((u8 *) arg0 + 4 * *(s32 *) ((u8 *) arg0 + 0x108) + 0x10c));
    } else if (arg1 == 1) {
        s32 lim;

        if (*(s32 *) ((u8 *) arg0 + 0x108) == 5) {
            lim = *(s32 *) ((u8 *) arg0 + 0x160);
        } else {
            lim = *(s32 *) ((u8 *) arg0 + 4 * data_020f020c[*(s32 *) ((u8 *) arg0 + 0x108)] + 0x148);
        }
        if (lim <= 2 * (*(s32 *) ((u8 *) arg0 + 4 * *(s32 *) ((u8 *) arg0 + 0x108) + 0x10c) + 3)) {
            return;
        }
        func_02067c30((u8 *) arg0 + 0x60);
        func_02067c30((u8 *) arg0 + 0x68);
        ((s32 *) ((u8 *) arg0 + 0x10c))[*((s32 *) ((u8 *) arg0 + 0x108))] =
            ((s32 *) ((u8 *) arg0 + 0x10c))[*((s32 *) ((u8 *) arg0 + 0x108))] + 1;
        *(s32 *) ((u8 *) arg0 + 0x124) = -0x25;
        func_02081eac(arg0, *(s32 *) ((u8 *) arg0 + 4 * *(s32 *) ((u8 *) arg0 + 0x108) + 0x10c) + 2);
    }
}
