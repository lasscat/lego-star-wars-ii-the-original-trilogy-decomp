#include "m2c.h"

extern s32 func_0205e540(s32, s32, s32);
extern void func_0200af88(u8 *, s32);
extern void *func_0205039c(void *);
extern u16 data_021019c0;
extern u32 data_020fcd18;
extern u32 data_020fe4a8;
extern u32 data_020fe438;
extern u32 data_020fe484;
extern volatile u32 data_020ff9a8;

void *func_020082a4(s32 arg0, s32 arg1, s32 arg2) {
    void *p;

    p = ((void **) arg0)[arg2 + 4];
    if (p == NULL) {
        p                          = (void *) func_0205e540(data_021019c0, 3, 4);
        ((void **) arg0)[arg2 + 4] = p;
    }
    switch (arg1) {
        case 0:
            p = ((void **) arg0)[arg2 + 4];
            if (p != NULL) {
                M2C_FIELD(p, void **, 0x00) = &data_020fcd18;
                M2C_FIELD(p, s32 *, 0x04)   = 0;
                M2C_FIELD(p, s32 *, 0x08)   = 0;
                M2C_FIELD(p, s32 *, 0x0c)   = 0;
                M2C_FIELD(p, s32 *, 0x10)   = 0;
                M2C_FIELD(p, s32 *, 0x14)   = 0;
                M2C_FIELD(p, s32 *, 0x18)   = 0;
                M2C_FIELD(p, s32 *, 0x1c)   = 0;
                M2C_FIELD(p, s32 *, 0x20)   = 0;
                func_0200af88((u8 *) p + 0x24, M2C_FIELD(p, s32 *, 0x20) - 1);
                M2C_FIELD(p, s8 *, 0x25)    = -1;
                M2C_FIELD(p, u8 *, 0x26)    = 0;
                M2C_FIELD(p, void **, 0x00) = &data_020fe4a8;
                M2C_FIELD(p, u16 *, 0x28)   = 0;
                M2C_FIELD(p, u16 *, 0x2a)   = 0;
                M2C_FIELD(p, u16 *, 0x2c)   = 0;
                M2C_FIELD(p, s32 *, 0x30)   = 0;
                M2C_FIELD(p, s8 *, 0x25)    = 0;
            }
            break;
        case 5:
            p = ((void **) arg0)[arg2 + 4];
            if (p != NULL) {
                M2C_FIELD(p, void **, 0x00) = &data_020fcd18;
                M2C_FIELD(p, s32 *, 0x04)   = 0;
                M2C_FIELD(p, s32 *, 0x08)   = 0;
                M2C_FIELD(p, s32 *, 0x0c)   = 0;
                M2C_FIELD(p, s32 *, 0x10)   = 0;
                M2C_FIELD(p, s32 *, 0x14)   = 0;
                M2C_FIELD(p, s32 *, 0x18)   = 0;
                M2C_FIELD(p, s32 *, 0x1c)   = 0;
                M2C_FIELD(p, s32 *, 0x20)   = 0;
                func_0200af88((u8 *) p + 0x24, M2C_FIELD(p, s32 *, 0x20) - 1);
                M2C_FIELD(p, s8 *, 0x25)    = -1;
                M2C_FIELD(p, u8 *, 0x26)    = 0;
                M2C_FIELD(p, void **, 0x00) = &data_020fe438;
                M2C_FIELD(p, s32 *, 0x28)   = 0;
                M2C_FIELD(p, s32 *, 0x2c)   = 0;
                M2C_FIELD(p, s32 *, 0x30)   = 0;
                M2C_FIELD(p, s8 *, 0x25)    = 5;
            }
            break;
        case 3:
            p = ((void **) arg0)[arg2 + 4];
            if (p != NULL) {
                M2C_FIELD(p, void **, 0x00) = &data_020fcd18;
                M2C_FIELD(p, s32 *, 0x04)   = 0;
                M2C_FIELD(p, s32 *, 0x08)   = 0;
                M2C_FIELD(p, s32 *, 0x0c)   = 0;
                M2C_FIELD(p, s32 *, 0x10)   = 0;
                M2C_FIELD(p, s32 *, 0x14)   = 0;
                M2C_FIELD(p, s32 *, 0x18)   = 0;
                M2C_FIELD(p, s32 *, 0x1c)   = 0;
                M2C_FIELD(p, s32 *, 0x20)   = 0;
                func_0200af88((u8 *) p + 0x24, M2C_FIELD(p, s32 *, 0x20) - 1);
                M2C_FIELD(p, s8 *, 0x25)    = -1;
                M2C_FIELD(p, u8 *, 0x26)    = 0;
                M2C_FIELD(p, void **, 0x00) = &data_020fe484;
                M2C_FIELD(p, s32 *, 0x28)   = data_020ff9a8;
                M2C_FIELD(p, s32 *, 0x2c)   = data_020ff9a8;
                M2C_FIELD(p, s8 *, 0x25)    = 3;
            }
            break;
        case 11:
            p = ((void **) arg0)[arg2 + 4];
            if (p != NULL) {
                func_0205039c(p);
            }
            break;
    }
    return ((void **) arg0)[arg2 + 4];
}
