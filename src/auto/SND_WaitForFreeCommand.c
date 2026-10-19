#include "m2c.h"

s32 SND_RecvCommandReply(M2C_UNK);                         /* extern */
M2C_UNK SND_FlushCommand(M2C_UNK);                     /* extern */
s32 SND_CountFreeCommand();                                /* extern */
s32 SND_CountWaitingCommand();                                /* extern */
M2C_UNK RequestCommandProc();                            /* extern */

void SND_WaitForFreeCommand(s32 arg0) {
    s32 temp_r0;

    temp_r0 = SND_CountFreeCommand();
    if (temp_r0 >= arg0) {
        return;
    }
    if ((s32) (temp_r0 + SND_CountWaitingCommand()) >= arg0) {
        do {

        } while (SND_RecvCommandReply(0) != 0);
        if (SND_CountFreeCommand() >= arg0) {
            return;
        }
        goto block_8;
    }
    SND_FlushCommand(1);
block_8:
    RequestCommandProc();
    do {
        SND_RecvCommandReply(1);
    } while (SND_CountFreeCommand() < arg0);
}
