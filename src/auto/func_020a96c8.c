#include "m2c.h"

extern s32 func_02067b48(s32 *, s32);
extern u8 func_02067b54(void *);
extern s32 func_020a97e0(void *, void *, void *);

s32 func_020a96c8(void *self, u32 index, void *arg2) {
    s32 prev;
    s32 next;
    s32 next_idx;
    s32 prev_idx;
    s32 d_prev;

    func_02067b48(M2C_FIELD(self, s32 *, 0x21c), index);
    prev     = 0;
    next     = 0;
    next_idx = index;
    prev_idx = index;

    if (index != 0) {
        prev_idx = (index - 1) & 0xff;
        prev     = func_02067b48(M2C_FIELD(self, s32 *, 0x21c), prev_idx);
    } else if (M2C_FIELD(self, u8 *, 0x241) != 0) {
        prev_idx = (func_02067b54(M2C_FIELD(self, s32 *, 0x21c)) - 1) & 0xff;
        prev     = func_02067b48(M2C_FIELD(self, s32 *, 0x21c), prev_idx);
    }

    if (index + 1 < func_02067b54(M2C_FIELD(self, s32 *, 0x21c))) {
        next_idx = (index + 1) & 0xff;
        next     = func_02067b48(M2C_FIELD(self, s32 *, 0x21c), next_idx);
    } else if (M2C_FIELD(self, u8 *, 0x241) != 0) {
        next_idx = 0;
        next     = func_02067b48(M2C_FIELD(self, s32 *, 0x21c), 0);
    }

    if (prev != 0) {
        d_prev = func_020a97e0(self, prev, arg2);
        index  = prev_idx;
    }
    if (next != 0) {
        if (func_020a97e0(self, next, arg2) < d_prev || prev == 0) {
            index = next_idx;
        }
    }
    return index;
}
