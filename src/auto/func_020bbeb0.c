#include "m2c.h"

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
} File;

typedef struct {
    u32 f0;
    u16 f4;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 f9;
    u8 fa;
    u8 fb;
    u8 fc;
} Rec;

typedef struct {
    u8 pad[0x90];
    u16 f90;
} Sub;

void *func_020bd5d4(void *);
M2C_UNK func_020be37c(void *);
void func_020bc530(void *, M2C_UNK);

void func_020bbeb0(void *arg0, void *arg1) {
    File *src = (File *) arg1;
    Sub *sub  = (Sub *) ((u8 *) arg0 + 0x300);
    Rec *rec;
    s32 count;
    s32 i;
    void *p;

    count = src->f0;
    rec   = (Rec *) ((u8 *) src + src->f2);

    M2C_FIELD(arg0, u32 *, 0x38c) = rec->f0;
    sub->f90                      = rec->f4;
    M2C_FIELD(arg0, u8 *, 0x392)  = rec->f6;
    M2C_FIELD(arg0, u8 *, 0x393)  = rec->f7;
    M2C_FIELD(arg0, u8 *, 0x394)  = rec->f8;
    M2C_FIELD(arg0, u8 *, 0x395)  = rec->f9;
    M2C_FIELD(arg0, u8 *, 0x396)  = rec->fa;
    M2C_FIELD(arg0, u8 *, 0x397)  = rec->fb;
    M2C_FIELD(arg0, u32 *, 0x384) |= rec->fc;

    p                              = func_020bd5d4((u8 *) src + src->f4);
    M2C_FIELD(arg0, void **, 0x48) = p;
    M2C_FIELD(arg0, u8 *, 0x39c)   = (M2C_FIELD(p, s32 *, 0x10) > 0) ? 1 : 0;

    for (i = 2; i < count; i++) {
        func_020bc530(arg0, func_020be37c((u8 *) src + ((u16 *) src)[i + 1]));
    }
}
