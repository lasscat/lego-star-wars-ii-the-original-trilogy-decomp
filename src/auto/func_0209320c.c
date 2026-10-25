/* Reconstructed from USA ARM9 at 0x0209320c (220 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

typedef struct {
    u16 value;
    u16 unk2;
    u32 data[3];
} Entry;

typedef struct {
    u8 count;
    u8 unk1;
    u16 unk2;
    Entry entries[1];
} Table;

typedef struct {
    u8 pad0[0x5C];
    Table *table;
    u16 values[1];
} Obj;

typedef struct {
    s32 unk0;
    s32 state;
} State;

typedef struct {
    State *state;
    u8 pad4[0x84];
} Manager;

extern s32 func_020917b4(void *arg0);
extern Manager data_02102900;
extern Table *data_020ff54c[];

static inline s32 GetManagerState(void) {
    // FAKE: the null test reads the pointer through a cast of &data_02102900; mwcc then keeps it apart
    // from the direct ->state loads (no CSE), matching the reloads in the original
    return ((Manager *) &data_02102900)->state ? data_02102900.state->state : 0;
}

void func_0209320c(Obj *arg0) {
    s32 idx;
    u32 i;

    M2C_FIELD(arg0, s32 *, 0x958) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x95C) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x960) = 0;
    idx                           = func_020917b4(arg0);
    if (idx >= 0x4A) {
        if (GetManagerState() == 0x11 || GetManagerState() == 0x33 || GetManagerState() == 9) {
            idx = 0x47;
        }
    }
    arg0->table = data_020ff54c[idx];
    if (arg0->table != NULL) {
        for (i = 0; i < arg0->table->count; i++) {
            arg0->values[i] = arg0->table->entries[i].value;
        }
    }
}
