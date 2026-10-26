#include "engine.h"
#include "m2c.h"

void func_020675d8(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0210930c;

/* Clear linked behavior state, mark its actor/object flags, and dispatch an
 * indexed shared action. */
void func_02039e5c(s32 behavior) {
    u8 actionIndex;
    void *actor;
    void *actor_2;
    void *linkedObject;

    actor                                                      = M2C_FIELD(behavior, void **, 4);
    M2C_FIELD(actor, s32 *, 8)                                 = (s32) (M2C_FIELD(actor, s32 *, 8) | 0x200);
    actor_2                                                    = M2C_FIELD(behavior, void **, 4);
    M2C_FIELD(actor_2, s32 *, 8)                               = (s32) (M2C_FIELD(actor_2, s32 *, 8) | 0x20);
    linkedObject                                               = M2C_FIELD(behavior, void **, 0x1C);
    M2C_FIELD(linkedObject, s32 *, 8)                          = (s32) (M2C_FIELD(linkedObject, s32 *, 8) | 2);
    M2C_FIELD(behavior, void **, 0x1C)                         = NULL;
    M2C_FIELD(M2C_FIELD(behavior, void **, 4), s8 *, 0x6BA)    = 0;
    M2C_FIELD(M2C_FIELD(behavior, void **, 4), s8 *, 0x1AD)    = 0;
    M2C_FIELD(M2C_FIELD(behavior, void **, 0x10), s8 *, 0x1AD) = 0;
    actionIndex                                                = M2C_FIELD(behavior, u8 *, 0x6C);
    if (actionIndex != 0) {
        func_020675d8(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0210930c, void **, 0x68), void **, 0x38C), s32 *, 4) + 0x28,
                      (s32) actionIndex);
    }
    M2C_FIELD(behavior, u8 *, 0xC) = (u8) (M2C_FIELD(behavior, u8 *, 0xC) | 1);
}
