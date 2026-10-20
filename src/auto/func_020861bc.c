#include "m2c.h"

/* Bit array at offset 0x4488 of the object: 32 flags per word. */
typedef struct {
    u8 pad_4400[0x4400];
    u32 flags[0x220];
} func_020861bc_Flags;

typedef struct {
    u8 pad_88[0x88];
    func_020861bc_Flags flags;
} func_020861bc_Obj;

/* Sets or clears the flag bit selected by arg1, depending on arg2. */
void func_020861bc(s32 arg0, s32 arg1, s32 arg2) {
    func_020861bc_Obj *obj = (func_020861bc_Obj *) arg0;
    u32 bit                = arg1 & 0x1f;
    u32 index              = arg1 >> 5;

    obj->flags.flags[index] &= ~(1u << bit);
    obj->flags.flags[index] |= ((arg2 != 0) ? 1u : 0u) << bit;
}
