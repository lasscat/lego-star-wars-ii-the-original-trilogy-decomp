#include "m2c.h"

typedef struct {
    u8 pad00[0xC];
    s32 field_0C[2];
    u16 field_14;
    u16 field_16;
    u8 pad18[8];
} Slot;

extern void func_02053c98(void *, u32, s32);
extern u16 *func_02053b50(void *);
extern void *func_0205ab58(s32);
extern void func_0205e6e0(void *, void *, s32);
extern void func_02055b04(s32, s32, s32, s32);
extern void func_02055b24(s32, s32, s32, s32, s32);

void func_0206b868(Slot *slots, s32 index) {
    u16 idx = slots[index].field_16;
    u16 *dst;

    func_02053c98(slots[index].field_0C, idx, 0);
    dst = func_02053b50(slots[index].field_0C);
    func_0205e6e0(dst + (((u16) (idx + 1) << 5) / 2), func_0205ab58(0x1465), 0x6C0);
    func_02055b04(0x1466, slots[index].field_14 << 4, 0x10, index);
    func_02055b04(0x1466, (slots[index].field_14 + 1) << 4, 0x10, index);
    func_02055b24(0x8F9, 0x24, (slots[index].field_14 << 4) + 1, 3, index);
}
