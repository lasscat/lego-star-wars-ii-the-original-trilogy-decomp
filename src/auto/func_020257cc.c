/* Reconstructed from USA ARM9 at 0x020257cc (724 bytes).
 * Names and types are inferred from the binary.
 */
#include "m2c.h"

extern M2C_UNK func_02011384(M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK func_0205e80c(s32, s32, s32);
extern M2C_UNK func_0200ff50(M2C_UNK, s32, s32, M2C_UNK, M2C_UNK);
extern M2C_UNK func_02001990(M2C_UNK, s32);
extern M2C_UNK func_0205c324(M2C_UNK);
extern M2C_UNK func_020082a4(M2C_UNK, s32, s32);
extern M2C_UNK func_0205c628(M2C_UNK, s32);
extern M2C_UNK func_02055128(M2C_UNK, M2C_UNK);
extern M2C_UNK data_020fda80;
extern M2C_UNK data_021094ac;

/* 12-byte group copied through the compiler's self-assignment guard. */
typedef struct {
    s32 f0;
    s32 f1;
    s32 f2;
} Group;

/* Layout of the object reached through obj->field20. */
typedef struct {
    s32 f00;
    Group f04;
    s32 f10;
    Group f14;
    s32 f20;
    u8 f24;
    u8 f25;
    u8 f26;
    Group f28;
} Other;

/* Local configuration block passed to func_0200ff50. */
typedef struct {
    u8 pad[0x24];
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s16 f3c;
    s16 f3e;
    s16 f40;
    u8 gap[2];
    u8 f44;
    u8 f45;
} Cfg;

void *func_020257cc(void *arg0, s32 arg1, void *arg2) {
    Other *src;

    func_02011384(arg0, arg1, arg2);
    M2C_FIELD(arg0, void **, 0)     = &data_020fda80;
    M2C_FIELD(arg0, s32 *, 0x218)   = 0;
    M2C_FIELD(arg0, s32 *, 0x21c)   = 0;
    M2C_FIELD(arg0, s32 *, 0x220)   = 0;
    M2C_FIELD(arg0, void **, 0x224) = 0;
    M2C_FIELD(arg0, void **, 0x228) = 0;
    M2C_FIELD(arg0, u8 *, 0x1bc)    = 0;
    {
        s32 *s = (s32 *) ((u8 *) arg0 + 0xb0);
        if ((s32 *) ((u8 *) arg0 + 0x218) != s) {
            M2C_FIELD(arg0, s32 *, 0x218) = s[0];
            M2C_FIELD(arg0, s32 *, 0x21c) = s[1];
            M2C_FIELD(arg0, s32 *, 0x220) = s[2];
        }
    }

    {
        void *var_r5;
        var_r5 = func_0205e80c(0x1bc, 1, 4);
        if (var_r5 != NULL) {
            Cfg cfg;
            cfg.f24 = 0;
            cfg.f28 = 0;
            cfg.f2c = 0;
            cfg.f30 = 0x1000;
            cfg.f34 = 0x1000;
            cfg.f38 = 0x1000;
            cfg.f3c = 0;
            cfg.f3e = 0;
            cfg.f40 = 0;
            cfg.f44 = 1;
            cfg.f45 = 1;
            var_r5  = func_0200ff50(var_r5, 0x80, 0x276, arg2, &cfg);
        }

        {
            void **var_r1_2 = M2C_FIELD(arg0, void ***, 0x224);
            void *temp_r0;
            void **node = (void **) var_r5;
            void *var_r2;

            if (var_r5 != NULL) {
                node = (void **) ((u8 *) var_r5 + 4);
            }
            if (var_r1_2 != NULL) {
                var_r2  = *var_r1_2;
                temp_r0 = (u8 *) arg0 + 0x224;
                if (var_r2 != temp_r0) {
                    do {
                        var_r1_2 = var_r2 + 4;
                        var_r2   = M2C_FIELD(var_r2, void **, 4);
                    } while (var_r2 != temp_r0);
                }
                *var_r1_2 = M2C_FIELD(arg0, void **, 0x228);
            }
            if (node != NULL) {
                M2C_FIELD(arg0, void **, 0x224) = node;
                M2C_FIELD(arg0, void **, 0x228) = *node;
                *node                           = (u8 *) arg0 + 0x224;
            } else {
                M2C_FIELD(arg0, void **, 0x224) = NULL;
                M2C_FIELD(arg0, void **, 0x228) = NULL;
            }
        }

        M2C_FIELD(var_r5, s32 *, 0x84) = 13;
        M2C_FIELD(var_r5, s32 *, 8)    = (M2C_FIELD(var_r5, s32 *, 8) & 0xfffffdde) | 0x1000000;
        func_02001990(arg0, 1);

        {
            void *tmp = func_0205e80c(0x30, 0, 4);
            if (tmp != NULL) {
                tmp = func_0205c324(tmp);
            }
            M2C_FIELD(var_r5, void **, 0x190) = tmp;
        }

        src = M2C_FIELD(arg0, Other **, 0x20);
        {
            Other *dst = (Other *) func_020082a4((u8 *) var_r5 + 0x10, 5, 0);
            if (&dst->f28 != &src->f28) {
                dst->f28.f0 = src->f28.f0;
                dst->f28.f1 = src->f28.f1;
                dst->f28.f2 = src->f28.f2;
            }
            if (&dst->f04 != &src->f04) {
                dst->f04.f0 = src->f04.f0;
                dst->f04.f1 = src->f04.f1;
                dst->f04.f2 = src->f04.f2;
            }
            dst->f10 = src->f10;
            if (&dst->f14 != &src->f14) {
                dst->f14.f0 = src->f14.f0;
                dst->f14.f1 = src->f14.f1;
                dst->f14.f2 = src->f14.f2;
            }
            dst->f20 = src->f20;
            dst->f26 = src->f26;
        }

        {
            s32 flag;
            if (M2C_FIELD(var_r5, s32 *, 0xb0) != M2C_FIELD(src, s32 *, 4) ||
                M2C_FIELD(var_r5, s32 *, 0xb4) != M2C_FIELD(src, s32 *, 8) ||
                M2C_FIELD(var_r5, s32 *, 0xb8) != M2C_FIELD(src, s32 *, 0xc)) {
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag != 0) {
                if ((s32 *) ((u8 *) var_r5 + 0xb0) != (s32 *) ((u8 *) src + 4)) {
                    M2C_FIELD(var_r5, s32 *, 0xb0) = M2C_FIELD(src, s32 *, 4);
                    M2C_FIELD(var_r5, s32 *, 0xb4) = M2C_FIELD(src, s32 *, 8);
                    M2C_FIELD(var_r5, s32 *, 0xb8) = M2C_FIELD(src, s32 *, 0xc);
                }
                M2C_FIELD(var_r5, u8 *, 0xd1) = 1;
            }
        }

        func_0205c628(M2C_FIELD(var_r5, void **, 0x190), 1);
        func_02055128(&data_021094ac, var_r5);
        if (arg1 == 0xe5) {
            M2C_FIELD(arg0, s32 *, 8) = M2C_FIELD(arg0, s32 *, 8) & 0xfffffdfe;
        }
    }
    return arg0;
}
