#include "m2c.h"

typedef struct {
    u8 pad000[0x6BB];
    u8 f6BB;
    u8 pad6BC[7];
    u8 f6C3;
    u8 pad6C4[0x26];
    u16 f6EA;
    u8 pad6EC[4];
    u16 f6F0;
} Sub;

typedef struct {
    u8 pad00[0x24];
    u16 f24;
    u16 f26;
    u16 f28;
} Res;

extern u8 data_020ef580[];
extern u8 data_020f6bab[];
extern void *func_0208dad8(u32);

u32 func_0208e190(Sub *s) {
    u32 v;
    u32 w;

    v = data_020ef580[(s16) s->f6BB * 0x18];
    if (v == 0x20) {
        w = s->f6F0;
        if (w != 0xFA) {
            w = ((Res *) func_0208dad8(w))->f24;
            if (w != 0x1F) {
                v = w;
            }
        }
        if (v == 0x20) {
            w = s->f6EA;
            if (w != 0xFA) {
                v = ((Res *) func_0208dad8(w))->f28;
            }
        }
        switch (data_020f6bab[(s16) s->f6C3 * 0x24]) {
            case 0:
            case 2:
                switch (v) {
                    case 4:
                    case 5:
                        v = 2;
                        break;
                }
                break;
            case 1:
                switch (v) {
                    case 2:
                        v = 0;
                        break;
                }
                break;
            case 3:
                switch (v) {
                    case 2:
                    case 4:
                    case 5:
                        v = 0;
                        break;
                }
                break;
        }
    }
    return v;
}
