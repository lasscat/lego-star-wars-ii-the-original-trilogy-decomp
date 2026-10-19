#include "engine.h"

#include "m2c.h"

void PushCommand_impl(s32, s32, s32, s32, s32);

void SND_SetChannelTimer(s32 arg0, s32 arg1) {
    PushCommand_impl(0x13, arg0, arg1, 0, 0);
}
