#include "m2c.h"

extern M2C_UNK data_020fdbc4;
extern M2C_UNK data_020fe0d8;

/* Initialize an actor-owned behavior object and link its embedded node to the
 * supplied target. */
void func_02039ff8(void *behavior, void *actor, s8 *target) {
    s8 *linkSlot;
    s8 *targetLink;
    void *listSentinel;
    s8 *listEntry;

    targetLink                         = target;
    M2C_FIELD(behavior, M2C_UNK **, 0) = &data_020fdbc4;
    M2C_FIELD(behavior, void **, 4)    = actor;
    M2C_FIELD(behavior, s8 *, 0xC)     = 0;
    M2C_FIELD(behavior, s8 *, 0xD)     = 0;
    M2C_FIELD(behavior, M2C_UNK **, 0) = &data_020fe0d8;
    M2C_FIELD(behavior, s8 **, 0x10)   = NULL;
    M2C_FIELD(behavior, void **, 0x14) = NULL;
    M2C_FIELD(behavior, s32 *, 0x20)   = 0;
    M2C_FIELD(behavior, s8 *, 0x24)    = 0;
    linkSlot                           = M2C_FIELD(behavior, s8 **, 0x10);
    if (targetLink != NULL) {
        targetLink += 4;
    }
    if (linkSlot != NULL) {
        listEntry    = M2C_FIELD(linkSlot, s8 **, 0);
        listSentinel = behavior + 0x10;
        if (listEntry != listSentinel) {
            do {
                linkSlot  = listEntry + 4;
                listEntry = M2C_FIELD(listEntry, s8 **, 4);
            } while (listEntry != listSentinel);
        }
        M2C_FIELD(linkSlot, void **, 0) = M2C_FIELD(behavior, void **, 0x14);
    }
    if (targetLink != NULL) {
        M2C_FIELD(behavior, s8 **, 0x10)   = targetLink;
        M2C_FIELD(behavior, void **, 0x14) = M2C_FIELD(targetLink, void **, 0);
        M2C_FIELD(targetLink, void **, 0)  = behavior + 0x10;
    } else {
        M2C_FIELD(behavior, s8 **, 0x10)   = NULL;
        M2C_FIELD(behavior, void **, 0x14) = NULL;
    }
    M2C_FIELD(behavior, s16 *, 0x1C) = (s16) M2C_FIELD(actor, s16 *, 0x6B6);
}
