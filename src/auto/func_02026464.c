/* Reconstructed from USA ARM9 at 0x02026464 (336 bytes).
 * Names and types are inferred from the binary.
 *
 * The switch cases 0x90/0xea/0xeb/0x147 share the default body; the original
 * kept them as explicit labels, which is why the compiler emits the
 * comparison tree over {0x2e,0x2f,0x5e,0x67,0x90,0xea,0xeb,0x147}.
 */
#include "m2c.h"

void func_02011384(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void func_020c3c34(void *, s32, s32, s8, s32);            /* extern */
void func_02026f88(void *);                               /* extern */
extern M2C_UNK data_020fdb50;

void *func_02026464(void *self, u32 arg1, s32 arg2, void *arg3) {
    s32 *p;
    s32 *q;
    s32 *base;
    u8 *tbl;
    u16 idx;
    u16 val;
    s32 *entry;

    func_02011384(self, arg1, arg2, (s32) arg3);
    M2C_FIELD(self, M2C_UNK **, 0) = &data_020fdb50;
    M2C_FIELD(self, s32 *, 0x218)  = 0;
    M2C_FIELD(self, s32 *, 0x21c)  = 0;
    M2C_FIELD(self, u16 *, 0x220)  = M2C_FIELD(arg3, u16 *, 0x3e);
    M2C_FIELD(self, u16 *, 0x222)  = 0;
    M2C_FIELD(self, u16 *, 0x224)  = 0;
    M2C_FIELD(self, u8 *, 0x226)   = 0;
    M2C_FIELD(self, u8 *, 0x227)   = 0;
    M2C_FIELD(self, s32 *, 0x228)  = 4;
    M2C_FIELD(self, u16 *, 0x1be)  = 0xc;

    switch (arg1) {
        case 0x2e:
        case 0x2f:
            p    = M2C_FIELD(self, s32 *, 0xdc);
            q    = (s32 *) ((u8 *) p + *(u16 *) ((u8 *) p + 0xe));
            base = (s32 *) ((u8 *) p + *(s32 *) ((u8 *) q + 0xc));
            tbl  = (u8 *) base + 0x40;
            if (arg1 == 0x2e) {
                idx   = *(u16 *) ((u8 *) tbl + 6);
                val   = *(u16 *) ((u8 *) tbl + idx);
                entry = (s32 *) ((u8 *) tbl + idx + val * 2);
            } else {
                idx   = *(u16 *) ((u8 *) tbl + 6);
                val   = *(u16 *) ((u8 *) tbl + idx);
                entry = (s32 *) ((u8 *) tbl + idx + val * 3);
            }
            M2C_FIELD(self, s32 *, 0x218) = (s32) ((u8 *) tbl + *(s32 *) ((u8 *) entry + 4));
        /* the field is read back from memory, not reused from the store */
            M2C_FIELD(self, s32 *, 0x21c) = M2C_FIELD(self, volatile s32 *, 0x218) + 0x10;
            break;
        case 0x5e:
        case 0x67:
            break;
        case 0x90:
        case 0xea:
        case 0xeb:
        case 0x147:
        default:
            M2C_FIELD(self, s32 *, 0x120) = (s32) self;
            func_020c3c34((void *) ((u8 *) self + 0xf4), (s32) (void *) &func_02026f88, 0, 6, 2);
            break;
    }
    return self;
}
