#include "m2c.h"

// Partial interface: unknown virtuals retain their observed vtable slots.
// Declarations only: the original vtable remains in the ROM data.
//
// OwnerAF460: ROM vtable 0x02100668 (address point), the same vtable the
// classes of src/auto/func_020af214.cpp, src/auto/func_020af718.cpp and
// src/auto/func_020af7f4.cpp use. Slot 0x00 takes an index and returns a
// pointer to one of the 0x70-byte elements of the container.
class OwnerAF460 {
public:
    virtual OwnerAF460 *unknown00(s32); // Slot 0x00.
    virtual OwnerAF460 *unknown04();    // Slot 0x04.
    u8 pad[0x6B0];
    /* The eight slot entries at offset 0x6b4 (see src/auto/func_020af214.cpp):
     * a u16 tag at +0 and a u32 value at +4. */
    struct {
        u16 tag;
        u32 value;
    } slots[8];
};

typedef struct {
    u16 tag;
    u32 value;
} ElemAF460;

extern "C" s32 func_020ad2a8(void *a, void *b);
extern "C" u16 func_020ad300(u16 *a);
extern "C" void func_020ad308(void *a);

extern "C" s32 func_020af460(OwnerAF460 *self) {
    if (M2C_FIELD(self->unknown00(-1), u8 *, 0x6E) != 0) {
        if (M2C_FIELD(self->unknown00(-1), u8 *, 0x6D) != 0) {
            u8 n = 0;
            s32 i;
            for (i = 0; i < 4; i++) {
                u16 flags = M2C_FIELD(self->unknown00(0), u16 *, 0x66);
                if ((flags & (1 << (u16) i)) == 0) {
                    continue;
                }
                u32 idx = M2C_FIELD(self->unknown00(n), u8 *, 0x6E) & 7;
                ElemAF460 e;
                e.value       = 0;
                OwnerAF460 *o = self->unknown00(n);
                e.value       = M2C_FIELD(o, u32 *, 0x60);
                e.tag         = M2C_FIELD(o, u16 *, 0x68);

                void *dst = &self->slots[idx];
                if (func_020ad2a8(dst, &e) == 0) {
                    func_020ad308(dst);
                    func_020ad308(&e);
                    func_020ad300((u16 *) &e);
                    func_020ad300((u16 *) dst);
                    return 0;
                }
                n = (u8) (n + 1);
            }
        }
    }
    return 1;
}
