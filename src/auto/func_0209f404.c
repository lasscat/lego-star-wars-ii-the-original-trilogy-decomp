/* Reconstructed from USA ARM9 at 0x0209f404 (144 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_020ffbb8;

typedef void *(*InitFn)(void *);
typedef s32 (*HandlerFn)(s32);

void *func_020acae8(void *);                           /* extern */
void func_020e46bc(void *, s32, s32, InitFn, HandlerFn); /* extern */
void *func_0209f180(void *);                           /* extern */
s32 func_0209f19c(s32);                                /* extern */

/* Constructor of the object at arg0: base constructor, virtual table pointer,
 * five 8 byte elements at +0x74 built by func_020e46bc, then the fields at
 * +0x9C .. +0xB8. Returns the object. */
void *func_0209f404(void *arg0) {
    func_020acae8(arg0);
    M2C_FIELD(arg0, s32 *, 0x0) = (s32) &data_020ffbb8;
    func_020e46bc((void *) ((u8 *) arg0 + 0x74), 5, 8, func_0209f180, func_0209f19c);
    M2C_FIELD(arg0, s32 *, 0x9C) = 0;
    M2C_FIELD(arg0, s32 *, 0xA0) = 0;
    M2C_FIELD(arg0, s32 *, 0xA4) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0xA8) = 0;
    M2C_FIELD(arg0, u16 *, 0xAC) = 0x276;
    M2C_FIELD(arg0, u16 *, 0xAE) = 0xF5;
    M2C_FIELD(arg0, u8 *, 0xB0)  = 0;
    M2C_FIELD(arg0, u8 *, 0xB1)  = 0;
    M2C_FIELD(arg0, s32 *, 0xB4) = 0;
    M2C_FIELD(arg0, s32 *, 0xB8) = 0;
    M2C_FIELD(arg0, u16 *, 0xB2) = 0;
    M2C_FIELD(arg0, u16 *, 0xB2) |= 2;
    return arg0;
}
