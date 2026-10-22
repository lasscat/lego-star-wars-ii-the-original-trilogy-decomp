#include "m2c.h"

extern M2C_UNK data_0210da80;
extern void func_020d2898(void *);
extern s32 FS_OpenFile(void *, void *);
extern u32 MB_GetSegmentLength(void *);
extern u8 *func_0205e838(u32);
extern M2C_UNK func_020d9da4(M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK MB_RegisterFile(M2C_UNK, M2C_UNK);
extern void func_0205e860(s32);
extern s32 func_020d2bc0(void *);

s32 func_020af8bc(void *arg0) {
    u8 buf[0x48];
    u8 *p;
    u8 *mem;
    u32 len;
    s32 ret;

    ret = 0;
    if (M2C_FIELD(arg0, void **, 0) == 0) {
        p = 0;
    } else {
        func_020d2898(buf);
        if (FS_OpenFile(buf, M2C_FIELD(arg0, void **, 0)) == 0) {
            return 0;
        }
        p = buf;
    }
    len = MB_GetSegmentLength(p);
    if (len != 0) {
        if (len > 0x80000) {
            len = 0x80000;
        }
        mem           = func_0205e838(len);
        data_0210da80 = mem;
        if (mem != 0) {
            if (func_020d9da4(p, mem, len) != 0) {
                if (MB_RegisterFile(arg0, data_0210da80) != 0) {
                    ret = 1;
                }
            }
            if (ret == 0) {
                func_0205e860(data_0210da80);
                data_0210da80 = 0;
            }
        }
    }
    if (p == buf) {
        func_020d2bc0(buf);
    }
    return ret;
}
