/* Reconstructed from USA ARM9 at 0x02068b90 (484 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

s32 func_0200aef8(void *, void *, s32, void *, s32);   /* extern */
void func_02001688(s32);                                /* extern */
void func_020016c0(void);                               /* extern */
s32 func_0204a880(void *);                              /* extern */
void func_020b04f0(M2C_UNK *, M2C_UNK, u8 *, M2C_UNK);  /* extern */
void func_020922f4(M2C_UNK *, u8, s32);                 /* extern */
void func_020b8f70(u8, u8);                             /* extern */

extern s32 data_027e02a8;
extern s32 data_02104d90;
extern M2C_UNK data_021027f8;
extern M2C_UNK data_02109358[18];
extern M2C_UNK data_0210930c;
extern M2C_UNK data_0210794c;

#define OBJ_IDX (M2C_FIELD(&data_021027f8, u8 *, 0x2A))
#define OBJ_A (data_02109358[OBJ_IDX])
#define OBJ_B (data_02109358[arg1])

s32 func_02068b90(s32 arg0, s32 arg1) {
    s32 var_r4;
    s32 var_r6;
    s32 temp;
    M2C_UNK var_b;
    u8 buf[0x1c];

    if (data_027e02a8 & 0x400) {
        goto ret0;
    }
    if (data_02104d90 & 1) {
        goto ret0;
    }
    if (M2C_FIELD(OBJ_A, u8 *, 0x5D6) == 0) {
        goto body;
    }
ret0:
    return 0;
body:
    var_r4 = (((M2C_FIELD(OBJ_A, u32 *, 8) & 0x2040803) == 1) & M2C_FIELD(OBJ_A, u8 *, 0x40)) != 0;
    var_r6 = (((M2C_FIELD(OBJ_B, u32 *, 8) & 0x2040803) == 1) & M2C_FIELD(OBJ_B, u8 *, 0x40)) != 0;
    temp   = func_0200aef8((void *) (OBJ_A + 0xB0), (void *) (OBJ_B + 0xB0), 0x32000, (void *) OBJ_B, 0x32000);
    if (var_r4 && var_r6 && temp) {
        if (M2C_FIELD(OBJ_A, u8 *, 0x6BA) == 0 && M2C_FIELD(OBJ_B, u8 *, 0x6BA) == 0) {
            goto cont;
        }
    }
    func_020b8f70(0xB7, 0);
    return 0;
cont:
    func_02001688(0);
    var_b = OBJ_B;
    if (arg1 == OBJ_IDX) {
        goto err2;
    }
    if (func_0204a880((void *) (var_b + 0x5CE)) == 0) {
        goto cont2;
    }
err2:
    func_020b8f70(0xB7, 0);
    goto fin;
cont2:
    if (!(data_027e02a8 & 0x40)) {
        func_020922f4(&data_0210930c, OBJ_IDX, arg1);
        func_020b8f70(0xB4, 0);
        goto fin;
    } else {
        buf[0] = OBJ_IDX;
        buf[1] = arg1;
        func_020b04f0(&data_0210794c, 0x2A, buf, 0xFF);
        func_020b8f70(0xB4, 0);
    }
fin:
    func_020016c0();
    return 1;
}
