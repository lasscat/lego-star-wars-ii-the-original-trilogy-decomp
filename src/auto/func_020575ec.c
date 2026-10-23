/* Reconstructed from USA ARM9 at 0x020575ec (132 bytes).
 * Names and types are inferred from the binary.
 *
 * The value of each axis is stored twice before the call that consumes it:
 * once into the slot that is read back after the call (sp8/sp4/sp0) and once
 * into a slot that is never read again (sp14/sp10/spC).  The write-only slots
 * are modelled as volatile locals so the compiler keeps them, the same
 * technique used by the already matched siblings func_02057788 / func_020577e0.
 */
#include "m2c.h"

void *func_020aaeb4(void);                              /* extern */

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 flag;
} Ang;

void func_020575ec(s32 arg0, Ang *arg1) {
    volatile s32 sp14;
    volatile s32 sp10;
    volatile s32 spC;
    volatile s32 sp8;
    volatile s32 sp4;
    volatile s32 sp0;
    u8 flag;
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    flag                                    = arg1->flag;
    M2C_FIELD(func_020aaeb4(), u8 *, 0x242) = flag;
    if (arg1->flag == 0) {
        return;
    }
    temp_r0                                  = arg1->z << 12;
    sp8                                      = temp_r0;
    sp14                                     = temp_r0;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x244) = sp8;
    temp_r0_2                                = arg1->y << 12;
    sp4                                      = temp_r0_2;
    sp10                                     = temp_r0_2;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x248) = sp4;
    temp_r0_3                                = arg1->x << 12;
    sp0                                      = temp_r0_3;
    spC                                      = temp_r0_3;
    M2C_FIELD(func_020aaeb4(), s32 *, 0x24c) = sp0;
}
