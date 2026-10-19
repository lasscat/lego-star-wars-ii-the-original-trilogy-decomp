#include "m2c.h"

s32 SND_RecvCommandReply();                         /* extern */
s32 SND_IsFinishedCommandTag();                         /* extern */
M2C_UNK RequestCommandProc();                            /* extern */

void SND_WaitForCommandProc(M2C_UNK arg0) {
    if (SND_IsFinishedCommandTag() != 0) {
        return;
    }
    do {

    } while (SND_RecvCommandReply(0) != 0);
    if (SND_IsFinishedCommandTag(arg0) != 0) {
        return;
    }
    RequestCommandProc();
    if (SND_IsFinishedCommandTag(arg0) != 0) {
        return;
    }
    do {
        SND_RecvCommandReply(1);
    } while (SND_IsFinishedCommandTag(arg0) == 0);
}
