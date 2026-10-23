#include "m2c.h"

M2C_UNK func_0205af6c(void **, void *, u16 *);   /* extern */
M2C_UNK func_0205b1e0(s32, s32, s32);            /* extern */
M2C_UNK func_0205ab30(s32);                      /* extern */
M2C_UNK func_020ab8e4(s32, s32, void *);         /* extern */
M2C_UNK func_020c61e0(s32, s32, s32);            /* extern */
extern void *data_021027f4;

s32 func_020ab40c(s32 arg0, u16 arg1) {
    u16 sp0;
    void *sp4;
    s32 r4;
    void *r7;

    if (arg1 == 0xffff) {
        return 0;
    }
    *(u16 *) (arg0 + 0x12) = arg1;
    r7                     = data_021027f4;
    sp0                    = arg1;
    func_0205af6c(&sp4, r7, &sp0);
    r4 = (s32) sp4;
    if (r4 == (s32) r7 + 4) {
        r4 = 0;
    } else {
        func_0205b1e0((s32) r7, *(s32 *) (r4 + 0x10), 1);
        r4 = *(s32 *) (*(s32 *) (r4 + 0x10));
    }
    if (r4 == 0) {
        s32 base;
        u16 off;
        u16 type;

        r4   = func_0205ab30(arg1);
        off  = *(u16 *) (r4 + 0xc);
        type = *(u16 *) (r4 + 0xe);
        base = r4 + off;
        if (type == 1) {
            if (*(u32 *) r4 == 0x30585442) {
                base = r4 + *(u32 *) base;
            } else {
                base = 0;
            }
        } else {
            base = r4 + *(u32 *) (base + 4);
        }
        func_020ab8e4(arg0, r4, (void *) base);
    }
    {
        s32 base;
        u16 off;
        u16 type;

        off  = *(u16 *) (r4 + 0xc);
        type = *(u16 *) (r4 + 0xe);
        base = r4 + off;
        if (type == 1) {
            if (*(u32 *) r4 == 0x30585442) {
                base = r4 + *(u32 *) base;
            } else {
                base = 0;
            }
        } else {
            base = r4 + *(u32 *) (base + 4);
        }
        *(s32 *) (arg0 + 0xc) = base;
    }
    *(u16 *) (arg0 + 0x14) |= 4;
    {
        s32 p = *(s32 *) (arg0 + 4);
        s32 q = p + *(u16 *) (p + 0xe);
        func_020c61e0(p + *(s32 *) (q + 0xc), 0, 0x40);
    }
    {
        s32 p = *(s32 *) (arg0 + 4);
        s32 q = p + *(u16 *) (p + 0xe);
        func_020c61e0(p + *(s32 *) (q + 0xc), 0, 0x80);
    }
    return 1;
}
