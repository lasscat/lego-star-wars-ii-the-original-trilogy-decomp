#include "m2c.h"

/* Reconstructed from USA ARM9 at 0x02060fa4 (64 bytes).
 *
 * A thin wrapper: it hands the address of the global object and its own
 * arguments to func_020610e4 and always returns 0.
 *
 * The "push {r0, r1, r2, r3}" prologue is MWCC's argument home area.  It is
 * created because the third and the fourth parameter are passed by value as
 * one word structures, so the compiler keeps them in the home area and reads
 * them back from there: the third one through its address ("add r3, sp,
 * #0x10" / "ldr r3, [r3]") because it is passed in a register, the fourth
 * one with a plain load ("ldr ip, [sp, #0x14]") because it is copied into
 * the callee's stack argument slot.
 */

typedef struct {
    s32 v;
} UnkVal;

extern M2C_UNK data_027e03a0;
extern void func_020610e4(void *, M2C_UNK, M2C_UNK, UnkVal, UnkVal);

s32 func_02060fa4(M2C_UNK a0, M2C_UNK a1, UnkVal a2, UnkVal a3) {
    func_020610e4(&data_027e03a0, a0, a1, a2, a3);
    return 0;
}
