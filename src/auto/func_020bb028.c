/* Reconstructed from USA ARM9 at 0x020bb028 (344 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK data_021009e8;
extern M2C_UNK data_0210db84;
extern M2C_UNK data_0210db88;
extern s32 data_0210dbd0[10];
extern s32 data_0210dbf8[10];
extern M2C_UNK data_0210dc20;
extern M2C_UNK data_0210e184;

void func_0205e624(void *, M2C_UNK, M2C_UNK);             /* extern */
void func_020d2898(M2C_UNK *);                            /* extern */
void FS_OpenFile(M2C_UNK *, M2C_UNK *);                  /* extern */
void func_020b3bb8(void);                                /* extern */
void func_020ba778(M2C_UNK, M2C_UNK);                    /* extern */
s32 func_020ba798(void *, M2C_UNK);                      /* extern */
void SND_WaitForFreeCommand(s32);                       /* extern */
void SND_SetMasterVolume(M2C_UNK);                       /* extern */
void SND_SetOutputSelector(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
void SND_LockChannel(s32, s32);                         /* extern */
void func_020bb49c(s32);                                /* extern */

void func_020bb028(void) {
    s32 i;

    func_0205e624(&data_0210dc20, 0, 0x5CC);
    func_0205e624(&data_0210dbd0, 0, 0x50);
    func_020d2898(&data_0210db88);
    FS_OpenFile(&data_0210db88, &data_021009e8);
    func_020b3bb8();
    func_020ba778(0, 0);
    func_020ba798(&data_0210dbd0, 0x28);
    for (i = 0; i < 10; i++) {
        func_020ba778(data_0210dbd0[i], 0);
        func_020ba798(&data_0210dbf8[i], 4);
    }
    M2C_FIELD(&data_0210db84, s8 *, 0xC0)  = 0x7F;
    M2C_FIELD(&data_0210db84, s8 *, 0xC1)  = 0x7F;
    M2C_FIELD(&data_0210e184, u16 *, 0x64) = 0;
    M2C_FIELD(&data_0210db84, s8 *, 0x666) = 0;
    M2C_FIELD(&data_0210db84, s8 *, 0x667) = 0;
    M2C_FIELD(&data_0210db84, s8 *, 0x5D8) = 7;
    for (i = 0; i < 16; i++) {
        *(u8 *) ((s8 *) &data_0210dc20 + i + 4) = 0xFF;
    }
    for (i = 0; i < 32; i++) {
        *(u8 *) ((u8 *) &data_0210dc20 + 4 * (u32) i + 0x41A) = 0xFF;
    }
    SND_WaitForFreeCommand(3);
    SND_SetMasterVolume(0x7F);
    SND_SetOutputSelector(0, 0, 0, 0);
    SND_LockChannel(0xFFFF, 0);
    func_020bb49c(4);
}
