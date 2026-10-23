/* Reconstructed from USA ARM9 at 0x0207d8f8 (336 bytes).
 * Names and types are inferred from the binary.
 *
 * The two byte globals are reached through local pointers; the declaration
 * order (p43 before p42) and the point where each address is taken are what
 * the original produced, so the compiler keeps them in r4/r5 across the calls.
 */
#include "m2c.h"

void func_0207f2b0(void *);                      /* extern */
void func_0205365c(M2C_UNK, M2C_UNK);            /* extern */
void func_020861bc(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
void func_0205ecc4(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
u8 func_02094048(s32);                          /* extern */
u8 func_02094058(s32);                          /* extern */
s32 func_02085d20(void *, M2C_UNK);              /* extern */
extern M2C_UNK data_02104d90;
extern M2C_UNK data_02102900;
extern M2C_UNK data_02107942;
extern M2C_UNK data_02107943;

void func_0207d8f8(void *self) {
    u32 n;

    n = M2C_FIELD(self, u32 *, 0);
    if (n >= 0xf) {
        func_0207f2b0(self);
        func_0205365c(M2C_FIELD(self, M2C_UNK *, 0x10), 0);
        M2C_FIELD(self, u8 *, 0x27) = 6;
        func_020861bc(&data_02104d90, 0xa, 0);
        func_0205ecc4(&data_02102900, 0xf, 0, 0, 0, 0);
        func_0205ecc4(&data_02102900, 0x1c, 1, 0x1a, 0xe, 0);
    } else {
        u8 *p43;
        u8 *p42;
        n                         = n + 1;
        M2C_FIELD(self, u32 *, 0) = n;
        p42                       = &data_02107942;
        *p42                      = func_02094048(n);
        p43                       = &data_02107943;
        *p43                      = func_02094058(M2C_FIELD(self, u32 *, 0));
        func_0207f2b0(self);
        if (func_02085d20(&data_02104d90, 0) != 0) {
            func_0205365c(M2C_FIELD(self, M2C_UNK *, 0x10), 0);
            func_0205ecc4(&data_02102900, 0xf, 0, 0, 0, 0);
            func_0205ecc4(&data_02102900, 0x1c, 1, M2C_FIELD(self, u32 *, 0), *p42, *p43);
        } else {
            func_0205ecc4(&data_02102900, 0x1f, 0, 2, 0, 0);
        }
    }
}
