#include "m2c.h"

extern u8 *data_0210daf0;
void func_020b7f90(u32, u32); /* extern */

/* Descriptor of one waveform table of a voice. */
typedef struct {
    u16 *table;
    s8 *flags;
    u8 flags2;
    u8 max;
    u8 lo;
    u8 hi;
    u8 lo2;
    u8 hi2;
} SND_Desc;

/* Per waveform channel state. */
typedef struct {
    u16 value;
    u8 index;
    u8 pad_0x3;
} SND_State;

/* One channel record of the sound object. */
typedef struct {
    u8 pad_0x00[0x5];
    u8 voice;
    u8 pad_0x06[0x5];
    u8 flags;
    u8 pad_0x0c[0x8];
    SND_State state[3];
} SND_Channel;

/* One voice record of the sound object. */
typedef struct {
    u8 pad_0x00[0x14];
    SND_Desc *desc[3];
} SND_Voice;

void func_020b891c(u32 ch, u32 idx) {
    SND_Desc *desc;
    SND_State *state;
    s32 lo;
    s32 hi;
    SND_Channel *rec;
    u8 *obj;
    SND_Voice *voice;

    if (ch == 0xff) {
        return;
    }
    lo    = -1;
    hi    = 0;
    obj   = data_0210daf0;
    rec   = (SND_Channel *) (obj + 0x4bc) + ch;
    voice = (SND_Voice *) (*(u32 *) (obj + 4)) + rec->voice;
    state = &rec->state[idx];
    desc  = voice->desc[idx];

    if (!(rec->flags & 2)) {
        if (desc->flags2 & 4) {
            lo = desc->lo2;
            hi = desc->hi2;
        } else if (desc->flags2 & 2) {
            lo = desc->lo;
            hi = desc->hi;
        }
    } else {
        if (desc->flags2 & 2) {
            lo = desc->lo;
            hi = desc->hi;
        }
    }

    if (lo == hi && state->index == lo) {
        state->index = lo;
        state->value = desc->table[state->index];
        return;
    }

    state->value = state->value + 1;
    if (state->value < desc->table[state->index + 1]) {
        return;
    }
    state->index++;
    if (lo != -1) {
        if (state->index < hi) {
            return;
        }
        state->index = lo;
        state->value = desc->table[state->index];
        return;
    }
    if (state->index < desc->max - 1) {
        return;
    }
    state->index = desc->max - 1;
    state->value = desc->table[state->index];
    if (idx != 0) {
        return;
    }
    if (desc->flags[state->index] == 0) {
        func_020b7f90(ch, 0);
        return;
    }
    rec->flags |= 4;
}
