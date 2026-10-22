#include "m2c.h"

typedef struct {
    u8 f00;
    u8 f01;
    u8 f02;
    u8 f03;
    u8 f04;
    u8 f05;
    u8 f06 : 1;
    u8 f06b : 7;
    u8 f07;
    u8 pad08[8];
    u32 f10;
    u32 f14;
    u32 f18;
} SndCmd;

typedef struct {
    u8 f00[0x1C];
} SndSlot;

extern SndCmd data_0210dd7c;
extern SndSlot data_0210dd98[];

extern s32 SND_IsFinishedCommandTag(s32);
extern u16 SND_GetChannelStatus(void);
extern void SND_WaitForCommandProc(M2C_UNK);
extern void func_020ba9b0(void *);
extern void func_020baef0(M2C_UNK);
extern void func_020bb488(s32, s32);

void func_020bb26c(void) {
    s32 i;
    SndCmd *cmd;

    i   = 0xB;
    cmd = &data_0210dd7c;
    do {
        switch (cmd->f01) {
            case 3:
                if ((SND_IsFinishedCommandTag(cmd->f18) == 1) && ((SND_GetChannelStatus() & (1 << cmd->f02)) == 0)) {
                    func_020bb488(cmd->f02, i | 0x20);
                    func_020ba9b0(&data_0210dd98[cmd->f00]);
                    cmd->f01 = 0;
                } else if (cmd->f06) {
                    func_020baef0(cmd);
                }
                break;
            case 1:
                if (SND_IsFinishedCommandTag(cmd->f18) == 1) {
                    func_020ba9b0(&data_0210dd98[cmd->f00]);
                    cmd->f01 = 0;
                }
                break;
            case 2:
                SND_WaitForCommandProc(cmd->f18);
                func_020ba9b0(&data_0210dd98[cmd->f00]);
                cmd->f01 = 0;
                break;
            case 0:
                break;
            case 4:
                break;
        }
        cmd--;
        i -= 1;
    } while (i >= 0);
}
