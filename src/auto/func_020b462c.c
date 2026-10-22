#include "m2c.h"

extern void *data_0210daf0;
extern M2C_UNK data_0210dafc;

s32 SND_IsFinishedCommandTag(u32);
s32 SND_GetCurrentCommandTag(void);
void func_020b8688(void);
s32 func_020b5bd4(void);
void func_020b5d3c(void);
void func_020b73e0(void);
void func_020b8a90(void);
void func_020b7dc4(void);

void func_020b462c(s32 arg0) {
    void *temp_r0;

    temp_r0 = *((M2C_UNK *) ((s8 *) &data_0210dafc + (arg0 * 4)));
    if (temp_r0 == NULL) {
        return;
    }
    data_0210daf0 = temp_r0;
    if (M2C_FIELD(temp_r0, u8 *, 0x25) != 1) {
        return;
    }
    if (M2C_FIELD(temp_r0, u32 *, 0x18) == 0 || SND_IsFinishedCommandTag(M2C_FIELD(temp_r0, u32 *, 0x18)) != 0) {
        func_020b8688();
    }
    if (((u8 *) data_0210daf0)[0x35]-- == 0) {
        ((u8 *) data_0210daf0)[0x35] = 0;
        ((u8 *) data_0210daf0)[0x27]--;
        if (((u8 *) data_0210daf0)[0x27] == 0) {
            ((u8 *) data_0210daf0)[0x27] = ((u8 *) data_0210daf0)[0x2c];
            if (((u8 *) data_0210daf0)[0x34]-- == 0) {
                ((u8 *) data_0210daf0)[0x34] = 0;
                if (M2C_FIELD(data_0210daf0, u16 *, 0x1e)-- == 0) {
                    if (func_020b5bd4() == 1) {
                        return;
                    }
                    M2C_FIELD(data_0210daf0, u16 *, 0x1e)--;
                }
                func_020b5d3c();
            }
            if (((u8 *) data_0210daf0)[0x2d] & 0x10) {
                ;
            } else {
                func_020b73e0();
            }
        } else {
            func_020b73e0();
        }
    } else {
        func_020b73e0();
    }
    func_020b8a90();
    func_020b7dc4();
    M2C_FIELD(data_0210daf0, u32 *, 0x18) = SND_GetCurrentCommandTag();
}
