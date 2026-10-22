/* Reconstructed from USA ARM9 at 0x020b4080 (740 bytes).
 *
 * Sound module teardown.  arg0 selects one of the three sound objects
 * stored in data_0210daf4[2..4]; the object being worked on is kept in the
 * global data_0210daf0.  The object holds
 *   +0x00  pointer to an array of 0x24 byte records,
 *   +0x04  pointer to an array of 0x20 byte voice records,
 *   +0x08  heap block,
 *   +0x0c  pointer to an array of heap blocks,
 *   +0x18  counter,
 *   +0x25  state byte (1 or 2 while the sound is still playing),
 *   +0x26  flags (bit 2 selects the full teardown),
 *   +0x2d  flags (bit 7 enables the teardown),
 *   +0x2f  number of voice records,
 *   +0x30  number of 0x24 byte records,
 *   +0x31  number of heap blocks,
 *   +0x39  channel id.
 */
#include "m2c.h"

extern void *data_0210daf0;
extern void *data_0210daf4[];
extern M2C_UNK data_0210dc20;

M2C_UNK func_020b5ba8(s32, s32, s32);                          /* extern */
M2C_UNK func_020bb488(s32);                                   /* extern */
M2C_UNK SND_StopTimer(s32, s32, s32, s32);                    /* extern */
M2C_UNK func_0205e5b0(M2C_UNK);                               /* extern */
M2C_UNK func_020b4018(s32);                                   /* extern */

void func_020b4080(s32 arg0) {
    s32 i;
    s32 k;
    s32 bit;
    u8 *rec;
    void *obj;
    void **arr;
    M2C_UNK p;

    if (arg0 == 4) {
        for (i = 0; i < 3; i++) {
            func_020b4080(i);
        }
        return;
    }
    obj = data_0210daf4[arg0 + 2];
    if (obj == NULL) {
        return;
    }
    data_0210daf0 = obj;
    func_020b5ba8(6, 0, 1);
    if ((u8) (M2C_FIELD(data_0210daf0, u8 *, 0x25) + 0xFF) <= 1) {
        u32 mask = 0;
        for (i = 0; i < 16; i++) {
            if (M2C_FIELD(data_0210daf0, u8 *, 0x39) == ((u8 *) &data_0210dc20)[i + 4]) {
                func_020bb488(i);
                mask |= 1 << i;
            }
            SND_StopTimer(mask, 0, 0, 0);
        }
        M2C_FIELD(data_0210daf0, u8 *, 0x25) = 0;
    }
    if (M2C_FIELD(data_0210daf0, u8 *, 0x2d) & 0x80) {
        if (M2C_FIELD(data_0210daf0, u8 *, 0x26) & 4) {
            for (i = 1; i < M2C_FIELD(data_0210daf0, u8 *, 0x2f) + 1; i++) {
                rec = (u8 *) M2C_FIELD(data_0210daf0, u32 *, 4) + i * 0x20;
                if (rec[3] & 1) {
                    func_0205e5b0(*(u32 *) (rec + 0xc));
                }
                if (rec[3] & 2) {
                    func_0205e5b0(*(u32 *) (rec + 0x10));
                }
                for (bit = 0; bit < 3; bit++) {
                    if (rec[3] & (4 << bit)) {
                        func_0205e5b0(((u32 *) (rec + 0x14))[bit]);
                    }
                }
            }
            for (i = 1; i < M2C_FIELD(data_0210daf0, u8 *, 0x30) + 1; i++) {
                arr = *(void **) ((s8 *) data_0210daf0 + 0);
                p   = *(M2C_UNK *) ((s8 *) arr + i * 0x24);
                if (p != 0) {
                    func_0205e5b0(p);
                    arr                                  = *(void **) ((s8 *) data_0210daf0 + 0);
                    *(M2C_UNK *) ((s8 *) arr + i * 0x24) = 0;
                }
            }
            for (k = 0; k < M2C_FIELD(data_0210daf0, u8 *, 0x31); k++) {
                arr = *(void **) ((s8 *) data_0210daf0 + 0xc);
                func_0205e5b0(((u32 *) arr)[k]);
            }
            func_0205e5b0(M2C_FIELD(data_0210daf0, u32 *, 8));
            M2C_FIELD(data_0210daf0, u32 *, 8) = 0;
            func_0205e5b0(M2C_FIELD(data_0210daf0, u32 *, 4));
            M2C_FIELD(data_0210daf0, u32 *, 4) = 0;
            func_0205e5b0(M2C_FIELD(data_0210daf0, u32 *, 0));
            M2C_FIELD(data_0210daf0, u32 *, 0) = 0;
            func_0205e5b0(M2C_FIELD(data_0210daf0, u32 *, 0xc));
            M2C_FIELD(data_0210daf0, u32 *, 0xc) = 0;
            p                                    = (M2C_UNK) data_0210daf4[arg0 + 2];
            func_0205e5b0(p);
            data_0210daf4[arg0 + 2] = 0;
            data_0210daf0           = NULL;
        } else {
            data_0210daf4[arg0 + 2]                = 0;
            data_0210daf0                          = NULL;
            M2C_FIELD(&data_0210daf0, s32 *, 0x18) = 0;
        }
    }
    if (arg0 != 1) {
        return;
    }
    func_020b4018(0);
}
