#include "m2c.h"

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
} TouchFlags;

u16 func_020d36c0(void);                   /* extern */
void func_020d38bc(u16 *out, u16 *in);     /* extern */
void TP_RequestSamplingAsync(void);        /* extern */
s32 TP_WaitRawResult(void *);              /* extern */
void func_020647ec(u8 *);                  /* extern */

void func_0206468c(u8 *obj) {
    TouchFlags *f = (TouchFlags *) obj;
    u16 buf[4];
    u8 c;
    s32 i;

    if (f->b6) {
        return;
    }

    if (f->b1) {
        u32 base = func_020d36c0();
        for (i = 0; i < 4; i++) {
            s32 j = base + i - 3;
            if (j < 0) {
                j += 5;
            }
            func_020d38bc((u16 *) (obj + 0x2a + 8 * i), (u16 *) (obj + 2 + 8 * j));
        }
    } else {
        do {
            TP_RequestSamplingAsync();
        } while (TP_WaitRawResult(buf) != 0);
        func_020d38bc((u16 *) (obj + 0x2a), buf);
    }

    f->b3 = f->b2;
    if (*(u16 *) (obj + 0x30) == 0 && *(u16 *) (obj + 0x2e) != 0) {
        c = 1;
    } else {
        c = 0;
    }
    f->b2 = c;
    if (f->b2 && !f->b3) {
        c = 1;
    } else {
        c = 0;
    }
    f->b4 = c;
    if (f->b3 && !f->b2) {
        c = 1;
    } else {
        c = 0;
    }
    f->b5 = c;
    func_020647ec(obj);
}
