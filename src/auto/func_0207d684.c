/* Reconstructed from USA ARM9 at 0x0207d684 (0x274 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0207dee4(void *);      /* extern */
s32 func_0207e050(void *);      /* extern */
s32 func_0207e108(void *);      /* extern */
void func_0207e460(void *);     /* extern */
s32 func_0207dba4(void);        /* extern */
s32 func_0207df90(void *);      /* extern */
s32 func_0207ea0c(void *);      /* extern */
s32 func_0207edb0(void *);      /* extern */
s32 func_0207e590(void *);      /* extern */
void func_0207e840(void *);     /* extern */
s32 func_0207f0f0(void *);      /* extern */
void func_0207de00(void *);     /* extern */
void func_0207d8f8(void *);     /* extern */
void func_0207da48(void *);     /* extern */
void func_0207dbfc(void *);     /* extern */
void func_02060158(void *, s32, s32, s32); /* extern */
extern M2C_UNK data_02102900;

void func_0207d684(void *arg0) {
    void *self = arg0;

    switch (M2C_FIELD(self, u8 *, 0x27)) {
        case 2:
        case 5:
        case 6:
        case 9:
        case 12:
            break;
        case 4:
            if (func_0207dee4(self)) {
                return;
            }
            if (func_0207e050(self)) {
                return;
            }
            if (func_0207e108(self)) {
                return;
            }
            func_0207e460(self);
            break;
        case 8:
            if (!func_0207dba4()) {
                return;
            }
            if (func_0207df90(self)) {
                return;
            }
            if (func_0207e050(self)) {
                return;
            }
            if (func_0207e108(self)) {
                return;
            }
            func_0207e460(self);
            break;
        case 10:
            if (!func_0207dba4()) {
                return;
            }
            if (func_0207e050(self)) {
                return;
            }
            if (func_0207e108(self)) {
                return;
            }
            func_0207e460(self);
            break;
        case 11:
            if (!func_0207dba4()) {
                return;
            }
            func_02060158(&data_02102900, 0, 0x1D, 0);
            if (func_0207e108(self)) {
                return;
            }
            func_02060158(&data_02102900, 0, 0x1E, 0);
            func_0207e460(self);
            break;
        case 13:
            if (!func_0207ea0c(self)) {
                M2C_FIELD(self, u8 *, 0x27) = 0xE;
            }
            break;
        case 14:
            if (!func_0207dba4()) {
                return;
            }
            func_02060158(&data_02102900, 0, 0x1E, 0);
            func_0207e460(self);
            break;
        case 15:
            if (!func_0207edb0(self)) {
                M2C_FIELD(self, u8 *, 0x27) = 0x10;
            }
            break;
        case 16:
            if (!func_0207dba4()) {
                return;
            }
            func_02060158(&data_02102900, 0, 0x1F, 0);
            if (func_0207e590(self)) {
                return;
            }
            func_02060158(&data_02102900, 0, 0x20, 0);
            func_0207e840(self);
            break;
        case 17:
            if (!func_0207f0f0(self)) {
                M2C_FIELD(self, u8 *, 0x27) = 0x12;
            }
            break;
        case 18:
            if (!func_0207dba4()) {
                return;
            }
            func_02060158(&data_02102900, 0, 0x20, 0);
            func_0207e840(self);
            break;
        case 7:
            func_0207de00(self);
            break;
        case 0:
            func_0207d8f8(self);
            break;
        case 1:
            func_0207da48(self);
            break;
        case 3:
            func_0207dbfc(self);
            break;
    }
}
