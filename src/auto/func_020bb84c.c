#include "m2c.h"

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04[0x14];
    s32 f18;
} SndCmd;

typedef struct {
    u8 f00[8];
    u8 f08;
    u8 f09[0x13];
} SndSlot;

extern SndCmd data_0210dd7c;
extern SndSlot data_0210dd98[];

extern s32 func_020bb388(s32, s32);
extern void func_020bb3f8(s32, s32);
extern void func_020bada8(M2C_UNK, M2C_UNK);
extern void func_020baef0(void *);
extern void SND_WaitForFreeCommand(s32);
extern void SND_StartTimer(M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern s32 SND_GetCurrentCommandTag(void);

void func_020bb84c(void) {
    s32 i;
    SndSlot *slot;
    SndCmd *cmd;
    s32 arg;

    cmd = &data_0210dd7c;
    for (i = 11; i >= 0; i--) {
        if (cmd->f01 == 4) {
            slot = &data_0210dd98[cmd->f00];
            if (slot->f08 & 0x10) {
                arg = 0xFF;
            } else {
                arg = cmd->f03 + 0xBE;
            }
            cmd->f01 = 3;
            cmd->f02 = func_020bb388(i | 0x20, arg);
            if (cmd->f02 != 0xFF) {
                func_020bb3f8(cmd->f02, i | 0x20);
                SND_WaitForFreeCommand(4);
                func_020bada8(cmd->f02, slot);
                func_020baef0(cmd);
                SND_StartTimer(1 << cmd->f02, 0, 0, 0);
                cmd->f18 = SND_GetCurrentCommandTag();
            } else {
                cmd->f01 = 1;
            }
        }
        cmd--;
    }
}
