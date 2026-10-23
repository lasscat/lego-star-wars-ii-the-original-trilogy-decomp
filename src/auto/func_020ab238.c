#include "m2c.h"

M2C_UNK func_0205af6c(void **, void *, u16 *);   /* extern */
M2C_UNK func_0205b1e0(s32, s32, s32);            /* extern */
M2C_UNK func_0205ab30(s32);                      /* extern */
s32 func_020c293c(s32);                           /* extern */
void DC_FlushRange(s32, s32);                     /* extern */
void func_0201c778(u16 *);                        /* extern */
M2C_UNK func_020abe14(void *, s32, u16 *);        /* extern */
u8 func_02064f7c(void *);                         /* extern */
void func_0205b41c(s32, s16, s32);                /* extern */
s32 func_020ab900(s32, s32, s32);                 /* extern */
void func_020ab8e4(s32, s32, void *);             /* extern */
s32 func_0205b454(s32, s16);                      /* extern */
void func_02064f90(void *);                       /* extern */
s32 func_020c4070(s32, s32);                      /* extern */
void func_020c61e0(s32, s32, s32);                /* extern */
extern void *data_021027f4;
extern s32 data_0210a0b4;

s32 func_020ab238(s32 arg0, s16 arg1) {
    u16 sp0;
    void *sp4;
    s32 r4;
    void *r7;
    s32 r8;
    u16 sp8[5];
    u32 *p;
    s32 v;

    sp0 = arg1;
    r7  = data_021027f4;
    func_0205af6c(&sp4, r7, &sp0);
    r4 = (s32) sp4;
    if (r4 == (s32) r7 + 4) {
        r4 = 0;
    } else {
        func_0205b1e0((s32) r7, *(s32 *) (r4 + 0x10), 1);
        r4 = *(s32 *) (*(s32 *) (r4 + 0x10));
    }
    if (r4 == 0) {
        r4 = func_0205ab30(arg1);
        DC_FlushRange(r4, func_020c293c(r4) + 0x20);
        p = (u32 *) ((u8 *) r4 + *(u16 *) (r4 + 0xC));
        if (*(u16 *) (r4 + 0xE) == 1) {
            r8 = (*(u32 *) r4 == 0x30585442) ? r4 + *p : 0;
        } else {
            r8 = r4 + p[1];
        }
        func_0201c778(sp8);
        r7 = func_020abe14(&data_0210a0b4, r8, sp8);
        func_02064f7c(r7);
        func_0205b41c(data_021027f4, arg1, r7);
        if (func_020ab900(arg0, r8, r7) != 0) {
            func_020ab8e4(arg0, r4, r8);
        }
    }
    p = (u32 *) ((u8 *) r4 + *(u16 *) (r4 + 0xC));
    if (*(u16 *) (r4 + 0xE) == 1) {
        r4 = (*(u32 *) r4 == 0x30585442) ? r4 + *p : 0;
    } else {
        r4 = r4 + p[1];
    }
    v                   = func_0205b454(data_021027f4, arg1);
    *(s32 *) (arg0 + 8) = v;
    func_02064f90(v);
    *(u16 *) (arg0 + 0x14) |= 4;
    func_020c4070(*(s32 *) (arg0 + 4), r4);
    {
        s32 q = *(s32 *) (arg0 + 4);
        s32 w = q + *(u16 *) (q + 0xE);
        func_020c61e0(q + *(s32 *) (w + 0xC), 0, 0x40);
    }
    {
        s32 q = *(s32 *) (arg0 + 4);
        s32 w = q + *(u16 *) (q + 0xE);
        func_020c61e0(q + *(s32 *) (w + 0xC), 0, 0x80);
    }
    return 1;
}
