/* Reconstructed from USA ARM9 at 0x02022a3c (384 bytes). */
#include "m2c.h"

/* Four byte aggregate, passed by value. */
typedef struct {
    s32 v;
} UnkVal;

/* Twelve byte aggregate, passed by value. */
typedef struct {
    u32 a;
    u32 b;
    u32 c;
} UnkTriple;

void func_02023374(void *, UnkTriple);
u32 func_020b9304(u32);
void func_020b9068(u32);
u32 func_020b8f70(u32, u32);
void func_02004b78(u32, u32);
void func_01ff8abc(void *, u32);
void func_02012744(void *, UnkVal);

void func_02022a3c(void *obj, UnkVal arg) {
    u16 v = M2C_FIELD(obj, u16 *, 0x212);

    if (v != 0x54 && v != 0x15d) {
        u32 p = M2C_FIELD(obj, u32 *, 0x224);

        if (p != 0 && M2C_FIELD(obj, u8 *, 0x217) == 0) {
            {
                UnkTriple t = *(UnkTriple *) ((u8 *) p + 0xb0);
                func_02023374(obj, t);
            }
            M2C_FIELD(obj, u32 *, 0x21c) = 0;
            M2C_FIELD(obj, u32 *, 0x218) = 0;
            if (func_020b9304(M2C_FIELD(obj, u32 *, 0x248)) != 0) {
                func_020b9068(M2C_FIELD(obj, u32 *, 0x248));
            }
            func_020b8f70(0xb8, 0);
        }

        if (M2C_FIELD(obj, u32 *, 0x194) & 0x100000) {
            u32 q = M2C_FIELD(obj, u32 *, 0x220);

            if (q != 0 && (M2C_FIELD(q, u32 *, 8) & 0x800)) {
                M2C_FIELD(obj, u32 *, 0x220) = 0;
                M2C_FIELD(obj, u32 *, 0x21c) = 0;
                M2C_FIELD(obj, u32 *, 0x218) = 0;
                M2C_FIELD(obj, u32 *, 8) |= 0x200;
                M2C_FIELD(obj, u8 *, 0x216) = 0;
                if (func_020b9304(M2C_FIELD(obj, u32 *, 0x248)) != 0) {
                    func_020b9068(M2C_FIELD(obj, u32 *, 0x248));
                }
            }

            if (M2C_FIELD(obj, u32 *, 0x218) != M2C_FIELD(obj, u32 *, 0x21c)) {
                if (M2C_FIELD(obj, u32 *, 0x218) == 0) {
                    M2C_FIELD(M2C_FIELD(obj, u32 *, 0x220), u32 *, 0x6ac) = (u32) obj;
                    func_02004b78(M2C_FIELD(obj, u32 *, 0x220), 0x2d);
                    M2C_FIELD(obj, u32 *, 0x248) = func_020b8f70(0x6e, 0);
                }
                M2C_FIELD(obj, u32 *, 0x218) = M2C_FIELD(obj, u32 *, 0x21c);
            }

            if (M2C_FIELD(obj, u8 *, 0x216) == 0) {
                M2C_FIELD(obj, u32 *, 0x21c) = 0;
                M2C_FIELD(obj, u32 *, 0x218) = 0;
                M2C_FIELD(obj, u32 *, 8) |= 0x200;
                if (func_020b9304(M2C_FIELD(obj, u32 *, 0x248)) != 0) {
                    func_020b9068(M2C_FIELD(obj, u32 *, 0x248));
                }
            }

            func_01ff8abc(obj, 0);
        }
    }

    func_02012744(obj, arg);
}
